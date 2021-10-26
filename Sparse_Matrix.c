#include<stdio.h>
#include<stdlib.h>
 
struct Node
{
    int row;
    int col;
    int data;
    struct Node *next;
};
 
void create_sam_node(struct Node** start, int data, int row_index, int col_index )
{
    struct Node *temp, *r;
    temp = *start;
    if (temp == NULL)
    {
        // Create new node dynamically
        temp = (struct Node *) malloc (sizeof(struct Node));
        temp->data = data;
        temp->row = row_index;
        temp->col = col_index;
        temp->next = NULL;
        *start = temp;
 
    }
    else
    {
        while (temp->next != NULL)
            temp = temp->next;
 
        r = (struct Node *) malloc (sizeof(struct Node));
        r->data = data;
        r->row= row_index;
        r->col = col_index;
        r->next = NULL;
        temp->next = r;
 
    }
}
 
void print(struct Node* start)
{
    struct Node *temp, *r, *s;
    temp = r = s = start;
 
    printf("row_pos: ");
    while(temp != NULL)
    {
 
        printf("%d ", temp->row);
        temp = temp->next;
    }
    printf("\n");
 
    printf("col_pos: ");
    while(r != NULL)
    {
        printf("%d ", r->col);
        r = r->next;
    }
    printf("\n");
    printf("data: ");
    while(s != NULL)
    {
        printf("%d ", s->data);
        s = s->next;
    }
    printf("\n");
}
 
 
int main()
{
    int sam_sparse_Matric[6][5] =
    {
        {1 , 0 , 0 , 0 , 9 },
        {1 , 2 , 0 , 0 , 0 },
        {1 , 2 , 0 , 0 , 0 },
        {1 , 0 , 3 , 0 , 0 },
        {1 , 0 , 0 , 4 , 0 },
        {1 , 0 , 0 , 4 , 5 },

    };
 
    
    struct Node* start = NULL;
 
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 5; j++)
 
            if (sam_sparse_Matric[i][j] != 0)
                create_sam_node(&start, sam_sparse_Matric[i][j], i, j);
 
    print(start);
 
    return 0;
}