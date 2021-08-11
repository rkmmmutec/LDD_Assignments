#include<stdio.h>
#include<pthread.h>


int count=0; //global declared variable

void * incThread(void * data)
{

   while (1) {

    count++;
    printf("--inc value :%d\n",count);

   }
}

void * decThread(void * data)
{

  while (1) {

   count--;
   printf("-----dec value: %d\n",count);

  }
}


int main(int argc, char const *argv[]) {


pthread_t inc;
pthread_t dec;

pthread_create(&inc,NULL,incThread,NULL);
pthread_create(&dec,NULL,decThread,NULL);

pthread_join(inc,NULL);
pthread_join(dec,NULL);


  return 0;
}
