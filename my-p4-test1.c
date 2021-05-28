#ifdef CS333_P4
#include "types.h"
#include "user.h"

int 
main(void)
{
  
  int rc = setpriority(1, 5);
  if(rc == -1)
	  printf(0, "An error has occurred while setting priority\n");
  else 
	  printf(1, "Priority set successfully\n");
  exit();
}
#endif
