/*****************************************************************************

------------------------------------------------------------------------------
        xm_fr_interface.h
��Ʒ��:    ����ʶ��
ģ����:    ����ʶ��
��������:  2018-09-10
����:      ������
�ļ�����:  ����ʶ�����ͷ�ļ�
�汾�ţ�   V0.1.1
*****************************************************************************/

#ifndef _XM_FR_INTERFACE_H_
#define _XM_FR_INTERFACE_H_
/*--------------------------------------------------------------------------------
    1. include headers
--------------------------------------------------------------------------------*/
#ifdef __cplusplus
extern "C"
{
#endif
#include "xm_ia_comm.h"

/*--------------------------------------------------------------------------------
    2. constant defines
--------------------------------------------------------------------------------*/
#define FACE_REC_FEATURE_NUM            (512)       /* ����ʶ����������� */

/*--------------------------------------------------------------------------------
    3. data struct
--------------------------------------------------------------------------------*/
/* ��������,�̶��ṹ�� */
typedef struct
{
    float afFaceFeat[FACE_REC_FEATURE_NUM];     /* 512ά�������� */

}XM_IA_FR_FEATRUES;

/* ���������б� */
typedef struct
{
    int iFaceNumInList;                         /* ������������������ */
    XM_IA_FR_FEATRUES **ppstFeatureItem;        /* ���������б�ָ�� */

    unsigned char ucReserved[128];              /* �����ֽ� */
}XM_IA_FR_FEATRUES_LIST;

/* ���������ȶԽ�� */
typedef struct
{
    int iFaceRecIdx;                            /* ʶ�����������б����������� */
    float fMatchingRate;                        /* �����(0~100%) */

    unsigned char ucReserved[64];               /* �����ֽ� */
}XM_IA_FR_MATCH_RSLT_S;

/* �����ȶ����� */
typedef struct
{
    int iMaxMatchNum;                           /* �������ȶ��� */
    float fThresh;                              /* �����ȶ���ֵ */

    unsigned char ucReserved[64];               /* �����ֽ� */
}XM_IA_FR_MATCH_CFG_S;

/* �������б���ȶԳ����д����趨��ֵ�ıȶԽ�� */
typedef struct
{
    int iMatchNum;                              /* �ȶԳ��������� */
    XM_IA_FR_MATCH_RSLT_S *pstMatchList;        /* �ȶԽ���б� */

    unsigned char ucReserved[64];               /* �����ֽ� */
}XM_IA_MATCH_LISTS_RSLT_S;

/* ����ʶ��ȼ����ã�Խ��Խ��ȫ��ͨ���ʽ��͡�Խ��ͨ����Խ�ߵ���Բ���ȫ */
typedef enum
{
    XM_IA_FR_MATCH_LEVEL_LOWEST = -2,           /* ���ʶ����ֵ�ȼ� */
    XM_IA_FR_MATCH_LEVEL_LOW = -1,              /* �ϵ�ʶ����ֵ�ȼ� */
    XM_IA_FR_MATCH_LEVEL_MID = 0,               /* ��ʶ����ֵ�ȼ� */
    XM_IA_FR_MATCH_LEVEL_HIGH = 1,              /* �ϸ�ʶ����ֵ�ȼ� */
    XM_IA_FR_MATCH_LEVEL_HIGHEST = 2,           /* ���ʶ����ֵ�ȼ� */
    XM_IA_FR_MATCH_LEVEL_NUM = 5,               /* ʶ����ֵ�ȼ����� */
}XM_IA_FR_MATCH_LEVEL_E;

/// ���������ȶ�,���1-2���������������
/// \param [in] pfFaceFeat      ��������
/// \param [in] pstFeatureList  ���������б�
/// \param [in] fThresh         �ȶ���ֵ(0~100%),������ֵ�����ƥ��ɹ�
/// \param [out] pstMatchRslt   ����ƥ����
/// \return 0  �ɹ�
/// \return !0 ʧ��
int XM_IA_FR_MatchFace(XM_IA_FR_FEATRUES *pstFaceFeat, XM_IA_FR_FEATRUES_LIST *pstFeatureList, float fThresh, XM_IA_FR_MATCH_RSLT_S *pstMatchRslt);

/// ���������ȶ�,���������ֵ���������
/// \param [in] pfFaceFeat      ��������
/// \param [in] pstFeatureList  ���������б�
/// \param [in] stMatchCfg      �����ȶ�������
/// \param [out] pstMatchRslt   ����ƥ����
/// \return 0  �ɹ�
/// \return !0 ʧ��
int XM_IA_FR_ListOfMatchFace(XM_IA_FR_FEATRUES *pstFaceFeat, XM_IA_FR_FEATRUES_LIST *pstFeatureList, XM_IA_FR_MATCH_CFG_S stMatchCfg, XM_IA_MATCH_LISTS_RSLT_S *pstMatchRslt);

/*************************************************
Author: WangZelang
Date: 2021-04-20
Description: �ṩ��׼������������ٱȶ�
INPUT:  pfFaceFeat      ��ʶ����������
        fNorm1          ��ʶ������������׼��
        pstFeatureList  ���������׿��е���������
        pfNormList      �׿�����������׼��
        fThresh         �ȶ���ֵ(0~100%),������ֵ�����ƥ��ɹ�,Ĭ��ʶ����ֵ0.50
OUTPUT: pstMatchRslt    �ȶԽ�����������������������ƶ�
*************************************************/
int XM_IA_FR_FastMatchFace(XM_IA_FR_FEATRUES *pfFaceFeat, float fNorm1, XM_IA_FR_FEATRUES_LIST *pstFeatureList, float *pfNormList, float fThresh, XM_IA_FR_MATCH_RSLT_S *pstMatchRslt);

#ifdef  __cplusplus
}
#endif  /* end of __cplusplus */
#endif