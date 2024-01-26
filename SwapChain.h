#pragma once
#include <d3d11.h>

class DeviceContext;

class SwapChain
{
public:
	SwapChain();
	bool init(HWND hWnd,UINT width,UINT height);
	bool release();
	bool present(bool vsync);
	~SwapChain();
private:
	IDXGISwapChain *p_swap_chain = nullptr;
	ID3D11RenderTargetView *p_render_target_view = nullptr;

private:
	friend class DeviceContext;
};

