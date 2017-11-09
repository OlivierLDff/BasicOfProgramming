#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

 #define SIZE 20

typedef struct l_t {
	int data[SIZE];
	struct l_t *nxt;
} l_t;

void l_t_delete(l_t * this)
{
	l_t * it = this;
	l_t * tmp;
	while(tmp = it)
	{
		it = it->nxt;
		free(tmp);
	}
}

l_t * l_t_createElt(int * d) //d is always size 20 and nit null
{
	l_t * res = malloc(sizeof(l_t));
	memcpy(res->data, d, SIZE*sizeof(int));
	res->nxt = NULL;
	return res;
}

l_t * l_t_copy(l_t * src)
{
	l_t * it = src;
	l_t * res = NULL;
	l_t * tRes = NULL;
	l_t * fres = NULL;
	while(it)
	{
		res = l_t_createElt(it->data);
		if (fres == NULL)
			fres = res;
		if(tRes)
			tRes->nxt = res;
		tRes = res;
		it = it->nxt;
	}
	return fres;
}

void l_t_print(l_t * this)
{
	l_t * it = this;
	printf("list of pointer %p is : ", this);
	while(it)
	{
		int i = 0;	
		for(; i < SIZE; ++i)
			printf("%d ", it->data[i]);
			printf("\n");
		it = it->nxt;
	}
	printf("\n");
}

int main(void) 
{
	l_t * firstArray = NULL;
	l_t * copyArray = NULL;
	int d1[] = { 8, 14, 13, 17, 1, 19, 16, 5, 3, 11, 2, 15, 9, 10, 6, 22, 4, 7, 18, 27 };
	int d2[] = { 5, 12, 13 , 14 , 2, 20, 17, 7, 5, 12, 4, 16, 10, 11, 12, 45, 9, 9, 15, 97 };

	firstArray = l_t_createElt(d1);
	firstArray->nxt = l_t_createElt(d2);

	copyArray = l_t_copy(firstArray);

	l_t_print(firstArray);
	l_t_print(copyArray);

	l_t_delete(firstArray);
	l_t_delete(copyArray);

	return 0;   
}