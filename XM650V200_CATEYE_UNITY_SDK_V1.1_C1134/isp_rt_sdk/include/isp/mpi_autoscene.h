#ifndef __MPI_AUTOSCENE_H__
#define __MPI_AUTOSCENE_H__ 

#ifdef __cplusplus
extern "C" {
#endif
#include "isp_comm_isp.h"
typedef enum enAUTOSCENE_DNC_STATUS
{
	DNS_COLOR = 0,
	DNS_BW = 1,
	DNS_BUTT,
}AUTOSCENE_DNC_STATUS;

typedef struct stAUTOSCENE_PRODUCT_INFO_S
{
	ISP_U32 u32ProductType;
	ISP_U32 u32SnsType;
	WDR_MODE_E	enWdrMode;
	ISP_U32 au32Rsv[4];
}AUTOSCENE_PRODUCT_INFO_S;

typedef struct stAS_CONFIG_CH
{
/*****************************************
1_0 u16LedIO: (��صƵ�GPIO)
	bit0~bit15:	(�����GPIO��10���Ʊ�ʾ)
	bit16~bit31: (�׹��GPIO��10���Ʊ�ʾ)
*****************************************/	
	ISP_U32 u32SoftLedIO;

	ISP_U32 au32Rsv[3];
/*****************************************
1_1	����ư� GPIO
*****************************************/
	ISP_U16 u16InfraredIO;
/*****************************************
1_2 IRCUT GPIO _A:[0]   _B:[1]
*****************************************/
	ISP_U16 au16IrCutIO[2];
/*****************************************
1_3	��������IRC�����Ƿ���õ�����IO֮һ(����һ��IO�̶�ΪADC)
*****************************************/
	ISP_U16 u16IrCutTestIO;

	ISP_U16 au16Rsv[4];
/*****************************************
1_3 u8PolaritySwap: 
	bit0:	����ư����뼫��
	bit1:	�������������
	bit2: 	�׹����������
	bit3: 	IRCUT���뼫��
*****************************************/
	ISP_U8 u8PolaritySwap;

/*****************************************
1_4 u8IRLed����صơ��������
	bit0: 	(1: ������Ƶ�(WL/IR)        0: Ӳ�����Ƶ�(����))
	bit4:	(1: Ӳ����					0: �����) --- bit0Ϊ1ʱ��Ч
*****************************************/
	ISP_U8 u8IRLed;


/*****************************************
1_5 u8LedMode: (LED�������ڽӿ�camera_get_ledMode�ķ���)
	u8LedMode:	0xAB(	A:	0: IR   �������
							1: WL   �׹��(CMS �����ó�˫��)
							2: Double (��˫��---˫��ǹ��)
							3: WL(only) (���׹�)
						B:	����
*****************************************/	
	ISP_U8 u8LedMode;

/*****************************************
1_6 u8LedAlarmAlg: (˫�� �����㷨ѡ��)
	u8LedAlarmAlg:	0: �����㷨
					1: �ƶ����
*****************************************/
	ISP_U8 u8LedAlarmAlg;

/*****************************************
1_7 u8LedAlarmMode: (����˫���(���ܾ���)������������ģ��ƴ���ģʽ)
	u8LedAlarmMode:	0x03: ����ģʽ���׵���˸��
					0x04: ����ģʽ���׹�Ƴ�����
					����: ����׵ƴ���(���׵�+ȫ��)	
*****************************************/
	ISP_U8 u8LedAlarmMode;
/*****************************************
1_8 u8LowFrequency(�͹��ĵȲ�Ʒ���)
*****************************************/
	ISP_U8 u8LowFrequency;

	ISP_U8 au8Rsv[8];
}AS_CONFIG_CH;

typedef struct stAUTOSCENE_CONFIG 
{
	ISP_FUN_EXT u8FunExt;
	ISP_U8 u8ChnMask;
	ISP_U8 au8Rsv[2];
/*****************************************
0_1 ��Ʒ�ͺ�
*****************************************/
	ISP_U32 u32ProductType;
/*****************************************
0_2 DSP�ͺ�
*****************************************/
	ISP_U32 u32DspType;
/*****************************************
0_3~8 ����
*****************************************/
	ISP_U32 au32Rsv[7];

	AS_CONFIG_CH astChnAttr[ISP_NUM_MAX];
}AUTOSCENE_CONFIG;

ISP_S32 XM_MPI_AUTOSCENE_SetConfig(AUTOSCENE_CONFIG stConfig);

ISP_S32 XM_MPI_AUTOSCENE_Init(ISP_DEV IspDev,AUTOSCENE_PRODUCT_INFO_S stProductInfo);
ISP_S32 XM_MPI_AUTOSCENE_Run(ISP_U8 u8ChnMask, ISP_S32 s32Rsv);
ISP_S32 XM_MPI_AUTOSCENE_Exit(ISP_DEV IspDev);
ISP_S32 XM_MPI_AUTOSCENE_AI_Face_Lum_Double(ISP_U32 u32flag,ISP_U32 u32Level,ISP_U32 u32Max,ISP_U32 u32Min);

ISP_S32 XM_MPI_AUTOSCENE_SetLumTarget(ISP_DEV IspDev, ISP_S32 s32Tgt);
ISP_S32 XM_MPI_AUTOSCENE_GetLumTarget(ISP_DEV IspDev, ISP_S32 *ps32Tgt);

ISP_S32 XM_MPI_AUTOSCENE_SetGainLvl(ISP_DEV IspDev, ISP_S32 s32En, ISP_S32 s32Level);
ISP_S32 XM_MPI_AUTOSCENE_GetGainLvl(ISP_DEV IspDev, ISP_S32 *ps32En, ISP_S32 *ps32Level);

ISP_S32 XM_MPI_AUTOSCENE_GetBlc(ISP_DEV IspDev, ISP_S32 *ps32En, ISP_S32 *ps32Level);
ISP_S32 XM_MPI_AUTOSCENE_SetBlc(ISP_DEV IspDev, ISP_S32 s32En, ISP_S32 s32Level);

ISP_S32 XM_MPI_AUTOSCENE_GetHlc(ISP_DEV IspDev, ISP_S32 *ps32En, ISP_S32 *ps32Level);
ISP_S32 XM_MPI_AUTOSCENE_SetHlc(ISP_DEV IspDev, ISP_S32 s32En, ISP_S32 s32Level);

ISP_S32 XM_MPI_AUTOSCENE_Debug(ISP_DEV IspDev, ISP_S32 s32Data, ISP_CHAR *pstrData);



#ifdef __cplusplus
}
#endif

#endif

