#include<stdio.h>
#include<setjmp.h>
int sum(int ,int);
int sub (int ,int);
int mul(int ,int );
int dive(int ,int );
jmp_buf v;
main()
{
	int n1,n2,n3,op,r;

	printf("hello...\n");

	r=setjmp(v);

	if(r==3)
		printf("error in mul...\n");
	else if(r==4)
		printf("error in dive...\n");


	printf("enter the number...\n");
	scanf("%d%d",&n1,&n2);
	printf("enter the option...\n");
	scanf("%d",&op);

	if(op==1)
	{
		n3=sum(n1,n2);
		printf("n3=%d\n",n3);
	}

	else if(op==2)
	{
		n3=sub(n1,n2);
		printf("n3=%d\n",n3);
	}
	else if(op==3)
	{
		n3=mul(n1,n2);
		printf("n3=%d\n",n3);
	}
	else if(op==4)
	{
		n3=dive(n1,n2);
		printf("n3=%d\n",n3);
	}
	else 
		printf("invalid option...\n");



}
int sum(int i,int j)
{

	return i+j;

}
int sub(int i,int j)
{
	return i-j;

}
int mul(int i, int j)
{
	if(i==0 || j== 0)
		longjmp(v,3);

	return(i*j);

}
int dive(int i,int j)
{
	if(i==0 || j==0)
		longjmp(v,4);

	return(i/j);

}

