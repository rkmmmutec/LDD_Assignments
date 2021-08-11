#include<stdio.h>

#include <sys/types.h>
#include <unistd.h>


int main()
{

  pid_t id,ppid;  //id is instance of pid_t
  pid_t tid;


  id=getpid();
  ppid=getppid();
  tid=gettid();
  gid_t gid;
  gid=getgid();

  printf("PID : %d\n",id); // for process id
  printf("PPID : %d\n",ppid); // for parent id
  printf("--TID : %d\n",tid); // for thread id
  printf("--GID : %d\n",gid); // for group id


return 0;
}
