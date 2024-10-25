#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <algorithm>

// Case-insensitive hash object for std::unordered_map
struct CaseInsensitiveHash {
    size_t operator()(const std::string& str) const {
        std::string lowerStr = str;
        std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
        std::hash<std::string> hasher;
        return hasher(lowerStr);
    }
};

// Case-insensitive equality object for std::unordered_map
struct CaseInsensitiveEqual {
    bool operator()(const std::string& str1, const std::string& str2) const {
        return std::equal(str1.begin(), str1.end(), str2.begin(), str2.end(),
            [](char c1, char c2) { return std::tolower(c1) == std::tolower(c2); });
    }
};

// Helper function to convert a string to lowercase
std::string toLowerCase(const std::string& str);

#endif
