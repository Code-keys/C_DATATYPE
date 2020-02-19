#pragma once
#include"math.h"
#include <iostream>
using namespace std;
/*
本头文件主要详细列些树的存储结构：

ADT 树 (tree)
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
		RightSibling()  /*右兄弟
		InsertChild(*T,*p,i,c)
		DeleteChild(T,p,i)
END-ADT
*/
#define MAX_TREE_SIZE 100
typedef char* TreeElemType;
typedef int TElemType ;

class TTree
{
private:/*双亲表示法*/
	typedef struct PTNode
	{
		TreeElemType data;
		int parent;/*双亲位置下标 -1*/

		int rightSib;
		int FirstChild;/*长子 次子*/

	}PTNode;
	typedef struct PTree
	{
		PTNode nodes[MAX_TREE_SIZE];/*树的顺序存储结构*/
		int r,n;/*根的位置及其节点数*/

	}PTree;
protected:/*孩子表示法【指针】*/
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

public:/*孩子兄弟表示法*/
	typedef struct CSNode
	{
		TreeElemType data;
		struct CSNode *firstchild,*rightsib,*parent;
	}*CSTree;

public:/*二叉树的存储*/
	typedef struct DTree 
	{
		TreeElemType data[MAX_TREE_SIZE];
		/* [0]->[1、2]->[3、4、5、6].。。。。。层的数目递归*/
	};
	typedef struct BiTNode
	{
		TreeElemType data;
		struct BiTNode *Lchild,*Rchild;/*,*parent*/
	}BiTNode,*BiTree;
//Operation:
	void CreateBiTree(BiTree *T)/*前序输入 递归创建*/
	{
		TreeElemType chr;
		scanf_s("%c",&chr);
		if (chr=="#") *T = NULL;
		else
		{
			*T = (BiTree)malloc(sizeof(BiTNode));
			if (!*T)exit(OVERFLOW);

			(*T)->data = chr;
			CreateBiTree(&(*T)->Lchild);/*构造节点*/
			CreateBiTree(&(*T)->Rchild);
		};
	};

	void PreOrderTraverse(BiTree T)/*前序遍历 递*/
	{
		if (T==NULL) return;

		printf("%c",T->data);
		PreOrderTraverse(T->Lchild);
		PreOrderTraverse(T->Rchild);	
	};	
	void InOrderTraverse(BiTree T)/*中序遍历*/
	{
		if (T==NULL) return;
		 
		InOrderTraverse(T->Lchild);
		printf("%c",T->data);
		InOrderTraverse(T->Rchild);	
	};
	void PostOrderTraverse(BiTree T)/*后序遍历*/
	{
		if (T==NULL) return;
		 
		PostOrderTraverse(T->Lchild);
		PostOrderTraverse(T->Rchild);	
		printf("%c",T->data);
	};
public:/*线索二叉树*/
	typedef enum {Link,Thread}PointerTag;/*link ==0  为孩子，thread == 0为前驱后继*/
	typedef struct BiThrNode
	{
		TElemType data;
		struct BiThrNode *Lchild,*Rchild;
		PointerTag LTag;
		PointerTag RTag;
	}BiThrNode,*BiThrTree;
	BiThrTree _ptr;

	void InThreading(BiThrTree T)/*中序遍历*/
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
	void InOrderTraver_Thr(BiThrTree T)/*中序遍历二叉线索树*/
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
public:/*森林*/
	typedef struct Forest
	{
		BiThrTree *q1;
		BiTree *q2;
		/* and so on */
	};
	
public:/*带权路径 二叉树化为霍夫曼树（最优化）*/
	typedef struct HofumanTree/*霍夫曼编码类似的思想*/
	{
		/*to do*/
	};

};