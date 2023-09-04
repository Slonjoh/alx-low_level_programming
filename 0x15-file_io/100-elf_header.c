#include "main.h"
#include <elf.h>

/**
 * print_error - Prints an error message to stderr and exits with status 98.
 * @message: The error message to print.
 */

void print_error(const char *message)
{
	dprintf(2, "%s\n", message);
	exit(98);
}

/**
 * print_elf_header_info - Reads and prints the ELF header information.
 * @fd: The file descriptor of the ELF file.
 */

void print_elf_header_info(int fd)
{
	Elf64_Ehdr elf_header;
	int i;

	if (read(fd, &elf_header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
		print_error("Unable to read ELF header");

	if (elf_header.e_ident[EI_MAG0] != ELFMAG0 ||
			elf_header.e_ident[EI_MAG1] != ELFMAG1 ||
			elf_header.e_ident[EI_MAG2] != ELFMAG2 ||
			elf_header.e_ident[EI_MAG3] != ELFMAG3)
		print_error("File is not an ELF");

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x ", elf_header.e_ident[i]);
	printf("\n");
	printf("  Class:                             %s\n",
			elf_header.e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");
	printf("  Data:                              %s\n",
			elf_header.e_ident[EI_DATA] == ELFDATA2LSB ?
			"2's complement, little endian" : "2's complement, big endian");
	printf("  Version:                           %d (current)\n",
			elf_header.e_ident[EI_VERSION]);
	printf("  OS/ABI:                            %d\n",
			elf_header.e_ident[EI_OSABI]);
	printf("  ABI Version:                       %d\n",
			elf_header.e_ident[EI_ABIVERSION]);
	printf("  Type:                              %s\n",
			elf_header.e_type == ET_REL ? "REL (Relocatable file)" :
			elf_header.e_type == ET_EXEC ? "EXEC (Executable file)" :
			elf_header.e_type == ET_DYN ? "DYN (Shared object file)" :
			"UNKNOWN (Unknown file type)");
	printf("  Entry point address:               0x%lx\n",
			(unsigned long)elf_header.e_entry);
}

/**
 * main - Entry point of the program.
 * @argc: The number of arguments.
 * @argv: The array of argument strings.
 *
 * Return: 0 on success, 98 on error.
 */

int main(int argc, char *argv[])
{
	int fd;

	if (argc != 2)
		print_error("Usage: elf_header elf_filename");

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_error("Error: Can't open file");

	print_elf_header_info(fd);

	if (close(fd) == -1)
		print_error("Error: Can't close file");

	return (0);
}
