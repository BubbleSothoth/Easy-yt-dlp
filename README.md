# Easy-yt-dlp
A lightweight software base yt-dlp, purposing to use yt-dlp easily.

Just like its name, this is a lightweight software which be built base yt-dlp, purposing to use yt-dlp easy. 
Now you can just provide the url, the file's path and some other optional option to download mp4 videos instand of loads of complex arguments in console.

## Input
Press url and file's name is required, but cookies' file and encoders is alternative. If you ignor alternative option, the procedure will use default 
congfig that no cookies, libx264 video encoder and aac audio encoder. 

## Output
Output be written to "Output file" where you were provided.
The procedure will create a temp file at %TEMP%\Easy-yt-dlp\.

## Use GPU
If you want use GPU to encode video, you have to provide a encoder supporting of your hardware. It is my suggesting that you can use h264_nvenc for NVIDIA,
h264_qsv for Intel and h264_amf for AMD.
