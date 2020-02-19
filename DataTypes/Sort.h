#ifndef MAXSIZE 
#define MAXSIZE 10000 /* 用于要排序数组个数最大值，可根据需要修改*/
#endif
#define  MAX_LENGTH_INSERT_SORT 7
#include"time.h"
#include<iostream>
using namespace std;

class Modify
{
public:
	Modify();
	~Modify();
};
class Sort
{
public:	
	Sort()  /*默认构造函数\			类的某个构造函数接受了显式声明的任意数量的参数，编译器便不再提供隐式默认构造函数，并且不再允许该类的新对象不带参数的声明*/	
	{
		//*_MAXSIZE = 1000;
		cout<<"ok";
	}

	void _test() //友元函数 类内定义 实属外部函数（Modify函数）
	{
		/*大数据排序*/
		srand(int(time(0)));
		int Max=10000;
		int d[10000];
		int i;
		SqList l0;
		for(i=0;i<Max;i++)
			d[i]=rand()%Max+1;
		for(i=0;i< Max;i++)
			l0.r[i+1]=d[i];
		l0.length=Max;
		MergeSort1(&l0);
	};
	typedef struct SqList
	{
		int r[MAXSIZE+1]; /* 用于存储要排序数组，r[0]用 作哨兵或临时变量*/
		int length;
	/* 用于记录顺序表的长度*/
	}SqList;	

public:
	void swap(SqList *L,int i,int j)throw();
	void BubbleSort0(SqList *L);  /*对顺序表L作交换排序(冒泡排序初级版) */
	void BubbleSort1(SqList *L);  /*冒泡排序*/
	void BubbleSort2(SqList *L);  /*改进冒泡算法*/

	void SelectSort(SqList *L); /*对顺序表L作简单选择排序*/
	void InsertSort(SqList *L); /*对顺序表L作直接插入排序*/
	void ShellSort(SqList *L);	/*对顺序表L作希尔排序*/

	void HeapAdjust(SqList *L,int s,int m);
	void HeapSort(SqList *L);   /*作堆排序*/

	
	void Merge(int SR[],int TR[],int i,int m,int n);/*将有序的Si..m]和SR([m+1..n]归并为有序的TRi.n] */
	void MSort(int SR[],int TR1[],int s, int t);
	void MergeSort1(SqList *L);
	void MergePass(int SR[],int TR[],int s,int n);
	void MergeSort2(SqList *L);

	int Partition(SqList *L,int low,int high);
	void QSort(SqList *L,int low,int high);
	void QuickSort(SqList *L,int low,int high);	/*对顺序表L作快速排序*/	
	int Partition1(SqList *L,int low,int high);
	void QSort1(SqList *L,int low,int high);
	void QuickSort1(SqList *L);


	~Sort(void)
	{
		delete _MAXSIZE;
	}

protected:
	int *_MAXSIZE;	

private:
};
/*交换L中数组r的下标为i和j的值*/
void Sort::swap(SqList *L,int i,int j)
{
	int temp=L->r[i];
	L->r[i]=L->r[j];
	L->r[i]=temp;
};
void Sort::BubbleSort0(SqList *L)
{
	
	int i,j;
		for(i=1;i<L->length;i++)
		{
			for(j=i+1;j<=L->length;j++)
			{
				if(L->r[i]>L->r[i])
				swap(L,i,j);/*交换L->r[i]与L->r[]的值*/
			}
		}
};
void Sort::BubbleSort1(SqList *L)
{
	int i,j;
	for(i=1;i<L->length;i++)
	{
		for(j=L->length-1;j>=i;j--) /* 注意j是从后往前循环*/
		{
			if(L->r[j]>L->r[j+1])/*若前者大于后者(注意这里与上一算法的差异) */
			{
			swap(L,j,j+1);/*交换L->r[i]与L->r[j+1]的值*/
			}
		}
	}
};
void Sort::BubbleSort2(SqList *L)
{
	int i,j;
	bool flag = TRUE;
	/* flag用来作为标记*/
	for(i=1;i< L->length && flag;i++)/*若flag为true说明有过数据交换，否则停止循环*/
	{
		flag =FALSE;
		/*初始为False */
		for(j=L->length-1;j>=i;j--)
		{
			if(L->r[j]>L->r[j+1])
			{
				swap(L,j,j+1);/*交换L->r[j]与L->r[j+1]的值*/
				flag = TRUE;/*如果有数据交换，则flag为true */
			}
		}
	}

};
void Sort::SelectSort(SqList *L)
{
	int i,j,min;
	for(i=1;i< L->length;i++)
	{
		min=i;/*将当前下标定义为最小值下标*/
		for (j= i+1;j<=L->length;j++)/*循环之后的数据*/
		{
			if (L->r[min]>L->r[j]) /* 如果有小于当前最小值的关键字*/
				min=j;/*将此关键字的下标赋值给min */
		}
		if(i!=min)/*若min不等于i, 说明找到最小值，交换*/
			swap(L,i,min);/*交换L->r[]与L->r[min]的值*/
	}
};

void Sort::InsertSort(SqList *L)
{
	int i,j;
	for(i=2;i<=L->length;i++)
	{
		if (L->r[i]<L->r[i-1]) /*需将L->r[]插入有序子表*/
		{
			L->r[0]=L->r[i];/*设置哨兵*/
			for(j=i-1;L->r[j]> L->r[0];j--)
				L->r[j+1] = L->r[i];/*记录后移*/
			L->r[j+1]=L->r[0];/*插入到正确位置*/
		}
	}
};
void Sort::ShellSort(SqList *L)
{

	int i,j,k=0;
	int increment=L->length;
	do
	{
		increment=increment/3+1;/*增量序列*/
		for(i=increment+1;i<=L->length;i++)
		{
			if (L->r[i]<L->r[i-increment])/*需将 L->r[]插入有序增量子表*/
			{
				L->r[0]=L->r[i];/*暂存在 L->r[0] */
				for(j=i-increment;j>0 && L->r[0]<L->r[j];j-=increment)
				{L->r[j+increment]=L->r[j];};/*记录后移， 查找插入位置*/
				L->r[j+increment]=L->r[0];/*插入*/
			}
		printf("第%d 趟排序结果:",++k); 
		cout<<(L->r); 
		}
	}
	while(increment>1);
};
/*序***********************/	
/*已知Ls>r5s.m]中记录的关键字除L->r[s]之外均满足堆的定义，*/
/*本函数调整L->r[s]的关键字,使L-rs..m]成为一个大顶堆*/
void Sort::HeapAdjust(SqList *L,int s,int m)
{
	int temp,j;
	temp=L->r[s];
	for(j=2*s;j<=m;j*=2)/*沿关键字较大的孩子结点向下筛选*/
	{
		if(j < m && L->r[j] < L->r[j+1])
			++j;/* j为关键字中较大的记录的下标*/
		if(temp >= L->r[j])
			break; /* rc应插入在位置s上*/
		L->r[s]=L->r[j];
		s=j;
	}
	L->r[s]=temp;/*插入*/
};
void Sort::HeapSort(SqList *L)
{
	/*对顺序表L 进行堆排序*/
	int i;
	for(i=L->length/2;i>0;i--)/*把L中的r构建成-一个大根堆*/
			HeapAdjust(L,i,L->length);
	for(i=L->length;i>1;i--)
	{
			swap(L,1,i); /*将堆顶记录和当前未经排序子序列的最后-一个记录交换*/
			HeapAdjust(L,1,i-1);/*将L->r1..-1]重新调整为大根堆*/
	}
};
void Sort::Merge(int SR[],int TR[],int i,int m,int n)/*将有序的Si..m]和SR([m+1..n]归并为有序的TRi.n] */
{
	int j,k,l;
	for(j=m+1,k=i;i<=m && j<=n;k++) /*将SR中记录由小到大地并入TR */
	{
		if (SR[i]<SR[j])
			TR[k]=SR[i++];
		else
		TR[k]=SR[j++];
	}
	if(i<=m)
	{
		for(l=0;l<=m;l++)
			TR[k+l]=SR[i+1];
		/*将剩余的Si.m]复制到TR */
	}
	if(j<=n)
	{
		for(l=0;l<=n-j;l++)
			TR[k+l]=SR[j+l];
		/*将剩余的Sij.n]复制到TR */
	};
};
/*递归法*/
	/*将SR[s..]归并排序为TR15..t] */
void Sort::MSort(int SR[],int TR1[],int s, int t)
{
	int m;
	int TR2[MAXSIZE+1];
	if(s==t)
		TR1[s]=SR[s];
	else
	{
		m=(s+t)/2;
		/*将S[.]平分为SR[s..m]和SR[m+1..t] */
		MSort(SR,TR2,s,m);
		/*递归地将SR[s..m]归并为有序的TR21s..m] */
		MSort(SR,TR2,m+1,t); /* 递归地将SRl[mt1.t归并为有序的TR2[m+1.t] */
		Merge(TR2,TR1,s,m,t); /* 将TR2s..m]和TR21mt1..t]归并到TR15s.] */
	}
};

void Sort::MergeSort1(SqList *L)
{
	/*对顺序表L作归并排序*/
	MSort(L->r,L->r,1,L->length);

};
/*非递归法*/
/*将SR[]中相邻长度为s的子序列两两归并到TR[ */
void Sort::MergePass(int SR[],int TR[],int s,int n)
{

	int i=1;
	int j ;
	while(i <= n-2*s+1)
	{/*两两归并*/
		Merge(SR,TR,i,i+s-1,i+2*s-1);
		i = i+2*s;
	}
	if(i<n-s+1)/* 归并最后两个序列*/
		Merge(SR,TR,i,i+s-1,n);
	else/*若最后只剩下单个子序列*/
		for(j=i;j <= n;j++)
			TR[j] = SR[i];	
};
void Sort::MergeSort2(SqList *L)
{
	/*对顺序表L作归并非递归排序*/

	int* TR = (int*)malloc(L->length * sizeof(int));/*申请额外空间*/
	int k = 1;
	while( k < L->length)
	{
		MergePass(L->r,TR,k,L->length);
		k=2*k;/*子序列长度加倍*/
		MergePass(TR,L->r,k,L->length);
		k=2*k;/*子序列长度加倍*/
	}
};


/*速排*********************** */
/*交换顺序表L中子表的记录，使枢轴记录到位，并返回其所在位置*/
/*此时在它之前(后)的记录均不大(小于它。*/
int Sort::Partition(SqList *L,int low,int high)
{
	int pivotkey;
	pivotkey = L->r[low];/*用子表的第一个记录作枢轴记录 */
	while(low<high)/*从表的两端交 替地向中间扫描*/
	{
		while(low<high && L->r[high]>=pivotkey)
			high--;
		swap(L,low,high);/* 将比枢轴记录小的记录交换到低端*/
		while(low<high && L->r[low]<=pivotkey)
			low++;
		swap(L,low,high);/*将比枢轴记录大的记录交换到高端*/
	}
	return low; /*返回枢轴所在位置*/
}
/*对顺序表L中的子序列L->r[low.high]作快速排序*/
void Sort::QSort(SqList *L,int low,int high)
{
	int pivot;
	if(low<high)
	{
		pivot = Partition(L,low,high);/*将L->r[|low.high]一分为二，算出枢轴值pivot */
		QSort(L,low,pivot-1);/*对低子表递归排序 */
		QSort(L,pivot+1,high);/*对高子表递归排序 */
	}
};

void Sort::QuickSort(SqList *L,int low,int high)
{	
	QSort(L,1,L->length);
};

/*快速排序优化算法*/
int Sort::Partition1(SqList *L,int low,int high)
	{
		int pivotkey;
		int m = low + (high - low)/2;/*计算数组中间的元素的下标*/

		if (L->r[low]>L->r[high])
			swap(L,low,high); /* 交换左端与右端数据，保证左端较小*/
		if (L->r[m]>L->r[high])
			swap(L,high,m);/*交换中间与右端数据，保证中间较小*/
		if (L->r[m]>L->r[low])
			swap(L,m,low);/*交换中间与左端数据，保证左端较小*/

		pivotkey =L->r[low];/*用子表的第一一个记录作枢轴记录*/
		L->r[0]=pivotkey; /* 将枢轴关键字备份到L->r[0] */
		while(low<high)/*从表的两 端交替地向中间扫描*/
		{	while(low<high && L->r[high]>=pivotkey)
				high--;
			L->r[low]=L->r[high];
			while(low<high && L->r[low]<=pivotkey)
				low++;
			L->r[high]=L->r[low];
		}
		L->r[low]=L->r[0];
		return low; /*返回枢轴所在位置*/
	}
void Sort::QSort1(SqList *L,int low,int high)
	{
		int pivot;
		if( (high-low) > MAX_LENGTH_INSERT_SORT )
			while(low<high)
			{
				pivot = Partition1(L,low,high);/*将 L->r[low.high]分为二， 算出枢轴值pivot */
				QSort1(L,low,pivot-1);
				/* 对低子表递归排序 */
				/* QSort(L,pivot+1,high);*/
				/* 对高子表递归排序 */
				low = pivot+1; /* 尾递归*/
			}
		else
		InsertSort(L);
	};

/*对顺序表L作快速排序*/
void Sort::QuickSort1(SqList *L){QSort1(L,1,L->length);};
