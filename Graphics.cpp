#include "Graphics.h"

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
                &p_context);

        if (SUCCEEDED(hr))
            break;
    }

    if (FAILED(hr))
        return false;

    return true;
}

bool Graphics::release()
{
    p_device->Release();
    p_context->Release();
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
