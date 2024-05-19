#ifndef RENDERER_HPP
#define RENDERER_HPP
#include"RenderingEngine.hpp"
#include <vulkan/vulkan.h>

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
    void Draw();

    void toggle_render(bool toggle);
};

#endif // end renderer hpp
