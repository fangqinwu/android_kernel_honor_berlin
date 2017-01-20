/******************************************************************************

    Copyright(C)2008,Hisilicon Co. LTD.

 ******************************************************************************
  File Name       : LrrcErrLogInterface.h
  Description     : LrrcErrLogInterface.h header file
  History         :
     1.HANLUFENG 41410       2013-8-27     Draft Enact
     2.
******************************************************************************/

#ifndef __LRRCERRLOGINTERFACE_H__
#define __LRRCERRLOGINTERFACE_H__

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

/*****************************************************************************
  1 Include Headfile
*****************************************************************************/
#include  "vos.h"


#include "omerrorlog.h"
#include "AppRrcInterface.h"
#include "OmCommon.h"
//#include "LPsOm.h"


#if (VOS_OS_VER != VOS_WIN32)
#pragma pack(4)
#else
#pragma pack(push, 4)
#endif


/*****************************************************************************
  2 macro
*****************************************************************************/

/*****************************************************************************
  3 Massage Declare
*****************************************************************************/
/* LTE֧��CA����£�֧�ֵ������Ƶ����V9R1Ϊ1��V7R2��K3V3Ϊ2��Э��涨���ֵΪ5 */
#define LRRC_APP_MAX_NUM 5

/* RRC error����ʱ��RRC�Ľ�����Ϣ��¼����������������ԭ��ͽ�� */
#define RRC_APP_MAX_RRC_EST_INFO_NUM              (5)

/* Э��ֵ:3 */
#define RRC_APP_MAX_NUM_OF_MCC                    (3)

/* RRC error����ʱ����ӡ�����Ϣ������¼���� */
#define RRC_APP_ERROR_PRINT_INFO_NUM              (4)

/* RRC error����ʱ��ģ�����������Ϣ������¼���� */
#define RRC_APP_RECEIVE_MSG_INFO_NUM              (16)

/* RRC error����ʱ������RRC�����������¼���� */
#define RRC_APP_CODE_NUM                          (4)

/* LTE֧��MIMOʱ�����ͬʱ֧�ֵ������� */
#define NUM_OF_CODEWORD                           (2)

/* ErrorLog����������Ϣbegin */
/* RRC error����ʱ����������¼���� */
#define RRC_ERRLOG_AREA_LOST_MAX_NUM             (4)
/* ErrorLog����������Ϣend */

#define LRRC_OM_Q_LOW_CELL_NUM_MAX                (8)
#define LRRC_OM_PING_PONG_INFO_NUM_MAX            (8)
#define LRRC_OM_PING_PONG_CELL_NUM_MAX            (8)
#define LRRC_OM_MOBILITY_2_QLOW_NUM_MAX           (8)
#define LRRC_OM_ESR_NUM_MAX                       (8)
#define LRRC_OM_OUT_OF_SYNC_NUM_MAX               (8)

#define LRRC_OM_MAX_LTE_INTER_FREQ_COUNT           (16)
#define LRRC_OM_MAX_SINGLE_FREQ_CELL_COUNT         (16)

#define LRRC_OM_AIR_MSG_MAX_LEN                    (240)
#define LRRC_OM_AIR_MSG_BUF_LEN                    (720)
#define LRRC_OM_SINGLR_AIR_MSG_MAX_LEN             (360)
#define LRRC_OM_AIR_MSG_MAX_RECORD_TIMEINT         (300)    /*�տ���Ϣ��¼�������*/

#define LRRC_OM_SINGE_PRINT_LEN                    (24)
#define LRRC_OM_PRINT_INFO_NUM                     (6)
#define LRRC_OM_SRVCC_MAX_MEASID_NUM               (3)

#define  LRRC_CHR_RPT_GUT2L_RESEL_FAIL_MAX_NUM           (10)

#define LRRC_OM_KEY_EVENT_DB_NUM                   56
#define LRRC_OM_UL_AIRMSG_DB_NUM                   60
#define LRRC_OM_AIR_SIGNAL_INFO_ELE_NUM            20
#define LRRC_OM_MEAS_RPT_DB_NUM                    16
#define LL2_OM_VOLTE_PKT_INFO_RPT_NUM              20

#define LRRC_OM_INVALID_LTE_CELLID                 0xFFFFUL

#define LRRC_OM_AIR_SIGNAL_RECORD_INTERVAL         400
#define LRRC_OM_INFO_RECORD_MAXINTVAL              90000   /*�¼����տڲ���������¼���*/

#define TLPS_SECU_FUNCTION_ERR_MAXNO               10


/* Volteͳ�����ĸ��� */
#define LRRC_LPDCP_VOLTE_STAT_NUM                  (6)

#define CHR_DIRECTRPT_HDR_LEN                       (sizeof(OM_ERR_LOG_HEADER_STRU) + sizeof(MODEM_ERR_LOG_HEADER_STRU))

/* BAND-38 Scell Not config MFBI record begin */
#define  LRRC_OM_SCELL_NOTCONFIG_MFBI_MAX_NUM             (30)
#define  LRRC_OM_SCELL_NOTCONFIG_MFBI_RPT_TIME_INTERVAL   (6*3600)
/* BAND-38 Scell Not config MFBI record end */


#define LRRC_VOLTE_GEN_STAT_CALL_NUM                16
#define LRRC_VOLTE_GEN_STAT_FAULT_NUM               40


/*****************************************************************************
  4 Enum
*****************************************************************************/
/* HIDS��ʾ��Ŀ�� */
typedef VOS_UINT16 LRRC_OM_AIRMSG_TYPE_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_GUTRRC_CELL_RESEL_RESULT_ENUM
 Э�����  :
 ASN.1���� :
 ö��˵��  : GUT��LTE֮��CELL RESEL���
*****************************************************************************/
enum LRRC_GUTRRC_RESEL_FAIL_CAUSE_ENUM
{
    LRRC_GUTRRC_CELL_RESEL_ARFCN_NOT_SUPPORT            = 0     ,                  /*��ѡ������飬��ѡƵ�㲻֧�� */
    LRRC_GUTRRC_CELL_LOCKED                          ,                             /*��ѡ������飬������С��*/
    LRRC_GUTRRC_FREQ_LOCKED                          ,                             /*��ѡ������飬������Ƶ��*/
    LRRC_GUTRRC_CELL_BARRED                                       ,                /* С����BAR�б���*/


    LRRC_GUTRRC_CELL_SET_WORK_MODE_FAIL                          ,                 /* �������������л�ģʽʧ��*/
    LRRC_GUTRRC_CELL_DSDS_NO_RF_FAIL                             ,                 /* DSDS������û��RF��Դ*/
    LRRC_GUTRRC_CELL_SEARCH_APPLY_RF_FAIL                        ,                 /*С������ǰ��������Դʧ��*/
    LRRC_GUTRRC_CELL_SEARCH_RF_OCCUPYED                          ,                 /*С�����������У���Դ����ռ����ֹͣ*/
    LRRC_GUTRRC_CELL_SEARCH_RSSI_SORT_FAIL                       ,                 /*�������ϱ�RSSI IND��������*/
    LRRC_GUTRRC_BAND_SCAN_IND_NO_RF                              ,                 /*�������ϱ�BAND SCAN IND,ʧ��ԭ��ΪNO-RF*/

    LRRC_GUTRRC_CELL_SEARCH_IND_NO_RF                            ,                 /*�������ϱ�CELL SEARCH IND,ʧ��ԭ��ΪNO-RF*/
    LRRC_GUTRRC_CELL_SEARCH_IND_LOCKED                          ,                  /*�������ϱ�CELL_SEARCH_IND,ʧ��ԭ��Ϊ������С��*/
    LRRC_GUTRRC_CELL_SEARCH_IND_FAKE                            ,                  /*�������ϱ�CELL_SEARCH_IND,ʧ��ԭ��Ϊ��С��*/
    LRRC_GUTRRC_CELL_SEARCH_IND_BAND_NOT_SUPP                   ,                  /*�������ϱ�CELL_SEARCH_IND,ʧ��ԭ��ΪBAND ��֧��*/

    LRRC_GUTRRC_CELL_SEARCH_IND_RSRP_LOW                        ,                  /*�������ϱ�CELL_SEARCH_IND,ʧ��ԭ��ΪRSRPֵ̫��*/
    LRRC_GUTRRC_CELL_SEARCH_IND_RSRQ_LOW                        ,                  /*�������ϱ�CELL_SEARCH_IND,ʧ��ԭ��ΪRSRQֵ̫*/
    LRRC_GUTRRC_CELL_SEARCH_IND_ACC_BARED                       ,                  /*�������ϱ�CELL_SEARCH_IND,ԭ��ΪС����ν���ʧ�ܱ�BAR*/
    LRRC_GUTRRC_CELL_SEARCH_IND_NO_CELL                         ,                  /*�������ϱ�CELL_SEARCH_IND,ʧ��ԭ��ΪС��������*/

    LRRC_GUTRRC_CELL_SYSINFO_SIB_RCV_FAIL                         ,                /* ϵͳ��Ϣ����ʧ��*/
    LRRC_GUTRRC_CELL_SYSINFO_CELL_AC_BARRED                       ,                /* ϵͳ��Ϣ��BARָʾ�����½���ʧ��*/
    LRRC_GUTRRC_CELL_SYSINFO_CELL_MFBI_ERROR                      ,                /* MFBI������������Ϣband����multiband�б���*/
    LRRC_GUTRRC_CELL_SYSINFO_CHINA_MOBILE_FDD                      ,               /* MCCΪ�й��ƶ���ϵͳ��ϢΪFDD*/
    LRRC_GUTRRC_CELL_SYSINFO_SOFT_BANK_ERROR                      ,                /* �������������쳣*/
    LRRC_GUTRRC_CELL_SYSINFO_BAND_NOT_SUPPORT                     ,                /* BAND��֧��*/


    LRRC_GUTRRC_CELL_SYSINFO_CELL_FORBID                          ,                /* CELL �� FORBID*/
    LRRC_GUTRRC_CELL_SYSINFO_NOT_EPLMNS                           ,                /* CELLЯ����PLMN��Ϣû������RPLMN��EPLMNS */
    LRRC_GUTRRC_CELL_S_CHECK_FAIL                               ,                  /* S׼������*/
    LRRC_GUTRRC_CELL_CAMP_FAIL                                  ,                  /* פ��ʧ��*/
    LRRC_GUTRRC_CELL_PCH_SETUP_FAIL                             ,                  /* Ѱ���ŵ�����ʧ��*/

    LRRC_GUTRRC_CELL_RESEL_UNSPECIFIC                           ,                  /* ����δ����Ĵ��� */

    LRRC_GUTRRC_CELL_RESEL_RESULT_BUTT
};
typedef VOS_UINT32 LRRC_GUTRRC_RESEL_FAIL_CAUSE_ENUM_UINT32;

enum RRC_APP_FTM_TYPE_ENUM
{
    RRC_APP_FTM_PERIOD_INFO,     /* �������ϱ��Ĺ���ģʽ��Ϣ��ĿǰIdle״̬�ϱ�����ΪDRX���ڣ�Connected״̬������Ϊ1�� */
    RRC_APP_FTM_CHANGE_INFO,     /* ���º��ϱ��͵Ĺ���ģʽ��Ϣ */
    RRC_APP_FTM_INFO_BUTT
};
typedef VOS_UINT32 RRC_APP_FTM_TYPE_ENUM_UINT32;

/*****************************************************************************
 ö����    : RRC_APP_PAGING_CYCLE_ENUM
 Э�����  :
 ASN.1���� :
 ö��˵��  : Ѱ�����ڣ�RFXX��XX��ʾ����֡��������λΪ10ms,RF32������320ms��������ʾΪXXXms
*****************************************************************************/
enum RRC_APP_PAGING_CYCLE_ENUM
{
    RRC_APP_RF32                                     = 0,
    RRC_APP_RF64                                     = 1,
    RRC_APP_RF128                                    = 2,
    RRC_APP_RF256                                    = 3
};
typedef VOS_UINT32 RRC_APP_PAGING_CYCLE_ENUM_UINT32;
/*****************************************************************************
 ö����    : RRC_APP_TRANSM_MODE_ENUM
 Э�����  :
 ASN.1���� :
 ö��˵��  : ����ģʽ���ͣ�����ֱ����ʾTMX_TRANSM_MODE����
*****************************************************************************/
enum RRC_APP_TRANSM_MODE_ENUM
{
    RRC_APP_TM1_TRANSM_MODE                          = 0,
    RRC_APP_TM2_TRANSM_MODE                          = 1,
    RRC_APP_TM3_TRANSM_MODE                          = 2,
    RRC_APP_TM4_TRANSM_MODE                          = 3,
    RRC_APP_TM5_TRANSM_MODE                          = 4,
    RRC_APP_TM6_TRANSM_MODE                          = 5,
    RRC_APP_TM7_TRANSM_MODE                          = 6,
    RRC_APP_TM8_TRANSM_MODE                          = 7,
    RRC_APP_TM9_TRANSM_MODE                          = 8,
    RRC_APP_TRANSM_MODE_BUTT
};
typedef VOS_UINT32 RRC_APP_TRANSM_MODE_ENUM_UINT32;
/*****************************************************************************
 ö����    : RRC_APP_PROTOCOL_STATE_IND
 Э�����  :
 ASN.1���� :
 ö��˵��  : RRCЭ��״̬����
*****************************************************************************/
enum RRC_APP_PROTOCOL_STATE_IND_ENUM
{
    RRC_APP_PROTOCOL_IDLE                   = 0 ,
    RRC_APP_PROTOCOL_CONNECTED,
    RRC_APP_PROTOCOL_STATE_BUTT
};
typedef VOS_UINT8 RRC_APP_PROTOCOL_STATE_IND_ENUM_UINT8;

/*****************************************************************************
 ö����    : RRC_APP_ERROR_CODE_ENUM
 Э�����  :
 ASN.1���� :
 ö��˵��  : RRC����������
*****************************************************************************/
enum RRC_APP_ERROR_CODE_ENUM
{
    RRC_APP_RB_MEAS_CHECK_ERR               = 0, /* ������ʧ��--measConfig���ʧ�� */
    RRC_APP_RB_MOCTRL_CHECK_ERR             = 1, /* ������ʧ��--MobilCtrlInfo �л���Ϣ���ʧ�� */
    RRC_APP_RB_RADIOSRC_CHECK_ERR           = 2, /* ������ʧ��--RadioRsrcConfigDedic ��Ϣ���ʧ�� */
    RRC_APP_RB_TTIBUNDING_CHECK_ERR         = 3, /* ������ʧ��--TTIBundling ���ʧ�� */
    RRC_APP_RB_SECU_CHECK_ERR               = 4, /* ������ʧ��--SecurCfgHo �л��а�ȫ���ʧ�� */
    RRC_APP_RB_CFGDSP_ERR                   = 5, /* ������ʧ��--����DSP��DSP����ʧ�� */
    RRC_APP_RB_CFGL2_ERR                    = 6, /* ������ʧ��--����L2,L2����ʧ�� */
    RRC_APP_RB_CFGDSP_TIMEROUT_ERR          = 7, /* ������ʧ��--����DSP��������ʱ����ʱ */
    RRC_APP_RB_CFGL2_TIMEROUT_ERR           = 8, /* ������ʧ��--����L2��������ʱ����ʱ */

    RRC_APP_EST_PRESENT                         = 12, /* RRC���ӽ���ʧ��--RRC�����Ѵ���*/
    RRC_APP_EST_ESTING                          = 13, /* RRC���ӽ���ʧ��--RRC���ڽ���*/
    RRC_APP_EST_DELING                          = 14, /* RRC���ӽ���ʧ��--RRC�����ͷ�����*/
    RRC_APP_EST_DSDS_NO_RF                      = 15, /* RRC���ӽ���ʧ��--˫ͨ:����Ƶ��Դ*/
    RRC_APP_EST_CELL_SEARCHING                  = 16, /* RRC���ӽ���ʧ��--RRC��������*/
    RRC_APP_EST_EUTRAN_REJ                      = 17, /* RRC���ӽ���ʧ��--����ܾ�����*/

    RRC_APP_EST_MT_T302_ERR                     = 18, /* RRC���ӽ���ʧ��--MT Call��T302��ʱ�������� */

    RRC_APP_EST_MO_T302_ERR                     = 22, /* RRC���ӽ���ʧ��--Mo Data��T302��ʱ�������� */
    RRC_APP_EST_MO_T303_ERR                     = 23, /* RRC���ӽ���ʧ��--Mo Data��T303��ʱ�������� */
    RRC_APP_EST_MO_ACC_PROBABILITY_ERR          = 24, /* RRC���ӽ���ʧ��--Mo Data��ACC����ȼ����� */
    RRC_APP_EST_MO_RHPLMN_PROBABILITY_ERR       = 25, /* RRC���ӽ���ʧ��--Mo Data��Rplmn��Hplmn���� */
    RRC_APP_EST_MO_ACC_RHPLMN_PROBABILITY_ERR   = 26, /* RRC���ӽ���ʧ��--Mo Data��AcBarringForMoData�����жϱ�Bar */

    RRC_APP_EST_MS_T302_ERR                     = 28, /* RRC���ӽ���ʧ��--Mo Signalling��T302��ʱ�������� */
    RRC_APP_EST_MS_T305_ERR                     = 29, /* RRC���ӽ���ʧ��--Mo Signalling��T305��ʱ�������� */
    RRC_APP_EST_MS_ACC_PROBABILITY_ERR          = 30, /* RRC���ӽ���ʧ��--Mo Signalling��ACC����ȼ����� */
    RRC_APP_EST_MS_RHPLMN_PROBABILITY_ERR       = 31, /* RRC���ӽ���ʧ��--Mo Signalling��Rplmn��Hplmn���� */
    RRC_APP_EST_MS_ACC_RHPLMN_PROBABILITY_ERR   = 32, /* Mo Signalling��AcBarringForMoData�����жϱ�Bar */
    RRC_APP_EST_T300_EXPIRED_ERR                = 33, /* RRC���ӽ���ʧ��--T300��ʱ*/
    RRC_APP_EST_AREA_LOST_ERR                   = 34, /* ��ǰ�Ѿ���������ֱ�Ӹ�NAS��ʧ�� */

    /* ErrorLog����������Ϣbegin */
    RRC_APP_AREA_LOST_ERR                       = 35,  /* �ϱ�NAS���� */
    /* ErrorLog����������Ϣend */

    RRC_APP_REEST_T311_TIMEROUT_ERR             = 49, /* �ؽ���ʧ��--�ؽ�������С������T311��ʱ����ʱ */
    RRC_APP_REEST_T301_TIMEROUT_ERR             = 50, /* �ؽ���ʧ��--���ͽ���Req��Ϣ�󣬵ȴ��ؽ���Ӧ��Ϣ��T301��ʱ */
    RRC_APP_REEST_SRB0CFGDSP_ERR                = 51, /* �ؽ���ʧ��--����DSP��DSP����ʧ�� */
    RRC_APP_REEST_SRB0CFGL2_ERR                 = 52, /* �ؽ���ʧ��--����L2��L2����ʧ�� */
    RRC_APP_REEST_MACCFG_CHECK_ERR              = 53, /* �ؽ���ʧ��--��Ϣ���MasCfgʧ�� */
    RRC_APP_REEST_PHYDEDIC_CHECK_ERR            = 54, /* �ؽ���ʧ��--��Ϣ���PhyCfgDedicʧ�� */
    RRC_APP_REEST_TTIBUND_CHECK_ERR             = 55, /* �ؽ���ʧ��--ttiBundling���ʧ�� */
    RRC_APP_REEST_SRB_CHECK_ERR                 = 56, /* �ؽ���ʧ��--SRB���ʧ�ܳ�ʱ */
    RRC_APP_REEST_SPS_CHECK_ERR                 = 57, /* �ؽ���ʧ��--SPS���ʧ�� */
    RRC_APP_REEST_SRB1CFGDSP_ERR                = 58, /* �ؽ���ʧ��--����DSP��DSP����ʧ�� */
    RRC_APP_REEST_SRB1CFGL2_ERR                 = 59, /* �ؽ���ʧ��--����L2��L2����ʧ�� */
    RRC_APP_REEST_SECU_ERR                      = 60, /* �ؽ���ʧ��--��ȫ������ʧ�� */

    RRC_APP_QLOW_WARN                           = 70,/* ��ʱ��פ������С������----������ܲ����� */
    RRC_APP_PINGPONG_WARN                       = 71,/* ƹ����ѡ�澯----���ܵ��±��в�ͨ */
    RRC_APP_CSFB_FAIL_ERR                       = 72,/* CSFBʧ�� --- ���ܵ������л򱻽в�ͨ */
    RRC_APP_MOBILITY_2_QLOW_WARN                = 73,/* ��ѡ�ض�����С��----������ܲ����� */
    RRC_APP_OUT_SYNC_ERR                        = 74,/* ʧ������ */
    RRC_APP_SRCHED_FIRST_FREQ_INFO              = 75,/* �����ѵ���һ��MCCʱ��Ƶ����Ϣ�ϱ� major */
    RRC_APP_SRCHED_SUCC_FREQ_INFO               = 76,/* �����ɹ�ʱƵ����Ϣ�ϱ� major */
    RRC_APP_SERVICE_RECOVER_WARN                = 77,/* �������������»ָ� */

    RRC_APP_MAC_RA_MAC_ERR                      = 78,/* �������ʧ��,Mac�ϱ�Err_Ind */
    RRC_APP_MAC_RA_CNF_FAIL                     = 79,/* �������ʧ��,�����������MAC�ظ�CNFָʾʧ�� */
    RRC_APP_MAC_RA_CNF_TIME_OUT                 = 80,/* �������ʧ��,����������󣬵ȴ�Mac�ظ�Cnf��ʱ */

    RRC_APP_AIRMSG_DECODE_FAIL                  = 81,/* �տ���ϢASN����ʧ�� */
    RRC_APP_AIRMSG_CHECK_FAIL                   = 82,/* �տ���Ϣ���ʧ�� */
    RRC_APP_SRVCC_FAIL_REEST                    = 83,/* SRVCC ʧ�� -- HOʧ�ܵ��ؽ������� */
    RRC_APP_SRVCC_FAIL_RF_FAIL                  = 84,/* SRVCC ʧ�� -- RFʧ���ؽ������� */
    RRC_APP_SRVCC_FAIL_CONN_REL                 = 85,/* SRVCC ʧ�� -- �쳣�ͷŴ��� */
    RRC_APP_SRVCC_FAIL_IRAT_FAIL                = 86,/* SRVCC ʧ�� -- ��ϵͳ�л�ʧ�ܴ��� */
    RRC_APP_SRVCC_STAT                          = 87,/* SRVCC ͳ����Ϣ */

    RRC_APP_LONG_TIME_INTER_MEAS                = 88,/* ��ʱ��������Ƶ��ϵͳ���� */
    RRC_APP_TLPS_SECU_FUNCTION_INFO_ERR         = 89,/* ��ȫ����ִ���쳣 */
    RRC_APP_MOD3_NCELL_IDLE_WARN                = 90,/* Idle̬������ģ3���ǿ���������澯 */
    RRC_APP_MOD3_NCELL_CONN_WARN                = 91,/* Conn̬������ģ3���ǿ���������澯 */

    RRC_APP_REEST_CAUSE_MAC_ERR                 = 92,/* Mac�ϱ�err���µ�������·ʧ���ؽ��� */
    RRC_APP_REEST_CAUSE_RLC_ERR                 = 93,/* Rlc�ϱ�err���µ�������·ʧ���ؽ��� */
    RRC_APP_REEST_CAUSE_OUT_OF_SYNC             = 94,/* �������ϱ�ʧ���������ؽ��� */

    RRC_APP_U2L_RESEL_FAIL                      = 95,/* TW��L��ѡʧ�� */
    RRC_APP_G2L_RESEL_FAIL                      = 96,/* G��L��ѡʧ�� */

    /* BAND-38 Scell Not config MFBI record begin */
    RRC_APP_BAND38_NCONFIG                      = 97,/* Band38С��δ����MFBIͳ�� */
    /* BAND-38 Scell Not config MFBI record end */

    RRC_APP_ERR_CODE_BUTT
};
typedef VOS_UINT16 RRC_APP_ERROR_CODE_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LNAS_EST_CAUSE_ENUM
 Э�����  :
 ASN.1���� :
 ö��˵��  : RRMM_EST_REQ_STRU��Ϣ�е�enEstCause
              emergency, highPriorityAccess, mt-Access, mo-Signalling, mo-Data,delayTolerantAccess-v1020 ,
*****************************************************************************/
enum LRRC_APP_LNAS_EST_CAUSE_ENUM
{
    LRRC_APP_LNAS_EST_CAUSE_EMERGENCY_CALL          = 0,
    LRRC_APP_LNAS_EST_CAUSE_HIGH_PRIORITY_ACCESS,
    LRRC_APP_LNAS_EST_CAUSE_MT_ACCESS,
    LRRC_APP_LNAS_EST_CAUSE_MO_SIGNALLING,
    LRRC_APP_LNAS_EST_CAUSE_MO_DATA,
    LRRC_APP_LNAS_EST_CAUSE_BUTT
};
typedef VOS_UINT8 LRRC_APP_LNAS_EST_CAUSE_ENUM_UINT8;

/*****************************************************************************
 ö����    : LRRC_LNAS_EST_RESULT_ENUM
 Э�����  :
 ASN.1���� :
 ö��˵��  : �������ӽ��ö������
*****************************************************************************/
enum LRRC_APP_LNAS_EST_RESULT_ENUM
{
    LRRC_APP_EST_SUCCESS                         = 0,       /* �������ӽ����ɹ� */
    LRRC_APP_EST_PRESENT                         = 1,       /* �����������Ѿ����� */
    LRRC_APP_EST_ESTING                          = 2,       /* �������������ڽ��� */
    LRRC_APP_EST_DELING                          = 3,       /* ���������������ͷ� */
    LRRC_APP_EST_ACCESS_BARRED_MO_CALL           = 4,       /* access barred when MO Call */
    LRRC_APP_EST_ACCESS_BARRED_MO_SIGNAL         = 5,       /* access barred When MO SIGNAL */
    LRRC_APP_EST_ACCESS_BARRED_EMERGENCY_CALL    = 6,       /* access barred When Emergency Call */
    LRRC_APP_EST_ACCESS_BARRED_ALL               = 7,       /* access barred When Rrc Con Rej */
    LRRC_APP_EST_EST_CONN_FAIL                   = 8,       /* RR connection establish failure  */
    LRRC_APP_EST_RJ_INTER_RAT                    = 9,       /* RR connection Reject: ָʾ������ϵͳ */
    LRRC_APP_EST_IMMEDIATE_ASSIGN_REJECT         = 10,      /* �����Ľ�����̣�����RA������յ�����ָ�ɾܾ���Ϣ��
                                                                û���յ�����ָ����Ϣ�����µĽ���ʧ�� */
    LRRC_APP_EST_RANDOM_ACCESS_REJECT            = 11,      /* �����Ľ�����̣�����RA�����û���յ�����������ָ�ɣ�
                                                                Ҳû���յ�����ָ�ɾܾ�������ʧ�� */
    LRRC_APP_EST_CELL_SEARCHING                  = 12,      /* RRCĿǰ���ܴ�����������NAS�յ���ԭ��ֵ��
                                                                ֱ���յ�RRC_MM_SYS_INFO_IND�ٷ�����*/
    LRRC_APP_EST_RESULT_BUTT
};
typedef VOS_UINT8 LRRC_APP_LNAS_EST_RESULT_ENUM_UINT8;

/*****************************************************************************
 ö����    : LRRC_FLOW_CTRL_TYPE_ENUM
 Э�����  :
 ASN.1���� :
 ö��˵��  : ���̿�������ö��
             �޸�ö��ʱ��Ҫע�⣬ʧ������ȡֵ = ��������ȡֵ+1
 ����: LRRC_FLOW_CTRL_TYPE_G2L_RESEL_FAIL = LRRC_FLOW_CTRL_TYPE_G2L_START_RESEL + 1
*****************************************************************************/
enum LRRC_APP_FLOW_CTRL_TYPE_ENUM
{
    LRRC_APP_FLOW_CTRL_TYPE_L2L_NORMAL            = 0,     /* LTE������ */
    LRRC_APP_FLOW_CTRL_TYPE_G2L_START_RESEL,               /* G->L��ʼ��ѡ */
    LRRC_APP_FLOW_CTRL_TYPE_G2L_RESEL_FAIL,                /* G->L��ѡʧ�� */
    LRRC_APP_FLOW_CTRL_TYPE_G2L_STOP_RESEL,                /* G->Lֹͣ��ѡ */
    LRRC_APP_FLOW_CTRL_TYPE_G2L_START_REDIR,               /* G->L��ʼ�ض��� */
    LRRC_APP_FLOW_CTRL_TYPE_G2L_REDIR_FAIL,                /* G->L�ض���ʧ�� */
    LRRC_APP_FLOW_CTRL_TYPE_G2L_STOP_REDIR,                /* G->Lֹͣ�ض��� */
    LRRC_APP_FLOW_CTRL_TYPE_G2L_START_CCO,                 /* G->L��ʼCCO */
    LRRC_APP_FLOW_CTRL_TYPE_G2L_CCO_FAIL,                  /* G->L CCOʧ�� */
    LRRC_APP_FLOW_CTRL_TYPE_G2L_STOP_CCO,                  /* G->LֹͣCCO */
    LRRC_APP_FLOW_CTRL_TYPE_G2L_START_HO,                  /* G->L��ʼHO */
    LRRC_APP_FLOW_CTRL_TYPE_G2L_HO_FAIL,                   /* G->L HOʧ�� */
    LRRC_APP_FLOW_CTRL_TYPE_G2L_STOP_HO,                   /* G->LֹͣHO */
    LRRC_APP_FLOW_CTRL_TYPE_W2L_START_RESEL,               /* W->L��ʼ��ѡ */
    LRRC_APP_FLOW_CTRL_TYPE_W2L_RESEL_FAIL,                /* W->L��ѡʧ�� */
    LRRC_APP_FLOW_CTRL_TYPE_W2L_STOP_RESEL,                /* W->Lֹͣ��ѡ */
    LRRC_APP_FLOW_CTRL_TYPE_W2L_START_REDIR,               /* W->L��ʼ�ض��� */
    LRRC_APP_FLOW_CTRL_TYPE_W2L_REDIR_FAIL,                /* W->L�ض���ʧ�� */
    LRRC_APP_FLOW_CTRL_TYPE_W2L_STOP_REDIR,                /* W->Lֹͣ�ض��� */
    LRRC_APP_FLOW_CTRL_TYPE_W2L_START_HO,                  /* W->L��ʼHO */
    LRRC_APP_FLOW_CTRL_TYPE_W2L_HO_FAIL,                   /* W->L HOʧ�� */
    LRRC_APP_FLOW_CTRL_TYPE_W2L_STOP_HO,                   /* W->LֹͣHO */
    LRRC_APP_FLOW_CTRL_TYPE_W2L_START_PLMN,                /* W->L��ʼPLMN���� */
    LRRC_APP_FLOW_CTRL_TYPE_W2L_DONE_PLMN,                 /* W->L PLMN������� */
    LRRC_APP_FLOW_CTRL_TYPE_W2L_STOP_PLMN,                 /* W->LֹͣPLMN���� */
    LRRC_APP_FLOW_CTRL_TYPE_L2G_START_RESEL,               /* L->G��ʼ��ѡ */
    LRRC_APP_FLOW_CTRL_TYPE_L2G_RESEL_FAIL,                /* L->G��ѡʧ�� */
    LRRC_APP_FLOW_CTRL_TYPE_L2G_START_REDIR,               /* L->G�ض��� */
    LRRC_APP_FLOW_CTRL_TYPE_L2G_REDIR_FAIL,                /* L->G�ض���ʧ�� */
    LRRC_APP_FLOW_CTRL_TYPE_L2G_START_CCO,                 /* L->G��ʼCCO */
    LRRC_APP_FLOW_CTRL_TYPE_L2G_CCO_FAIL,                  /* L->G CCOʧ�� */
    LRRC_APP_FLOW_CTRL_TYPE_L2G_START_HO,                  /* L->G��ʼ�л� */
    LRRC_APP_FLOW_CTRL_TYPE_L2G_HO_FAIL,                   /* L->G�л�ʧ�� */
    LRRC_APP_FLOW_CTRL_TYPE_L2W_START_RESEL,               /* L->W��ʼ��ѡ */
    LRRC_APP_FLOW_CTRL_TYPE_L2W_RESEL_FAIL,                /* L->W��ѡʧ�� */
    LRRC_APP_FLOW_CTRL_TYPE_L2W_START_REDIR,               /* L->W�ض��� */
    LRRC_APP_FLOW_CTRL_TYPE_L2W_REDIR_FAIL,                /* L->W�ض���ʧ�� */
    LRRC_APP_FLOW_CTRL_TYPE_L2W_START_HO,                  /* L->W��ʼ�л� */
    LRRC_APP_FLOW_CTRL_TYPE_L2W_HO_FAIL,                   /* L->W�л�ʧ�� */
    LRRC_APP_FLOW_CTRL_TYPE_G2L_IDLE_MEAS,                 /* G->L IDLE�������� */
    LRRC_APP_FLOW_CTRL_TYPE_W2L_IDLE_MEAS,                 /* W->L IDLE�������� */
    LRRC_APP_FLOW_CTRL_TYPE_G2L_CONN_MEAS,                 /* G->L CONN�������� */
    LRRC_APP_FLOW_CTRL_TYPE_W2L_CONN_MEAS,                 /* W->L CONN�������� */
    LRRC_APP_FLOW_CTRL_TYPE_W2L_RELALL,                    /* W->L RELALL */
    LRRC_APP_FLOW_CTRL_TYPE_L2W_START_CELL_SRCH,           /* L->W ���� */
    LRRC_APP_FLOW_CTRL_TYPE_L2W_STOP_CELL_SRCH,            /* L->W ֹͣ���� */
    LRRC_APP_FLOW_CTRL_TYPE_L2G_START_CELL_SRCH,           /* L->G ���� */
    LRRC_APP_FLOW_CTRL_TYPE_L2G_STOP_CELL_SRCH,            /* L->G ֹͣ���� */
    LRRC_APP_FLOW_CTRL_TYPE_T2L_RELALL,                    /* T->L RELALL */
    LRRC_APP_FLOW_CTRL_TYPE_G2L_RELALL,                    /* G->L RELALL */
    LRRC_APP_FLOW_CTRL_TYPE_L2T_START_REDIR,               /* L->T�ض��� */
    LRRC_APP_FLOW_CTRL_TYPE_L2T_START_HO,                  /* L->T��ʼ�л� */
    LRRC_APP_FLOW_CTRL_TYPE_L2T_START_RESEL,               /* L->T��ʼ��ѡ */
    LRRC_APP_FLOW_CTRL_TYPE_T2L_IDLE_MEAS,                 /* T->L IDLE�������� */
    LRRC_APP_FLOW_CTRL_TYPE_T2L_CONN_MEAS,                 /* G->L CONN�������� */

    LRRC_APP_FLOW_CTRL_TYPE_BUTT
};
typedef VOS_UINT8 LRRC_APP_FLOW_CTRL_TYPE_ENUM_UINT8;

/*****************************************************************************
 ö����    : RRC_APP_BOOL_ENUM
 Э�����  :
 ASN.1���� :
 ö��˵��  : PSͳһ��������ö�ٶ���
*****************************************************************************/
enum RRC_APP_BOOL_ENUM
{
    RRC_APP_PS_FALSE                            = 0,
    RRC_APP_PS_TRUE                             = 1,
    RRC_APP_PS_BOOL_BUTT
};
typedef VOS_UINT8   RRC_APP_BOOL_ENUM_UINT8;

/*****************************************************************************
 ö����    : RRC_UE_CATEGORY_ENUM_UINT8
 Э�����  :
 ASN.1���� :
 ö��˵��  : UE Category����μ�36306Э��
*****************************************************************************/
enum RRC_APP_CATEGORY_ENUM
{
    RRC_APP_UE_CATEGORY_1                   = 0,
    RRC_APP_UE_CATEGORY_2                   = 1,
    RRC_APP_UE_CATEGORY_3                   = 2,
    RRC_APP_UE_CATEGORY_4                   = 3,
    RRC_APP_UE_CATEGORY_5                   = 4,
    RRC_APP_UE_CATEGORY_6                   = 5,
    RRC_APP_UE_CATEGORY_7                   = 6,
    RRC_APP_UE_CATEGORY_BUTT
};
typedef VOS_UINT8 RRC_APP_CATEGORY_ENUM_UINT8;
/*****************************************************************************
 ö����    : RRC_CONN_REEST_IND_ENUM_UINT8
 Э�����  :
 ASN.1���� :
 ö��˵��  : RRC�����ؽ������ԭ��
*****************************************************************************/
enum RRC_APP_CONN_REEST_IND_ENUM
{
    RRC_APP_CONN_REEST_FOR_RBCFG_ERROR      = 1,                                    /* 0:����RB����ʧ�ܵ��µ�RRC�����ؽ� */
    RRC_APP_CONN_REEST_FOR_HANDOVER_ERROR   = 2,                                    /* 1:�����л�ʧ�ܵ��µ�RRC�����ؽ� */
    RRC_APP_CONN_REEST_FOR_OTHER_ERROR      = 3,                                    /* 2:����������·ʧ�ܻ�����������֤ʧ�ܵ��µ�RRC�����ؽ� */
    RRC_APP_CONN_REEST_FOR_BUTT
};
typedef VOS_UINT8 RRC_APP_CONN_REEST_IND_ENUM_UINT8;

/*********************************************************
 ö����    : RRC_APP_FTM_CHANGE_INFO_TYPE_ENUM
 Э�����  :
 ASN.1���� :
 ö��˵��  : ����ϱ�����ģʽ���Ͷ���
**********************************************************/
enum RRC_APP_FTM_CHANGE_INFO_TYPE_ENUM
{
    RRC_APP_FTM_CHANGE_CELL_INFO,  /* RRCפ��С����Ϣ���仯���ϱ����л�����ѡ��ɺ��ϱ� */
    RRC_APP_FTM_CHANGE_STATE_INFO, /* RRC״̬��Ϣ���仯���ϱ� */
    RRC_APP_FTM_CHANGE_BUTT
};

typedef VOS_UINT32 RRC_APP_FTM_CHANGE_INFO_TYPE_ENUM_UINT32;
/*********************************************************
 ö����    : LRRC_LPHY_LTE_BAND_WIDTH_ENUM
 Э�����  :
 ASN.1���� :
 ö��˵��  : LTE������WIDTH_3M���Ǳ�ʾ���д�����3M��������ʾ3M����
**********************************************************/
enum LRRC_APP_BAND_WIDTH_ENUM
{
    LRRC_APP_LTE_BAND_WIDTH_1D4M = 0,
    LRRC_APP_LTE_BAND_WIDTH_3M,
    LRRC_APP_LTE_BAND_WIDTH_5M,
    LRRC_APP_LTE_BAND_WIDTH_10M,
    LRRC_APP_LTE_BAND_WIDTH_15M,
    LRRC_APP_LTE_BAND_WIDTH_20M,
    LRRC_APP_LTE_BAND_WIDTH_BUTT
};
typedef VOS_UINT16 LRRC_APP_BAND_WIDTH_ENUM_UINT16;

enum LRRC_OM_QLOW_WATCH_TYPE_ENUM
{
    LRRC_OM_QLOW_WATCH_NONE = 0,
    LRRC_OM_QLOW_WATCH_L2L_REDIR,
    LRRC_OM_QLOW_WATCH_L2L_RESEL,
    LRRC_OM_QLOW_WATCH_U2L_REDIR,
    LRRC_OM_QLOW_WATCH_U2L_RESEL,
    LRRC_OM_QLOW_WATCH_G2L_REDIR,
    LRRC_OM_QLOW_WATCH_G2L_RESEL,
    LRRC_OM_QLOW_WATCH_C2L_RESEL,
    LRRC_OM_QLOW_WATCH_BUTT
};
typedef VOS_UINT8 LRRC_OM_QLOW_FLOW_TYPE_ENUM_UINT8;

/*****************************************************************************
 �ṹ��    :LRRC_ERRLOG_ESR_CS_FAIL_TYPE_ENUM32
 �ṹ˵��  :
*****************************************************************************/
enum LRRC_OM_RAT_TYPE_ENUM
{
    LRRC_OM_RAT_TYPE_GSM = 1,                         /* GSM���뼼�� */
    LRRC_OM_RAT_TYPE_UTRA,                            /* UTRA���뼼�� */
    LRRC_OM_RAT_TYPE_LTE,                             /* LTE���뼼�� */
    LRRC_OM_RAT_TYPE_HRPD,                            /* CDMA HRPD*/
    LRRC_OM_RAT_TYPE_BUTT
};
typedef VOS_UINT16  LRRC_OM_RAT_TYPE_ENUM_UINT16;

/*****************************************************************************
 �ṹ��    :LRRC_CHR_MEAS_STATE_AND_CNF_ENUM_UINT16
 �ṹ˵��  :���ڽ���LRRC_OM_NCELL_INFO�е�usMeasCnfAndState
*****************************************************************************/
enum  LRRC_CHR_MEAS_STATE_AND_CNF_ENUM
{
    LRRC_CHR_MEAS_STATE_BitOpIntraReselCfg = 0x8000,
    LRRC_CHR_MEAS_STATE_bitOpInterMeasCfg = 0x4000,
    LRRC_CHR_MEAS_STATE_bitOp2GMeasCfg = 0x2000,
    LRRC_CHR_MEAS_STATE_bitOp3GMeasCfg = 0x1000,
    LRRC_CHR_MEAS_STATE_bitOpIntraMeasState = 0x0800,
    LRRC_CHR_MEAS_STATE_bitOpInterMeasState = 0x0400,
    LRRC_CHR_MEAS_STATE_bitOp2GMeasState = 0x0200,
    LRRC_CHR_MEAS_STATE_bitOp3GMeasState = 0x0100,
    LRRC_CHR_MEAS_STATE_bitOpValidIntraCell = 0x0080,
    LRRC_CHR_MEAS_STATE_bitOpValidInterCell = 0x0040,
    LRRC_CHR_MEAS_STATE_bitOpValid2GCell = 0x0020,
    LRRC_CHR_MEAS_STATE_bitOpValid3GCell = 0x0010,
    LRRC_CHR_MEAS_STATE_BUTT = 0x0000
};
typedef VOS_UINT16  LRRC_CHR_MEAS_STATE_AND_CNF_ENUM_UINT16;

/*****************************************************************************
   5 STRUCT
*****************************************************************************/
/*****************************************************************************
                  ����ģʽ�ϱ��ṹ�嶨��
*****************************************************************************/
/*********************************************************************
* ASN �ı� :MCC
*********************************************************************/
typedef struct
{
    VOS_UINT8                           ucCnt;    /*(0, 3)*/
    VOS_UINT8                           aucItem[RRC_APP_MAX_NUM_OF_MCC];
}RRC_APP_MCC_STRU;

/*********************************************************************
* ASN �ı� :PLMN-Identity
*********************************************************************/
typedef struct
{
    RRC_APP_MCC_STRU                         Mcc;                          /* optional */
    RRC_APP_MCC_STRU                         Mnc;
}LRRC_APP_PLMN_ID_STRU;
/*****************************************************************************
 �ṹ��    :APP_RRC_Txpwr
 �ṹ˵��  :RRC�ϱ���APP�����з��书��
*****************************************************************************/
typedef struct
{
    VOS_INT16                        sPuschTxPwr;
    VOS_INT16                        sPucchTxPwr;
    VOS_INT16                        sSrsTxpwr;
    VOS_UINT16                       usReserved;
}RRC_APP_Txpwr_INFO_STRU;
/*****************************************************************************
 �ṹ��    :RRC_APP_PUSCH_BLER_STRU
 �ṹ˵��  :RRC�ϱ���APP��PUSCH�����ʽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT32             ulAckCnt;    /* �յ���ACK���� */
    VOS_UINT32             ulNackCnt;   /* �յ���NACK���� */
}RRC_APP_PUSCH_BLER_STRU;

/*****************************************************************************
 �ṹ��    :RRC_APP_PDSCH_BLER_STRU
 �ṹ˵��  :RRC�ϱ���APP��PDSCH�����ʽṹ����Ҫ��ʾ��ʼ�����ʺ��ۼ������ʣ���Ҫ��������ʾ
*****************************************************************************/
typedef struct
{
    VOS_UINT16              ausCWInitTotal[NUM_OF_CODEWORD]; /* ��ʼ�����ʣ��յ�����֡�����������������ȷ�� */
    VOS_UINT16              ausCWInitError[NUM_OF_CODEWORD]; /* ��ʼ�����ʣ��յ��Ĵ�����֡���� */
    VOS_UINT16              ausCWReTotal[NUM_OF_CODEWORD];   /* ���������ʣ��յ�����֡�����������������ȷ�� */
    VOS_UINT16              ausCWReError[NUM_OF_CODEWORD];   /* ���������ʣ��յ��Ĵ�����֡���� */
}RRC_APP_PDSCH_BLER_STRU;

/*****************************************************************************
 �ṹ��    :RRC_APP_PDCCH_BLER_STRU
 �ṹ˵��  :RRC�ϱ���APP����������Ȩ����
*****************************************************************************/
typedef struct
{
    VOS_UINT32              ulDlGrantCnt; /* ������Ȩ���� */
    VOS_UINT32              ulUlGrantCnt; /* ������Ȩ���� */
}RRC_APP_PDCCH_BLER_STRU;

/*****************************************************************************
 �ṹ��    :APP_RRC_BLER_INFO_STRU
 �ṹ˵��  :RRC�ϱ���APP�������ʽṹ
*****************************************************************************/
typedef struct
{
    RRC_APP_PUSCH_BLER_STRU         stPuschBlerCnt; /* PUSCH �����BLER */
    RRC_APP_PDSCH_BLER_STRU         stPdschBlerCnt; /* PDSCH �����BLER */
    RRC_APP_PDCCH_BLER_STRU         stPdcchBlerCnt; /* PDCCH ��������Ȩ���� */
}RRC_APP_BLER_INFO_STRU;

/*****************************************************************************
 �ṹ��    :RRC_APP_PERIOD_CELL_INFO_STRU
 �ṹ˵��  :RRC�����ϱ���APP��פ��С����Ϣ
*****************************************************************************/
typedef struct
{
    VOS_INT16                           sRsrp;              /* RSRP����ֵ��Χ��(-141,-44)����λdbm*/
    VOS_INT16                           sRsrq;              /* RSRQ����ֵ��Χ��(-40, -6) */
    VOS_INT16                           sRssi;              /* RSSI����ֵ����λdbm */
    VOS_UINT16                          usRI;               /* RIֵ */
    VOS_UINT16                          ausCQI[2];          /* CQI�������֣�ֻ��һ������ʱ�������һ��ֵ��Ч */
    VOS_INT32                           lSINR;              /* SINR��С���ο��ź������ */
    RRC_APP_Txpwr_INFO_STRU             stTxPwr;            /* LTE�����ŵ����͹��� */
    RRC_APP_BLER_INFO_STRU              stBler;             /* LTE������ */
}RRC_APP_PERIOD_CELL_INFO_STRU;
/*****************************************************************************
 �ṹ��    : RRC_APP_FREQ_PARA_STRU
�ṹ˵��  : RRC�ϱ�����Ϣ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                              usUlFreq;          /* ��������Ƶ�� ��λ:100Khz */
    VOS_UINT16                              usDlFreq;          /* ��������Ƶ�� ��λ:100Khz */
    LRRC_APP_BAND_WIDTH_ENUM_UINT16         enDlBandwidth;     /* ���д��� */
    VOS_UINT8                               usBand;            /* Ƶ��ָʾ */
    VOS_UINT8                               aucResv[1];
} RRC_APP_FREQ_PARA_STRU;

/*****************************************************************************
 �ṹ��    : RRC_APP_CHANGE_CELL_INFO_STRU
 �ṹ˵��  : �仯�ϱ��Ĺ���ģʽ�ṹ--פ��С����Ϣ
*****************************************************************************/
typedef struct
{
    VOS_UINT32                                ulValidNum;                      /* LTE֧��CA����£���Ч��Ƶ���� */
    RRC_APP_FREQ_PARA_STRU                    astFreqInfo[LRRC_APP_MAX_NUM];   /* LTE֧��CA����£�������Ƶ����Ϣ */
    VOS_UINT16                                astPhyCellId[LRRC_APP_MAX_NUM];  /* LTE֧��CA����£�����С��ID��Ϣ */
    VOS_UINT8                                 ucSbuFrmAssignmentType;          /* TDDģʽ����Ч��LTE��֡��ȣ�0xFFΪ��Чֵ */
    VOS_UINT8                                 ucSpecialSubFrmPatterns;         /* TDDģʽ����Ч��LTE������֡��ȣ�0xFFΪ��Чֵ */
    RRC_APP_PAGING_CYCLE_ENUM_UINT32          enPagingCycle;                   /* Ѱ������ */
    RRC_APP_TRANSM_MODE_ENUM_UINT32           enTranMode;                      /* LTE����ģʽ */
}RRC_APP_CHANGE_CELL_INFO_STRU;

/*****************************************************************************
 �ṹ��    : RRC_APP_FTM_CHANGE_INFO_STRU
 �ṹ˵��  : �仯�ϱ��Ĺ���ģʽ�ṹ
*****************************************************************************/
typedef struct
{
    RRC_APP_FTM_CHANGE_INFO_TYPE_ENUM_UINT32  ulFtmChangeInfoType;

    union
    {
        RRC_APP_CHANGE_CELL_INFO_STRU             stCellInfo;  /* �仯�ϱ��Ĺ���ģʽ�ṹ--פ��С����Ϣ */
        RRC_APP_PROTOCOL_STATE_IND_ENUM_UINT8     enState;     /* �仯�ϱ��Ĺ���ģʽ�ṹ--״̬��Ϣ������Э��״̬���ڲ�����״̬ */
    }u;
}RRC_APP_FTM_CHANGE_INFO_STRU;
/*****************************************************************************
 �ṹ��    : RRC_APP_FTM_PERIOD_INFO_STRU
 �ṹ˵��  : �����ϱ��Ĺ���ģʽ�ṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT32                                 ulValidNum;
    RRC_APP_PERIOD_CELL_INFO_STRU              astCellInfo[LRRC_APP_MAX_NUM]; /* RRC�����ϱ���APP��פ��С����Ϣ */
}RRC_APP_FTM_PERIOD_INFO_STRU;

/*****************************************************************************
 �ṹ��    : RRC_APP_FTM_INFO_STRU
 �ṹ˵��  : ����ģʽ�ϱ����ݽṹ
*****************************************************************************/
typedef struct
{
    RRC_APP_FTM_TYPE_ENUM_UINT32             enRrcAppFtmType; /* ����ģʽ�£��ϱ���Ϣ����--�����ϱ��ͱ���ϱ����� */

    union
    {
        RRC_APP_FTM_PERIOD_INFO_STRU         stPeriodInfo;    /* ����ģʽ�£������ϱ����ݣ� Idle״̬�ϱ�����ĿǰΪDRX���ڣ�Connected״̬������Ϊ1��*/
        RRC_APP_FTM_CHANGE_INFO_STRU         stChangeInfo;    /* ����ģʽ�£�������ϱ����� */
    }u;
}RRC_APP_FTM_INFO_STRU;

/*****************************************************************************
 �ṹ��    : RRC_APP_FTM_INFO_STRU
 �ṹ˵��  : ����ģʽ�ϱ����ݽṹ
*****************************************************************************/
typedef struct
{
    /* ��ģ��ID */
    OM_ERR_LOG_MOUDLE_ID_ENUM_UINT32    ulMsgModuleID;

    /* 00������, 01������ ,10/11:����  */
    VOS_UINT16                          usModemId;

    VOS_UINT16                          usProjectID;
    VOS_UINT32                          ulLength;

    RRC_APP_FTM_INFO_STRU               stLrrcFtmInfo;

}LRRC_OM_FTM_REPROT_CONTENT_STRU;

/*****************************************************************************
 �ṹ��    : RRC_APP_FTM_INFO_STRU
 �ṹ˵��  : ����ģʽ�ϱ����ݽṹ
*****************************************************************************/

/* ���������ģʽ�����ϱ����� ����� -> OM*/
typedef struct
{
    VOS_MSG_HEADER
    VOS_UINT32                          ulMsgName;
    VOS_UINT32                          ulMsgType;
    VOS_UINT32                          ulMsgSN;
    VOS_UINT32                          ulRptlen;      /* ����ģʽ�ϱ������ݳ���,���ulRptlenΪ0,aucContent���ݳ���ҲΪ0 */
    LRRC_OM_FTM_REPROT_CONTENT_STRU     stLrrcFtmContent;
}LRRC_OM_FTM_REPROT_IND_STRU;

/*****************************************************************************
                   ERROR LOG�ϱ��ṹ�嶨��
*****************************************************************************/
/*****************************************************************************
 ö����    : LRRC_OM_ALARMID_ENUM
 Э�����  :
 ASN.1���� :
 ö��˵��  : ErrorLog Cnf��Ϣ�ṹ���AlarmIdö��
*****************************************************************************/
enum LRRC_OM_ALARMID_ENUM
{
    LRRC_OM_ALARMID_ENUM_RECFG          = 1,                /*�����ô���*/
    LRRC_OM_ALARMID_ENUM_REEST          = 2,                /*�ؽ�������*/
    LRRC_OM_ALARMID_ENUM_EST            = 3,                /*��������*/
    LRRC_OM_ALARMID_ENUM_LOSTAREA       = 4,                /*����*/
    LRRC_OM_ALARMID_ENUM_OVERFLOW       = 5,                /*��Ϣ���������*/
    LRRC_OM_ALARMID_ENUM_QLOW_CELL      = 6,                /*פ������С���澯*/
    LRRC_OM_ALARMID_ENUM_PINGPONG_RESEL = 7,                /*ƹ����ѡ�澯*/
    LRRC_OM_ALARMID_ENUM_CSFB_FAIL      = 8,                /*CSFBʧ��*/
    LRRC_OM_ALARMID_ENUM_MOBILITY_2_QLOW_CELL = 9,          /*��ѡ���ض�����С���澯*/
    LRRC_OM_ALARMID_ENUM_OUT_OF_SYNC    = 10,               /*ʧ������*/
    LRRC_OM_ALARMID_ENUM_CSEL_INFO      = 11,               /* С��ѡ����Ϣ */
    LRRC_OM_ALARMID_ENUM_ISLAND_CELL    = 12,               /* �µ�С�� */
    LRRC_OM_ALARMID_ENUM_RA             = 13,               /* ������� */
    LRRC_OM_ALARMID_ENUM_AIRMSG_FAIL    = 14,               /* �տ���Ϣ�쳣 */
    LRRC_OM_ALARMID_ENUM_SRVCC_FAIL     = 15,               /* SRVCC ʧ�� */
    LRRC_OM_ALARMID_ENUM_SRVCC_STAT     = 16,               /* SRVCC ͳ����Ϣ */
    LRRC_OM_ALARMID_ENUM_LONGTIMEMEAS_STAT = 17,            /* ��ʱ����������ͳ����Ϣ */
    LRRC_OM_ALARMID_ENUM_SECU_FUNCTION_ERR_INFO = 18,            /*��ȫ�������д���*/
    LRRC_OM_ALARMID_ENUM_MOD3_NCELL     = 19,               /* ģ�����ͬƵǿ�������� */
    LRRC_OM_ALARMID_ENUM_RFFAIL_REEST   = 20,               /* UE�����˲������棬���ǲ�δ�����л�������ؽ��� */

    LRRC_OM_ALARMID_ENUM_RESEL_TO_LTE_FAIL = 21,            /*����ģ��ѡ��Lģʧ��*/

    /* BAND-38 Scell Not config MFBI record begin */
    LRRC_OM_ALARMID_ENUM_NCONFIG_MFBI_STAT = 22,            /* Band38 Scellδ����MFBI��Ϣͳ�� */
    /* BAND-38 Scell Not config MFBI record end */

    LRRC_OM_ALARMID_ENUM_BUTT
};
typedef VOS_UINT16 LRRC_OM_ALARMID_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_OM_ALARMID_ENUM
 Э�����  :
 ASN.1���� :
 ö��˵��  : ErrorLog Cnf��Ϣ�ṹ���AlarmIdö��
*****************************************************************************/
enum LRRC_OM_SRCHED_FREQ_SCENARIO_ENUM
{
    LRRC_OM_RREQ_SCENARIO_ENUM_FIRST_MCC = 1,
    LRRC_OM_RREQ_SCENARIO_ENUM_CSEL_SUCC,
    LRRC_OM_RREQ_SCENARIO_ENUM_BUTT
};
typedef VOS_UINT16 LRRC_OM_SRCHED_FREQ_SCENARIO_ENUM_UINT16;

/*****************************************************************************
 �ṹ��    : LRRC_OM_ACC_INFO_STRU
 Э�����  :
 ASN.1���� :
 �ṹ˵��  : RRC������Ϣ�洢
*****************************************************************************/
typedef struct
{
    VOS_UINT8                              ucAsRelBitmap;      /* ��������UE�����汾��1��֧�֣�0����֧�֣��ӵ͵���λ�ֱ�����ָʾRel8,Rel9,.... */
    VOS_UINT8                              aucReserved[3];
    VOS_UINT32                             ulFeatureGroupInds; /* ��μ�36.331 B.1  Feature group indicators �½ڣ���λȡֵ */
}LRRC_OM_ACC_INFO_STRU;

/*****************************************************************************
 �ṹ��    : RRC_RRC_EST_INFO_STRU
 Э�����  :
 ASN.1���� :
 �ṹ˵��  : RRC������Ϣ�洢
*****************************************************************************/
typedef struct
{
    LRRC_APP_LNAS_EST_CAUSE_ENUM_UINT8     enEstCause;             /* ����ԭ�� */
    LRRC_APP_LNAS_EST_RESULT_ENUM_UINT8    enResult;               /* ������� */
    VOS_UINT8                              ucNumOfPrembSentR11;
    VOS_UINT8                              ucContentionDetctR11;
    VOS_UINT8                              ucMaxTxPwrReachedR11;
    VOS_UINT8                              aucRsv[3];
}LRRC_OM_RRC_EST_LIST_INFO_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_OM_STATE_INFO_STRU
 �ṹ˵��  : ERROR LOG RRC״̬��Ϣ
*****************************************************************************/
typedef struct
{
    RRC_APP_PROTOCOL_STATE_IND_ENUM_UINT8       enState;            /* RRCЭ��״̬ */
    VOS_UINT8                                   ucErrcTopMsState;   /* RRC��״̬�����ڲ������״̬�� */
    VOS_UINT8                                   ucErrcTopSsState;   /* RRC��״̬�����ڲ������״̬�� */
    LRRC_APP_FLOW_CTRL_TYPE_ENUM_UINT8          enErrcFlowCtrlType; /* LTE������ϵͳ����ʱ����ϵͳ���̱�ʶ */
}LRRC_OM_STATE_INFO_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_OM_SYNC_INFO_STRU
 �ṹ˵��  : ERR LOG ͬ����Ϣ
*****************************************************************************/
typedef struct
{
    VOS_UINT32          ulInSyncCnt;   /* LRRC�յ�LPHY��������ͬ������ */
    VOS_UINT32          ulOutSyncCnt;  /* LRRC�յ�LPHY��������ʧ������ */
}LRRC_OM_SYNC_INFO_STRU;

/*****************************************************************************
 ö����    : LRRC_APP_ERR_LOG_RAT_TYPE_ENUM
 Э�����  :
 ASN.1���� :
 ö��˵��  : ���뼼��ö��ֵ�����ݼ������GUTL���Զ��嵫���ָ���ʽ˳��һ��
*****************************************************************************/
enum LRRC_APP_ERR_LOG_RAT_TYPE_ENUM
{
    LRRC_APP_ERR_LOG_RAT_TYPE_GSM      = 1,      /* GSM ���뼼��*/
    LRRC_APP_ERR_LOG_RAT_TYPE_WCDMA,             /* WCDMA ���뼼��*/
    LRRC_APP_ERR_LOG_RAT_TYPE_LTE,               /* LTE ���뼼��*/
    LRRC_APP_ERR_LOG_RAT_TYPE_TDS,               /* TDS ���뼼��*/
    LRRC_APP_ERR_LOG_RAT_TYPE_BUTT
};
typedef VOS_UINT8  LRRC_APP_ERR_LOG_RAT_TYPE_ENUM_UINT8;

/*****************************************************************************
 ö����    : LRRC_APP_ERR_LOG_AREA_LOST_CAUSE_ENUM
 Э�����  :
 ASN.1���� :
 ö��˵��  : �����ϱ�ԭ��ֵ
*****************************************************************************/
enum LRRC_APP_ERR_LOG_AREA_LOST_CAUSE_ENUM
{
    LRRC_APP_ERR_LOG_AREA_LOST_BUTT = 1         /* ��ǰԤ����ö��ֵ*/
};
typedef VOS_UINT8  LRRC_APP_ERR_LOG_AREA_LOST_CAUSE_ENUM_UINT8;

/*****************************************************************************
 �ṹ��    : LRRC_LMAC_RA_TYPE_ENUM
 Э�����  :
 ASN.1���� :
 �ṹ˵��  : RRC����MAC�������������
*****************************************************************************/
enum LRRC_OM_RA_TYPE_ENUM
{
    LRRC_OM_RA_TYPE_CONTENTION              = 0,                                    /* ���ھ����� */
    LRRC_OM_RA_TYPE_NON_CONTENTION          = 1,                                    /* �Ǿ����� */
    LRRC_OM_RA_TYPE_BUTT
};
typedef VOS_UINT8 LRRC_OM_RA_TYPE_ENUM_UINT8;

/*****************************************************************************
 �ṹ��    : LRRC_LMAC_RA_CAUSE_ENUM
 Э�����  :
 ASN.1���� :
 �ṹ˵��  : RRC����MAC��������ԭ��
*****************************************************************************/
enum LRRC_OM_RA_CAUSE_ENUM
{
    LRRC_OM_RA_CAUSE_CONN                   = 0,                                    /* ���ӽ����� */
    LRRC_OM_RA_CAUSE_HO                     = 1,                                    /* �л��� */
    LRRC_OM_RA_CAUSE_REEST                  = 2,                                    /* RRC�����ؽ����� */
    LRRC_OM_RA_CAUSE_WAITTA_TIMEOUT         = 3,                                    /* �ȴ�TA��ʱ */
    LRRC_OM_RA_CAUSE_SENDSR                 = 4,                                    /* ����������뷢��SR��Ϣ */
    LRRC_OM_RA_CAUSE_BUTT
};
typedef VOS_UINT8 LRRC_OM_RA_CAUSE_ENUM_UINT8;

/*****************************************************************************
 �ṹ��    : LRRC_OM_ERR_CAUSE_ENUM
 Э�����  :
 ASN.1���� :
 �ṹ˵��  : �������ʧ�ܵ�ԭ��ֵ
*****************************************************************************/
enum LRRC_OM_ERR_CAUSE_ENUM
{
    LRRC_OM_ERR_FATAL                        = 0,                                   /*MAC�����������ɻָ��Դ���*/
    LRRC_OM_RA_ERR_MAX_TX_NUM                = 1,                                   /*�����������Preamble�ﵽ������*/
    LRRC_OM_RA_ERR_MAX_HARQ_NUM              = 2,                                   /*���������̷�����Ϣ3�ﵽ������*/
    LRRC_OM_ERR_NO_RF_RA                     = 3,                                   /*�������ʱû��RF*/
    LRRC_OM_ERR_NO_RF_TIMEROUT               = 4,                                   /*RF������ʱ����ʱ*/
    LRRC_OM_ERR_RF_RESUME_SYNC               = 5,                                   /*RF�ָ����ֹ�����಻ͬ��*/
    LRRC_OM_ERR_BUTT
};
typedef VOS_UINT8 LRRC_OM_ERR_CAUSE_ENUM_UINT8;

/*****************************************************************************
 �ṹ��    : LRRC_OM_SRVCC_RST_ENUM
 Э�����  :
 ASN.1���� :
 �ṹ˵��  : SRVCC���
*****************************************************************************/
enum LRRC_OM_SRVCC_RST_ENUM
{
    LRRC_OM_SRVCC_NO_B1B2                    = 0,                                   /* SRVCC û���յ�B1B2���� */
    LRRC_OM_SRVCC_NO_RPT                     = 1,                                   /* SRVCC û�з���B1B2���� */
    LRRC_OM_SRVCC_NO_HO                      = 2,                                   /* SRVCC ����δ�����л� */
    LRRC_OM_SRVCC_HO_FAIL                    = 3,                                   /* SRVCC �л�ʧ�� */
    LRRC_OM_SRVCC_CONN_REL                   = 4,                                   /* Volte �����У��յ�������쳣�����ͷ� */
    LRRC_OM_SRVCC_REEST                      = 5,                                   /* Volte �����У����ڰ�ȫ������ʧ�ܵ�����ԭ�������ؽ��� */
    LRRC_OM_SRVCC_SUCC                       = 6,                                   /* SRVCC �ɹ� */
    LRRC_OM_SRVCC_FAIL_BUTT
};
typedef VOS_UINT8 LRRC_OM_SRVCC_RST_UINT8;

/*****************************************************************************
 �ṹ��    : LRRC_OM_MEAS_RPT_TYPE_ENUM
 Э�����  :
 ASN.1���� :
 �ṹ˵��  : �������������
*****************************************************************************/
enum LRRC_OM_MEAS_RPT_TYPE_ENUM
{
    LRRC_OM_MEAS_RPT_TYPE_EVENT_BEGIN = 0,
    LRRC_OM_MEAS_RPT_TYPE_EVENT_A1,
    LRRC_OM_MEAS_RPT_TYPE_EVENT_A2,
    LRRC_OM_MEAS_RPT_TYPE_EVENT_A3,
    LRRC_OM_MEAS_RPT_TYPE_EVENT_A4,
    LRRC_OM_MEAS_RPT_TYPE_EVENT_A5,
    LRRC_OM_MEAS_RPT_TYPE_EVENT_A6,
    LRRC_OM_MEAS_RPT_TYPE_EVENT_B1,
    LRRC_OM_MEAS_RPT_TYPE_EVENT_B2,

    LRRC_OM_MEAS_RPT_TYPE_PERIOD_BEGIN = 20,
    LRRC_OM_MEAS_RPT_TYPE_REPORT_STRONGESTCELLS,
    LRRC_OM_MEAS_RPT_TYPE_REPORT_STRONGESTCELLS_FOR_SON,
    LRRC_OM_MEAS_RPT_TYPE_REPORT_CGI,

    LRRC_OM_MEAS_RPT_TYPE_BUTT
};
typedef VOS_UINT8 LRRC_OM_MEAS_RPT_TYPE_ENUM_UINT8;

/*****************************************************************************
 �ṹ��    : LL2_OM_VOLTE_AUTOAN_EVENT_ENUM_UINT8
 Э�����  :
 ASN.1���� :
 �ṹ˵��  : L2����ϵ�Volte�쳣�¼�
*****************************************************************************/
enum LL2_OM_VOLTE_AUTOAN_EVENT_ENUM
{
    LL2_OM_VOLTE_RTP_NO_ABORMAL = 0,                 /* δ���쳣��L2 RTP SN�����޶��� */
    LL2_OM_VOLTE_RTP_LOSTORJITTERLOW,            /* �������������޴󶶶������������� */
    LL2_OM_VOLTE_RTP_LOST_PDCP_NOLOST,               /* RTP SN��������PDCP���� */
    LL2_OM_VOLTE_ROHC_FAIL_WITH_BLER,                /* ��������ROHCʧ�� */
    LL2_OM_VOLTE_ROHC_FAIL_NO_BLER,                  /* ���������������ROHCʧ�� */
    LL2_OM_VOLTE_RTP_LOST_WITH_BLER,                 /* �������������RTP���� */
    LL2_OM_VOLTE_PDCP_LOST_RLC_NOLOST,               /* PDCP������,RLC���� */
    LL2_OM_VOLTE_RTP_BIG_JITTER,                     /* RTP ���� >=300 ms*/
    LL2_OM_VOLTE_NO_PACKET_HIGH_QULITY,              /* ���������ް��������������а��������ź��������� */
    LL2_OM_VOLTE_NO_PACKET_LOW_QULITY,               /* ���������ް���������������벻�ߣ����ź������ܲ�,����DCI��û�⵽ */
    LL2_OM_VOLTE_LESS_PACKET_HIGH_QULITY,            /* �޶�������ٶ����������٣��ź��������ó��� */
    LL2_OM_VOLTE_INTERNAL_ERROR                      /* �ڲ��쳣�������ѯʱ���L2û������ */
};
typedef VOS_UINT8  LL2_OM_VOLTE_AUTOAN_EVENT_ENUM_UINT8;

/*****************************************************************************
 �ṹ��    : LPS_LOW_QUILITY_ABNORMAL_STRU
 Э�����  :
 ASN.1���� :
 �ṹ˵��  : �������ź�ʱ����ȡ���쳣��
*****************************************************************************/
typedef struct
{
    VOS_UINT8                      enMod3EqualCell;               /* ����������ȵ�ģ�������쳣�㣬�����쳣 */
    VOS_UINT8                      enNoIntraFreqHo;               /* A3�ϱ��ɹ�����û��ͬƵ�л��·� */
    VOS_UINT8                      enNoInterFreqHo;               /* A4A5�ϱ��ɹ�����û����ƵƵ�л��·� */
    VOS_UINT8                      enNoInterRATHo;                /* B2�ϱ��ɹ�����û����ϵͳ�л��·� */
    VOS_UINT8                      enNoNcellMeasRpt;              /* û�������ϱ���������û�⵽���������� */
    VOS_UINT8                      enNoNcellMeasCfg;              /* û�г�A1A2���������쳣���Ƿ����*/
    VOS_UINT8                      enMeasRptTryFail;              /* ���Է���A3֮��Ĳ������浫û�гɹ� */
    VOS_UINT8                      enUnknowInt;                   /* �ź������ߣ�û��ͬƵ���ţ���RSRQ�쳣ƫ�� */
    VOS_UINT8                      enRsv0;                        /* Ԥ�� */
    VOS_UINT8                      enRsv1;                        /* Ԥ�� */
    VOS_UINT8                      enRsv2;                        /* Ԥ�� */
    VOS_UINT8                      enRsv3;                        /* Ԥ�� */
}LPS_LOW_QUILITY_ABNORMAL_STRU;



/*****************************************************************************
 ö����    : LRRC_LPDCP_VOLTE_FAULT_TRIG_ENUM
 Э�����  :
 ASN.1���� :
 ö��˵��  : PDCP�ϱ���VOLTE_FAULT_IND�Ĵ���ԭ��:
             0:��ѯ����;
             1:��������
*****************************************************************************/
enum LRRC_LPDCP_VOLTE_FAULT_TRIG_ENUM
{
    LRRC_LPDCP_VOLTE_FAULT_TRIG_BY_QUERY      = 0,                               /* ��ѯ���� */
    LRRC_LPDCP_VOLTE_FAULT_TRIG_AUTO,                                            /* �������� */
    LRRC_LPDCP_VOLTE_FAULT_TRIG_BUTT
};
typedef VOS_UINT8 LRRC_LPDCP_VOLTE_FAULT_TRIG_ENUM_UINT8;

/*****************************************************************************
 ö����    : SECU_FUNC_TYPE_ENUM
 Э�����  :
 ASN.1���� :
 ö��˵��  : ��ȫ��������
*****************************************************************************/
enum SECU_FUNC_TYPE_ENUM
{
    MEM_CPY_TYPE  = 0,
    MEM_SET_TYPE     ,
    MEM_MOVE_TYPE    ,
    MEM_SECU_BUTT
};
typedef VOS_UINT8   SECU_FUNC_TYPE_ENUM_UINT8;

/*****************************************************************************
 �ṹ��    : LRRC_OM_OVERFLOW_INFO_STRU
 �ṹ˵��  : ERR LOG ����������ṹ
*****************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU                  stHead;
    VOS_UINT32                              ulCount;    /*�������������*/
}LRRC_OM_OVERFLOW_INFO_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_OM_CAMP_THRESHOLD_STRU
 �ṹ˵��  : С����ѡ�ĵ���ֵ��Ϣ���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_INT16 sQRxLevMin;                      /* ʵ��ֵ���������*2 */
    VOS_INT16 sQRxLevMinOffset;                /* ʵ��ֵ���������*2,Ĭ��0 */
    VOS_INT16 sQqualMin;                       /* ʵ��ֵ��Ĭ����С RRC_INT16_NEGATIVE_INFINITY*/
    VOS_INT16 sQqualMinOffset;                 /* ʵ��ֵ��Ĭ��0 */
}LRRC_OM_CAMP_THRESHOLD_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_OM_TAC_STRU
 �ṹ˵��  : TAC ��Ϣ
*****************************************************************************/
typedef struct
{
    VOS_UINT8                           ucTac;
    VOS_UINT8                           ucTacCont;
    VOS_UINT8                           aucReserved[2];
}LRRC_OM_TAC_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_OM_CELL_MEAS_INFO
 �ṹ˵��  : LTE����С���������
*****************************************************************************/
typedef struct
{
    VOS_INT16                                           sRsrp;                          /* RSRPֵ,ʵ��ֵ */
    VOS_INT16                                           sRsrq;                          /* RSRqֵ��ʵ��ֵ */
    VOS_INT16                                           sRssi;                          /* RSSIֵ��ʵ��ֵ */
    VOS_INT16                                           sSValue;                        /* S Criteria Value */
    VOS_INT16                                           sRValue;                        /* R Criteria Value */
    VOS_INT16                                           sSqual;                         /* S Criteria RSRQ Value */
}LRRC_OM_CELL_MEAS_INFO;

/*****************************************************************************
 �ṹ��    : LRRC_OM_SCELL_ID
 �ṹ˵��  : LTE����С��ʶ����Ϣ������Plmn\Gci\Tac\PhyCellId\Arfcn\Band��
*****************************************************************************/
typedef struct
{
    VOS_UINT32                                          ulGci;                          /* sib1�е�GlobalCellId */
    VOS_UINT32                                          ulMcc;                          /* Mcc */
    VOS_UINT32                                          ulMnc;                          /* Mnc */
    LRRC_OM_TAC_STRU                                    stTac;                          /* tac */
    VOS_UINT16                                          usPhyCellId;                    /* ����С��id */
    VOS_UINT16                                          usUlEarfcn;                     /*����Ƶ�ʣ���λ100khz*/
    VOS_UINT16                                          usDlEarfcn;                     /*����Ƶ�ʣ���λ100khz*/
    VOS_UINT8                                           ucServerCellBandInd;            /* ����band*/
    VOS_UINT8                                           ucRsv;
}LRRC_OM_SCELL_ID;

/*****************************************************************************
 �ṹ��    : LRRC_OM_SCELL_ID
 �ṹ˵��  : LTE����С��ʶ����Ϣ������Plmn\Gci\Tac\PhyCellId\Arfcn\Band��
*****************************************************************************/
typedef struct
{
    VOS_UINT8    aucPrint[LRRC_OM_SINGE_PRINT_LEN];
}LRRC_OM_SINGLE_PRINT_INFO;


/*****************************************************************************
 �ṹ��    : LRRC_OM_SCELL_ID
 �ṹ˵��  : LTE����С��ʶ����Ϣ������Plmn\Gci\Tac\PhyCellId\Arfcn\Band��
*****************************************************************************/
typedef struct
{
    LRRC_OM_SINGLE_PRINT_INFO  astLastPrint[LRRC_OM_PRINT_INFO_NUM];
}LRRC_OM_LATEST_PRINT_INFO;


/*****************************************************************************
 �ṹ��    : LRRC_CHR_SCELL_INFO
 �ṹ˵��  : ����С����Ƶ�㣬������Ƶ�������ޣ�PLMNID�� ���ݽṹ
*****************************************************************************/
typedef struct
{
    LRRC_OM_SCELL_ID                                   stSCellIdInfo;                  /*����С��Id��Ϣ*/
    LRRC_OM_CELL_MEAS_INFO                             stSCellMeasRst;                 /*С���������*/
    LRRC_OM_CAMP_THRESHOLD_STRU                        stCampThreshold;                /*פ������*/
}LRRC_OM_SCELL_INFO;

/*****************************************************************************
 �ṹ��    : LRRC_OM_AREA_LOST_INFO_STRU
 �ṹ˵��  : �����ϱ�ERROR LOG����С����Ƶ�㣬������Ƶ�������ޣ�PLMNID�� ���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT32                                          ulTimeStamp;                    /* ����������ʱ�� */
    VOS_UINT32                                          ulGci;                          /* sib1�е�GlobalCellId */
    VOS_UINT32                                          ulMcc;                          /* MCC,3 bytes      */
    VOS_UINT32                                          ulMnc;                          /* MNC,2 or 3 bytes */
    LRRC_OM_TAC_STRU                                    stTac;                          /* tac */
    VOS_UINT16                                          usPhyCellId;                    /* ����С��id */
    VOS_UINT16                                          usUlEarfcn;                     /*����Ƶ�ʣ���λ100khz*/
    VOS_UINT16                                          usDlEarfcn;                     /*����Ƶ�ʣ���λ100khz*/
    VOS_INT16                                           sRsrp;                          /* RSRPֵ,ʵ��ֵ */
    VOS_INT16                                           sRsrq;                          /* RSRqֵ��ʵ��ֵ */
    VOS_INT16                                           sRssi;                          /* RSSIֵ��ʵ��ֵ */
    LRRC_OM_CAMP_THRESHOLD_STRU                         stCampThreshold;                /* פ������*/
    VOS_UINT8                                           ucServerCellBandInd;            /* ����band*/
    LRRC_APP_ERR_LOG_AREA_LOST_CAUSE_ENUM_UINT8         enSubCase;                      /* ����ԭ��:�ݱ���������չ */
    VOS_UINT8                                           aucResv[2];
}LRRC_OM_AREA_LOST_INFO_STRU;

/*****************************************************************************
 �ṹ��    : Lte������Ϣ
 �ṹ˵��  : lte������Ϣ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                          usCellCount;
    VOS_UINT8                           aucRsv[2];
    VOS_UINT16                          ausCellIds[LRRC_OM_MAX_SINGLE_FREQ_CELL_COUNT];
}LRRC_OM_FREQ_CELL_LIST_STRU;

/*****************************************************************************
 �ṹ��    : Lte��Ƶ��Ϣ
 �ṹ˵��  : lte��Ƶ��Ϣ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                          usFreqBandInd;
    VOS_UINT16                          usFreqInfo;
    VOS_UINT32                          ulDlArfcn;
    LRRC_OM_FREQ_CELL_LIST_STRU         stNCellList;
}LRRC_OM_LTE_FREQ_PARAM_STRU;

/*****************************************************************************
 �ṹ��    : Lte��ƵList
 �ṹ˵��  : lte��ƵList
*****************************************************************************/
typedef struct
{
    VOS_UINT16                          usInterFreqCount;
    VOS_UINT8                           aucRsv[2];
    LRRC_OM_LTE_FREQ_PARAM_STRU         astLteNFreqParams[LRRC_OM_MAX_LTE_INTER_FREQ_COUNT];
}LRRC_OM_LTE_NCELL_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_OM_COVER_LOST_NCELL_STRU
 �ṹ˵��  : ��������������Ϣ
*****************************************************************************/
typedef struct
{
    LRRC_OM_LTE_NCELL_STRU               stLteNcellInfo;
}LRRC_OM_COVER_LOST_NCELL_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_OM_LOST_COVERAGE_STRU
 �ṹ˵��  : ����������Ϣ
*****************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU                  stHead;
    RRC_APP_ERROR_CODE_ENUM_UINT16          enErrorCode;            /* �������ϱ��ṹ��ÿ��ģ�鵥����� */
    VOS_UINT16                              usRsv;
    LRRC_OM_SCELL_ID                        stCoverLostSCellId;     /* ����������С��ID */
    LRRC_OM_COVER_LOST_NCELL_STRU           stCoverLostNCellInfo;   /* ��������ʱ������Ϣ */
    LRRC_OM_SCELL_ID                        stCurrSCellId;          /* ��������פ������С��ID */
    LRRC_OM_COVER_LOST_NCELL_STRU           stCurrNCellInfo;        /* ��������פ����������Ϣ */
}LRRC_OM_LOST_COVERAGE_STRU;

/*****************************************************************************
 �ṹ��    : RRC_OM_AREA_LOST_STRU
 �ṹ˵��  : ������Ϣ
*****************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU                  stHead;
    RRC_APP_ERROR_CODE_ENUM_UINT16          enErrorCode;            /* �������ϱ��ṹ��ÿ��ģ�鵥����� */
    LRRC_APP_ERR_LOG_RAT_TYPE_ENUM_UINT8    enRatType;              /* ��������ʱ�Ľ��뼼�� */
    VOS_UINT8                               ucRsv;
    LRRC_OM_AREA_LOST_INFO_STRU             stAreaLostInfo;        /* ������Ϣ */
}RRC_OM_AREA_LOST_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_OM_EST_INFO_STRU
 �ṹ˵��  : ERR LOG ���ӽ������ݽṹ
*****************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU                  stHead;
    RRC_APP_ERROR_CODE_ENUM_UINT16          enErrorCode;            /* �������ϱ��ṹ��ÿ��ģ�鵥����� */
    VOS_UINT16                              usRsv;
    LRRC_OM_SCELL_ID                        stPCellInfo;
    LRRC_OM_CELL_MEAS_INFO                  stPCellMeasInfo;
    LRRC_OM_RRC_EST_LIST_INFO_STRU          stEstInfoList;          /* ������� */
    LRRC_OM_ACC_INFO_STRU                   stAccInfo;              /* RRC����ʱ��UE��������ṹ */
    LRRC_OM_STATE_INFO_STRU                 stRrcAppStateInfo;      /* ��������ʱ��RRC״̬��Ϣ������Э��״̬�����ڲ�����״̬�� */
}LRRC_OM_EST_INFO_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_OM_REEST_INFO_STRU
 �ṹ˵��  : ERR LOG �ؽ������ݽṹ
*****************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU              stHead;
    RRC_APP_ERROR_CODE_ENUM_UINT16      enErrorCode;            /* �������ϱ��ṹ��ÿ��ģ�鵥����� */
    RRC_APP_CONN_REEST_IND_ENUM_UINT8   enReestConnCause;       /* ���һ���ؽ�ԭ�� */
    VOS_UINT8                           ucNumOfPrembSentR11;
    VOS_UINT8                           ucContentionDetctR11;
    VOS_UINT8                           ucMaxTxPwrReachedR11;
    VOS_UINT16                          usRsv;
    LRRC_OM_SCELL_ID                    stPCellInfo;
    LRRC_OM_CELL_MEAS_INFO              stPCellMeasInfo;
    LRRC_OM_SYNC_INFO_STRU              stSyncInfo;             /* ������ͬ����Ϣ */
    LRRC_OM_STATE_INFO_STRU             stRrcAppStateInfo;      /* ��������ʱ��RRC״̬��Ϣ������Э��״̬�����ڲ�����״̬�� */
}LRRC_OM_REEST_INFO_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_OM_RECFG_INFO_STRU
 �ṹ˵��  : ERR LOG ���������ݽṹ
*****************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU              stHead;
    RRC_APP_ERROR_CODE_ENUM_UINT16      enErrorCode;            /* �������ϱ��ṹ��ÿ��ģ�鵥����� */
    VOS_UINT8                           ucNumOfPrembSentR11;
    VOS_UINT8                           ucContentionDetctR11;
    VOS_UINT8                           ucMaxTxPwrReachedR11;
    VOS_UINT8                           ucRsv[3];
    LRRC_OM_SCELL_ID                    stPCellInfo;
    LRRC_OM_CELL_MEAS_INFO              stPCellMeasInfo;
    LRRC_OM_STATE_INFO_STRU             stRrcAppStateInfo;      /* ��������ʱ��RRC״̬��Ϣ������Э��״̬�����ڲ�����״̬�� */
}LRRC_OM_RECFG_INFO_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_OM_SRCHED_FREQ_INFO_STRU
 �ṹ˵��  : ERR LOG �ϱ�����Ƶ����Ϣ
*****************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU                      stHead;
    RRC_APP_ERROR_CODE_ENUM_UINT16              enErrorCode;            /* �������ϱ��ṹ��ÿ��ģ�鵥����� */
    VOS_UINT16                                  usBandInd;
    VOS_UINT16                                  usAllBandSrchIdx;
    PS_BOOL_ENUM_UINT8                          enIsHistoryFreqFlg;
    VOS_UINT8                                   ucRsv;
    VOS_UINT32                                  ulDlArfcn;
    VOS_UINT32                                  ulGci;
    VOS_UINT32                                  ulMcc;                  /* Mcc */
    VOS_UINT32                                  ulMnc;                  /* Mnc */
}LRRC_OM_SRCHED_FREQ_INFO_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_OM_RA_ERROR_INFO_STRU
 �ṹ˵��  : ERR LOG �ϱ��������ʧ��ԭ��ֵ
*****************************************************************************/
typedef struct
{
    LRRC_OM_ERR_CAUSE_ENUM_UINT8    enRaErrCause;
    VOS_UINT8                       ucPblSentNum;                               /*Preamble���ʹ���*/
    PS_BOOL_ENUM_UINT8              enMaxTxPowerReached;                        /*����ָʾPreamble�Ƿ�ﵽ����͹���,1:�ﵽ��0:û�ﵽ*/
    PS_BOOL_ENUM_UINT8              enContentionDetected;                       /*�Ƿ��о�����0:�Ǿ���������룬1:�����������*/
}LRRC_OM_RA_ERROR_INFO_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_OM_RA_INFO_STRU
 �ṹ˵��  : ERR LOG �ϱ�������������Ϣ
*****************************************************************************/
typedef struct
{
    LRRC_OM_RA_TYPE_ENUM_UINT8      enRaType;                                   /* ������뷽ʽ */
    LRRC_OM_RA_CAUSE_ENUM_UINT8     enRaCause;                                  /* �������ԭ�� */
    VOS_UINT8                       ucDediPreambleId;
    VOS_UINT8                       ucPrachMaskIndex;
    VOS_INT16                       sPathLoss ;                                 /* ȡֵ���������ʱ��������ѡ��Group A��B��ʵ��·�𣬸�ֵ��Ҫȷ�ϻ�ȡ��ʽ */
    VOS_UINT16                      usMsg3Size;                                 /* ����ѡ��Group A��B����Ϣ3��Сֵ ����ֵʹ�õĵ�λȷ��:byte */
    LRRC_OM_RA_ERROR_INFO_STRU      stRaErrInfo;
}LRRC_OM_RA_INFO_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_OM_RA_ERR_INFO_STRU
 �ṹ˵��  : ERR LOG �ϱ��������ʧ����Ϣ
*****************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU                      stHead;
    RRC_APP_ERROR_CODE_ENUM_UINT16              enErrorCode;            /* �������ϱ��ṹ��ÿ��ģ�鵥����� */
    VOS_UINT16                                  usRsv;
    LRRC_OM_SCELL_ID                            stSCellIdInfo;          /* ����С��Id��Ϣ */
    LRRC_OM_CELL_MEAS_INFO                      stSCellMeasRst;         /* С��������� */
    LRRC_OM_CAMP_THRESHOLD_STRU                 stCampThreshold;        /* פ������ */
    LRRC_OM_RA_INFO_STRU                        stRaInfo;               /* ������������Ϣ */
}LRRC_OM_RA_ERR_INFO_STRU;

/*****************************************************************************
 �ṹ��    : OM_ERR_LOG_REPORT_CNF_STRU
 �ṹ˵��  : Balongƽ̨�ڲ�������ERROR LOG ���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    VOS_UINT32                          ulMsgName;
    VOS_UINT32                          ulMsgType;
    VOS_UINT32                          ulMsgSN;
    VOS_UINT32                          ulRptlen;      /* �������ݳ���,���ulRptlenΪ0,aucContent���ݳ���ҲΪ0 */
    VOS_UINT8                           aucContent[4]; /* �������� */
} LRRC_OM_ERR_LOG_REPORT_CNF_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_OM_FAULT_ERR_LOG_IND_STRU
 �ṹ˵��  : Balongƽ̨�ڲ������������ϱ�Fault���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    VOS_UINT32                          ulMsgName;
    VOS_UINT32                          ulMsgType;
    VOS_UINT32                          ulMsgSN;
    VOS_UINT32                          ulRptlen;      /* �������ݳ���,���ulRptlenΪ0,aucContent���ݳ���ҲΪ0 */
    VOS_UINT8                           aucContent[4]; /* �������� */
}LRRC_OM_FAULT_ERR_LOG_IND_STRU;

typedef LRRC_OM_FAULT_ERR_LOG_IND_STRU LRRC_OM_ALARM_ERR_LOG_IND_STRU;

/*****************************************************************************
�ṹ��    : LRRC_CHR_NCELL_INFO
Э�����  :
ASN.1���� :
�ṹ˵��  : ������ѡ�����Ϣ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                          usMeasCnfAndState;
    VOS_UINT16                          usMeasLevel;
}LRRC_OM_NCELL_INFO;

/*****************************************************************************
�ṹ��    : LRRC_ERRLOG_Q_LOW_CELL_INFO
Э�����  :
ASN.1���� :
�ṹ˵��  : CHR ��С����¼ rsrq < -15db
*****************************************************************************/
typedef struct
{
    LRRC_OM_SCELL_INFO                 stSCellInfo;                    /* ����С����Ϣ */
    LRRC_OM_NCELL_INFO                 stNcellInfo;                    /* ����������Ϣ*/
    VOS_UINT32                         ulCampTimes;                    /* פ����¼����������*10sΪ��С����פ��ʱ�� */
}LRRC_OM_Q_LOW_CELL_INFO;

/*****************************************************************************
�ṹ��    : LRRC_OM_QLOW_CELL_INFO_STRU
Э�����  :
ASN.1���� :
�ṹ˵��  : ��С����Ϣ
*****************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU              stHead;
    RRC_APP_ERROR_CODE_ENUM_UINT16      enErrorCode;            /* �������ϱ��ṹ��ÿ��ģ�鵥����� */
    VOS_UINT16                          usQlowCellInfoNum;
    LRRC_OM_Q_LOW_CELL_INFO             astQLowCellInfoList[LRRC_OM_Q_LOW_CELL_NUM_MAX];
}LRRC_OM_QLOW_CELL_INFO_STRU;

/*****************************************************************************
�ṹ��    : LRRC_OM_UTRA_CELL_INFO
�ṹ˵��  : ƹ����ѡutranС����ѡ��Ϣ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                          usArfcn;
    VOS_UINT16                          usPrimaryCode;                      /* С����Ϣ */
}LRRC_OM_UTRA_CELL_INFO;

/*****************************************************************************
�ṹ��    : LRRC_OM_GSM_CELL_INFO
�ṹ˵��  : ƹ����ѡgsmС����ѡ��Ϣ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                          usArfcn;
    VOS_UINT16                          enBandInd;
    VOS_UINT16                          usNcc;
    VOS_UINT16                          usBcc;
    VOS_UINT16                          usRsv;
    VOS_INT16                           sGeranCellRxlev;
}LRRC_OM_GSM_CELL_INFO;

/*****************************************************************************
�ṹ��    : LRRC_OM_CDMA_CELL_INFO
�ṹ˵��  : ƹ����ѡcdmaС����ѡ��Ϣ
*****************************************************************************/
typedef struct
{
    VOS_UINT8                           ucBand;
    VOS_UINT8                           aucRsv[3];
    VOS_UINT16                          usArfcn;
    VOS_UINT16                          usPn;                               /* С����Ϣ */
}LRRC_OM_CDMA_CELL_INFO;

/*****************************************************************************
�ṹ��    : LRRC_OM_PINGPONG_LTE_CELL_INFO
�ṹ˵��  : ƹ����ѡlteС����ѡ��Ϣ
*****************************************************************************/
typedef struct
{
    LRRC_OM_SCELL_ID                        stLteScellId;
    LRRC_OM_CELL_MEAS_INFO                  stScellMeasInfo;
}LRRC_OM_PINGPONG_LTE_CELL_INFO;

/*****************************************************************************
�ṹ��    : LRRC_OM_PINGPONG_CELL_INFO
�ṹ˵��  : ƹ����ѡС����ѡ��Ϣ
*****************************************************************************/
typedef struct
{
    LRRC_OM_RAT_TYPE_ENUM_UINT16         usRatType;
    VOS_UINT16                           usRsv;
    union
    {
        LRRC_OM_PINGPONG_LTE_CELL_INFO   stLteCellInfo;
        LRRC_OM_UTRA_CELL_INFO           stUtraCellInfo;
        LRRC_OM_GSM_CELL_INFO            stGsmCellInfo;
        LRRC_OM_CDMA_CELL_INFO           stCdmaCellInfo;
    }u;
}LRRC_OM_PINGPONG_CELL_INFO;

/*****************************************************************************
�ṹ��    : LRRC_OM_PINGPONG_RESEL_RECORD
�ṹ˵��  : ƹ����ѡ��¼
*****************************************************************************/
typedef struct
{
    VOS_UINT8                               ucPingPongCellNum;
    VOS_UINT8                               ucRsv;
    VOS_UINT16                              usPingPongTimes;
    LRRC_OM_PINGPONG_CELL_INFO              astPpCellReselCellList[LRRC_OM_PING_PONG_CELL_NUM_MAX];
}LRRC_OM_PINGPONG_RESEL_RECORD;

/*****************************************************************************
�ṹ��    : LRRC_CHR_PINGPONG_RESEL_LIST_INFO
�ṹ˵��  : ƹ����ѡ��Ϣ
*****************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU                stHead;
    RRC_APP_ERROR_CODE_ENUM_UINT16        enErrorCode;            /* �������ϱ��ṹ��ÿ��ģ�鵥����� */
    VOS_UINT16                            usPpCellReselRecordNum;
    LRRC_OM_PINGPONG_RESEL_RECORD         astPpCellReselRecordList[LRRC_OM_PING_PONG_INFO_NUM_MAX];
}LRRC_OM_PINGPONG_RESEL_INFO_STRU;

/*****************************************************************************
�ṹ��    : RRC_ERRLOG_ESR_CS_FAIL_STRU
Э�����  :
ASN.1���� :
�ṹ˵��  : CSʧ�ܼ�¼
*****************************************************************************/
typedef struct
{
    LRRC_OM_SCELL_ID                        stScellId;
    VOS_UINT16                              usCsTotalTimes;                 /* ��cs���� */
    VOS_UINT16                              usCsFailTimes;                  /* csʧ�ܴ��� */
    VOS_UINT16                              usConnPagingRelTimes;           /* ����̬Ѱ���Ż���Ч���� */
    VOS_UINT16                              usCsReestRelTimes;              /* cs�ڼ��ؽ����Ż���Ч���� */
    VOS_UINT16                              usCsExpiredRelTimes;            /* cs�ڼ䳬ʱ�ͷ��Ż���Ч���� */
    VOS_UINT16                              ausRsv[9];
}LRRC_OM_ESR_CS_FAIL_RECORD;

/*****************************************************************************
�ṹ��    : LRRC_OM_CSFB_FAIL_INFO_STRU
Э�����  :
ASN.1���� :
�ṹ˵��  : CSFBʧ����Ϣ
*****************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU              stHead;
    RRC_APP_ERROR_CODE_ENUM_UINT16      enErrorCode;            /* �������ϱ��ṹ��ÿ��ģ�鵥����� */
    VOS_UINT16                          usCsfbFailInfoNum;
    LRRC_OM_ESR_CS_FAIL_RECORD          astEsrFailList[LRRC_OM_ESR_NUM_MAX];
}LRRC_OM_CSFB_FAIL_INFO_STRU;

/*****************************************************************************
�ṹ��    : LRRC_CHR_MOBILITY_2_QLOW_CELL_INFO
Э�����  :
ASN.1���� :
�ṹ˵��  : Mobility2QLowCell��¼
*****************************************************************************/
typedef struct
{
    LRRC_OM_QLOW_FLOW_TYPE_ENUM_UINT8       usMobiltyFLowType;
    VOS_UINT8                               aucRsv[3];
    LRRC_OM_SCELL_ID                        stScellId;
    LRRC_OM_CELL_MEAS_INFO                  stScellMeasInfo;
}LRRC_OM_MOBILITY_2_QLOW_CELL_RECORD;

/*****************************************************************************
�ṹ��    : LRRC_OM_MOBILITY_2_QLOW_CELL_INFO_STRU
Э�����  :
ASN.1���� :
�ṹ˵��  : Mobility2QLowCell��Ϣ
*****************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU                  stHead;
    RRC_APP_ERROR_CODE_ENUM_UINT16          enErrorCode;            /* �������ϱ��ṹ��ÿ��ģ�鵥����� */
    VOS_UINT16                              usMobility2QLowInfoNum;
    LRRC_OM_MOBILITY_2_QLOW_CELL_RECORD     astMobility2QLowRecordList[LRRC_OM_MOBILITY_2_QLOW_NUM_MAX];
}LRRC_OM_MOBILITY_2_QLOW_CELL_INFO_STRU;

/*****************************************************************************
�ṹ��    : LRRC_CHR_OUT_OF_SYNC_INFO
Э�����  :
ASN.1���� :
�ṹ˵��  : ʧ����¼
*****************************************************************************/
typedef struct
{
    LRRC_OM_SCELL_ID                        stScellId;
    VOS_UINT32                              ulOutOfSyncNum;
    VOS_UINT32                              ulInSyncNum;
}LRRC_OM_OUT_OF_SYNC_RECORD;

/*****************************************************************************
�ṹ��    : LRRC_CHR_OUT_OF_SYNC_INFO_LIST
Э�����  :
ASN.1���� :
�ṹ˵��  : ʧ����¼��Ϣ
*****************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU                       stHead;
    RRC_APP_ERROR_CODE_ENUM_UINT16               enErrorCode;                   /* �������ϱ��ṹ��ÿ��ģ�鵥����� */
    VOS_UINT16                                   usOutOfSyncRecordNum;          /*ʧ����¼���������Ϊ8*/
    LRRC_OM_OUT_OF_SYNC_RECORD                   astOutOfSyncInfoList[LRRC_OM_OUT_OF_SYNC_NUM_MAX];
}LRRC_OM_OUT_OF_SYNC_INFO_STRU;

/* BAND-38 Scell Not config MFBI record begin */
/*****************************************************************************
�ṹ��    : LRRC_CHR_SCELL_MFBI_RECORD_STRU
Э�����  :
ASN.1���� :
�ṹ˵��  : MFBI info record
*****************************************************************************/
typedef struct
{
    VOS_UINT32                                  ulGci;                          /* sib1�е�GlobalCellId */
    VOS_UINT32                                  ulMcc;                          /* Mcc */
    VOS_UINT32                                  ulMnc;                          /* Mnc */
    LRRC_OM_TAC_STRU                            stTac;                          /* tac */
    VOS_UINT16                                  usPhyCellId;                    /* ����С��id */
    VOS_UINT16                                  usUlEarfcn;                     /*����Ƶ�ʣ���λ100khz*/
    VOS_UINT16                                  usDlEarfcn;                     /*����Ƶ�ʣ���λ100khz*/
    VOS_UINT8                                   ucServerCellBandInd;            /* ����band*/
    VOS_UINT8                                   ucRsv;
    VOS_UINT8                                   ucMultiBandIndNum;
    VOS_UINT8                                   aucMultiBandInd[9];             /* ��band�б���Ϣ����һλ���sib1 r9 band��Ϣ */
    VOS_UINT8                                   aucReserved[2];
}LRRC_CHR_SCELL_MFBI_RECORD_STRU;

/*****************************************************************************
�ṹ��    : LRRC_CHR_SCELL_MFBI_INFO_RPT_STRU
Э�����  :
ASN.1���� :
�ṹ˵��  : MFBI info report
*****************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU                       stHead;
    RRC_APP_ERROR_CODE_ENUM_UINT16               enErrorCode;      /* �������ϱ��ṹ��ÿ��ģ�鵥����� */
    VOS_UINT16                                   usRecordNum;      /* δ����MFBI��BAND38С����¼���������Ϊ30 */
    LRRC_CHR_SCELL_MFBI_RECORD_STRU              astScellInfoList[LRRC_OM_SCELL_NOTCONFIG_MFBI_MAX_NUM];
}LRRC_OM_SCELL_MFBI_INFO_RPT_STRU;
/* BAND-38 Scell Not config MFBI record end */

/*****************************************************************************
 ö����    : RRC_APP_ERROR_CODE_ENUM
 Э�����  :
 ASN.1���� :
 ö��˵��  : RRC����������
*****************************************************************************/
enum RRC_APP_AIR_MSG_FAIL_ENUM
{
    RRC_APP_AIR_MSG_DECODE_FAIL               = 0,  /* ����ʧ�� */
    RRC_APP_AIR_MSG_CHECK_FAIL                = 0,  /* ���ʧ�� */

    RRC_APP_AIR_MSG_FAIL_BUTT
};
typedef VOS_UINT16 RRC_APP_AIR_MSG_FAIL_ENUM_UINT16;

/*****************************************************************************
�ṹ��    : LRRC_CHR_OUT_OF_SYNC_INFO_LIST
Э�����  :
ASN.1���� :
�ṹ˵��  : ʧ����¼��Ϣ
*****************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU                       stHead;
    RRC_APP_ERROR_CODE_ENUM_UINT16               enErrorCode;         /* �������ϱ��ṹ��ÿ��ģ�鵥����� */
    VOS_UINT16                                   usFailAirMsgType;
    VOS_UINT32                                   ulGci;                          /* sib1�е�GlobalCellId */
    VOS_UINT32                                   ulMcc;                          /* MCC,3 bytes      */
    VOS_UINT32                                   ulMnc;                          /* MNC,2 or 3 bytes */
    LRRC_OM_TAC_STRU                             stTac;                          /* tac */
    VOS_UINT16                                   usPhyCellId;                    /* ����С��id */

    VOS_UINT16                                   usRsv0;
    VOS_UINT16                                   usRsv1;
    VOS_UINT16                                   usRsv2;
    VOS_UINT16                                   usRsv3;
    VOS_UINT16                                   usRsv4;
    VOS_UINT16                                   usRsv5;
    VOS_UINT16                                   usRsv6;
    LRRC_OM_LATEST_PRINT_INFO                    stLatestPrint;
    VOS_UINT8                                    aucBuf[LRRC_OM_AIR_MSG_BUF_LEN];
}LRRC_OM_AIRMSG_PROC_FAIL;
/*****************************************************************************
�ṹ��    : LRRC_OM_SRVCC_MEAS_INFO_STRU
Э�����  :
ASN.1���� :
�ṹ˵��  : SRVCC��صĲ���ID
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                   usMeasId;
    VOS_UINT16                                   usMeasObjId;
    VOS_UINT16                                   usMeasRptId;
    LRRC_OM_RAT_TYPE_ENUM_UINT16                 usMeasObjRat;
    VOS_UINT32                                   ulCarrierFreq;
    VOS_UINT16                                   usMeasRptType;
    VOS_INT16                                    sEventThreshold1;
    VOS_INT16                                    sEventThreshold2;
    VOS_INT16                                    sFreqOffset;
    VOS_UINT8                                    ucHysteresis;
    VOS_UINT8                                    ucEventRptFlg;                 /* ��MeasId�Ƿ񴥷����������� */
    VOS_UINT8                                    aucRsv[2];
    VOS_UINT32                                   aulRsv[4];
}LRRC_OM_SRVCC_MEAS_INFO_STRU;

/*****************************************************************************
�ṹ��    : LRRC_OM_SRVCC_INFO_STRU
Э�����  :
ASN.1���� :
�ṹ˵��  : SRVCCʧ����Ϣ
*****************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU                       stHead;
    RRC_APP_ERROR_CODE_ENUM_UINT16               enErrorCode;                   /* �������ϱ��ṹ��ÿ��ģ�鵥����� */
    VOS_INT16                                    sRsrp;                         /* ��ǰ����С��rsrp */
    VOS_INT16                                    sRsrq;                         /* ��ǰ����С��rsrq */
    VOS_INT16                                    sRssi;
    VOS_UINT32                                   ulGci;                         /* sib1�е�GlobalCellId */
    LRRC_OM_TAC_STRU                             stTac;                         /* tac */
    VOS_UINT32                                   ulMcc;                         /* Mcc */
    VOS_UINT32                                   ulMnc;                         /* Mnc */
    VOS_UINT32                                   ulDlEarfcn;                    /*����Ƶ�㣬��λ100khz */
    VOS_UINT16                                   usPhyCellId;                   /* ����С������λ100khz */
    LRRC_OM_SRVCC_RST_UINT8                      ucFailCause;                   /* ʧ��ԭ��ֵ */
    VOS_UINT8                                    ucSrvccState;                  /* Ԥ�� */
    VOS_UINT16                                   usRsv;
    VOS_UINT16                                   usMeasIdNum;
    LRRC_OM_SRVCC_MEAS_INFO_STRU                 astMeasIdList[LRRC_OM_SRVCC_MAX_MEASID_NUM];
    VOS_UINT32                                   aulRsv[8];
}LRRC_OM_SRVCC_FAIL_INFO_STRU;

/*****************************************************************************
�ṹ��    : LRRC_OM_MOD3_NCELL_INFO_STRU
Э�����  :
ASN.1���� :
�ṹ˵��  : ģ�����ǿ����С��
*****************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU                       stHead;
    RRC_APP_ERROR_CODE_ENUM_UINT16               enErrorCode;                   /* �������ϱ��ṹ��ÿ��ģ�鵥����� */
    VOS_UINT16                                   usRsv0;
    VOS_UINT32                                   ulGci;                         /* sib1�е�GlobalCellId */
    LRRC_OM_TAC_STRU                             stTac;                         /* tac */
    VOS_UINT32                                   ulMcc;                         /* Mcc */
    VOS_UINT32                                   ulMnc;                         /* Mnc */
    VOS_UINT32                                   ulDlarfcn;                     /* ����Ƶ�� */
    VOS_INT16                                    sRsrp;                         /* ��ǰ��С��rsrp */
    VOS_INT16                                    sRsrq;                         /* ��ǰ��С��rsrq */
    VOS_INT16                                    sRssi;
    VOS_INT16                                    sNcellRsrp;                    /* ģ�����ͬƵ��С��rsrp */
    VOS_INT16                                    sNcellRsrq;                    /* ģ�����ͬƵ��С��rsrq */
    VOS_INT16                                    sNcellRssi;
    VOS_UINT16                                   usPCellId;                     /* ��С��ID */
    VOS_UINT16                                   usNCellId;                     /* ��С��ID */

    PS_BOOL_ENUM_UINT8                           ucVolteFlag;
    VOS_UINT8                                    ucRsv0;
    VOS_UINT8                                    ucRsv1;
    VOS_UINT8                                    ucRsv2;
    VOS_UINT8                                    ucRsv3;
    VOS_UINT8                                    ucRsv4;
    VOS_UINT8                                    ucRsv5;
    VOS_UINT8                                    ucRsv6;
    VOS_UINT16                                   usRsv1;
    VOS_UINT16                                   usRsv2;
    VOS_UINT16                                   usRsv3;
    VOS_UINT16                                   usRsv4;
    VOS_UINT32                                   ulRsv0;
    VOS_UINT32                                   ulRsv1;
}LRRC_OM_MOD3_NCELL_INFO_STRU;

/*****************************************************************************
�ṹ��    : LRRC_OM_RF_FAIL_REEST_INFO_STRU
Э�����  :
ASN.1���� :
�ṹ˵��  : ������·ʧ�ܵ��µ��ؽ���������ͳ��ͬƵA3��������δ��Ӧ�����
*****************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU                       stHead;
    RRC_APP_ERROR_CODE_ENUM_UINT16               enErrorCode;                   /* �������ϱ��ṹ��ÿ��ģ�鵥����� */
    VOS_UINT16                                   usRsv0;

    VOS_UINT32                                   ulGci;                         /* sib1�е�GlobalCellId */
    LRRC_OM_TAC_STRU                             stTac;                         /* tac */
    VOS_UINT32                                   ulMcc;                         /* Mcc */
    VOS_UINT32                                   ulMnc;                         /* Mnc */
    VOS_UINT32                                   ulDlarfcn;                     /* ����Ƶ�� */

    VOS_INT16                                    sRsrp;                         /* ��ǰ��С��rsrp */
    VOS_INT16                                    sRsrq;                         /* ��ǰ��С��rsrq */

    VOS_INT16                                    sRssi;
    VOS_INT16                                    sStrongestIntraNcellRsrp;      /* ��ǿͬƵ��С��rsrp */

    VOS_INT16                                    sStrongestIntraNcellRsrq;      /* ��ǿͬƵ��С��rsrq */
    VOS_INT16                                    sStrongestIntraNcellRssi;

    VOS_UINT16                                   usPCellId;                     /* ��С��ID */
    VOS_UINT16                                   usStrongestIntraNCellId;       /* ��ǿͬƵ��С��ID */

    VOS_UINT16                                   usA3RptCnt;                    /* A3�ϱ����� */
    VOS_UINT16                                   usRsv7;

    VOS_UINT32                                   ulA3ToReestInterTime;          /* ��һ���ϱ�A3���ؽ�����ʱ��������λms */
    VOS_UINT32                                   ulT310Len;                     /* T310ʱ������λms */

    VOS_UINT8                                    ucA3RptFlag;                   /* ͬƵA3�����ϱ����:0:δ����A3���� 1:�в�����δ�ϱ� 2:�в������ϱ� */
    PS_BOOL_ENUM_UINT8                           ucPcellStrongestFlag;          /* ��С��ͬƵ�ź�������ǿ��־��������rsrp */
    PS_BOOL_ENUM_UINT8                           ucVolteFlag;
    VOS_UINT8                                    ucRsv0;

    VOS_UINT16                                   usA3NCellId0;                  /* A3�ϱ���������С��ID0����Чֵ0xFF */
    VOS_UINT16                                   usA3NCellId1;

    VOS_UINT16                                   usA3NCellId2;
    VOS_UINT16                                   usA3NCellId3;

    VOS_UINT16                                   usA3NCellId4;
    VOS_UINT16                                   usA3NCellId5;

    VOS_UINT8                                    ucRsv1;                        /* �൱��usA3NCellId6 */
    VOS_UINT8                                    ucRsv2;                        /* �൱��usA3NCellId7 */
    VOS_UINT8                                    ucRsv3;
    VOS_UINT8                                    ucRsv4;

    VOS_UINT8                                    ucRsv5;
    VOS_UINT8                                    ucRsv6;
    VOS_UINT8                                    ucRsv7;
    VOS_UINT8                                    ucRsv8;

    VOS_UINT16                                   usRsv1;
    VOS_UINT16                                   usRsv2;

    VOS_UINT16                                   usRsv3;
    VOS_UINT16                                   usRsv4;

    VOS_UINT16                                   usRsv5;
    VOS_UINT16                                   usRsv6;

    VOS_UINT32                                   ulRsv0;                        /* ���һ�γɹ��ϱ�A3���ؽ�����ʱ��������λms */
    VOS_UINT32                                   ulRsv1;
}LRRC_OM_RF_FAIL_REEST_INFO_STRU;
/*****************************************************************************
�ṹ��    : LRRC_GUTRRC_CELL_RESEL_RESULT
Э�����  :
ASN.1���� :
�ṹ˵��  : GUT2L ��ѡѡʧ��ԭ��ֵ������
*****************************************************************************/
typedef struct
{
    RRC_APP_ERROR_CODE_ENUM_UINT16              enErrorCode;               /* �������ϱ��ṹ��ÿ��ģ�鵥����� */
    LRRC_APP_ERR_LOG_RAT_TYPE_ENUM_UINT8        enSrcIratType;             /* ԴС����ʽ����1ΪG, 2ΪW, 4ΪT */
    VOS_UINT8                                   ucRsv;                     /* ���� */

    VOS_UINT32                                  ulGci;                    /* sib1�е�GlobalCellId */
    VOS_UINT32                                  ulMcc;                    /* Mcc */
    VOS_UINT32                                  ulMnc;                    /* Mnc */
    LRRC_OM_TAC_STRU                            stTac;                    /* tac */
    VOS_UINT16                                  usPhyCellId;              /* ����С��id */
    VOS_UINT16                                  usDlEarfcn;               /*����Ƶ�ʣ���λ100khz*/
    VOS_UINT16                                  usBandInd;                /* ����band*/
    VOS_UINT16                                  usRsv0;

    VOS_INT16                                   sCurrSCellRsrp;            /* С��Rsrp */
    VOS_INT16                                   sCurrSCellRsrq;            /* С��Rsrq */

    LPS_32K_TIMESTAMP                           stCurrTimeStamp;            /* GUT��ѡ��Lʧ�ܵ�ʱ�� */
    LRRC_GUTRRC_RESEL_FAIL_CAUSE_ENUM_UINT32    enReselFailCause;           /* GUT��ѡ��Lʧ�ܵ�ԭ�� */
}LRRC_GUTRRC_CELL_RESEL_RESULT;

/*****************************************************************************
�ṹ��    : LRRC_OM_GUT2L_RESEL_INFO_STRU
Э�����  :
ASN.1���� :
�ṹ˵��  : ����ͳ������ģ��L��ѡʧ�ܵ����
*****************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU                       stHead;
    VOS_UINT16                                   usRptNum;
    LRRC_GUTRRC_CELL_RESEL_RESULT                stCellReselResult[LRRC_CHR_RPT_GUT2L_RESEL_FAIL_MAX_NUM];
}LRRC_OM_GUT2L_RESEL_INFO_STRU;

/*****************************************************************************
�ṹ��    : LRRC_OM_SRVCC_STAT_INFO_STRU
Э�����  :
ASN.1���� :
�ṹ˵��  : SRVCCͳ����Ϣ
*****************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU                       stHead;
    RRC_APP_ERROR_CODE_ENUM_UINT16               enErrorCode;                   /* �������ϱ��ṹ��ÿ��ģ�鵥����� */
    VOS_UINT16                                   usRsv;
    VOS_UINT32                                   ulGci;
    LRRC_OM_TAC_STRU                             stTac;                         /* tac */
    VOS_UINT32                                   ulPreDelay;                    /* SRVCC׼��ʱ�� */
    VOS_INT16                                    sMeasCfgRsrp;                  /* ����B1B2ʱrsrp */
    VOS_INT16                                    sMeasCfgRsrq;                  /* ����B1B2ʱrsrq */
    VOS_INT16                                    sMeasRptRsrp;                  /* ��������ʱrsrq */
    VOS_INT16                                    sMeasRptRsrq;                  /* ��������ʱrsrp */
    VOS_INT16                                    sEventThreshold1;
    VOS_INT16                                    sEventThreshold2;
    VOS_UINT32                                   aulRsv[8];
}LRRC_OM_SRVCC_STAT_INFO_STRU;

/*****************************************************************************
�ṹ��    : LRRC_OM_INTER_FREQ_ORRAT_MEAS_FOR_LONG_TIME
Э�����  :
ASN.1���� :
�ṹ˵��  :��ʱ�䴦����ϵͳ����������ѡ�������𹦺����ߵ�����ͳ��
*****************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU                       stHead;
    RRC_APP_ERROR_CODE_ENUM_UINT16               enErrorCode;                   /* �������ϱ��ṹ��ÿ��ģ�鵥����� */
    VOS_UINT16                                   usRsv;
    VOS_UINT32                                   ulGci;
    LRRC_OM_TAC_STRU                             stTac;                         /* tac */
    VOS_UINT32                                   ulMeasTimeLen;                 /* �����ȼ���ϵͳ������ʱ�� */
    VOS_UINT32                                   ulCampTimeLen;                 /* ��ǰС��פ����ʱ�� */
    VOS_UINT32                                   ulConnStateTimeLen;            /* ����̬��ʱ��*/
    VOS_UINT32                                   ulCometoConnTimes;             /* �ڼ��������̬�Ĵ���*/

    VOS_UINT32                                   ulCampTstampStartHighBits;
    VOS_UINT32                                   ulCampTstampStartLowBits;

    VOS_UINT32                                   ulCampTstampEndHighBits;
    VOS_UINT32                                   ulCampTstampEndLowBits;


    VOS_INT16                                    sRxLevelMin;
    VOS_INT16                                    sRxLevelQMin;
    VOS_INT16                                    sNonIntraSearch;
    VOS_INT16                                    sNonIntraSearchQ;
    VOS_INT16                                    sThreshServingLowP;
    VOS_INT16                                    sThreshServingLowQ;

    VOS_UINT16                                   usLowUmtsFreqNum;
    VOS_UINT16                                   usLowGsmFreqNum;


    VOS_UINT16                                   usUtranMode;
    VOS_UINT16                                   usRsv0;

    VOS_UINT16                                   usRsv1;
    VOS_UINT16                                   usRsv2;


    VOS_UINT32                                   ulRsv0;
    VOS_UINT32                                   ulRsv1;
    VOS_UINT32                                   ulRsv2;
    VOS_UINT32                                   ulRsv3;

}LRRC_OM_INTER_FREQORRAT_MEAS_FOR_LONG_TIME;

typedef struct
{
    VOS_UINT32   ulTimeStamp;
    VOS_UINT32   ulFileID;
    VOS_UINT32   ulLineNO;
    SECU_FUNC_TYPE_ENUM_UINT8 enSecuFuncType;/*��������*/
    VOS_UINT8    ucRsv;
    VOS_INT16    sErrNo;/*����ֵ*/
    VOS_VOID *   pDst;/*Ŀ�ĵ�ַ*/
    VOS_UINT32   ulMaxBuffer;/*Ŀ�Ļ��泤��*/
    VOS_VOID *   pSrc;/*Դ��ַ*/
    VOS_UINT32   ulLength;/*ʵ�ʳ���*/
}TLPS_SECU_FUNCTION_INFO_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_OM_SECU_FUNCTION_ERROR_INFO_STRU
 �ṹ˵��  : ��ȫ�����쳣���д�����Ϣ
*****************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU                     stHead;                /* Errorlog ��Ϣͷ*/
    RRC_APP_ERROR_CODE_ENUM_UINT16             enErrorCode;             /* ������*/
    VOS_UINT16                                 usRsv;
    TLPS_SECU_FUNCTION_INFO_STRU               stTlpsSecuFunctionInfo;   /* ��ȫ���������쳣ʱ״̬��Ϣ */
}LRRC_OM_SECU_FUNCTION_ERROR_INFO_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_OM_AIR_SIGNAL_INFO_STRU
 �ṹ˵��  : һ���źŹ켣�ļ�¼��Ϣ
*****************************************************************************/
typedef struct
{
    VOS_UINT16        usCellId;
    VOS_UINT16        usDLEarfcn;
    VOS_INT16         sRsrp;
    VOS_INT16         sRsrq;
    VOS_UINT16        usStrongestIntraCell;
    VOS_INT16         sStrongestIntrRsrp;
    VOS_UINT16        usMod3EualIntraCell;
    VOS_INT16         sMod3EualIntraRsrp;
    VOS_UINT32        ulTimeStamp;
    VOS_INT8          sPusPwr;
    VOS_UINT8         ucBler;
    VOS_UINT8         ucMeasLevel;
    VOS_INT8          sSnr;
    LPS_OM_SENSOR_STAT_ENUM_UINT8   enSensorState;
    VOS_INT8          sResv;
    VOS_UINT16        usResv;
}LRRC_OM_AIR_SIGNAL_INFO_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_OM_LAYER_EVENT_INFO_STRU
 �ṹ˵��  : һ��Key ��¼��Ϣ
*****************************************************************************/
typedef struct
{
    OM_PS_KEY_EVENT_ENUM_UINT16   usEvent;
    VOS_UINT16                    usRsv;
    VOS_UINT32                    ulTimeStamp;
}LRRC_OM_LAYER_EVENT_INFO_STRU;

/*****************************************************************************
 ö����    : RRC_MR_TRIG_TYPE_ENUM
 Э�����  :
 ASN.1���� :
 ö��˵��  : �������������ϱ�������
*****************************************************************************/
enum LRRC_MR_TRIG_TYPE_ENUM
{
    LRRC_MR_TRIG_TYPE_A1 = 0,
    LRRC_MR_TRIG_TYPE_A2 ,
    LRRC_MR_TRIG_TYPE_A3 ,
    LRRC_MR_TRIG_TYPE_A4 ,
    LRRC_MR_TRIG_TYPE_A5 ,
    LRRC_MR_TRIG_TYPE_A6 ,
    LRRC_MR_TRIG_TYPE_A7 ,
    LRRC_MR_TRIG_TYPE_A8 ,
    LRRC_MR_TRIG_TYPE_A9 ,

    LRRC_MR_TRIG_TYPE_B1 ,
    LRRC_MR_TRIG_TYPE_B2 ,
    LRRC_MR_TRIG_TYPE_B3 ,
    LRRC_MR_TRIG_TYPE_B4 ,


    LRRC_MR_TRIG_TYPE_C1 ,
    LRRC_MR_TRIG_TYPE_C2 ,
    LRRC_MR_TRIG_TYPE_C3 ,
    LRRC_MR_TRIG_TYPE_C4 ,

    LRRC_MR_TRIG_TYPE_PERIOD_STR ,
    LRRC_MR_TRIG_TYPE_PERIOD_CGI ,

    LRRC_MR_TRIG_TYPE_BUTT
};
typedef VOS_UINT8   LRRC_MR_TRIG_TYPE_ENUM_UINT8;

/*****************************************************************************
 ö����    : RRC_CMM_MEAS_OBJ_TYPE_ENUM
 Э�����  :
 ASN.1���� :
 ö��˵��  :����Э�鶨��
*****************************************************************************/
enum LRRC_OM_MEAS_OBJ_TYPE_ENUM
{
    RRC_OM_MEAS_OBJ_EUTRA     = 1,
    RRC_OM_MEAS_OBJ_UTRA      ,
    RRC_OM_MEAS_OBJ_GERAN     ,
    RRC_OM_MEAS_OBJ_CDMA2000  ,
    RRC_OM_MEAS_OBJ_BUTT
};
typedef VOS_UINT8 LRRC_OM_MEAS_OBJ_TYPE_ENUM_UINT8;


/*****************************************************************************
 �ṹ��    : LRRC_OM_MR_BASIC_INFO
 �ṹ˵��  : ����ǲ������棬��¼һЩ������Ϣ
*****************************************************************************/
typedef struct
{
    VOS_UINT32                       ulTimeStamp;
    VOS_UINT16                       usSrvingCellId;       /* ���Ͳ�������ʱ��PCELL ID */
    VOS_UINT16                       usSrvingEarfcn;       /* ���Ͳ�������ʱ��PCELL��ARFCN */

    VOS_UINT32                       ulObjEarfcn;

    RRC_APP_BOOL_ENUM_UINT8          enCnfFlg;             /* ȷ�ϱ�־ */
    LRRC_OM_MEAS_RPT_TYPE_ENUM_UINT8 enEvtType;
    VOS_UINT8                        ucIfScell;            /* �����A1-A3�Ƿ���SCELL*/
    LRRC_OM_MEAS_OBJ_TYPE_ENUM_UINT8 enObjType;            /* ObjType*/

    VOS_UINT8                        ucPcellRsrp;
    VOS_UINT8                        ucPcellRsrq;
    VOS_UINT8                        ucNcellEnergy;        /* ��A1,A2ʱ�䱨��ǿ�������� */
    VOS_UINT8                        ucNcellQulity;        /* ��A1,A2ʱ�䱨��ǿ�������� */

    VOS_UINT8                        ucNcellEnergySnd;     /* ��ǿ�������� */
    VOS_UINT8                        ucRsv0;
    VOS_UINT8                        ucRsv1;
    VOS_UINT8                        ucRsv2;

    VOS_UINT16                       usNcellId;             /* NcellId */
    VOS_UINT16                       usNcellIdSnd;          /* ��ǿNcellId */
}LRRC_OM_MEASRPT_INFO;

/*****************************************************************************
 �ṹ��    : LRRC_OM_UL_AIRMSG_INFO_STRU
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_UINT32                       ulTimeStamp;
    LRRC_OM_AIRMSG_TYPE_ENUM_UINT16  usMsgType;
    RRC_APP_BOOL_ENUM_UINT8          enCnfFlg;             /* ȷ�ϱ�־ */
    VOS_UINT8                        ucRsv;

    LRRC_OM_MEASRPT_INFO            *pstMrInfo;             /* ���������ṩ�������Ϣ��
                                                              ���ڳ�ʼ������ã��ڴ治�����Ż�*/
}LRRC_OM_UL_AIRMSG_INFO_STRU;

/*****************************************************************************
 �ṹ��    :LRRC_OM_REEST_TRIG_ENUM
 �ṹ˵��  :�ؽ���������ֱ��ԭ��
*****************************************************************************/
enum LRRC_OM_REEST_TRIG_ENUM
{
    LRRC_OM_REEST_TRIG_LMAC_ERR_FATAL = 0,                  /*�����������粻ָʾ�л�*/
    LRRC_OM_REEST_TRIG_LMAC_RA_ERR_MAX_TX,                        /*ȷʵû���ź�*/
    LRRC_OM_REEST_TRIG_LMAC_RA_ERR_MAX_HARQ,
    LRRC_OM_REEST_TRIG_LMAC_ERR_NO_RF_RA,
    LRRC_OM_REEST_TRIG_LMAC_ERR_NO_RF_TIMEROUT,
    LRRC_OM_REEST_TRIG_LMAC_ERR_RF_RESUME_SYNC,

    LRRC_OM_REEST_TRIG_LRLC_ERR_RL_FAIL = 20,

    LRRC_OM_REEST_TRIG_LPDCP_INTEGRITY_VERIFY = 30,

    LRRC_OM_REEST_TRIG_OUT_OF_SYNC       = 40,
    LRRC_OM_REEST_TRIG_LPHY_TIMING_ERR,
    LRRC_OM_REEST_TRIG_SERV_MEAS_DOWN,            /* �������������� */

    LRRC_OM_REEST_TRIG_HIGH_LAYER        = 60,    /* �߲�Ƶ�ν�ֹ��ԭ�� */
    LRRC_OM_REEST_TRIG_INTERNAL_CONFLICT,         /* �ڲ����̶Գ� */

    /* RRCԭ�� */
    LRRC_OM_REEST_TRIG_INTRAFREQ_HO_FAIL = 70,         /* LTEģ��ͬƵ�л�ʧ��*/
    LRRC_OM_REEST_TRIG_INTERFREQ_HO_FAIL,         /* LTEģ����Ƶ�л�ʧ��*/
    LRRC_OM_REEST_TRIG_L2W_HO_FAIL,           /* ϵͳ���л�ʧ��*/
    LRRC_OM_REEST_TRIG_L2G_HO_FAIL,           /* ϵͳ���л�ʧ��*/
    LRRC_OM_REEST_TRIG_L2G_CCO_FAIL,          /* ϵͳ���л�ʧ��*/
    LRRC_OM_REEST_TRIG_L2L_T304_EXPIRED,      /* T304 Expired */
    LRRC_OM_REEST_TRIG_CCO_T304_EXPIRED,
    LRRC_OM_REEST_TRIG_X2LHO_T304_EXPIRED,


    /*=========================�ڲ��쳣=======================================*/
    LRRC_OM_REEST_TRIG_X2L_CHECKFAIL      = 160,         /* L2X�л�����Ԫ���ʧ�� */
    LRRC_OM_REEST_TRIG_X2L_SUSPENDFAIL,       /* L2X����ʧ�� */

    LRRC_OM_REEST_TRIG_CFG_PHY_FAIL,
    LRRC_OM_REEST_TRIG_CFG_L2_FAIL,
    LRRC_OM_REEST_TRIG_CFG_PDCP_FAIL,
    LRRC_OM_REEST_TRIG_SCELL_RELCFG_FAIL,
    LRRC_OM_REEST_TRIG_RELNEWRB_FAIL,
    LRRC_OM_REEST_TRIG_SAVERECFG_FAIL,
    LRRC_OM_REEST_TRIG_STOP_PDCP_FAIL,
    LRRC_OM_REEST_TRIG_HO_CFGMACRLC_FAIL,
    LRRC_OM_REEST_TRIG_HO_CFGRB_FAIL,
    LRRC_OM_REEST_TRIG_HO_CFGSMC_FAIL,
    LRRC_OM_REEST_TRIG_HO_CFGSCELL_FAIL,
    LRRC_OM_REEST_TRIG_HO_RELNEWRB_FAIL,
    LRRC_OM_REEST_TRIG_BUTT
};
typedef VOS_UINT8  LRRC_OM_REEST_TRIG_ENUM_UINT8;

/*****************************************************************************
 �ṹ��    :LRRC_OM_REEST_SUBTRIG_ENUM
 �ṹ˵��  :�ؽ�����������ԭ��
*****************************************************************************/
enum LRRC_OM_REEST_SUBTRIG_ENUM
{
    LRRC_OM_REEST_SUBTRIG_NORMAL,
    LRRC_OM_REEST_SUBTRIG_BUTT
};
typedef VOS_UINT8  LRRC_OM_REEST_SUBTRIG_ENUM_UINT8;

/*****************************************************************************
 �ṹ��    :LRRC_OM_REEST_GUESSTRIG_ENUM
 �ṹ˵��  :�ؽ����������Ʋ�ԭ��ֵ
*****************************************************************************/
enum LRRC_OM_REEST_GUESSTRIG_ENUM
{
    LRRC_OM_REEST_GUESSTRIG_NORMAL = 1,
    LRRC_OM_REEST_GUESSTRIG_BUTT,
};
typedef VOS_UINT8  LRRC_OM_REEST_GUESSTRIG_ENUM_UINT8;

/*****************************************************************************
 �ṹ��    :LRRC_OM_REEST_FLOW_IND
 �ṹ˵��  :�ؽ�������ָʾ
*****************************************************************************/
enum LRRC_OM_REEST_FLOW_IND_ENUM
{
    LRRC_OM_REEST_FLOW_IND_SUCC = 1,                         /*�ؽ��ɹ�*/
    LRRC_OM_REEST_FLOW_IND_REJ,                              /*�ؽ�������*/

    LRRC_OM_REEST_FLOW_IND_T311_EXPIRE,                      /* �ؽ���ʧ��--�ؽ�������С������T311��ʱ����ʱ */
    LRRC_OM_REEST_FLOW_IND_T301_EXPIRE,                      /* �ؽ���ʧ��--���ͽ���Req��Ϣ�󣬵ȴ��ؽ���Ӧ��Ϣ��T301��ʱ */
    LRRC_OM_REEST_FLOW_IND_INTR_ERROR,                       /* �ڲ��쳣����Ԫ���ʧ�ܵ� */
    LRRC_OM_REEST_FLOW_IND_BUTT,
};
typedef VOS_UINT8  LRRC_OM_REEST_FLOW_IND_ENUM_UINT8;



/*****************************************************************************
�ṹ��    : LRRC_OM_REESTAB_STAT_INFO_STRU
Э�����  :
ASN.1���� :
�ṹ˵��  : �ؽ���ͳ����Ϣ
*****************************************************************************/
typedef struct
{
    VOS_UINT32                                   ulMcc;                         /* Mcc */
    VOS_UINT32                                   ulMnc;

    VOS_UINT32                                   ulGci;                         /* �ؽ�ǰС����Ϣ */
    LRRC_OM_TAC_STRU                             stTac;

    LRRC_OM_REEST_TRIG_ENUM_UINT8                enReesTrig;                    /* ����ֱ��ԭ��*/
    LRRC_OM_REEST_SUBTRIG_ENUM_UINT8             enReesSubTrig;                 /* ������ԭ�򣬴�����*/
    LRRC_OM_REEST_GUESSTRIG_ENUM_UINT8           enReesGuessTrig;               /* ͨ���Զ��������ó����Ʋ�ԭ��ֵ���������粻�л�*/
    LRRC_OM_REEST_FLOW_IND_ENUM_UINT8            enReesFlowInd;                 /* �ؽ����������̳ɹ�ʧ��ԭ��ֵ*/

    VOS_UINT32                                   ulReesFailSubRslt;             /* ����ؽ�ʧ�ܼ�¼һ����ԭ�� */

    VOS_UINT8                                    enOrigFreqRees;                /* �Ƿ���ԭƵ���ؽ� */
    VOS_UINT8                                    enIfRssiStrPointToSelect;      /* �Ƿ���������ǿ��С����������ѡ�� */
    VOS_UINT16                                   usResv;

    VOS_INT16                                    sTrigRsrp;                     /* �������ϵ�С������ */
    VOS_INT16                                    sTrigRsrq;                     /* �������ϵ�С������ */

    VOS_INT16                                    sRsrpAfterReest;               /* �ؽ����С������ */
    VOS_INT16                                    sRsrqAfterReest;               /* �ؽ����С������ */

    /* ����Ϊ����ϵ�ԭ��ֵ */
    LPS_LOW_QUILITY_ABNORMAL_STRU                stLowQuiltyCause;

    VOS_UINT8                                    enGoodSigRlError;              /* ���ź�������·���⣬������UE�ײ��쳣 */
    VOS_UINT8                                    enNotMaxTxPwrRl;               /* �����ź�δ�Ƶ������RL�쳣�� */
    VOS_UINT8                                    enFastFading;
    VOS_UINT8                                    enRsv1;

    VOS_UINT8                                    enRsv2;
    VOS_UINT8                                    enRsv3;
    VOS_UINT8                                    enRsv4;
    VOS_UINT8                                    enRsv5;

    VOS_UINT32                                   ulRsv0;
    VOS_UINT32                                   ulRsv1;

    VOS_UINT16                                   usRsv1;
    VOS_UINT16                                   usRsv2;

    VOS_UINT32                                   ul1stFreq;
    VOS_INT16                                    s1stRssi;
    VOS_UINT16                                   us1stPssRatio;

    VOS_UINT32                                   ul2ndFreq;
    VOS_INT16                                    s2ndRssi;
    VOS_UINT16                                   us2ndPssRatio;

    VOS_UINT32                                   ul3rdFreq;
    VOS_INT16                                    s3rdRssi;
    VOS_UINT16                                   us3rdPssRatio;

    VOS_UINT32                                   ulFreqBeforeRees;               /* �ؽ�ǰƵ�� */
    VOS_UINT16                                   usPCellIdBeforeRees;            /* �ؽ�ǰС��ID */
    VOS_UINT16                                   usBandBeforeRees;
    VOS_UINT32                                   ulEarfcnBeforeRees;

    VOS_UINT32                                   ulFreqAfterRees;               /* �ؽ�ѡ���Ƶ�� */
    VOS_UINT16                                   usPCellIdAfterRees;            /* �ؽ�ѡ���Ƶ���С��ID */
    VOS_UINT16                                   usBandAfterRees;
    VOS_UINT32                                   ulGciAfterRees;                /* �ؽ�ǰС����Ϣ */

    VOS_UINT32                                   ulSigDbNum;
    LRRC_OM_AIR_SIGNAL_INFO_STRU                 astAirSigDb[LRRC_OM_AIR_SIGNAL_INFO_ELE_NUM]; /* �ؽ�������20s���ź�db*/

    VOS_UINT32                                   ulEvtNum;
    LRRC_OM_LAYER_EVENT_INFO_STRU                astLayerEventDb[LRRC_OM_KEY_EVENT_DB_NUM];    /* ��ֹ�ؽ������̽������¼�DB*/

    VOS_UINT32                                   ulMeasRptNum;
    LRRC_OM_MEASRPT_INFO                         astMeasRptDb[LRRC_OM_MEAS_RPT_DB_NUM];        /* ����MeasRpt��Ϣ�� */

    /* VOS_UINT8                                    aucAirMsgBuff[LRRC_OM_AIR_MSG_BUF_LEN];  */     /* ԭʼAirMsg������*/
}LRRC_OM_REESTAB_STAT_INFO_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_OM_REESTAB_STAT_INFO_STRU
 �ṹ˵��  : �ϱ�HIDS�Ľṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                          /*_H2ASN_Skip*/
    VOS_UINT32                          ulMsgId;            /*_H2ASN_Skip*/
    LRRC_OM_REESTAB_STAT_INFO_STRU      stReestabStatInfo;
}LRRC_AUTOAN_REESTAB_INFO_IND;

/*****************************************************************************
 �ṹ��    : LL2_OM_VOLTE_STAT_INFO_STRU
 Э�����  :
 ASN.1���� :
 �ṹ˵��  : L2 Volte����ͳ����Ϣ
*****************************************************************************/
typedef struct
{
    VOS_UINT32                                ulMsTimeStamp;                    /* ת����MS��ʱ��� */

    LL2_OM_VOLTE_AUTOAN_EVENT_ENUM_UINT8      ucEvent;
    VOS_UINT8                                 ucRtpPktCnt;                      /* 1�������н��յ�RTP������ */
    VOS_UINT8                                 ucRtpLossPktCnt;                  /* 1�������н��յ�����RTP�������� */
    VOS_UINT8                                 ucRohcDecompFailCnt;              /* 1���ڱ���ROHC��ѹ��ʧ�ܵĸ���ͳ�� */

    VOS_UINT16                                usTotalMACTb;                     /* 1��������MAC TB���ܵĸ���ͳ�ƣ������������� */
    VOS_UINT16                                usCrcErrMACTb;                    /* 1��������MAC TB��CRC���ĸ���ͳ�ƣ������������� */
    VOS_UINT16                                usRtpJitter;                      /* 1���ڱ���RTP����ʱ�䣬MS */
    VOS_UINT16                                usRsv0;

    VOS_UINT32                                ulPdcpSendIpPktCnt;               /* PDCP �����������з��͵ı������� */

    VOS_UINT8                                 ucSilenceFrameCnt;                /*1�������о�Ĭ֡����ͳ��*/
    VOS_UINT8                                 ucRsv;
    VOS_UINT16                                usRsv;
}LL2_OM_VOLTE_STAT_INFO_STRU;

/*****************************************************************************
�ṹ��    : LPS_OM_VOLTE_FAULT_AUTOAN_INFO_STRU
Э�����  :
ASN.1���� :
�ṹ˵��  : Volte�������ϸ�������Ϣ���û�CHR��HIDS�ϱ�
*****************************************************************************/
typedef struct
{
    VOS_UINT32                                   ulMcc;                         /* Mcc */
    VOS_UINT32                                   ulMnc;

    VOS_UINT32                                   ulGci;
    LRRC_OM_TAC_STRU                             stTac;

    LRRC_LPDCP_VOLTE_FAULT_TRIG_ENUM_UINT8       enTrigSrc;                     /* ����Դ:�û���ʶ����쳣����BSDʶ����쳣 */
    VOS_UINT8                                    ucRsv;
    LPS_OM_VOLTE_FAULT_CAUSE_ENUM_UINT16         enFaultCause;                  /* �ۺϷ�����FaultCause */

    /* ����Ϸ���ʶ������쳣��,�������쳣 */
    LPS_LOW_QUILITY_ABNORMAL_STRU                stLowQuiltyCause;

    VOS_UINT8                                    enGoodSigRlError;              /* ���ź�������·���⣬������UE�ײ��쳣 */
    VOS_UINT8                                    enGoodSigOutofSync;            /* ���ź�ʧ�� */
    VOS_UINT8                                    enGoodSigBler;                 /* ���ź�����ϸ� */
    VOS_UINT8                                    enNotMaxTxPwrRl;               /* �����ź�δ�Ƶ������RL�쳣�� */

    VOS_UINT8                                    enSrvccFail;                   /* SRVCCʧ�� */
    VOS_UINT8                                    enSrvccDelayAbnormal;          /* SRVCCʱ���쳣 */
    VOS_UINT8                                    enSrvccSucc;                   /* SRVCC�ɹ� */
    VOS_UINT8                                    enAirMsgCheckFail;             /* �տ���ϢASN�������ʧ�� */

    VOS_UINT8                                    enInteVeriFail;                /* ��������֤ʧ�� */
    VOS_UINT8                                    enIntraHoFail;                 /* ������ģ���л�ʧ�� */
    VOS_UINT8                                    enIntraHoSucc;                 /* IntraHo�ɹ� */
    VOS_UINT8                                    enReestHappen;                 /* �������ؽ��� */

    VOS_UINT8                                    enOutOfSync;                   /* ������ʧ��*/
    VOS_UINT8                                    enNotReasonableHoInd;          /* �л���Ŀ��С���Ǻ��� */
    VOS_UINT8                                    enLowQuilBeforeHo;             /* �л�ǰSNR�� */
    VOS_UINT8                                    enLowQuilBeforeSrvcc;          /* SRVCCǰSNR�� */

    VOS_UINT8                                    enLowQuilty;                   /* ����ʱ�δ������ź� */
    LRRC_OM_REEST_TRIG_ENUM_UINT8                enReesTrig;                    /* ��������ؽ�������¼�ؽ�������ԭ�� */
    VOS_UINT8                                    enFastFading;                  /* �źſ�˥ */
    VOS_UINT8                                    enRsv1;

    /* ����Ϸ���ʶ������쳣��,�û����쳣*/
    LL2_OM_VOLTE_AUTOAN_EVENT_ENUM_UINT8         enL2FaultEvent;
    VOS_UINT8                                    enDecipherFail;                /* ��������ʧ�� */
    VOS_UINT8                                    enRohcFail;                    /* ����ͷѹ��ʧ�� */
    VOS_UINT8                                    enRtpPktLostPdcpNoLost;        /* RTP�ж�����PDCP�޶��� */

    VOS_UINT32                                   usRtpConPktLostnum;            /* ����ʱ�Σ���λʱ����������������� */
    VOS_UINT32                                   usRtpPktTotalLostnum;          /* ����ʱ�Σ��ܵ�RTP������ */

    VOS_UINT8                                    enJitterFlg;                   /* �Ƿ���ڶ��� */
    VOS_UINT8                                    enJitterOrPktLostReachThre;    /* �ۺ϶����򶪰��Ƿ񳬹����� */
    VOS_UINT16                                   usJitterTime;                  /* ����ʱ�Σ���λʱ����󶶶�ʱ�� */

    VOS_UINT8                                    enRsv2;
    VOS_UINT8                                    enRsv3;
    VOS_UINT8                                    enRsv4;
    VOS_UINT8                                    enRsv5;

    /* ��Ϣ���ݿ��е�ԭʼ��Ϣ */
    VOS_UINT32                                   ulSigDbNum;
    LRRC_OM_AIR_SIGNAL_INFO_STRU                 astAirSigDb[LRRC_OM_AIR_SIGNAL_INFO_ELE_NUM]; /* Volte���Ϸ���ʱ��20s���ҵ��źű仯*/

    VOS_UINT32                                   ulEvtNum;
    LRRC_OM_LAYER_EVENT_INFO_STRU                astLayerEventDb[LRRC_OM_KEY_EVENT_DB_NUM];    /* Volte���Ϸ���ʱ��20s���ҹؼ��¼�DB */

    VOS_UINT32                                   ulMeasRptNum;
    LRRC_OM_MEASRPT_INFO                         astMeasRptDb[LRRC_OM_MEAS_RPT_DB_NUM];        /* Volte���Ϸ���ʱ�̲������潻������ */

    VOS_UINT16                                   usFaultMsStamp;
    VOS_UINT16                                   usValidPktRptNum;
    LL2_OM_VOLTE_STAT_INFO_STRU                  astLL2PktOmDb[LRRC_LPDCP_VOLTE_STAT_NUM];     /* ����ͳ��L2�û������ݰ�ͳ����Ϣ */
}LPS_OM_VOLTE_FAULT_AUTOAN_INFO_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_OM_VOLTE_AUTOAN_INFO_IND
 �ṹ˵��  : �ϱ�HIDS�Ľṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                          /*_H2ASN_Skip*/
    VOS_UINT32                               ulMsgId;            /*_H2ASN_Skip*/
    LPS_OM_VOLTE_FAULT_AUTOAN_INFO_STRU      stVolteFaultInd;
}LRRC_OM_VOLTE_AUTOAN_INFO_IND;


/*****************************************************************************
�ṹ��    : LRRC_OM_VOLTE_GENERAL_STAT_INFO_STRU
Э�����  :
ASN.1���� :
�ṹ˵��  : �ؽ���ͳ����Ϣ
*****************************************************************************/
typedef struct
{
    VOS_UINT32                                   ulGci;
    LRRC_OM_TAC_STRU                             stTac;

    VOS_UINT8                                    ucHour;
    VOS_UINT8                                    ucMin;
    VOS_UINT8                                    ucIfMoCall;
    VOS_UINT8                                    ucRsv0;
}LRRC_OM_VOLTE_SINGLE_CALL_INFO_STRU;

/*****************************************************************************
�ṹ��    : LRRC_OM_VOLTE_SINGLE_FAULT_INFO_STRU
Э�����  :
ASN.1���� :
�ṹ˵��  : �ؽ���ͳ����Ϣ
*****************************************************************************/
typedef struct
{
    VOS_UINT8                                    ucHour;
    VOS_UINT8                                    ucMin;
    VOS_UINT8                                    ucSec;
    LPS_OM_SENSOR_STAT_ENUM_UINT8                enSensorState;
    LPS_OM_VOLTE_FAULT_CAUSE_ENUM_UINT16         enCause;
    VOS_UINT8                                    ucRsrq;   /* ���ղ���������㷽������ */
    VOS_UINT8                                    ucRsrp;
}LRRC_OM_VOLTE_SINGLE_FAULT_INFO_STRU;


/*****************************************************************************
�ṹ��    : LRRC_OM_VOLTE_GENERAL_STAT_INFO_STRU
Э�����  :
ASN.1���� :
�ṹ˵��  : �ؽ���ͳ����Ϣ
*****************************************************************************/
typedef struct
{
    VOS_UINT32                                   ulMcc;                         /* Mcc */
    VOS_UINT32                                   ulMnc;

    VOS_UINT16                                   usYear;
    VOS_UINT8                                    ucMon;
    VOS_UINT8                                    ucDayOfMon;

    VOS_UINT16                                   usVolteCallNum;                /* VolteCall�ܴ��� */
    VOS_UINT16                                   usMoCallNum;
    VOS_UINT32                                   ulTotalTimeLenInSec;           /* VolteCall��ʱ�����뵥λ */

    VOS_UINT16                                   usBsdFaultTimes;               /* BSDʶ����쳣���� */
    VOS_UINT16                                   usAutoFaultTimes;              /* ����ϴ���ʶ����쳣���� */

    VOS_UINT16                                   usPktLostMoreThan50Times;
    VOS_UINT16                                   usPktLostBet30and50Times;
    VOS_UINT16                                   usPktLostBet20and30Times;
    VOS_UINT16                                   usPktLostBet10and20Times;
    VOS_UINT16                                   usPktLostBet5and10Times;

    VOS_UINT16                                   usJitterMoreThan3SecTimes;
    VOS_UINT16                                   usJitterMoreBet2and3SecTimes;
    VOS_UINT16                                   usJitterMoreBet1and2SecTimes;
    VOS_UINT16                                   usJitterMoreBet500msand1SecTimes;
    VOS_UINT16                                   usJitterMoreBet300and500msTimes;

    VOS_UINT16                                   usStartHour;
    VOS_UINT16                                   usStartDay;
    VOS_UINT16                                   usDurationLenInMin;
    VOS_UINT16                                   usRsv3;

    VOS_UINT16                                   usNoPktTimes;
    VOS_UINT16                                   usLessPktTimes;

    VOS_UINT32                                   ulFaultCallNum;
    LRRC_OM_VOLTE_SINGLE_CALL_INFO_STRU          astFaultCallInfo[LRRC_VOLTE_GEN_STAT_CALL_NUM];

    VOS_UINT32                                   ulFaultInfoNum;
    LRRC_OM_VOLTE_SINGLE_FAULT_INFO_STRU         astFaultPointInfo[LRRC_VOLTE_GEN_STAT_FAULT_NUM];
}LPS_OM_VOLTE_GENERAL_STAT_INFO_STRU;



/*****************************************************************************
  6 UNION
*****************************************************************************/


/*****************************************************************************
  7 Extern Global Variable
*****************************************************************************/


/*****************************************************************************
  8 Fuction Extern
*****************************************************************************/


/*****************************************************************************
  9 OTHERS
*****************************************************************************/


#if (VOS_OS_VER == VOS_WIN32)
#pragma pack()
#else
#pragma pack(0)
#endif




#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* end of LrrcErrLogInterface.h */

