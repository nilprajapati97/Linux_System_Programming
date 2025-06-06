/*
4. Write a program to pass num of commands each seperated by delimiter(,) through command line.
                  I/p :   ./a.out   ls,pwd,cal,date
*/
#include<stdio.h>
#include<string.h>
main(int argc,char **argv)
{
	int i,n;
	n=strlen(argv[1]);
	char s[n+1];
	strcpy(s,argv[1]);
	for(i=0;s[i];i++)
	{
		if(s[i]==',')
			s[i]=';';
	}
	s[i]='\n';
	system(s);
}
