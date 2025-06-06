#include<stdio.h>
main()
{


if(fork()==0)
{
printf("in child...\n");
sleep(10);
exit(1);
}
else
{
int s,r;
printf("in parent.\n");
r=wait(&s);
printf("in parent after wait s=%d,r=%d\n",s,r);


if(WIFEXITED(s))
{
printf("normal...%d\n",WEXITSTSTUS(s));
}
else if(WIFSIGNALED(s))
{
printf("signal ...%d\n",WTERMSIG(s));

}

}



}
