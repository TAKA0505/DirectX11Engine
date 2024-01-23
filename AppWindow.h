#pragma once
#include "Window.h"
#include "Graphics.h"

class AppWindow : public Window
{
public:
	AppWindow();
	~AppWindow();
	// Í¨¹ý Window ¼Ì³Ð
	void onCreate() override;
	void onUpdate() override;
	void onDestroy() override;
};

