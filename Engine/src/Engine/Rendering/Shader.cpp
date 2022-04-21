#include "Shader.h"
#include "Utilities.h"
#include "PipelineBuilder.h"
#include "VulkanInitializer.h"
#include "../Log.h"

namespace Engine 
{
    Shader::Shader(Renderer* renderer) : m_renderer(renderer) {}

    Shader::~Shader() {
        vkDestroyPipeline(m_renderer->m_logicalDevice, m_pipeline, nullptr);
        vkDestroyPipelineLayout(m_renderer->m_logicalDevice, m_pipelineLayout, nullptr);
    }

    void Shader::Bind() {
        vkCmdBindPipeline(m_renderer->m_mainCommandBuffer, VK_PIPELINE_BIND_POINT_GRAPHICS, m_pipeline);
    }

    void Shader::Load(const std::string&& vertexShader, const std::string&& fragmentShader) {
        VkShaderModule vertShader;
        if (!Utilities::LoadShaderModule(vertexShader, m_renderer->m_logicalDevice, vertShader)) {
            ENGINE_CORE_ERROR("Failed to load vertex shader module\n");
        }

        VkShaderModule fragShader;
        if (!Utilities::LoadShaderModule(fragmentShader, m_renderer->m_logicalDevice, fragShader)) {
            ENGINE_CORE_ERROR("Failed to load fragment shader module\n");
        }

        auto pipelineLayoutInfo = VulkanInitializers::PipelineLayoutCreateInfo();
        VK_CHECK(vkCreatePipelineLayout(m_renderer->m_logicalDevice, &pipelineLayoutInfo, nullptr, &m_pipelineLayout));

        VulkanPipelineBuilder pipelineBuilder;
        pipelineBuilder.shaderStages.push_back(
            VulkanInitializers::PipelineShaderStageCreateInfo(VK_SHADER_STAGE_VERTEX_BIT, vertShader));
        pipelineBuilder.shaderStages.push_back(
            VulkanInitializers::PipelineShaderStageCreateInfo(VK_SHADER_STAGE_FRAGMENT_BIT, fragShader));

        pipelineBuilder.vertexInputInfo = VulkanInitializers::PipelineVertexInputStateCreateInfo();
        pipelineBuilder.inputAssembly = VulkanInitializers::PipelineInputAssemblyStateCreateInfo(VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST);

        // build the viewport
        pipelineBuilder.viewport = {
                .x = 0.f,
                .y = 0.f,
                .width = static_cast<float>(m_renderer->m_windowExtent.width),
                .height = static_cast<float>(m_renderer->m_windowExtent.height),
                .minDepth = 0.f,
                .maxDepth = 1.f
        };

        pipelineBuilder.scissor = {
                .offset = {0 , 0},
                .extent = m_renderer->m_windowExtent
        };

        pipelineBuilder.rasterizer = VulkanInitializers::PipelineRasterizationStateCreateInfo(VK_POLYGON_MODE_FILL);
        pipelineBuilder.multisampling = VulkanInitializers::PipelineMultisampleStateCreateInfo();
        pipelineBuilder.colorBlendAttachment = VulkanInitializers::PipelineColorBlendAttachmentState();
        pipelineBuilder.pipelineLayout = m_pipelineLayout;

        m_pipeline = pipelineBuilder.BuildPipeline(m_renderer->m_logicalDevice, m_renderer->m_renderPass);

        vkDestroyShaderModule(m_renderer->m_logicalDevice, fragShader, nullptr);
        vkDestroyShaderModule(m_renderer->m_logicalDevice, vertShader, nullptr);
    }
}