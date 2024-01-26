#include "AppWindow.h"

AppWindow::AppWindow()
{
}

AppWindow::~AppWindow()
{
}

void AppWindow::onCreate()
{
	Window::onCreate();
	Graphics::Get()->init();
	//not IDXGI_SWAP_CHAIN
	p_swap_chain = Graphics::Get()->createSwapChain();

	RECT rect = getClientWindowRect();
	p_swap_chain->init(this->m_hwnd, rect.right - rect.left, rect.bottom - rect.top);
}

void AppWindow::onUpdate()
{
	Window::onUpdate();
	float color[4] = { 0,1.f,0,1.f };
	Graphics::Get()->getDeviceContext()->clearRenderTargetColor4f(p_swap_chain, color);
	p_swap_chain->present(false);
}

void AppWindow::onDestroy()
{
	Window::onDestroy();
	Graphics::Get()->release();
	//not IDXGI_SWAP_CHAIN
	p_swap_chain->release();
}
