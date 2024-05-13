#include "Renderer.hpp"
#include "Logger.hpp"


VulkanRenderer::VulkanRenderer() :
    m_instance(VK_NULL_HANDLE),
    m_debugMessenger(VK_NULL_HANDLE),
    m_physicalDevice(VK_NULL_HANDLE),
    m_logicalDevice(VK_NULL_HANDLE),
    m_surface(VK_NULL_HANDLE)
{

}

VulkanRenderer::~VulkanRenderer()
{
    LOG("\tDestroying Vulkan Renderer");
}

bool VulkanRenderer::Init()  
{
    bool ret = false;
    init_vulkan();
    init_swapchain();
    init_commands();
    init_sync();

    ret = true;
    return ret;
}

void VulkanRenderer::Render() 
{
    LOG("VULKANRENDERER");
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


