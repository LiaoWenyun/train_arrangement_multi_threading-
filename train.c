#include <pthread.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>


struct train{
    int train_id;               //which line it i sfrom 
    char direction;             //two directions, west or east 
    int loading_time; 
    int crossing_time; 
    int priority;               //0 or 1, 0 is low priority, 1 is high priority 
    pthread_t train_number;     //used to create threads
    struct train *next_train;   //used to create linked list
};


struct train * head= NULL;      // the first train in the linked list 
pthread_mutex_t list_lock;      //mutex for the list 



int count_number_of_trains(FILE *file){
    int c=0;
    int count=1;
    while(!feof(file)){
        c = fgetc(file);
        if(c == '\n'){          //new line 
        count++;
        }
    }
    return count;
}



int main(int argc, char *argv[]){
    int train_count=0;
    FILE *file = NULL;
    if( argc != 2 ){
        printf("please have exact one input file\n");
        exit(1);
    }
    file = fopen(argv[1], "r");
    if(file == NULL){
        printf("file %s can not be opend\n" , argv[1]);
        exit(1);
    }
    train_count= count_number_of_trains(file);
    
    

    printf("total number of trains is %d\n",train_count);





}
