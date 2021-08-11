#include<stdio.h>
#include<pthread.h>

int count=0;
pthread_mutex_t mutex_count;


void * incThread(void *data)
{

   while(1)
   {

  pthread_mutex_lock(&mutex_count); //putting lock

   count++;
   printf("--INC value: %d\n",count);

   pthread_mutex_unlock(&mutex_count); // unlocking mutex


   }


}

void * decThread(void *data)
{

  while(1)
  {

   pthread_mutex_lock(&mutex_count); //putting lock

   count--;
   printf("------DEC value: %d\n",count);

   pthread_mutex_unlock(&mutex_count); //Unlocking mutex

   }

}


int main(int argc, char const *argv[]) {

pthread_t inc;
pthread_t dec;


pthread_mutex_init(&mutex_count,NULL);  //initilizing mutex

pthread_create(&inc,NULL,incThread,NULL);
pthread_create(&dec,NULL,decThread,NULL);

pthread_join(inc,NULL);
pthread_join(dec,NULL);

pthread_mutex_destroy(&mutex_count); //destroying mutex

  return 0;
}
