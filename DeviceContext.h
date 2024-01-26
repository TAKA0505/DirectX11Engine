#pragma once
#include <d3d11.h>

class SwapChain;

class DeviceContext
{
public:
	DeviceContext(ID3D11DeviceContext *p_device_context);
	~DeviceContext();

	bool release();
	bool clearRenderTargetColor4f(SwapChain *swap_chain,float *color);
private:
	ID3D11DeviceContext *p_device_context;
};

