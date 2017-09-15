/****************************************************************************
*
* Created: 30/8/2017 by Ali Sepehri-Amin
* Version: 1.00
*
* Description:
* The code and information provided "as-is" without
* warranty of any kind, either expressed or implied.
*
***************************************************************************/

#ifndef __KAVENEGAR_MAPI__
#define __KAVENEGAR_MAPI__

#ifdef KAVENEGAR_EXPORT
#define KAVENEGAR_MAPI __declspec(dllexport)
#else
#define KAVENEGAR_MAPI __declspec(dllimport)
#endif

#define WIN32_DEFAULT_LIBS

#include <iostream> // string
#include <string.h>
#include <Windows.h>
#include <vector>
#include <stdio.h>
#include <WinInet.h>
#include <sstream>

#include "config.h"
#include "sal-define.h"

#if KAVENEGAR_CONFIG(KAVENEGAR_MSVC, >= 1400)
#pragma warning(push)
#pragma warning(disable: 4996) // std::equal function call with parameters that may be unsafe
#endif

#ifdef __cplusplus
	extern "C";
#endif

/* Better than calling whole std */
using std::string;
using std::vector;
using std::stringstream;
using std::cout;
using std::endl;
using std::boolalpha;

#define OPERATION_SUCCESS 0
#define OPERATION_FAILD	1

#define POST 1
#define GET 0

typedef unsigned __int8 UINT8; // 0 to 255

/* -------------------------------------------------------------------------- */
/*								Status by Reference							  */
/* -------------------------------------------------------------------------- */
#define KAVENEGAR_OK						200
#define KAVENEGAR_INCOMPLETE_PARAMETERS		400
#define KAVENEGAR_INVALID_USER_ACCOUNT		401
#define KAVENEGAR_ERROR						402
#define KAVENEGAR_AUTH_FAILD				403
#define KAVENEGAR_SERVER_NOT_RESPOND		409
#define KAVENEGAR_INVALID_RECEIVER			411
#define KAVENEGAR_INVALID_SENDER			412
#define KAVENEGAR_MESSAGE_ERROR				413
#define KAVENEGAR_RECORD_ERROR				414
#define KAVENEGAR_INVALID_TIME				417
#define KAVENEGAR_NOT_ENOUGH_CREDIT			418
#define KAVENEGAR_ERROR_LENGTH				419

/* -------------------------------------------------------------------------- */
/*									SMS Status								  */
/* -------------------------------------------------------------------------- */
#define KAVENEGARSMS_IN_QUEUE				1
#define KAVENEGARSMS_SCHEDULED				2
#define KAVENEGARSMS_SENT_TO_TELECOM		4
#define KAVENEGARSMS_SENT_TO_TELECOM_		5
#define KAVENEGARSMS_FAILD_TO_SEND			6
#define KAVENEGARSMS_DELIVERED				10
#define KAVENEGARSMS_DELIVERY_FAILD			11
#define KAVENEGARSMS_CANCEL					13
#define KAVENEGARSMS_BLOCKED				14
#define KAVENEGARSMS_INVALID_SMS_ID			100

/* -------------------------------------------------------------------------- */
/*									SMS Types								  */
/* -------------------------------------------------------------------------- */
#define ST_DIRECT_NO_SAVE					0
#define ST_NORMAL							1
#define ST_SMS_WITH_SAVE					2
#define ST_CUSTOM_APP_SAVE					3

/* -------------------------------------------------------------------------- */
/*									Maximum Length							  */
/* -------------------------------------------------------------------------- */
#define MAX_EN_SMS_LENGTH					612
#define MAX_FA_SMS_LENGTH					268

#define VERIFY_LOOKUP_TYPE_SMS 0
#define VERIFY_LOOKUP_TYPE_CALL 1

//
// prototype
//

typedef struct _HANDLE_HTTP_REQUEST
{
	LPCSTR urlAddress;
	LPCSTR majorVersion;
	LPCSTR minorVersion;
	LPCSTR apiKey;
	LPCSTR sendPath;
	LPCSTR receptor;
	LPCSTR sender;
	LPCWSTR message;
	DWORD date;
	UINT8 type;
} HANDLE_HTTP_REQUEST;

struct SMS_STATUS_INFORMATION
{
	DWORD	dwSMSInfoSize;
	DWORD	dwMessageId; // Unique message id
	DWORD	dwMessage; // message text
	DWORD	dwStatus; // Message status
	LPCSTR	lpStatusContext; // Message context
	LPCSTR	lpSender; // Sender number
	LPCSTR	lpReceptor; // Receptor number
	DWORD	dwDate; // The time of sending sms (UnixDate format)
	DWORD	dwCost; // Cost of the sms
};

typedef struct
{
	DWORD dwMessageId;
	DWORD dwLocalId;
	DWORD dwStatus;
	LPCSTR lpStatusText;
} SMS_GET_STATUS_INFORMATION;

typedef struct
{
	DWORD dwStartDate;
	DWORD dwEndDate;
	DWORD dwSumpart;
	DWORD dwSumCount;
	DWORD dwCost;
} SMS_SEND_LIST;

typedef struct
{
	DWORD dwMessageId;
	DWORD dwStatus;
	LPCSTR lpStatusText;
} SMS_CANCEL_REQUEST;

typedef struct
{
	DWORD dwStartDate;
	DWORD dwEndDate;
	DWORD dwSumCount;
} SMS_COUNT_OF_SMS_RECEIVES;

typedef struct
{
	LPCSTR lpSection;
	DWORD dwValue;
} GET_COUNT_OF_RECEIVERS;

typedef struct
{
	DWORD dwRemainCredit;
	DWORD dwExpireDate;
	DWORD dwType;
} GET_ACCOUNT_INFO;

typedef struct
{
	LPCSTR lpAPILogs;
	LPCSTR lpDailyReport;
	LPCSTR lpDebugMode;
	LPCSTR lpDefaultSender;
	DWORD dwMinCreditWarning;
	LPCSTR lpResendFaild;
} GET_ACCOUNT_OPTIONS;

/* -------------------------------------------------------------------------- */
namespace kavenegar
{
	class CKavenegarAPI
	{
	public:
		static KAVENEGAR_MAPI int SMSSendRequest(
			_In_ LPCSTR lpAPIKEY,
			_In_ LPCSTR lpSender,
			_In_ LPCWSTR lpMessage,
			_In_ vector<LPCSTR> lpReceptors,
			_In_ DWORD dwUnixDate,
			_In_ UINT8 uType,
			_Out_ DWORD &dwContext
		);

		static KAVENEGAR_MAPI void SMSSendBatchRequest(
			_In_ LPCSTR lpAPIKEY,
			_In_ LPCSTR lpSender,
			_In_ LPCSTR lpMessage,
			_In_ vector<LPCSTR> lpReceptor,
			_In_ DWORD dwUnixDate,
			_In_ UINT8 uType,
			_Out_ DWORD &dwContext
		);

		static KAVENEGAR_MAPI int SMSSendRequestByPostalCode(
			_In_ LPCSTR lpAPIKEY,
			_In_ DWORD dwPostalCode,
			_In_ LPCSTR lpMessage,
			_In_ DWORD dwMCIStartIndex,
			_In_ DWORD dwMCICount,
			_In_ DWORD dwMTNStartIndex,
			_In_ DWORD dwMTNCount,
			_In_ DWORD dwDate,
			_Out_ DWORD &dwContext
		);

		static KAVENEGAR_MAPI int SMSGetStatus(
			_In_ LPCSTR lpAPIKEY,
			_In_ vector<LPCSTR>& dwMessageIds,
			_Out_ std::string &lpEntries
		);

		static KAVENEGAR_MAPI void SMSGetStatusByLocalId(
			_In_ DWORD dwLocalId
		);

		static KAVENEGAR_MAPI void SMSReadData(
			_In_ DWORD dwMessageId
		);

		static KAVENEGAR_MAPI void SMSQuerySendList(
			_In_ DWORD dwStartDate,
			_In_ DWORD dwEndDate,
			_In_ LPCSTR lpSender
		);

		static KAVENEGAR_MAPI void SMSGetLastSend(
			_In_ DWORD dwPageSize,
			_In_ LPCSTR lpSender
		);

		static KAVENEGAR_MAPI void SMSQueryCountOfSends(
			_In_ DWORD dwStatusText,
			_In_ DWORD dwEndDate,
			_In_ DWORD dwStatus
		);

		static KAVENEGAR_MAPI void SMSCancelRequest(
			_In_ DWORD dwMessageId
		);

		static KAVENEGAR_MAPI void SMSReadReceives(
			_In_ LPCSTR lpLineNumber,
			_In_ BOOL bIsRead
		);

		static KAVENEGAR_MAPI void SMSQueryCountOfReceives(
			_In_ DWORD dwStartDate,
			_In_ DWORD dwEndDate,
			_In_ LPCSTR lpLineNumber,
			_In_ BOOL bIsRead
		);

		static KAVENEGAR_MAPI void GetReceiversByPostalCode(
			_In_ DWORD dwPostalCode
		);

		static KAVENEGAR_MAPI void SMSVerificationRequest(
			_In_ LPCSTR lpReceptor,
			_In_ LPCSTR lpToken,
			_In_ LPCSTR lpToken2,
			_In_ LPCSTR lpToken3,
			_In_ LPCSTR lpTemplate,
			_In_ LPCSTR lpType
		);

		static KAVENEGAR_MAPI void TTSSendRequest(
			_In_ LPCSTR lpReceptor,
			_In_ LPCSTR lpMessage,
			_In_ DWORD dwDate,
			_In_ LPCSTR lpLocalId
		);

		static KAVENEGAR_MAPI void GetAccountInfo(void);

		static KAVENEGAR_MAPI void SetAccountOption(
			_In_ LPCSTR lpAPILogs,
			_In_ LPCSTR lpDailyReport,
			_In_ LPCSTR lpDebugMode,
			_In_ LPCSTR lpDefaultSender,
			_In_ DWORD dwMinCreditWarning,
			_In_ LPCSTR lpResendFaild
		);

		static KAVENEGAR_MAPI string HttpRequest(
			_In_ int Method,
			_In_ LPCSTR Host,
			_In_ LPCSTR url,
			_In_ LPCSTR header,
			_In_ LPSTR data
		);

		static KAVENEGAR_MAPI VOID SetErrorDetail(
			_In_ DWORD dwErrMessage
		);

		static KAVENEGAR_MAPI string GetErrorDetail(VOID);

		static KAVENEGAR_MAPI DWORD SMSCheckStatus(
			_In_ DWORD dwStatusCode
		);

		static KAVENEGAR_MAPI DWORD CheckSMSStatusInfo(
			_In_ DWORD dwStatusCode
		);
	};
} /* namespace kavenegar */

#if KAVENEGAR_CONFIG(KAVENEGAR_MSVC, >= 1400)
#pragma warning (pop)
#endif

#endif // !__KAVENEGAR_MAPI__