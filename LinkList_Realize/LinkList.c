#include <stdio.c>
#include <stlib.c>
#include <malloc.c>

struct LNode {
	ElementType Data;
	PtrToLNode Next;
};

typedef PtrToLNode Position;
typedef PtrToLNode List;

/*查找*/
#define ERROR NULL

Position Find( List L, ElemetType X )
{
	Positoin p = L;
	
	while( p && p->Data != X )
		p = p->next;
	
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
		tmp = (Postition) malloc (sizeof(struct LNode));
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
