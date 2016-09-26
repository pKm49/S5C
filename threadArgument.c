/*Program :Two counters
	file: threadArgument.c
	Date: 08-08-16

*/

    #include <stdio.h>
    #include <stdlib.h>
    #include <pthread.h>
	#include<unistd.h>

    
void *counter1( void *ptr )
    {
	int i;
         char *message;
         message = (char *) ptr;
         
	for (i=1;i<=10;i++)
	{
		printf("\n%s---i=%d",message,i);
		sleep(1);
	}
    }


void *counter2( void *ptr )
    {
	int id;
	id=(int )ptr;
	int i;

         
	for (i=1000;i<=1020;i++)
	{
		printf("\n%d---i=%d",id,i);
		sleep(2);
	}
    }

    main()
    {
         pthread_t thread1, thread2;
         char *message1 = "Thread 1"; 	//note
         
         int  iret1, iret2;
	int i=2;			//note

        /* Create independent threads each of which will execute function */

         iret1 = pthread_create( &thread1, NULL, counter1, (void*) message1);
         iret2 = pthread_create( &thread2, NULL, counter2, (void*) i);

         /* Wait till threads are complete before main continues. Unless we  */
         /* wait we run the risk of executing an exit which will terminate   */
         /* the process and all threads before the threads have completed.   */

         pthread_join( thread1, NULL);
         pthread_join( thread2, NULL); 

         printf("\nThread 1 returns: %d\n",iret1);
         printf("\nThread 2 returns: %d\n",iret2);
         exit(0);
    }

    
