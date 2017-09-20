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

