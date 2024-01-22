#pragma once
#include <Windows.h>

class Window
{
public:
	Window() = default;
	//initialize the window
	bool init();
	bool broadcast();
	//release the window
	bool release();
	bool isRun();
	~Window() = default;

	//Events
	virtual void onCreate();
	virtual void onUpdate();
	virtual void onDestroy();
protected:
	HWND m_hwnd;
	bool m_is_run;
};

