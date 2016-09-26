#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
void sort();
void search();
int array[100],limit,key,flag,pos;
main()
{
	int i,j;
	pthread_t thread1, thread2;
	int  iret1, iret2;
	iret1 = pthread_create( &thread1, NULL,sort,NULL);
        iret2 = pthread_create( &thread2, NULL, search,NULL);
	pthread_join( thread1, NULL);
        pthread_join( thread2, NULL); 
	printf("*. ENTER THE NO: OF ELEMENTS::");
	scanf("%d",&limit);
	printf("\n*. ENTER THE ELEMENTS::\n");	
	for(i=0;i<limit;i++)
	{
		scanf("%d",&array[i]);
	}
	

	printf("*. SORTED ARRAY IS::\n");
	for(i=0;i<limit;i++)
	{
		printf("%d  ",array[i]);
	}
		printf("*. ENTER THE KEY ELEMENT::\n");
		scanf("%d",&key);
		if(flag==1)
		printf("==>ELEMENT PRESENT AT THE POSITION::%d",(pos+1));
		else
		printf("==>ELEMENT NOT PRESENT IN THE ARRAY");
}
void sort()
{
	int k,temp,j;
	for(k=0;k<limit-1;k++)
	{
		for(j=k+1;j<limit;j++)
		{
			if(array[k]>array[j])
			{
				temp=array[k];
				array[k]=array[j];
				array[j]=temp;
			}
		}
	}
}
void search()
{
	for(pos=0;pos<limit;pos++)
	{
		if(key==array[pos])
		{
			flag=1;
			break;
		}
		else
			flag=0;
	}
}		


