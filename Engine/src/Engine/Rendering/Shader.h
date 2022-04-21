#pragma once
#include <string>

#include "IShader.h"
#include "Renderer.h"


namespace Engine 
{
    class Shader : public IShader
    {
    public:
        explicit Shader(Renderer* renderer);
        ~Shader() override;

        void Bind() override;

        void Load(const std::string&& vertexShader, const std::string&& fragmentShader) override;

    private:
        Renderer* m_renderer{ nullptr };

        // Vulkan handles
        VkPipelineLayout m_pipelineLayout{ VK_NULL_HANDLE };
        VkPipeline m_pipeline{ VK_NULL_HANDLE };
    };
}

