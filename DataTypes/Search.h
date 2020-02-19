#pragma once

#include"Graph.h"
#include"Tree.h"

/*
��h�ļ���ϸ������һЩ�����㷨���õ��� ֮ǰ��һЩ���ݽṹ�������﷨
operation��
	void Sequential_Search()//��̬���ң����㷨��
	void Binary_SortTree()//����������
	void AVLLTree();//ƽ�������
	void Btree������//B��
	void HashTable();//��ϣɢ�б�
	
*/
class Search:public M_Graph ,public pre 
{
private:
	int length;
	
	int F[100]/*쳲���������*/
		{
			F[0]=0;
			F[1]=1;
			try {for(i= 2;i < length;i++){	F[i]= F[i-1]+ F[i-2]; };}
		};

public:

	Search(void)
	{
	}

	~Search(void)
	{
	}

	void Sequential_Search(int *a,int n,int key);//��̬���ң����㷨��
	void Sequential2_Search(int *a,int n,int key);
	void Binary_Search(int *a,int n,int key);
	void Interpolation_Search(int *a,int n,int key);
	void Fibonacci_Search(int *a,int n,int key);

	void Binary_SortTree();
	void Binary_SortTree();
	void Binary_SortTree();
	void Binary_SortTree();
	void Binary_SortTree();//����������

	#define LH +1/*��� */
	#define EH O /*�ȸ�*/
	#define RH -1 /*�Ҹ�*/
	void R_Rotate(BiTree *T);
	void L_Rotate(BiTree *T);
	void LeftBalance(BiTree *T);
	void RightBalance(BiTree *T);
	void InsertAVL(BiTree *T,int *e,bool *taller);//ƽ�������

	#define m 3/* B ���Ľף�����Ϊ3*/
	#define N 17/*����Ԫ�ظ��� */
	#define MAX 5/*�ַ�����󳤶�+1 */
	typedef struct BTNode
	{
		int keynum;/*����� �ؼ��ָ����������Ĵ�С*/
		struct BTNode *parent;/*ָ��˫�׽�� */
		struct Node/*�����������*/
		{
			int key;/*�ؼ������� */
			struct BTNode *ptr;/*����ָ������ */
			int recptr;/*��¼ָ������ */
		}node[m+1];/* key,recptr ��0�ŵ�Ԫδ��*/
	}BTNode,*BTree;/* B ������B��������*/
	typedef struct Result
	{
		BTNode *pt; /*ָ���ҵ��Ľ�� */
		int i;/* 1..m, �ڽ���еĹؼ������*/
		int tag;/* 1:���ҳɹ��� 0:����ʧ��*/
	}Result;/* B ���Ĳ��ҽ������*/

	int Search(BTree p, int K)/*��p->nodle1.keynum].key �в���i,ʹ��p->nodelj].key��K<p->nodel[+1.key */
	{
		int i=0,j; .
		for(j=1;j<=p->keynum;++)
		if(p->node[i].key<=K)
		i=j;
		return i; .
	}
	void SearchBST(BiTree T, int key, BITree f, BiTree *p);
	void Insert(BTree *q,int i,int key,BTree ap);
	void split(BTree *q,BTree *ap);
	void NewRoot(BTree *T,int key,BTree ap);
	void InsertBTree(BTree *T,int key,BTree q,int i);
	void Btree();//B��


	int m=0;/*ɢ�б����ȫ�ֱ���*/
	#define SUCCESS 1 
	#define UNSUCCESS 0
	#define HASHSIZE12/*����ɢ�б�Ϊ����ĳ���*/
	#define NULLKEY 32768
	typedef int Status; /* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK��*/
	typedef struct HashTable
	{
		int *elem;/*����Ԫ�ش洢��ַ����̬��������*/
		int count;/*��ǰ����Ԫ�ظ��� */
	}HashTable;

	void InitHashTable(HashTable *H);
	void Hash(int key);
	void InsertHash(HashTable *H,int key);
	void SearchHash(HashTable H,int key,int *addr);
	void HashTable();//��ϣɢ�б�

};


//��̬���ң����㷨��
void Search::Sequential_Search(int *a,int n,int key)
{///*���ڱ�˳����ң�aΪ���飬nΪҪ���ҵ����������key ΪҪ���ҵĹؼ���*/
	int i;
	for(i=1;i<=n;i++)
	{
		if (a[i]==key)
		return i;
	}
	return 0;
};
void Search::Sequential2_Search(int *a,int n,int key)
{/*���ڱ�˳�����*/
	int i;
	a[0]=key;
	i=n;
	while(a[i]!=key)
		i--;
	return i;
};
void Search::Binary_Search(int *a,int n,int key)
{/*�۰����*/
	int low,high,mid;
	low=1; /* ��������±�Ϊ��¼��λ*/
	high=n; /* ��������±�Ϊ��¼ĩλ*/
	while(low<=high)
		mid=(low+high)/2; /*�۰�*/
	if (key<a[mid])/*������ֵ����ֵС*/
		high=mid-1;/*����±��������λ�±�Сһλ*/
	else if (key>a[mid])/*������ֵ����ֵ��*/
		low=mid+1;/*����±��������λ�±��һλ*/
	else
	{
		return mid;/*�������˵��mid��Ϊ���ҵ���λ��*/
	}
	return 0;
};
void Search::Interpolation_Search(int *a,int n,int key)
{/*��ֵ����*/
	int low,high,mid;
	low=1; /* ��������±�Ϊ��¼��λ*/
	high=n; /* ��������±�Ϊ��¼ĩλ*/
	while(low<=high)
	{	
		mid=low+(high-low)*(keya[low)/alhigh]a[low]);/*��ֵ*/
		if (key<a[mid])/*������ֵ�Ȳ�ֵС*/
			high=mid-1;/*����±��������ֵ�±�Сһλ*/
		else if (key>a[mid])/*������ֵ�Ȳ�ֵ��*/
			low=mid+1;/*����±��������ֵ�±��һλ*/
		else
			return mid;/*�������˵��mid��Ϊ���ҵ���λ��*/
	}
	return 0;
};
void Search::Fibonacci_Search(int *a,int n,int key)
{/*쳲���������*/
	int low,high,mid,k=0;
	low=1; /* ��������±�Ϊ��¼��λ*/
	high=n; /* ��������±�Ϊ��¼ĩλ*/
	while(n>F[k]-1)
		k++;
	for (i=n;i<F[k]-1;i++)
		a[i]=a[n];
	while(low<=high)
	{
		mid=low+F[k-1]-1;
		if (key<a[mid])
		{
			high=mid-1;
			k=k-1;
		}
		else if (key>a[mid])
		{
			low=mid+1;
			k=k-2; 
		}
		else
		{
			if (mid<=n)
				return mid;/*�������˵��mid��Ϊ���ҵ���λ��*/
			else
				return n; 
		}
	}
	return 0;
};
//����������
void Search::SearchBST(BiTree T, int key, BITree f, BiTree *p)
{/*�ݹ���Ҷ���������T���Ƿ����key, */
/*ָ��fָ��T��˫�ף����ʼ����ֵΪNULL */
/*�����ҳɹ�����ָ��pָ�������Ԫ�ؽ�㣬������TRUE */
/*����ָ��pָ�����·���Ϸ��ʵ����-һ����㲢����FALSE */
			if(!T) /* ���Ҳ��ɹ�*/
			*p=f; .
			return FALSE;
			else if (key==T->data)/*���ҳɹ� */
			*p=T;
			return TRUE;
			else if (key<T->data)
			return SearchBST(T->lchild, key,T,p); /* ���������м������� */
			else
			return SearchBST(T->rchild, key,T,p); /* ���������м������� */
}
void Search::InsertBST(BiTree *T, int key)
{/* ������������T�в����ڹؼ��ֵ���key������Ԫ��ʱ�� */
/*���� key������TRUE�����򷵻�FALSE */
			Status InsertBST(BiTree *T, int key)
			BiTree p,S;
			if (!SearchBST(*T, key, NULL, &p))/*���Ҳ��ɹ�*/
			s = (BiTree)malloc(sizeof(BiTNodel);
			s->data = key;
			s->lchild = s->rchild = NULL;
			if (!p)
			*=s;
			/* ����sΪ�µĸ����*/
			else if (key<p->data)
			p->lchild=s; /*����sΪ���� */
			else
			p->rchild=s; /* ���� sΪ�Һ���*/
			return TRUE;
			else
			return FALSE; /* �������йؼ�����ͬ�Ľ�㣬 ���ٲ���*/
};
void Search::Delete(BiTree *p)
{/*�Ӷ�����������ɾ�����p�����ؽ����������������*/
			Status Delete(BiTree *p)
			BiTree q,s; .
			if(*p)->rchild=NULL)/*����������ֻ���ؽ�����������(��ɾ�����Ҷ��Ҳ�ߴ˷�֧)
			*/
			q=*p; *p=*p)->lchild; free(q);
			else f((*p)->IchiId==NULL)/*ֻ���ؽ�����������*/
			q=* p; *p=(*p)->rchild; free(q);
			else/*��������������*/
			{
			q=* p; s=(*p)->lchild;
			while(s->rchild)/*ת��Ȼ�����ҵ���ͷ(�Ҵ�ɾ����ǰ��) */
			{q=s;
			s=s->rchild;
			(*p)->data=s->data;/* s ָ��ɾ����ֱ��ǰ��(����ɾ���ǰ����ֵȡ����ɾ
			����ֵ) */
			if(q!=*p)
			q->rchild=s->lchild;/*�ؽ�q ��������*/
			else
			q->lchild=s->lchild;/*�ؽ� q��������*/
			free(s);
			}
			return TRUE;
}
};
void Search::DeleteBST(BiTree *Tint key)
{
/*������������T�д��ڹؼ��ֵ���key������Ԫ��ʱ����ɾ��������Ԫ�ؽ�㣬*/
/*������TRUE; ���򷵻�FALSE�� */
			Status DeleteBST(BiTree *Tint key)
			if(!*T)/*�����ڹؼ��ֵ���key������Ԫ��*/
			return FALSE;
			else
			{
			if (key-=(*T)->data)/*�ҵ��ؼ��ֵ���key������Ԫ��*/
			return Delete(T);
			else if (key<(*T)->data)
			return DeleteBST(&(T)->lchild,key);
			else
			return DeleteBST(&(*T)->rchild,key);
			}

};
void Search::Binary_SortTree()
{
	int i;
	int a[10]={62,88,58,47,35,73,51,99,37,93};
	BiTree T=NULL;
	for(i=0;i<10;++)
	{
		InsertBST(&T, a[i);
		DeleteBST(&T,93);
		DeleteBST(&T,47);
		printf("����������ϵ���ٲ鿴�����������ṹ");
		return 0;
	}


};
//ƽ�������
void Search::R_Rotate(BiTree *P)
{
/*����pΪ���Ķ�������������������*/
/*����֮��pָ���µ�������㣬����ת����֮ǰ���������ĸ����*/
	BiTree L;
	L=(*P)->lchild;/* L ָ��P�������������*/
	(*P)->lchild=L->rchild;/* L ���������ҽ�ΪP��������*/
	L->rchild=(*P);
	*P=L;/* P ָ���µĸ����*/
};
void Search::L_Rotate(BiTree *P)
{
	BiTree R;
	R=(*P)->rchild;/* R ָ��P�������������*/
	(*P)->rchild=R- >lchild; /* R���������ҽ�ΪP��������*/
	R->Ichild=(*P);
	*P=R;/* P ָ���µĸ����*/
};
void Search::LeftBalance(BiTree *T)
{
/*����ָ��T��ָ���Ϊ���Ķ���������ƽ����ת����*/
/*���㷨����ʱ�� ָ��Tָ���µĸ����*/
			BiTree L,Lr;
			L=(T)->lchild;/* L ָ��T�������������*/
			switch(L->bf)
			{/*���T����������ƽ��ȣ�������Ӧƽ�⴦��*/
			caseLH:/*�½������� T�����ӵ��������ϣ�Ҫ������������*/
			(*T)->bf=L->bf=EH;
			R_ Rotate(T);
			break;
			case RH:/*�½������� T�����ӵ��������ϣ�Ҫ��˫������*/
			Lr=L->rchild;/* Lr ָ��T�����ӵ���������*/
			switch(Lr->bf)
			{/*�޸�T �������ӵ�ƽ������*/
			case LH: (*T)->bf=RH;
			L->bf=EH;
			break;
			case EH: (*T)->bf=L->bf=EH;
			break;
			case RH: (*T)->bf=EH;
			L->bf=LH;
			break;
			}
			Lr->bf-=EH;
			L Rotate(&(T)->lchild);/*��T��������������ƽ�⴦��*/
			R_ Rotate(T);/*�� T������ƽ�⴦��*/
			}

};
void Search::RightBalance(BiTree *T)
{
			BiTree R,RI; .
			R=(*T)->rchild;/* R ָ��T�������������*/
			switch(R->bf)
			{/* ���T����������ƽ��ȣ�������Ӧƽ�⴦��*/
			case RH:/*�½������� T���Һ��ӵ��������ϣ�Ҫ������������*/
			(T)->bf=R->bf=EH;
			L Rotate(T);
			break;
			case LH:/*�½������� T���Һ��ӵ��������ϣ�Ҫ��˫������*/
			Rl=R->lchild;/* RI ָ��T���Һ��ӵ���������*/
			switch(Rl->bf)
			{/* �޸�T�����Һ��ӵ�ƽ������*/
			case RH: (T)->bf=LH;
			R->bf=EH; :
			break;
			case EH: (*T)->bf=R->bf=EH;
			break;
			case LH: (*T)->bf=EH;
			R->bf=RH;
			break; ;
			}
			Rl->bf=EH;
			R_ Rotate(&(*T)->rchild);/*�� T��������������ƽ�⴦��*/
			L_ Rotate(T);/*��T������ƽ�⴦��*/

			}
};
void Search::InsertAVL(BiTree *T,int e,Status *taller)
{
/* ����ƽ��Ķ���������T�в����ں�e����ͬ�ؼ��ֵĽ�㣬�����һ��*/
/* ����Ԫ��Ϊe���½�㣬������1�����򷵻�0����������ʹ����������*/
/*ʧȥƽ�⣬ ����ƽ����ת������������tllr��ӳT�������*/
			if(!*T)
			{/* �����½�㣬�������ߡ�����tllrΪTRUE */
			*T=(BiTeealloc(sizeof(BiTNodel);
			(*T)->data=e; (*T)->/child=(*T)->rchild=NULL; (*T)->bf=EH;
			*taller=TRUE;
			}
			else
			{
			if (e==(*T)->data)
			{/*�����Ѵ��ں� e����ͬ�ؼ��ֵĽ�����ٲ���*/
			*taller=FALSE; return FALSE;
			}}

};

//B��
Result Search::SearchBTree(BTree T, int K)
{
/*��m��B��T�ϲ��ҹؼ���K�� ���ؽ��(pt,tag)�� �����ҳɹ���������ֵ*/
/* tag=1, ָ��pt��ָ����е�i���ؼ��ֵ���K;��������ֵtag=0������K��*/
/*�ؼ���Ӧ������ָ�� Pt��ָ����е�i�͵�i+1���ؼ���֮�䡣*/
			Result SearchBTree(BTree T, int K)
			BTree p=T,q=NULL;/*��ʼ���� pָ������㣬q ָ��p��˫��*/
			Status found=FALSE;
			int i=0; .
			Result r;
			while(p&&!found)
			i=Search(p,K);/* p->nodelij].key��K<p->node[i+1].key */
			if(i>0&p->nodel[j.ke==K)/*�ҵ�����ؼ��� */
			{found=TRUE;
			else
			{
			q=p;
			p=p->node[].ptr;
			}
}
			r.i=i;
			if(found)/*���ҳɹ�*/
			{r.pt=p;
			r.tag=1;}
			else/*���Ҳ��ɹ��� ����K�Ĳ���λ����Ϣ*/
			{r.pt=q;
			r.tag=0;}
			return r;


};
void Search::Insert(BTree *q,int i,int key,BTree ap)
{/*��r->key�� r��ap�ֱ���뵽q->key/[i+1]��q->recptr[i+1]�� q->ptr[+1]��*/
			int j;
			for(j=(*)->keynum;)ij-)/*�ճ�(*)->node[i+1] */
			{(*q)->node[i+1]=(*q)->node[j];
			(*q)->nodel[i+1].key=key; .
			(*q)->nodel[i+1].ptr=ap;
			(*q)->node[i+1].recptr=key;
			(*q)->keynum++;
			}
};
void Search::split(BTree *q,BTree *ap)
{/*�����q���ѳ�������㣬ǰһ�뱣������һ�������������ap*/
			void split(BTree *q,BTree *ap)
			int i,s=(m+1)/2;
			*ap=8Tel)alloc(sizeof(BNode)):/*�����½�� ap */
			(*ap)>node([)]ptr=(*q)->nodefsl.ptr;/*��һ ������ ap */
			for(i=s+1;i<=m;i++)
			(* ap)->node[i-s]=(*q)->node[i];
			if(*ap)->node[-sJ.ptr)
			(*p)->node[i-sJ.ptr->parent=*ap;
			(*ap)->keynum=m-s;
			(*ap)->parent=(*q)->parent;
			(*q)->keynum=s-1;/* q ��ǰһ�뱣�����޸�keynum */


};
void Search::NewRoot(BTree *T,int key,BTree ap)
{/*���ɺ���Ϣ(T,rap)���µĸ����&T,ԭT��apΪ����ָ��*/
			BTree p;
			p=(BTree)malloc(sizeof(BTNodel);
			p->node[0].ptr=*T;
			*T=p;
			if(*T)->node[0].ptr)
			(T)->nodel0]ptr->parent=*T;
			(*T)->parent=NULL;
			(T)->keynum=1;
			(T)->node[1].key=key;
			(T)->node[1].recptr=key;
			(*T)->node[1].ptr=ap;
			if(IT)->node[1].ptr)
			(T)->node[1].ptr->parent=*T;


};
void Search::InsertBTree(BTree *T,int key,BTree q,int i)
{/* ��m��B��T�Ͻ��*q��key[]��key[i+1]֮�����ؼ���K��ָ��r��������*/
/* ����������˫�������б�Ҫ�Ľ����ѵ���,ʹT����m��B���� */

			BTree ap=NULL;
			Status finished=FALSE;
			ints; 
			int rx;
			rx=key;
			while(q&& !finished)
			Insert(&q,nx,ap); /*��r->key��r��ap�ֱ���뵽q->key[i+1]��q->recptr(i+1]��
			g->ptr[i+1]��*/
			if(q->keynum<m)
			finished=TRUE;/*������� */
			else
			{/*���ѽ��*q*/ 
			s=(m+1)/2;
			rx=q->node[s].recptr;
			split(&q,&ap); /*��q-><eylst1.m.),->ptrs..m]��q->recptr5+1..m]�����½�� *ap */
			q=q->parent;
			if(q)
			i=Search(q,key);/*��˫�׽� ��*q�в���rx->key�Ĳ���λ��*/
			}
			if(lfinished)/* T �ǿ���(����q��ֵΪNULL)�������ѷ���Ϊ���*q��*ap */
			NewRoot(T,rx,ap); /*���ɺ� ��Ϣ(,rx,ap)���µĸ����ƣ�ԭT��apΪ����ָ��
			*/



};
void Search::Btree()
{
	
			int r[N]={22,16,41,58,8,11,12,16,17,22,23,31,41,52,58,59,61};
			BTree T=NUL;
			Result s;
			int i;
			for(i=0;i<N;i++)
			s=SearchBTree(T,[i]);
			if(ls.tag)
			InsertBTeel(&,lis,spt,si);
			printf("\n����������Ҽ�¼�Ĺؼ���: ");
			scanf("%d",&i);
			s=SearchBTree(T,i);
			if(s.tag)
				priftf("(%d)",(s.pt)->node[s.i].key);/*prit(*(s.pt),s.i);priftf("(%d)",c.nodelij.key);*/
			else
			printf("û�ҵ�");
			printf("\n"); .
			return 0; 


};
//��ϣɢ�б�
void Search::InitHashTable(HashTable *H)
{/*��ʼ��ɢ�б�*/

	int i;
	m=HASHSIZE;
	H->count=m;
	H->elem=(int *)malloc(m*sizeofint));
	for(i=;k<m;++)
		H->elem[)=NULLKEY;
	return OK;

};
void Search::Hash(int key)
{/*ɢ�к���*/
	return key% m;/*����������*/
};
void Search::InsertHash(HashTable *H,int key)
{/*����ؼ��ֽ�ɢ�б�*/
	int addr = Hash(key); /*��ɢ�е�ַ*/
	while (H->elem[addr] != NULLKEY)/*�����Ϊ�գ����ͻ*/
	{addr = (addr+1) % m; /*���Ŷ�ַ��������̽��*/
	}
	H->elem[addr] = key;/*ֱ���п�λ�����ؼ���*/
};
void Search::SearchHash(HashTable H,int key,int *addr)
{
	Status SearchHash(HashTable H,int key,int *addr)
	*addr = Hash(key); /* ��ɢ�е�ַ*/
	while(H.elem[*addr] != key)/*�����Ϊ�գ����ͻ*/
		*addr = (*addr+1) % m; /*���Ŷ�ַ��������̽��*/
	if (H.elem[*addr] = NULLKEY II *addr == Hash(key) /*���ѭ���ص�ԭ��*/
		return UNSUCCESS;/*��˵���ؼ��ֲ�����*/
	return SUCCESS;

};
void Search::HashTable()
{
	int arr[HASHSIZE]={12,67,56,16,25,37,22,29,15,47,48,34};
	int i,p,key,result;
	HashTable H;
	key=39;
	InitHashTable(&H);
	for(i=0;i<m;i++)
		InsertHash(&H,rr[);
	result=SearchHash(H,key,&p);
	if (result)
		printf("����%d�ĵ�ַΪ: %d \n",key.p);
	else
		print("����%dʧ�ܡ�\n" ,key);
	for(i=0;i<m;++)
	{
		key=arr[i];
		SearchHash(H,key,&p);
		printf("����%d�ĵ�ַΪ: %d \n",key.p);
	}
	return 0;
}: