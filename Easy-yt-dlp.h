/*
* MIT License
*
* Copyright (c) 2024 Yunze Guo
*
* Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

/*******************
* Easy-yt-dlp V0.1
* gcc version 8.1.0 (x86_64-win32-seh-rev0, Built by MinGW-W64 project)
****************************************************************************************************************
* Just like its name, this is a lightweight software which be built base yt-dlp, purposing to use yt-dlp easy.
* Now you can just private the url, the file's path, the file's format and your cookie-writing file to download
* videos instand of loads of complex arguments in console.
****************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

#define CMDSize 2048

/*------------------------------------State------------------------------------*/

//char StrCmd[CMDSize];

struct YtDlpCmdInfo {
    char url[1024];
    char name[1024];
    char cookie[1024];
} YDInfo;

void CreateYDCmdString(char* buf, unsigned long long len, struct YtDlpCmdInfo* yci);

struct FfmpegCmdInfo {
    char vdecode[32];
    char adecode[32];
    char vencode[32];
    char aencode[32];
    char infile[1024];
    unsigned short infileSize;
    char outfile[1024];
    unsigned short outfileSize;
} FFInfo;

void CreateFfmpegCmdInfo(void);
void CreateFfmegCmdString(char* buf, size_t buf_size, struct FfmpegCmdInfo* fci);

void Call(const char* cmd);

void Init(void);
void Input(void);