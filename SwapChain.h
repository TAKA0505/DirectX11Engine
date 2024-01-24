#pragma once
#include <d3d11.h>

class SwapChain
{
public:
	SwapChain();
	bool init(HWND hWnd,UINT width,UINT height);
	bool release();
	~SwapChain();
private:
	IDXGISwapChain *p_swap_chain = nullptr;
};

