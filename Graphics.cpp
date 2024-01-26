#include "Graphics.h"
#include "SwapChain.h"
#include "DeviceContext.h"

Graphics::Graphics()
{
}

bool Graphics::init()
{
    D3D_DRIVER_TYPE driver_type[] =
    {
        D3D_DRIVER_TYPE_HARDWARE,
        D3D_DRIVER_TYPE_WARP,
        D3D_DRIVER_TYPE_REFERENCE
    };

    UINT driver_size = ARRAYSIZE(driver_type);

    D3D_FEATURE_LEVEL feature_levels[] =
    {
        D3D_FEATURE_LEVEL_11_0
    };

    UINT feature_size = ARRAYSIZE(feature_levels);

    HRESULT hr = 0;
    ID3D11DeviceContext *m_imm_context;
    for (UINT index = 0; index < driver_size; index++)
    {
        hr = D3D11CreateDevice(NULL,
                driver_type[index],
                NULL,
                NULL,
                feature_levels,
                feature_size,
                D3D11_SDK_VERSION,
                &p_device,p_feature,
                &m_imm_context);

        if (SUCCEEDED(hr))
            break;
    }

    if (FAILED(hr))
        return false;

     p_device_context = new DeviceContext(m_imm_context);

    p_device->QueryInterface(__uuidof(IDXGIDevice),reinterpret_cast<void**>(&p_dxgi_device));
    p_dxgi_device->GetParent(__uuidof(IDXGIAdapter), reinterpret_cast<void**>(&p_dxgi_adapter));
    p_dxgi_adapter->GetParent(__uuidof(IDXGIFactory), reinterpret_cast<void**>(&p_dxgi_factory));
    return true;
}

bool Graphics::release()
{
    p_device->Release();
    p_dxgi_device->Release();
    p_dxgi_adapter->Release();
    p_dxgi_factory->Release();
    p_device_context->release();
    return true;
}

Graphics::~Graphics()
{
}

Graphics* Graphics::Get()
{
    static Graphics engine;
    return &engine;
}

SwapChain* Graphics::createSwapChain()
{
    return new SwapChain();
}

DeviceContext* Graphics::getDeviceContext()
{
    return this->p_device_context;
}
