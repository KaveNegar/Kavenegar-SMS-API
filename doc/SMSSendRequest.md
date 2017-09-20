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
