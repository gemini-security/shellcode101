# shellcode101

Source code used in the video

https://youtu.be/hWbfifU8TtA

# tips

simple proof of concept on how you can automate the building of shellcode launchers in Python

consider implementing some payload encryption to bypass windows defender into the proof of concept code!

eg: 

python -> read payload.bin file, performs encryption, match and replace encrypted payload into the .cpp file

of course - the .cpp file should contain the relevant decryption routine in order to execute it
