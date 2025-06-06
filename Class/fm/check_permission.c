#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
main(int argc,char **argv)
{
struct stat v;
if(argc!=2)
{
printf("usage:./a.out fname\n");
return;
}

if(stat(argv[1],&v)<0)
{
perror("stat");
return;
}

//printf("st_mode=%o\n",v.st_mode);
//printf("st_mode=%o",v.st_mode&0777);
//printf("size=%d\n",v.st_size);

if(S_ISREG(v.st_mode))
printf("reguleer....\n");
else if(S_ISDIR(v.st_mode))
printf("dir...\n");

}
