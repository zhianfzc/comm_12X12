#include "isp_type.h"
#include "isp_comm_isp.h"
#include "isp_comm_sns.h"
#include "isp_sns_ctrl.h"
#include "mpi_isp.h"
#include "mpi_ae.h"
#include "mpi_awb.h"
#include "isp_awb_comm.h"
#include "XAx_cmos.h"
#include "isp_print.h"



#define HD4MP_25P_LINES_SC4336		(1500)
#define MAX_SHUT_OFST		(10)



static const ISP_CMOS_AGC_TABLE_S g_stIspAgcTable_sc4336 = {
	/* bvalid */
	1,
	/* 100, 200, 400, 800, 1600, 3200, 6400, 12800; 100, 200, 400, 800, 1600, 3200, 6400, 12800 */
	/* snr_thresh 2DNr		*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	/* drc	*/
	{0x32,0x28,0x1c,0x1a,0x16,0x10,0x0c,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08},
	/* defog	*/
	{0x28,0x28,0x20,0x1a,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18},
	/* defog_vpss	*/
	{0x20,0x20,0x40,0x40,0x40,0x40,0x40,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60}, 
	/* DyDpc_thresh 		*/
	{0xB8,0xC0,0xD0,0xD4,0xD8,0xDC,0xE0,0xE0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0},   
	/* saturation_strength */
	{0xb2,0xb0,0xa8,0x98,0x88,0x78,0x50,0x50,0x50,0x10,0x10,0x10,0x10,0x10,0x10,0x10},
	/* Blc	*/
	{0x104,0x104,0x104,0x104,0x104,0x104,0x104,0xF0,0x104,0x104,0x104,0x104,0x104,0x104,0x104,0x104},
	/* Contrast*/ 
	{0x32,0x32,0x32,0x32,0x32,0x32,0x32,0x32,0x32,0x32,0x32,0x32,0x32,0x32,0x32,0x32}
};

static ISP_S32 cmos_get_isp_default(ISP_DEV IspDev, ISP_CMOS_DEFAULT_S *pstDef)
{
	ISP_U8 u8ColorBw = 0;	// 0:Color	1:Bw
	if (ISP_NULL == pstDef)
	{
		ERR("null pointer when get isp default value!\n");
		return -1;
	}
	gstCmosDnPara[IspDev].pastAgcTab[0] = &g_stIspAgcTable_sc4336;
	gstCmosDnPara[IspDev].pastAgcYcNr[0] = &gstYCNr;
	gstCmosDnPara[IspDev].pastAgcSharp[0] = &gstSharpenColor;
	gstCmosDnPara[IspDev].pastAgcSharp[1] = &gstSharpenBw;
	gstCmosDnPara[IspDev].pastAgcVpss3DNr[0] = &gstVpss3DNr;
	gstCmosDnPara[IspDev].pastGamma[0] = &gastIspGamma[1];
	gstCmosDnPara[IspDev].pastGamma[1] = &gastIspGamma[0];
	gstCmosDnPara[IspDev].pastAgcLtm[0] = &gstLtm;
	gstCmosDnPara[IspDev].past2DNr[0] = &gst2DNr;
	if(gstCmosDnPara[IspDev].pastAgcTab[1] == NULL)
	{
		gstCmosDnPara[IspDev].pastAgcTab[1] = gstCmosDnPara[IspDev].pastAgcTab[0];
	}	
	if(gstCmosDnPara[IspDev].pastAgcYcNr[1] == NULL)
	{
		gstCmosDnPara[IspDev].pastAgcYcNr[1] = gstCmosDnPara[IspDev].pastAgcYcNr[0];
	}	
	if(gstCmosDnPara[IspDev].pastAgcSharp[1] == NULL)
	{
		gstCmosDnPara[IspDev].pastAgcSharp[1] = gstCmosDnPara[IspDev].pastAgcSharp[0];
	}
	if(gstCmosDnPara[IspDev].pastAgcVpss3DNr[1] == NULL)
	{
		gstCmosDnPara[IspDev].pastAgcVpss3DNr[1] = gstCmosDnPara[IspDev].pastAgcVpss3DNr[0];
	}
	if(gstCmosDnPara[IspDev].pastGamma[1] == NULL)
	{
		gstCmosDnPara[IspDev].pastGamma[1] = gstCmosDnPara[IspDev].pastGamma[0];
	}
	if(gstCmosDnPara[IspDev].pastAgcLtm[1] == NULL)
	{
		gstCmosDnPara[IspDev].pastAgcLtm[1] = gstCmosDnPara[IspDev].pastAgcLtm[0];
	}
	if(gstCmosDnPara[IspDev].past2DNr[1] == NULL)
	{
		gstCmosDnPara[IspDev].past2DNr[1] = gstCmosDnPara[IspDev].past2DNr[0];
	}
	pstDef->stGamma.bValid = ISP_TRUE;
	XM_MPI_ISP_Memncpy((ISP_U8*)&pstDef->stGamma, (ISP_U8*)(gstCmosDnPara[IspDev].pastGamma[u8ColorBw]), sizeof(ISP_CMOS_GAMMA_S));
	XM_MPI_ISP_Memncpy((ISP_U8*)&pstDef->stAgcTbl, (ISP_U8*)(gstCmosDnPara[IspDev].pastAgcTab[u8ColorBw]), sizeof(ISP_CMOS_AGC_TABLE_S));
	XM_MPI_ISP_Memncpy((ISP_U8*)&pstDef->stVpss3DNr, (ISP_U8*)(gstCmosDnPara[IspDev].pastAgcVpss3DNr[u8ColorBw]), sizeof(ISP_CMOS_VPSS_3DNR_S));
	XM_MPI_ISP_Memncpy((ISP_U8*)&pstDef->stSharpen, (ISP_U8*)(gstCmosDnPara[IspDev].pastAgcSharp[u8ColorBw]), sizeof(ISP_CMOS_SHARPEN_S));
	XM_MPI_ISP_Memncpy((ISP_U8*)&pstDef->stYcNr, (ISP_U8*)(gstCmosDnPara[IspDev].pastAgcYcNr[u8ColorBw]), sizeof(ISP_CMOS_YCNR_S));
	XM_MPI_ISP_Memncpy((ISP_U8*)&pstDef->stLtm, (ISP_U8*)(gstCmosDnPara[IspDev].pastAgcLtm[u8ColorBw]), sizeof(ISP_CMOS_LTM_S));
	XM_MPI_ISP_Memncpy((ISP_U8*)&pstDef->st2DNr, (ISP_U8*)(gstCmosDnPara[IspDev].past2DNr[u8ColorBw]), sizeof(ISP_CMOS_2DNR_S));
	XM_MPI_ISP_Memncpy((ISP_U8*)&pstDef->stShading, (ISP_U8*)&gstShading, sizeof(ISP_CMOS_SHADING_S));
	XM_MPI_ISP_Memncpy((ISP_U8*)&pstDef->stLocalCAC, (ISP_U8*)&gstLocalCAC, sizeof(ISP_CMOS_LOCAL_CAC_S));
	return 0;
}

static ISP_VOID cmos_set_pixel_detect(ISP_DEV IspDev, ISP_BOOL bEnable)
{
    return;
}

static ISP_S32 cmos_set_mirror_flip(ISP_DEV IspDev, ISP_U8 u8Mirror,ISP_U8 u8Flip)
{
	ISP_U32 u32Val;
	ISP_U16 u16OfstH,u16OfstV;
	ISPAPP_WIN_ATTR_S stWinAttr;
	u16OfstH = 0;
	u32Val = sensor_read_register(IspDev, 0x3221);
	if(u8Mirror)
	{
		u32Val |= 0x06;
	}
	else
	{
		u32Val &= ~0x06;
	}

	if(u8Flip)
	{
		u32Val |= 0x60;
		u16OfstV = 0;
	}
	else
	{
		u32Val &= ~0x60;
		u16OfstV = 0;
	}
	sensor_write_register(IspDev, 0x3221, u32Val);
	stWinAttr.u8Mode = 1;
	stWinAttr.u16ValH = u16OfstH;
	stWinAttr.u16ValV = u16OfstV;
	XM_MPI_ISPAPP_WinSet(IspDev, &stWinAttr);
	return ISP_SUCCESS;
}

static ISP_VOID cmos_again_calc_table(ISP_DEV IspDev, ISP_U32 u32InTimes,AE_SENSOR_GAININFO_S *pstAeSnsGainInfo)
{
	ISP_U8 i;
	
	ISP_U32 au32Again[7] = {1, 2, 4, 8, 16, 32}; 
	ISP_U32 au32AgainDb[7] = {0, 0x8, 0x9, 0xb, 0xf, 0x1f};

	if(ISP_NULL == pstAeSnsGainInfo)
	{
		return;
	}
	u32InTimes = CLIP3(u32InTimes,1,32);

	for(i = 1; i < 6; i++)
	{
		if(u32InTimes < au32Again[i])
		{
			break;
		}
	}
	pstAeSnsGainInfo->u32GainDb = au32AgainDb[i-1]; 
	pstAeSnsGainInfo->u32SnsTimes = au32Again[i-1];
	gau32AGainNow[IspDev] = pstAeSnsGainInfo->u32SnsTimes;
	return;
}


static ISP_VOID cmos_dgain_calc_table(ISP_DEV IspDev, ISP_U32 u32InTimes,AE_SENSOR_GAININFO_S *pstAeSnsGainInfo)
{
	if(ISP_NULL == pstAeSnsGainInfo)
	{
		ERR("cmos_dgain_calc_table failed!\n");
		return;
	}
	
	pstAeSnsGainInfo->u32GainDb = u32InTimes;
	pstAeSnsGainInfo->u32SnsTimes = u32InTimes;
	gau32DGainNow[IspDev] = pstAeSnsGainInfo->u32SnsTimes;
	return;
}

static ISP_S32 cmos_get_ae_default(ISP_DEV IspDev, AE_SENSOR_DEFAULT_S *pstAeSnsDft)
{
	if (ISP_NULL == pstAeSnsDft)
	{
		ERR("null pointer when get ae default value!\n");
		return -1;
	}
	pstAeSnsDft->u32FullLinesStd = HD4MP_25P_LINES_SC4336;
	pstAeSnsDft->u8AeCompensation = 0x39;	
	pstAeSnsDft->u32LinesPer500ms = pstAeSnsDft->u32FullLinesStd*20/2;
	pstAeSnsDft->u32FlickerFreq = 0;

	pstAeSnsDft->u32MaxIntTime = pstAeSnsDft->u32FullLinesStd-MAX_SHUT_OFST;
	pstAeSnsDft->u32MinIntTime = 2;    

	pstAeSnsDft->u32MaxAgain = 32;
	pstAeSnsDft->u32MinAgain = 1;

	pstAeSnsDft->u32MaxDgain = 1969;	
	pstAeSnsDft->u32MinDgain = 128;

	pstAeSnsDft->u32ISPDgainShift = 8;
	pstAeSnsDft->u32MaxISPDgain= 8 << pstAeSnsDft->u32ISPDgainShift;
	pstAeSnsDft->u32MinISPDgain= 1 << pstAeSnsDft->u32ISPDgainShift;
	return 0;
}


static ISP_S32 cmos_get_sensor_max_resolution(ISP_DEV IspDev, ISP_CMOS_SENSOR_MAX_RESOLUTION *pstSensorMaxResolution)
{
	if (ISP_NULL == pstSensorMaxResolution)
	{
	    ERR("null pointer when get sensor max resolution \n");
	    return -1;
	}

	pstSensorMaxResolution->u32MaxWidth  = 2568;
	pstSensorMaxResolution->u32MaxHeight = 1448;
	return 0;
}

static ISP_VOID cmos_inttime_update(ISP_DEV IspDev, ISP_U32 u32IntTime)
{
	if(gau32ShutNow[IspDev] == u32IntTime)
		return ;
	gau32ShutNow[IspDev] = u32IntTime;
	sensor_write_register(IspDev, 0x3e02, ((u32IntTime&0xf)<<4));
	sensor_write_register(IspDev, 0x3e01, ((u32IntTime&0x0ff0)>>4));
	sensor_write_register(IspDev, 0x3e00, ((u32IntTime&0xf000)>>12));
	return;
}


static ISP_VOID cmos_gains_update(ISP_DEV IspDev, ISP_U32 u32Again, ISP_U32 u32Dgain)
{
	static ISP_U32 sau32AGain[ISP_NUM_MAX] = {0xFFFFFFFE};
	static ISP_U32 sau32DGain[ISP_NUM_MAX] = {0xFFFFFFFE};
	ISP_U8 u8i, u8Reg0x3e09, u8Reg0x3e07, u8Reg0x3e06;
	if(sau32AGain[0] == 0xFFFFFFFE)
	{
		for(u8i=0;u8i<ISP_NUM_MAX;u8i ++)
		{
			sau32AGain[u8i] = 0xFFFFFFFF;
			sau32DGain[u8i] = 0xFFFFFFFF;
		}
	}
	if((sau32AGain[IspDev] != u32Again) || (sau32DGain[IspDev] != u32Dgain))
	{
		sau32AGain[IspDev] = u32Again;
		sau32DGain[IspDev] = u32Dgain;
		// 2.GainUpdate
		u8Reg0x3e09 = u32Again&0xFF; 
		u8i = 0;
		while(u32Dgain >> u8i)
		{
			u8i++;
		}
		u8Reg0x3e06 = (~(0xFF << (u8i - 8))) & 0xFF;
		u8Reg0x3e07 = (((u32Dgain & (0xFF << (u8i-8))) >> (u8i-8))& 0xFF);
		u8Reg0x3e07 = u8Reg0x3e07 / 4 * 4;
		sensor_write_register(IspDev, 0x3e09, u8Reg0x3e09);
		sensor_write_register(IspDev, 0x3e06, u8Reg0x3e06);
		sensor_write_register(IspDev, 0x3e07, u8Reg0x3e07);
	}
	return;
}

static ISP_VOID cmos_slow_framerate_set(ISP_DEV IspDev, ISP_U16 u16FullLines, AE_SENSOR_DEFAULT_S *pstAeSnsDft)
{
	static ISP_U16 preU16FullLine = 0xffff;
	if(preU16FullLine == u16FullLines)
		return;

	preU16FullLine = u16FullLines;
	pstAeSnsDft->u32MaxIntTime = u16FullLines - MAX_SHUT_OFST;
	if(gau32ShutNow[IspDev]>pstAeSnsDft->u32MaxIntTime)
	{
		cmos_inttime_update(IspDev, pstAeSnsDft->u32MaxIntTime);
	}

	sensor_write_register(IspDev, 0x320e, (u16FullLines>>8)&0xFF);
	sensor_write_register(IspDev, 0x320f, u16FullLines&0xFF);	

	XM_MPI_MIPI_RefreshFV(IspDev,0, u16FullLines);
}

static ISP_VOID cmos_fps_set(ISP_DEV IspDev, ISP_U8 u8Fps, AE_SENSOR_DEFAULT_S *pstAeSnsDft)
{
	ISP_U32 u32TotalSizeV,u32TotalSizeH;
	u32TotalSizeV = HD4MP_25P_LINES_SC4336;
	switch(u8Fps)
	{
		case 30:	u32TotalSizeH = 4200*20/30;
					break;
		case 25:	u32TotalSizeH = 4200*20/25;
					break;
		case 20:
		default:	u8Fps = 20;
					u32TotalSizeH = 4200;
					break;
	}
	if(pstAeSnsDft != NULL)
	{
		pstAeSnsDft->u32FullLinesStd = u32TotalSizeV;
		pstAeSnsDft->u32MaxIntTime = pstAeSnsDft->u32FullLinesStd-MAX_SHUT_OFST;
		pstAeSnsDft->u32LinesPer500ms = pstAeSnsDft->u32FullLinesStd * u8Fps / 2;
	}
	sensor_write_register(IspDev, 0x320c, (u32TotalSizeH>>8)&0xFF);
	sensor_write_register(IspDev, 0x320d, (u32TotalSizeH>>0)&0xFF);	
	sensor_write_register(IspDev, 0x320e, (u32TotalSizeV>>8)&0xFF);
	sensor_write_register(IspDev, 0x320f, u32TotalSizeV&0xFF);	
	XM_MPI_MIPI_RefreshFV(IspDev,0, u32TotalSizeV);
	return;
}



/****************************************************************************
* AWB
****************************************************************************/
static const ISP_COLORMATRIX_AUTO_S g_stAwbCcm =
{
	5000,
	{
		0x000,408, -127, -25,
		0x000,-61,  390, -73,
		0x000,-21, -160, 437
	},
	4000,
	{
		0x000,485, -199, -30,
		0x000,-80,  372, -36,
		0x000,-21, -167, 443
	},
	2800,
	{
		0x000,353,  -85, -12,
		0x000,-86,  362, -20,
	    0x000,-126,-376, 758
	}

};

static const ISP_AWB_CALIBRATION_V2_S gstAwbCal = {
	{0, 0, 4096, 2670, 2972, 2019, 1435, 4096},
	{4096, 4096, 0, 0, 4096, 2861, 4096, 2166},
	{-501, -4073, -1378, -4096, -3097, -4096, -2100, -2951},
	213,
	0, 1677, 0, 2729,
	{0, 721, 1001, 1300, 1398, 1522, 1742, 1811, 2729, 0, 0, 0, 0, 0, 0, 0},
	{2000, 2150, 2800, 4000, 4150, 5000, 6500, 7500, 12000, 0, 0, 0, 0, 0, 0, 0},
 	{1479, 1024, 1892, 0}
};

static ISP_S32 cmos_get_awb_default(ISP_DEV IspDev, AWB_SENSOR_DEFAULT_S *pstAwbSnsDft)
{
	if (ISP_NULL == pstAwbSnsDft)
	{
		ERR("null pointer when get awb default value!\n");
		return ISP_FAILURE;
	}
	XM_MPI_ISP_Memset((ISP_U8*)pstAwbSnsDft, 0, sizeof(AWB_SENSOR_DEFAULT_S));
	pstAwbSnsDft->pstAwbCal = &gstAwbCal;
	// CCM
	XM_MPI_ISP_Memncpy((ISP_U8*)&(pstAwbSnsDft->stCcm), (ISP_U8*)&g_stAwbCcm, sizeof(ISP_COLORMATRIX_AUTO_S));
	return ISP_SUCCESS;
}


/****************************************************************************
 * callback structure                                                       *
 ****************************************************************************/
 ISP_S32 cmos_init_chn_sc4336(ISP_DEV IspDev)
{
	return 0;
}
 
ISP_S32 cmos_init_sensor_exp_function_sc4336(ISP_SENSOR_EXP_FUNC_S *pstSensorExpFunc)
{
	XM_MPI_ISP_Memset((ISP_U8 *)pstSensorExpFunc, 0, sizeof(ISP_SENSOR_EXP_FUNC_S));
	pstSensorExpFunc->pfn_cmos_sensor_init = sensor_init;
	pstSensorExpFunc->pfn_cmos_get_isp_default = cmos_get_isp_default;
	pstSensorExpFunc->pfn_cmos_set_pixel_detect = cmos_set_pixel_detect;
	pstSensorExpFunc->pfn_cmos_get_sensor_max_resolution = cmos_get_sensor_max_resolution;
	pstSensorExpFunc->pfn_cmos_set_mirror_flip = cmos_set_mirror_flip;
	return 0;
}

ISP_S32 cmos_init_ae_exp_function_sc4336(AE_SENSOR_EXP_FUNC_S *pstExpFuncs)
{
	XM_MPI_ISP_Memset((ISP_U8 *)pstExpFuncs, 0, sizeof(AE_SENSOR_EXP_FUNC_S));
	pstExpFuncs->pfn_cmos_fps_get = NULL;
	pstExpFuncs->pfn_cmos_get_ae_default    = cmos_get_ae_default;
	pstExpFuncs->pfn_cmos_fps_set           = cmos_fps_set;
	pstExpFuncs->pfn_cmos_slow_framerate_set= cmos_slow_framerate_set;    
	pstExpFuncs->pfn_cmos_inttime_update    = cmos_inttime_update;
	pstExpFuncs->pfn_cmos_gains_update      = cmos_gains_update;
	pstExpFuncs->pfn_cmos_again_calc_table  = cmos_again_calc_table;
	pstExpFuncs->pfn_cmos_dgain_calc_table  = cmos_dgain_calc_table;
	return 0;
}

ISP_S32 cmos_init_awb_exp_function_sc4336(AWB_SENSOR_EXP_FUNC_S *pstExpFuncs)
{
	XM_MPI_ISP_Memset((ISP_U8*)pstExpFuncs, 0, sizeof(AWB_SENSOR_EXP_FUNC_S));
	pstExpFuncs->pfn_cmos_get_awb_default = cmos_get_awb_default;
	return 0;
}








