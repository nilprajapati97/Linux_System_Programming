/*
1. Write a program to execute ls , pwd & cal sequentially
a) Using system( )
  	       b) Using exec( )
		Hint : use fork().
*/
////   using   system  
/*
#include<stdio.h>
main()
{
system("ls");
system("pwd");
system("cal");

}
 */

///// using exec

#include<stdio.h>
#include<unistd.h>
main()
{

	if(fork()==0)
	{
		execl("/bin/ls","ls",NULL);
	}
	else
	{
		wait(0);
		if(fork()==0)
		{
			execl("/bin/pwd","pwd",NULL);

		}
		else
		{
			wait(0);
			if(fork()==0)
			{
				execl("/usr/bin/cal","cal",NULL);
			}
			else
			{
			wait(0);
			}
		}

	}



}
