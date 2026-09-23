#include "kernel/types.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  char* address = sbrk(100);
  *address = 0x12;
  mprotect(address);
  // *address = 0x34;
  printf("%d\n", (int)(*address));
  munprotect(address);
  *address = 0x56;
  printf("%d\n", (int)(*address));
  printf("%d\n", mprotect((void*)1));
  printf("%d\n", mprotect((void*)0xffffffffff));
  exit(0);
}