#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <elf.h>

void print_magic(Elf64_Ehdr *header);
void print_class(Elf64_Ehdr *header);
void print_data(Elf64_Ehdr *header);
void print_version(Elf64_Ehdr *header);
void print_osabi(Elf64_Ehdr *header);
void print_type(Elf64_Ehdr *header);
void print_entry_point(Elf64_Ehdr *header);
int read_elf_header(const char *filename, Elf64_Ehdr *header);
int main(int argc, char *argv[]);
/**
 * print_magic - Prints the magic bytes of the ELF header
 * @header: Pointer to the ELF header structure
 */
void print_magic(Elf64_Ehdr *header)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x ", header->e_ident[i]);
	printf("\n");
}
/**
 * print_class - Prints the class of the ELF header
 * @header: Pointer to the ELF header structure
 */
void print_class(Elf64_Ehdr *header)
{
	printf("  Class:                             ");
	switch (header->e_ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("Invalid class\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("Unknown\n");
			break;
	}
}

/**
 * print_data - Prints the data encoding of the ELF header
 * @header: Pointer to the ELF header structure
 */
void print_data(Elf64_Ehdr *header)
{
	printf("  Data:                              ");
	switch (header->e_ident[EI_DATA])
	{
		case ELFDATANONE:
			printf("Invalid data encoding\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("Unknown\n");
			break;
	}
}
/**
 * print_version - Prints the version of the ELF header
 * @header: Pointer to the ELF header structure
 */
void print_version(Elf64_Ehdr *header)
{
	printf("  Version:                           %d (current)\n",
		header->e_ident[EI_VERSION]);
}
/**
 * print_osabi - Prints the OS/ABI of the ELF header
 * @header: Pointer to the ELF header structure
 */
void print_osabi(Elf64_Ehdr *header)
{
	printf("  OS/ABI:                            ");
	switch (header->e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		default:
			printf("Unknown\n");
			break;
	}
	    printf("  ABI Version:                       %d\n",
		    header->e_ident[EI_ABIVERSION]);
}
/**
 * print_type - Prints the type of the ELF header
 * @header: Pointer to the ELF header structure
 */
void print_type(Elf64_Ehdr *header)
{
	printf("  Type:                              ");
	switch (header->e_type)
	{
		case ET_NONE:
			printf("No file type\n");
			break;
		case ET_REL:
			printf("Relocatable file\n");
			break;
		case ET_EXEC:
			printf("Executable file\n");
			break;
		case ET_DYN:
			printf("Shared object file\n");
			break;
		case ET_CORE:
			printf("Core file\n");
			break;
		default:
			printf("Unknown\n");
			break;}
}
/**
 * print_entry_point - Prints the entry point address of the ELF header
 * @header: Pointer to the ELF header structure
 */
void print_entry_point(Elf64_Ehdr *header)
{
	printf("  Entry point address:               0x%lx\n",
		header->e_entry);
}

/**
 * read_elf_header - Reads the ELF header from a file
 * @filename: Name of the file
 * @header: Pointer to the ELF header structure
 * Return: 0 on success, -1 on failure
 */
int read_elf_header(const char *filename, Elf64_Ehdr *header)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't read from file %s\n", filename);
		return (-1);
	}
	if (read(fd, header, sizeof(*header)) != sizeof(*header))
	{
		fprintf(stderr, "Error: Unable to read ELF header from file %s\n",
			filename);
		close(fd);
		return (-1);
	}

	close(fd);
	return (0);
}
/**
 * main - Entry point
 * @argc: The argument count
 * @argv: Array of argument strings
 * Return: 0 on success, otherwise exits with an error code.
 */
int main(int argc, char *argv[])
{
	Elf64_Ehdr header;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: elf_header elf_filename\n");
		exit(1);
	}
	if (read_elf_header(argv[1], &header) != 0)
		exit(98);

	printf("ELF Header:\n");

	print_magic(&header);
	print_class(&header);
	print_data(&header);
	print_version(&header);
	print_osabi(&header);
	print_type(&header);
	print_entry_point(&header);
	return (0);
}
