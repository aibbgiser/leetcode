#pragma once	//because of vs2010
#ifndef _LISTNODE_H
#define _LISTNODE_H

struct ListNode{
	int m_value;
	ListNode* m_pNext;
};

ListNode* CreateListNode( int value );
void ConnectListNodes(ListNode* pCurrent, ListNode* pNext);
void PrintListNode(ListNode* pNode);
void PrintList(ListNode* pHead);
void DestroyList(ListNode* pHead);
void AddToTail(ListNode** pHead, int value);
void RemoveNode(ListNode** pHead, int value);

#endif