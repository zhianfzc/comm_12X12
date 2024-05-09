//
//  "$Id: Camera.h 4 2011-09-14 14:13:30Z xiaoyongli $"
//
//  Copyright (c)2008-2008, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//
#ifndef __CAMERA_H__
#define __CAMERA_H__ 

#ifdef __cplusplus
extern "C" {
#endif
#include "isp_type.h"


#define GET_REJECT_SHAKE_TIME(cfgTime)  ((cfgTime)*20)
#define BYTE		unsigned char
#define WORD	unsigned short




enum dvr_info_cmd_hs
{
	PRODUCT_TYPE 		= 0,
	VIDEO_CHANNEL 		= 1,
	AUDIO_CHANNEL 		= 2,
	ALARM_IN 			= 3,
	ALARM_OUT			= 4,
	FVIDEO_CHIP			= 5,
	DSP_CHIP 			= 6,
	ANALOG_AUDIO_MODE	= 7,
	TALKBACK			= 8,
	BVIDEO_CHIP			= 9,
	STORE_INTERFACE 	= 10,
	MATRIX		 		= 11,
	WIRELESS_INTERFACE	= 12,
	HD_ENCODE			= 13,
	HD_VERSION 			= 14,
	VD_INTERFACE        = 15,
	NET_INTERFACE       = 16,
	HD_INFO_LEN			= 17
};


enum netmode{
	NET_LAN = 0,
	NET_WLAN_8188EU
};

typedef enum _resolution_bit_{
	RSLTION_BIT_720P = 0,
	RSLTION_BIT_960P,
	RSLTION_BIT_1080P,
	RSLTION_BIT_1536P,
	RSLTION_BIT_4MP,
	RSLTION_BIT_5MP,
	RSLTION_BIT_8MP,

	RSLTION_BIT_BUTT
}RSLTION_BIT;




typedef enum {
	BLIGHT_CLOSE = 0x10,
	BLIGHT_OPEN = 0x11,
	CLIGHT_CLOSE = 0x20,
	MUSICLIGHT_OPEN = 0x21,
	MOODLIGHT_OPEN = 0x22,
}enLIGHT_CTRL;

typedef struct stCOORD_S
{
    int s32X;
    int s32Y;
}COORD_S;

typedef enum IRCUT_SWITCH_MODE
{
	IRCUT_SYN_INFRARED,
	IRCUT_SWITCH_AUTO,
	IRCUT_BUTT
}IRCUT_SWITCH_MODE;
typedef enum DNC_MODE
{
	DNC_AUTO,			// �Զ��л�
	DNC_MULTICOLOR,		// ��ɫ
	DNC_BLACKWHITE,		// ǿ��Ϊ�ڰ�ģʽ
	DNC_INTE_WHITE_INF, //���ܾ���
	DNC_WHITELAMP_AUTO, //����ů��
	DNC_IRLAMP_AUTO,	//���ܺ���
	DNC_LP_MODE,		//����ģʽ
	DNC_BUTT
}DNC_MODE;

typedef enum IRCUT_MODE
{
	IRCUT_NIGHT,///����
	IRCUT_DAY,///�����˹�Ƭ
	IRCUT_AUTO,
}IRCUT_MODE;

typedef enum CAMERA_SCENE
{
	SCENE_AUTO,
	SCENE_INDOOR,
	SCENE_OUTDOOR,
	SCENE_BUTT,
}CAMERA_SCENE;
typedef enum IRCUT_SWITCH_DIRECTION
{
	NORMAL_DIRECTION,
//	CONTRARY_DIRECTION
}IRCUT_SWITCH_DIRECTION;

typedef struct stMOVEMENT_DATA_S
{
	 int 	reg_addr; 
	 int 	data; 
	 int   mode;
}MOVEMENT_DATA_S ;

/// ��Ƶ��ɫ��ʽ
typedef struct CAMERA_COLOR{
	unsigned char	Brightness;		///< ���ȣ�ȡֵ0-100��
	unsigned char	Contrast;		///< �Աȶȣ�ȡֵ0-100��
	unsigned char 	Saturation;		///< ���Ͷȣ�ȡֵ0-100��
	unsigned char 	Hue;			///< ɫ����ȡֵ0-100��
	unsigned char 	Gain;			///< ���棬ȡֵ0-100��bit7��λ��ʾ�Զ����棬����λ�����ԡ�
	unsigned char	WhiteBalance;	///< �Զ��׵�ƽ���ƣ�bit7��λ��ʾ�����Զ�����.0x0,0x1,0x2�ֱ�����,��,�ߵȼ�
	unsigned short	Acutance;       	///< ��ȣ�ȡֵ0-15, ��8λ��ʾˮƽ��ȣ���8Ϊ��ʾ��ֱ��ȡ�
}CAMERA_COLOR;	// ��VIDEO_COLORһ��

// �������
typedef struct tagCAPTURE_FORMAT
{
    BYTE    Compression;        /*!< ѹ��ģʽ */
    BYTE    BitRateControl;     /*!< �������� */
    BYTE    ImageSize;          /*!< ͼ��ֱ��� */
    BYTE    ImageQuality;       /*!< ͼ���� */
    BYTE    FramesPerSecond;    /*!< ֡�� */
    BYTE    AVOption;           /*!< ����Ƶѡ�� */
    WORD    BitRate;            ///< �ο�����ֵ��KbpsΪ��λ
    BYTE    GOP;                /*< ֡�������ֵ������ֵ49��99*/
    BYTE    reserved[3];        /*< �����ֽ�*/
} CAPTURE_FORMAT;

//����VI���ڳߴ�Ľṹ��
typedef struct st_VI_WIN_S
{
    unsigned int u32Width;
    unsigned int u32Height;
    unsigned int u32TotalWidth;
    unsigned int u32TotalHeight;
}VI_WIN_S;


typedef struct st_CAMERA_INIT_ATTR_S
{
	unsigned char u8ProductFun;	//��Ʒ����(����)  --- ��:0x10ʱ ΪС����(�͹��ġ�Ƶ�ʼ���)
	unsigned char u8ProductLow;	//��Ƶ����(0����׼Ƶ��    		1��Ƶ�ʼ��루֡�ʼ��룩
	unsigned char u8SnsConnect;	//����sensor ���� ָ��DVP/MIPI
	unsigned char u8MipiLane;
	unsigned char u8MipiBit;
	unsigned char au8Rsv[11];
}CAMERA_INIT_ATTR_S;


typedef struct st_AIRSLT_INFO_S
{
    unsigned char u8AlarmFlg;	//1: ��������   	0:δ����
    unsigned int u32TargetNum;	// Ŀ�����;
    unsigned int u32Info[64];		// ������Ϣ(�����)
}AIRSLT_INFO_S;

typedef struct stISP_GET_AI_RESULT_S
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
}ISP_GET_AI_RESULT_S;

typedef struct stISP_GET_AI_FUNC_S
{
	int(*pfn_get_ai_result)(ISP_GET_AI_RESULT_S *pstAiResult);	// ����ֵ��0:�ɹ�      	-1:ʧ��
} ISP_GET_AI_FUNC_S;



/*************************************************************************
��������:	��ȡ/���� ��ҹģʽ
�������:			0:	Auto
				1:	Color
				2:	BW
				3:	���ܾ���
				4: 	����ů��(�ɱ��)
				5:	���ܺ���
				6:	����ģʽ
note:
*************************************************************************/
int camera_set_dnc_mode_chn(int chn, unsigned int mode);
int camera_get_dnc_mode_chn(int chn, unsigned int *pMode);
int camera_get_dnc_mode(unsigned int *pMode);
int camera_set_dnc_mode(unsigned int mode);


/*************************************************************************
��������:	��ȡ֧�ֵ��ع�ȼ���
�������:		chn: ͨ����[0,2]
			vstd: ��ʽ[0,1](0:PAL 1:NTSC)
			speeds: ÿ���ȼ���ֵ
���ز���:		֧�ֵĵȼ��ĸ���
*************************************************************************/
int camera_get_exposure_speeds_chn(int chn, int vstd, unsigned int *speeds);
int camera_get_exposure_speeds(int vstd, unsigned int *speeds);


/*************************************************************************
��������:	�ع�ģʽ����
�������:		chn: ͨ����[0,2]
			level:	0		�Զ��ع�
					1~9		�ֶ��ع�(�̶�����)	
			value1:	�ع�����(min,us)
			value2:	�ع�����(max,us)
�������:		pLevel:	0		�Զ��ع�
					1~9		�ֶ��ع�(�̶�����)	
			pValue1:	�ع�����(min,us)
			pValue2:	�ع�����(max,us)
note:	
	�Զ��ع�(��������Ч)  		level :0
	�Զ��ع�(��������Ч)  		level :255
	�ֶ��ع�(�̶�����)			level :1~9
*************************************************************************/
int camera_set_exposure_level_chn(int chn, int level, unsigned int u32MinUs, unsigned int u32MaxUs);
int camera_get_exposure_level_chn(int chn, int *pLevel, unsigned int *pValue1, unsigned int *pValue2);
int camera_get_exposure_level(int *pLevel, unsigned int *pValue1, unsigned int *pValue2);
int camera_set_exposure_level(int level, unsigned int value1, unsigned int value2);

/*******************************************************************
��������:	����/��ȡ�Զ�����
�������:		chn: ͨ����[0,2]
			s32GainMax:	�������( 	[0,100] def: 50)
			s32AutoEn:	�Զ�����ʹ��	([0,1]		def: 1)
�������:		pGainLevel:	�������( 	[0,100] def: 50)
			pAutoEn:	�Զ�����ʹ��	([0,1]		def: 1)
���ز���:	0 	�ɹ�
				-1	����
Note:			Lycai
*******************************************************************/
int camera_set_gain_chn(int chn, int s32GainMax, int s32AutoEn);
int camera_get_gain_chn(int chn, int *pGainLevel, int *pAutoEn);
int camera_get_gain(int *pGainLevel, int *pAutoEn);
int camera_set_gain(int s32GainMax, int s32AutoEn);


/*******************************************************************
��������:	����/��ȡ�ع�ο�
�������:		chn: ͨ����[0,2]
			level: Ŀ��ȼ�[0,100] def:50
�������:	��
���ز���:	0 	�ɹ�
				-1	����
Note:			Lycai
*******************************************************************/
int camera_set_refrence_level_chn(int chn, int level);
int camera_get_refrence_level_chn(int chn);
int camera_get_refrence_level(void);
int camera_set_refrence_level(int level);


/*******************************************************************
��������:	��ȡƽ������ֵ
�������:		chn: ͨ����[0,2]
���ز���:		��ǰ����
���ز���:	0 	�ɹ�
				-1	����
Note:			Lycai
	��δ֧��
*******************************************************************/
int camera_get_luminance_chn(int chn);
int camera_get_luminance(void);


/*******************************************************************
��������:	��ȡ״̬
�������:		chn: ͨ����[0,2]
�������:		status:
				>=0��ʾ״̬����,<0��ʾ״̬�쳣
���ز���:		0 	�ɹ�
			-1	����
Note:			Lycai
	��δ֧��
*******************************************************************/
int camera_get_status_chn(int chn, int *status);
int camera_get_status(int *status);


/*******************************************************************
��������:	�����Զ���Ȧ(��/�ر�)
�������:		chn: ͨ����[0,2]
�������:		mode: [0,1]  0:�ر� 1:��
���ز���:		0 	�ɹ�
			-1	����
Note:			Lycai
*******************************************************************/
int camera_set_aperture_chn(int chn, unsigned int mode);
int camera_set_aperture(unsigned int mode);


/*******************************************************************
��������:	����/��ȡ���ⲹ��
�������:		chn: ͨ����[0,2]
			u32Enable: ʹ�ܿ���[0,1]
			u32Level: ǿ�ȵȼ�[0,100] def:0
�������:		pu32Enable: ʹ�ܿ���[0,1]
			pu32Level: ǿ�ȵȼ�[0,100] def:0
���ز���:	0:	 �ɹ�
		 -1: ʧ��
*******************************************************************/
int camera_set_blc_chn_v2(int chn, unsigned int u32Enable, unsigned int u32Level);
int camera_get_blc_chn_v2(int chn, unsigned int *pu32Enable, unsigned int *pu32Level);
int camera_get_blc(unsigned int *pMode);
int camera_set_blc(unsigned int mode);
int camera_set_blc_v2(unsigned int u32Enable, unsigned int u32Level);
int camera_get_blc_v2(unsigned int *pu32Enable, unsigned int *pu32Level);

int camera_get_face_exposure(unsigned int *pu32Enable);
int camera_set_face_exposure(unsigned int u32Enable);

int camera_get_plate_exposure(unsigned int *pu32Enable);
int camera_set_plate_exposure(unsigned int u32Enable);

/*******************************************************************
��������:	����/��ȡ�龰ģʽ
�������:		chn: ͨ����[0,2]
			scene: ģʽ[0,2]
�������:	pScene: ģʽ[0,2]
���ز���:	0:	 �ɹ�
		 -1: ʧ��
*******************************************************************/
int camera_set_scene_chn(int chn, CAMERA_SCENE scene);
int camera_get_scene_chn(int chn, CAMERA_SCENE* pScene);

int camera_get_scene(CAMERA_SCENE* pScene);
int camera_set_scene(CAMERA_SCENE scene);


/*******************************************************************
��������:	��ȡ����������״̬(��ǰ)
�������:	chn: ͨ����[0,2]
�������:	*pu8EShutterSts:
					 fps' = fps*0x10/gu8EshutterSts
���ز���:	0:	�ɹ�
				-1:	ʧ��
*******************************************************************/
int camera_get_es_status_chn(ISP_S32 chn, ISP_U8 *pu8EShutterSts);
int camera_get_es_status(unsigned char *pu8EShutterSts);


/*************************************************************************
��������: 	��֡���ܣ�ʹ�ܣ�
�������:		chn: ͨ����[0,2]
			es_shutter: 
					0:		1/1
					2:		1/2 (default)
					4:		1/3
					6:		1/4
�������:	pEshutterLevel
					0:		1/1
					2:		1/2 (default)
					4:		1/3
					6:		1/4	
���ز���:	0:	�ɹ�
				-1:	����
*************************************************************************/
int camera_set_es_shutter_chn(int chn, int es_shutter);
int camera_get_es_shutter_chn(int chn, int *pEshutterLevel);
int camera_get_es_shutter(int *pEshutterLevel);
int camera_set_es_shutter(int es_shutter);


/*******************************************************************
��������:	����/��ȡ�չ�Ʒ���
�������:		chn: ͨ����[0,2]
			en: ʹ�ܿ���[0,1] def:0
�������:		pEn: ʹ�ܿ���[0,1] def:0
���ز���:	0:	 �ɹ�
		 -1: ʧ��
*******************************************************************/
int camera_set_reject_flicker_chn(int chn, int en);
int camera_get_reject_flicker_chn(int chn, int *pEn);
int camera_get_reject_flicker(int *pEn);
int camera_set_reject_flicker(int en);


/*************************************************************************
��������: 	��ҹ�л���ֵ
�������:		chn: [0,2]
			dnc_thr: [10,50] def:30
�������:		pDnc_thr
���ز���:		0:	�ɹ�
			-1:	����
*************************************************************************/
int camera_set_dnc_thr_chn(int chn, int dnc_thr);
int camera_get_dnc_thr_chn(int chn, int *pDnc_thr);
int camera_get_dnc_thr(int *pDnc_thr);
int camera_set_dnc_thr(int dnc_thr);


/*******************************************************************
��������:	��ȡ/���� ��ҹ����������
�������:		chn: [0,2]
			level: [1,10] def:5
�������:	* pLevel:	[1,10] def:5
���ز���:	0 	�ɹ�
				-1	����
Note:			Lycai
*******************************************************************/
int camera_set_ae_sensitivity_chn(int chn, int level);
int camera_get_ae_sensitivity_chn(int chn, int* pLevel);
int camera_get_ae_sensitivity(int*pLevel);
int camera_set_ae_sensitivity(int ae_sensitivity);


/*******************************************************************
��������:	��ȡ/���� AE����������
�������:		chn: [0,2]
			level: [1,10] def:5
�������:		*pLevel: [1,10] def:5
���ز���:		0 	�ɹ�
			-1	����
Note:			Lycai
*******************************************************************/
int camera_set_ae_sensitivity2_chn(int chn, int level);
int camera_get_ae_sensitivity2_chn(int chn, int* pLevel);
int camera_get_ae_sensitivity2(int* pLevel);
int camera_set_ae_sensitivity2(int level);


/*******************************************************************
��������:	��ȡ/���� IRCUT״̬
�������:		chn:ͨ���� [0,2]
			mode:[0,1]  0:���˺���	1:�˺���
�������:	��
���ز���:	0 	�ɹ�
				-1	����
Note:			Lycai
*******************************************************************/
int camera_set_ircut_chn(int chn, int mode);
int camera_set_Ircut(int mode);


/*******************************************************************
��������:	��ȡ�ư�״̬
�������:		chn:ͨ���� [0,2]
�������:		��
���ز���:		0: ����
			1: ����
			-1	����
			others: ��֧��
Note:			Lycai
*******************************************************************/
int camera_get_infrared_chn(int chn);
int camera_get_Infrared(void);


/*******************************************************************
��������:	��ȡ/������ҹ����ȼ�
�������:		chn: [0,2]
			daynight(��ɫ/�ڰ�):[0,1]		
				0(Color) 
				1(BW)
			nf_level(����ȼ�):[0,5] Def:3
�������:		pNrLevel(����ȼ�):[0,5] Def:3
���ز���:	0 	�ɹ�
				-1	����
Note:			Lycai
*******************************************************************/
int camera_set_nf_level_chn(int chn, int daynight, int nf_level);
int camera_get_nf_level_chn(int chn, int daynight, int *pNrLevel);
int CameraGetNFLevel(int daynight, int *pNrLevel);
int CameraSetNFLevel(int daynight, int nf_level);


/*******************************************************************
��������:	��ȡ/����IRCUT����
�������:		chn: [0,2]
			s32Wap(����):[0,1]		
				0(����) 
				1(����)
�������:		ps32Swap:[0,1]		
				0(����) 
				1(����)
���ز���:	0 	�ɹ�
				-1	����
Note:			Lycai
*******************************************************************/
int camera_set_icr_swap_chn(int chn, int s32Wap);
int camera_get_icr_swap_chn(int chn, int *ps32Swap);
int CameraGetSwapICR(int *pSwap);
int CameraSwapICR(int swap);


/*******************************************************************
��������:	��ȡ/���ÿ�̬
�������:		chn: [0,2]
			level(ǿ�ȵȼ�):[0,100] Def:50
			enable(ʹ�ܿ���):[0,1] Def:0
�������:		pLevel(ǿ�ȵȼ�):[0,100] Def:50
			pEnable(ʹ�ܿ���):[0,1] Def:0
���ز���:	0 	�ɹ�
				-1	����
Note:			Lycai
*******************************************************************/
int camera_get_wdr_chn(int chn, int* pLevel, int* pEnable);
int camera_set_wdr_chn(int chn, int level, int enable);
int camera_get_wdr(int* pLevel, int* pEnable);
int camera_set_wdr(int level, int enable);


/*******************************************************************
��������:	��ȡ/���� ͼ����
�������:		chn: [0,2]
			choice: [0,2] def:1
�������:	*pChoice:	[0,2] def:1
���ز���:	0 	�ɹ�
				-1	����
Note:			Lycai
*******************************************************************/
int camera_get_style_chn(int chn, int *pChoice);
int camera_set_style_chn(int chn, int choice);
int Camera_Get_StyleMode(int *pChoice);
int Camera_Set_StyleMode(int choice);		


/*******************************************************************
��������:	��ȡ/���� IRCUTͬ����ʽ
�������:		chn: [0,2]
			ircut_mode: [0,1]
				0: �����ͬ��
				1: �Զ�ͬ��
�������:		*pIrcutMode: [0,1]
				0: �����ͬ��
				1: �Զ�ͬ��
���ز���:		0 	�ɹ�
			-1	����
Note:			Lycai
*******************************************************************/
int camera_set_ircut_mode_chn(int chn, int ircut_mode);
int camera_get_ircut_mode_chn(int chn, int *pIrcutMode);
int camera_get_ircut_mode(int *pIrcutMode);
int camera_set_ircut_mode(int ircut_mode);


/*******************************************************************
��������:	��ȡ/���� �������ң�
�������:		chn: [0,2]
			mirror: [0,1] def:0
�������:	*pMirror:	[0,1] def:0
���ز���:	0 	�ɹ�
				-1	����
Note:			Lycai
*******************************************************************/
int camera_set_mirror_chn(int chn, int mirror);
int camera_get_mirror_chn(int chn, int *pMirror);
int camera_get_mirror(int *pMirror);
int camera_set_mirror(int mirror);


/*******************************************************************
��������:	��ȡ/���� ��ת�����£�
�������:		chn: [0,2]
			flip: [0,1] def:0
�������:	*pFlip:	[0,1] def:0
���ز���:	0 	�ɹ�
				-1	����
Note:			Lycai
*******************************************************************/
int camera_set_flip_chn(int chn, int flip);
int camera_get_flip_chn(int chn, int *pFlip);
int camera_get_flip(int *pFlip);
int camera_set_flip(int flip);


/*************************************************************************
��������: 	ͼ����ɫ(Web) �ӿ�
�������:	channel:	 ��Ч
				pColor:
					Brightness: ����(0~100)
					Contrast: �Աȶ�(0~100)
					Saturation: ���Ͷ�(0~100)
					Hue:	ɫ��(0~100)
					Acutance: ��(0~15)
���ز���:	0:	�ɹ�
				-1:	����
*************************************************************************/
int camera_get_color_chn(int channel, CAMERA_COLOR * pColor);
int camera_set_color_chn(int channel, CAMERA_COLOR * pColor);


/*************************************************************************
��������: 	��ȡ/���� ��Ƶ��ʽ(PAL/NTSC)
�������:	channel:	 ��Ч
				u32Vstd: 0:(UN)
						1:PAL
						2:NTSC
�������:	*pu32Vstd	0:(UN)
							1:PAL
							2:NTSC
���ز���:	0:	�ɹ�
				-1:	����
*************************************************************************/
int camera_get_vstd(int channel,unsigned int *pu32Vstd);
int camera_set_vstd(int channel,unsigned int u32Vstd);


/*************************************************************************
��������:	��ȡ/���� ȥα��
�������:		chn:[0,2]
			u32Level:[0,100](def:0)
�������:	pu32Level:	[0,100](def:0)
���ز���:	0:	�ɹ�
				-1:	����
*************************************************************************/
int camera_set_demoire_chn(int chn,unsigned int u32Level);
int camera_get_demoire_chn(int chn,unsigned int *pu32Level);
int camera_set_antiFalseColor(unsigned int u32Level);
int camera_get_antiFalseColor(unsigned int *pu32Level);


/*************************************************************************
��������: 	��ȡ/���� ȥ���
�������:		chn:[0,2]
			u32Level:[0,100](def:0)
�������:	pu32Level:[0,100](def:0)
���ز���:	0:	�ɹ�
				-1:	����
*************************************************************************/
int camera_set_sawtooth_chn(int chn, unsigned int u32Level);
int camera_get_sawtooth_chn(int chn, unsigned int *pu32Level);
int camera_set_sawtooth(unsigned int u32Level);
int camera_get_sawtooth(unsigned int *pu32Level);


/*************************************************************************
��������: 	��ȡ/���� ǿ�����ƣ���������أ�
�������:		chn: ͨ����[0,2]
			Enable: ʹ�ܿ���[0,1] def:0
�������:		pEnable: ʹ�ܿ���[0,1] def:0
���ز���:	0:	�ɹ�
				-1:	����
*************************************************************************/
int camera_set_hlc_chn(int chn,int Enable);
int camera_get_hlc_chn(int chn,int *pEnable);
int camera_set_hlc(int Enable);
int camera_get_hlc(int *pEnable);



/*************************************************************************
��������:	��ȡ��ҹ״̬
�������: chn: ͨ����[0,2]
�������:	pu8Mode:
					0:	Color
					1:    BW
note:
*************************************************************************/
int camera_get_dn_state_chn(int chn, unsigned char *pu8Mode);
int camera_get_dn_state(unsigned char *pu8Mode);
int camera_get_dn_state_double_chn(int chn, unsigned int *pu8Mode);

/*************************************************************************
��������: 	����/��ȡ LEDģʽ
�������:		chn:ͨ����[0,2]
			s32Mode:	0xAB(	A:	0: IR   1: WL   --- ����ȡʱ��Ч
							 	B:	0:Auto  1:Manual  2:Intelligence)
			s32State(for Manual mode): 	0:Close 1:Open
�������:		ps32Mode:	0xAB(	A:	0: IR   1: WL   --- ����ȡʱ��Ч
							 	B:	0:Auto  1:Manual  2:Intelligence)
			ps32State(for Manual mode): 	0:Close 1:Open
���ز���:		0:	�ɹ�
			-1:	����
*************************************************************************/
int camera_set_ledMode_chn(int chn, int s32Mode, int s32State);
int camera_get_ledMode_chn(int chn, int *ps32Mode, int *ps32State);
int camera_set_ledMode(int s32Mode, int s32State);
int camera_get_ledMode(int *ps32Mode, int *ps32State);


/*************************************************************************
��������: 	���� LED����
�������:		chn:ͨ���� [0,2]
			s32Type:[0,2]	0: IR   1: WL  2:Double
�������:	ps32Type:[0,2]	0: IR   1: WL  2:Double
���ز���:	0:	�ɹ�
				-1:	����
*************************************************************************/
int camera_set_ledType_chn(int chn, int s32Type);
int camera_get_ledType_chn(int chn, int *ps32Type);
int camera_set_ledType(int s32Type);
int camera_get_ledType(int *ps32Type);


/*************************************************************************
��������: 	����/��ȡ LED���ȵȼ�
�������:		chn:ͨ���� [0,2]
			s32Mode: ������(����)  0:�׹��
			s32Level: ���ȵȼ� (0~100)
�������:	ps32Level: ���ȵȼ� (0~100)
���ز���:	0:	�ɹ�
				-1:	����
*************************************************************************/
int camera_set_ledLumLevel_chn(int chn, int s32Mode, int s32Level);
int camera_get_ledLumLevel_chn(int chn, int s32Mode, int *ps32Level);
int camera_set_ledLumLevel(int s32Mode, int s32Level);
int camera_get_ledLumLevel(int s32Mode, int *ps32Level);


/*************************************************************************
��������: 	����/��ȡ �ƶ����(�����㷨)���
�������:		chn:ͨ���� [0,2]
			u8MovFlg:[0,1]  1:����(�ƶ����)����
�������:		pu8MovFlg:[0,1]  1:����(�ƶ����)����
���ز���:		0:	�ɹ�
			-1:	����
*************************************************************************/
int camera_set_smartVda_chn(int chn,unsigned char u8MovFlg);
int camera_get_smartVda_chn(int chn, unsigned char *pu8MovFlg);
int camera_set_smartVda(unsigned char u8MovFlg);
int camera_get_smartVda(unsigned char *pu8MovFlg);


/*************************************************************************
��������: 	��ȡ�ȶ�״̬(����)
�������:	chn: ͨ����[0,2]
�������:	pu8StateFlg
					0: �ȶ�
					1: ����LED
���ز���:	0:	�ɹ�
				-1:	����
*************************************************************************/
int camera_get_stabState_chn(int chn,unsigned char *pu8StateFlg);
int camera_get_stabState(unsigned char *pu8StateFlg);


/*************************************************************************
��������: 	��ȡ ����LED����ʱ��(ms)
�������:		chn: ͨ����[0,2]
			s32Tms:  ����ʱ��(ms) ----(����100ms)
�������:	��
���ز���:	0:	�ɹ�
				-1:	����
*************************************************************************/
int camera_set_ledHold_chn(int chn,int s32Tms);
int camera_get_ledHold_chn(int chn,int *ps32Tms);
int camera_set_ledHold(int s32Tms);
int camera_get_ledHold(int *ps32Tms);


/*************************************************************************
��������: 		�������η�����ʹ��
�������:		chn:ͨ����[0,2]
			en:	1:ʹ��   0:����
�������:		ps32En
���ز���:		0:	�ɹ�
			-1:	����
*************************************************************************/
int camera_set_aeweight_chn(int chn, int en);
int camera_get_aeweight_chn(int chn, int *ps32En);
int camera_set_aeweight(int en);
int camera_get_aeweight(int *ps32En);


/*************************************************************************
��������:		�����������ֵ
�������:		chn:ͨ����[0,2]
			dnc_thr:[1,5] def:3 (ԽС��Խ���кڰ�)
�������:	��
���ز���:	0:	�ɹ�
				-1: ����
*************************************************************************/
int camera_set_softIr_thr_chn(int chn, int dnc_thr);
int camera_set_softIr_thr(int dnc_thr);
int camera_get_softIr_thr_chn(ISP_S32 chn, ISP_S32 *pdnc_thr);


/*************************************************************************
��������:		���õư��źŷ��򣨺�Ĭ�϶�Ӧ��
�������:		chn:ͨ����[0,2]
			s32SWapEn:[0,1] def:0
				0: ������    	1:����
�������:		ps32SWapEn:[0,1] def:0
				0: ������    	1:����
���ز���:	0:	�ɹ�
				-1: ����
ע��
	�ư�->����
*************************************************************************/
int camera_set_infrared_swap_chn(int chn, int s32SWapEn);
int camera_get_infrared_swap_chn(int chn, int *ps32SWapEn);
int camera_set_infrared_swap(int s32SWapEn);
int camera_get_infrared_swap(int *ps32SWapEn);


/*************************************************************************
��������:		����LED�ƿ����źŷ��򣨺�Ĭ�϶�Ӧ��
�������:		s32SWapEn:
				bit0:  ����� 0: ������    	1:����
				bit4:  �׹�� 0: ������    	1:����
�������:	��
���ز���:	0:	�ɹ�
				-1: ����
ע��
	��Ҫ���˫��ư�Ŀ��Ƶ�ƽ(Ĭ�ϸߵ�ƽ�����͵�ƽ��)
*************************************************************************/
int camera_set_ledDrv_swap_chn(int chn, int s32SWapEn);
int camera_get_ledDrv_swap_chn(int chn, int *ps32SWapEn);
int camera_set_ledDrv_swap(int s32SWapEn);
int camera_get_ledDrv_swap(int *ps32SWapEn);


/***************************************************************
��������:	ȥ����
�������:		chn: ͨ����[0,2]
			enable:	�򿪹ر�[0,1] def:0
			level:	ǿ�ȵȼ�[0,100] def:0
�������:	 	penable:�򿪹ر�[0,1] def:0
			plevel:	ǿ�ȵȼ�[0,100] def:0
���ز���:	0:		�ɹ�
				-1:		����
***************************************************************/
int camera_get_defog_chn(int chn, int *penable, int *plevel);
int camera_set_defog_chn(int chn, int enable, int level);
int Camera_SetClearFog(int enable, int level);
int Camera_GetClearFog(int *penable, int *plevel);


/***************************************************************
��������:	��ȡ��ǰ�ع����
�������:		chn:ͨ����[0,2]
			*pu32line:  ��ǰ�ع�����
			*pu32Gain:	��ǰ�ع�����(*1024)
���ز���:		0:		�ɹ�
			-1:		����
***************************************************************/
int camera_get_exposure_data_chn(int chn,int *pu32line,int *pu32Gain);
int camera_get_exposure_data(int *pu32line, int *pu32Gain);
int Camera_Get_ExposureData(int *pT_us, int *pGain);


/***************************************************************
��������:	��ȡsensor�ͺ�
�������:		chn:ͨ����[0,2]
���ز���:		sensor�ͺ�ID
***************************************************************/
int camera_get_sensor_chn(ISP_S32 chn);
int GetSensorType(void);


/*************************************************************************
��������:	������Ӳ����ѡ��
�������:		chn: ͨ����
			*ps32Mode: ģʽ	
�������:	��
���ز���:		0:	�ɹ�
			-1:	����
*************************************************************************/
int camera_get_photosensitive_chn(int chn, int *ps32Mode);
int camera_set_photosensitive_chn(int chn, int s32Mode);
int camera_get_Photosensitive(int *photosensitive);
int camera_set_Photosensitive(int photosensitive);

typedef enum{
	FACE_PRIOR = 0,
	UVC_DAY = 1,
	UVC_NIGHT = 2,
}CAMERA_FACE_UVC_AE_MOD;
/*************************************************************************
��������:	˫��FUN_EXT_DOOR_LOCK_FACE_UVC����ר�ã�����sensor�Ŀ���ʹ��
�������:		chn: ͨ����
			ps32Mode��sensor����״̬
�������:	��
���ز���:		0:	�ɹ�
			-1:	����
*************************************************************************/
int camera_set_sensor_state(int chn, int s32Mode);
/*************************************************************************
��������:	˫��FUN_EXT_DOOR_LOCK_FACE_UVC����ר�ã����ڿ����㷨��������
�������:	s32Mode��AEģʽ
�������:	��
���ز���:		0:	�ɹ�
			-1:	����
*************************************************************************/
int camera_set_ae_mod(int s32Mode);
/*************************************************************************
��������:	��ȡ/���� ɨ���ά��ģʽ
�������:	qrcode:   0:	��
				qrcode:   1:    ��				
*************************************************************************/
int camera_get_qrcode(ISP_S32 *pQrcode);
int camera_set_qrcode(ISP_S32 qrcode);

int camera_set_af_switch(ISP_S32 ps32Mode);
int camera_get_af_switch(ISP_S32* ps32Mode);
int camera_get_af_stat(ISP_S32 chn,ISP_S32* AfStat);

/*************************************************************************
��������:	��ȡ/���� UVC������ֱ���
�������:	
			s32CaptureSize:	0:��	1:��				
*************************************************************************/
int camera_get_capture_size(ISP_S32 *s32CaptureSize);
int camera_set_capture_size(ISP_S32 s32CaptureSize);

/************************************************************************************************************
��������: ����ISP���(XM_MPI_ISPAPP_RUN + ����isp.json)
�������:		u32Mode:
				bit0~bit3: VStd(1:PAL  2:NTSC)
			s32Rsv: ����
�������: ��
���ز���: 		0:�ɹ�
			-1:ʧ��
ע:
	�漰isp.json�Ľ���
************************************************************************************************************/
int camera_init(unsigned int u32Mode, int s32Rsv);

/*************************************************************************
��������:	ͼ����ؽ����˳�����
�������:	��
�������:	��
���ز���:		0:	�ɹ�
			-1:	����
*************************************************************************/
int camera_exit(void);

/*************************************************************************
��������:	����/��ʽ/�ֱ��� ģʽ�л�
�������:	u8Mode:
					0x00:AHD	0x01:CVI		0x02:TVI		0x10:XVI
				u8VstdMode:	
					1: PAL	2:NTSC
				u8RlstMode:
					0:1M 1:2M 3:3M 4:4M 5:5M
note:
*************************************************************************/
int camera_set_isp_para(unsigned char u8Mode, unsigned char u8VstdMode, unsigned char u8RlstMode);
int camera_get_isp_para(unsigned char *pu8Mode);

int camera_set_language(int s32Language);

/*****************************************************************************
��������:	�ⲿ����ѡ��gamma
�������:    	u32Gamma: [High Byte->Low Byte] = [u8IdxWgt(Idx2)  u8Idx2  u8Idx1]
				u8Idx1:	0: 		disable gamma  (����)
						1~15:	LinearGamma
						128~255:	WdrGamma
				u8Idx2:	0: 		disable gamma  (����)
						0~15:	LinearGamma
						128~255:	WdrGamma
				u8IdxWgt: (0~255)
						u8Idx1 Weight: 255-u8IdxWgt
						u8Idx2 Weight: u8IdxWgt				
���ز���:    0: �ɹ� -1: ʧ��
*****************************************************************************/
int camera_set_gamma(unsigned int u32Gamma);
int camera_get_gamma(unsigned int *pu32Gamma);


/*************************************************************************
��������: 	2Mץͼ�ӿ�
�������:	��
�������:	pstSnapVFInfo
���ز���:	0:	�ɹ�
				-1:	����
*************************************************************************/
int camera_snap(void *pstSnapVFInfo);

/*************************************************************************
��������: 	����ͼ������
�������:	chn: ͨ��
		  mode: ����
		  stCoord: ������Ϣ
�������:	��
���ز���:	0:	�ɹ�
				-1:	����
*************************************************************************/
int camera_set_coord_chn(int chn, int mode, COORD_S stCoord);

/*************************************************************************
��������: 	����ͼ������
�������:	pstViWin 
�������:	��
���ز���:	0:	�ɹ�
				-1:	����
*************************************************************************/
int camera_get_vi_resolution(VI_WIN_S *pstViWin);

/*************************************************************************
��������:		ע���ȡ���ܿ����Ľӿں���
�������:		pstGetAiFunc:
				ָ������
�������:	��
���ز���:	0:	�ɹ�
				-1: ����
*************************************************************************/
int camera_register_callback_aiFun(ISP_GET_AI_FUNC_S *pstGetAiFunc);

/*************************************************************************
��������:		���û�ȡ�㷨֧������
�������:		u32AiType: //bit0:����bit1: ����bit2:����
				
�������:	��
���ز���:	0:	�ɹ�
				-1: ����
*************************************************************************/


int camera_set_aiType(unsigned int u32AiType);
int camera_get_aiType(unsigned int *pu32AiType);


// ���ð�ƽ�����
int camera_set_wb_mode(unsigned int mode);
//���ڵ���
int camera_debug(char *cmd);

int camera_aew_get_version(char *str);

//����WB����
void  camera_get_wb_params(void *param);

int camera_save_debug_cmd(char *cmd);

int Camera_Get_DebugFile(char *fliename, unsigned int choice, unsigned int depth);

int camera_scan_task(unsigned int u32Tms);


/*************************************************************************
��������: 	camera_set_format
�������:	chn
				u32Type: 0MainStream	1:SubStream1	2:SubStream2
				pstFormat: encode paramer
�������:	none
���ز���:	0:	�ɹ�
				-1:	����
*************************************************************************/
int camera_set_format_chn(int chn, unsigned int u32Type,const CAPTURE_FORMAT *pstFormat);
int camera_set_format(int chn, unsigned int u32Type,const CAPTURE_FORMAT *pstFormat);


/*************************************************************************
�������:	u8Mode:		1: Read 	
							2: Write
				pu8Status: 			fps
							0:		1/1
							2:		1/2
�������:	��
���ز���:	0:	�ɹ�
				-1:	����
*************************************************************************/
int camera_es_shutter_ex(unsigned char u8Mode, unsigned char *pu8Status);


/*************************************************************************
��������: 	��Ʒ�ͺ�(��/д)
�������:	u8Mode:		1: Read 	
							2: Write
				*pu32ProductType:	��Ʒ�ͺ�
�������:	*pu32ProductType:	��Ʒ�ͺ�
���ز���:	0:	�ɹ�
				-1:	����
*************************************************************************/
int camera_productType(unsigned char u8Mode, unsigned int *pu32ProductType);


/*************************************************************************
��������: 	����/��ȡ ����AWBɫ��
�������:	u8MinCt: 	���ɫ��	bit7: En  bit0~bit6: Choice
			u32Start: 	��ʼ��������(x1024)
			u32End: 	�ſ���������(x1024)
�������:	��
���ز���:	0:	�ɹ�
				-1:	����
*************************************************************************/
int camera_awbLimit_set(unsigned char u8MinCt, unsigned int u32Start, unsigned int u32End);
int camera_awbLimit_get(unsigned char *pu8MinCt, unsigned int *pu32Start, unsigned int *pu32End);


/*************************************************************************
��������: 	����/��ȡ Burstʹ��(BW)
�������:	u8Enable: 0:Disable 	1:Enable
�������:	��
���ز���:	0:	�ɹ�
				-1:	����
*************************************************************************/
int camera_bwBurst_set(unsigned char u8Enable);
int camera_bwBurst_get(unsigned char *pu8Enable);

int camera_set_wbRB(unsigned char u8Data);
int camera_get_wbRB(unsigned char *pu8Data);

int camera_set_wbGM(unsigned char u8Data);
int camera_get_wbGM(unsigned char *pu8Data);


#ifdef __cplusplus
}
#endif

#endif

