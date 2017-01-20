

#include "bsp_applog.h"
#include "bsp_slice.h"

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef CONFIG_APPLOG
/*****************************************************************************
* �� �� ��  : mdrv_applog_cfg
*
* ��������  :����״̬����ӡ��������
*
* �������  : ��
*
* �������  : ��
*
* �� �� ֵ  : �ɹ�����ʶ��

 �޸���ʷ	:
 ��    ��	: 2016��4��8��
 ��    ��	: x00346372
 �޸�����	:
*****************************************************************************/
int mdrv_applog_cfg(unsigned int enable,unsigned int level)
{
    return bsp_applog_cfg(enable,level);
}


/*****************************************************************************
* �� �� ��  : mdrv_applog_conn
*
* ��������  :�빤������״̬����
*
* �������  : ��
*
* �������  : ��
*
* �� �� ֵ  : �ɹ�����ʶ��

 �޸���ʷ	:
 ��    ��	: 2016��4��8��
 ��    ��	: x00346372
 �޸�����	:
*****************************************************************************/
int mdrv_applog_conn(void)
{
    return bsp_applog_conn();
}

#else
/*****************************************************************************
* �� �� ��  : mdrv_applog_conn
*
* ��������  :�빤������״̬����
*
* �������  : ��
*
* �������  : ��
*
* �� �� ֵ  : �ɹ�����ʶ��

 �޸���ʷ	:
 ��    ��	: 2016��4��8��
 ��    ��	: x00346372
 �޸�����	:
*****************************************************************************/
int mdrv_applog_conn(void)
{
    return 0;
}
/*****************************************************************************
* �� �� ��  : mdrv_applog_cfg
*
* ��������  :����״̬����ӡ��������
*
* �������  : ��
*
* �������  : ��
*
* �� �� ֵ  : �ɹ�����ʶ��

 �޸���ʷ	:
 ��    ��	: 2016��4��8��
 ��    ��	: x00346372
 �޸�����	:
*****************************************************************************/
int mdrv_applog_cfg(unsigned int enable,unsigned int level)
{
    return 0;
}
#endif


#ifdef __cplusplus
}
#endif

