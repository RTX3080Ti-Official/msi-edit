// SPDX-License-Identifier: GPL-2.0-only
// Copyright (C) 2026 RTX3080Ti <rtx3080ti0415@gmail.com>

#pragma once

#include <cstring>
#include <string>

struct MsiFileContent {
    std::string productName;
    std::string productVersion;
    std::string productUrl;
    std::string productContact;
    std::string productComments;
    std::string productCode;
};

struct MsiFileData {
    std::string filePath;
    bool wasEdited;
    MsiFileContent content;
};
class MsiFile {
public:
    MsiFile();
    MsiFileData create(std::string filePath);
    MsiFileContent createFileContent(std::string filePath);
};