#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
/**
 * print_entry - prints the entry.
 * @ptr: pointer to the ELF header.
 * Return: no return.
 */
void print_entry(char *ptr)
{
	unsigned long int e_entry;
	unsigned char *ep_pointer;
	char sys;

	ep_pointer = (unsigned char *)ptr;
	e_entry = *((unsigned long int *)(ptr + 0x18));
	printf("  Entry point address:               0x");

	sys = ep_pointer[EI_VERSION];
	if (sys == EV_CURRENT)
	{
		if (ep_pointer[EI_DATA] == ELFDATA2MSB)
		{
			e_entry = ((e_entry << 8) & 0xFF00FF00) |
				((e_entry >> 8) & 0xFF00FF);
			e_entry = (e_entry << 16) | (e_entry >> 16);
		}

		if (ep_pointer[EI_CLASS] == ELFCLASS32)
			printf("%08x\n", (unsigned int)e_entry);
		else if (ep_pointer[EI_CLASS] == ELFCLASS64)
			printf("%016lx\n", e_entry);
	}
}
/**
 * print_type - prints the type
 * @ptr: a pointer
 */
void print_type(char *ptr)
{
	unsigned int type;

	if (ptr[5] == 1)
	{
		type = *(unsigned int *)(ptr + 16);
	}
	else
	{
		type = *(unsigned int *)(ptr + 18);
	}
	printf("  Type:                              ");

	switch (type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
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
	}
}

/**
 * print_osabi - prints osabi
 * @ep_pointer: magic.
 * Return: no return.
 */
void print_osabi(unsigned char *ep_pointer)
{
	const char *osabi_names[] = {
		"System V", "HP-UX", "NetBSD", "Linux",
		"GNU Hurd", "Solaris", "AIX", "IRIX",
		"FreeBSD", "Tru64", "Novell Modesto",
		"OpenBSD", "OpenVMS", "NonStop Kernel",
		"AROS", "Fenix OS", "CloudABI",
		"Stratus Technologies OpenVOS"
		};
	int osabi = ep_pointer[EI_OSABI];

	const char *osabi_name =
		osabi < (sizeof(osabi_names) / sizeof(osabi_names[0])) ?
		osabi_names[osabi] : "Unknown";
	printf("  OS/ABI:                            %s\n", osabi_name);
	printf("  ABI Version:                       %d\n",
	       ep_pointer[EI_ABIVERSION]);
}
/**
 * print_version - Prints the version
 * @ep_pointer: A pointer
 */
void print_version(unsigned char *ep_pointer)
{
	int version = ep_pointer[EI_VERSION];

	printf("  Version:                           %d", version);
	if (version == EV_CURRENT)
	{
		printf(" (current)");
	}
	printf("\n");
}

/**
 * print_data - Prints the data
 * @ep_pointer: A pointer
 */
void print_data(unsigned char *ep_pointer)
{
	printf("  Data:                              ");
	switch (ep_pointer[EI_DATA])
	{
		case ELFDATANONE:
			printf("none\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian");
			if (ep_pointer[EI_VERSION] == EV_CURRENT)
			{
				printf(" (current)");
			}
			printf("\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian");
			if (ep_pointer[EI_VERSION] == EV_CURRENT)
			{
				printf(" (current)");
			}
			printf("\n");
			break;
		default:
			printf("<unknown: %x>\n", ep_pointer[EI_CLASS]);
	}
}


/**
 * print_magic - Prints the magic
 * @ep_pointer: A pointer
 *
 * Description: Magic numbers.
 */
void print_magic(unsigned char *ep_pointer)
{
	printf("  Magic:   ");
	for (int i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", ep_pointer[i]);
		if (i == EI_CLASS || i == EI_DATA || i == EI_VERSION || i == EI_OSABI)
		{
			printf(" ");
		}
	}
	printf("\n");
}


/**
 * print_class - Prints the class
 * @ep_pointer: A pointer
 */
void print_class(unsigned char *ep_pointer)
{
	printf("  Class:                             ");

	if (ep_pointer[EI_CLASS] == ELFCLASSNONE)
		printf("none\n");
	else if (ep_pointer[EI_CLASS] == ELFCLASS32)
		printf("ELF32\n");
	else if (ep_pointer[EI_CLASS] == ELFCLASS64)
		printf("ELF64\n");
	else
		printf("<unknown: %x>\n", ep_pointer[EI_CLASS]);
}
/**
 * check_elf - Checks if a file is an ELF file.
 * @ep_pointer: A pointer to an array containing the ELF magic numbers.
 *
 * Return: If the file.
 */
int check_elf(unsigned char *ep_pointer)
{
	if (ptr[0] == 0x7f && ptr[1] == 'E' && ptr[2] == 'L' && ptr[3] == 'F')
		return (1);

	return (0);
}

/**
 * main - Entry point.
 * @argc: Number of arg
 * @argv: Array
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int fd, ret_read;
	char ptr[27];
	Elf64_Ehdr *header;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		exit(98);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	ret_read = read(fd, ptr, sizeof(ptr));
	if (ret_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		(fd);
		exit(98);
	}
	if (!check_elf(ptr))
	{
		dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
		close(fd);
		exit(98);
	}
	header = (Elf64_Ehdr *)ptr;
	printf("ELF Header:\n");
	print_magic(header->ep_pointer);
	print_class(header->ep_pointer);
	print_data(header->ep_pointer);
	print_version(header->ep_pointer);
	print_osabi(header->ep_pointer);
	print_abi(header->ep_pointer);
	print_type(header->e_type, header->ep_pointer);
	print_entry(header->e_entry, header->ep_pointer);
	close(fd);
	return (0);
}
