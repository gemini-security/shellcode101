# Build Your Own Shellcode Launcher in C++ 

Source code used in the video (scheduled to be posted on Friday 10th November 10:30pm SGT):

https://youtu.be/hWbfifU8TtA

Video showcases how you can build your very own shellcode launcher program in C++ - with Python automation!

# tips

simple proof of concept on how you can automate the building of shellcode launchers in Python

consider implementing some payload encryption to bypass windows defender into the proof of concept code!

eg: 

python -> read payload.bin file, performs encryption, match and replace encrypted payload into the .cpp file

of course - the .cpp file should contain the relevant decryption routine in order to execute it
