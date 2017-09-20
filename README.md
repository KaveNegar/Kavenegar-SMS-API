# kavenegar-cpp
## Installation :
### Step 1:
1. Open Your Visual Studio solution and Go to Properties page (Right-click on project name and last bottom list select properties).
2. At very top of the window select **Configuration** to "All Configurations" and **Platform** to "All Platforms".
3. Under Configuration Properties drop down list select **C/C++ -> General -> Additional Include Directories** and Enter your KaveNegar C++ include directory.
4. Go to Linker drop down list and Select **General -> Additional Library Directories** and Enter your KaveNegar C++ Lib directory.
5. Under Linker drop down list Select **Input -> Additional Dependencies** and Type **Kavenegar.lib** for the dependency.

**Notice**: If you get Error of any type of WinInet header file, Just add** WinInet.lib** in **Input -> Additional Dependencies**,
Or simply add **#pragma comment (lib, "Wininet.lib")** in your source file. 


### Step 2 :
1. Add **#include "kavenegar-api.h"** in your source.
2. Add **using namespace kavenegar** in your source for using KaveNegar namespace including classes.
3. Use code below that simply implement and shows how it works:
```c++
DWORD dwResult = 0;
CKavenegarAPI* kvng = new CKavenegarAPI;
vector "LPCSTR" recpectors { "number1", "number2", etc.. };

int res = kvng->SendSMSbyAPIKEY("YOUR APIKEY", "SENDER", "MESSAGE", recpectors, NULL, NULL, dwResult);
if(!res) {
if(dwResult != KAVENEGAR_OK)
{
std::cout << "Messages has been sent.";
} 
else{
std::cout << kvng->GetErrorDetail(); 
} 
}
```
**Notice** : Replace < > instead of " " between string tag. 

### Step 3:
1. Build your Project and Run it. It will send a Text message to recpector.
2. See other pages for more help. Play with SDK and Enjoy!
Happy Coding... :)


# SMSSendRequest function 

Sends the specified SMS request to the HTTP server by getting user API-KEY.
### Syntax 
```c++
int SMSSendRequest(
   _In_  LPCSTR   lpAPIKEY,
   _In_  LPCSTR   lpSender,
   _In_  LPCWSTR  lpMessage,
   _In_  vector   lpReceptors,
   _In_  DWORD    dwUnixDate,
   _In_  UINT8    uType,
   _Out_ DWORD    dwContext
);
```
### Parameters 
```lpAPIKEY [in]``` 
A string you got from user panel. 

```lpSender [in] ```
A string specified sender number. 

```lpMessage [in] ```
A string for your message to sent. 

```lpReceptors [in] ```
A vector string to your receptors. 

```dwUnixDate [in] ```
A long date number specified a Date/Time to send. 

```uType [in] ```
A int number that specified type of message to send. 

```dwContext [out] ```
A int number of result of message. if message success, return 200,
otherwise return KAVENEGAR_ERROR that you can get the exact error type by calling ()[] 


### Return value 

Returns  0 if successful, or 1 otherwise. 


This function needs: 
|  -  |  -   |
| ------------- | ------------- |
| Header  | kavenegar-api.h |
|Library  | Kavenegar.lib  |
| DLL  | Kavenegar.dll  |


# SMSGetStatus function 

Sends the specified SMS request to the HTTP server by getting user API-KEY.
### Syntax 
```c++
int SMSGetStatus(
   _In_  LPCSTR      lpAPIKEY,
   _In_  vector&     dwMessageIds,
   _Out_ std::string &lpEntries
);
```
### Parameters 

```lpAPIKEY [in] ```
A string you got from user panel. 

```dwMessageIds [in] ```
A string specified sender number. 

```lpEntries [out] ```
A string that contains message ids, status code and status text 


### Return value 

Returns ```0``` if successful, or ```1``` otherwise. 


This function needs: 
|  -  |  -   |
| ------------- | ------------- |
| Header  | kavenegar-api.h |
|Library  | Kavenegar.lib  |
| DLL  | Kavenegar.dll  |

# GetErrorDetails function 
Gets the last error has been occured by web server.
### Syntax 
```c++
string GetErrorDetail(VOID);
````

### Parameters 

This function has no parameters (void). 


### Return value 

Returns a string of the last error. 


This function needs: 
|  -  |  -   |
| ------------- | ------------- |
| Header  | kavenegar-api.h |
|Library  | Kavenegar.lib  |
| DLL  | Kavenegar.dll  |

## Contribution



