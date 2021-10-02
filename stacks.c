// a stack is a linear data structure in which insertions and deletions 
// are allowed only at the end , called the top of the stack.
// can be implemented using array and linked list
#include<stdio.h>
#include<stdlib.h>
#define MAX 4

// pop function
int stack_arr[MAX]; // global declarartion
int top = -1;

int isFull(){
    if (top == MAX-1){
        return 1;
    }
    else{
        return 0;
    }

}

int isEmpty(){
    if (top == -1){
        return 1;
    }
    else{
        return 0;
    }
}
void push(int data){
    if (isFull()){
        printf("stack overflow\n");
        return; // back to the calling function even though return type is void, indicates end of function
    }
    top = top +1;
    stack_arr[top] = data;
    }

int pop(){
    int value;
    if (isEmpty()){
        printf("stack underflow\n");
        exit(1);
    }
    value = stack_arr[top];
    top = top - 1;
    return value;
}

int peek(){
    if (isEmpty()){
        printf("stack underflow\n");
        exit(1);//abnormal terminiation of the program, do not want to return anything
    }
    return stack_arr[top];
}

void print(){
    int i;
    if (top == -1){
        printf("stack underflow\n");
        return;
    }
    for(i=top; i>=0; i--){
        printf("%d", stack_arr[i]);
    }
    printf("\n");
}

int main(){
    int choice, data;
    while(1){
        printf("\n");
        printf("1. push\n");
        printf("2. pop\n");
        printf("3. print the top element\n");
        printf("4. print all the elements of the stack\n");
        printf("5. Quit\n");
        printf("Please enter your choice: ");
        scanf("%d\n", &choice);

        switch(choice){
            case 1 :
                printf("enter the element to be pushed");
                scanf("%d\n", &data);
                push(data);
                break;
            case 2:
                data = pop();
                printf("the element popped out is %d\n", data);
                break;
            case 3:
                printf("element present at the top of the stack is %d\n", peek());
                break;
            case 4:
                print();
                break;
            case 5:
                exit(1);
            default:
                printf("wrong choice\n");
        }
    }
    return 0;

}