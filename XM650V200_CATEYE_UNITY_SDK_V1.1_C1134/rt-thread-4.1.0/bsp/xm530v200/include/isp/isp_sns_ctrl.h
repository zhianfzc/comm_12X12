#ifndef __ISP_SNS_CTRL_H__
#define __ISP_SNS_CTRL_H__

#include "isp_type.h"
#include "isp_comm_sns.h"
#include "isp_ae_comm.h"
#include "isp_i2c.h"
#include "isp_idefines.h"
#define HD720P_LINES  	(750)
#define HD1080P_LINES 	(1125)

void sensor_init(ISP_DEV IspDev);
ISP_S32 sensor_write_register(ISP_U8,ISP_U32 addr, ISP_U32 data);
ISP_S32  sensor_read_register(ISP_U8,ISP_U32 addr);
int  sensor_write_register_bit(int addr, int data, int mask);
int sensor_register_callback(ISP_DEV IspDev); 
int sensor_unregister_callback(ISP_DEV IspDev);
int  sensor_get_chip(ISP_DEV IspDev,ISP_U8 I2cCh,I2C_DATA_S *pstI2CData,ISP_FUN_EXT u8FunExt);
void  sensor_set_chip(ISP_DEV IspDev,ISP_S32 *s32SnsChip);
int sensor_mode_set(ISP_DEV IspDev,ISP_U8 u8Mode);
int  sensor_mode_get(ISP_DEV IspDev);

int  sensor_get_temp(ISP_S16 *ps16Temp);
void  sensor_set_dnMode(ISP_U8 u8Mode);
int	sensor_get_encoderinfo(ISP_U8 *u8pDta);
void sensor_set_isp_para(ISP_U8 u8RlstMode,ISP_U8 u8Mode);

void sensor_set_ioAbility(ISP_U8 u8Level);
ISP_S32 sensor_set_reslotionType(RESL_TYPE enResType);
/*************************************************************************************
�������: 	u8Mode(0:Stop  1:Restart)
*************************************************************************************/
void sensor_restart(ISP_U8 u8Mode);
void sensor_restart_double(ISP_DEV IspDev,ISP_U8 u8Mode);

ISP_S32 cmos_set_sns_attr(ISP_DEV IspDev, ISP_CMOS_SNS_ATTR_S *pstSnsAttr);
ISP_S32 cmos_get_sns_attr(ISP_DEV IspDev, ISP_CMOS_SNS_ATTR_S *pstSnsAttr);



/*************************************************************************************
��������: ��ȡAGC��صĲ���(��ɫ/�ڰ���Ҫ����)
�������: u8IspCh: ָ��ISP�豸��
�������: pstAgcPara(��������ַ)
���ز���: 		-1:ʧ��
			0: �ɹ�
*************************************************************************************/
ISP_S32 sensor_get_agc_para(ISP_DEV IspDev, ISP_CMOS_DN_PARA_S *pstAgcPara);

#endif /* __ISP_SNS_CTRL_H__ */

