#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

//function for checking if there was an error
void check(int fd) {
  if (fd == -1) {
    printf("ERRNO: %s\n", strerror(errno));
  }
}

// open /dev/random as read only; read 4 byes (int) into int ret. 
int getRand() {
  int fd = open("/dev/random", O_RDONLY);
  int ret;
  check(fd);
  read(fd, &ret, 4); 
  close(fd);
  return ret;
}

int main() {
  
  int arrR[10], arrW[10];
  int count;

  // read from /dev/random 10 times; printing as the file is being read
  printf("\nGenerating random numbers:\n");
  for (count = 0; count < 10; count++) {
    arrR[count] = getRand();
    printf("arrR[%d] : %d\n", count, arrR[count]);
  }

  //create file with rwxr--r--; writes from arrR to file 40 bytes (10 ints); 
  printf("\nWriting numbers to a file...\n");
  int fd = open("numbers", O_WRONLY | O_CREAT, 0744);
  check(fd);
  int error = write(fd, arrR, 40);
  check(error);
  close(fd);

  //open file created for read only; read from file 40 bytes into arrW
  printf("\nReading numbers from file...\n");
  fd = open("numbers", O_RDONLY);
  check(fd);
  error = read(fd, arrW, 40);
  check(error);
  close(fd);

  //for loop to print each value in arrW; should match arrR
  printf("\nVerification that written values were the same:\n");
  for (count = 0; count < 10; count++) {
    printf("arrW[%d] : %d\n", count, arrW[count]);
  }
}





