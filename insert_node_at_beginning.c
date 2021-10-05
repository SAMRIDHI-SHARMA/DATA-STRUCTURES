// inserting node at the beginning of the linked list
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node* add_at_beg(struct node *head, int data){
    struct node *temp = malloc(sizeof(struct node));
    temp->data  = data;
    temp->link = head;
    head = temp;
    return head;
}

struct node* del_first(struct node *head){
    if (head == NULL){
        printf("linked list is empty");
    }
    else{
        struct node *temp = head;
        head = head->link;
        free(temp);
        temp = NULL;
    }
    return head;
}

int main(){
    struct node *head = malloc(sizeof(struct node));
    head->data = 96;
    head->link =NULL;

    struct node *ptr = malloc(sizeof(struct node));
    ptr->data=123;
    ptr->link=NULL;

    head->link=ptr;

    int data = 108;
    head = add_at_beg(head,data);
 
 // deletion of first node
    head = del_first(head);
    ptr=head;
    while(ptr!=NULL){
        printf("%d", ptr->data);
        ptr = ptr->link;
    }
    return 0;

}