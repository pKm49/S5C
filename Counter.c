#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
void *Function1();
//void *Function2();
main(){
	int i;
	//int *mnt = malloc(sizeof(int));
	//*mnt= 20;
	pthread_t thr1, thr2;
	char *thr1msg= "thread 1";
	char *thr2msg= "thread 2";
	//char *cnt= "10";
	int ret1,ret2;
	for(i=0;i<10;i++){
		ret1=pthread_create(&thr1, NULL, (void*)&Function1, (void*) thr1msg);
		//ret2=pthread_create(&thr2, NULL, (void*)&Function1, (void*) thr2msg);
		pthread_join(thr1,NULL);
		//pthread_join(thr2,NULL);
	}
	//pthread_join(thr1,NULL);
	exit(0);
}

void *Function1(void *ptr){
	int i=0;
	char *msg;
	//int *cnt= malloc(sizeof(int));
	//int cnt= *((int *) ptr);
	msg= (char *) ptr;
	for(i=1;i<=100;i++){
		printf("%d %s\n",i,msg);
		sleep(1);
	}
}

/*void *Function2(void *ptr){
int i;
char *msg;
msg= (char *) ptr;
printf("%s:",msg);
for(i=1;i<=100;i++){
printf("%d \n",i);
sleep(3);}
}
*/

