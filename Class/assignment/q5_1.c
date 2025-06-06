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
	char s[50];
        
//	execlp(argv[1],argv[1],NULL);
	for(i=1;i<argc;i++)
	{
		if(fork()==0)
		{
		execlp(argv[i],argv[i],NULL);
			
		}
		else
		{
		 wait(0);
		}	
	}
	while(1);
}

