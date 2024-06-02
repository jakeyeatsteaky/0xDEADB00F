#include "Renderer.hpp"
#include "Logger.hpp"

#include <chrono>
#include <thread>


VulkanRenderer::VulkanRenderer(uint32_t width, uint32_t height) :
    m_instance(VK_NULL_HANDLE),
    m_debugMessenger(VK_NULL_HANDLE),
    m_physicalDevice(VK_NULL_HANDLE),
    m_logicalDevice(VK_NULL_HANDLE),
    m_surface(VK_NULL_HANDLE),
    m_windowExtent({width, height }), 
    m_frameNumber(0),
    m_initialized(false),
    stop_rendering(false)
{

}

VulkanRenderer::~VulkanRenderer()
{
    LOG("\tDestroying Vulkan Renderer");
}

bool VulkanRenderer::Init()  
{
    // only one instance for now -- make this a singleton eventually?
    if(true == m_initialized) {
        Logger::Err("Only one instance of the vulkan engine is allowed");
        m_initialized = false;
        return m_initialized;
    }

    init_vulkan();
    init_swapchain();
    init_commands();
    init_sync();

    m_initialized = true;
    return m_initialized;
}

void VulkanRenderer::Render() 
{
    if(stop_rendering) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        return;
    }

    // Any steps need to happen before the draw call?

    // draw
    Draw();

}

void VulkanRenderer::toggle_render(bool toggle)
{
    if(toggle)
        LOG("Conserving CPU by putting the Render loop to sleep");
    else
        LOG("Drawing");
    stop_rendering = toggle;
}

void VulkanRenderer::Draw()
{
    
}

void VulkanRenderer::init_vulkan()
{
    vkb::InstanceBuilder builder;
    auto inst_ret = builder.set_app_name("Vulkan Renderer")
                    .request_validation_layers(bUseValidationLayers)
                    .use_default_debug_messenger()
                    .require_api_version(1,3,0)
                    .build();
    
    // vkbInstanceBuilder just creates boilerplate for vkinstance
    vkb::Instance vkb_instance = inst_ret.value();

    // assign instance from vk builder to VulkanRenderer VkInstance
    m_instance = vkb_instance.instance;
    m_debugMessenger = vkb_instance.debug_messenger;

    // vk bulder instance is destroyed when exiting scope
}

void VulkanRenderer::init_swapchain()
{

}

void VulkanRenderer::init_commands()
{

}

void VulkanRenderer::init_sync()
{

}



//////////////////////////////////////////////////////////////////////
//                                                                  //
//                          SDL RENDERER                            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

SDLRenderer::SDLRenderer(uint32_t windowWidth, uint32_t windowHeight, SDL_Window& window) :
    m_rendererInstance(nullptr, SDL_DestroyRenderer),
    m_SDLWindow(window)
{
    LOG("Creating SDL Renderer object");
}

SDLRenderer::~SDLRenderer()
{
    LOG("\tDestroying SDL Renderer");
}

bool SDLRenderer::Init()
{
    bool ret = false;
    SDL_Window* win = &m_SDLWindow;
    SDL_Renderer* renderer = nullptr;

    if (win)
        renderer = SDL_CreateRenderer(win, 0, SDL_RENDERER_ACCELERATED);

    if (!renderer) {
        ERR("Failed to create SDL Renderer object", SDL_GetError());
        return ret;
    }

    m_rendererInstance.reset(renderer);
    ret = true;
    return ret;
}

void SDLRenderer::Render()
{
    SDL_SetRenderDrawColor(m_rendererInstance.get(), 0xFF, 0, 0xFF, 255);
    SDL_RenderClear(m_rendererInstance.get());
    
    RenderGameObjects();

    SDL_RenderPresent(m_rendererInstance.get());
}

void SDLRenderer::AddRenderObject(RenderData object)
{
    m_renderObjects.push_back(object);
}

void SDLRenderer::UpdateRenderObject(size_t idx, RenderData newData)
{
    m_renderObjects.at(idx).colorData = newData.colorData;
    m_renderObjects.at(idx).positionData = newData.positionData;
}

void SDLRenderer::RenderGameObjects() const
{
    uint32_t DEFAULT_RECT_SIZE = 200;

    for (size_t i = 0; i < m_renderObjects.size(); i++) {
        RenderData data = m_renderObjects.at(i);
        uint32_t RED = data.colorData.r;
        uint32_t GREEN = data.colorData.g;
        uint32_t BLUE = data.colorData.b;
        uint32_t ALPHA = data.colorData.a;

        SDL_SetRenderDrawColor(m_rendererInstance.get(), RED, GREEN, BLUE, ALPHA);
        SDL_Rect fillRect = { data.positionData.x, data.positionData.y, DEFAULT_RECT_SIZE, DEFAULT_RECT_SIZE };

        SDL_RenderFillRect(m_rendererInstance.get(), &fillRect);
    }
}

