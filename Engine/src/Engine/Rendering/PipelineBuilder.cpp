#include "PipelineBuilder.h"
#include "../Log.h"

namespace Engine 
{
    VkPipeline VulkanPipelineBuilder::BuildPipeline(VkDevice device, VkRenderPass pass)
    {
        VkPipelineViewportStateCreateInfo viewportState{ VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO };
        viewportState.viewportCount = 1;
        viewportState.pViewports = &viewport;
        viewportState.scissorCount = 1;
        viewportState.pScissors = &scissor;

        VkPipelineColorBlendStateCreateInfo colorBlendStateCreateInfo{ VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO };
        colorBlendStateCreateInfo.logicOpEnable = VK_FALSE;
        colorBlendStateCreateInfo.logicOp = VK_LOGIC_OP_COPY;
        colorBlendStateCreateInfo.attachmentCount = 1;
        colorBlendStateCreateInfo.pAttachments = &colorBlendAttachment;

        VkGraphicsPipelineCreateInfo pipelineCreateInfo{ VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO };
        pipelineCreateInfo.stageCount = shaderStages.size();
        pipelineCreateInfo.pStages = shaderStages.data();
        pipelineCreateInfo.pVertexInputState = &vertexInputInfo;
        pipelineCreateInfo.pInputAssemblyState = &inputAssembly;
        pipelineCreateInfo.pViewportState = &viewportState;
        pipelineCreateInfo.pRasterizationState = &rasterizer;
        pipelineCreateInfo.pMultisampleState = &multisampling;
        pipelineCreateInfo.pColorBlendState = &colorBlendStateCreateInfo;
        pipelineCreateInfo.layout = pipelineLayout;
        pipelineCreateInfo.renderPass = pass;
        pipelineCreateInfo.subpass = 0;
        pipelineCreateInfo.basePipelineHandle = VK_NULL_HANDLE;

        VkPipeline newPipeline;

        if (vkCreateGraphicsPipelines(device, VK_NULL_HANDLE, 1, &pipelineCreateInfo, nullptr, &newPipeline) != VK_SUCCESS) {
            ENGINE_CORE_ERROR("Failed to create pipeline\n");
            return VK_NULL_HANDLE;
        }

        return newPipeline;
    }
}
