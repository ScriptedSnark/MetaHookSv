#pragma once

#include <string>

qboolean UTIL_ParseStringAsVector1(const char* string, float* vec);
qboolean UTIL_ParseStringAsVector2(const char* string, float* vec);
qboolean UTIL_ParseStringAsVector3(const char* string, float* vec);
qboolean UTIL_ParseStringAsVector4(const char* string, float* vec);

void UTIL_RemoveFileExtension(std::string& filePath);
std::string trim(const std::string& str);