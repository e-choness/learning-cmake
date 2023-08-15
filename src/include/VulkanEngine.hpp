//
// Created by echo_ on 2023-08-14.
//

#pragma once
#include "vk_types.hpp"
#include <iostream>

namespace engine{
    namespace {
        void WindowErrorCallback(int error, const char* description){
            std::cout << stderr << "Window error:" << description << "\n";
        }

        void WindowCloseCallback(GLFWwindow* window){
            glfwSetWindowShouldClose(window, GLFW_TRUE);
        }

        void WindowCloseCallback(GLFWwindow* window, int key, int scancode, int action, int mods){
            if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
                glfwSetWindowShouldClose(window, GLFW_TRUE);
        }

        void WindowFocusCallback(GLFWwindow* window, int focused){
            // TODO: set window focus state
        }

        void WindowSizeCallback(GLFWwindow* window, int width, int height){
            glfwSetWindowSize(window, width, height);
        }

        void WindowTitleCallback(GLFWwindow* window, const char* title){
            glfwSetWindowTitle(window, title);
        }

        void WindowCursorPositionCallback(GLFWwindow* window, double x, double y){
            glfwSetCursorPos(window, x, y);
            std::cout << "Cursor position: (" << x << "," << y << ")\n";
        }

    }
    class VulkanEngine {
    public:
        void init();
        void run();
        void draw();
        void cleanup();

    bool _isInitialized{false};
    int _frameNumber {0};
    VkExtent2D _windowExtent{1600, 900};
    GLFWwindow* _window{nullptr};

    };
}

