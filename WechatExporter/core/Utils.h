//
//  util.h
//  WechatExporter
//
//  Created by Matthew on 2020/9/30.
//  Copyright © 2020 Matthew. All rights reserved.
//

#include <string>
#include <vector>
#include <locale>

#ifdef _WIN32
#include <io.h>
typedef int mode_t;
#endif

#define ENABLE_AUDIO_CONVERTION

#ifndef Utils_h
#define Utils_h

std::string replace_all(std::string input, std::string search, std::string format);

bool endsWith(const std::string& str, const std::string& suffix);
bool endsWith(const std::string& str, std::string::value_type ch);
bool startsWith(const std::string& str, const std::string& prefix);
bool startsWith(const std::string& str, const std::string::value_type ch);

template <typename ...Args>
std::string formatString(const std::string& format, Args && ...args)
{
    auto size = std::snprintf(nullptr, 0, format.c_str(), std::forward<Args>(args)...);
    std::string output(size + 1, '\0');
    std::sprintf(&output[0], format.c_str(), std::forward<Args>(args)...);
    return output;
}

std::string combinePath(const std::string& p1, const std::string& p2);
std::string combinePath(const std::string& p1, const std::string& p2, const std::string& p3);
std::string combinePath(const std::string& p1, const std::string& p2, const std::string& p3, const std::string& p4);

// bool existsFile(const std::string &path);
// int makePath(const std::string& path, mode_t mode);

std::string md5(const std::string& s);

std::string safeHTML(const std::string& s);

std::string removeCdata(const std::string& str);

std::string fromUnixTime(unsigned int unixtime);

const char* calcVarint32Ptr(const char* p, const char* limit, uint32_t* value);
const unsigned char* calcVarint32Ptr(const unsigned char* p, const unsigned char* limit, uint32_t* value);

std::string readFile(const std::string& path);
bool readFile(const std::string& path, std::vector<unsigned char>& data);
bool writeFile(const std::string& path, const std::vector<unsigned char>& data);
bool writeFile(const std::string& path, const std::string& data);
bool isValidFileName(const std::string& fileName);

int GetBigEndianInteger(const unsigned char* data, int startIndex = 0);
int GetLittleEndianInteger(const unsigned char* data, int startIndex = 0);

class sqlite3;
int openSqlite3ReadOnly(const std::string& path, sqlite3 **ppDb);

std::string encodeUrl(const std::string& url);

std::string utcToLocal(const std::string& utcTime);

bool silkToPcm(const std::string& silkPath, std::vector<unsigned char>& pcmData);
bool silkToPcm(const std::string& silkPath, const std::string& pcmPath);

bool pcmToMp3(const std::string& pcmPath, const std::string& mp3Path);
bool pcmToMp3(const std::vector<unsigned char>& pcmData, const std::string& mp3Path);

#endif /* Utils_h */