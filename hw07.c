#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int getRand() {
  int fd = open("/dev/random", O_RDONLY);
  //might be a problem with ret
  int * ret;
  read(fd, ret, 4); //bc an int is 4 bytes
  printf("a is: %d\n", *ret);
  close(fd);
  return *ret;
}

int main() {

  int * ;
  printf("%d\n", sizeof(getRand()));

}





