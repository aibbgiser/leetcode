#include <iostream>
#include "myList.h"

using std::cout;

ListNode* CreateListNode( int value ){
	ListNode* pNode = new ListNode();	//ע������½���ʵ������֤�ڴ����ɹ�;�����Ƕ�̬�ڴ�
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
	//ͷ����ɢ������ȷ���µ�ͷ��㣬ԭͷ���ɾ��
	ListNode* pNode = pHead;
	while( pNode!=NULL ){
		pHead = pHead->m_pNext;
		delete pNode;
		pNode = pHead;
	}
}

void AddToTail(ListNode** pHead, int value){
	//������ֻ��֪��ͷ��㣬��add��Ҫ��ĩβ���еģ�����ֻ���������
	//���ǿ�������ӵ���������ȥ
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
	//ͬ�ϣ�����ɾ��������Ϊ�յ����;���Ǵ�ɾ�������ͷ���
	//����ֻ��ɾ��ֵΪvalue��һ����û���Ƕ�γ���
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