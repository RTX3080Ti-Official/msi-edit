// SPDX-License-Identifier: GPL-2.0-only
// Copyright (C) 2026 RTX3080Ti <rtx3080ti0415@gmail.com>

#pragma once

#include <cstring>
#include <string>

class MsiFile {
public:
    MsiFile();
    void create(std::string filePath);
};

struct MsiFileContent {
    std::string productName;
};

struct MsiFileData {
    std::string filePath;
    bool wasEdited;
    MsiFileContent content;
};