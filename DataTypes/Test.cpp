#pragma once
#include <iostream>
using namespace std;
//#include"List.h"
#include "Search.h"
#include "Tree.h"
#include "Cstring.h"
#include "Graph.h"
#include "Sort.h"
//#include "thread.h"

void main_cstring(void)
{
	

	Cstring str,T;
	fun<int> func(12);
	cin >>str;
	cin >> func.data;
	cin >> T;
	int a[2];
	a[0] = 12;
	cout<< str.Index(str,T,1)<<func.data<<endl;
	str.get_next("iyfyf",a);
	system("pause");
	return;
};
void main_tree(void)
{

	TTree t;
	TTree::BiTree T=NULL;
	t.PreOrderTraverse(T);

	cout << t.Link <<"   ";

	system("pause");
	return;
};

/*void main_graph(void)
{
	
	MGraph G;

	G.CreateMGraph();

	G.CreateALGraph();

	system("pause");
	return;
};*/

void main_Sort(void)
{
	Sort G;

	int i;
	int N = 90;
	// int d[N]={9,1,5,8,3,7,4,6,2}; 
	int d[90]={50,10,90,30,70,40,80,60,20};
	// int d[N]={9,8,7,6,5,4,3,2,1}; 
	Sort::SqList l0,l1,l2,l3,l4,l5,l6,l7,l8,l9,l10;
	for(i=0;i<N;i++)
		l0.r[i+1]=d[i];
	l0.length = N;

	l1=l2=l3=l4=l5=l6=l7=l8=l9=l10=l0;

	printf("ÅÅÐòÇ°:\n");
	cout<<l0.r[0]<<endl;
	printf("³õ¼¶Ã°ÅÝÅÅÐò:\n");
	G.BubbleSort0(&l0);
	cout<<(l0.r)<<endl;
	printf("Ã°ÅÝÅÅÐò:\n");
	G.BubbleSort1(&l1);
	cout<<(l1.r)<<endl;
	printf("¸Ä½øÃ°ÅÝÅÅÐò:\n");
	G.BubbleSort2(&l2);
	cout<<(l2.r)<<endl;
	printf("Ñ¡ÔñÅÅÐò:\n");
	G.SelectSort(&l3);
	cout<<(l3.r)<<endl;
	printf("Ö±½Ó²åÈëÅÅÐò:\n");
	G.InsertSort(&l4);
	cout<<(l4.r)<<endl;
	printf("Ï£¶ûÅÅÐò:\n");
	G.ShellSort(&l5);
	cout<<(l5.r)<<endl;
	printf("¶ÑÅÅÐò:\n");
	G.HeapSort(&l6);
	cout<<(l6.r)<<endl;
	printf("¹é²¢ÅÅÐò(µÝ¹é) :\n"); 
	G.MergeSort1(&l7);
	cout<<(l7.r)<<endl;
	printf("¹é²¢ÅÅÐò(·ÇµÝ¹é) :\n");
	G.MergeSort2(&l8);
	cout<<(l8.r)<<endl;
	printf("¿ìËÙÅÅÐò:\n");
	G.QuickSort(&l9,1,l9.length);
	cout<<(l9.r)<<endl;
	printf("¸Ä½ø¿ìËÙÅÅÐò:\n");
	G.QuickSort1(&l10);
	cout<<(l10.r)<<endl;
	
};

/*int thread() 
{
	void foo() 
	{
  // do stuff...
	for (int i = 0;i<30;i++)
		cout<<"A "<<i<<endl;
	}

	void bar(int x)
	{
  // do stuff...
	for (int i = 0;i<30;i++)
		cout<<"B "<<i<<endl;
	}

	thread first (foo);     // spawn new thread that calls foo()
	thread second (bar,0);  // spawn new thread that calls bar(0)

	cout << "main, foo and bar now execute concurrently...\n";

	// synchronize threads:
	first.join();                // pauses until first finishes
	second.join();               // pauses until second finishes

	cout << "foo and bar completed.\n";

	return 0;
};*/
void main_graph(void)
{
	GraphUsage *MG;
	int *p, *d; 
	M_Graph::MGraph temp = MG->DefaultGraphV();
	M_Graph::GraphAdjList tempList = MG->DefaultGraphT(temp);

	MG->MiniSpanTree_Prim(temp);

	MG->MiniSpanTree_Kruskal(temp);

	MG->ShortestPath_ Floyd(temp,&P,&D);

	MG->ShortestPath_Djkstra(temp,0,p,d);
	{
		printf("×î¶ÌÂ·¾¶µ¹ÐòÈçÏÂ:\n");
		for(i=1;i<G.numVertexes;++)
			printf("v%d - v%d : ",v0,i);
		j=i;
		while(p[ij!=0)
		{
			printf("%d ",p[i]);
			j=p[];
		}
		printf("\n");
		};

		MG->TopologicalSort(tempList);

		MG->CriticalPath(tempList);

	};




	system("pause");
	return;
};
void main(void)
{
	main_graph();
	system("pause");
	return;
};