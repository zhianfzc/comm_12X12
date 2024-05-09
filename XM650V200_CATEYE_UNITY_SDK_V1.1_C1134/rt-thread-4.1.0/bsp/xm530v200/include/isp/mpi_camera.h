#ifndef __MPI_CAMERA_H__
#define __MPI_CAMERA_H__ 

#ifdef __cplusplus
extern "C" {
#endif
#include "isp_type.h"

typedef ISP_S32 CAM_DEV;

typedef enum stCAM_SCENE_TYPE_E
{
	SCENE_TYPE_AUTO,
	SCENE_TYPE_INDOOR,
	SCENE_TYPE_OUTDOOR,
	SCENE_TYPE_BUTT,
}CAM_SCENE_TYPE_E;


typedef enum stCAM_DNC_MODE_E
{
	DNC_MODE_AUTO,			// �Զ��л�
	DNC_MODE_MULTICOLOR,		// ��ɫ
	DNC_MODE_BLACKWHITE,		// ǿ��Ϊ�ڰ�ģʽ
	DNC_MODE_INTE_WHITE_INF, //���ܾ���
	DNC_MODE_WHITELAMP_AUTO, //����ů��
	DNC_MODE_IRLAMP_AUTO,	//���ܺ���
	DNC_MODE_LP_MODE,		//����ģʽ
	DNC_MODE_BUTT
}CAM_DNC_MODE_E;


typedef enum stCAM_DN_STATUS_E
{
	DN_STATUS_COLOR,
	DN_STATUS_BW,
	DN_STATUS_BUTT,
}CAM_DN_STATUS_E;


typedef enum stCAM_IMG_STYLE_E
{
	IMG_STYLE_0,
	IMG_STYLE_1,
	IMG_STYLE_2,
	IMG_STYLE_BUTT,
}CAM_IMG_STYLE_E;

typedef enum stCAM_ESHUTTER_TYPE_E
{
	ESHUTTER_DISABLE=0,
	ESHUTTER_LOW=2,
	ESHUTTER_MIDDLE=4,
	ESHUTTER_HIGH=6,
	ESHUTTER_BUTT,
}CAM_ESHUTTER_TYPE_E;

typedef enum stCAM_LED_TYPE_E
{
	LED_TYPE_IR=0,
	LED_TYPE_WL=1,
	LED_TYPE_DOUBLE=2,
	LED_TYPE_MOOD=3,
	LED_TYPE_MUSIC=4,
	LED_TYPE_BUTT,
}CAM_LED_TYPE_E;

typedef enum stCAM_LED_OP_MODE_E
{
	LED_OP_MODE_AUTO=0,
	LED_OP_MODE_MANUAL=1,
	LED_OP_MODE_INTELL=2,
	LED_OP_MODE_DETER=3,
	LED_OP_MODE_BUTT,
}CAM_LED_OP_MODE_E;

typedef struct stCAM_COLOR_ATTR{
	ISP_U8 u8Brightness;
	ISP_U8 u8Contrast;
	ISP_U8 u8Saturation;
	ISP_U8 u8Hue;
	ISP_U8 u8Rsv0;
	ISP_U8 u8Rsv1;
	ISP_U16 u16Acutance;			//< ��ȣ�ȡֵ0-15, ��8λ��ʾˮƽ��ȣ���8Ϊ��ʾ��ֱ��ȡ�   	/
}CAM_COLOR_ATTR;

typedef struct stCAM_SOFTIR_THR
{
	int s32ColorExp;
	int s32ColorDlt;
	int s32ColorDlt2;
	int s32BwExp;
}CAM_SOFTIR_THR;

typedef struct stCAM_ATTR_PARA
{
	ISP_U32 u32EshutterLvEn;		// E Shutter enable level
	ISP_U32 u32EshutterLvDis;	// E Shutter Disbale level	
	CAM_SOFTIR_THR astSoftIr[6];	// Ĭ��ʹ��astSoftIr[3]	
	ISP_U32 au32Rsv[16];
}CAM_ATTR_PARA;



typedef struct stCAM_INNER_INFO
{
	ISP_U8 u8AiStrategyStr;	// AI��ز���ǿ��
	ISP_U8 u8InfraredStatus;
	ISP_U8 u8LedStab;		// �ƹ�״̬�ȶ�
	ISP_U8 u8DnStatus;	
	ISP_U8 au8Rsv[4];
	ISP_U16 au16Rsv[4];
	ISP_U32 u32ExpLines;
	ISP_U32 u32ExpAllGain;
	ISP_U32 au32Rsv[2];
}CAM_INNER_INFO;

/* �������������Ϣ */
typedef struct stCAM_IA_FD_REGION_INFO_S
{
    ISP_U8 u8ActiFlag;                    /* �������򼤻��־ */
    ISP_U16 u16AveLuma;                  /* ��������ƽ������ */
    ISP_U16 u16LumaMin;               /* ������ʶ����������*/
    ISP_U16 u16LumaMax;               /* ����ʶ����������*/
    ISP_U8 ucIrActiveFlag;       /* IRͨ�����������־ */
    ISP_U16 ucIrAveLightness;     /* IRͨ������ƽ������ */
    ISP_U16 ucIrLightnessLmtMin;  /* IRͨ��������������Ҫ�� */
    ISP_U16 ucIrLightnessLmtMax;  /* IRͨ��������������Ҫ�� */
    ISP_U16 u16stRegion[4];  /* ��ȡ������������λ��(�ڰ׹�ͼ�У��������0~8192) */
}CAM_IA_FD_REGION_INFO_S;

// �������
typedef struct stCAM_VENC_INFO
{
    ISP_U8    u8Compression;        /*!< ѹ��ģʽ */
    ISP_U8    u8BitRateControl;     /*!< �������� */
    ISP_U8    u8ImageSize;          /*!< ͼ��ֱ��� */
    ISP_U8    u8ImageQuality;       /*!< ͼ���� */
    ISP_U8    u8FramesPerSecond;    /*!< ֡�� */
    ISP_U8    u8AVOption;           /*!< ����Ƶѡ�� */
    ISP_U16   u16BitRate;            ///< �ο�����ֵ��KbpsΪ��λ
    ISP_U8    u8GOP;                /*< ֡�������ֵ������ֵ49��99*/
    ISP_U8    u8Reserved[3];        /*< �����ֽ�*/
} CAM_VENC_INFO;

typedef struct stCAM_AI_RESULT_S
{	
	/***
	u32Cmd: 
	 0: ���μ��
	 	0x01: ����(ȫ��)
	 	0x02: ����(����)
	 	0x03: ����(��ͷ)
	 0x10: ���Ƽ��
	 0x20: �ƶ���⣨�������ܾ���ʹ�ã�
	 0x40: �������
	***/
	 unsigned int u32Cmd;  /*������*/

	 unsigned int u32AlarmFlag; /*��������(����/����)1������(��⵽Ŀ��)  0��������(δ��⵽Ŀ��)*/

	 /***
	 u32TargetNum
	 	bit0~bit7: Ŀ�����    
	 	bit16~bit31: �����
	 ***/
	 unsigned int u32TargetNum; /*Ŀ����(����/����) */
	 
	/***
	u32Cmd = 0x10ʱ:
	 u32Reserved[0]:�����ʼ��ˮƽ����
	 u32Reserved[1]:�����ʼ�㴹ֱ����
	 u32Reserved[2]:��Ľ�����ˮƽ����
	 u32Reserved[3]:��Ľ����㴹ֱ����
	***/
	 unsigned int u32Reserved[64];
}CAM_AI_RESULT_S;

typedef struct stCAM_GET_AI_FUNC_S
{
	ISP_S32(*pfn_get_ai_result)(CAM_AI_RESULT_S *pstAiResult);	// ����ֵ��0:�ɹ�      	-1:ʧ��
} CAM_GET_AI_FUNC_S;



/*********************************** �ƶ������ز��� ***********************************/
typedef struct stCAM_MD_PARAM
{
	// ��̬�������жȵ���
	ISP_S32 s32Level;

	/**************************
	a.��λ��Ч(ÿλ��Ӧһ�����ο�)
	b.λ����:   	1:��Ҫ���    	0:������
	c.����߿��Ӧ���λ
	d.���ϵ��µ��ж�Ӧ���±��0��17
	**************************/
	ISP_U32 au32Win[18];

	// �����ȵľ���ֵ
	ISP_U8 u8Sensitiveness;

	// ֡���
	ISP_U8 u8Fieldinterval;

	// ʹ�ܿ���   	1:��ʾʹ�ܣ�0:��ʾ����(��������������)��
	ISP_S32 s32Enable;
}CAM_MD_PARAM;

typedef struct stCAM_MD_CAPS
{
	ISP_S32 s32Support;		// 1.֧�ּ��    	0:��֧��
	ISP_U32 u32GridLines;	// ��̬����������Ҫ���ֳɵ�������
	ISP_U32 u32GridRows;		// ��̬����������Ҫ���ֳɵ�������
	ISP_U8 u8Result;			// �Ƿ��ܵõ�ÿ������ļ������
	ISP_U8 u8Hint;			// �Ƿ����ڼ��ɹ�ʱ������ʾ��
}CAM_MD_CAPS;

typedef struct stCAM_MD_RESULT
{
	/**************************
	a.��λ��Ч(ÿλ��Ӧһ�����ο�)
	b.λ����:   	1:��������    	0:δ��������
	c.����߿��Ӧ���λ
	d.���ϵ��µ��ж�Ӧ���±��0��17
	**************************/
	ISP_U32 au32Win[18];
}CAM_MD_RESULT;


/*********************************** ��Ƶ�ڵ���ز��� ***********************************/
typedef struct stCAM_BD_CAPS
{
	ISP_U32 u32Surport;		// 1: ֧��   0:��֧��
}CAM_BD_CAPS;

typedef struct stCAM_BD_PARAM
{
	ISP_U8	u8Level;        // �ȼ� 1~6
	
	// ʹ�ܿ���   	1:��ʾʹ�ܣ�0:��ʾ����(��������������)��
	ISP_S32 s32Enable;
}CAM_BD_PARAM;





ISP_S32 XM_MPI_CAM_Init(ISP_S32 s32Rsv, ISP_VOID* pstAsConfig);
ISP_S32 XM_MPI_CAM_Exit(ISP_VOID);

ISP_S32 XM_MPI_CAM_SetPara(CAM_DEV CamDev, CAM_ATTR_PARA *pstConfig);
ISP_S32 XM_MPI_CAM_GetPara(CAM_DEV CamDev, CAM_ATTR_PARA *pstConfig);

ISP_S32 XM_MPI_CAM_SetScene(CAM_DEV CamDev, CAM_SCENE_TYPE_E enType);
ISP_S32 XM_MPI_CAM_GetScene(CAM_DEV CamDev, CAM_SCENE_TYPE_E *penType);

ISP_S32 XM_MPI_CAM_SetDncMode(CAM_DEV CamDev, CAM_DNC_MODE_E enMode);
ISP_S32 XM_MPI_CAM_GetDncMode(CAM_DEV CamDev, CAM_DNC_MODE_E *penMode);

ISP_S32 XM_MPI_CAM_SetDncThr(CAM_DEV CamDev, ISP_S32 s32Thr);
ISP_S32 XM_MPI_CAM_GetDncThr(CAM_DEV CamDev, ISP_S32 *ps32Thr);

ISP_S32 XM_MPI_CAM_SetDncThrSoftIR(CAM_DEV CamDev, ISP_S32 s32Thr);
ISP_S32 XM_MPI_CAM_GetDncThrSoftIR(CAM_DEV CamDev, ISP_S32 *ps32Thr);

ISP_S32 XM_MPI_CAM_SetDncSpeed(CAM_DEV CamDev, ISP_S32 s32Val);
ISP_S32 XM_MPI_CAM_GetDncSpeed(CAM_DEV CamDev, ISP_S32 *ps32Val);

ISP_S32 XM_MPI_CAM_GetDnStatus(CAM_DEV CamDev, CAM_DN_STATUS_E *penStatus);

ISP_S32 XM_MPI_CAM_SetLumTarget(CAM_DEV CamDev, ISP_S32 s32Tgt);
ISP_S32 XM_MPI_CAM_GetLumTarget(CAM_DEV CamDev, ISP_S32 *ps32Tgt);

ISP_S32 XM_MPI_CAM_SetBlc(CAM_DEV CamDev, ISP_U32 u32En, ISP_U32 u32Level);
ISP_S32 XM_MPI_CAM_GetBlc(CAM_DEV CamDev, ISP_U32 *pu32En, ISP_U32 *pu32Level);

ISP_S32 XM_MPI_CAM_SetHlc(CAM_DEV CamDev, ISP_S32 s32En, ISP_S32 s32Level);
ISP_S32 XM_MPI_CAM_GetHlc(CAM_DEV CamDev, ISP_S32 *ps32En, ISP_S32 *ps32Level);

ISP_S32 XM_MPI_CAM_SetExposureLvl(CAM_DEV CamDev, ISP_S32 s32Lvl, ISP_U32 u32MinUs, ISP_U32 u32MaxUs);
ISP_S32 XM_MPI_CAM_GetExposureLvl(CAM_DEV CamDev, ISP_S32 *ps32Lvl, ISP_U32 *pu32MinUs, ISP_U32 *pu32MaxUs);

ISP_S32 XM_MPI_CAM_SetGainLvl(CAM_DEV CamDev, ISP_S32 s32En, ISP_S32 s32Level);
ISP_S32 XM_MPI_CAM_GetGainLvl(CAM_DEV CamDev, ISP_S32 *ps32En, ISP_S32 *ps32Level);

ISP_S32 XM_MPI_CAM_SetMirror(CAM_DEV CamDev, ISP_S32 s32En);
ISP_S32 XM_MPI_CAM_GetMirror(CAM_DEV CamDev, ISP_S32 *ps32En);

ISP_S32 XM_MPI_CAM_SetFlip(CAM_DEV CamDev, ISP_S32 s32En);
ISP_S32 XM_MPI_CAM_GetFlip(CAM_DEV CamDev, ISP_S32 *ps32En);

ISP_S32 XM_MPI_CAM_SetAntiFlicker(CAM_DEV CamDev, ISP_S32 s32En, ISP_S32 s32Rsv);
ISP_S32 XM_MPI_CAM_GetAntiFlicker(CAM_DEV CamDev, ISP_S32 *ps32En, ISP_S32 *ps32Rsv);

ISP_S32 XM_MPI_CAM_SetEShutter(CAM_DEV CamDev, CAM_ESHUTTER_TYPE_E enType);
ISP_S32 XM_MPI_CAM_GetEShutter(CAM_DEV CamDev, CAM_ESHUTTER_TYPE_E *penType);

ISP_S32 XM_MPI_CAM_SetNrLevel(CAM_DEV CamDev, CAM_DN_STATUS_E enDnMode, ISP_S32 s32Val);
ISP_S32 XM_MPI_CAM_GetNrLevel(CAM_DEV CamDev, CAM_DN_STATUS_E enDnMode, ISP_S32 *ps32Val);

ISP_S32 XM_MPI_CAM_GetWdr(CAM_DEV CamDev, ISP_S32 *ps32En, ISP_S32 *ps32Val);
ISP_S32 XM_MPI_CAM_SetWdr(CAM_DEV CamDev, ISP_S32 s32En, ISP_S32 s32Val);

ISP_S32 XM_MPI_CAM_GetDefog(CAM_DEV CamDev, ISP_S32 *ps32En, ISP_S32 *ps32Val);
ISP_S32 XM_MPI_CAM_SetDefog(CAM_DEV CamDev, ISP_S32 s32En, ISP_S32 s32Val);

ISP_S32 XM_MPI_CAM_GetImgStyle(CAM_DEV CamDev, CAM_IMG_STYLE_E *penImgStyle);
ISP_S32 XM_MPI_CAM_SetImgStyle(CAM_DEV CamDev, CAM_IMG_STYLE_E enImgStyle);

ISP_S32 XM_MPI_CAM_SetIcrSwap(CAM_DEV CamDev, ISP_S32 s32En);
ISP_S32 XM_MPI_CAM_GetIcrSwap(CAM_DEV CamDev, ISP_S32 *ps32En);

ISP_S32 XM_MPI_CAM_SetInfraredSwap(CAM_DEV CamDev, ISP_S32 s32En);
ISP_S32 XM_MPI_CAM_GetInfraredSwap(CAM_DEV CamDev, ISP_S32 *ps32En);

ISP_S32 XM_MPI_CAM_SetColor(CAM_DEV CamDev, CAM_COLOR_ATTR stColorAttr);
ISP_S32 XM_MPI_CAM_GetColor(CAM_DEV CamDev, CAM_COLOR_ATTR *pstColorAttr);

ISP_S32 XM_MPI_CAM_GetAiFdRegion(CAM_DEV CamDev, CAM_IA_FD_REGION_INFO_S *pstAiFdRegionInfo);

ISP_S32 XM_MPI_CAM_SetLedMode(CAM_DEV CamDev, CAM_LED_TYPE_E enType, CAM_LED_OP_MODE_E enMode, ISP_S32 s32Status);
ISP_S32 XM_MPI_CAM_GetLedMode(CAM_DEV CamDev, CAM_LED_TYPE_E *penType, CAM_LED_OP_MODE_E *penMode, ISP_S32 *ps32Status);

ISP_S32 XM_MPI_CAM_SetLedLevel(CAM_DEV CamDev, ISP_S32 s32Rsv, ISP_S32 s32Val);
ISP_S32 XM_MPI_CAM_GetLedLevel(CAM_DEV CamDev, ISP_S32 s32Rsv, ISP_S32 *ps32Val);

ISP_S32 XM_MPI_CAM_SetLedType(CAM_DEV CamDev, ISP_S32 s32Type);
ISP_S32 XM_MPI_CAM_GetLedType(CAM_DEV CamDev, ISP_S32 *ps32Type);

ISP_S32 XM_MPI_CAM_SetLedDrvSwap(CAM_DEV CamDev, ISP_S32 s32SWapEn);
ISP_S32 XM_MPI_CAM_GetLedDrvSwap(CAM_DEV CamDev, ISP_S32 *ps32SWapEn);

ISP_S32 XM_MPI_CAM_SetLedHold(CAM_DEV CamDev, ISP_U32 u32Tms);
ISP_S32 XM_MPI_CAM_GetLedHold(CAM_DEV CamDev, ISP_U32 *pu32Tms);

ISP_S32 XM_MPI_CAM_GetStabState(CAM_DEV CamDev, ISP_U32 *pu8StateFlg);

ISP_S32 XM_MPI_CAM_SetAperture(CAM_DEV CamDev, ISP_U32 u32Mode);
ISP_S32 XM_MPI_CAM_GetAperture(CAM_DEV CamDev, ISP_U32 *pu32Mode);

ISP_S32 XM_MPI_CAM_SetAeSensitivity(CAM_DEV CamDev, ISP_S32 s32Level);
ISP_S32 XM_MPI_CAM_GetAeSensitivity(CAM_DEV CamDev, ISP_S32 *ps32Level);

ISP_S32 XM_MPI_CAM_SetDnSensitivity(CAM_DEV CamDev, ISP_S32 s32Level);
ISP_S32 XM_MPI_CAM_GetDnSensitivity(CAM_DEV CamDev, ISP_S32 *ps32Level);

ISP_S32 XM_MPI_CAM_SetIrcutMode(CAM_DEV CamDev, ISP_S32 s32Mode);
ISP_S32 XM_MPI_CAM_GetIrcutMode(CAM_DEV CamDev, ISP_S32 *ps32Mode);

ISP_S32 XM_MPI_CAM_SetVStd(CAM_DEV CamDev, ISP_U32 u32Std);
ISP_S32 XM_MPI_CAM_GetVStd(CAM_DEV CamDev, ISP_U32 *pu32Std);

ISP_S32 XM_MPI_CAM_SetInfraredSwap(CAM_DEV CamDev, ISP_S32 s32En);
ISP_S32 XM_MPI_CAM_GetInfraredSwap(CAM_DEV CamDev, ISP_S32 *ps32En);


ISP_S32 XM_MPI_CAM_GetInfo(CAM_DEV CamDev, CAM_INNER_INFO *pstInfo);
ISP_S32 XM_MPI_CAM_AiFunRegCallBack(CAM_DEV CamDev, CAM_GET_AI_FUNC_S *pstGetAiFunc);

ISP_S32 XM_MPI_CAM_GetDnDouble(CAM_DEV CamDev, ISP_U32 *pu32Mode);
ISP_S32 XM_MPI_CAM_SetSensorState(CAM_DEV CamDev, ISP_S32 ps32Mode);
ISP_S32 XM_MPI_CAM_SetAEMod(CAM_DEV CamDev, ISP_S32 ps32Mode);
ISP_S32 XM_MPI_CAM_Getqrcode(CAM_DEV CamDev, ISP_S32 *ps32Mode);
ISP_S32 XM_MPI_CAM_Setqrcode(CAM_DEV CamDev, ISP_S32 ps32Mode);
ISP_S32 XM_MPI_CAM_GetCaptureSize(CAM_DEV CamDev, ISP_S32 *ps32Mode);
ISP_S32 XM_MPI_CAM_SetCaptureSize(CAM_DEV CamDev, ISP_S32 ps32Mode);


/*********************************** �ƶ������ؽӿ� ***********************************/
ISP_S32 XM_MPI_CAM_MD_Create(CAM_DEV CamDev);
ISP_S32 XM_MPI_CAM_MD_Destory(CAM_DEV CamDev);

ISP_S32 XM_MPI_CAM_MD_GetCaps(CAM_DEV CamDev, CAM_MD_CAPS *pstCaps);
ISP_S32 XM_MPI_CAM_MD_SetPara(CAM_DEV CamDev, CAM_MD_PARAM stPara);

ISP_S32 XM_MPI_CAM_MD_GetStatus(CAM_DEV CamDev, ISP_U32 *pu32Val);
ISP_S32 XM_MPI_CAM_MD_GetResult(CAM_DEV CamDev, CAM_MD_RESULT *pstResult);


/*********************************** ��Ƶ�ڵ���ؽӿ� ***********************************/
ISP_S32 XM_MPI_CAM_BD_GetCaps(CAM_DEV CamDev, CAM_BD_CAPS *pstCaps);
ISP_S32 XM_MPI_CAM_BD_SetPara(CAM_DEV CamDev, CAM_BD_PARAM stPara);
ISP_S32 XM_MPI_CAM_BD_GetStatus(CAM_DEV CamDev, ISP_U32 *pu32Val);

#ifdef __cplusplus
}
#endif

#endif

