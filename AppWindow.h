#pragma once
#include "Window.h"
#include "Graphics.h"

class AppWindow : public Window
{
public:
	AppWindow();
	~AppWindow();
	// ͨ�� Window �̳�
	void onCreate() override;
	void onUpdate() override;
	void onDestroy() override;
};

