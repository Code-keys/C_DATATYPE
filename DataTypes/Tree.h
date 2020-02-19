#pragma once
#include"math.h"
#include <iostream>
using namespace std;
/*
��ͷ�ļ���Ҫ��ϸ��Щ���Ĵ洢�ṹ��

ADT �� (tree)
	data
		*tree[MAX_TREE_SIZE]
	Operation
		InitTree(*T)
		DestoryTree()
		CreateTree()
		ClearTree()
		TreeEmpty(0
		TreeDepth()
		Root(T)
		Value(T,cur_e)
		Assign(T,cur_e,Value)
		Parent(T,cur_e)
		leftChild()
		RightSibling()  /*���ֵ�
		InsertChild(*T,*p,i,c)
		DeleteChild(T,p,i)
END-ADT
*/
#define MAX_TREE_SIZE 100
typedef char* TreeElemType;
typedef int TElemType ;

class TTree
{
private:/*˫�ױ�ʾ��*/
	typedef struct PTNode
	{
		TreeElemType data;
		int parent;/*˫��λ���±� -1*/

		int rightSib;
		int FirstChild;/*���� ����*/

	}PTNode;
	typedef struct PTree
	{
		PTNode nodes[MAX_TREE_SIZE];/*����˳��洢�ṹ*/
		int r,n;/*����λ�ü���ڵ���*/

	}PTree;
protected:/*���ӱ�ʾ����ָ�롿*/
	typedef struct CTNode
	{
		int child;
		struct CTNode* next;
	}*ChildPtr;
	typedef struct CTbox
	{
		TreeElemType data ;
		ChildPtr firstchild;
	};
	typedef struct CTree
	{
		CTbox nodes[MAX_TREE_SIZE];
		int r,n;
	};

public:/*�����ֵܱ�ʾ��*/
	typedef struct CSNode
	{
		TreeElemType data;
		struct CSNode *firstchild,*rightsib,*parent;
	}*CSTree;

public:/*�������Ĵ洢*/
	typedef struct DTree 
	{
		TreeElemType data[MAX_TREE_SIZE];
		/* [0]->[1��2]->[3��4��5��6].���������������Ŀ�ݹ�*/
	};
	typedef struct BiTNode
	{
		TreeElemType data;
		struct BiTNode *Lchild,*Rchild;/*,*parent*/
	}BiTNode,*BiTree;
//Operation:
	void CreateBiTree(BiTree *T)/*ǰ������ �ݹ鴴��*/
	{
		TreeElemType chr;
		scanf_s("%c",&chr);
		if (chr=="#") *T = NULL;
		else
		{
			*T = (BiTree)malloc(sizeof(BiTNode));
			if (!*T)exit(OVERFLOW);

			(*T)->data = chr;
			CreateBiTree(&(*T)->Lchild);/*����ڵ�*/
			CreateBiTree(&(*T)->Rchild);
		};
	};

	void PreOrderTraverse(BiTree T)/*ǰ����� ��*/
	{
		if (T==NULL) return;

		printf("%c",T->data);
		PreOrderTraverse(T->Lchild);
		PreOrderTraverse(T->Rchild);	
	};	
	void InOrderTraverse(BiTree T)/*�������*/
	{
		if (T==NULL) return;
		 
		InOrderTraverse(T->Lchild);
		printf("%c",T->data);
		InOrderTraverse(T->Rchild);	
	};
	void PostOrderTraverse(BiTree T)/*�������*/
	{
		if (T==NULL) return;
		 
		PostOrderTraverse(T->Lchild);
		PostOrderTraverse(T->Rchild);	
		printf("%c",T->data);
	};
public:/*����������*/
	typedef enum {Link,Thread}PointerTag;/*link ==0  Ϊ���ӣ�thread == 0Ϊǰ�����*/
	typedef struct BiThrNode
	{
		TElemType data;
		struct BiThrNode *Lchild,*Rchild;
		PointerTag LTag;
		PointerTag RTag;
	}BiThrNode,*BiThrTree;
	BiThrTree _ptr;

	void InThreading(BiThrTree T)/*�������*/
	{
		if (T)
		{
			InThreading(T->Lchild);	

			if (!T->Lchild){
				T->LTag  = Thread;
				T->Lchild = _ptr;
			};
			if (!T->Rchild){
				T->RTag  = Thread;
				T->Rchild = T;
			};
			_ptr = T;

			InThreading(T->Rchild);	
		};
	};
	void InOrderTraver_Thr(BiThrTree T)/*�����������������*/
	{
		BiThrTree p;
		p = T->Lchild;
		while(p != T)
		{
			while(p->LTag==Link)
			{
				p=p->Lchild;

				printf("%c",p->data);
				while(p->RTag==Thread && p->Rchild != T)
				{
					p  = p->Rchild;
					printf("%c",p->data);
				};

				p = p->Rchild;
			};
		};return ;
	};
public:/*ɭ��*/
	typedef struct Forest
	{
		BiThrTree *q1;
		BiTree *q2;
		/* and so on */
	};
	
public:/*��Ȩ·�� ��������Ϊ�������������Ż���*/
	typedef struct HofumanTree/*�������������Ƶ�˼��*/
	{
		/*to do*/
	};

};