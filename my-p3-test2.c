#ifdef CS333_P3
#include "types.h"
#include "user.h"

int 
main(void)
{
  int pid;
  printf(1,"Process is sleeping now\n");
  sleep(5000);
  printf(1,"Forking\n");
  pid = fork();
  if(pid<0){
      printf(2,"An error has occurred while forking!\n");
      exit();
  }
  if(pid == 0){
    printf(1,"Child process is in SLEEPING state\n");
    sleep(5000);
    exit();
  }else{
    wait();
    printf(1,"Child process has exited\n")
  }
  exit();
}
#endif