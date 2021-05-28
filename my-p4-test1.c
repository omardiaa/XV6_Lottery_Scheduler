#ifdef CS333_P4
#include "types.h"
#include "user.h"

int 
main(void)
{
  int pid = getpid();
  int rc = getpriority(pid);
  if(rc == -1)
	  printf(0, "An error has occurred while setting priority\n");
  else 
	  printf(1, "Priority of pid %d is %d\n", pid, rc);
  exit();
}
#endif
