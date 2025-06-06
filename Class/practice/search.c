#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<dirent.h>
#include<string.h>
int  serch(char *a,char *b);
static int c=0;

main(int argc,char **argv)
{
        if(argc!=3)
        {
                printf("usage:./a.out path filename\n");
                return;
        }


        c=serch(argv[1],argv[2]);
        printf("in main c=%d\n",c);
}

int serch(char *a,char *b)
{
        struct dirent *p;
        DIR *dp;
        int j;
        char t[10000];


        dp=opendir(a);

        if(dp<0)
        {
                perror("opendir");
                return;
        }
        //printf("%s\n",a);
        //printf("%s\n",b);i



        while(p=readdir(dp))
        {
                if(p->d_name[0]!='.')
                {
                                printf("file:%s\n",p->d_name);
                        if(strcmp(b,p->d_name)==0)
                        {
                     	         c++;
                                printf("c=%d\n",c);
                        }
                        else if(p->d_type == DT_DIR)
                        {
                                //bzero(t,sizeof(t));
                                strcpy(t,a);
                                strcat(t,"/");
                                strcat(t,p->d_name);
                                printf("%s\n",t);
                                serch(t,b);
                        }
                }
        }
return c;

}




  
