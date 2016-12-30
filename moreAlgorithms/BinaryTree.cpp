#include <iostream>
#include "BinaryTree.h"

using std::cout;
using std::endl;

BinaryTreeNode* CreateBinaryTreeNode(int value){
	BinaryTreeNode* pNode = new BinaryTreeNode();
	pNode->m_nValue = value;
	pNode->m_pLeft = NULL;	//Ԥ�������NULL��cstdlibͷ�ļ���;��һ��ֻҪ������һ��C++��׼�⣬���㹻��null�Ķ�������
	pNode->m_pRight = NULL;

	return pNode;
}

void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight){
	if( pParent!=NULL ){
		pParent->m_pLeft = pLeft;
		pParent->m_pRight = pRight;
	}
}

void PrintTreeNode(BinaryTreeNode* pNode){
	if( pNode!=NULL ){
		cout<<"value of this node is "<<pNode->m_nValue<<"	";
		if( pNode->m_pLeft!=NULL ){
			cout<<"left child value of this node is "<<pNode->m_pLeft->m_nValue<<"	";
		}else{
			cout<<"left child is null."<<"	";
		}
		if( pNode->m_pRight!=NULL ){
			cout<<"right child value of this node is "<<pNode->m_pRight->m_nValue<<"	";
		}else{
			cout<<"right child is null."<<"	";
		}
	}else{
		cout<<"this node is null."<<"	";
	}
	cout<<endl;
}

void PrintTree(BinaryTreeNode* pRoot){
	PrintTreeNode(pRoot);
	if ( pRoot!=NULL ){
		if ( pRoot->m_pLeft!=NULL ){
			PrintTree(pRoot->m_pLeft);
		}
		if ( pRoot->m_pRight!=NULL ){
			PrintTree(pRoot->m_pRight);
		}
	}
}

void DestroyTree(BinaryTreeNode* pRoot){
	if ( pRoot!=NULL ){	//�ͷſ�ָ���ǲ��Եģ�ʱ���μ��жϣ�
		BinaryTreeNode* pLeft = pRoot->m_pLeft;
		BinaryTreeNode* pRight = pRoot->m_pRight;
		delete pRoot;
		pRoot = NULL;

		DestroyTree(pLeft);
		DestroyTree(pRight);
	}
}