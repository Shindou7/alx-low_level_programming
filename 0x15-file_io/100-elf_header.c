#include "main.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int is_elf(char *ptr);
void print_magic(char *ptr);
void print_data(char *ptr);
void print_osabi(char *ptr);
void print_version(char *ptr);
void print_type(char *ptr);
void print_addr(char *ptr);
void print_elf_info(char *ptr);
int elf_header(int argc, char *argv[]);

/**
 * is_elf - check if it is an elf file.
 * @ptr: magic.
 * Return: 1 if it is an elf file. 0 if not.
 */
int is_elf(char *ptr)
{
	unsigned char magic[4] = {0x7f, 'E', 'L', 'F'};
	int i;

	for (i = 0; i < 4; i++)
	{
		if (ptr[i] != magic[i])
			return (0);
	}
	return (1);
}

/**
 * print_magic - prints magic.
 * @ptr: magic.
 * Return: no return.
 */
void print_magic(char *ptr)
{
	int i;

	printf("Magic:  ");

	for (i = 0; i < 16; i++)
		printf("%02x ", ptr[i]);

	printf("\n");
}

/**
 * print_data - prints data.
 * @ptr: magic.
 * Return: no return.
 */
void print_data(char *ptr)
{
	char data = ptr[5];

	printf("  Data:                              2's complement");

	if (data == 1)
		printf(", little endian\n");
	else if (data == 2)
		printf(", big endian\n");
	else
		printf(", unknown format (%d)\n", data);
}

/**
 * print_osabi - prints osabi.
 * @ptr: magic.
 * Return: no return.
 */
void print_osabi(char *ptr)
{
	char osabi = ptr[7];

	printf("  OS/ABI:                            ");

	switch (osabi)
	{
	case 0:
		printf("UNIX - System V\n");
		break;
	case 2:
		printf("UNIX - NetBSD\n");
		break;
	case 3:
		printf("UNIX - GNU Hurd\n");
		break;
	case 6:
		printf("UNIX - Solaris\n");
		break;
	case 7:
		printf("UNIX - AIX\n");
		break;
	case 8:
		printf("UNIX - IRIX\n");
		break;
	case 9:
		printf("UNIX - FreeBSD\n");
		break;
	case 10:
		printf("UNIX - Tru64\n");
		break;
	case 11:
		printf("UNIX - Novell Modesto\n");
		break;
	case 12:
		printf("UNIX - OpenBSD\n");
		break;
	case 13:
		printf("UNIX - OpenVMS\n");
		break;
	default:
		printf("<unknown: %x>\n", osabi);
		break;
	}
}

/**
 * print_version - prints version.
 * @ptr: magic.
 * Return: no return.
 */
void print_version(char *ptr)
{
	int version = ptr[6];

	printf("  ABI Version:                       %d\n", ptr[8]);

	printf("  Version:                           %d", version);

	if (version == EV_CURRENT)
		printf(" (current)");

	printf("\n");
}

/**
 * print_type - prints type.
 * @ptr: magic.
 * Return: no return.
 */
void print_type(char *ptr)
{
	int type = *(unsigned short int *)(ptr + 16);

	printf("  Type:                              ");

	switch (type)
	{
		case ET_NONE:
			printf("NONE (No file type)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("<unknown: %x>\n", type);
			break;
	}
}
