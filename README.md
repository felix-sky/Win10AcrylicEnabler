# Win10AcrylicEnabler
A DLL that use windows api to enable the blur effect on windows10

# How to use

## Use the DLL

(```)
  typedef int(*MYFUNC)(HWND,INT);
  
  HWND w = FindWindow(NULL, _T("CommandLine")); // target window
  INT radius = 24; // a number you like
  
  HINSTANCE hModule = LoadLibrary(_T("XBlur.dll"));
  MYFUNC myfunc = (MYFUNC)GetProcAddress(hModule, "blurer");
  if (myfunc) int a = myfunc(w,radius);
	else
	{
		std::cout << "load failed";
	}
(```)

## Use the header file instead
(```)
  #include "xblur.h"
(```)
