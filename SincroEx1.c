#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex; 
int count = 0; 

void* thread(void* arg) 
{
    int i;
    
    for (i = 0; i < 100; i++) {
    
        pthread_mutex_lock(&mutex); 
    
        count++; 
    
        pthread_mutex_unlock(&mutex); 
    
    }
    
    pthread_exit(NULL);
}

int main() 
{
    pthread_t t1, t2, t3, t4, t5;
    
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
  
    pthread_create( &t1, NULL, thread, NULL );
    
    pthread_create( &t2, NULL, thread, NULL );
    
    pthread_create( &t3, NULL, thread, NULL );
    
    pthread_create( &t4, NULL, thread, NULL );
    
    pthread_create( &t5, NULL, thread, NULL );
  
  
     pthread_join( t1, NULL);
     
     pthread_join( t2, NULL);
     
     pthread_join( t3, NULL);
     
     pthread_join( t4, NULL);
     
     pthread_join( t5, NULL);
     
  
    printf("\n\nEl contador llego a:  %d\n\n\n", count);

    pthread_mutex_destroy(&mutex); 
    
    return 0;
}
