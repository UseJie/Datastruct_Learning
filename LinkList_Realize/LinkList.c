#include <stdio.h>
#include <stdlib.h>
#define ElementType int 
#define false 0
#define true 1
#define bool int 

typedef struct LNode *PtrToLNode;
struct LNode {
	ElementType Data;
	PtrToLNode Next;
};

typedef PtrToLNode Position;
typedef PtrToLNode List;

/*初始化*/
List MakeEmpty()
{
	List L;
	L = (List) malloc (sizeof(struct LNode));
	L->Next = NULL;
	
	return L;
}
/*查找*/
#define ERROR NULL

Position Find( List L, ElementType X )
{
	Position p = L;
	
	while( p && p->Data != X )
		p = p->Next;
	
	if(p)
		return p;
	else
		return ERROR;
}

/*带头节点的插入*/
/* 注意:在插入参数P上与课程视频有所不同，课程视频中i时序列位序（从1开始）
 * 是链表结点指针，在P之前插入新结点
*/

bool Insert( List L, ElementType X, Position P )
{
	Position tmp, pre;
		for( pre = L; pre && pre->Next != P; pre = pre->Next );
	if( pre == NULL ) {
		printf("插入位置参数错误\n");
		return false;
	}
	else {
		tmp = (Position) malloc (sizeof(struct LNode));
		tmp->Data = X;
		tmp->Next = P;
		pre->Next = tmp;
		return true;
	}
}

/*带头结点删除*/
bool Delete( List L, Position P )
{
	Position tmp, pre;
	for( pre = L; pre && pre->Next != P; pre = pre->Next );
	if( pre == NULL || P == NULL ) {
		printf("删除位置参数错误");
		return false;
	}
	else {
		pre->Next = P->Next;
		free(P);
		return true;
	}
}

/*打印链表*/
void PrintList( List L )
{
	Position p = L;
	if( p == NULL ) {
		printf("链表为空\n");
		return;
	}
	
	do {
		printf("%d ", p->Data);
		p = p->Next;
	}while( p->Next != NULL);
	return;
}

int main()
{
	List L = (List) malloc (sizeof( struct LNode)); 
	L->Data = 0;
	L->Next = NULL;
	Position p = (List) malloc (sizeof (struct LNode ));
	p->Data = 1;
	p->Next = NULL;
	L->Next = p;
	List insertP = (List) malloc (sizeof( struct LNode));
	insertP->Data = 2;
	insertP->Next = NULL;
	if( Insert( L, 1, p) ) {
		printf("insert success!\n");
	}
	else 
		printf("Insert failed\n");
	PrintList( L );
	return 0;
}
