/* implement the ps -el|grep pts/0
*/

#include<stdio.h>
#include<unistd.h>
main()
{
	int p[2];
	pipe(p);

	if(fork()==0)
	{
		//close(0);
		//dup(p[0]);
		//close(p[1]);
		dup2(p[0],0);

		execlp("grep","grep","pts/0",NULL);


	}
	else
	{
		//close(1);
		//dup(p[1]);
		//close(p[0]);
		dup2(p[1],1);
		execlp("ps","ps","-el",NULL);

	}

}
