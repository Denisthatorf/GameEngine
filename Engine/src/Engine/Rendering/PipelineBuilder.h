#pragma once
#include <vector>

#include "vulkan/vulkan.h"

namespace Engine 
{
    class VulkanPipelineBuilder {
    public:
        std::vector<VkPipelineShaderStageCreateInfo> shaderStages;
        VkPipelineVertexInputStateCreateInfo vertexInputInfo;
        VkPipelineInputAssemblyStateCreateInfo inputAssembly;
        VkViewport viewport;
        VkRect2D scissor;

        VkPipelineRasterizationStateCreateInfo rasterizer;
        VkPipelineColorBlendAttachmentState colorBlendAttachment;
        VkPipelineMultisampleStateCreateInfo multisampling;
        VkPipelineLayout pipelineLayout;

        VkPipeline BuildPipeline(VkDevice device, VkRenderPass pass);
    };
}
