#include<stdio.h>
//for pthread_create
#include<pthread.h>


  void * tempthread(void *data)
  {
        printf("---In temperature thread\n");
  }

int main(int argc, char const *argv[]) {


   pthread_t p_th;

   printf("BEfore threading\n");
   pthread_create( &p_th,NULL,tempthread,NULL);
   pthread_join(p_th,NULL);
   printf("After thereading\n");


  return 0;
}
