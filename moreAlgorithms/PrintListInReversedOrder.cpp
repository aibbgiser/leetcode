#include <iostream>	//<iostream>是C++标准，需要与std配套使用；<iostream.h>则是C标准
#include <stack>
#include "myList.h"

using std::stack;
using std::cout;
using std::endl;


void PrintListReversingly_Iteratively(ListNode* pHead){
	stack<ListNode*> pNodes;
	ListNode* pNode = pHead;
	while( pNode!=NULL ){
		pNodes.push(pNode);
		pNode = pNode->m_pNext;
	}
	while( !pNodes.empty() ){
		pNode = pNodes.top();
		cout<<pNode->m_value;
		pNodes.pop();
	}
}

void PrintListReversingly_Recursively( ListNode* pHead ){
	if ( pHead != NULL ){
		if ( pHead->m_pNext!=NULL ){
			PrintListReversingly_Recursively(pHead->m_pNext);
		}
		cout<<pHead->m_value;
	}
}

void test( ListNode* pHead ){
	PrintList(pHead);
	cout<<"List has been printed"<<endl;
	PrintListReversingly_Iteratively(pHead);
	cout<<endl;
	PrintListReversingly_Recursively(pHead);
}

void Test1(){
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);

	test(pNode1);
	cout<<"test1 has done"<<endl;
	DestroyList(pNode1);
}

// 只有一个结点的链表: 1
void Test2()
{
	ListNode* pNode1 = CreateListNode(1);

	test(pNode1);
	cout<<"test2 has done"<<endl;
	DestroyList(pNode1);
}

// 空链表
void Test3()
{
	test(NULL);
	cout<<"test3 has done"<<endl;
}

int main(){
	Test1();
	Test2();
	Test3();
	system("pause");
	return 0;
}
