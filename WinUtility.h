#pragma once
#include <string>
// #include <Windows.h>
#include <vector>
#include <stdint.h>
#include <cwchar>

#define MD5LEN  16

class WinUtility
{
public:
	WinUtility();
	~WinUtility();

	static std::string Base64Encode(const uint8_t* data, uint32_t sz);
	static std::basic_string<uint8_t> Base64Decode(const char* data, uint32_t sz);
	static std::string UnicodeToAnsi(const wchar_t* data, uint32_t sz);
	static std::wstring AnisToUnicode(const char* data, uint32_t sz);
	static std::string MD5Encode(const uint8_t* data, uint32_t sz);
	static std::string CreateXID();
private:
	static uint8_t encoding[32];
};

