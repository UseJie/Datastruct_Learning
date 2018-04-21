#include <stdio.h>
#include <stdlib.h>
#include "StackList.h"
#define ElementType int
#define false 0
#define ERROR 0
#define true 1
#define bool int

int main()
{
	PtrToSNode S;
	S = (PtrToSNode)malloc(sizeof(struct SNode));
	S = CreateStack();
	Push( S, 3);
	printf("%d", Pop(S));
	return 0;
}
