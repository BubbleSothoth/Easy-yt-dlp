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
* Easy-yt-dlp V0.2
* gcc version 8.1.0 (x86_64-win32-seh-rev0, Built by MinGW-W64 project)
****************************************************************************************************************
* Just like its name, this is a lightweight software which be built base yt-dlp, purposing to use yt-dlp easy.
* Now you can just private the url, the file's path, the file's format and your cookie-writing file to download
* videos instand of loads of complex arguments in console.
****************************************************************************************************************/

#include "Easy-yt-dlp.h"

#define TempFile "%TEMP%\\Easy-yt-dlp\\out"

/*------------------------------------Define------------------------------------*/

void CreateYDCmdString(char* buf, unsigned long long len, struct YtDlpCmdInfo* yci) {
    char* cookie = yci->cookie;
    char* temp = (char*)malloc(len);

    if (cookie[0] == '\0')
        strcpy(cookie, "--no-cookies");
    else {
        char* _ = (char*)calloc(len, sizeof(char));
        sprintf(_, "--cookies %s", cookie);
        strcpy(cookie, _);
        free(_);
    }

    sprintf(temp, "yt-dlp -o %s %s %s", yci->name, cookie, yci->url);
    strcpy(buf, temp);
    free(temp);

    return;
}

void CreateFfmegCmdString(char* buf, size_t buf_size, struct FfmpegCmdInfo* fci) {
    char* temp = (char*)malloc(buf_size);
    WIN32_FIND_DATA fdata;

    /**
    char* cp_fname = (char*)malloc(fci->infileSize);
    strcpy(cp_fname, fci->infile);
    int i = 0;
    for (i = fci->infileSize - 1; i >= 0; i--) {

        if (cp_fname[i] == '.') break;
    }
    strcpy(cp_fname + i, ".*");
    printf("[INFO] cp_fname:%s\n", cp_fname);
    strcat(cp_fname, "*");
    */
    
    char _[128] = "";
    sprintf(_, "%s\\Easy-yt-dlp\\out.*", getenv("TEMP"));
    FindFirstFile(_, &fdata);
    printf("[INFO] cp_fname:%s\n", fdata.cFileName);
    if (fdata.cFileName[0] == '\0') {
        buf[0] = '\0';
        return;
    }

    sprintf(fci->infile, "%s\\Easy-yt-dlp\\%s", getenv("TEMP"), fdata.cFileName);

    if (fci->vencode[0] == '\0') strcpy(fci->vencode, "libx264");
    if (fci->aencode[0] == '\0') strcpy(fci->aencode, "aac");

    sprintf(temp, "ffmpeg -i \"%s\" -c:v %s -c:a %s \"%s\"", fci->infile, fci->vencode, fci->aencode, fci->outfile);
    strcpy(buf, temp);

    /**
    free(cp_fname);
    */
    free(temp);
    return;
}

void Call(const char* cmd) {
    if (cmd[0] == '\0')
        return;
    if (cmd[0] != '@')
        printf("[INFO] ÔËÐÐÖ¸Áî: %s\n", cmd);
    system(cmd);
    return;
}

void Init(void){
    memset(&YDInfo,'\0',sizeof(YDInfo));
    memset(&FFInfo, '\0', sizeof(FFInfo)); 
    
    strcpy(YDInfo.name, TempFile);
    FFInfo.infileSize = strlen(FFInfo.infile);
    return;
}

void Input(void){
    printf("URL: ");
    gets(YDInfo.url);
    printf("Out file:");
    gets(FFInfo.outfile);
    FFInfo.outfileSize = strlen(FFInfo.outfile);
    printf("Cookies file:");
    gets(YDInfo.cookie);
    printf("Video encoder:");
    gets(FFInfo.vencode);
    printf("Aideo encoder:");
    gets(FFInfo.aencode);
}

int main(int args, char** argv, char** envp){
    Init();
    Input();
    char* cmd = (char*)calloc(CMDSize, sizeof(char));
    Call("del %TEMP%\\Easy-yt-dlp\\out.*");
    CreateYDCmdString(cmd, CMDSize, &YDInfo);
    Call(cmd);
    CreateFfmegCmdString(cmd, CMDSize, &FFInfo);
    Call(cmd);
    Call("@echo °´ÈÎÒâ¼üÍË³ö & pause > nul");
    
    //RunCmd(&CmdManager);

    free(cmd);
    return 0;
}
