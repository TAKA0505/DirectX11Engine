#pragma once
#include <Windows.h>

class Window
{
public:
	Window();
	//initialize the window
	bool init();
	bool broadcast();
	//release the window
	bool release();
	bool isRun();

	RECT getClientWindowRect();
	void setHWND(HWND hWnd);

	//Events
	virtual void onCreate();
	virtual void onUpdate();
	virtual void onDestroy();

	~Window();
protected:
	HWND m_hwnd;
	bool m_is_run;
};

