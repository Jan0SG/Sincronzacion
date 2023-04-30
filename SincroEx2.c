#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int hello_written = 0;

void* hola(void* arg) 
{
    pthread_mutex_lock(&mutex);
    
    printf("\n\nHello");
    
    hello_written = 1;
    
    pthread_mutex_unlock(&mutex);
    
    return NULL;
}

void* mundo(void* arg) 
{
    while (1) 
    {
        pthread_mutex_lock(&mutex);
        
        if (hello_written != 0) 
        {
        
            printf(" World!\n\n\n");
            
            pthread_mutex_unlock(&mutex);
            
            break;
            
        }
        
        pthread_mutex_unlock(&mutex);
    }
    
    return NULL;
}

int main() 
{
    pthread_t thread_1, thread_2;
    
    pthread_create(&thread_1, NULL, hola, NULL);
    
    pthread_create(&thread_2, NULL, mundo, NULL);
    
    pthread_join(thread_1, NULL);
    
    pthread_join(thread_2, NULL);
    
    pthread_mutex_destroy(&mutex); 
    
    return 0;
}
