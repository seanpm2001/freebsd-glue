#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

int
main (int argc, char **argv)
{
  int fd;
  Elf32_Ehdr ehdr;

  fd = open (argv[0], O_RDONLY);
  if (fd == -1)
    perror ("open");

  if (read (fd, &ehdr, sizeof (ehdr)) != sizeof (ehdr))
    perror ("read");

  printf ("#define ELF_ARCH %u\n", ehdr.e_machine);

  close (fd);

  return 0;
}
