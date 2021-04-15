
#ifdef CS333_P2
#include "types.h"
#include "user.h"
#include "ps.h"

int
main(int argc, char *argv[])
{
 
  uint max;
  struct uproc *table = malloc(max);

  int table_size;
  if (table_size=getprocs(max,&table)) {
    printf(2,"Error: ps call failed. %s at line %d\n",
        __FILE__, __LINE__);
    exit();
  }
  for(int i=0;i<table_size;i++){
    // cprintf("%s",table[i]->)
  }

  exit();
}
#endif // CS333_P2
