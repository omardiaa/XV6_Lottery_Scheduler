// #ifdef CS333_P3
// #include "types.h"
// #include "user.h"

// int 
// main(void)
// {
//   int pid;
//   printf(1,"Process is sleeping now\n");
//   sleep(5000);
//   printf(1,"Forking\n");
//   pid = fork();
//   if(pid<0){
//       printf(2,"An error has occurred while forking!\n");
//       exit();
//   }
//   if(pid == 0){
//     printf(1,"Child process is in SLEEPING state\n");
//     sleep(5000);
//     exit();
//   }else{
//     printf(1,"Before Wait\n");
//     sleep(5000);
//     wait();
//     printf(1,"After Wait\n");
//     sleep(5000);
//     printf(1,"Child process has exited\n");
//   }
//   exit();
// }
// #endif


#ifdef CS333_P3
#include "types.h"
#include "user.h"
#include "param.h"
#include "pdx.h"

int
main(int argc, char *argv[])
{
  int rc, i = 0, childCount = 2;

  if (argc > 1) {
    childCount = atoi(argv[1]);
  }
  if (!childCount) {
    printf(1, "No children to create, so %s is exiting.\n", argv[0]);
    exit();
  }

  printf(1, "Starting %d child processes\n", childCount);

  do {
    rc = fork();
    if (rc < 0) {
      printf(2, "Fork failed!\n");
      exit();
    }
    if (rc == 0) { // child process
      sleep(30*TPS);
      printf(1, "\n-->Child exiting normally.  View with Control-Z and Control-P\n");
      exit();
    }
    childCount--;
  } while(childCount);

  printf(1, "\nAll child processes created.  View with Control-P\n");
  sleep(10*TPS);
  printf(1, "\nQuickly kill one child.  View with Control-Z and Control-P\n");
  sleep(10*TPS);
  printf(1, "\nWait for other child to exit normally\n");
  sleep(50*TPS);
  printf(1, "\nCheck UNUSED list.  View with Control-F\n");
  sleep(10*TPS);
  printf(1, "\nReap both children with wait.  View with Control-F and Control-P\n");
  wait();
  while(1) i++;  // parent loops forever
  exit();  // not reachable
}
#endif // CS333_P3
