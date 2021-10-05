#include<stdio.h>
#include<stdlib.h>

struct  node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node* add_to_empty(struct node *head, int data){ //insertion of a node to an empty list
    struct node *temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    head = temp;
    return head;
}

struct node* add_at_beg(struct node *head, int data){ // insertion at beginning of doubly linked list
    struct node *temp = malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;

    temp->next=head;
    head->prev =temp;
    head = temp;
    return head;
}

struct node* add_at_end(struct node *head, int data){ // insertion at end of doubly linked list
    struct node *temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;

    struct node *ptr = head;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = temp;
    temp->prev = ptr;
    return head;
}

struct node* add_at_pos(struct node *head, int data,int position){ // insertion of a node at certain position
    struct node *newP = NULL;
    struct node *temp = head;
    struct node *temp2 = NULL;
    newP = add_to_empty(newP, data);
    int pos = position;
    while(pos > position-1){
        temp=temp->next;
        pos--;

    }
    if (position ==1 ){
        head = add_at_beg(head,data);
    }
    else{
        temp2=temp->next;
        temp->next = newP;
        temp2->prev=newP;
        newP->next=temp2;
        newP->prev=temp;
    }
    return head;
}

struct node* del_at_beg(struct node *head){
    head = head->next;
    free(head->prev);
    head->prev=NULL;
}

struct node* del_at_end(struct node *head){
    struct node *temp = head;
    struct node *temp2 = NULL;

    while(temp!=NULL){
        temp=temp->next;
    }
    temp2=temp->prev;
    temp2->next=NULL;
    free(temp);
    temp=NULL;

}

struct node* del_at_pos(struct node *head, int position){
    struct node *temp =head;
    struct node *temp2 =NULL;
    if (position == 1){
        head = del_at_beg(head);
        return head;
    }
    int pos = position -1;
    while(position>pos){
        temp=temp->next;
        position--;
    }
    if (temp->next == NULL){
        head = del_at_end(head);
    }
    else{
        temp2 = temp->prev;
        temp2->next=temp->next;
        temp->next->prev = temp2;
        free(temp);
        temp=NULL;
    }
    return head;
}

int main(){
    struct node *head = NULL;
    head = add_to_empty(head,45); 
    head = add_at_beg(head,108);
    head = add_at_end(head,78);
    int n;
    scanf("%d", n);
    int position = n;
    head = add_at_pos(head, 1, position);

    struct node *ptr = head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }

    head = del_at_beg(head);
    head = del_at_end(head);
    position = 2;
    head = del_at_pos(head,position);
    return 0;
}