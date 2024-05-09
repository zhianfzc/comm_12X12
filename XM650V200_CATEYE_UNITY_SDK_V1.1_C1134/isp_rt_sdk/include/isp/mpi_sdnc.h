#ifndef __MPI_SDNC_H__
#define __MPI_SDNC_H__
#include "isp_common.h"
typedef struct stSDNC_DNC_ATTR_S
{
	int s32ColorExpMin;
	int s32ColorExp;
	int s32ColorDlt;
	int s32ColorDlt2;
	int s32BwExp;
}SDNC_DNC_ATTR_S;

typedef struct stSDNC_DNC_INFO_S
{
	int s32Data[16];
}SDNC_DNC_INFO_S;


typedef struct stSDNC_FUNC_S
{
/**************************************
��������: ���Ƶư��Դ
�������:   u8Mode
			0: �ر�
			1: ��
���ز���:	-1: 	����
		0:		�������
		1:		������Ч
**************************************/
    int(*pfn_led_ctrl)(int chn, unsigned char u8Mode);

/**************************************
��������: ��ȡ�ư�״̬
�������:  ��
�������:	*ps32Mode: 0:Auto 1:Manual
		* ps32State: 0:Close 1:Open
		
���ز���:	-1: 	����
		0:		�ɹ�
**************************************/
	int(*pfn_led_get)(int chn, int *ps32Mode, int* ps32State);

/**************************************
��������: ��ҹ״̬��ȡ
�������: *ps32State:  0: Day 1:Night
�������: ��
���ز���:	-1: 	����
		0:		�ɹ�
**************************************/
	int(*pfn_dnStatusExt_get)(int chn, int* ps32State);

} SDNC_FUNC_S;

typedef struct stSDNC_CTRL_ATTR_S
{
	unsigned char u8Delay2Color;		// (s)
	unsigned char u8Delay2Bw;			// (s)
	unsigned char u8DelayLedReOpen;	// (s)
	unsigned char u8Mode;				// 2: No PhotoR_V2  3: Have PhotoR_V2
	unsigned short u16PeriodMs;		// ��������(ms)
} SDNC_CTRL_ATTR_S;


/*********************************************************************************
��������:	��ȡ��ҹ״̬
�������:		IspDev: ISP�豸��
			u8DnNow: ��ǰ��ҹģʽ(ʵ����Ч)
					0: ��ɫ
					1: �ڰ�
			pstIrDncAttr
					s32ColorExp:  <=��ֵ�����ɫģʽ
					s32ColorDlt:  	>=��ֵ�����ɫģʽ
					s32ColorDlt2:	>=��ֵ�����ɫģʽ(Example: 50)
					s32BwExp:	>=��ֵ����ڰ�ģʽ
�������:	��
���ز���:	-1:	����
				0:	��ɫ
				1:	�ڰ�
*********************************************************************************/
ISP_S32 XM_MPI_SDNC_GetDNCStatus(ISP_DEV IspDev, ISP_U8 u8DnNow, SDNC_DNC_ATTR_S* pstIrDncAttr);

/*********************************************************************************
��������:	��ȡͳ����Ϣ
�������:	��
�������:	pstDncInfo: ͳ����Ϣ
���ز���:	-1:	����
				0:	��ɫ
				1:	�ڰ�
*********************************************************************************/
ISP_S32 XM_MPI_SDNC_GetInfo(ISP_DEV IspDev, SDNC_DNC_INFO_S *pstDncInfo);

/*********************************************************************************
��������:	ע��ư���ƽӿ�
�������:	pstRegister: ָ��ӿڵ�ַ
�������:	��
���ز���:	-1:	����
		0:     �ɹ�
*********************************************************************************/
ISP_S32 XM_MPI_SDNC_FunCallBack(ISP_DEV IspDev, SDNC_FUNC_S *pstRegister);


/*********************************************************************************
��������:	���ÿ��Ʋ���
�������:	pstCtrlAttr: ָ���������
�������:	��
���ز���:	-1:	����
		0:     �ɹ�
*********************************************************************************/
ISP_S32 XM_MPI_SDNC_SetCtrlAttr(ISP_DEV IspDev, SDNC_CTRL_ATTR_S *pstCtrlAttr);


/*********************************************************************************
��������:	��ȡ���Ʋ���
�������:	��
�������:	pstCtrlAttr: ָ���������
���ز���:	-1:	����
		0:     �ɹ�
*********************************************************************************/
ISP_S32 XM_MPI_SDNC_GetCtrlAttr(ISP_DEV IspDev, SDNC_CTRL_ATTR_S *pstCtrlAttr);


/*********************************************************************************
��������:	�л�ģʽ
�������:	u8Mode: 
					0: IR
					1: WL
�������:	��
���ز���:	-1:	����
				0:	�ɹ�
*********************************************************************************/
ISP_S32 XM_MPI_SDNC_SwitchMode(ISP_DEV IspDev, ISP_U8 u8Mode);


#endif /* __MPI_SDNC_H__ */

