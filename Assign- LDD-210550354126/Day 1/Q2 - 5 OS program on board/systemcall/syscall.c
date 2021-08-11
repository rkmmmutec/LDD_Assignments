#include<stdio.h>

#include <sys/types.h>
#include <sys/stat.h>   //for opening of file
#include <fcntl.h>

#include <unistd.h> //for write


int main()
{


  int fd;
  fd=open("file.txt",O_WRONLY | O_CREAT);
   if(-1==fd)
   {

    perror("Error in opening file:\n");
    return -1;

   }


  write(fd,"Hello World",11);
  close(fd);


  printf("\nSuccessful\n");





return 0;
}
