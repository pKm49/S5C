#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *count1();

int main()
{
     	int i,j;
     	pthread_t thread[250];
      	for(i=0; i < 250; i++)
      	{
      		pthread_create( &thread[i], NULL, count1, (void *)i);
     	}
	for(j=0; j < 250; j++)
     	{
       		pthread_join( thread[j], NULL); 
     	}
     		exit(0);
}
void *count1( void *ptr)
{
	int j,message;
        message=(int)ptr;
 	for(j=1;j<=10;j++)
	{
		sleep(2);
		printf("Thread %d:%d\n",message,j);
	}
}
