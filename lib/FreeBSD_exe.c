#include "pkg/elf_sc.h"
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main() {

    // FreeBSD support right now is broken, will try fix soon

    // Check if elf_len is valid
    if (elf_len == 0) {
        fprintf(stderr, "Error: elf_len is zero. No ELF binary to execute.\n");
        return EXIT_FAILURE;
    }

    // Allocate memory for the ELF binary
    void *exec_mem_elf = mmap(NULL, elf_len, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (exec_mem_elf == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    // Copy the ELF binary into the allocated memory
    memcpy(exec_mem_elf, elf, elf_len);

    // Change the memory protection to executable
    if (mprotect(exec_mem_elf, elf_len, PROT_READ | PROT_EXEC) == -1) {
        perror("mprotect");
        munmap(exec_mem_elf, elf_len);
        exit(EXIT_FAILURE);
    }

    /* Execute the ELF */
    char *args[] = { NULL };
    if (execve(exec_mem_elf, args, NULL) == -1) {
        perror("execve");
        munmap(exec_mem_elf, elf_len);
        exit(EXIT_FAILURE);
    }
   
    // Cleanup
    munmap(exec_mem_elf, elf_len);
    return EXIT_SUCCESS;
}
