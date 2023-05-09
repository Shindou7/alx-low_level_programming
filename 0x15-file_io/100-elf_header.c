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


/**
 * _data - Prints the data encoding of an ELF header.
 * @pt: A pointer to an array containing the ELF magic numbers.
 *
 * Description: The data encoding can be either little-endian or big-endian.
 */
void _data(unsigned char *pt)
{
	printf("  Data:                              ");
	if (pt[EI_DATA] == ELFDATA2LSB)
		printf("2's complement, little-endian\n");
	else if (pt[EI_DATA] == ELFDATA2MSB)
		printf("2's complement, big-endian\n");
	else
		printf("<unknown: %x>\n", pt[EI_DATA]);
}



/**
 * _version - Prints the v
 * @pt: A pointer
 */
void _version(unsigned char *pt)
{
	printf("  Version:                           ");

	switch (pt[EI_VERSION])
	{
		case EV_NONE:
			printf("Invalid version\n");
			break;
		case EV_CURRENT:
			printf("%d (current)\n", EV_CURRENT);
			break;
		default:
			printf("%d\n", pt[EI_VERSION]);
			break;
	}
}

/**
 * _osabi - Prints the OS/ABI of an ELF header.
 * @pt: A pointer to an array containing the ELF version.
 */
void _osabi(unsigned char *pt)
{
	printf("  OS/ABI:                            ");

	switch (pt[EI_OSABI])
	{
		case ELFOSABI_SYSV:
			printf("UNIX - System V ABI\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX ABI\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD ABI\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - GNU/Linux ABI\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris ABI\n");
			break;
		case ELFOSABI_AIX:
			printf("UNIX - AIX ABI\n");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX ABI\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD ABI\n");
			break;
		case ELFOSABI_OPENBSD:
			printf("UNIX - OpenBSD ABI\n");
			break;
		case ELFOSABI_ARM_AEABI:
			printf("ARM - ARM EABI\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM - ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone App\n");
			break;
		default:
			printf("<unknown: %x>\n", pt[EI_OSABI]);
	}
}


/**
 * _entry - Prints the prog
 * @e_entry: The proble offset.
 * @pt: A pointer to an array.
 */
void _entry(unsigned long int e_entry, unsigned char *pt)
{
	printf("  Start of program headers:          ");

	if (pt[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			  ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (pt[EI_CLASS] == ELFCLASS32)
		printf("%u (bytes into file)\n", (unsigned int)e_entry);

	else
		printf("%lu (bytes into file)\n", e_entry);
}
