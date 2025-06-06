#include<stdio.h>
#include<string.h>
main()
{
	FILE *fp;
	char l[256]={},cmd[64]={};
	int i=0,cl=0,j=0;

	if(!(fp=fopen("makefile","r")))
	{
		perror("makefile");
		return;
	}

	while(fgets(l,257,fp))
	{
		{
			for(i=0;l[i];i++)
			{
				if(l[i]=='c' && l[i+1]=='c')
				{
					if(cl!=0)
					for(;l[i];i++)
					cmd[j++]=l[i];
					
					system(cmd);
					cl++;
					j=0;
					bzero(cmd,sizeof(cmd));
				}
			}
		}
	}

	rewind(fp);
	

	fgets(l,257,fp);
	if(strstr(l,"outfile:"))
	{
		fgets(l,257,fp);
		for(i=0;l[i];i++)
		{
			if(l[i]=='c' && l[i+1]=='c')
			{
				for(;l[i];i++)
				cmd[j++]=l[i];
				system(cmd);
			}
		}
	}
}
