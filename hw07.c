#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int getRand() {
  int fd = open("/dev/random", O_RDONLY);
  int ret;
  read(fd, &ret, 4); //bc an int is 4 bytes
  close(fd);
  return ret;
}

int main() {

  int ary[10];
  int count = 0;

  printf("Filling and printing array:\n");
  while (count < 10) {
    ary[count] = getRand();
    printf("%d : %d\n", count, ary[count]);
    count++;
  }

}





