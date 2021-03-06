#ifdef CS333_P4
#include "types.h"
#include "user.h"

int 
main(int argc, char *argv[])
{
  if(argc<3)printf(0, "Please set pid and priority\n");

  int rc = setpriority(atoi(argv[1]), atoi(argv[2]));
  if(rc == -1)
    printf(0, "An error has occurred while setting priority\n");
  else 
    printf(1, "Priority set successfully\n");
  exit();
}
#endif
