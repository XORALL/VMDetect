

#include <unistd.h>
#include <signal.h>
main(a);
__sighandler_t handler(int sig)
{
	switch(sig)
	{
		case SIGSEGV:
			main(0xc0de);
		break;
	}
}

unsigned vmware(void)
{
asm(
	".intel_syntax noprefix\n"
	"mov eax, 0x564d5868\n"
	"mov cl, 0xa\n"
	"mov dx, 0x5658\n"
	"in eax, dx\n"
	"cmp ebx, 0\n"
	"jne matrix\n"
	"xor eax, eax\n"
	"ret\n"
	"matrix:\n"
	"mov eax, 1\n");
}



main(a)
{
	if(a==0xc0de) goto stage2;
	signal(SIGSEGV, &handler);
	
	if(vmware()) goto matrix;

stage2:
	puts("ones and zeros");
	exit(0);

matrix:
	puts("im apart of the matrix now");
	exit(1);
}




#include <iostream>
#include <windows.h>

unsigned vmware(void)
{
__asm{
	mov eax, 0x564d5868
	mov cl, 0xa
	mov dx, 0x5658
	in eax, dx
	cmp ebx, 0
	jne matrix
	xor eax, eax
	ret
	matrix:
	mov eax, 1};
}

int seh_filter(unsigned code, struct _EXCEPTION_POINTERS* ep)
{
	return EXCEPTION_EXECUTE_HANDLER;
}

int _tmain(int a, _TCHAR* argv[])
{
    __try
	{
		if(vmware()) goto matrix;
    }
    __except(seh_filter(GetExceptionCode(), GetExceptionInformation()))
    {
            goto stage2;
    }

stage2:
	std::cout << "Isn't real life boring?"<<std::endl;
	exit(0);

matrix:
	std::cout << "The Matrix haz you Neo..."<<std::endl;
	exit(1);
}
