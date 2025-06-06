#include<stdio.h>
main()
{
char *p[]={"ls","-l","-i",NULL};
execvp(p[0],p);

}
