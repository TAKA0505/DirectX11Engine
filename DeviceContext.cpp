#include "DeviceContext.h"
#include "SwapChain.h"

DeviceContext::DeviceContext(ID3D11DeviceContext* p_device_context)
	: p_device_context(p_device_context)
{
}

DeviceContext::~DeviceContext()
{
}

bool DeviceContext::release()
{
	p_device_context->Release();
	delete this;
	return true;
}

bool DeviceContext::clearRenderTargetColor4f(SwapChain* swap_chain,float* color)
{
	p_device_context->ClearRenderTargetView(swap_chain->p_render_target_view,color);
	return true;
}
