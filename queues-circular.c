#include<stdio.h>

int length = 5;

struct queue {
    int front, back;
    //back will always point to the next element in the queue
    int a[10];
};

struct queue q1;

void add(int a){
    if(((q1.back + 1) % length) == q1.front){
        printf("Overflow\n");
    }

    else if(q1.back == -1 && q1.front == -1){
        //first element
        q1.front = 0;
        q1.back = 0;
        q1.a[q1.back] = a;
    }
    else {
        q1.back = (q1.back + 1) % length;
        q1.a[q1.back] = a;
    }
}

void delete(){
    if(q1.front == -1 && q1.back == -1){
        printf("Underflow\n");
    }
    else if(q1.back == q1.front){
        //only happens if there's only 1 element in the queue
        q1.front = -1;
        q1.back = -1;
    }
    else {
        //normal deletion
        q1.front = (q1.front + 1) % length;
    }
}

void display(){
    if(q1.front == -1){
        printf("Queue is empty\n");
        return;
    }
    printf("[ ");
    int i = q1.front;
    while(1==1){
        printf("%d ", q1.a[i]);
        if(i == q1.back){
            break;
        }
        i = (i + 1) % length;
    }
    printf("]\n");
}

void main(){
    q1.front = -1;
    q1.back = -1;
    add(2);
    add(3);
    display();
    add(3);
    add(4);
    add(5);
    display();
    //add(5);
    delete();
    display();
    delete();
    delete();
    display();
    add(3);
    add(4);
    display();
}