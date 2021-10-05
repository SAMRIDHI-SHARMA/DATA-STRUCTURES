/* creating the node of a single linked list
self referential strucutre is a strucutre which contains a pointer to a structure 
of the same type
struct abc{
    int a;
    int b;
    struct abc *self; here, *self is a pointer to the strucutre struct abc
}
we will use a self referential structure for creating a node of the single linked list
node is combination of two different types -> data and link
we can use strucutre to combine two different types into a single type and we name it with our own type
structure representing a node:
struct node{
    int data; // could be any other data type also
    struct node *link; // this link is a pointer to some other node and represents pointer to a struct node
};
*/

#include<stdio.h> //represents standard input output 
#include<stdlib.h> // to call malloc function, it is because creating a structure is not enough, we also have to allocate memory for it

struct node{
    int data;
    struct node *link;
};

int main(){
    struct node *head = NULL; // pointer " *head " is created to struct node only which can access data as well as link
    head = (struct node *)malloc(sizeof(struct node));//malloc is used to allocate memory to the struct node
    // malloc returns a void pointer which can be type casted to struct node, but type casting is not necessary
    head->data=45;
    head->link=NULL;
    printf("%d", head->data);
    return 0;
}
