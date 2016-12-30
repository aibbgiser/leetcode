#include <iostream>
#include "myList.h"

using std::cout;

ListNode* CreateListNode( int value ){
	ListNode* pNode = new ListNode();	//注意这里，新建空实例，保证内存分配成功;链表是动态内存
	pNode->m_pNext = NULL;
	pNode->m_value = value;
	return pNode;
}

void ConnectListNodes(ListNode* pCurrent, ListNode* pNext){
	if ( pCurrent == NULL ){
		cout<<"can't connect to a null nodes";
		exit(1);
	}
	pCurrent->m_pNext = pNext;
}
void PrintListNode(ListNode* pNode){
	if ( pNode == NULL ){
		cout<<"can't print a null nodes";
	}else{
		cout<<pNode->m_value;
	}
}

void PrintList(ListNode* pHead){
	ListNode* pNode = pHead;
	while( pNode!=NULL ){
		cout<<pNode->m_value;
		pNode = pNode->m_pNext;
	}
}

void DestroyList(ListNode* pHead){
	//头结点打散出来，确定新的头结点，原头结点删除
	ListNode* pNode = pHead;
	while( pNode!=NULL ){
		pHead = pHead->m_pNext;
		delete pNode;
		pNode = pHead;
	}
}

void AddToTail(ListNode** pHead, int value){
	//单链表只能知道头结点，而add是要在末尾进行的，所以只能依次向后
	//考虑可能是添加到空链表上去
	ListNode* pNewNode = new ListNode();
	pNewNode->m_pNext = NULL;
	pNewNode->m_value = value;

	if( *pHead == NULL ){
		*pHead = pNewNode;
	}else{
		ListNode* pNode = *pHead;
		while( pNode->m_pNext!=NULL ){
			pNode = pNode->m_pNext;
		}
		pNode->m_pNext = pNewNode;
	}
}

void RemoveNode(ListNode** pHead, int value){
	//同上，考虑删除后链表为空的情况;考虑待删除点就是头结点
	//这里只会删除值为value的一个，没考虑多次出现
	if ( pHead==NULL || *pHead==NULL ){
		return;
	}
	ListNode* pToBeDeleted = NULL;
	if( (*pHead)->m_value == value ){
		pToBeDeleted = *pHead;
		*pHead = (*pHead)->m_pNext;
	}else{
		ListNode* pNode = *pHead;
		while( pNode->m_pNext!=NULL && pNode->m_pNext->m_value!=value){
			pNode = pNode->m_pNext;
		}
		if( pNode->m_pNext!=NULL && pNode->m_pNext->m_value!=value){
			pToBeDeleted = pNode->m_pNext;
			pNode->m_pNext = pNode->m_pNext->m_pNext;
		}
	}
	if ( pToBeDeleted!=NULL ){
		delete pToBeDeleted;
		pToBeDeleted = NULL;
	}
}