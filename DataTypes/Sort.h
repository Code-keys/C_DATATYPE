#ifndef MAXSIZE 
#define MAXSIZE 10000 /* ����Ҫ��������������ֵ���ɸ�����Ҫ�޸�*/
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
	Sort()  /*Ĭ�Ϲ��캯��\			���ĳ�����캯����������ʽ���������������Ĳ������������㲻���ṩ��ʽĬ�Ϲ��캯�������Ҳ������������¶��󲻴�����������*/	
	{
		//*_MAXSIZE = 1000;
		cout<<"ok";
	}

	void _test() //��Ԫ���� ���ڶ��� ʵ���ⲿ������Modify������
	{
		/*����������*/
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
		int r[MAXSIZE+1]; /* ���ڴ洢Ҫ�������飬r[0]�� ���ڱ�����ʱ����*/
		int length;
	/* ���ڼ�¼˳���ĳ���*/
	}SqList;	

public:
	void swap(SqList *L,int i,int j)throw();
	void BubbleSort0(SqList *L);  /*��˳���L����������(ð�����������) */
	void BubbleSort1(SqList *L);  /*ð������*/
	void BubbleSort2(SqList *L);  /*�Ľ�ð���㷨*/

	void SelectSort(SqList *L); /*��˳���L����ѡ������*/
	void InsertSort(SqList *L); /*��˳���L��ֱ�Ӳ�������*/
	void ShellSort(SqList *L);	/*��˳���L��ϣ������*/

	void HeapAdjust(SqList *L,int s,int m);
	void HeapSort(SqList *L);   /*��������*/

	
	void Merge(int SR[],int TR[],int i,int m,int n);/*�������Si..m]��SR([m+1..n]�鲢Ϊ�����TRi.n] */
	void MSort(int SR[],int TR1[],int s, int t);
	void MergeSort1(SqList *L);
	void MergePass(int SR[],int TR[],int s,int n);
	void MergeSort2(SqList *L);

	int Partition(SqList *L,int low,int high);
	void QSort(SqList *L,int low,int high);
	void QuickSort(SqList *L,int low,int high);	/*��˳���L����������*/	
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
/*����L������r���±�Ϊi��j��ֵ*/
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
				swap(L,i,j);/*����L->r[i]��L->r[]��ֵ*/
			}
		}
};
void Sort::BubbleSort1(SqList *L)
{
	int i,j;
	for(i=1;i<L->length;i++)
	{
		for(j=L->length-1;j>=i;j--) /* ע��j�ǴӺ���ǰѭ��*/
		{
			if(L->r[j]>L->r[j+1])/*��ǰ�ߴ��ں���(ע����������һ�㷨�Ĳ���) */
			{
			swap(L,j,j+1);/*����L->r[i]��L->r[j+1]��ֵ*/
			}
		}
	}
};
void Sort::BubbleSort2(SqList *L)
{
	int i,j;
	bool flag = TRUE;
	/* flag������Ϊ���*/
	for(i=1;i< L->length && flag;i++)/*��flagΪtrue˵���й����ݽ���������ֹͣѭ��*/
	{
		flag =FALSE;
		/*��ʼΪFalse */
		for(j=L->length-1;j>=i;j--)
		{
			if(L->r[j]>L->r[j+1])
			{
				swap(L,j,j+1);/*����L->r[j]��L->r[j+1]��ֵ*/
				flag = TRUE;/*��������ݽ�������flagΪtrue */
			}
		}
	}

};
void Sort::SelectSort(SqList *L)
{
	int i,j,min;
	for(i=1;i< L->length;i++)
	{
		min=i;/*����ǰ�±궨��Ϊ��Сֵ�±�*/
		for (j= i+1;j<=L->length;j++)/*ѭ��֮�������*/
		{
			if (L->r[min]>L->r[j]) /* �����С�ڵ�ǰ��Сֵ�Ĺؼ���*/
				min=j;/*���˹ؼ��ֵ��±긳ֵ��min */
		}
		if(i!=min)/*��min������i, ˵���ҵ���Сֵ������*/
			swap(L,i,min);/*����L->r[]��L->r[min]��ֵ*/
	}
};

void Sort::InsertSort(SqList *L)
{
	int i,j;
	for(i=2;i<=L->length;i++)
	{
		if (L->r[i]<L->r[i-1]) /*�轫L->r[]���������ӱ�*/
		{
			L->r[0]=L->r[i];/*�����ڱ�*/
			for(j=i-1;L->r[j]> L->r[0];j--)
				L->r[j+1] = L->r[i];/*��¼����*/
			L->r[j+1]=L->r[0];/*���뵽��ȷλ��*/
		}
	}
};
void Sort::ShellSort(SqList *L)
{

	int i,j,k=0;
	int increment=L->length;
	do
	{
		increment=increment/3+1;/*��������*/
		for(i=increment+1;i<=L->length;i++)
		{
			if (L->r[i]<L->r[i-increment])/*�轫 L->r[]�������������ӱ�*/
			{
				L->r[0]=L->r[i];/*�ݴ��� L->r[0] */
				for(j=i-increment;j>0 && L->r[0]<L->r[j];j-=increment)
				{L->r[j+increment]=L->r[j];};/*��¼���ƣ� ���Ҳ���λ��*/
				L->r[j+increment]=L->r[0];/*����*/
			}
		printf("��%d ��������:",++k); 
		cout<<(L->r); 
		}
	}
	while(increment>1);
};
/*��***********************/	
/*��֪Ls>r5s.m]�м�¼�Ĺؼ��ֳ�L->r[s]֮�������ѵĶ��壬*/
/*����������L->r[s]�Ĺؼ���,ʹL-rs..m]��Ϊһ���󶥶�*/
void Sort::HeapAdjust(SqList *L,int s,int m)
{
	int temp,j;
	temp=L->r[s];
	for(j=2*s;j<=m;j*=2)/*�عؼ��ֽϴ�ĺ��ӽ������ɸѡ*/
	{
		if(j < m && L->r[j] < L->r[j+1])
			++j;/* jΪ�ؼ����нϴ�ļ�¼���±�*/
		if(temp >= L->r[j])
			break; /* rcӦ������λ��s��*/
		L->r[s]=L->r[j];
		s=j;
	}
	L->r[s]=temp;/*����*/
};
void Sort::HeapSort(SqList *L)
{
	/*��˳���L ���ж�����*/
	int i;
	for(i=L->length/2;i>0;i--)/*��L�е�r������-һ�������*/
			HeapAdjust(L,i,L->length);
	for(i=L->length;i>1;i--)
	{
			swap(L,1,i); /*���Ѷ���¼�͵�ǰδ�����������е����-һ����¼����*/
			HeapAdjust(L,1,i-1);/*��L->r1..-1]���µ���Ϊ�����*/
	}
};
void Sort::Merge(int SR[],int TR[],int i,int m,int n)/*�������Si..m]��SR([m+1..n]�鲢Ϊ�����TRi.n] */
{
	int j,k,l;
	for(j=m+1,k=i;i<=m && j<=n;k++) /*��SR�м�¼��С����ز���TR */
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
		/*��ʣ���Si.m]���Ƶ�TR */
	}
	if(j<=n)
	{
		for(l=0;l<=n-j;l++)
			TR[k+l]=SR[j+l];
		/*��ʣ���Sij.n]���Ƶ�TR */
	};
};
/*�ݹ鷨*/
	/*��SR[s..]�鲢����ΪTR15..t] */
void Sort::MSort(int SR[],int TR1[],int s, int t)
{
	int m;
	int TR2[MAXSIZE+1];
	if(s==t)
		TR1[s]=SR[s];
	else
	{
		m=(s+t)/2;
		/*��S[.]ƽ��ΪSR[s..m]��SR[m+1..t] */
		MSort(SR,TR2,s,m);
		/*�ݹ�ؽ�SR[s..m]�鲢Ϊ�����TR21s..m] */
		MSort(SR,TR2,m+1,t); /* �ݹ�ؽ�SRl[mt1.t�鲢Ϊ�����TR2[m+1.t] */
		Merge(TR2,TR1,s,m,t); /* ��TR2s..m]��TR21mt1..t]�鲢��TR15s.] */
	}
};

void Sort::MergeSort1(SqList *L)
{
	/*��˳���L���鲢����*/
	MSort(L->r,L->r,1,L->length);

};
/*�ǵݹ鷨*/
/*��SR[]�����ڳ���Ϊs�������������鲢��TR[ */
void Sort::MergePass(int SR[],int TR[],int s,int n)
{

	int i=1;
	int j ;
	while(i <= n-2*s+1)
	{/*�����鲢*/
		Merge(SR,TR,i,i+s-1,i+2*s-1);
		i = i+2*s;
	}
	if(i<n-s+1)/* �鲢�����������*/
		Merge(SR,TR,i,i+s-1,n);
	else/*�����ֻʣ�µ���������*/
		for(j=i;j <= n;j++)
			TR[j] = SR[i];	
};
void Sort::MergeSort2(SqList *L)
{
	/*��˳���L���鲢�ǵݹ�����*/

	int* TR = (int*)malloc(L->length * sizeof(int));/*�������ռ�*/
	int k = 1;
	while( k < L->length)
	{
		MergePass(L->r,TR,k,L->length);
		k=2*k;/*�����г��ȼӱ�*/
		MergePass(TR,L->r,k,L->length);
		k=2*k;/*�����г��ȼӱ�*/
	}
};


/*����*********************** */
/*����˳���L���ӱ�ļ�¼��ʹ�����¼��λ��������������λ��*/
/*��ʱ����֮ǰ(��)�ļ�¼������(С������*/
int Sort::Partition(SqList *L,int low,int high)
{
	int pivotkey;
	pivotkey = L->r[low];/*���ӱ�ĵ�һ����¼�������¼ */
	while(low<high)/*�ӱ�����˽� ������м�ɨ��*/
	{
		while(low<high && L->r[high]>=pivotkey)
			high--;
		swap(L,low,high);/* ���������¼С�ļ�¼�������Ͷ�*/
		while(low<high && L->r[low]<=pivotkey)
			low++;
		swap(L,low,high);/*���������¼��ļ�¼�������߶�*/
	}
	return low; /*������������λ��*/
}
/*��˳���L�е�������L->r[low.high]����������*/
void Sort::QSort(SqList *L,int low,int high)
{
	int pivot;
	if(low<high)
	{
		pivot = Partition(L,low,high);/*��L->r[|low.high]һ��Ϊ�����������ֵpivot */
		QSort(L,low,pivot-1);/*�Ե��ӱ�ݹ����� */
		QSort(L,pivot+1,high);/*�Ը��ӱ�ݹ����� */
	}
};

void Sort::QuickSort(SqList *L,int low,int high)
{	
	QSort(L,1,L->length);
};

/*���������Ż��㷨*/
int Sort::Partition1(SqList *L,int low,int high)
	{
		int pivotkey;
		int m = low + (high - low)/2;/*���������м��Ԫ�ص��±�*/

		if (L->r[low]>L->r[high])
			swap(L,low,high); /* ����������Ҷ����ݣ���֤��˽�С*/
		if (L->r[m]>L->r[high])
			swap(L,high,m);/*�����м����Ҷ����ݣ���֤�м��С*/
		if (L->r[m]>L->r[low])
			swap(L,m,low);/*�����м���������ݣ���֤��˽�С*/

		pivotkey =L->r[low];/*���ӱ�ĵ�һһ����¼�������¼*/
		L->r[0]=pivotkey; /* ������ؼ��ֱ��ݵ�L->r[0] */
		while(low<high)/*�ӱ���� �˽�������м�ɨ��*/
		{	while(low<high && L->r[high]>=pivotkey)
				high--;
			L->r[low]=L->r[high];
			while(low<high && L->r[low]<=pivotkey)
				low++;
			L->r[high]=L->r[low];
		}
		L->r[low]=L->r[0];
		return low; /*������������λ��*/
	}
void Sort::QSort1(SqList *L,int low,int high)
	{
		int pivot;
		if( (high-low) > MAX_LENGTH_INSERT_SORT )
			while(low<high)
			{
				pivot = Partition1(L,low,high);/*�� L->r[low.high]��Ϊ���� �������ֵpivot */
				QSort1(L,low,pivot-1);
				/* �Ե��ӱ�ݹ����� */
				/* QSort(L,pivot+1,high);*/
				/* �Ը��ӱ�ݹ����� */
				low = pivot+1; /* β�ݹ�*/
			}
		else
		InsertSort(L);
	};

/*��˳���L����������*/
void Sort::QuickSort1(SqList *L){QSort1(L,1,L->length);};
