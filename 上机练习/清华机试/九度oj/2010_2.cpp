#include <stdio.h>
#include <stdlib.h>
#define MAX 1000010

int main()
{

	int *cn,i,N;

	cn=(int *)malloc(MAX*(sizeof(int)));
	cn[0]=0;
	cn[1]=1;

	for(i=2;i<MAX-1;i++)
	{
		if(i%2==1)
			cn[i]=cn[i-1]%1000000000;
		else
			cn[i]=(cn[i/2]+cn[i-1])%1000000000;
	}

	while(scanf("%d",&N)!=EOF)
		printf("%d\n",cn[N]%1000000000);


	return 0;
}
