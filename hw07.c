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

  int ary[10], testAry[10];
  int count = 0;

  printf("Filling and printing array:\n");
  while (count < 10) {
    ary[count] = getRand();
    printf("%d : %d\n", count, ary[count]);
    count++;
  }

  printf("\nWriting the numbers to a file\n");
  int fd = open("numbers", O_WRONLY | O_CREAT);
  write(fd, ary, 40);
  close(fd);

  printf("\nReading file and storing values in new array\n");

  printf("\nPrinting new array to verify it worked:\n");
  
}





