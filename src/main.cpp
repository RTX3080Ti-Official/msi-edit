// SPDX-License-Identifier: GPL-2.0-only
// Copyright (C) 2026 RTX3080Ti <rtx3080ti0415@gmail.com>

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "ui/home.hpp"
#include "ui/menu.hpp"
#include "ui/dialog.hpp"
#include "msi/MsiFile.hpp"
#include <GLFW/glfw3.h>

GLFWwindow* window;
bool g_ShowConfigDialog = false;
bool g_IsMsiOpen = false;

bool init() {
    if (!glfwInit()) return false;
    window = glfwCreateWindow(1280, 720, "MsiEdit", NULL, NULL);
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    return true;
}

int main() {
    if (!init()) return 0;
    MsiFile file;
    
    auto& style = ImGui::GetStyle();
    style.WindowRounding = 8.0f;
    style.FrameRounding = 5.0f;
    style.Colors[ImGuiCol_WindowBg] = ImVec4(0.10f, 0.10f, 0.12f, 1.00f);
    style.Colors[ImGuiCol_Button]   = ImVec4(0.20f, 0.25f, 0.30f, 1.00f);
    style.Colors[ImGuiCol_Header]   = ImVec4(0.26f, 0.59f, 0.98f, 0.31f);

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130");

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        Home homeView;
        Menu menuView;
        Dialog dialogView;
        
        menuView.create();

        if (g_ShowConfigDialog) {
            ImGui::OpenPopup("No config file has been found.");
            g_ShowConfigDialog = false;
        }

        dialogView.render(0);
        homeView.create(file.createFileContent(R"(C:\Users\yoann.degardin\Downloads\gh_2.86.0_windows_amd64.msi)"));

        ImGui::Render();
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        glfwSwapBuffers(window);
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}