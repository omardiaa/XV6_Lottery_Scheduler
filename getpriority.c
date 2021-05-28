#ifdef CS333_P4
#include "types.h"
#include "user.h"

int 
main(int argc, char *argv[])
{
  if(argc<2)cprintf(0, "Please set pid\n");

  int rc = getpriority(argv[1]);
  if(rc == -1)
	  printf(0, "An error has occurred while getting priority\n");
  else 
	  printf(1, "Priority is: %d\n", rc);
  exit();
}
#endif
