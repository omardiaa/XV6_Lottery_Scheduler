
#ifdef CS333_P2
#include "types.h"
#include "user.h"
#include "ps.h"
#include "uproc.h"

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
  int max = atoi(argv[1]);
  struct uproc *table;
  table = malloc(sizeof(struct uproc) * max);

  int table_size;
  table_size=getprocs(max,table);
  if (table_size<0) {
    printf(1,"Table size: %d\n",table_size);
    printf(2,"Error: ps call failed. %s at line %d\n",
        __FILE__, __LINE__);
    exit();
  }
  printf(1,"PID\tUID\tGID\tPPID\tElapsed Ticks\tCPU Total Ticks\tState\tSize\tName\n");
  for(int i=0;i<table_size;i++){
     printf(1,"%d\t%d\t%d\t%d\t%d\t\t%d\t\t%s\t%d\t%s\n",table[i].pid,table[i].uid,table[i].gid,table[i].ppid,table[i].elapsed_ticks,table[i].CPU_total_ticks,table[i].state,table[i].size,table[i].name);
  }

  exit();
}
#endif // CS333_P2
