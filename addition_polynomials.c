#include <stdio.h>
#include <stdlib.h>

struct node {
    float coeff;
    int expo;
    struct node* link;
};

struct node* insert_sam(struct node* head, float co, int ex){
    struct node* temp;
    struct node* sam = malloc(sizeof(struct node));
    sam->coeff = co;
    sam->expo = ex;
    sam->link = NULL;

    if (head == NULL || ex > head->expo){
        sam->link = head;
        head = sam;
    }
    else{
        temp = head;
        while(temp->link != NULL && temp->link->expo >= ex){
            temp = temp->link;
        }
        sam->link = temp->link;
        temp->link = sam;
    }
    return head;
}

struct node* create_sam(struct node* head){
    int n,i;
    float coeff;
    int expo;

    printf("Enter the number of terms : ");
    scanf("%d", &n);
     for(i=0; i<n; i++){
         printf("Enter the coefficient for the term %d : ", i+1);
         scanf("%f", &coeff);
         printf("Enter the exponent for the term %d : ", i+1);
         scanf("%d", &expo);
         head = insert_sam(head,coeff,expo);

     }
     return head;
}
void print_sam(struct node* head){
    if(head == NULL){
        printf(" There is no Polynomial");
    }
    else{
        struct node* temp = head;
        while(temp != NULL){
            printf("(%.1fx^%d)",temp->coeff,temp->expo);
            temp =temp->link;
            if(temp != NULL){
                printf(" + ");
            }
            else{
                printf("\n");
            }
        }

    }
}

void polynomial_Addition_sam(struct node* head1, struct node* head2){
    struct node* ptr1 = head1;
    struct node* ptr2 = head2;
    struct node* head3 = NULL;
    while(ptr1 != NULL && ptr2!=NULL){
        if(ptr1->expo == ptr2->expo){
            head3 = insert_sam(head3, ptr1->coeff+ptr2->coeff,ptr1->expo);
            ptr1 = ptr1->link;
            ptr2 = ptr2->link;
        }
        else if(ptr1->expo > ptr2->expo){
            head3 = insert_sam(head3, ptr1->coeff, ptr1->expo);
            ptr1 = ptr1->link;
        }
        else if(ptr2->expo > ptr1->expo){
            head3 = insert_sam(head3, ptr2->coeff,ptr2->expo);
            ptr2 = ptr2->link;
        }
    }
    while(ptr1 != NULL){
        head3 = insert_sam(head3,ptr1->coeff,ptr1->expo);
        ptr1 = ptr1->link;
    }
    while(ptr2!= NULL){
        head3 = insert_sam(head3,ptr2->coeff,ptr1->expo);
        ptr2 = ptr2->link;
    }
    printf("ADDED POLYNIMIAL IS : ");
    print_sam(head3);
}

int main(){
    struct node* head1 = NULL;
    struct node* head2 = NULL;
    printf("Enter the first polynomial\n ");
    head1 = create_sam(head1);
    printf("Enter the second polynomial\n ");
    head1 = create_sam(head2);
    polynomial_Addition_sam(head1,head2);
    return 0;

}