#pragma once
#include <string>

#include "vulkan/vulkan.h"

#include "../Log.h"

#define VK_CHECK(x)                                                             \
    do {                                                                        \
        VkResult err = x;                                                       \
        if (err) {                                                              \
            ENGINE_CORE_ERROR("Detected Vulkan error: VKResult = VK_FALSE");                 \
            abort();                                                            \
        }                                                                       \
    } while(0)

namespace Engine {
    class Utilities {
    public:
        static bool LoadShaderModule(const std::string& filePath, VkDevice device, VkShaderModule& outShaderModule);
    };
}



