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