#pragma once
#include <d3d11.h>

#pragma comment(lib,"d3d11.lib")

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
private:
	ID3D11Device	*p_device = nullptr;
	D3D_FEATURE_LEVEL *p_feature = nullptr;
	ID3D11DeviceContext *p_context = nullptr;
};

