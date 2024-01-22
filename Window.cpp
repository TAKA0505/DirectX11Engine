#include "Window.h"

Window *window = nullptr;

LRESULT CALLBACK WndProc(HWND hwnd,UINT msg,WPARAM wparam,LPARAM lparam)
{
	switch (msg)
	{
	case WM_CREATE:
	{
		//event fired when the window is created
		window->onCreate();
		break;
	}
	case WM_DESTROY:
	{
		//event fired when the window is destroyed
		window->onDestroy();
		::PostQuitMessage(0);
		break;
	}
	default:
		DefWindowProc(hwnd, msg, wparam, lparam);
		break;
	}
	return NULL;
}

bool Window::init()
{
	WNDCLASSEX wc;
	wc.cbClsExtra = NULL;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbWndExtra = NULL;
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wc.hInstance = NULL;
	wc.lpszClassName = L"MyWindowClass";
	wc.lpszMenuName = L"";
	wc.style = NULL;
	wc.lpfnWndProc = &WndProc;

	//if register class is failed,return false
	if (!::RegisterClassEx(&wc))
		return false;

	if (!window)
		window = this;

	//creation of the window
	m_hwnd = ::CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, L"MyWindowClass", L"DirectX GameEngine", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1024, 768,
		NULL, NULL, NULL,NULL);

	//if the creation is failed return false
	if (!m_hwnd)
		return false;

	//show up window
	::ShowWindow(m_hwnd, SW_SHOW);
	::UpdateWindow(m_hwnd);

	//set the flag about if the window is running or not
	m_is_run = true;

	return true;
}

bool Window::broadcast()
{
	MSG msg;
	while (::PeekMessage(&msg,NULL,0,0,PM_REMOVE)>0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	
	window->onUpdate();

	Sleep(0);

	return true;
}

bool Window::release()
{
	if (::DestroyWindow(m_hwnd))
		return false;
	return true;
}

bool Window::isRun()
{
	return m_is_run;
}

void Window::onDestroy()
{
	m_is_run = false;
}
