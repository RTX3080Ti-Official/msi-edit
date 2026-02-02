// SPDX-License-Identifier: GPL-2.0-only
// Copyright (C) 2026 RTX3080Ti <rtx3080ti0415@gmail.com>

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "ui/menu.hpp"
#include <GLFW/glfw3.h>

Menu::Menu() {

}

void Menu::create() {
    if (ImGui::BeginMainMenuBar()) {
        if (ImGui::BeginMenu("File")) {
            if (ImGui::MenuItem("New Project", "Ctrl+N")) { 
                /* Handle New */ 
            }
            if (ImGui::MenuItem("Open...", "Ctrl+O")) { 
                /* Handle Open */ 
            }
            ImGui::Separator();
            if (ImGui::MenuItem("Exit", "Alt+F4")) { 
                // Handle Exit
            }
            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Edit")) {
            if (ImGui::MenuItem("Undo", "Ctrl+Z")) {}
            if (ImGui::MenuItem("Redo", "Ctrl+Y", false, false)) {} // Disabled item
            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Help")) {
            if (ImGui::MenuItem("Documentation")) {
                // Here is where you'd link your Sphinx docs!
            }
            ImGui::EndMenu();
        }
        
        ImGui::EndMainMenuBar();
    }
}