#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

 #define SIZE 30

typedef struct l_t {
	char data[SIZE];
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

l_t * l_t_createElt(char * d)
{
	l_t * res = malloc(sizeof(l_t));
	memcpy(res->data, d, SIZE*sizeof(char));
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
	while(it)
	{
		int i = 0;	
		printf("%s,", it->data);
		it = it->nxt;
	}
	printf("\n");
}

void deletefifthElement(l_t * this)
{
	l_t * it = this;
	size_t cnt = 0;
	while (it)
	{
		++cnt;
		if(cnt == 4)
		{
			l_t * tmp = it->nxt;
			if(tmp)
			{
				it->nxt = tmp->nxt;
				free(tmp);
			}
			return;
		}
		it = it->nxt;
	}
}

int main(void) 
{
	l_t * firstArray = NULL;
	l_t * secondArray = NULL;
	char * word[] = {
		"house", 
		"car", 
		"subway", 
		"kebab", 
		"nathan gros pd",
		"6th word" 
	};

	firstArray = l_t_createElt(word[0]);
	firstArray->nxt = l_t_createElt(word[1]);
	firstArray->nxt->nxt = l_t_createElt(word[2]);
	firstArray->nxt->nxt->nxt = l_t_createElt(word[3]);
	firstArray->nxt->nxt->nxt->nxt = l_t_createElt(word[4]);
	firstArray->nxt->nxt->nxt->nxt->nxt = l_t_createElt(word[5]);

	secondArray = l_t_createElt(word[0]);
	secondArray->nxt = l_t_createElt(word[1]);
	secondArray->nxt->nxt = l_t_createElt(word[2]);

	deletefifthElement(firstArray);
	deletefifthElement(secondArray);

	l_t_print(firstArray);
	l_t_print(secondArray);

	l_t_delete(firstArray);
	l_t_delete(secondArray);

	return 0;   
}