
#ifdef CS333_P2
#include "types.h"
#include "user.h"
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
  
  printf(1,"\nPID\tName         UID\tGID\tPPID\tPrio\tElapsed\tCPU\tState\tSize\n");
  for(int i=0;i<table_size;i++){
    int s_elapsed_ticks = table[i].elapsed_ticks/1000;
    int ms_elapsed_ticks = table[i].elapsed_ticks%1000;

    int s_cpu_total_ticks =table[i].CPU_total_ticks/1000;
    int ms_cpu_total_ticks =table[i].CPU_total_ticks%1000;
 
   printf(1,"%d\t%s\t     %d\t\t%d\t%d\t%d\t%d.",
   table[i].pid,
   table[i].name,
   table[i].uid,
   table[i].gid,
   table[i].ppid,
   table[i].priority,
   s_elapsed_ticks
   );
   if (ms_elapsed_ticks < 10)  printf(1,"0");
   if (ms_elapsed_ticks < 100) printf(1,"0");
   printf(1,"%d\t%d.",ms_elapsed_ticks,s_cpu_total_ticks);
   if (ms_cpu_total_ticks < 10)  printf(1,"0");
   if (ms_cpu_total_ticks < 100) printf(1,"0");
   printf(1,"%d\t%s\t%d\n",ms_cpu_total_ticks,table[i].state,table[i].size);
 }
  free(table);
  exit();
}
#endif // CS333_P2
