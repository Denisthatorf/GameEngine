#pragma once
#include <string>
#include <vector>

#include <vulkan/vulkan.h>

namespace Engine
{
    struct RendererSettings {
        std::string ApplicationName;
    };

    class Renderer {
    public:
        void Init(RendererSettings settings);
        void Shutdown();
        void RenderFrame();

    private:
        void initCore();
        void createSwapchain();
        void createCommands();
        void createDefaultRenderPass();
        void createFramebuffers();
        void createSyncStructures();

    private:
        uint64_t m_frameNumber{ 0 };
        RendererSettings m_rendererSettings{};

        //CORE VULKAN
        VkInstance m_instance;
        VkDebugUtilsMessengerEXT m_debugMessenger;
        VkPhysicalDevice m_physicalDevice; 
        VkDevice m_logicalDevice; 
        VkSurfaceKHR m_surface;

        //SWAPCHAIN
        VkSwapchainKHR m_swapchain;
        VkFormat m_swapchainImageFormat;
        std::vector<VkImage> m_swapchainImages;
        std::vector<VkImageView> m_swapchainImageViews;
        VkExtent2D m_windowExtent;

        //COMMAND POOLS AND QUEUES
        VkQueue m_graphicsQueue;
        uint32_t m_graphicsQueueFamily;

        VkCommandPool m_commandPool;
        VkCommandBuffer m_mainCommandBuffer;

        //RENDER PASSES
        VkRenderPass m_renderPass;
        std::vector<VkFramebuffer> m_framebuffers{ 3 };

        //SYNCHRONIZATION OBJECTS
        VkSemaphore m_presentSemaphore, m_renderSemaphore;
        VkFence m_renderFence;
    };
}
