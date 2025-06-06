/*
5. Write a program to execute the no of commands from command line
a) using system( )
b) using exec()
              Note : no of new process create must be euql to no of cmd given at command line)

*/
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<wait.h>
main(int argc,char **argv)
{
	int i,n;
	char s[50],a[50];
	strcpy(a,argv[1]);
	system(a);

	for(i=2;i<argc;i++)
	{
		if(fork()==0)
		{
			n=strlen(argv[i]);
			strcpy(s,argv[i]);
			s[n]='\n';
			s[n+1]='\0';
			system(s);
		//exit(0);
		}
		else
		wait(0);
		
	}	
	
	while(1);
}

