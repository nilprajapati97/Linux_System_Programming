#include<stdio.h>
#include<sys/stat.h>
#include<sys/stat.h>
#include<unistd.h>
main(int argc,char **argv)
{

struct stat v,v1;
if(argc!=3)
{
printf("usage:./a.out fname fname\n");
return;
} 

if(stat(argv[1],&v)<0)
{
perror("stat");
return;
}
if(stat(argv[2],&v1)<0)
{
perror("stat");
return;
}

if(v.st_ino==v1.st_ino)
{
lstat(argv[1],&v);
lstat(argv[2],&v1);
if(v.st_ino==v1.st_ino)
printf("hard link..\n");
else
printf("soft link....\n");



}
else 
printf("no link....\n");
}
