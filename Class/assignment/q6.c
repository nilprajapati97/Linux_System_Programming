/*
6. Write a program to creat  3 new  jobs , in such a manner that all the 3 new jobs should have common parent.
x------bash
x+1 ---x
x+2----x
x+3--- x

*/

#include<stdio.h>
#include<unistd.h>
main()
{

        if(fork()==0)
        {
                printf("In job 1..pid=%d ppid=%d \n",getpid(),getppid());
                sleep(2);
        }
        else
        {
                if(fork()==0)
                {
                        printf("In job 2 pid=%d ppid=%d\n",getpid(),getppid());
                        sleep(2);
                }
                else
                {
                        if(fork()==0)
                        {
                        printf("In job 3 pid=%d ppid=%d\n",getpid(),getppid());
                                sleep(2);
                        }
                        else
                        {
                        printf("In parent..pid=%d ppid=%d\n",getpid(),getppid());
                                sleep(2);
                        }
                }
        }

}

