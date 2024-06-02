#ifndef RENDERER_HPP
#define RENDERER_HPP
#include"RenderingEngine.hpp"
#include <memory>
#include <vulkan/vulkan.h>
#include <SDL_render.h>

#include "VkBootstrap.h"


constexpr bool bUseValidationLayers = true;

class VulkanRenderer : public RenderingEngine
{
private:
    VkInstance m_instance;
    VkDebugUtilsMessengerEXT m_debugMessenger;
    VkPhysicalDevice m_physicalDevice;
    VkDevice m_logicalDevice;
    VkSurfaceKHR m_surface;

    VkExtent2D m_windowExtent;
    int m_frameNumber;
    bool m_initialized;
    bool stop_rendering;
    

    void init_vulkan();
    void init_swapchain();
    void init_commands();
    void init_sync();

public:
    VulkanRenderer(uint32_t windowWidth, uint32_t windowHeight);
    ~VulkanRenderer() override;
    bool Init() override;
    void Render() override; 
    void AddRenderObject(RenderData /*object*/)override {};
    void UpdateRenderObject(size_t /*idx*/, RenderData /*newData*/) override {};
    void Draw();

    void toggle_render(bool toggle);
};

class SDLRenderer : public RenderingEngine
{
private:
    std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> m_rendererInstance;
    SDL_Window& m_SDLWindow;
    std::vector<RenderData> m_renderObjects;
public:
    SDLRenderer(uint32_t windowWidth, uint32_t windowHeight, SDL_Window& window);
    ~SDLRenderer() override;
    bool Init() override;
    void Render() override;
    void AddRenderObject(RenderData object) override;
    void UpdateRenderObject(size_t idx, RenderData newData) override;
    void RenderGameObjects() const;
};

#endif // end renderer hpp
