/*****************************************************************************

------------------------------------------------------------------------------
        xm_ia_fdr_interface.h
��Ʒ��:    �������ʶ��
ģ����:    �������ʶ��
��������:  2018-09-10
����:      ������
�ļ�����:  �������ʶ�����ͷ�ļ�
�汾�ţ�   V1.4.15.0
*****************************************************************************/
#ifndef _XM_IA_FDR_INTERFACE_H_
#define _XM_IA_FDR_INTERFACE_H_

#include "xm_ia_comm.h"
#include "xm_fr_interface.h"

#ifdef __cplusplus
extern "C" {
#endif
#define FDR_MAJOR_VERSION               (1)             /* �������ʶ���㷨���汾�� */
#define FDR_MINOR_VERSION               (4)             /* �������ʶ���㷨�ΰ汾�� */
#define FDR_REVERSION                   (15)             /* �������ʶ���㷨�޸İ汾�� */
#define FDR_BUILD                       (0)             /* �������ʶ���㷨����汾��(�ݲ���) */
#define FACE_POINT_NUM                  (68)            /* ������λ���� */
#define FACE_POINT_MAX_NUM              (136)           /* ������λ������ */
#define FACE_REC_VERSION_LEN            (10)            /* ����ʶ��汾�ų��� */

typedef struct
{
    unsigned char ucEyeClosedCnt;
    unsigned char ucHeadLowerCnt;
    unsigned char ucHeadTurnedCnt;
    unsigned char ucMouthWideOpenCnt;
   
    unsigned char ucReserved[24];
}FDR_IA_ATTENTION_STRATEGY_S;

/* �������ʶ���㷨����ģʽ */
typedef enum
{
    XM_IA_FDR_MODE_FDR = 0,                     /* ָʾ�㷨���������������ʶ�� */
    XM_IA_FDR_MODE_EXTRACT_FEATURE = 1,         /* ָʾ�㷨��ǰ֡������Ҫ¼��׿� */
    XM_IA_FDR_MODE_DIRECT_EXTRACT_FEATURE = 2,  /* ָʾ�㷨����������ⲽ��,ֱ����ȡ�����ǶȺ��������� */
    XM_IA_FDR_MODE_DIRECT_GET_FACE_ANGLE = 3,   /* ָʾ�㷨����������ⲽ��,ֱ�ӻ�ȡ�����Ƕ� */
    XM_IA_FDR_MODE_UNSTABLE_FDR = 4,            /* ָʾ�㷨���õ�����λ���ȶ���������ʶ�� */
    XM_IA_FDR_MODE_FD = 5,                      /* ָʾ�㷨����ֻ��ⲻʶ�� */
    XM_IA_FDR_MODE_FDR_TWO_FEATURES = 6,        /* ָʾ�㷨�������ʶ��,��ȡ˫���� */
    XM_IA_FDR_MODE_UNSTABLE_FDR_TWO_FEATURES = 7,/* ָʾ�㷨���õ�����λ���ȶ���������ʶ��,����ȡ˫���� */
    XM_IA_FDR_MODE_EXTRACT_TWO_FEATURES = 8,    /* ָʾ�㷨��ȡ��Ƶ��˫����(����ʹ��,Ϊ�����ϰ汾,�����ⲿͬ���޸ģ���ʱ��1���������) */
    XM_IA_FDR_MODE_NUM                          /* �������ʶ���㷨ģʽ������ */

}XM_IA_FDR_MODE_E;

/* ���忪�� */
typedef enum
{
    XM_IA_ALIVE_MODE_INFRARED_INACTIVE = 0,     /* �رջ���ģʽ */
    XM_IA_ALIVE_MODE_INFRARED_ACTIVE = 1,       /* ��ɫ + �����жϻ���ģʽ */
    XM_IA_ALIVE_MODE_INFRARED_DUAL = 2,         /* ˫�����жϻ���ģʽ */
    XM_IA_ALIVE_MODE_COLOR_INFRARED_PLUS_INFRARED = 3,  /* ��ɫ����˫ͨ + �����жϻ���ģʽ */
    XM_IA_ALIVE_MODE_COLOR_PLUS_INFRARED = 4,   /* ����RGB + �����жϻ���ģʽ */
    XM_IA_ALIVE_MODE_INFRARED_DUAL_ASYNC = 5,   /* ˫�����첽�жϻ���ģʽ */
    XM_IA_ALIVE_MODE_COLOR_PLUS_INFRARED_DUAL_ASYNC = 6    /* RGB + ˫�����첽�жϻ���ģʽ */
}XM_IA_ALIVE_MODE_E;

/* ������λ���� */
typedef enum
{
    XM_IA_FP_MODE_INACTIVE = 0,                 /* �ر�������ģʽ */
    XM_IA_FP_MODE_ACTIVE = 1                    /* ����������ģʽ */
}XM_IA_FP_MODE_E;

/* ������ */
typedef enum
{
    XM_IA_ALIVE_INACTIVE = 0,                   /* �ǻ��� */
    XM_IA_ALIVE_ACTIVE = 1                      /* ���� */
}XM_IA_ALIVE_S;

/* ע����״̬ */
typedef enum
{
    XM_IA_ATTENTION_NO = 0,                     /* �����롢���ļ��� */
    XM_IA_ATTENTION_YAWN = 10,                  /* ���Ƿ */
    XM_IA_ATTENTION_HEAD_TURNED = 13,           /* תͷ */
    XM_IA_ATTENTION_HEAD_LOWER = 14,            /* ��ͷ̧ͷ */
    XM_IA_ATTENTION_EYE_CLOSED = 15,            /* ���� */
    XM_IA_ATTENTION_DOZE = 20,                  /* ���� */
    XM_IA_ATTENTION_CLOSE_EDGE = 30,            /* ���������Ե */

}XM_IA_ATTENTION_STATUS_E;

typedef struct
{
    unsigned char ucFaceAgeFlag;                /* ֧���������� */
    unsigned char ucFaceMaskFlag;               /* ֧�ֿ��ּ�� */
    unsigned char ucFaceGlassFlag;              /* ֧���۾���� */
    unsigned char ucFaceGenderFlag;             /* ֧���Ա��� */
    unsigned char ucFaceExpressionFlag;         /* ֧�ֱ����� */
    unsigned char ucFaceAttentionFlag;          /* ֧��ע���� */
    unsigned char ucSafetyHelmetFlag;           /* ֧�ְ�ȫñ��� */

    unsigned char ucReserved[31];               /* �����ֽ� */
}XM_IA_ATTRIBUTES_SET_S;

typedef struct
{
    unsigned char ucFaceAgeEnable;              /* �������俪�� */
    unsigned char ucFaceMaskEnable;             /* ���ֿ��� */
    unsigned char ucFaceGlassEnable;            /* �۾����� */
    unsigned char ucFaceGenderEnable;           /* �Ա𿪹� */
    unsigned char ucFaceExpressionEnable;       /* ���鿪�� */
    unsigned char ucFaceAttentionEnable;        /* ע�������� */
    unsigned char ucSafetyHelmetEnable;         /* ��ȫñ��⿪�� */

    unsigned char ucReserved[31];               /* �����ֽ� */
}XM_IA_ATTRIBUTES_MODE_S;

typedef struct
{
    int iFaceMinWid;                            /* ͼ������С������ȣ���ͼ����խ���������(0~8192) */
    int iFaceMaxWid;                            /* ͼ�������������ȣ���ͼ����խ���������(0~8192) */

    unsigned char ucReserved[128];              /* �����ֽ� */
}XM_IA_FD_CONFIG_S;

/* ������������ȼ����ã�Խ��Խ��ȫ��ͨ���ʽ��͡�Խ��ͨ����Խ�ߵ���Բ���ȫ */
typedef enum
{
    XM_IA_FR_ALIVE_LEVEL_LOWEST = -2,           /* ��ͻ�������ȼ� */
    XM_IA_FR_ALIVE_LEVEL_LOW = -1,              /* �ϵͻ�������ȼ� */
    XM_IA_FR_ALIVE_LEVEL_MID = 0,               /* �л�������ȼ� */
    XM_IA_FR_ALIVE_LEVEL_HIGH = 1,              /* �ϸ߻�������ȼ� */
    XM_IA_FR_ALIVE_LEVEL_HIGHEST = 2,           /* ��߻�������ȼ� */
    XM_IA_FR_ALIVE_LEVEL_NUM = 5,               /* ��������ȼ����� */
}XM_IA_FR_ALIVE_LEVEL_E;

/* ����ʶ�����ýṹ�� */
typedef struct
{
    int iClearThr;                              /* ����������ʶ����ֵ */
    XM_IA_ANGLE_S stFaceAngle;                  /* ��������ʶ�����Ƕ�(0~90)��ƫ���ǡ�����ǡ������� */
    XM_IA_RECT_S stFaceRecRegion;               /* ����ʶ�������������(0~8191) */
    XM_IA_ATTRIBUTES_MODE_S stFaceAttrMode;     /* �������Թ���״̬ */

    XM_IA_FR_ALIVE_LEVEL_E eAliveLevel;         /* ������������ȼ� */
    XM_IA_FR_MATCH_LEVEL_E eMatchLevel;         /* ����ʶ��ȼ� */

    unsigned char ucReserved[120];              /* �����ֽ� */
}XM_IA_FR_CONFIG_S;

/* �����ǶȽṹ�� */
typedef struct
{
    short sYaw;                                 /* ƫ����(-90, 90)����ת������ת */
    short sRoll;                                /* �����(-90, 90)��������Ҹߣ���������ҵ� */
    short sPitch;                               /* ������(-90, 90)�������ӣ��������� */
    short sReserved;                            /* �����ֽ� */
}XM_IA_FACE_ANGLE_S;

/* �����ǶȽṹ�� */
typedef struct
{
    short sRotateYaw;                           /* תͷ[35, 90],����ת�Ƕ���ͬ��ֵ,����ֵ45 */
    short asReserved[3];                        /* �����ֽ� */

}XM_IA_FACE_ROTATION_ANGLE_THR_S;

/* �������ʶ�����ò��� */
typedef struct
{
    XM_IA_SENSE_E eAlgSense;                    /* �㷨������ */

    XM_IA_FD_CONFIG_S stFaceDetConfig;          /* ����������� */
    XM_IA_FR_CONFIG_S stFaceRecConfig;          /* ����ʶ������ */

    XM_IA_ROTATE_E eRotate;                     /* ��ת����ѡ�� */
    XM_IA_FACE_ANGLE_S stCalibrateFaceAngle;    /* �궨�����������Ƕ�(DMSʹ��) */
    XM_IA_FACE_ROTATION_ANGLE_THR_S stRotationAngleThr;  /* ƫ��������ʻλ�Ƕȱ�����ֵ(DMSʹ��,��ǰֻ��Yaw��Ч,��ʹ����������) */
    FDR_IA_ATTENTION_STRATEGY_S stAttentionStrategy;  /* ����ע�������� */

    unsigned char ucReserved[212];              /* �����ֽ� */
}XM_IA_FDR_CONFIG_S;

/* �������ʶ���ʼ������ */
typedef struct
{
    char acClassBinPath[XM_IA_PATH_MAX_LEN];    /* ������Bin�ļ�·�� */
    unsigned int uiInStructSize;                /* Run��β����ṹ����Size */
    unsigned int uiInitStructSize;              /* ��ʼ�������ṹ����Size */
    unsigned int uiConfigStructSize;            /* ���ò����ṹ����Size */
    unsigned int uiRsltStructSize;              /* �㷨��������ṹ����Size */

    int iFDMaxNum;                              /* ������������ */
    int iFRMaxNum;                              /* �������ʶ���� */
    int iRotateMode;                            /* �Ƿ�������תģʽ��1���ã�0�����á�������תģʽ��֧��0�Ȳ���ת��90����ת��270����ת */
    XM_IA_IMG_TYPE_E eDevImgType;               /* �豸ͼ������ */
    XM_IA_IMG_SIZE_S stDevImgSize;              /* �豸ͼ��ߴ�/XM510Ϊ�㷨ȷ�Ϲ���ͼ��ߴ� */
    XM_IA_FDR_CONFIG_S stFdrConfig;             /* �������ʶ������ */
    XM_IA_ALIVE_MODE_E eInfraredMode;           /* ����ģʽ */
    XM_IA_FP_MODE_E eFaceAngleMode;             /* �����Ƕȼ�⿪�أ�����ʶ��Ĭ�Ͽ��� */
    XM_IA_PLATFORM_E ePlatForm;                 /* оƬƽ̨ѡ�� */
    XM_IA_ATTRIBUTES_SET_S stFaceAttrSet;       /* ��������:���� */

    char acFrAlgVersion[FACE_REC_VERSION_LEN];  /* OUTPUT: ����ʶ���㷨�汾�� */
    XM_IA_IMG_SIZE_S stAlgImgSize;              /* OUTPUT: �㷨ͼ��ߴ� */

    unsigned char ucAutoCalibrateFlag;          /* DMS�㷨���������Զ��궨������ʻ�Ƕȣ�ʹ�ó�����Ϣʵ��. */
    unsigned char ucAutoCalibrateTotalCnt;      /* DMS�����Զ��궨,��ͳ������������������100 */
    unsigned char ucAutoCalibrateStartSpeed;    /* DMS�����Զ��궨,�������ٶ�km/h����������20��40 */
    unsigned char ucAutoCalibrateCntInterval;   /* DMS�����Զ��궨,ͳ��֡�������������5  */

    char *pcCalibrateFilePath;                  /* ˫Ŀ�����㷨˫Ŀ�궨:�ļ�·��/���ص����ڴ��ַ */
    char *pcModelFilePtr;                       /* ģ���ļ���ַ.(ģ�ͼ��ص��ڴ���ֱ�Ӷ�ȡ) */
    
    unsigned char ucReserved[244];              /* �����ֽ� */
}XM_IA_FDR_INIT_S;

typedef struct
{
    int iRegionNum;                             /* ��ʶ�������������,���֧��6������ */
    XM_IA_RECT_S astFaceRect[6];                /* ��ʶ����������λ��,�������(0~8191) */
    
    unsigned char ucReserved[64];               /* �����ֽ� */
}XM_IA_FDR_REGION_S;

/* �������ʶ������� */
typedef struct
{
    unsigned char ucIsFirstFrm;                 /* ��֡����֡��־��1��֡/0����֡ */
    XM_IA_FDR_MODE_E eFdrMode;                  /* �������ʶ���㷨ģʽ */
    XM_IA_FDR_REGION_S stFaceRecRegion;         /* ����ʶ������,��XM_IA_FDR_MODE_DIRECT_EXTRACT_FEATURE��XM_IA_FDR_MODE_DIRECT_GET_FACE_ANGLEģʽ����Ч */
    XM_IA_IMAGE_S *pstImg[2];                   /* ͼ��ṹ��,0:��ͼ,1:��ͼ��(˫�����Ϊ����ͼ��,Ҳ�����˫ͨ��ͼ������㷨XM580֧��) */

    short sSpeed;                               /* ������ǰ��ʻ�ٶ�(����ֵ-20~140km/h).(DMS���ܱ궨ʹ��) */ 
    char cInImgMode;                            /* ����ͼ��ģʽ.0:��ɫ+IR����,1:˫IR����.(˫ͨʶ��ʹ��),2:��ɫ+IR��ⳡ��,4:����תIR,5:���תIR */
    unsigned char ucReserved1;

    XM_IA_IMAGE_S *pstImgMultiple[2];           /* ��Ŀʱ��ͼ������ */

    unsigned char ucReserved[116];              /* �����ֽ� */
}XM_IA_FDR_IN_S;

/* ��������沿��Ϣ */
typedef struct
{
    int iFaceId;                                    /* ����ID */

    float fScore;                                   /* �������Ÿ��� */
    float fClearness;                               /* ������������ֵ,ֵԽ��Խ���� */

    /* ��������귽ʽ�ṩ(0~8191) */
    XM_IA_RECT_S stFace;                            /* ����λ�� */
    XM_IA_POINT_S stNose;                           /* ����λ�� */
    XM_IA_POINT_S stLftEye;                         /* ����λ�� */
    XM_IA_POINT_S stRgtEye;                         /* ����λ�� */
    XM_IA_POINT_S stMouthLft;                       /* �����λ�� */
    XM_IA_POINT_S stMouthRgt;                       /* �����λ�� */
    XM_IA_POINT_S astFacePoint[FACE_POINT_MAX_NUM]; /* ��������λ�õ� */
    XM_IA_ALIVE_S iAliveFace;                       /* ���������� */
    int iAliveScore;                                /* �����������[0��100],����Խ�߻������Խ�� */
    unsigned char ucAge;                            /* ��������[0��100].Ĭ��ֵ255 */
    unsigned char ucGlass;                          /* ������������۾�:0δ���/1����۾�.Ĭ��ֵ255 */
    unsigned char ucGender;                         /* �����Ա�:0����/1Ů��.Ĭ��ֵ255 */
    unsigned char ucFaceMask;                       /* ���������������:0δ���/1�������.Ĭ��ֵ255 */
    unsigned char ucFaceExpression;                 /* ��������:0ƽ��/1����/2��ʹ/3��ŭ/4�־�/5����.Ĭ��ֵ255 */
    XM_IA_ATTENTION_STATUS_E eAttentionStatus;      /* ����ע����״̬.Ĭ��ֵ0 */
    unsigned char ucFaceQuanlity;                   /* ��������[0��100] */
    unsigned char ucSafetyHelmet;                   /* ���������ȫñ:0δ���/1���.Ĭ��ֵ255 */

    unsigned char ucReserved[126];                  /* �����ֽ� */
}XM_IA_FACE_DET_INFO_S;

/* ��ʶ������״̬ */
typedef enum
{
    FACE_STATUS_APPROPRIATE = 0,    /* ǡ������ */
    FACE_STATUS_LEAN = 1,           /* ��б���� */
    FACE_STATUS_OUTDROP = 2,        /* �������� */
    FACE_STATUS_ANALYSISING = 3,    /* ���ڷ��������� */
    FACE_STATUS_LOW_RELIABLE = 4,   /* �����Ŷ����� */
    FACE_STATUS_INVALID = 5,        /* �����Ƕ��޷����� */
    FACE_STATUS_SUBMARGINAL = 6,    /* ������Ե���� */
    FACE_STATUS_SMALL = 7,          /* С���� */
    FACE_STATUS_LEFT_EDGE = 8,      /* ����λ�ڻ������Ե */
    FACE_STATUS_RIGHT_EDGE = 9,     /* ����λ�ڻ����ұ�Ե */
    FACE_STATUS_TOP_EDGE = 10,      /* ����λ�ڻ����ϱ�Ե */
    FACE_STATUS_BOTTOM_EDGE = 11,   /* ����λ�ڻ����±�Ե */
    FACE_STATUS_NEAR_EDGE = 12,     /* ����λ�ڻ������Ե */
    FACE_STATUS_FAR_EDGE = 13,      /* ����λ�ڻ���Զ��Ե */
    FACE_STATUS_OVER_EXPOSURE = 14, /* �������� */
    FACE_STATUS_UNDER_EXPOSURE = 15,/* ����Ƿ�� */
    FACE_STATUS_UNCLEAR = 16,       /* ���������� */
    FACE_STATUS_BLOCK = 17,         /* �����ڵ� */
    FACE_STATUS_NUM                 /* ����״̬�� */

}APPROPRIATE_FACE_STATUS_E;

/* �������ʶ��ָ�� */
typedef enum
{
    FACE_GUIDE_APPROPRIATE = 0,     /* ǡ������ */
    FACE_GUIDE_LOOK_STRAIT = 1,     /* ����Ҫƽ��,��Ҫ��ͷ */
    FACE_GUIDE_MULTI_FACE = 2,      /* ������,�뱣��һ������ */
    FACE_GUIDE_MOVE_LEFT = 3,       /* ����λ���Ҳ��Ե,�볯���ƶ� */
    FACE_GUIDE_MOVE_RIGHT = 4,      /* ����λ������Ե,�볯���ƶ� */
    FACE_GUIDE_MOVE_FORWARD = 5,    /* ������Զ/���ⲻ��,�볯ǰ�ƶ� */
    FACE_GUIDE_MOVE_BACKWARD = 6,   /* ��������/�����ǿ,�볯���ƶ� */
    FACE_GUIDE_TAKE_OFF_MASK = 7,   /* �����������޷�ʶ�� */
    FACE_GUIDE_MOVE_UP = 8,         /* ����λ���±�Ե,�����볯���ƶ� */
    FACE_GUIDE_MOVE_DOWN = 9,       /* ����λ���ϱ�Ե,�����볯���ƶ� */
    FACE_GUIDE_SHOW_COMPLETE_FACE = 10,     /* �����ڵ�,��ʾ�������� */
    FACE_GUIDE_NUM                  /* ����ָ��״̬�� */

}XM_IA_FACE_GUIDE_E;

/* �����ǶȽṹ�� ������Ի������˵ķ���*/
typedef struct
{
    int iYaw;                                       /* ƫ����(-90, 90)������ת��������ת */
    int iRoll;                                      /* �����(-90, 90)��������Ҹߣ���������ҵ� */
    int iPitch;                                     /* ������(-90, 90)�������ӣ��������� */

    APPROPRIATE_FACE_STATUS_E eFaceAngleStatus;     /* �����Ƕ�״̬ */

    unsigned char ucReserved[32];                   /* �����ֽ� */
}XM_IA_FDR_ANGLE_S;

/* ��������� */
typedef struct
{
    int iFaceNum;                               /* ��������� */
    XM_IA_FACE_DET_INFO_S* pstFaceRect;         /* ������Ϣ */
    XM_IA_FDR_ANGLE_S* pstFaceAngle;            /* �����Ƕ���Ϣ */

    unsigned char ucReserved[128];              /* �����ֽ� */
}XM_IA_FD_RESULTS_S;

/* ����ʶ����Ϣ */
typedef struct
{
    int iFaceId;                                /* ʶ������ID�� */
    XM_IA_RECT_S stFaceRect;                    /* ʶ��λ��:�������(0~8191) */
    XM_IA_FR_FEATRUES stFrFeatures;             /* �������� */

    unsigned char ucReserved[128];              /* �����ֽ� */
}XM_IA_FACE_REC_INFO_S;

/* ����ʶ���� */
typedef struct
{
    int iFaceNum;                               /* ����ʶ���� */
    XM_IA_FACE_REC_INFO_S* pstFaceRecInfo;      /* ����ʶ����Ϣ */

    unsigned char ucReserved[128];              /* �����ֽ� */
}XM_IA_FR_RESULTS_S;

/* �������������Ϣ */
typedef struct
{
    int iActiveFlag;                    /* ���򼤻��־ */
    int iAveLightness;                  /* ����ƽ������ */
    int iLightnessLmtMin;               /* ����ʶ���������� */
    int iLightnessLmtMax;               /* ����ʶ���������� */
    XM_IA_RECT_S stRegion;              /* ��ȡ������������λ��(�ڰ׹�ͼ�У��������0~8192) */

    unsigned char ucIrActiveFlag;       /* IRͨ�����������־ */
    unsigned char ucIrAveLightness;     /* IRͨ������ƽ������ */
    unsigned char ucIrLightnessLmtMin;  /* IRͨ��������������Ҫ�� */
    unsigned char ucIrLightnessLmtMax;  /* IRͨ��������������Ҫ�� */
    unsigned char ucReserved[28];       /* �����ֽ� */

}XM_IA_FD_REGION_INFO_S;

/* �������ʶ���� */
typedef struct
{
    XM_IA_FD_RESULTS_S stFdResult;              /* ��������� */
    XM_IA_FR_RESULTS_S stFrResult;              /* ����ʶ���� */

    XM_IA_FD_REGION_INFO_S stFdRegionInfo;      /* ����������Ϣ */

    unsigned char ucReserved[256];              /* �����ֽ� */
}XM_IA_FDR_RESULTS_S;

/* DMS״̬��� */
typedef struct
{
    int iCalibrateCnt;                          /* ���ܱ궨��ͳ�������Ƕ�֡�� */
    int iCalibrateTotal;                        /* ���ܱ궨��Ҫͳ��֡�� */

    unsigned char ucAutoCalibrateStatus;        /* ���ܱ궨״̬��0δ��ɣ�1�����,ucDriveYaw��ucDriveRoll��ucDrivePitch��Ч */
    char cDriveYaw;                             /* ��ʻ��̬ƫ���ǣ�һ��Ϊ-30��30 */
    char cDriveRoll;                            /* ��ʻ��̬����ǣ���δ������,�̶�Ϊ0 */
    char cDrivePitch;                           /* ��ʻ��̬�����ǣ�һ��Ϊ-15��15 */

    unsigned char ucReserved[244];              /* �����ֽ� */
}XM_IA_DMS_STATUS_S;

/*************************************************
Author: WangZelang
Date: 2022-10-06
Description: �ṩͨ������ʶ��ָ��
INPUT:  pstFaceAngleInfo    �����Ƕ���Ϣ
        pstFdrRslt          �������ʶ���㷨���
OUTPUT: peFaceAppropriate   �ȶԽ�����������������������ƶ�
*************************************************/
int XM_IA_GetFaceRecGuide(XM_IA_FDR_ANGLE_S *pstFaceAngleInfo, XM_IA_FDR_RESULTS_S *pstFdrRslt, XM_IA_FACE_GUIDE_E *peFaceAppropriate);

/*************************************************
Author: WangZelang
Date: 2023-05-09
Description: ��������
INPUT:  pFdrHandle          �����������
OUTPUT: pstFaceImg          ����ͼ
*************************************************/
int XM_IA_GetDenoisedFace(void *pFdrHandle, XM_IA_IMAGE_S *pstFaceImg);

/*************************************************
Author: WangZelang
Date: 2023-09-14
Description: �������ֱ���
INPUT:  pFdrWork            �����������
        pstFaceInImg        ��������ͼ
OUTPUT: pstFaceOutImg       �������ֱ���ͼ
*************************************************/
int XM_IA_GetSRFace(void *pFdrHandle, XM_IA_IMAGE_S *pstFaceInImg, XM_IA_IMAGE_S *pstFaceOutImg);

/*************************************************
Author: WangZelang
Date: 2023-05-17
Description: ��ȡDMS״̬��Ϣ
INPUT:  pFdrHandle          �����������
OUTPUT: pstDmsStatus        DMS״̬
*************************************************/
int XM_IA_GetDmsStatus(void *pFdrHandle, XM_IA_DMS_STATUS_S *pstDmsStatus);


#ifdef __cplusplus
}
#endif

#endif