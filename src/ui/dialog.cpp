// SPDX-License-Identifier: GPL-2.0-only
// Copyright (C) 2026 RTX3080Ti <rtx3080ti0415@gmail.com>

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "ui/dialog.hpp"
#include <GLFW/glfw3.h>
#include <vector>

Dialog::Dialog() {

}

void Dialog::init(const char* modal, const char* desc, std::vector<DialogExtra> extras) {
    ImVec2 center = ImGui::GetMainViewport()->GetCenter();
    ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));

    if (ImGui::BeginPopupModal(modal, NULL, ImGuiWindowFlags_AlwaysAutoResize)) {
        ImGui::Text(desc);
        ImGui::Separator();

        for (const auto& item : extras) {
            if (ImGui::Button(item.name, ImVec2(120, 0))) {
                item.action();
                ImGui::CloseCurrentPopup();
            }
            if (&item == &extras.front()) {
                ImGui::SetItemDefaultFocus();
            }
            ImGui::SameLine();
        }
        ImGui::EndPopup();
    }
}

void Dialog::render(int type) {
    Dialog dialog;

    switch (type) {
        case 0: {
            std::vector<DialogExtra> extras;

            for (size_t i = 0; i < 2; ++i) {
                DialogExtra extra;
                switch (i) {
                    case 0:
                        extra.name = "OK";
                        break;
                    case 1:
                        extra.name = "Cancel";
                        break;
                    default:
                        extra.name = nullptr;
                }
                extra.action = nullptr;
                extras.push_back(extra);
            }

            dialog.init("No config file has been found.", "No config file has been found, do you want to create one?", extras);
            break;
        }

        case 1: {
            break;
        }

        default:
            break;
    }
}