#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

void print_error(char *error_msg)
{
  fprintf(stderr, "%s\n", error_msg);
  exit(98);
}

void print_elf_header(Elf64_Ehdr *header)
{
  printf("ELF Header:\n");
  printf("  Magic:   ");
  for (int i = 0; i < EI_NIDENT; i++)
    printf("%02x ", header->e_ident[i]);
  printf("\n");
  printf("  Class:                             %s\n", header->e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" : "ELF32");
  printf("  Data:                              %s\n", header->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "2's complement, big endian");
  printf("  Version:                           %d (current)\n", header->e_ident[EI_VERSION]);
  printf("  OS/ABI:                            ");
  switch (header->e_ident[EI_OSABI])
  {
    case ELFOSABI_SYSV:
      printf("UNIX - System V\n");
      break;
    case ELFOSABI_LINUX:
      printf("UNIX - Linux\n");
      break;
    case ELFOSABI_SOLARIS:
      printf("UNIX - Solaris\n");
      break;
    default:
      printf("<unknown: %x>\n", header->e_ident[EI_OSABI]);
      break;
  }
  printf("  ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);
  printf("  Type:                              ");
  switch (header->e_type)
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
      printf("<unknown: %x>\n", header->e_type);
      break;
  }
  printf("  Entry point address:               %lx\n", header->e_entry);
}
int main(int argc, char *argv[])
{
  if (argc != 2)
    print_error("Usage: elf_header elf_filename");
  
  int fd = open(argv[1], O_RDONLY);
  
  if (fd == -1)
    print_error("Error: Cannot open file");

  Elf64_Ehdr header;
  if (read(fd, &header, sizeof(header)) != sizeof(header))
    print_error("Error: Cannot read ELF header");

  if (memcmp(header.e_ident, ELFMAG, SELFMAG) != 0)
    print_error("Error: Not an ELF file");

  print_elf_header(&header);

  return (0);
}
