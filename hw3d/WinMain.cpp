#include <Windows.h>

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) 
{
	switch (msg)
	{
	case WM_CLOSE:
		PostQuitMessage(69);
		break;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}


//вызов окна
int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstans,
	LPSTR    lpCmdLine,
	int      nShowCmd)
{    //константы
	const auto pClassName = L"ClassNameHere";
	// регистрация класса окна и какое оно и т.д
	WNDCLASSEX wc = { 0 };
	wc.cbSize = sizeof( wc );
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = nullptr;
	wc.hCursor = nullptr;
	wc.hbrBackground = nullptr;
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = pClassName;
	wc.hIconSm = nullptr;
	RegisterClassEx( &wc );
	// связано с рг окна
	HWND hWnd = CreateWindowEx(
		0, pClassName,
		//название
		L"this programm isnt eazy",
		//размеры
		WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
		200, 200, 640, 480,
		nullptr, nullptr, hInstance, nullptr
	);
	//показ окна
	ShowWindow(hWnd, SW_SHOW);
	//функции (т.к чтоб не было овощем прога)
	MSG msg;
	BOOL gResult;
	while( (gResult = GetMessage( &msg,nullptr,0,0 )) > 0 )
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	
	if (gResult == -1) 
	{
		return -1;
	}
	else 
	{
		return msg.wParam;
	}

	return 0;
}



