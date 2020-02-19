#pragma once
#include <math.h>
#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <exception>
#pragma comment(lib,"User32")

#ifndef error
#define error 0

using namespace std;
#define MAXSIZE 2000;
typedef int ElemType;
#endif
/*可以为 int float char long Double 、、、、、 */
/*ADT
本头文件主要详细列些线性表的存储结构：   查找（已知大小） VS 插入、删除（未知个数） 
	{
		顺序存储结构；线性表 栈 队列
		链式存储结构(单链表、静态链表、循环链表、双向链表)；
	}
操作:  
	{
		创建与初始化；
		置空；
		获取元素；
		查找；
		表长度；
		插入与删除；
	}
endADT
*/

class fun 
{
public:
	virtual void  _funA_()
	{
		::MessageBox(NULL, "你好，OJBK。", ("标题"),MB_OK);
	};
	virtual void  _funB_()
	{
		::MessageBox(NULL, "你好，ERROR。", ("标题"),MB_OK);
	};
	virtual void  _funC_();
	virtual void  _funD_();
	virtual void  _funE_();
	virtual void  _funF_();
	virtual void  _funG_();

};
/* 1、顺序存储结构 */
class Sqlist :public fun
{
private:
	int MaxSize;
	int* data;
	
protected:
	virtual void _funA_(){::MessageBox(NULL, "你好，0.0。", ("标题"),MB_OKCANCEL);}; 
	
	typedef	struct sqList
		{
			//static const int a=new int[10];
			ElemType* data;
			int length;/*表长*///分配的内存容量
		}sqList;
	/*队列的顺序存储结构*/
	typedef	struct queue
		{
			int data[MAXSIZE];
			int front;/* 头指针*/
			int rear;/*尾指针,若队列不空,指向队列尾元素的下一个位置*/
		
		}queue;/*初始化一个空队列Q*/

	void InitQueue(queue *Q)
	{
		Q->front=0;
		Q->rear=0;
		return fun::_funA_();
	};


public:

	void GetElem(sqList L,int i,ElemType *e)
	{
		if (L.length==0 || i<1 || i>L.length) return _funA_();
		*e = L.data[i-1];
		return fun::_funA_() ;
	};

	void ListInsert(sqList L,int i,ElemType *e)
	{
		if (L.length==0 || i<1 || i>L.length) return fun::_funB_() ;
		if (i <= L.length)
		{
			for (int k = L.length;k >= i-1;	k--)
			{
				L.data[k+1] = L.data[k];
			};
		};	
		L.data[i-1] = int(e[0]);
		L.length++;
		return	fun::_funA_() ;
	};

	void ListDelete(sqList L,int i,ElemType *e)
	{
		if (L.length==0 || i<1 || i>L.length) return fun::_funB_() ;
		*e = L.data[i-1];
		if (i < L.length)
		{
			for (int k = i;k < L.length;	k++)
			{
				L.data[k-1] = L.data[k];
			};
		};
		L.length++;
		return fun::_funA_() ;
	};





};
class Stack :public fun , public sqlist
{
public:/*栈【递归与后缀表达式】*/
	typedef	struct SqStack
		{
			ElemType data[MAXSIZE];
			int top;//-1 -> 0 -> x

		}SqStack;
	void Push(SqStack *S,ElemType *e)
	{
		if (S->top == MAXSIZE-1){return fun::_funB_()};
		S->top++;
		S->data[S->top] = *e;
		return fun::_funA_();
	};
	void Pop(SqStack *s,ElemType *e)
	{
		if (s->top == -1){return fun::_funB_()};
		*e = s->data[s->top];
		s->top--;
		return fun::_funA_();
	};
public:/*两栈共享空间*/
	typedef struct SqDoubleStack
	{
		ElemType data[MAXSIZE];
		int top1;
		int top2;
	}SqDoubleStack;
	void Push(SqDoubleStack *s,ElemType *e,int stackNum)
	{
		if (s->top1+1 == s->top2){return fun::_funB_();};
		if (stackNum == 1)s->data[++s->top1 = *e];
		else if (stackNum == 2)s->data[--s->data=*e];
		return fun::_funA_();
	};
	void Pop(SqDoubleStack *s,ElemType *e,int stackNum)
	{
		if (stackNum==1)
		{
			if (s->top1==-1)
			{
				return fun::_funB_();
			};
			*e = s->data[s->top1--];
		}else if(stackNum==2)
		{
			if (s->top2==MAXSIZE)
				return fun::_funB_();
			*e =s->data[s->top2++];
		};
		return fun::_funA_;
	};

public:/*链式存储结构*/
	typedef struct StackNode
	{
		ElemType data;
		struct StackNode *next;
	}StackNode,*LinkStackPtr;
	typedef struct LinkStack
	{
		LinkStackPtr top;
		int count;
	}LinkStack;
	bool StackEmpty(LinkStack *S)
	{
		if (S->top)
			return 0;
		else return 1;
	};
	void Push(LinkStack *S,ElemType *e)
	{
		LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
		s->data = *e;
		s->next = S->top;
		S->top = s;
		S->count++;
		return fun::_funA_();
	};
	void Pop(LinkStack *S,ElemType *e)
	{
		LinkStackPtr p;
		if (StackEmpty(*S))return fun::_funB_();
		*e = S->top->data;
		p = S->top;
		S->top = S->top->next;
		free(p);
		S->count--;
		return fun::_funA_();
	};
};


class Queue:public fun
{
	/*initQueue\DestoryQueue\ClearQueue\QueueEmpty\GetHead\EnQueue\DeQueue\QueueLength*/
protected:
	SqQueue _Q;
public:/*循环队列*/
	typedef	struct SqQueue
		{
			ElemType data[MAXSIZE];
			int front;
			int rear;
		}SqQueue;
	void initQueue(SqQueue *Q);
	{
		Q->front = 0;
		Q->rear = 0;
		return fun::_funA_();
	};
	int QueueLength(SqQueue *Q)
	{
		return (Q->rear-Q->front+MAXSIZE) % MAXSIZE;
	};
	void EnQueue(SqQueue *Q,ElemType *e)
	{
		if (Q->rear+1)%MAXSIZE == Q->front)return fun::_funB_();
		Q->data[Q->rear] = *e;
		Q->rear = (Q->rear+1)% MAXSIZE;
		return fun::_funA_();
	};
	void DeQueue(SqQueue *Q,ElemType *e)
	{
		if (Q->front == Q->rear)return fun::_funB_();
		*e = Q->data[Q->front];
		Q->front = (Q->front+1) % MAXSIZE;
		return fun::_funA_(); 
	};
public:/*链式存储*/
	typedef struct QNode
	{
		ElemType data;
		struct QNode *next;
	}QNode,*QueuePtr;
	typedef struct LinkQueue
	{
		QueuePtr front,rear;
	}LinkQueue;
	void EnQueue(LinkQueue *Q,ElemType *e)
	{
		QueuePtr s = (QueuePtr)malloc(sizeof (QNode));
		if (!s)exit(OVERFLOW);
		s->data = *e;
		s->next = NULL;
		Q->rear->next= s;
		Q->front = s;
		return fun::_funA_();
	};
	void DeQueue(LinkQueue *Q,ElemType *e)
	{
		QueuePtr p;
		if (Q->front == Q->rear)return fun::_funB_();
		p = Q->front->next;
		*e = p->data;
		Q->front->next = p->next;
		if (Q->rear == p) Q->rear = Q->front;
		free(p);
		return fun::_funA_();
	};

};

/* 2、链表存储结构 */
class linkList :public fun
{
private:
protected:
	virtual void  _funA_();
public:
	/* 单链表 */
	int* data;
	typedef struct Node
	{
		ElemType data;
		struct Node *next;
	}Node;
	typedef struct Node* LinkList;

	void GetElem(LinkList L,int i,ElemType *e)
	{
		LinkList p;
		p = L->next;
		int j = 1;
		while(p && j<i)
		{
			 p  = p->next;
			 ++j;
		};
		if (!p || j>i) return fun::_funB_() ;
		*e = p->data;
		return fun::_funA_()  ;
	};

	void ListInsert(LinkList L,int i,ElemType *e)
	{
		LinkList p , s;
		p = *L;
		int j = 1;
		while(p && j<i)
		{
			 p  = p->next;
			 j++;
		};
		if (!p || j>i) return fun::_funB_() ;

		s = (LinkList)malloc(sizeof(Node));
		s->data = e[0];
		s->data = p->next;
		p->data = s;
		return fun::_funA_()  ;
	};

	void ListDelete(LinkList L,int i,ElemType *e)
	{
		LinkList p,q;
		p = *L;
		int j = 1;
		while(p->next && j<i)
		{
			 p  = p->next;
			 j++;
		};
		if (!p->next || j>i) return fun::_funB_() ;
		q = p->next;
		p->next = q->next;
		free(q);
		delete q;
		return fun::_funA_() ;
	};
	/*头插法创建的*/
	void CreateListHead(LinkList *L,int n,ElemType *e)  
	{
		LinkList p;
		int i;
		*L = (LinkList)malloc(sizeof(Node));
		(*L)->next = NULL;
		for (i = 0;i<n;i++)
		{
			p = (LinkList)malloc(sizeof(Node));

			try {
				p->data = e[i];
			}catch(std::exception()){
				p->data = NULL;
			};

			p->next = (*L)->next;

			(*L)->next = p;
		};
	};
	/*尾插法创建的*/
	void CreateListTail(LinkList *L,int n,ElemType *e)  
	{
		LinkList p,r;
		int i;
		*L = (LinkList)malloc(sizeof(Node));
		r = *L ;
		for (i = 0;i<n;i++)
		{
			p = (Node *)malloc(sizeof(Node));

			try {
				p->data = e[i];
			}catch(std::exception()){
				p->data = NULL;
			};

			r->next = p;
			r = p;
		};
		r->next = NULL;
	};
	void ClearList(LinkList* L)
	{
		LinkList  p,q;
		p = (*L)->next;
		while(p)
		{
			q = p->next;
			free(p);
			p =q ;
		};
		(*L)->next = NULL;
		return fun::_funA_(); 
	};


};
class StaticLinkList :public fun
{
private:
protected:
	virtual void  _funA_();
public:/*静态链表*/
	typedef struct Component
	{
		ElemType data;
		int cur;
	}Component,StaticLinkList[MAXSIZE];
	void InitStaList(StaticLinkList space)
	{
		int i;
		for (i =0;i<MAXSIZE-1;i++)
		{
			space[i].cur = i+1;
		};
		space[MAXSIZE-1].cur = 0;
		return fun::_funB_();
	};
	int  Malloc_SLL(StaticLinkList space)
	{
		int i = space[0].cur;
		if (space[0].cur)
			space[0].cur =space[i].cur;
		return i;
	};


public:
	void ListInsert(StaticLinkList L,int i ,ElemType e)
	{
		int j,k,l;
		k = MAXSIZE-1;/*修改为元素的最后一个下标*/
		if (i <1  ||i>ListLength(L)+1 )
			return fun::_funB_();
		j = Malloc_SSL(L);
		if(j)
		{
			L[j].data = e;
			for (l = 1;l<=i-1;l++)
				k = L[k].cur;
			L[k].cur = L[k].cur;
			L[k].cur = j;
			return fun::_funA_();
		};
		return fun::_funB_();

	};

	void ListDelete(StaticLinkList L;int i)
	{
		int j.k;
		if (i<1 ||i>ListLenth(L)+1)
			return fun::_funB_();
		k = MAXSIZE-1;
		for (j = 1;j<=i-1;j++)
				k = L[k].cur;
		j = L[k].cur;
		L[k].cur = L[j].cur;
		free_SSL(L,j);
		return fun::_funA_();
			
	};
protected:
	int Listlenth(StaticLinkList L)
	{
		/* to do */
		int i = 0;
		int count = 0;
		while(i)
		{
			if (L[i].cur)
				i = L[0].cur;
			count++;
		};
		return count;
	};
	void free_SSL(StaticLinkList L,int k)
	{
		L[k].cur = L[0].cur;
		L[0].cur = k;
	};


	
};
class CircleLinkList :public fun
{
public:
	/*循环链表*/
	typedef struct Node* CircleLinkList;
	void CircleLinkList(CircleLinkList space,ElemType *e)
	{
		int i;
		for (i =0;i<MAXSIZE-1;i++)
		{
			space[i].cur = i+1;
		};
		space[MAXSIZE-1].cur = 0;
		return fun::_funB_();
	};
	void Merge(CircleLinkList a,){/*to do*/};
};
class DuLinkList :public fun
{
private:
protected:
	virtual void  _funA_();
public:
	/*双向链表DLL*/
	typedef struct DulNode
	{
		ElemType data;
		struct DulNode *prior;
		struct DulNode *next;
	}DulNode,*DuLinkList;
	
	virtual void initDLL(DuLinkList *L,ElemType *e)
	{
		DuLinkList p;
		p = p->prior->next;
		p->next->prior = p;
		L[0]->next->prior = p;

	};
	virtual void InsertElem(DuLinkList p,ElemType *e)
	{
		//q = (DuLinkList)malloc(sizeof(DulNode));
		/*TO  DO*/
		DuLinkList s;
		s->data = *e;

		s->prior = p;
		s->next = p->next;
		p->next->prior = s;
		p->next = s;

	};
	
	virtual void GetElem():
	virtual void ListLength();
	virtual DuLinkList LocateElem(DuLinkList L,ElemType *e)
	{
		DuLinkList p;
		while(p->next)
		{
			if (p->data = *e)break;
			p = L->next ;
		};
		return p;
	};
	void DeleteElem(DuLinkList L,ElemType *e)
	{
		DuLinkList p = LocateElem(DuLinkList L,ElemType *e);
		p->prior->next = p->next;
		p->next->prior = p->prior;
		L = p->next;
		free(p);
		return fun::_funA_();
	}:
};
