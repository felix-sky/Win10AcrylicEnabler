# Win10AcrylicEnabler
A DLL that use windows api to enable the blur effect on windows10

# How to use

## Use the DLL

```
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
```

## Use the header file instead
```
//main.cpp
  #include "xblur.h"
  #include"xmagic.h"

void blurer(HWND ptr,INT radius) {
	HMODULE hMod = LoadLibrary(L"user32.dll");
	pfnGWA getWindowAttribute = (pfnGWA)GetProcAddress(hMod, "GetWindowCompositionAttribute");
	
	HWND hwndCon = HWND(ptr); 
	

	if (hMod) {
		pfnSetWindowCompositionAttribute setWindowCompositionAttribute = (pfnSetWindowCompositionAttribute)GetProcAddress(hMod, "SetWindowCompositionAttribute");
		if (setWindowCompositionAttribute)
		{
			ACCENT_POLICY accent = { ACCENT_ENABLE_ACRYLICBLURBEHIND, 0, radius, 0 };
			WINDOWCOMPOSITIONATTRIBDATA data;
			data.Attrib = WCA_ACCENT_POLICY;
			data.pvData = &accent;
			data.cbData = sizeof(accent);
			setWindowCompositionAttribute(hwndCon, &data);
		}
	}
}

int main()
{
	HWND w = FindWindow(NULL, _T("CommandLine")); // target window
  	INT radius = 24; // a number you like
	blurer(w,radius);
	
	return 0;
}
```

# Samples
![image](https://github.com/felix-sky/Win10AcrylicEnabler/blob/master/images/0.jpg)
