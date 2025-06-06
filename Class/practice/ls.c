#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<dirent.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

DIR *dp;
struct dirent *p;
struct stat v;
void ls();
void ls_ls(char *);
void ls_li(char *);
void ls_l(char *);
void print_mode(int);
void dir_path(char *);
void print_name();
void print_name2();
main(int argc, char ** argv)
{
	if(argc==1)
	{
		ls();
	}

	else if(argc==2)
	{
		if(argv[1][0]!='-')
			dir_path(argv[1]);
		else if(argv[1][0]=='-')
		{
			if(!(strcmp("-ls",argv[1])))
				ls_ls("./");
			else if(!(strcmp("-l",argv[1])))
				ls_l("./");
			else if(!(strcmp("-li",argv[1])))
				ls_li("./");

		}
	}

	else if(argc==3)
	{
		if(argv[1][0]=='-')
		{
			if(!(strcmp("-ls",argv[1])))
				ls_ls(argv[2]);
			else if(!(strcmp("-l",argv[1])))
				ls_l(argv[2]);
			else if(!(strcmp("-li",argv[1])))
				ls_li(argv[2]);



		}
	}

//system("echo  \x1b[34m""dinesh");


}
////////////////////////////////////////////////////////
void ls_li(char *str)
{
 char s[100];
        int ret,i,j;
        dp=opendir(str);
        if(dp==0)
        {
                perror("opendir");
                return;
        }
        while(p=readdir(dp))
        {
                //if(p->d_name[0]!='.')
                {
                lstat(p->d_name,&v);
                printf("\x1b[0m%-8d  ",(int)v.st_ino);
	//	printf("%o ",v.st_mode);
                ret=v.st_mode& 0777;
	//	for(j=8;j>=0; j--)
	//	printf("%d ",ret>>j&1);
	//	printf("%o ",ret);
                print_mode(ret);
                printf(" %3d  ",v.st_nlink);
                printf("%s  ",getenv("LOGNAME"));
		printf("%s ",getenv("USER"));
	        printf("%d  ",v.st_uid);	
                printf("%-6d  ",(int)v.st_size);
                strcpy(s,(char*)ctime(&v.st_mtime));
                s[strlen(s)-1]='\0';
                printf("%s ",s);
		
		print_name2();	
		
			
                	
        	}

	}
}
///////////////////////////////////////////////////
void print_mode(int ret)
{
	int i;

	if(S_ISREG(v.st_mode))
		printf("-");
	else if(S_ISDIR(v.st_mode))
	{		
                //system("echo  \x1b[34m""d \x1b[0m");
		printf("d");
		//system("echo \x1b[0m");
	}
	else if(S_ISCHR(v.st_mode))
		printf("c");
	else if(S_ISBLK(v.st_mode))
		printf("b");
	else if(S_ISLNK(v.st_mode))
		printf("l");


	for(i=8;i>=0;i--)
	{
	
		if(ret>>i&1)
		{
			if(i==0||i==3||i==6)
				printf("x");
			else if(i==1||i==4||i==7)
				printf("w");
			else if(i==2||i==5||i==8)
				printf("r");
		}
		else
			printf("\x1b[0m-");
	}

}

///////////////////////////////////////////////////
void ls_l(char *str)
{
	char s[100];
	int ret,i,block=0;
	dp=opendir("./");
	if(dp==0)
	{
		perror("opendir");
		return;
	}

	while(p=readdir(dp))
	{
		if(p->d_name[0]!='.')
		{
			lstat(p->d_name,&v);
			block=block+v.st_blocks;
		}
	}
	printf("total %-3d\n",block);
	closedir(dp);

	dp=opendir("./");
	while(p=readdir(dp))
	{
		if(p->d_name[0]!='.')
		{
			lstat(p->d_name,&v);
			ret=v.st_mode& 0777;
			print_mode(ret);
			printf(" %-2d",v.st_nlink);
			printf("%-10s",getenv("USER"));
			printf("%-6d",(int)v.st_size);
			strcpy(s,(char *)ctime(&v.st_mtime));
			s[strlen(s)-1]='\0';
			printf("%s ",s);
			
			print_name2();
		}
	}




} 







//////////////////////////////////////////////////////
void ls_ls(char *str)
{

	char s[128];
	int ret,i;
	char ch[100];

	dp=opendir(str);
	if(dp==0)
	{
		perror("opendir");
		return;

	}
	while(p=readdir(dp))
	{
		if(p->d_name[0]!='.')
		{
			lstat(p->d_name,&v);

			printf("%-3d",(int)v.st_blocks);
			ret=v.st_mode&0777;
			print_mode(ret);

			printf(" %-2d",v.st_nlink);
			printf("%-10s",getenv("LOGNAME"));
			printf("%-6d",(int)v.st_size);
			strcpy(s,(char *)ctime(&v.st_mtime));
			s[strlen(s)-1]='\0';
			printf("%s ",s); 
		
			print_name2();	


		}


	}

}




//////////////////////////////////////////////
void dir_path(char *str)
{
	dp=opendir(str);
	if(dp==0)
	{
		perror("opendir");
		return;
	}
	while(p=readdir(dp))
	{
		if(p->d_name[0]!='.')
			printf("%s ",p->d_name);
	}





}

///////////////////////////////////////////
void ls()
{
		
	int i,ret;
	char ch[100];
        dp=opendir("./");
	if(dp==0)
	{
		perror("opendir");
		return;
	}
	
	while(p=readdir(dp))
	{
		if(p->d_name[0]!='.')
		{      
	
			lstat(p->d_name,&v);
			
		print_name();	
		}

	}
	printf("\n");
}

///////////////////////////////////////////////////////////
void print_name()
{
char ch[100];
int i;
			sprintf(ch,"%o",v.st_mode);
			i=atoi(ch);
			i=i%10;
			if(S_ISDIR(v.st_mode))
			{
			printf("\x1b[01;34m%15s\t",p->d_name);
			}
			else if (!S_ISDIR(v.st_mode)&& (i==1 ||i==3||i==5||i==7))
			printf("\x1b[01;32m%15s\t",p->d_name);
			else
			printf("\x1b[0m%15s\t",p->d_name);


}
///////////////////////////////////////////////////////////////////

void print_name2()
{
char ch[100];
int i;
			sprintf(ch,"%o",v.st_mode);
			i=atoi(ch);
			i=i%10;
			if(S_ISDIR(v.st_mode))
			{
			printf("\x1b[01;34m%s\n",p->d_name);
			}
			else if (!S_ISDIR(v.st_mode)&& (i==1 ||i==3||i==5||i==7))
			printf("\x1b[01;32m%s\n",p->d_name);
			else
			printf("\x1b[0m%s\n",p->d_name);


}















