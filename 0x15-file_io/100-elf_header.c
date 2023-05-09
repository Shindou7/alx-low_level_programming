#include "main.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void check_elf(unsigned char *pt);
void _magic(unsigned char *pt);
void _class(unsigned char *pt);
void _data(unsigned char *pt);
void _version(unsigned char *pt);
void _abi(unsigned char *pt);
void _osabi(unsigned char *pt);
void _type(unsigned int e_type, unsigned char *pt);
void _entry(unsigned long int e_entry, unsigned char *pt);
void close_elf(int elf);

/**
 * check_elf - check if it is an elf file.
 * @pt: magic.
 * Return: 1 if it is an elf file. 0 if not.
 */
void check_elf(unsigned char *pt)
{
	unsigned char elf_magic[4] = { 0x7f, 'E', 'L', 'F' };

	if (memcmp(pt, elf_magic, 4) != 0)
	{
		dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
		exit(98);
	}
}


/**
 * _magic - Prints the magic numbers of an ELF header.
 * @pt: A pointer to an array containing the ELF magic numbers.
 * Description: Magic numbers are separated by spaces.
*/
void _magic(unsigned char *pt)
{
	int i;

	printf(" Magic: ");
	for (i = 0; i < EI_NIDENT; i++, pt++)
	{
		printf("%02x", *pt);
		if (i == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * _class - Prints the class of an ELF header.
 * @pt: A pointer to an array containing the ELF class.
 */
void _class(unsigned char *pt)
{
	printf("  Class:                             ");

	unsigned int class = pt[EI_CLASS];

	if (class == ELFCLASSNONE)
		printf("none\n");
	else if (class == ELFCLASS32)
		printf("ELF32\n");
	else if (class == ELFCLASS64)
		printf("ELF64\n");
	else
		printf("<unknown: %x>\n", class);
}
