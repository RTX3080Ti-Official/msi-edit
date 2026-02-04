// SPDX-License-Identifier: GPL-2.0-only
// Copyright (C) 2026 RTX3080Ti <rtx3080ti0415@gmail.com>

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "ui/home.hpp"
#include <GLFW/glfw3.h>
#include "home.hpp"

Home::Home() {

}

void Home::create() {
    ImGui::Begin("Dashboard");
    ImGui::Text("Welcome to your custom C++ App");
    if (ImGui::Button("Action Button", ImVec2(120, 40))) {

    }
    ImGui::End();
}

void Home::createInfo() {
    ImGui::Begin("File Info");
    ImGui::Text("Welcome to your custom C++ App");
    if (ImGui::Button("Action Button", ImVec2(120, 40))) {

    }
    ImGui::End();
}