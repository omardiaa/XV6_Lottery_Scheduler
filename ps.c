
#ifdef CS333_P2
#include "types.h"
#include "user.h"
#include "ps.h"

int
main(int argc, char *argv[])
{
  if(argc<2){
    printf(1,"Error: max value must be specified\n");
    exit();
  }else if(argc>2){
    printf(1,"Error: too many arguments\n");
    exit();
  }
  uint max = atoi(argv[1]);
  struct uproc *table = malloc(max);

  int table_size=getprocs(max,table);
  if (table_size<0) {
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
