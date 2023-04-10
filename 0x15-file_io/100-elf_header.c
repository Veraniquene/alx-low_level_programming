#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <elf.h>

void print_error(const char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(98);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_error("Usage: elf_header elf_filename");
    }

    const char *filename = argv[1];
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        print_error("Error: could not open file");
    }

    Elf64_Ehdr header;
    ssize_t bytes_read = read(fd, &header, sizeof(header));
    if (bytes_read != sizeof(header)) {
        print_error("Error: could not read ELF header");
    }

    if (header.e_ident[EI_MAG0] != ELFMAG0 ||
        header.e_ident[EI_MAG1] != ELFMAG1 ||
        header.e_ident[EI_MAG2] != ELFMAG2 ||
        header.e_ident[EI_MAG3] != ELFMAG3) {
        print_error("Error: not an ELF file");
    }

    printf("Magic:   %02x %02x %02x %02x\n",
           header.e_ident[EI_MAG0],
           header.e_ident[EI_MAG1],
           header.e_ident[EI_MAG2],
           header.e_ident[EI_MAG3]);
    printf("Class:   %d\n", header.e_ident[EI_CLASS]);
    printf("Data:    %d\n", header.e_ident[EI_DATA]);
    printf("Version: %d\n", header.e_ident[EI_VERSION]);
    printf("OS/ABI:  %d\n", header.e_ident[EI_OSABI]);
    printf("ABI Version: %d\n", header.e_ident[EI_ABIVERSION]);
    printf("Type:    %d\n", header.e_type);
    printf("Entry point address: 0x%lx\n", header.e_entry);
    printf("Format:  %d-bit %s, %s, version %d\n",
           header.e_ident[EI_CLASS] == ELFCLASS32 ? 32 : 64,
           header.e_ident[EI_DATA] == ELFDATA2LSB ? "LSB" : "MSB",
           header.e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64",
           header.e_ident[EI_VERSION]);

    close(fd);
    return 0;
}
