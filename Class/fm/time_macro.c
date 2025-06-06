#include<stdio.h>
#include<time.h>
#include<sys/stat.h>
#include<sys/types.h>
main(int argc ,char **argv)
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

printf("atime=%d\n",v.st_atime);
printf("mtime=%d\n",v.st_mtime);
printf("ctime=%d\n",v.st_ctime);

printf("atime=%s\n",ctime(&v.st_ctime));
printf("mtime=%s\n",ctime(&v.st_ctime));
printf("ctime=%s\n",ctime(&v.st_ctime));

}
