#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef struct l_t {
	int data;
	struct l_t *nxt;
} l_t;

void l_t_delete(l_t * this)
{
	l_t * it = this;
	l_t * tmp;
	while (tmp = it)
	{
		it = it->nxt;
		free(tmp);
	}
}

l_t * l_t_createElt(const int d)
{
	l_t * res = malloc(sizeof(l_t));
	res->data = d;
	res->nxt = NULL;
	return res;
}

void l_t_print(l_t * this)
{
	l_t * it = this;
	while (it)
	{
		int i = 0;
		printf("%d,", it->data);
		it = it->nxt;
	}
	printf("\n");
}

l_t * l_t_fromEndToHead(l_t * this)
{
	l_t * res = NULL;
	l_t * lst = NULL;
	if(this && this->nxt)
	{
		if(this->nxt->nxt == NULL)
		{
			res = this->nxt;
			this->nxt = NULL;
			res->nxt = this;
		}
		else if (this && this->nxt)
		{
			lst = this->nxt;
			while (lst && lst->nxt && lst->nxt->nxt != NULL)
				lst = lst->nxt;
			res = lst->nxt;
			lst->nxt = NULL;
			res->nxt = this;
		}
	}
	
	return res;
}

int main(void)
{
	l_t * firstArray = NULL;
	l_t * secondArray = NULL;
	int word[] = {
		1,2,3,4,5
	};

	firstArray = l_t_createElt(word[0]);
	firstArray->nxt = l_t_createElt(word[1]);
	firstArray->nxt->nxt = l_t_createElt(word[2]);
	firstArray->nxt->nxt->nxt = l_t_createElt(word[3]);
	firstArray->nxt->nxt->nxt->nxt = l_t_createElt(word[4]);

	secondArray = l_t_createElt(word[0]);
	secondArray->nxt = l_t_createElt(word[1]);

	firstArray = l_t_fromEndToHead(firstArray);
	secondArray = l_t_fromEndToHead(secondArray);

	l_t_print(firstArray);
	l_t_print(secondArray);

	l_t_delete(firstArray);
	l_t_delete(secondArray);

	return 0;
}