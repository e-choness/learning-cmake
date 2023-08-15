//
// Created by echo_ on 2023-08-14.
//

#include "VulkanEngine.hpp"
#include "vk_initializers.hpp"

namespace engine{
    void VulkanEngine::init() {
        _window = (GLFWwindow*)glfwCreateWindow(
                _windowExtent.width,
                _windowExtent.height,
                "Vulkan Engine",
                nullptr, nullptr);
        _isInitialized = true;
    }

    void VulkanEngine::run() {
        glfwPollEvents()
    }

    void VulkanEngine::cleanup() {
        if(_isInitialized){
            glfwDestroyWindow(_window);
        }
    }
}