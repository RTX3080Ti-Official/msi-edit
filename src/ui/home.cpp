// SPDX-License-Identifier: GPL-2.0-only
// Copyright (C) 2026 RTX3080Ti <rtx3080ti0415@gmail.com>

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "ui/home.hpp"
#include "msi/MsiFile.hpp"
#include <GLFW/glfw3.h>
#include "home.hpp"
#include <cstdio>

Home::Home() {

}

void Home::create(MsiFileContent content) {
    /*ImGui::Begin("Dashboard");
    ImGui::Text("Welcome to your custom C++ App");
    if (ImGui::Button("Action Button", ImVec2(120, 40))) {

    }
    ImGui::End();*/
    createInfo(content);
}

void UpdateBuffer(char* dest, size_t destSize, const std::string& src) {
    if (!src.empty()) {
        strncpy(dest, src.c_str(), destSize - 1);
        dest[destSize - 1] = '\0';
    }
}

void Home::createInfo(MsiFileContent msiFile) {
    static char pNameBuf[128] = "";
    static char pVerBuf[64]   = "";
    static char pUrlBuf[256]  = "";
    static char pConBuf[128]  = "";
    static char pComBuf[512]  = "";
    static char pCodeBuf[128] = "";

    UpdateBuffer(pNameBuf, sizeof(pNameBuf), msiFile.productName);
    UpdateBuffer(pVerBuf,  sizeof(pVerBuf),  msiFile.productVersion);
    UpdateBuffer(pUrlBuf,  sizeof(pUrlBuf),  msiFile.productUrl);
    UpdateBuffer(pConBuf,  sizeof(pConBuf),  msiFile.productContact);
    UpdateBuffer(pComBuf,  sizeof(pComBuf),  msiFile.productComments);
    UpdateBuffer(pCodeBuf, sizeof(pCodeBuf), msiFile.productCode);

    ImGui::Begin("File Info");
    if (ImGui::InputText("Product Name", pNameBuf, sizeof(pNameBuf))) {
    }
    if (ImGui::InputText("Version", pVerBuf, sizeof(pVerBuf))) {
    }
    if (ImGui::InputText("URL / Support", pUrlBuf, sizeof(pUrlBuf))) {
    }
    if (ImGui::InputText("Contact", pConBuf, sizeof(pConBuf))) {
    }
    if (ImGui::InputTextMultiline("Comments", pComBuf, sizeof(pComBuf), ImVec2(0, 80))) {
    }
    ImGui::InputText("Product Code",    pCodeBuf,  sizeof(pCodeBuf), ImGuiInputTextFlags_ReadOnly);
    ImGui::End();
}