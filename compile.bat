call "C:\Program Files\Microsoft Visual Studio\18\Community\VC\Auxiliary\Build\vcvarsall.bat" x64

cd src

cl *.c *.cpp /link /SUBSYSTEM:CONSOLE user32.lib gdi32.lib

pause