/*
* LinkList.h 实现了:
* MakeEmpty()	//链表的初始化
* Find()		//查找
* Insert()		//带头结点的插入
* Delete()		//带头节点的删除
* PrintList() 	//打印链表
*/

#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

/*
* 采用前插入式的方法构造链表
* 插入完成后
* 可以通过查找结点内容值返回结点地址后删除结点
* 也可以通过指定结点然后删除
*/

int main()
{
	int N, D;
	printf("Please input the number of Link:");
	scanf("%d", &N);
	List L = MakeEmpty(); 	//初始化链表
	L->Data = -1;			//头结点数据为-1
	for( int i = 0; i < N; i++ ) {
		printf("Please input the No.%d Data:\n", i+1 );
		scanf("%d", &D);
		Position p;
		if( Insert( L, D, p)) {
			printf("Insert No.%d Success!\n", i+1 );
		}
		else {
			printf("Insert No.%d Failure!\n", i+1 );
		}
		printf("The LinkList is : \n");
		PrintList( L );
	}
	printf("Please input you want to delete data:");
	scanf("%d", &D);
	if( Delete(L,  Find( L, D ) ) ) {
		printf("Delete Success!\n");
		printf("The LinkList is : \n");
		PrintList( L );
	}
	else {
		printf("Delete Failure!\n");
	}
	return 0;
}
