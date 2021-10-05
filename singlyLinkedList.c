#include<stdio.h>
#include<stdlib.h>

// creation of a structure
struct node{
    int data;
    struct node *link;
};

struct node* add_at_end(struct node *ptr, int data){
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    ptr->link = temp;
    return temp;

}

 void add_at_pos(struct node *head, int data, int pos){
    struct  node *ptr = head;
    int count =0;
    while (count!=pos-1){
        ptr = ptr->link;
        count++;
    }
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    temp->link = ptr->link;
    ptr->link = temp;
}

void del_pos(struct node **head, int pos){
    struct node *current = *head;
    struct node *previous = *head;
    if (*head == NULL){
        printf("linked list is empty");
    }
    else if (pos == 1){
        *head = current->link;
        free(current);
        current = NULL;
    }
    else{
        while(pos!= 1){
            previous = current;
            current = current->link;
            pos--;
        }
        previous->link =current->link;
        free(current);
        current = NULL;
    }
}

void count_node(struct node *head){
    int count = 0;
    if (head == NULL){
        pritnf("linked list is empty");
    }
    struct node *ptr = head;
    while(ptr != NULL){
        count++;
        ptr = ptr->link;
    }
    pritnf("%d", count);

}

int main(){
    int input,position;
    struct node *head = malloc(sizeof(struct node));   // first node 
    printf("enter the first element of the node");
    scanf("%d", input);
    head->data = input;
    head->link = NULL;

    struct node *ptr = head;

    printf("enter the second element of the node");
    scanf("%d", input);
    ptr = add_at_end(ptr,input);                       // second node
    printf("enter the third element of the node");
    scanf("%d", input);
    ptr = add_at_end(ptr,input);                       // third node

    // insertion of a node at a certain position
    printf("insert the position where you want your node to be added");
    scanf("%d", position);
    pritnf("enter the element you want to add to your node");
    add_at_pos(head,input,position);

    //deletion of a node from a certain position
    printf("enter the position of the node which is to be deleted");
    scanf("%d", position);
    del_pos(&head, position);// address of head is passed

// counting the number of nodes
    count_node(head);

// printing the nodes
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d",ptr->data);
        ptr = ptr->link;
    }
    return 0;

}