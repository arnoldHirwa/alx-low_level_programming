#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

/**
* print_magic - Prints the ELF magic bytes.
* @ident: The ELF identification bytes.
*
* Description: This function prints the magic bytes from the ELF header.
*/
void print_magic(unsigned char *ident)
{
	int index;

	printf("  Magic:   ");
	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", ident[index]);
		if (index == EI_NIDENT - 1)
			continue;
		printf(" ");
	}
	putchar('\n');
}

/**
 * check_elf - Checks if a file is an ELF file.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: If the file is not an ELF file - exit code 98.
 */
void check_elf(unsigned char *e_ident)
{
	int index;

	for (index = 0; index < 4; index++)
	{
		if (e_ident[index] != 127 &&
		    e_ident[index] != 'E' &&
		    e_ident[index] != 'L' &&
		    e_ident[index] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
* print_class - Prints the ELF file class.
* @ident: The ELF identification bytes.
*
* Description: This function prints the ELF file class (32-bit or 64-bit).
*/
void print_class(unsigned char *ident)
{
	printf("  Class:                             ");
	if (ident[EI_CLASS] == ELFCLASS32)
	{
		printf("ELF32");
	}
	else if (ident[EI_CLASS] == ELFCLASS64)
	{
		printf("ELF64");
	}
	else
	{
		printf("Unknown");
	}
	printf("\n");
}

/**
* print_data - Prints the data encoding (endianess) of the ELF file.
* @ident: The ELF identification bytes.
*
* Description: This function prints the data encoding of the ELF file.
*/
void print_data(unsigned char *ident)
{
	printf("  Data:                              ");
	if (ident[EI_DATA] == ELFDATA2LSB)
	{
		printf("2's complement, little endian\n");
	}
	else if (ident[EI_DATA] == ELFDATA2MSB)
	{
		printf("2's complement, big endian\n");
	}
	else if (ident[EI_DATA] == ELFDATANONE)
	{
		printf("none\n");
	} else
	{
		printf("<unknown: %x>\n", ident[EI_CLASS]);
	}
}

/**
 * print_version - Prints the version of an ELF header.
 * @ident: A pointer to an array containing the ELF version.
 */
void print_version(unsigned char *ident)
{
	printf("  Version:                           %d",
	       ident[EI_VERSION]);

	switch (ident[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
* print_osabi - Prints the OS/ABI of the ELF file.
* @eident: The ELF identification bytes.
*
* Description: This function prints the OS/ABI of the ELF file.
*/
void print_osabi(unsigned char *eident)
{
	printf("  OS/ABI:                            ");

	switch (eident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", eident[EI_OSABI]);
	}
}

/**
* print_abi - Prints the ABI version of the ELF file.
* @ident: The ELF identification bytes.
*
* Description: This function prints the ABI version of the ELF file.
*/

void print_abi(unsigned char *ident)
{
	printf("  ABI Version:                       %d\n",
		ident[EI_ABIVERSION]);
}

/**
* print_type - Prints the type of the ELF file.
* @e_type: The ELF file type.
* @ident: The ELF identification bytes.
*
* Description: This function prints the type of the ELF file.
*/
void print_type(unsigned int e_type, unsigned char *ident)
{
	if (ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:                              ");

	switch (e_type)
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
		printf("<unknown: %x>\n", e_type);
	}
}

/**
 * print_entry - Prints the entry point of an ELF header.
 * @entry: The address of the ELF entry point.
 * @ident: A pointer to an array containing the ELF class.
 */
void print_entry(unsigned long int entry, unsigned char *ident)
{
	printf("  Entry point address:               ");

	if (ident[EI_DATA] == ELFDATA2MSB)
	{
		entry = ((entry << 8) & 0xFF00FF00) |
				((entry >> 8) & 0xFF00FF);
		entry = (entry << 16) | (entry >> 16);
	}

	if (ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)entry);

	else
		printf("%#lx\n", entry);
}

/**
 * main - Displays the information contained in the
 *        ELF header at the start of an ELF file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the file is not an ELF File or
 *              the function fails - exit code 98.
 */

int main(int argc, char *argv[])
{
	int r, o;
	Elf64_Ehdr elf_header;

	if (argc != 2)
	{
		dprintf(2, "Usage: elf_header elf_filename\n");
		exit(97);
	}

	o = open(argv[1], O_RDONLY);
	if (o == -1)
	{
		dprintf(2, "Error: Can't open %s file\n", argv[1]);
		exit(98);
	}

	r = read(o, &elf_header, sizeof(elf_header));
	if (r == -1)
	{
		dprintf(2, "Error: Can't read %s file\n", argv[1]);
		exit(98);
	}
	check_elf(elf_header.e_ident);
	printf("ELF Header:\n");
	print_magic(elf_header.e_ident);
	print_class(elf_header.e_ident);
	print_data(elf_header.e_ident);
	print_version(elf_header.e_ident);
	print_osabi(elf_header.e_ident);
	print_abi(elf_header.e_ident);
	print_type(elf_header.e_type, elf_header.e_ident);
	print_entry(elf_header.e_entry, elf_header.e_ident);

	close(o);
	return (0);
}
