#pragma once
#include "Log.h"
#include <string>

using namespace std;
#define VK_CHECK(x)                                                             \
    do {                                                                        \
        VkResult err = x;                                                       \
        if (err) {                                                              \
            ENGINE_CORE_ERROR("Detected Vulkan error: VKResult = VK_FALSE");                 \
            abort();                                                            \
        }                                                                       \
    } while(0)

class VulkanUtilities {

};



