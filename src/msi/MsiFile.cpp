// SPDX-License-Identifier: GPL-2.0-only
// Copyright (C) 2026 RTX3080Ti <rtx3080ti0415@gmail.com>

#include <cstring>
#include <string>
#include "msi/MsiFile.hpp"
#include "msi/reader.hpp"

MsiFile::MsiFile() {

}

void MsiFile::create(std::string filePath) {
    MsiFileData data;
    data.filePath = filePath;
    std::string name = GetMsiProductName(filePath);
    printf(name.c_str());
}