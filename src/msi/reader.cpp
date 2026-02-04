// SPDX-License-Identifier: GPL-2.0-only
// Copyright (C) 2026 RTX3080Ti <rtx3080ti0415@gmail.com>
/*
Please dont, just turn back, this code is fucking HORRIBLE.
Why did they make MSI reading so hard without Microsoft-specific
libraries.
Really if you wanna look at this code be prepared to vomit.
Best regards, RTX3080Ti.
*/

#include "msi/reader.hpp"

#ifdef _WIN32
    #define WIN32_LEAN_AND_MEAN
    #include <windows.h>
    #include <msiquery.h>

    std::string GetMsiProductName(const std::string& filePath) {
        MSIHANDLE hDatabase = 0;
        MSIHANDLE hView = 0;
        MSIHANDLE hRecord = 0;
        std::string result = "Unknown Product";

        if (MsiOpenDatabaseA(filePath.c_str(), MSIDBOPEN_READONLY, &hDatabase) != ERROR_SUCCESS)
            return "Error: Open Failed";

        // Yes, MSIs are just SQL databases disguised, why? I don't know, ask them not me.
        const char* sql = "SELECT `Value` FROM `Property` WHERE `Property` = 'ProductName'";
        if (MsiDatabaseOpenViewA(hDatabase, sql, &hView) == ERROR_SUCCESS) {
            MsiViewExecute(hView, 0);
            if (MsiViewFetch(hView, &hRecord) == ERROR_SUCCESS) {
                char buf[256];
                DWORD sz = sizeof(buf);
                MsiRecordGetStringA(hRecord, 1, buf, &sz);
                result = buf;
            }
        }

        if (hRecord) MsiCloseHandle(hRecord);
        if (hView) MsiCloseHandle(hView);
        if (hDatabase) MsiCloseHandle(hDatabase);
        return result;
    }

    std::string GetMsiProductVersion(const std::string& filePath) {
        MSIHANDLE hDatabase = 0;
        MSIHANDLE hView = 0;
        MSIHANDLE hRecord = 0;
        std::string result = "Unknown Product Version";

        if (MsiOpenDatabaseA(filePath.c_str(), MSIDBOPEN_READONLY, &hDatabase) != ERROR_SUCCESS)
            return "Error: Open Failed";

        const char* sql = "SELECT `Value` FROM `Property` WHERE `Property` = 'ProductVersion'";
        if (MsiDatabaseOpenViewA(hDatabase, sql, &hView) == ERROR_SUCCESS) {
            MsiViewExecute(hView, 0);
            if (MsiViewFetch(hView, &hRecord) == ERROR_SUCCESS) {
                char buf[256];
                DWORD sz = sizeof(buf);
                MsiRecordGetStringA(hRecord, 1, buf, &sz);
                result = buf;
            }
        }

        if (hRecord) MsiCloseHandle(hRecord);
        if (hView) MsiCloseHandle(hView);
        if (hDatabase) MsiCloseHandle(hDatabase);
        return result;
    }

    std::string GetMsiProductUrl(const std::string& filePath) {
        MSIHANDLE hDatabase = 0;
        MSIHANDLE hView = 0;
        MSIHANDLE hRecord = 0;
        std::string result = "Unknown Product Url";

        if (MsiOpenDatabaseA(filePath.c_str(), MSIDBOPEN_READONLY, &hDatabase) != ERROR_SUCCESS)
            return "Error: Open Failed";

        // Yes, there's two values for this, why? I dont fucking know.
        const char* sql = "SELECT `Value` FROM `Property` WHERE `Property` = 'ARPHELPLINK'";
        const char* sql2 = "SELECT `Value` FROM `Property` WHERE `Property` = 'UrlInfoAbout'";
        if (MsiDatabaseOpenViewA(hDatabase, sql, &hView) == ERROR_SUCCESS) {
            MsiViewExecute(hView, 0);
            if (MsiViewFetch(hView, &hRecord) == ERROR_SUCCESS) {
                char buf[256];
                DWORD sz = sizeof(buf);
                MsiRecordGetStringA(hRecord, 1, buf, &sz);
                result = buf;
            }
        }

        if (MsiDatabaseOpenViewA(hDatabase, sql2, &hView) == ERROR_SUCCESS) {
            MsiViewExecute(hView, 0);
            if (MsiViewFetch(hView, &hRecord) == ERROR_SUCCESS) {
                char buf[256];
                DWORD sz = sizeof(buf);
                MsiRecordGetStringA(hRecord, 1, buf, &sz);
                result = buf;
            }
        }

        if (hRecord) MsiCloseHandle(hRecord);
        if (hView) MsiCloseHandle(hView);
        if (hDatabase) MsiCloseHandle(hDatabase);
        return result;
    }

    std::string GetMsiProductContact(const std::string& filePath) {
        MSIHANDLE hDatabase = 0;
        MSIHANDLE hView = 0;
        MSIHANDLE hRecord = 0;
        std::string result = "Unknown Product Contact";

        if (MsiOpenDatabaseA(filePath.c_str(), MSIDBOPEN_READONLY, &hDatabase) != ERROR_SUCCESS)
            return "Error: Open Failed";

        const char* sql = "SELECT `Value` FROM `Property` WHERE `Property` = 'ARPCONTACT'";
        if (MsiDatabaseOpenViewA(hDatabase, sql, &hView) == ERROR_SUCCESS) {
            MsiViewExecute(hView, 0);
            if (MsiViewFetch(hView, &hRecord) == ERROR_SUCCESS) {
                char buf[256];
                DWORD sz = sizeof(buf);
                MsiRecordGetStringA(hRecord, 1, buf, &sz);
                result = buf;
            }
        }

        if (hRecord) MsiCloseHandle(hRecord);
        if (hView) MsiCloseHandle(hView);
        if (hDatabase) MsiCloseHandle(hDatabase);
        return result;
    }

    std::string GetMsiProductComments(const std::string& filePath) {
        MSIHANDLE hDatabase = 0;
        MSIHANDLE hView = 0;
        MSIHANDLE hRecord = 0;
        std::string result = "Unknown Product Comments";

        if (MsiOpenDatabaseA(filePath.c_str(), MSIDBOPEN_READONLY, &hDatabase) != ERROR_SUCCESS)
            return "Error: Open Failed";

        const char* sql = "SELECT `Value` FROM `Property` WHERE `Property` = 'Comments'";
        if (MsiDatabaseOpenViewA(hDatabase, sql, &hView) == ERROR_SUCCESS) {
            MsiViewExecute(hView, 0);
            if (MsiViewFetch(hView, &hRecord) == ERROR_SUCCESS) {
                char buf[256];
                DWORD sz = sizeof(buf);
                MsiRecordGetStringA(hRecord, 1, buf, &sz);
                result = buf;
            }
        }

        if (hRecord) MsiCloseHandle(hRecord);
        if (hView) MsiCloseHandle(hView);
        if (hDatabase) MsiCloseHandle(hDatabase);
        return result;
    }

    std::string GetMsiProductCode(const std::string& filePath) {
        MSIHANDLE hDatabase = 0;
        MSIHANDLE hView = 0;
        MSIHANDLE hRecord = 0;
        std::string result = "Unknown Product Code";

        if (MsiOpenDatabaseA(filePath.c_str(), MSIDBOPEN_READONLY, &hDatabase) != ERROR_SUCCESS)
            return "Error: Open Failed";

        const char* sql = "SELECT `Value` FROM `Property` WHERE `Property` = 'ProductCode'";
        if (MsiDatabaseOpenViewA(hDatabase, sql, &hView) == ERROR_SUCCESS) {
            MsiViewExecute(hView, 0);
            if (MsiViewFetch(hView, &hRecord) == ERROR_SUCCESS) {
                char buf[256];
                DWORD sz = sizeof(buf);
                MsiRecordGetStringA(hRecord, 1, buf, &sz);
                result = buf;
            }
        }

        if (hRecord) MsiCloseHandle(hRecord);
        if (hView) MsiCloseHandle(hView);
        if (hDatabase) MsiCloseHandle(hDatabase);
        return result;
    }
#else
    std::string GetMsiProductName(const std::string& filePath) {
        return "N/A (Non-Windows)";
    }

    std::string GetMsiProductVersion(const std::string& filePath) {
        return "N/A (Non-Windows)";
    }

    std::string GetMsiProductUrl(const std::string& filePath) {
        return "N/A (Non-Windows)";
    }

    std::string GetMsiProductContact(const std::string& filePath) {
        return "N/A (Non-Windows)";
    }

    std::string GetMsiProductComments(const std::string& filePath) {
        return "N/A (Non-Windows)";
    }

    std::string GetMsiProductCode(const std::string& filePath) {
        return "N/A (Non-Windows)";
    }
#endif