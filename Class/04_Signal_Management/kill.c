#include<stdio.h>
#include<sys/types.h>
#include<signal.h>
main(int argc,char **argv)
{
int i;
if(argc!=3)
{
printf("usage:./my_kill signo. pid\n");
return;
}
i=kill(atoi(argv[2]),atoi(argv[1]));
//kill(getpid(),atoi(argv[1]));
printf("%d\n"i);
perror("kill");

}
