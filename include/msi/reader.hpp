#pragma once
#include <string>

std::string GetMsiProductName(const std::string& filePath);
std::string GetMsiProductVersion(const std::string& filePath);
std::string GetMsiProductUrl(const std::string& filePath);
std::string GetMsiProductContact(const std::string& filePath);
std::string GetMsiProductComments(const std::string& filePath);
std::string GetMsiProductCode(const std::string& filePath);