#include "SwapChain.h"
#include "Graphics.h"


SwapChain::SwapChain()
{
}

bool SwapChain::init(HWND hWnd, UINT width, UINT height)
{
    IDXGIDevice *device = Graphics::Get()->p_dxgi_device;

    DXGI_SWAP_CHAIN_DESC desc;
    ZeroMemory(&desc, sizeof(DXGI_SWAP_CHAIN_DESC));

    desc.BufferCount = 1;
    desc.BufferDesc.Width = width;
    desc.BufferDesc.Height = height;
    desc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    desc.BufferDesc.RefreshRate.Numerator = 60;
    desc.BufferDesc.RefreshRate.Denominator = 1;
    desc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    desc.OutputWindow = hWnd;
    desc.SampleDesc.Count = 1;
    desc.SampleDesc.Quality = 0;
    desc.Windowed = TRUE;

    HRESULT hr = Graphics::Get()->p_dxgi_factory->CreateSwapChain(device,&desc,&p_swap_chain);

    if (FAILED(hr))
        return false;

    return true;
}

bool SwapChain::release()
{
    p_swap_chain->Release();
    delete this;
    return true;
}

SwapChain::~SwapChain()
{
}
