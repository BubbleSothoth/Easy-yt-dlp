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
**************************************************************************************************************
* Just like its name, this is a lightweight software which be built base yt-dlp, purposing to use yt-dlp easy. 
* Now you can just private the url, the file's path, the file's format and your cookie-writing file to download videos instand of loads of complex arguments in console.
**************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct CmdInfo{
    char url[1024];
    char name[1024];
    char format[64];
    char cookie[1024];
} info;

char strcmd[4096];

void CreateCmdString(char* buf, unsigned long long len,struct CmdInfo* cnf){
    if(cnf->cookie[0]!='\0') {
        char* temp=(char*)calloc(sizeof(cnf->cookie), sizeof(char));
        if(temp==NULL) return;
        sprintf(temp,"\"%s\"",cnf->cookie);
        strcpy(cnf->cookie,temp);
        free(temp);
    }

    /*
     * I removed GPU's function in my program, thus everyone can run it whether AMD or NVIDIA in the computer.If you want to use this function, 
     * you need rewrite next codes base your GPU and build source codes angain
     */

    /**
    //You can use CPU to improve the speed of transcoding to mp4.
    if (!strcmp(cnf->format, "mp4"))
        strcpy(cnf->format, "mp4 --postprocessor-args \"ffmpeg:-c:v h264_nvenc\"");  //Secect encoders which your GPU supposed.
    */
    sprintf(buf,"yt-dlp -o \"%s\" --recode-video %s %s %s %s", cnf->name, cnf->format, cnf->cookie[0]=='\0'?"--no-cookies":"--cookies", cnf->cookie, cnf->url);
    return;
}

void Init(void){
    memset(&info,'\0',sizeof(info));
    memset(strcmd,'\0',sizeof(strcmd));
    return;
}

void Input(struct CmdInfo* cnf){
    printf("URL: ");
    gets(cnf->url);
    printf("Output file: ");
    gets(cnf->name);
    printf("Recode format: ");
    gets(cnf->format);
    printf("Cookies file: ");
    gets(cnf->cookie);
}

int main(int args, char** argv){
    Init();
    Input(&info);
    CreateCmdString(strcmd,sizeof(strcmd),&info);
    printf("ÔËÐÐÖ¸Áî>%s\n",strcmd);
    system(strcmd);
    printf("\n");
    system("echo °´ÈÎÒâ¼üÍË³ö & pause>nul");
    return 0;
}
