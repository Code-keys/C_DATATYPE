#pragma once

#include"Graph.h"
#include"Tree.h"

/*
本h文件详细定义了一些查找算法，用到了 之前的一些数据结构基本类语法
operation：
	void Sequential_Search()//静态查找（多算法）
	void Binary_SortTree()//二叉排序树
	void AVLLTree();//平衡二叉树
	void Btree（）；//B树
	void HashTable();//哈希散列表
	
*/
class Search:public M_Graph ,public pre 
{
private:
	int length;
	
	int F[100]/*斐波那契数列*/
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

	void Sequential_Search(int *a,int n,int key);//静态查找（多算法）
	void Sequential2_Search(int *a,int n,int key);
	void Binary_Search(int *a,int n,int key);
	void Interpolation_Search(int *a,int n,int key);
	void Fibonacci_Search(int *a,int n,int key);

	void Binary_SortTree();
	void Binary_SortTree();
	void Binary_SortTree();
	void Binary_SortTree();
	void Binary_SortTree();//二叉排序树

	#define LH +1/*左高 */
	#define EH O /*等高*/
	#define RH -1 /*右高*/
	void R_Rotate(BiTree *T);
	void L_Rotate(BiTree *T);
	void LeftBalance(BiTree *T);
	void RightBalance(BiTree *T);
	void InsertAVL(BiTree *T,int *e,bool *taller);//平衡二叉树

	#define m 3/* B 树的阶，暂设为3*/
	#define N 17/*数据元素个数 */
	#define MAX 5/*字符串最大长度+1 */
	typedef struct BTNode
	{
		int keynum;/*结点中 关键字个数，即结点的大小*/
		struct BTNode *parent;/*指向双亲结点 */
		struct Node/*结点向量类型*/
		{
			int key;/*关键字向量 */
			struct BTNode *ptr;/*子树指针向量 */
			int recptr;/*记录指针向量 */
		}node[m+1];/* key,recptr 的0号单元未用*/
	}BTNode,*BTree;/* B 树结点和B树的类型*/
	typedef struct Result
	{
		BTNode *pt; /*指向找到的结点 */
		int i;/* 1..m, 在结点中的关键字序号*/
		int tag;/* 1:查找成功， 0:查找失败*/
	}Result;/* B 树的查找结果类型*/

	int Search(BTree p, int K)/*在p->nodle1.keynum].key 中查找i,使得p->nodelj].key≤K<p->nodel[+1.key */
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
	void Btree();//B树


	int m=0;/*散列表表长，全局变量*/
	#define SUCCESS 1 
	#define UNSUCCESS 0
	#define HASHSIZE12/*定义散列表长为数组的长度*/
	#define NULLKEY 32768
	typedef int Status; /* Status是函数的类型,其值是函数结果状态代码，如OK等*/
	typedef struct HashTable
	{
		int *elem;/*数据元素存储基址，动态分配数组*/
		int count;/*当前数据元素个数 */
	}HashTable;

	void InitHashTable(HashTable *H);
	void Hash(int key);
	void InsertHash(HashTable *H,int key);
	void SearchHash(HashTable H,int key,int *addr);
	void HashTable();//哈希散列表

};


//静态查找（多算法）
void Search::Sequential_Search(int *a,int n,int key)
{///*无哨兵顺序查找，a为数组，n为要查找的数组个数，key 为要查找的关键字*/
	int i;
	for(i=1;i<=n;i++)
	{
		if (a[i]==key)
		return i;
	}
	return 0;
};
void Search::Sequential2_Search(int *a,int n,int key)
{/*有哨兵顺序查找*/
	int i;
	a[0]=key;
	i=n;
	while(a[i]!=key)
		i--;
	return i;
};
void Search::Binary_Search(int *a,int n,int key)
{/*折半查找*/
	int low,high,mid;
	low=1; /* 定义最低下标为记录首位*/
	high=n; /* 定义最高下标为记录末位*/
	while(low<=high)
		mid=(low+high)/2; /*折半*/
	if (key<a[mid])/*若查找值比中值小*/
		high=mid-1;/*最高下标调整到中位下标小一位*/
	else if (key>a[mid])/*若查找值比中值大*/
		low=mid+1;/*最低下标调整到中位下标大一位*/
	else
	{
		return mid;/*若相等则说明mid即为查找到的位置*/
	}
	return 0;
};
void Search::Interpolation_Search(int *a,int n,int key)
{/*插值查找*/
	int low,high,mid;
	low=1; /* 定义最低下标为记录首位*/
	high=n; /* 定义最高下标为记录末位*/
	while(low<=high)
	{	
		mid=low+(high-low)*(keya[low)/alhigh]a[low]);/*插值*/
		if (key<a[mid])/*若查找值比插值小*/
			high=mid-1;/*最高下标调整到插值下标小一位*/
		else if (key>a[mid])/*若查找值比插值大*/
			low=mid+1;/*最低下标调整到插值下标大一位*/
		else
			return mid;/*若相等则说明mid即为查找到的位置*/
	}
	return 0;
};
void Search::Fibonacci_Search(int *a,int n,int key)
{/*斐波那契查找*/
	int low,high,mid,k=0;
	low=1; /* 定义最低下标为记录首位*/
	high=n; /* 定义最高下标为记录末位*/
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
				return mid;/*若相等则说明mid即为查找到的位置*/
			else
				return n; 
		}
	}
	return 0;
};
//二叉排序树
void Search::SearchBST(BiTree T, int key, BITree f, BiTree *p)
{/*递归查找二叉排序树T中是否存在key, */
/*指针f指向T的双亲，其初始调用值为NULL */
/*若查找成功，则指针p指向该数据元素结点，并返回TRUE */
/*否则指针p指向查找路径上访问的最后-一个结点并返回FALSE */
			if(!T) /* 查找不成功*/
			*p=f; .
			return FALSE;
			else if (key==T->data)/*查找成功 */
			*p=T;
			return TRUE;
			else if (key<T->data)
			return SearchBST(T->lchild, key,T,p); /* 在左子树中继续查找 */
			else
			return SearchBST(T->rchild, key,T,p); /* 在右子树中继续查找 */
}
void Search::InsertBST(BiTree *T, int key)
{/* 当二叉排序树T中不存在关键字等于key的数据元素时， */
/*插入 key并返回TRUE，否则返回FALSE */
			Status InsertBST(BiTree *T, int key)
			BiTree p,S;
			if (!SearchBST(*T, key, NULL, &p))/*查找不成功*/
			s = (BiTree)malloc(sizeof(BiTNodel);
			s->data = key;
			s->lchild = s->rchild = NULL;
			if (!p)
			*=s;
			/* 插入s为新的根结点*/
			else if (key<p->data)
			p->lchild=s; /*插入s为左孩子 */
			else
			p->rchild=s; /* 插入 s为右孩子*/
			return TRUE;
			else
			return FALSE; /* 树中已有关键字相同的结点， 不再插入*/
};
void Search::Delete(BiTree *p)
{/*从二叉排序树中删除结点p，并重接它的左或右子树。*/
			Status Delete(BiTree *p)
			BiTree q,s; .
			if(*p)->rchild=NULL)/*右子树空则只需重接它的左子树(待删结点是叶子也走此分支)
			*/
			q=*p; *p=*p)->lchild; free(q);
			else f((*p)->IchiId==NULL)/*只需重接它的右子树*/
			q=* p; *p=(*p)->rchild; free(q);
			else/*左右子树均不空*/
			{
			q=* p; s=(*p)->lchild;
			while(s->rchild)/*转左，然后向右到尽头(找待删结点的前驱) */
			{q=s;
			s=s->rchild;
			(*p)->data=s->data;/* s 指向被删结点的直接前驱(将被删结点前驱的值取代被删
			结点的值) */
			if(q!=*p)
			q->rchild=s->lchild;/*重接q 的右子树*/
			else
			q->lchild=s->lchild;/*重接 q的左子树*/
			free(s);
			}
			return TRUE;
}
};
void Search::DeleteBST(BiTree *Tint key)
{
/*若二叉排序树T中存在关键字等于key的数据元素时，则删除该数据元素结点，*/
/*并返回TRUE; 否则返回FALSE。 */
			Status DeleteBST(BiTree *Tint key)
			if(!*T)/*不存在关键字等于key的数据元素*/
			return FALSE;
			else
			{
			if (key-=(*T)->data)/*找到关键字等于key的数据元素*/
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
		printf("本样例建议断点跟踪查看二叉排序树结构");
		return 0;
	}


};
//平衡二叉树
void Search::R_Rotate(BiTree *P)
{
/*对以p为根的二叉排序树作右旋处理，*/
/*处理之后p指向新的树根结点，即旋转处理之前的左子树的根结点*/
	BiTree L;
	L=(*P)->lchild;/* L 指向P的左子树根结点*/
	(*P)->lchild=L->rchild;/* L 的右子树挂接为P的左子树*/
	L->rchild=(*P);
	*P=L;/* P 指向新的根结点*/
};
void Search::L_Rotate(BiTree *P)
{
	BiTree R;
	R=(*P)->rchild;/* R 指向P的右子树根结点*/
	(*P)->rchild=R- >lchild; /* R的左子树挂接为P的右子树*/
	R->Ichild=(*P);
	*P=R;/* P 指向新的根结点*/
};
void Search::LeftBalance(BiTree *T)
{
/*对以指针T所指结点为根的二叉树作左平衡旋转处理*/
/*本算法结束时， 指针T指向新的根结点*/
			BiTree L,Lr;
			L=(T)->lchild;/* L 指向T的左子树根结点*/
			switch(L->bf)
			{/*检查T的左子树的平衡度，并作相应平衡处理*/
			caseLH:/*新结点插入在 T的左孩子的左子树上，要作单右旋处理*/
			(*T)->bf=L->bf=EH;
			R_ Rotate(T);
			break;
			case RH:/*新结点插入在 T的左孩子的右子树上，要作双旋处理*/
			Lr=L->rchild;/* Lr 指向T的左孩子的右子树根*/
			switch(Lr->bf)
			{/*修改T 及其左孩子的平衡因子*/
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
			L Rotate(&(T)->lchild);/*对T的左子树作左旋平衡处理*/
			R_ Rotate(T);/*对 T作右旋平衡处理*/
			}

};
void Search::RightBalance(BiTree *T)
{
			BiTree R,RI; .
			R=(*T)->rchild;/* R 指向T的右子树根结点*/
			switch(R->bf)
			{/* 检查T的右子树的平衡度，并作相应平衡处理*/
			case RH:/*新结点插入在 T的右孩子的右子树上，要作单左旋处理*/
			(T)->bf=R->bf=EH;
			L Rotate(T);
			break;
			case LH:/*新结点插入在 T的右孩子的左子树上，要作双旋处理*/
			Rl=R->lchild;/* RI 指向T的右孩子的左子树根*/
			switch(Rl->bf)
			{/* 修改T及其右孩子的平衡因子*/
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
			R_ Rotate(&(*T)->rchild);/*对 T的右子树作右旋平衡处理*/
			L_ Rotate(T);/*对T作左旋平衡处理*/

			}
};
void Search::InsertAVL(BiTree *T,int e,Status *taller)
{
/* 若在平衡的二叉排序树T中不存在和e有相同关键字的结点，则插入一个*/
/* 数据元素为e的新结点，并返回1，否则返回0。若因插入而使二叉排序树*/
/*失去平衡， 则作平衡旋转处理，布尔变量tllr反映T长高与否。*/
			if(!*T)
			{/* 插入新结点，树“长高”，置tllr为TRUE */
			*T=(BiTeealloc(sizeof(BiTNodel);
			(*T)->data=e; (*T)->/child=(*T)->rchild=NULL; (*T)->bf=EH;
			*taller=TRUE;
			}
			else
			{
			if (e==(*T)->data)
			{/*树中已存在和 e有相同关键字的结点则不再插入*/
			*taller=FALSE; return FALSE;
			}}

};

//B树
Result Search::SearchBTree(BTree T, int K)
{
/*在m阶B树T上查找关键字K， 返回结果(pt,tag)。 若查找成功，则特征值*/
/* tag=1, 指针pt所指结点中第i个关键字等于K;否则特征值tag=0，等于K的*/
/*关键字应插入在指针 Pt所指结点中第i和第i+1个关键字之间。*/
			Result SearchBTree(BTree T, int K)
			BTree p=T,q=NULL;/*初始化， p指向待查结点，q 指向p的双亲*/
			Status found=FALSE;
			int i=0; .
			Result r;
			while(p&&!found)
			i=Search(p,K);/* p->nodelij].key≤K<p->node[i+1].key */
			if(i>0&p->nodel[j.ke==K)/*找到待查关键字 */
			{found=TRUE;
			else
			{
			q=p;
			p=p->node[].ptr;
			}
}
			r.i=i;
			if(found)/*查找成功*/
			{r.pt=p;
			r.tag=1;}
			else/*查找不成功， 返回K的插入位置信息*/
			{r.pt=q;
			r.tag=0;}
			return r;


};
void Search::Insert(BTree *q,int i,int key,BTree ap)
{/*将r->key、 r和ap分别插入到q->key/[i+1]、q->recptr[i+1]和 q->ptr[+1]中*/
			int j;
			for(j=(*)->keynum;)ij-)/*空出(*)->node[i+1] */
			{(*q)->node[i+1]=(*q)->node[j];
			(*q)->nodel[i+1].key=key; .
			(*q)->nodel[i+1].ptr=ap;
			(*q)->node[i+1].recptr=key;
			(*q)->keynum++;
			}
};
void Search::split(BTree *q,BTree *ap)
{/*将结点q分裂成两个结点，前一半保留，后一半移入新生结点ap*/
			void split(BTree *q,BTree *ap)
			int i,s=(m+1)/2;
			*ap=8Tel)alloc(sizeof(BNode)):/*生成新结点 ap */
			(*ap)>node([)]ptr=(*q)->nodefsl.ptr;/*后一 半移入 ap */
			for(i=s+1;i<=m;i++)
			(* ap)->node[i-s]=(*q)->node[i];
			if(*ap)->node[-sJ.ptr)
			(*p)->node[i-sJ.ptr->parent=*ap;
			(*ap)->keynum=m-s;
			(*ap)->parent=(*q)->parent;
			(*q)->keynum=s-1;/* q 的前一半保留，修改keynum */


};
void Search::NewRoot(BTree *T,int key,BTree ap)
{/*生成含信息(T,rap)的新的根结点&T,原T和ap为子树指针*/
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
{/* 在m阶B树T上结点*q的key[]与key[i+1]之间插入关键字K的指针r。若引起*/
/* 结点过大，则沿双亲链进行必要的结点分裂调整,使T仍是m阶B树。 */

			BTree ap=NULL;
			Status finished=FALSE;
			ints; 
			int rx;
			rx=key;
			while(q&& !finished)
			Insert(&q,nx,ap); /*将r->key、r和ap分别插入到q->key[i+1]、q->recptr(i+1]和
			g->ptr[i+1]中*/
			if(q->keynum<m)
			finished=TRUE;/*插入完成 */
			else
			{/*分裂结点*q*/ 
			s=(m+1)/2;
			rx=q->node[s].recptr;
			split(&q,&ap); /*将q-><eylst1.m.),->ptrs..m]和q->recptr5+1..m]移入新结点 *ap */
			q=q->parent;
			if(q)
			i=Search(q,key);/*在双亲结 点*q中查找rx->key的插入位置*/
			}
			if(lfinished)/* T 是空树(参数q初值为NULL)或根结点已分裂为结点*q和*ap */
			NewRoot(T,rx,ap); /*生成含 信息(,rx,ap)的新的根结点灯，原T和ap为子树指针
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
			printf("\n请输入待查找记录的关键字: ");
			scanf("%d",&i);
			s=SearchBTree(T,i);
			if(s.tag)
				priftf("(%d)",(s.pt)->node[s.i].key);/*prit(*(s.pt),s.i);priftf("(%d)",c.nodelij.key);*/
			else
			printf("没找到");
			printf("\n"); .
			return 0; 


};
//哈希散列表
void Search::InitHashTable(HashTable *H)
{/*初始化散列表*/

	int i;
	m=HASHSIZE;
	H->count=m;
	H->elem=(int *)malloc(m*sizeofint));
	for(i=;k<m;++)
		H->elem[)=NULLKEY;
	return OK;

};
void Search::Hash(int key)
{/*散列函数*/
	return key% m;/*除留余数法*/
};
void Search::InsertHash(HashTable *H,int key)
{/*插入关键字进散列表*/
	int addr = Hash(key); /*求散列地址*/
	while (H->elem[addr] != NULLKEY)/*如果不为空，则冲突*/
	{addr = (addr+1) % m; /*开放定址法的线性探测*/
	}
	H->elem[addr] = key;/*直到有空位后插入关键字*/
};
void Search::SearchHash(HashTable H,int key,int *addr)
{
	Status SearchHash(HashTable H,int key,int *addr)
	*addr = Hash(key); /* 求散列地址*/
	while(H.elem[*addr] != key)/*如果不为空，则冲突*/
		*addr = (*addr+1) % m; /*开放定址法的线性探测*/
	if (H.elem[*addr] = NULLKEY II *addr == Hash(key) /*如果循环回到原点*/
		return UNSUCCESS;/*则说明关键字不存在*/
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
		printf("查找%d的地址为: %d \n",key.p);
	else
		print("查找%d失败。\n" ,key);
	for(i=0;i<m;++)
	{
		key=arr[i];
		SearchHash(H,key,&p);
		printf("查找%d的地址为: %d \n",key.p);
	}
	return 0;
}: