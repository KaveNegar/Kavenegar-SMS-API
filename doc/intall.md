## Step 1: 
1. Open Your Visual Studio solution and Go to Properties page (Right-click on project name and last bottom list select properties).
2. At very top of the window select Configuration to ```All Configurations``` and Platform to ```All Platforms```.
3. Under Configuration Properties drop down list select ```C/C++``` -> ```General``` -> ```Additional Include Directories``` and Enter your ```KaveNegar C++ include directory```.
4. Go to Linker drop down list and Select ```General``` -> ```Additional Library Directories``` and Enter your ```KaveNegar C++ Lib directory```.
5. Under Linker drop down list Select ```Input``` -> ```Additional Dependencies``` and Type ```Kavenegar.lib``` for the dependency.
Notice: If you get Error of any type of WinInet header file, Just add ```WinInet.lib ```in ```Input``` -> ```Additional Dependencies``` ,
Or simply add ```#pragma comment (lib, "Wininet.lib")``` in your source file. 

## Step 2:
1. Add ```#include "kavenegar-api.h"``` in your source.
2. Add using namespace ```kavenegar``` in your source for using KaveNegar namespace including classes.
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
Notice: Replace``` < > ``` instead of ``` " "``` between string tag. 

## Step 3:
1. Build your Project and Run it. It will send a Text message to recpector.
2. See other pages for more help. Play with SDK and Enjoy!
Happy Coding... :)