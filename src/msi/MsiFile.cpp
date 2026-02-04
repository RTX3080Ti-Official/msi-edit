// SPDX-License-Identifier: GPL-2.0-only
// Copyright (C) 2026 RTX3080Ti <rtx3080ti0415@gmail.com>

#include <cstring>
#include <string>
#include "msi/MsiFile.hpp"
#include "msi/reader.hpp"

MsiFile::MsiFile() {

}

MsiFileData MsiFile::create(std::string filePath) {
    MsiFileData data;
    data.filePath = filePath;
    data.wasEdited = true;
    data.content = createFileContent(filePath);
    return data;
}

MsiFileContent MsiFile::createFileContent(std::string filePath) {
    MsiFileContent content;
    content.productName = GetMsiProductName(filePath);
    content.productUrl = GetMsiProductUrl(filePath);
    content.productVersion = GetMsiProductVersion(filePath);
    content.productContact = GetMsiProductContact(filePath);
    content.productComments = GetMsiProductComments(filePath);
    content.productCode = GetMsiProductCode(filePath);
    return content;
}