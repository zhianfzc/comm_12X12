/*****************************************************************************

------------------------------------------------------------------------------
                            xm_ia_comm.h
��Ʒ��:    ���ܷ����㷨
ģ����:    �����ļ�
��������:  2018-06-11
����:     ������
�ļ�����:  ���ܷ������⹫��ͷ�ļ�
*****************************************************************************/
#ifndef _XM_IA_COMM_H_
#define _XM_IA_COMM_H_

#ifdef __cplusplus
extern "C"
{
#endif

/* �������ܷ���ģ����󷵻��� */
#define XM_IA_SUCCESS          (0)
#define XM_IA_MALLOC_FAIL      (1)                          /* �ڴ�����ʧ�� */
#define XM_IA_FREE_FAIL        (2)                          /* �ڴ��ͷ�ʧ�� */
#define XM_IA_NULL_POINTER     (3)                          /* ��ָ����� */
#define XM_IA_HISI_IVE_FAIL    (4)                          /* ��˼IVE���� */
#define XM_IA_PARA_FAULT       (5)                          /* ����������� */
#define XM_IA_EXCEPTION        (6)                          /* �����쳣��֧ */
#define XM_IA_HW_FAULT         (7)                          /* Ӳ������ */

/* �������ܷ���ģ�鳣������ */
#define XM_IA_RELATIVE_COORD_SCALE          (8192)          /* ����������� */
#define XM_IA_PATH_MAX_LEN                  (256)           /* ·������ַ�����(�ֽ�) */
#define XM_IA_MAX_VERSION_LEN               (64)

/* оƬѡ�� */
typedef enum
{
    /* ����ƽ̨ */
    XM_IA_PLATFORM_XM530 = 0,               /* XM530 */
    XM_IA_PLATFORM_XM550 = 1,               /* XM550 */
    XM_IA_PLATFORM_XM580 = 2,               /* XM580 */
    XM_IA_PLATFORM_XM8536 = 3,              /* XM580 NVR��� */
    XM_IA_PLATFORM_XM8520 = 4,              /* XM580 DVR���4· */
    XM_IA_PLATFORM_XM650 = 5,               /* XM650 */
    XM_IA_PLATFORM_XM8521D = 6,             /* XM580 DVR���8· */
    XM_IA_PLATFORM_XM8516D = 7,             /* XM580 ˫�㿼�ڻ� */
    XM_IA_PLATFORM_XM350AI = 8,             /* XM350 AI */
    XM_IA_PLATFORM_XM530V200 = 50,          /* XM530V200 */
    XM_IA_PLATFORM_XM550V200 = 51,          /* XM550V200 */
    XM_IA_PLATFORM_XM650V200 = 52,          /* XM650V200 */
    
    XM_IA_PLATFORM_XM580V200 = 70,          /* XM580V200 */
    XM_IA_PLATFORM_XM8520DV200 = 71,        /* XM580V200���DVR */

    XM_IA_PLATFORM_XM530V300 = 90,          /* XM530V300 */
    XM_IA_PLATFORM_XM550V300 = 91,          /* XM550V300 */

    /* ��˼ƽ̨ */
    XM_IA_PLATFORM_HI3516EV200 = 1000,
    XM_IA_PLATFORM_HI3536 = 1001,  
    HI_IA_PLATFORM_31DV200 = 1100,        
    XM_IA_PLATFORM_HI3535A = 1101,        
    XM_IA_PLATFORM_HI3516DV300 = 1102,    
    XM_IA_PLATFORM_HI3516CV500 = 1103,    

    /* NVTƽ̨ */
    XM_IA_PLATFORM_NVT98321 = 2000,         /* NOVA��NPU 32�汾 */
    XM_IA_PLATFORM_NVT98336 = 2001,         /* NOVA��NPU 64�汾 */
    XM_IA_PLATFORM_NVT98331 = 2002,         /* NOVA��NPU 32�汾 */
    XM_IA_PLATFORM_NVT98312 = 2010,         /* NOVAƽ̨ */
    XM_IA_PLATFORM_NVT98562 = 2020,         /* NOVAƽ̨ */
    XM_IA_PLATFORM_NVT98566 = 2030,         /* NOVA��NPU�汾 */

    /* MSTARƽ̨ */
    XM_IA_PLATFORM_SSC337DE = 3000,         /* MSTAR ǰ��IPC */

    XM_IA_PLATFORM_NUM                      /* ƽ̨�� */

}XM_IA_PLATFORM_E;

/* ��������ѡ��, �ٴ������������޸ģ��м��м�*/
typedef enum
{
    XM_IA_ARM_INFERENCE_ENGINE = 0x00000000,         /* ARM�������� */
    XM_IA_XMNPU_INFERENCE_ENGINE = 0x00000001,       /* XM580 XMNPU�������� */
    XM_IA_NNIE_INFERENCE_ENGINE_1_2 = 0x00000002,    /* Hisi NNIE1.2�汾�������� */
    XM_IA_NNIE_INFERENCE_ENGINE_1_3 = 0x00000003,    /* Hisi NNIE1.3�汾�������� */
    XM_IA_NOVATEK_INFERENCE_ENGINE_32X = 0x00000004, /* Novatek 32x engine,�ӿ�8bit */
    XM_IA_NOVATEK_INFERENCE_ENGINE_64X = 0x00000006, /* Novatek 64x engine */
    XM_IA_XMDPU_INFERENCE_ENGINE_1_0 = 0x00000005,   /* XM DPU v1.0�������� */
    XM_IA_XMDPU_INFERENCE_ENGINE_1_1 = 0x00000008,   /* XM DPU v1.1�������� */
    XM_IA_XMDPU_INFERENCE_ENGINE_1_2 = 0x00000009,   /* XM DPU v1.2�������� */
    XM_IA_ARM_INFERENCE_ENGINE_1_0 = 0x0000007,      /* ARM�������������� */
    XM_IA_XMDPU_INFERENCE_ENGINE_1_3 = 0x0000000a,   /* XM DPU v1.2 for XM530V400*/
    XM_IA_INFERENCE_ENGINE_NUM = 16                  /* ��ǰ������֧��16���������� */
}XM_IA_INFERENCE_ENGINE_E;

/* ѵ����� */
typedef enum
{
    XM_IA_CAFFE_FRAMEWORK = 0x00000000,             /* Caffe��� */
    XM_IA_TENSORFLOW_FRAMEWORK = 0x00000001,        /* TF��� */
    XM_IA_PYTORCH_FRAMEWORK = 0x00000002,           /* PyTorch��� */
    XM_IA_TRAIN_FRAMEWORK = 16                      /* ��ǰ������֧��16��ѵ����� */
}XM_IA_TRAIN_FRAMEWORK_E;

/* ��ת�Ƕ� */
typedef enum
{
    XM_IA_ROTATE_NO = 0,                /* ����ת */
    XM_IA_ROTATE_CLOCKWISE = 1,         /* ˳ʱ����ת90�� */
    XM_IA_ROTATE_CLOCKWISE_INVERT = 2   /* ��ʱ����ת90��/˳ʱ����ת270�� */

}XM_IA_ROTATE_E;

/* Ŀ������,����ֽڱ���Ŀ�������� */
typedef enum
{
    XM_IA_PEDESTRAIN = 0x00,            /* ���� */
    XM_IA_VEHICLE = 0x10,               /* ����,����0x11�ɱ�ʾ��С�γ���0x12�ɱ�ʾ��SUV,��ʱ���� */
    XM_IA_NONMOTOR = 0x20,              /* �ǻ����� */
    XM_IA_SPEED_SIGN = 0x30,            /* ��ͨ������ */
    XM_IA_PET = 0x50,                   /* ���è���� */
    XM_IA_HAND = 0x60,                  /* ���� */
    XM_IA_THINGS = 0x100,               /* ��Ʒ:ռ��0x100��0x1FF */
    XM_IA_THINGS_SEAT_BELT = 0x101,     /* ��ȫ�� */
    XM_IA_THINGS_CIGARETTE = 0x102,     /* ���� */
    XM_IA_THINGS_MOBILE_PHONE = 0x103,  /* �ֻ� */
    XM_IA_THINGS_CUP = 0x104,           /* ˮ�� */
    XM_IA_THINGS_IR_BLOCK_GLASS = 0x105,/* ��������۾� */
    
    XM_IA_UNKOWN_TYPE = -1              /* δ֪���� */

}XM_IA_TARGET_TYPE_E;

/* ͼ�����ͽṹ�� */
typedef enum
{
    XM_IMG_TYPE_U8C1 = 0x0,         /* ��ͨ��8bit��ͼ�� */
    XM_IMG_TYPE_S8C1 = 0x1,

    XM_IMG_TYPE_U16C1 = 0x2,        /* ��ͨ��16bit��ͼ�� */
    XM_IMG_TYPE_S16C1 = 0x3,

    XM_IMG_TYPE_U32C1 = 0x4,        /* ��ͨ��32bit��ͼ�� */
    XM_IMG_TYPE_S32C1 = 0x5,

    XM_IMG_TYPE_U64C1 = 0x6,        /* ��ͨ��64bit��ͼ�� */
    XM_IMG_TYPE_S64C1 = 0x7,

    XM_IMG_TYPE_U8C3_PKG = 0x8,     /* ��ͨ��8bit Package��ͼ��,BGR�� BGRBGRBGR */
    XM_IMG_TYPE_U8C3_PLN = 0x9,     /* ��ͨ��8bit Planar��ͼ��,BGR�� BBBGGGRRR */

    XM_IMG_TYPE_U16C3_PKG = 0xa,    /* ��ͨ��16bit Package��ͼ�� */
    XM_IMG_TYPE_U16C3_PLN = 0xb,    /* ��ͨ��16bit Planar��ͼ�� */

    /* YUV420 */
    XM_IMG_TYPE_YUV420SP = 0x10,    /* YUV420SP��ͼ�� */
    XM_IMG_TYPE_NV12 = 0x11,        /* NV12��ͼ�� */
    XM_IMG_TYPE_NV21 = 0x12,        /* NV21��ͼ�� */

    XM_IMG_TYPE_YUV422SP = 0x20,    /* YUV422SP��ͼ�� */
    XM_IMG_TYPE_YUV444 = 0x30,      /* YUV444��ͼ�� */

    XM_IMG_TYPE_FREQENCY_DOMAIN = 0x40, /* ��ͨ��float��Ƶ��RIͼ�� */
    
    XM_IMG_TYPE_F32C1 = 0x50,           /* ��ͨ������ */

    XM_IMG_TYPE_UNKNOWN

}XM_IA_IMG_TYPE_E;

/** ��ṹ���� */
typedef struct
{
    short s16X;         /**< ������x */
    short s16Y;         /**< ������y */
}XM_IA_POINT_S;

/** ��ṹ���� */
typedef struct
{
    float fX;         /**< ������x */
    float fY;         /**< ������y */
}XM_IA_POINT_FL_S;

/** ���νṹ���� */
typedef struct
{
    short s16X1;        /**< ���Ͻ�x���� */
    short s16Y1;        /**< ���Ͻ�y���� */
    short s16X2;        /**< ���½�x���� */
    short s16Y2;        /**< ���½�y���� */
}XM_IA_RECT_S;

/** ����ϵ�ṹ���� */
typedef struct
{
    float fX;           /**< ����x */
    float fY;           /**< ����y */
    float fZ;           /**< ����z */
    char acReserved[16];   /* �����ֽ� */

}XM_IA_COORDINATE_FL_S;

/* ͼ����Ϣ�ṹ�� */
/* ��XM_IAͼ����� */
/* ����1�����ڲ�ͬͼ��������ʹ�õ�ͼ������ָ��Ϳ������ */
/*       1) �������Ϳ����õ�������ָ��Ϳ��,��ʱĬ�ϲ�ͬ��ɫ���������ҿ����ͬ */
/*       2) ����Ҫʹ�ö�ͨ��������ָ��Ϳ��,RGB_PLN 3ͨ����YUV420SP 3ͨ����NV12��NV21 2ͨ������ͨ��0ָ��Y����ͨ��1ָ��UV���� */
/* ����2�����������ַ */
/*       1) ��Ӳ�����ٵ�ƽ̨,����ʹ�ò��������ַ��ϵͳ�ڴ� */
/*       2) ��Ӳ�����ٵ�ƽ̨,�������ַ��Ҫ��д������Ҫͬʱ��д32λ�����ַ��64λ�����ַ,32λƽ̨��д64λ�����ַ����Ϊ(unsigned long long)((u32PhyAddr) | (unsigned long long)0)
 */
typedef struct
{
    unsigned short usWidth;        /* ͼ���� */
    unsigned short usHeight;       /* ͼ��߶� */
    unsigned short usBitCnt;       /* ����Bit�� */
    XM_IA_IMG_TYPE_E eImgType;     /* ͼ���ʽ */

    void *pvImgData;               /* ͼ������ͨ��0�����ַ */
    void *pvImgData1;              /* ͼ������ͨ��1�����ַ */
    void *pvImgData2;              /* ͼ������ͨ��2�����ַ */
    unsigned int u32PhyAddr;       /* ͼ������ͨ��0 32λ�����ַ */
    unsigned int u32PhyAddr1;      /* ͼ������ͨ��1 32λ�����ַ */
    unsigned int u32PhyAddr2;      /* ͼ������ͨ��2 32λ�����ַ */
    unsigned short usStride;       /* ͼ��ͨ��0��� */
    unsigned short usStride1;      /* ͼ��ͨ��1��� */
    unsigned short usStride2;      /* ͼ��ͨ��2��� */
    unsigned long long u64PhyAddr;  /* ͼ������ͨ��0 64λ�����ַ */
    unsigned long long u64PhyAddr1; /* ͼ������ͨ��1 64λ�����ַ */
    unsigned long long u64PhyAddr2; /* ͼ������ͨ��2 64λ�����ַ */

    unsigned int uiReserved[16];   /* �����ֽ� */
}XM_IA_IMAGE_S;

/* Ŀ�����״̬ */
typedef enum
{
    XM_IA_TRACK_LAST,              /* ����Ŀ�� */
    XM_IA_TRACK_LOSS               /* ��ʧĿ�� */

}XM_IA_TRACK_STATUS_E;

/* �㷨������ */
typedef enum
{
    IA_SENSE_LOW,                  /* �������� */
    IA_SENSE_MID,                  /* �������� */
    IA_SENSE_HIGH,                 /* �������� */
    IA_SENSE_NUM,                  /* ���������� */
}XM_IA_SENSE_E;

/* �㷨ͼ��ߴ����ֽṹ�� */
typedef struct
{
    int iDevImgWid;                 /* �豸ͼ���/XM510Ϊ�㷨ȷ�Ϲ���ͼ��� */
    int iDevImgHgt;                 /* �豸ͼ���/XM510Ϊ�㷨ȷ�Ϲ���ͼ��� */
    int iAlgImgWid;                 /* �㷨ͼ��� */
    int iAlgImgHgt;                 /* �㷨ͼ��� */
}XM_IA_IMAGESIZE_EXCHANGE_S;

/* ����߻��ķ��� */
typedef enum
{
    XM_IA_DIRECT_FORWARD,               /* ���� */
    XM_IA_DIRECT_BACKWARD,              /* ���� */
    XM_IA_BIDIRECTION,                  /* ˫�� */
    XM_IA_DIRECT_NUM
}XM_IA_DIRECTION_E;

/* ��ת�Ƕ� */
typedef struct
{
    int iYaw;                       /* ƫ����(-90, 90)����ת������ת */
    int iRoll;                      /* �����(-90, 90)��������Ҹߣ���������ҵ� */
    int iPitch;                     /* ������(-90, 90)�������ӣ���������*/

}XM_IA_ANGLE_S;

/* �����㷨��Դ */
typedef struct
{
    unsigned int uiMemPoolSizeMax;
    int iDevIdx;                    /* NVT98336����DevIdx���� 0:���� 1���� */
    void** ppvHandle;               /* ��ǰ�㷨��� */
    int iMSFlag;                    /* �����Ƿ����ӹ��ܿ��� 0���رգ�1����*/

    unsigned int uiReserved[61];    /* �����ֽ� */
}XM_IA_RESOURCE_LIMIT_S;

/* �㷨�汾�� */
typedef struct
{
    int iMajorVersion;              /* ���汾��.�ӿڴ�С�仯���� */
    int iMinorVersion;              /* �Ӱ汾��.�ӿ������б仯���� */
    int iReversion;                 /* �޸İ汾.ÿ�ΰ汾���޸ĸ��� */
    int iBuild;                     /* ����汾.�ݲ��� */

}XM_IA_VERSION_S;

/* ����IA�㷨���� */
typedef enum
{
    /* �����㷨ռ�� 0��99 */
    XM_FACE_DET_IA = 1,                         /* ��������㷨 */
    XM_FACE_DET_REC_IA = 2,                     /* �������ʶ���㷨 */
    XM_FACE_DET_SSH_IA = 3,                     /* �������SSH�㷨 */
    XM_FACE_DET_REC_LOW_MEM_IA = 4,             /* �������ʶ���㷨(ʶ��ʹ洢�;���) */
    XM_FACE_REC_IA = 5,                         /* ����ʶ���㷨 */
    XM_FACE_ALIVE_IR_IA = 6,                    /* �������������ж��㷨 */
    XM_FACE_POINT_IA = 7,                       /* �����ؼ����ж��㷨 */
    XM_FACE_DET_REC_MASK_IA = 8,                /* �������������ʶ���㷨 */
    XM_FACE_ALIVE_COLOR_IA = 9,                 /* ��ɫ���������ж��㷨 */
    XM_FACE_DEPTH_ALIVE_IA = 10,                /* ������������ж��㷨 */

    /* �����㷨ռ�� 100��199 */
    XM_PEDETRIAN_DETECT_SSH_RULE_IA = 101,      /* ����SSH���μ�� */
    XM_PEDETRIAN_FACE_DETECT_RULE_IA = 102,     /* ����������������㷨 */
    XM_PEDETRIAN_FACE_DET_REC_RULE_IA = 103,    /* ���������������ʶ���㷨 */
    XM_PED_PET_DETECT_RULE_IA = 105,            /* ����������μ�� */
    /* �����㷨ռ�� 200��299 */
    XM_PGS_IA = 200,                            /* ͣ���յ�ϵͳ������������⡢���Ƽ�⡢����ʶ�� */
    XM_PV_DETECT_SSH_RULE_IA = 201,             /* ����SSH�����˼�� */

    /* ҡͷ���㷨ռ�� 300~400 */
    XM_SC_IA = 300,
    XM_OBJECT_TRACKING_IA = 301,                /* Ŀ������㷨 */

    /*��Ʒ�����㷨ռ��400~500*/
    XM_OBJTL_IA = 400,
    //�ƶ�����㷨
    XM_MD_IA = 500,

    /* �����NN */
    XM_PED_BIKE_DET_NN_IA = 600,                /* �˷ǻ��������NN */

    /* ����㷨 */
    XM_TARGET_DETECT_RULE_IA = 700,             /* ����Ŀ�����㷨 */
    XM_TARGET_CLASSIFIER_IA = 702,              /* Ŀ������㷨 */
    XM_PET_DETECT_IA = 710,                     /* ������ */
    /* �����㷨 */
    XM_VAD_IA = 800,                            /* Ӥ��������� */
    XM_KEYWORD_REC_IA = 801,                    /* �ؼ���ʶ�� */

    /* ��ͨ���㷨 */
    XM_TRAFFIC_LIGHT_DET_IA = 900,              /* TLD ��ͨ�Ƽ�� */
    XM_TRAFFIC_SIGN_DET_IA = 901,               /* TSD ��ͨ��־��� */
    XM_LICENSEPLATE_DET_REC_IA = 902,           /* LPDR ���Ƽ��ʶ�� */
    XM_ROADSIDE_PARKING_IA = 903,               /* RSP ·��ͣ�����ʶ�� */
    XM_SIDE_CAR_DET_IA = 904,                   /* ��·������� */
    XM_OBJECT_DET_IA = 905,                     /* OBJD Ŀ���� */
    XM_VEHICLE_TRACKING_IA = 906,               /* VT Ŀ����� */
    XM_VEHICLE_DET_TRACKING_IA = 907,           /* VDT ��·������� */
    /* ͼ�������ж��㷨 */
    XM_IQD_IA = 1000,                       /* �ж�ͼ�������� */

    XM_ADAS_IA = 1100,                       /* ���ظ�����ʻ */

    XM_SDV_IA = 1200,                           /* �����Ӿ��㷨 */
    XM_DMS_BH_IA = 1300,                       /* ��ʻԱ��Ϊ�ж� */
    XM_VECAP_IA = 1400,                        /* ����ץ��ʶ�� */

    XM_MAX_SIZE_IA,
}XM_IA_TYPE_E;

typedef XM_IA_RECT_S XM_IA_LINE_S;
typedef XM_IA_POINT_S XM_IA_IMG_SIZE_S;

/*************************************************
Author: WangZelang
Date: 2021-01-27
Description: ���������㷨Ӳ����ʼ��
*************************************************/
int XM_IA_Init(void);

/*************************************************
Author: WangZelang
Date: 2018-11-28
Description: ���������㷨����
INPUT:  eIAtype       �㷨����
        initParams    ��ʼ�������ṹ��
        Handle        �㷨���
*************************************************/
int XM_IA_Create(XM_IA_TYPE_E eIAtype, void* initParams, void **Handle);

/*************************************************
Author: WangZelang
Date: 2018-11-28
Description: ���������㷨��������
INPUT:  Handle        �㷨���
        inParams      �㷨�������
OUTPUT: Result        �㷨����ṹ��
*************************************************/
int XM_IA_Run(void* Handle, void* inParams, void* Result);

/*************************************************
Author: WangZelang
Date: 2018-11-28
Description: �������������㷨
INPUT:  configParams  �㷨���ýṹ��
        Handle        �㷨���
*************************************************/
int XM_IA_Configuration(void* configParams, void* Handle);

/*************************************************
Author: WangZelang
Date: 2018-11-28
Description: �������������㷨
INPUT:  Handle        �㷨���
*************************************************/
int XM_IA_Destruction(void **Handle);

/*************************************************
Author: FengShiYi
Date: 2020-09-27
Description: ���������㷨���߳����ú���
INPUT:  ThreadNum        �߳���
        eIAType          �㷨����
*************************************************/
int XM_IA_ThreadNum_Set(int ThreadNum, XM_IA_TYPE_E eIAType);

/*************************************************
Author: WangZelang
Date: 2020-10-20
Description: �����㷨ʹ�õ���Դ
INPUT:  eIAType             �㷨����
        pstResourceLimit    �㷨��Դ���ƽṹ��
*************************************************/
int XM_IA_SetResourceLimit(XM_IA_TYPE_E eIAType, XM_IA_RESOURCE_LIMIT_S *pstResourceLimit);

/*************************************************
Author: WangZelang
Date: 2021-01-13
Description: ��ȡ�㷨�汾��Ϣ
INPUT:  eIAType             �㷨����
OUTPUT: pstVersion          �汾��Ϣ
*************************************************/
int XM_IA_GetVersion(XM_IA_TYPE_E eIAType, XM_IA_VERSION_S *pstVersion);

/*************************************************
Author: WuChunXuan
Date: 2020-06-30
Description: �ͷ����������㷨XM_IA_Init��������Դ
*************************************************/
int XM_IA_UnInit(void);

#ifdef  __cplusplus
}
#endif  /* end of __cplusplus */

#endif

