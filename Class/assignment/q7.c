/*
7)
   modify the above program.So that no two jobs have the common parent.
   {each job have different parent).
   x------bash
   x+1 ---x
   x+2----x+1
   x+3---x+2 
 */

#include<stdio.h>
#include<unistd.h>
main()
{
        if(fork()==0)
        {
                printf("x+1 job..pid=%d ppid=%d \n",getpid(),getppid());


                if(fork()==0)
                {
                        printf("x+2 job..pid=%d ppid=%d \n",getpid(),getppid());

                        if(fork()==0)
                        {
                        printf("x+3 job..pid=%d ppid=%d \n",getpid(),getppid());
                        }
                        else
                        {   wait(0);
                                printf("===x+2...parent pid=%d \n",getpid());
                        }

                }
                else
                {
                        wait(0);
                        printf("===x+1  parent pid=%d ppid=%d \n",getpid(),getppid());
                }


        }
        else
        {    wait(0);
                printf("===x...pid=%d ppid=%d \n",getpid(),getppid());
        }

}

