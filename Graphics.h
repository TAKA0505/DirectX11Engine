#pragma once
#include <d3d11.h>

#pragma comment(lib,"d3d11.lib")


class SwapChain;

class Graphics
{
public:
	Graphics();
	//initialize the GraphicsEngine and DirectX 11 Device
	bool init();
	//release the resourse
	bool release();
	~Graphics();

public:
	static Graphics* Get();
	SwapChain *createSwapChain();
private:
	ID3D11Device	*p_device = nullptr;
	D3D_FEATURE_LEVEL *p_feature = nullptr;
	ID3D11DeviceContext *p_context = nullptr;
	IDXGIDevice *p_dxgi_device = nullptr;
	IDXGIAdapter *p_dxgi_adapter = nullptr;
	IDXGIFactory * p_dxgi_factory = nullptr;
private:
	friend class SwapChain;
};

