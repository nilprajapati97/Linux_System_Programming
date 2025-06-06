#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<dirent.h>
#include<stdlib.h>
main(int argc, char ** argv)
{
if(argc!=2)
{
printf("usage:./a.out d name\n");
return;
}

DIR *dp; 
struct dirent *p;


dp=opendir(argv[1]);
if(dp==0)
{
perror("opendir");
return;

}
while(p=readdir(dp))
if(p->d_name[0]!='.')
printf("%s\n",p->d_name);


}
