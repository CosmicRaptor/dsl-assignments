#include<stdio.h>

int length = 5;

struct queue {
    int front, back;
    //back will always point to the next element in the queue
    int a[10];
};

struct queue q1;

void add(int a){
    if(q1.back == length - 1){
        printf("\nQueue full");
        return;
    }
    else if(q1.front == -1 && q1.back == -1){
        //queue empty
        q1.front = 0;
        q1.back = 0;
        q1.a[q1.back] = a;
    }
    else{
        //normal insert
        q1.back++;
        q1.a[q1.back] = a;
    }
    //printf("%d\n", q1.back);
}

void delete(){
    if(q1.front == -1 && q1.back == -1){
        printf("Queue is empty\n");
    }
    else if(q1.front == q1.back){
        //queue is empty
        q1.front = -1;
        q1.back = -1;
    }
    else {
        //increment front 
        q1.front++;
    }
}

void display(){
    printf("[ ");
    for(int i = q1.front; i <= q1.back; i++){
        printf("%d ", q1.a[i]);
    }
    printf("]\n");
}

void main(){
    q1.front = -1;
    q1.back = -1;
    add(2);
    display();
    add(3);
    add(3);
    add(3);
    add(3);
    display();
    delete();
    display();
    delete();
    delete();
    delete();
    add(2);
    display();
    add(3);
    display();
    display();
    delete();
    printf("%d %d\n", q1.front, q1.back);
}