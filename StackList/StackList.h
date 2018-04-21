#include <stdio.h>
#include <stdlib.h>
#define ElementType int
#define false 0
#define ERROR 0
#define true 1
#define bool int


typedef struct SNode *PtrToSNode;
struct SNode {
	ElementType Data;
	PtrToSNode Next;
};
typedef PtrToSNode Stack;

Stack CreateStack()
{/*创建堆栈*/
	Stack S;
	
	S = (Stack)malloc(sizeof(struct SNode));
	S->Next = NULL;
	return S;
}

bool IsEmpty( Stack S )
{
	return( S->Next == NULL);
}

bool Push ( Stack S, ElementType X )
{/*进栈 X为入栈数据*/
	PtrToSNode TmpCell;
	
	TmpCell = (PtrToSNode)malloc(sizeof(struct SNode ));
	TmpCell->Data = X;
	TmpCell->Next = S->Next;
	S->Next = TmpCell;
	return true;
}

ElementType Pop( Stack S )
{
	PtrToSNode FirstCell;
	ElementType TopElem;
	
	if( IsEmpty(S) ) {
		printf( "堆栈空" );
		return ERROR;
	}
	else {
		FirstCell = S->Next;
		TopElem = FirstCell->Data;
		S->Next = FirstCell->Next;
		free(FirstCell);
		return TopElem;
	}
}

