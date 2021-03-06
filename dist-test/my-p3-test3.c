#ifdef CS333_P3
#include "types.h"
#include "user.h"
 
int 
main(void)
{
  int pid;
  printf(1,"Forking\n");
  pid = fork();
  if(pid<0){
      printf(2,"An error has occurred while forking!\n");
      exit();
  }
  if(pid == 0){
    printf(1,"Child process is sleeping for 10 seconds\n");
    sleep(10*TPS);
    printf(1,"Child process is exiting normally. \n");
    exit();
  }
  sleep(5*TPS);
  printf(1,"Wait for the child to exit normally. Sleeping for 20 seconds.\n");

  sleep(20*TPS);
  
  printf(1,"Before Wait(). Sleeping for 5 seconds.\n");
  sleep(5*TPS);
  wait();
  printf(1,"After Wait(). Sleeping for 5 seconds. \n");
  sleep(5*TPS);
  exit();
}
#endif
