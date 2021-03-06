#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
 
typedef struct ListEl {
    int data;
    struct ListEl *nxt;
} ListEl;
 
 
/* creates a new list from the array elements */
ListEl *list_build(void) {
    int values[] = { 8, 14, 13, 17, 1, 19, 16, 5, 3, 11, 2,
                     15, 9, 10, 6, 22, 4, 7, 18, 27, -1 };
    ListEl *lis = NULL;
 
    int i;
    for (i = 0; values[i] != -1; ++i) {
        ListEl *u;
        u = (ListEl*) malloc(sizeof(ListEl));
        u->nxt = lis;
        u->data = values[i];
        lis = u;
    }
    return lis;
}

size_t size(ListEl * this)
{
	size_t res = 0;
	ListEl * it = this;
    while(it)
    {
    	++res;
    	it = it->nxt;
    }
    return res;
}

void delete(ListEl * this)
{
    ListEl * it = this;
    ListEl * tmp;
    while(tmp = it)
    {
        it = it->nxt;
        free(tmp);
    }
}

void printList(ListEl * this)
{
    ListEl * it = this;
    printf("list : ");
    while(it)
    {
        printf("%d ", it->data);
        it = it->nxt;
    }
}

 ListEl * list_insert_athead(ListEl * this, const int data)
 {
    ListEl *u;
    u = (ListEl*) malloc(sizeof(ListEl));
    u->data = data;
    if(!u)
    {
        fprintf(stderr, "fail to allocate element\n");
        return NULL; //be carful memory leak may occur
    }
    u->nxt = this;
    return u;
 }
 
int main(void) {
    ListEl *head;
    head = list_build();

    ListEl * tres = list_insert_athead(head, 21);
    if(tres)
        head = tres;
    else
        printf("fail\n");

    printList(head);
    delete(head);
    
    return 0;   
}