#ifndef RENDERER_HPP
#define RENDERER_HPP
#include "VkBootstrap.h"
#include "RenderingEngine.hpp"

constexpr bool bUseValidationLayers = true;

class VulkanRenderer : public RenderingEngine
{
private:
    VkInstance m_instance;
    VkDebugUtilsMessengerEXT m_debugMessenger;
    VkPhysicalDevice m_physicalDevice;
    VkDevice m_logicalDevice;
    VkSurfaceKHR m_surface;
    

    void init_vulkan();
    void init_swapchain();
    void init_commands();
    void init_sync();

public:
    VulkanRenderer();
    ~VulkanRenderer() override;
    bool Init() override;
    void Render() override;
};

#endif // end renderer hpp
