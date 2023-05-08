#include "main.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int elf_header(int argc, char *argv[]);
void print_addr_and_type(char *ptr);
void print_osabi_version(char *ptr);
void display_data(char *ptr);
void print_elf_info(char *ptr);
int is_elf(char *ptr);

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
 * print_elf_info - print ELF header information
 * @ptr: magic.
 * Return: no return.
 */
void print_elf_info(char *ptr)
{
	char sys = ptr[4] + '0';

	if (sys == '0')
		exit(98);
	printf("ELF Header:\n");
	print_magic(ptr);

	switch (sys)
	{
		case '1':
			printf("  Class:                             ELF32\n");
			break;
		case '2':
			printf("  Class:                             ELF64\n");
			break;
		default:
			printf("  Unknown ELF class\n");
			break;
	}
	print_data(ptr);
	print_version(ptr);
	print_osabi(ptr);
	print_type(ptr);
	print_addr(ptr);
}

/**
 * display_magic_info - displays magic information.
 * @ptr: pointer to the ELF header.
 * Return: void.
 */
void display_magic_info(char *ptr)
{
	int i;

	printf("Magic:  ");

	for (i = 0; i < 16; i++)
		printf("%02x ", ptr[i]);

	printf("\n");
}


/**
 * display_data - displays the data format of an ELF file.
 * @ptr: pointer to the ELF header.
 * Return: none.
 */
void display_data(char *ptr)
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
 * print_osabi_version - prints osabi and version
 * @ptr: magic.
 * Return: no return.
 */
void print_osabi_version(char *ptr)
{
	char osabi = ptr[7];
	int version = ptr[6];

	printf("  OS/ABI:                            ");
	if (osabi == 0)
		printf("UNIX - System V\n");
	else if (osabi == 2)
		printf("UNIX - NetBSD\n");
	else if (osabi == 6)
		printf("UNIX - Solaris\n");
	else
		printf("<unknown: %x>\n", osabi);
	printf("  ABI Version:                       %d\n", ptr[8]);

	printf("  Version:                           %d", version);
	if (version == EV_CURRENT)
		printf(" (current)");
	printf("\n");
}
/**
 * print_addr_and_type - prints address and type
 * @ptr: magic.
 * Return: no return.
 */
void print_addr_and_type(char *ptr)
{
	int i;
	int begin;
	char sys;

	printf("  Entry point address:               0x");

	sys = ptr[4] + '0';
	if (sys == '1')
	{
		begin = 26;
		printf("80");
		for (i = begin; i >= 22; i--)
		{
			if (ptr[i] > 0)
				printf("%x", ptr[i]);
			else if (ptr[i] < 0)
				printf("%x", 256 + ptr[i]);
		}
		if (ptr[7] == 6)
			printf("00");
	}

	if (sys == '2')
	{
		begin = 26;
		for (i = begin; i > 23; i--)
		{
			if (ptr[i] >= 0)
				printf("%02x", ptr[i]);

			else if (ptr[i] < 0)
				printf("%02x", 256 + ptr[i]);

		}
	}
	printf("\n");

	char type = ptr[16];

	if (ptr[5] == 1)
		type = ptr[16];
	else
		type = ptr[17];

	printf("  Type:                              ");
	if (type == 0)
		printf("NONE (No file type)\n");
	else if (type == 1)
		printf("REL (Relocatable file)\n");
	else if (type == 2)
		printf("EXEC (Executable file)\n");
	else if (type == 3)
		printf("DYN (Shared object file)\n");
	else if (type == 4)
		printf("CORE (Core file)\n");
	else
		printf("<unknown: %x>\n", type);
}

/**
 * elf_header - prints ELF header information.
 * @argc: number of arguments.
 * @argv: arguments vector.
 * Return: Always 0.
 */
int elf_header(int argc, char *argv[])
{
	struct stat st;
	int ret;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: elf_header elf_filename\n");
		exit(98);
	}
	ret = stat(argv[1], &st);
	if (ret == -1)
	{
		fprintf(stderr, "Err: file can not be open\n");
		exit(98);
	}

	if (!S_ISREG(st.st_mode) || !(st.st_mode & S_IXUSR))
	{
		fprintf(stderr, "Err: It is not an ELF\n");
		exit(98);
	}
	check_sys(argv[1]);
	return (0);
}
