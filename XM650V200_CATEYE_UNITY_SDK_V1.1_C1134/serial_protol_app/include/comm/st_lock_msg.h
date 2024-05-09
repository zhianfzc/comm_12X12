#ifndef __ST_LOCK_MSG_H__
#define __ST_LOCK_MSG_H__

#include "input.h"
#include "version.h"

#define USER_NAME_SIZE 32
#define VERSION_INFO_BUFFER_SIZE 32
#define MAX_USER_COUNTS 100
#define SYNC_WORD_H 0xEF
#define SYNC_WORD_L 0xAA

#define RANDOM_SIZE 4
#define KEY_SIZE 16

#define MY_SUCCESS 0
#define MY_ERRROR -1


#define MY_ERR_PRT(str, err_num) printf("\033[31m %s error ret=0x%x \033[0m \n", str, err_num)
#define MY_STATUS_PRT(str) printf("\033[33m %s \033[0m \n", str)
#define CHECK_RET(express, name) \
			do { \
				unsigned int Ret; \
				Ret = express; \
				if (MY_SUCCESS != Ret) { \
					printf("\033[0;31m[%s:%d]%s failed with %#x!\033[0;39m\n", \
					__FILE__, __LINE__, name, Ret); \
					return Ret; \
				} \
			} while(0)
			
//#define DEFAULT_DUPLICATE_FACE_LIMIT //can re-enroll undefine this

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;

/* communication message ID definitions*/
typedef uint8_t s_msg_id;

// Module to Host (m->h)
#define MID_REPLY 0x00 	// request(command) reply message,success with data or fail with reason
#define MID_NOTE 0x01 	// note to host e.g. the position or angleof the face
#define MID_IMAGE 0X02 	// send image to host

// Host to Module (h->m)
#define MID_RESET 0x10 // stop and clear all in-processingmessages. enter standby mode
#define MID_GETSTATUS 0x11 // to ping the module and get the status
#define MID_VERIFY 0x12 // to verify the person in front of the camera
#define MID_ENROLL 0x13 // to enroll and register the persion in front of the camera
#define MID_ENROLL_SINGLE 0x1D // to enroll and register the persion in front of the camera, with one frame image
#define MID_ENROLL_ITG 0x26 // Integrated enroll message, support all existing enroll type
#define MID_SNAPIMAGE 0x16 // to snap a picture and save it
#define MID_GETSAVEDIMAGE 0x17 // to get size of saved image
#define MID_UPLOADIMAGE 0x18 // upload images
#define MID_DELUSER 0x20 // Delete the specified user with user id
#define MID_DELALL 0x21 // Delete all registerred users
#define MID_GETUSERINFO 0x22 // Get user info
#define MID_FACERESET 0x23 // Reset face status
#define MID_GET_ALL_USERID 0x24 // get all users ID
#define MID_GET_VERSION 0x30 // get version information
#define MID_GET_VERSION_ZA 0x6a // get version information
#define MID_GET_VERSION_ZAPRD 0x3a // get prd version information
#define MID_START_OTA 0x40 // ask the module to enter OTA mode
#define MID_STOP_OTA 0x41 // ask the module to exit OTA mode
#define MID_GET_OTA_STATUS 0x42 // query the current ota status
#define MID_OTA_HEADER 0x43 // the ota header data
#define MID_OTA_PACKET 0x44 // the data packet, carries real firmware data
#define MID_INIT_ENCRYPTION 0x50 // initialize encrypted communication
#define MID_CONFIG_BAUDRATE 0x51 // config uart baudrate
#define MID_SET_RELEASE_ENC_KEY 0x52 // set release encrypted key(Warning!!!:Once set, the KEY will not be able to modify)
#define MID_SET_DEBUG_ENC_KEY 0x53 // set debug encrypted key
//#define MID_GET_LOGFILE 0x60 // get log file
//#define MID_UPLOAD_LOGFILE 0x61 // upload log file
#define MID_SET_UVC_NET_FLAG 0x8F //set uvc net flag 
#define MID_SET_THRESHOLD_LEVEL 0xD4 //set threshold level
#define MID_GET_INIT_TIME 0xC2 //get device init time
#define MID_POWERDOWN 0xED // be prepared to power off
//#define MID_DEBUG_MODE 0xF0 // enter debug mode
//#define MID_GET_DEBUG_INFO 0xF1 // get size of debug information
//#define MID_UPLOAD_DEBUG_INFO 0xF2 // upload debug information
//#define MID_GETLIBRARY_VERSION 0xF3 // Get library version
#define MID_DEMOMODE 0xFE // enter demo mode, verify flow will skip feature comparation step.
#define MID_MAX 0xFF // reserved

/* communication message ID definitions end */

/* message result code */
typedef uint8_t s_msg_result;
#define MR_SUCCESS 0 // success
#define MR_REJECTED 1 // module rejected this command
#define MR_ABORTED 2 // algo aborted
//#define MR_FAILED4_CAMERA 4 // camera open failed
#define MR_FAILED4_UNKNOWNREASON 5 // UNKNOWN_ERROR
#define MR_FAILED4_INVALIDPARAM 6 // invalid param
#define MR_FAILED4_NOMEMORY 7 // no enough memory
#define MR_FAILED4_UNKNOWNUSER 8 // no user enrolled
#define MR_FAILED4_MAXUSER 9 // exceed maximum user number
#define MR_FAILED4_FACEENROLLED 10 // this face has been enrolled
#define MR_FAILED4_LIVENESSCHECK 12// liveness check failed
#define MR_FAILED4_TIMEOUT 13 // exceed the time limit
#define MR_FAILED4_AUTHORIZATION 14// authorization failed
//#define MR_FAILED4_CAMERAFOV 15 // camera fov test failed
//#define MR_FAILED4_CAMERAQUA 16 // camera quality test failed
//#define MR_FAILED4_CAMERASTRU 17 // camera structure test failed
#define MR_FAILED4_BOOT_TIMEOUT 18 // boot up timeout
//#define MR_FAILED4_READ_FILE 19 // read file failed
//#define MR_FAILED4_WRITE_FILE 20 // write file failed
//#define MR_FAILED4_NO_ENCRYPT 21 // encrypt must be set
//#define MR_FAILED4_NO_RGBIMAGE 23 // rgb image is not ready
#define MR_FAILED4_IA_SIGN_UPDATE_FAILED 24 // ia sign update failed(xm add)
/* message result code end */

/* module state */
typedef uint8_t s_mstate;
#define MS_STANDBY 0 // IDLE, waiting for commands
#define MS_BUSY 1 // in working of processing commands
#define MS_ERROR 2 // in error state. can't work properly
#define MS_INVALID 3 // not initialized
#define MS_OTA 4 // in ota state
/* module state end */

// a general message adapter
typedef struct {
	uint8_t sync_word_heb;	// sync word high eight bits
	uint8_t sync_word_leb;	// sync word low eight bits
	uint8_t mid; 		// the message id
	uint8_t size_heb; 	// high eight bits
	uint8_t size_leb; 	// low eight bits
	uint8_t data[0];	// data
	uint8_t parity_check; //parity check
} s_msg;

typedef struct {
	uint8_t sync_word_heb;	// sync word high eight bits
	uint8_t sync_word_leb;	// sync word low eight bits
	uint8_t size_heb; 	// high eight bits
	uint8_t size_leb; 	// low eight bits
	uint8_t data[0];	// data
	uint8_t parity_check; //parity check
} s_enc_msg;

/* message data definitions */
/* module -> host note */
/* msg note id */
typedef uint8_t s_note_id;
#define NID_READY 0 // module ready for handling request(command)
#define NID_FACE_STATE 1 // the detected face status description
#define NID_UNKNOWNERROR 2 // unknown error
#define NID_OTA_DONE 3 // OTA upgrading processing done
#define NID_EYE_STATE 4 // the face in the eye_close status
#define NID_AUTHORIZATION 8 /* License 验证失败 */
/* msg note id end */

/* msg face direction */
typedef uint8_t s_face_dir;
#define FACE_DIRECTION_UP 0x10 // face up
#define FACE_DIRECTION_DOWN 0x08 // face down
#define FACE_DIRECTION_LEFT 0x04 // left face 
#define FACE_DIRECTION_RIGHT 0x02 // right face 
#define FACE_DIRECTION_MIDDLE 0x01 // face middle
#define FACE_DIRECTION_UNDEFINE 0x00 // face undefine
/* msg face direction end */

/* msg face enroll type */
#define FACE_ENROLL_TYPE_INTERACTIVE 0 // interactive enroll
#define FACE_ENROLL_TYPE_SINGLE 1 // enroll with one frame image
/* msg face enroll type end */

#define FACE_STATE_NORMAL 0 // normal state, the face is available
#define FACE_STATE_NOFACE 1 // no face detected
#define FACE_STATE_TOOUP 2 // face is too up side
#define FACE_STATE_TOODOWN 3 // face is too down side
#define FACE_STATE_TOOLEFT 4 // face is too left side
#define FACE_STATE_TOORIGHT 5 // face is too right side
#define FACE_STATE_TOOFAR  6 // face is too far
#define FACE_STATE_TOOCLOSE 7 // face is too near
//#define FACE_STATE_EYEBROW_OCCLUSION 8 // eyebrow occlusion
//#define FACE_STATE_EYE_OCCLUSION 9 // eye occlusion
#define FACE_STATE_FACE_OCCLUSION 10 // face occlusion
#define FACE_STATE_DIRECTION_ERROR 11 // face direction error
//#define FACE_STATE_EYE_CLOSE_STATUS_OPEN_EYE 12 //open eye in the eye close status
//#define FACE_STATE_EYE_CLOSE_STATUS 13 //confirm eye close status
//#define FACE_STATE_EYE_CLOSE_UNKNOW_STATUS 14 //eye close unknow status
#define FACE_STATE_MULTI_FACE 15 //multiple FACE

/* logfile type */
#define LOG_FILE_KERNEL 0 // kernel log
#define LOG_FILE_SENSELOCK_APP 1 // senselock app log
#define LOG_FILE_FACE_MODULE 2 // face module log
/* logfile type end */

/* enc key type */
#define RELEASE_ENC_KEY 0 // for release
#define DEBUG_ENC_KEY 1 // for debug
/* enc key type end */

typedef struct {
	int16_t state; 	// corresponding to FACE_STATE_*
	// position
	int16_t left; 	// in pixel
	int16_t top;
	int16_t right;
	int16_t bottom;
	// pose
	int16_t yaw; 	// up and down in vertical orientation
	int16_t pitch; 	// right or left turned in horizontal orientation
	int16_t roll; 	// slope
} s_note_data_face;

typedef struct {
	uint8_t nid; // note id
	uint8_t data[0];
} s_msg_note_data;
/* module -> host note end */

// enroll user
typedef struct {
	uint8_t admin; 	// the user will be set to admin
	uint8_t user_name[USER_NAME_SIZE];
	s_face_dir face_direction;
	uint8_t timeout; // timeout, unit second default 10s
} s_msg_enroll_data;

// enroll user intergrated
typedef struct {
	uint8_t admin; // the user will be set to admin, 1:admin user, 0:normal user
	uint8_t user_name[USER_NAME_SIZE];
	uint8_t face_direction; // reference FACE_DIRECTION_*
	uint8_t enroll_type; 	// reference FACE_ENROLL_TYPE_*
	uint8_t enable_duplicate; // enable user enroll duplicatly, 1:enable, 0:disable
	uint8_t timeout; // timeout unit second default 10s
	uint8_t reserved[3]; // reserved feild
} s_msg_enroll_itg;

// verify
typedef struct {
	uint8_t pd_rightaway; // power down right away after verifying
	uint8_t timeout; // timeout, unit second, default 10s
} s_msg_verify_data;

// delete user
typedef struct {
	uint8_t user_id_heb; // high eight bits of user_id to be deleted
	uint8_t user_id_leb; // low eight bits pf user_id to be deleted
} s_msg_deluser_data;

// get user info
typedef struct {
	uint8_t user_id_heb; // high eight bits of user_id to get info
	uint8_t user_id_leb; // low eight bits of user_id to get info
} s_msg_getuserinfo_data;

// start ota data MID_START_OTA
typedef struct {
	uint8_t v_primary; // primary version number
	uint8_t v_secondary; // secondary version number
	uint8_t v_revision; // revision number
	uint8_t ota_type; // ota partition: 0:lock_os(rtthread.bin), 1:uvc_os(rtthread_uvc.bin) 2:upall(upall_XM650v200_RT_CAT_EYE.xxx.bin) 3: ProductDefinition
} s_msg_startota_data;

// ota header MID_OTA_HEADER
typedef struct {
	uint8_t fsize_b[4]; // OTA FW file size int -> [b1, b2, b3, b4]
	uint8_t num_pkt[4]; // number packet to be divided for transferring, int ->[b1, b2, b3, b4]
	uint8_t pkt_size[2]; // raw data size of single packet
	uint8_t md5_sum[32]; // md5 check sum
} s_msg_otaheader_data;

// ota packet MID_OTA_PACKET
typedef struct {
	uint8_t pid[2]; // the packet id
	uint8_t psize[2]; // the size of this package
	uint8_t data[0]; // data 0 start
} s_msg_otapacket_data;

// MID_INIT_ENCRYPTION data
typedef struct {
	uint8_t seed[4]; // random data as a seed
	uint8_t mode; // reserved for selecting encrytion mode
	uint8_t crttime[4]; // current time - this is the interface that module sync time with host
} s_msg_init_encryption_data;

// demo data
typedef struct {
	uint8_t enable; // enable demo or not
} s_msg_demomode_data;

// debug mode data
typedef struct {
	uint8_t enable; // enable debug mode or not
} s_msg_debug_mode_data;

// snap image data
typedef struct {
	uint8_t image_counts; // number of stored images
	uint8_t start_number; // start number of stored images
} s_msg_snap_image_data;

// get saved image data
typedef struct {
	uint8_t image_number; // number of saved image
} s_msg_get_saved_image_data;

// upload image
typedef struct {
	uint8_t upload_image_offset[4]; // upload image offset, int -> [o1 o2 o3 o4]
	uint8_t upload_image_size[4]; 	// upload image size, int -> [s1 s2 s3 s4]
} s_msg_upload_image_data;

//config baudrate
typedef struct {
	uint8_t baudrate_index; // 1:115200 2:230400 3:460800 4:921600
}s_msg_config_baudrate;

/* 不支持 */
// upload debug informaiton
typedef struct {
uint8_t upload_debug_info_offset[4]; // upload debug informaiton offset, int -> [o1 o2 o3 o4]
uint8_t upload_debug_info_size[4]; // upload debug informaiton size, int -> [s1 s2 s3 s4]
} s_msg_upload_debug_info_data;

/* 不支持 */
// upload logfile
typedef struct {
	uint8_t upload_logfile_offset[4]; // upload logfile offset, int -> [o1 o2 o3 o4]
	uint8_t upload_logfile_size[4]; // uploade logfile size, int -> [s1 s2 s3 s4]
} s_msg_upload_logfile_data;

/* 不支持 */
// DDR test
typedef struct {
	uint8_t ddr_test_counts; // number of DDR testing
} s_msg_ddr_test_data;

/* message reply data definitions */
typedef struct {
	uint8_t user_id_heb;
	uint8_t user_id_leb;
	uint8_t user_name[USER_NAME_SIZE]; /* 不支持姓名 */
	uint8_t admin;
	uint8_t unlockStatus;
} s_msg_reply_verify_data;

typedef struct {
	uint8_t user_id_heb;
	uint8_t user_id_leb;
	uint8_t face_direction;
} s_msg_reply_enroll_data;

typedef struct {
	uint8_t status;
} s_msg_reply_getstatus_data;

typedef struct {
	uint8_t version_info[VERSION_INFO_BUFFER_SIZE];
} s_msg_reply_version_data;

/* 不支持 */
typedef struct {
	uint8_t library_version_info[20];
} s_msg_reply_library_version_data;

typedef struct {
	uint8_t user_id_heb;
	uint8_t user_id_leb;
	uint8_t user_name[USER_NAME_SIZE];
	uint8_t admin;
} s_msg_reply_getuserinfo_data;

/* 不支持 */
typedef struct {
	uint8_t user_counts; // number of enrolled users
	uint8_t users_id[MAX_USER_COUNTS*2]; //use 2 bytes to save a user ID and save high eight bits firstly
} s_msg_reply_all_userid_data;

/* 不支持 */
typedef struct {
	uint8_t time_heb; // high eight bits of factory test time
	uint8_t time_leb; // low eight bits of facetory test time
} s_msg_reply_factory_test_data;

/* 不支持 */
// MID_INIT_ENCRYPTION reply
typedef struct {
	uint8_t device_id[20]; // the unique ID of this device, string type
} s_msg_reply_init_encryption_data;

/* 不支持 */
// REPLY MID_GET_OTA_STATUS
typedef struct {
	uint8_t ota_status; // current ota status
	uint8_t next_pid_e[2]; // expected next pid, [b0,b1]
} s_msg_reply_getotastatus_data;

typedef struct {
	uint8_t image_size[4]; // image size int -> [s1, s2, s3, s4]
} s_msg_reply_get_saved_image_data;

/* 不支持 */
typedef struct {
	uint8_t debug_file_size[4]; // debug file size int -> [s1, s2, s3, s4]
} s_msg_reply_get_debug_info_data;

typedef struct {
	uint8_t mid; // the command(message) id to reply (the request message ID)
	uint8_t result; // command handling result: success or failed ->
	uint8_t data[0];
} s_msg_reply_data;

typedef struct {
	uint8_t ota_result;//0 :is sucess; 1: is faile;
} s_note_ota_result;

typedef struct {
	uint8_t baudrate_index;//1: is 115200 (115200*1); 2 is 230400 (115200*2); 3 is 460800 (115200*4); 4 is 1500000
} s_note_config_baudrate;

/* 不支持 */
typedef struct {
	uint8_t enc_key_number[16]; //
} s_msg_enc_key_number_data;

typedef struct {
	uint8_t verify_threshold_level; // level 0~4, safety from low to high, default 2
	uint8_t liveness_threshold_level; // level 0~4, safety from low to high, default 2
}s_msg_algo_threshold_level;

typedef struct {
	uint8_t time[2]; //ms time[0]: high eight bits   time[1]: lows eight bits
} s_msg_reply_init_time;

typedef struct ST_SIZE_S
{
    unsigned int u32Width;
    unsigned int u32Height;
} ST_SIZE_S;

typedef enum {
    SIGN_DISABLE 	= 0,
    SIGN_ENABLE  	= 1,
    SIGN_ENABLE_END	= 2
} SIGN_STATUS_E;

/* get app init sign */
extern unsigned char init_sign_get();

/* get verify usr pass id */
extern unsigned char usr_pass_id_get();

/* single enroll */
extern int single_enroll(s_msg_enroll_data *pst_enroll);

/* five point enroll */
extern int five_point_enroll(s_msg_enroll_data *pst_enroll);

/* judge duplicate face (return [0]:no duplicate face  [-1]:duplicate face) */
extern int duplicate_face_judge(unsigned char enable_duplicate);

/* generate encryption key */
extern void gen_enc_key();

/* encryption msg */
extern int enc_bytes(uint8_t *bytes, int length, const uint8_t *key, int stride, uint8_t *out);

/* dencryption msg */
extern int decrypt_bytes(uint8_t *bytes, int length, const uint8_t *key, int stride, uint8_t *out);

/* ota mmz alloc */
extern int ota_mmz_alloc(unsigned int buf_size, unsigned char **p_bur_addr);

/* set scan mode  0:disable 1:enable */
extern int scan_mode_set(unsigned int value);

char *cap_sign_addr_get();
unsigned char verify_timeout_get();
unsigned char *enroll_timeout_get();
unsigned char *ota_mode_get();
unsigned char demo_mode_get();
int st_mod_to_host_mid(uint8_t mid, uint8_t nid, uint8_t reply_result);
int uart_connect();

#endif 


