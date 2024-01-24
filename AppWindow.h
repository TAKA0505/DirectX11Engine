#pragma once
#include "Window.h"
#include "Graphics.h"
#include "SwapChain.h"

class AppWindow : public Window
{
public:
	AppWindow();
	~AppWindow();
	// ͨ�� Window �̳�
	void onCreate() override;
	void onUpdate() override;
	void onDestroy() override;
private:
	//not IDXGI_SWAP_CHAIN
	SwapChain *p_swap_chain;
};

