#pragma once
#include"stdio.h"
#include"stdlib.h"
#include"io.h"
#include"time.h"
#include"math.h"
/*
本文详细列些来了两类图的相关定义与
				基本算法和高级使用算法，
				并用类的封装将其定义。
base operation（）：

	createGraph(*G,V,VR)
	DestoryGraph(*G)
	LocateVex(G,u)
	GetVex(G,v)
	PutVex(G,v,value)
	FirstAdjiVex(G,*v)
	NextAdjVex(G,v,*w)
	InsertVex(*G,v)
	DeleteVex(*G,v)  
	InsertArc(*G,v,w)
	DeleteArc(*G,v,w)
	DFSTraverse(G)ee
	HFSTraverse(G)

Advance operation（）：
	 Prim();//最小生成树
	 Kruskal();

	 Djkstra();//最短路径
	 Floyd();

	 TopologicalSort();//拓扑排序
	 CriticalPath());//关键路径

*/
//template<class GElemType>
#define	ERROR  0 
#define	OK  1
#define	TURE 1
#define	FALSE  0

#define MAXVEX  100
#define MAXSIZE 9 /*存储空间初始分配量*/
#define MAXEDGE 15
#define INFINITY  65535

typedef int GElemType;

class pre /*重写了之前的一些定义*/
{
public:
	/*用到的队列结构与************************* */
	/*循环队列的顺序存储结构*/
	typedef struct
	{
		int begin;
		int end;
		int weight;
	}Edge; /* 对边集数组Edge结构的定义*/

	typedef struct
	{
		int data[MAXSIZE];
		int front;
		/*头指针*/
		int rear; 
		/*尾指针，若队列不空，指向队列尾元素的下一个位置*/
	}Queue;

	/*初始化一个空队列Q*/
	bool InitQueue(Queue *Q)
	{
		Q->front=0;
		Q->rear=0;
		return OK;
	};
	/*若队列Q为空队列，则返回TRUE,否则返回FALSE */
	bool QueueEmpty(Queue Q)
	{
		if(Q.front==Q.rear) /*队列空的标志*/
			return TRUE;
		else 
			return FALSE;
	};
	/*若队列未满，则插入元素e为Q新的队尾元素*/
	bool EnQueue(Queue *Q,int e)
	{
		if( (Q->rear+1) % MAXSIZE == Q->front)/*队列满的判断*/
			return ERROR;
		Q->data[Q->rear]=e;
		/*将元素e赋值给队尾*/
		Q->rear=(Q->rear+1)%MAXSIZE;/* rear指针向后移- -位置， */
		/*若到最后则转到数组头部*/
		return OK;
	};
	/*若队列不空，则删除Q中队头元索，用e返回其值*/
	bool DeQueue(Queue *Q,int *e)
	{
		if (Q->front == Q->rear)
		/*队列空的判断*/
		return ERROR;
		*e=Q->data[Q->front];
		/*将队头元素赋值给e*/
		Q->front=(Q->front+1)%MAXSIZE; /* front指针向后移- -位置，*/
		/*若到最后则转到数组头部*/
		return OK;
	};


	
	void Swapn(Edge *edges,int i, int j)/*交换权值以及头和尾*/
	{
		int temp;
		temp = edges[i].begin;
		edges[i].begin = edges[j].begin;
		edges[j].begin = temp;

		temp = edges[i].end;
		edges[i].end = edges[j].end;
		edgesj].end = temp;

		temp = edges[i].weight;
		edges[i].weight = edges[j].weight;
		edges[j].weight = temp;
	};
	
	void sort(Edge edges[],MGraph *G)/*对权值进行排序*/
	{
		int i, j;
		for (i= 0; i< G->numEdges; i++)
		{	for(j=i+ 1;j< G->numEdges; j++)
			{	
				if (edges[i].weight > edgesj].weight)
					Swapn(edges, i, j);
			}
		}
		printf("权排序之后的为:\n");
		for (i= 0; i< G->numEdges; i++)
			printf("(%d, %d) %d\n", edges[i].begin, edges[i].end, edges[i].weight);
	};
	
	int Find(int * parent, int f)/*查找连线顶点的尾部下标*/
	{
		while ( parent[f]> 0)
		{f= parent[f];}
		return f;
	}


};
class M_Graph :public pre
{
private:
	typedef int Status; /* Status是函数的类型,其值是函数结果状态代码，如OK等*/
	typedef char VertexType;/*顶点类型应由用户定义*/
	typedef int EdgeType;/*边上的权值类型应由用户定义*/
	typedef int Boolean; /* Boolean是布尔类型,其值是TRUE或FALSE */
protected:
public:
	/*邻接矩阵*/
	typedef struct MGraph
	{
		VertexType vexs[MAXVEX];/*顶点表*/
		EdgeType arc[MAXVEX][MAXVEX];/*邻接矩阵，可看作边表*/
		int numVertexes, numEdges; /*图中当前的顶点数和边数*/
	}*MGraphptr;
	/*邻接表*/
	typedef struct EdgeNode/*边表结点*/
	{
		int adjvex; /* 邻接点域存储该顶点对应的下标*/
		EdgeType info;/*用于存储权值,对于非网图可以不需要*/
		struct EdgeNode *next;/*链域,指向下一个邻接点*/
	}EdgeNode;
	typedef struct VertexNode/*顶点表结点*/
	{
		int in;/*定点入度*/
		VertexType data;/*顶点域,存储顶点信息*/
		EdgeNode *firstedge;/*边表头指针*/
	}VertexNode, AdjList[MAXVEX];
	typedef struct graphAdjList 
	{
		AdjList adjList;
		int numNodes,numEdges; /*图中当前顶点数和边数*/
	}graphAdjList,*GraphAdjList;

	graphAdjList *G;
	Boolean visited[MAXVEX]; /*访问标志的数组*/

	

public:	
	bool _initial(){/*to do*/};

	/*邻接矩阵表示、建立无向网图*/
	virtual void CreateMGraph(MGraph *MG)
	{
		int i,j,k,w;
		printf("输入顶点数和边数:\n");
		scanf_s("%d,%d",&MG->numVertexes,&MG->numEdges);/*输入顶点数和边数*/
		for(i = 0;i < MG->numVertexes;i++)/*读入顶点信息,建立顶点表*/
			scanf_s(&MG->vexs[i]);
		for(i = 0;i < MG->numVertexes;i++)
			for(j= 0;j < MG->numVertexes;j++)
				MG->arc[i][j]=INFINITY; /* 邻接矩阵初始化*/
				for(k = 0;k < MG->numEdges;k++)/*读入numEdges条边，建立邻接矩阵*/
				{
					printf("输入边(i,vj)上的下标i，下标j和权w:\n");
					scanf_s("%d,%d,%d",&i,&j,&w); /*输入边(i,vj)上的权w*/
					MG->arc[i][j]=w;
					MG->arc[j][i]= MG->arc[i][j]; /*因为是无向图，矩阵对称*/
				};
	};	
	virtual MGraph DefaultGraphV(void);
	/*邻接矩阵深度和广度遍历DFS_ BFS */
	virtual void DFS();
	void DFSTraverse(GraphAdjList GL);
	void BFSTraverse(MGraph G);
.
	
	/*邻接表 -> 建立无向网图*/
	virtual void CreateALGraph()
	{
		int i,j,k;
		EdgeNode *e;
		printf("输入顶点数和边数:\n");
		scanf_s("%d,%d" ,&G->numNodes,&G->numEdges); /*输入顶点数和边数*/
		for(i = 0;i < G->numNodes;i++)/*读入顶点信息,建立顶点表*/
		{
			scanf_s(&G->adjList[i].data); /* 输入顶点信息*/
			G->adjList[i].firstedge=NULL; /* 将边表置为空表*/
		}
		for(k = 0;k < G->numEdges;k++)/*建立边表*/
		{
			printf("输入边(vi,vj).上的顶点序号:\n");
			scanf_s("%d,%d" ,&i,&j);/*输入边(i,vi)l 上的顶点序号*/
			e=(EdgeNode *)malloc(sizeof(EdgeNode)); /*向内存申请空间,生成边表结点*/
			e->adjvex=j;/*邻接序号为j*/
			
			e->next = G->adjList[i].firstedge; /* 将e的指针指向当前顶点上指向的结点*/
			G->adjList[i].firstedge = e; /* 将当前顶点的指针指向e*/
			e=(EdgeNode *)malloc(sizeof(EdgeNode)); /*向内存申请空间,生成边表结点*/
			e->adjvex = i;/*邻接序号为i*/
			
			e->next=G->adjList[j].firstedge; /* 将e的指针指向当前顶点上指向的结点*/
			G->adjList[j].firstedge=e; /* 将当前顶点的指针指向e*/
		}
	};
	GraphAdjList DefaultGraphT(MGraph G);

	/*邻接表深度和广度遍历DFS_ BFS */
	virtual void DFS1();
	void DFSTraverse(GraphAdjList GL);
	void BFST1raverse(MGraph G);
};

class GraphUsage:public M_Graph
{
public:

	void MiniSpanTree_Prim();//最小生成树
	void MiniSpanTree_Kruskal();

	typedef int Patharc[MAXVEX];/*用于存储最短路径下标的数组*/ .
	typedef int ShortPathTable[MAXVEX];/*用于存储到各点最短路径的权值和*/
	void ShortestPath_Djkstra(MGraph G,int v0,Patharc *P, ShortPathTable* D);//最短路径

	typedef int Patharc_[MAXVEX][MAXVEX];/*用于存储最短路径下标的数组*/ .
	typedef int ShortPathTable_[MAXVEX][MAXVEX];/*用于存储到各点最短路径的权值和*/
	void ShortestPath_Floyd(MGraph G, Patharc *p, ShortPathTable *D);

	void TopologicalSort(GraphAdjList GL);//拓扑排序
	void CriticalPath(GraphAdjList GL);//关键路径


};
M_Graph::MGraph M_Graph::DefaultGraphV(void)
{
	MGraph s;//MGraphptr s = (MGraphptr)malloc(sizeof(MGraph));/* MGraphptr s = (MGraph)malloc(sizeof(MGraphptr)); ->  */
	s.numEdges = 15;s.numVertexes = 9;
	for(int i = 0;i<=8;i++){s.vexs[i] = char(56+i);};
	for(int i = 0;i<=s.numVertexes;i++)
	{	for(int j = 0;j<=s.numVertexes;j++)
			{
				s.arc[i][j] = 0;
	}};

	s.arc[0][1] = 1;s.arc[0][5] = 1;
	s.arc[1][2] = 1;s.arc[1][8] = 1;s.arc[1][6] = 1;
	s.arc[2][3] = 1;s.arc[2][8] = 1;
	s.arc[3][4] = 1;s.arc[3][7] = 1;s.arc[3][6] = 1;s.arc[3][8] = 1;
	s.arc[6][7] = 1;s.arc[4][7] = 1;
	s.arc[5][6] = 1;
	s.arc[4][5] = 1;

	for(int i= 0; i< s.numVertexes; i++)
	{
		for(int j=i;j< s.numVertexes; j++)
		{
			s.arc[i][j] =s.arc[j][i];
		}
	};
	return s;
};
void M_Graph::DFS()
{
							/*邻接矩阵的深度优先递归算法*/
						void DFS(MGraph G, int i)
						int j; .
						visited[i] = TRUE;
						printf("%c ", G.vexs[);/*打印顶点，也可以其它操作*/
						for(j = 0; j < G.numVertexes; j++)
						if(G.arc[)[j] == 1 && !visited[j])
						DFS(G, j);/*对为访问的邻接顶点递归调用*/


};
void M_Graph::DFSTraverse()
{
							/*邻接矩阵的深度遍历操作*/
							void DFSTraverse(MGraph G)
							inti;
							for(i= 0; i< G.numVertexes; i++)
							visited[i] = FALSE; /*初始所有顶点状态都是未访问过状态*/
							for(i= 0; i < G.numVertexes; i++)
							if(visited[i) /*对未访问过的顶点调用DFS,若是连通图，只会执行一次*/ 
							DFS(G, i);

};
void M_Graph::BFSTraverse()
{
								/*邻接矩阵的广度遍历算法*/
							void BFSTraverse(MGraph G)
							inti, j;
							Queue Q;
							for(i = 0; i < G.numVertexes; i++)
							visited[i] = FALSE;
							InitQueue(&Q);
							/*初始化一辅助用的队列*/
							for(i = 0; i< G.numVertexes;i++) /* 对每-一个顶点做循环*/
							if (visited[i) /* 若是未访问过就处理*/
							visited[)=TRUE;
							/*设置当前顶点访问过*/
							printf("%c " G.vex5[);/*打印顶点，也可以其它操作*/
							EnQueue(&Q,i);
							/*将此顶点入队列*/
							while(!QueueEmpty(Q)) /*若当前队列不为空*/
							DeQueue(&Q,&i); /* 将队对元素出队列，赋值给i*/
							for(j=0;j<G.numVertexes;j++)
							/*判断其它顶点若与当前顶点存在边且未访问过*/
							if(G.arc[)[j] = 1 && !visited[j])
							visited[j]=TRUE;
							/*将找到的此顶点标记为已访问
							*/
							printf("%c ", G.vexs[j]); /* 打印顶点*/
							EnQueue(&Q,j);
							/*将找到的此顶点入队列*/
};
M_Graph::GraphAdjList M_Graph::DefaultGraphT(MGraph G)
{	/*利用邻接矩阵构建邻接表*/
						int i,j;
						EdgeNode *e;
						*GL = (GraphAdjLit)malloc(sizeof(graphAdjList);
						(*GL)->numVertexes=G.numVertexes;
						(*GL)->numEdges=G.numEdges;
						for(i= 0;i <G.numVertexes,;++)/*读入顶点信息,建立顶点表*/
						(*QGL)->adjist[ij.in=0;
						(*GL)->adjList[i].data=G.vexs[i];
						(*G)->adjLiti.firstedge=NULL; /* 将边表置为空表*/
						for(i=;<G.numVertexes,;++)/*建立边表*/
						for(j=0;j<G.numVertexes;j++)
						if (G.arCi)i)==1)
						e=(EdgeNode *laliszeof(Edgeodell;
						e->adjvex=j;
						/*邻接序号为j*/ 
						e->ext-(*G)-adjLitij.firstedge; /* 将当前顶点上的指向的结点指针
						赋值给e*/
						(*G)->adjLit(i.firstedge=e;
						/*将当前顶点的指针指向e*/
						(96G)->adjistjl.in+t;


	return GL;
}

void M_Graph::DFS1()
{
							/*邻接表的深度优先递归算法*/
						void DFS(GraphAdjList GL, int i)
					
						EdgeNode *p;
						visited[i] = TRUE;
						printf("%c ",GL>adjLstij.data);:/*打印顶点也可以其它操作*/
						p= GL->adjListij_firstedge;
						while(p)
						if(!visited[p->adjvex)
						DFS(GL, p->adjvex);/*对为访问的邻接顶点递归调用*/
						p= p->next;
				


};
void M_Graph::DFS1Traverse()
{
			/*邻接表的深度遍历操作*/
					void DFSTraverse(GraphAdjList GL)
				
					int i;
					for(i = 0; i< GL->numVertexes; it+)
					visited[i] = FALSE; /*初始所有顶点状态都是未访问过状态*/
					for(i= 0;i< GL->numVertexes; i++)
					if(visited[i]) /*对未访问过的顶点调用DFS,若是连通图,只会执行一次*/
					DFS(GL, i);

};

void M_Graph::BFS1Traverse()
{
						/*邻接表的广度遍历算法*/
					void BFSTraverse(GraphAdjList GL)
					inti;
					EdgeNode *p;
					Queue Q;
					for(i= 0; i< GL->numVertexes; i++)
					visited[i] = FALSE;
					InitQueue(&Q);
					for(i= 0;i< GL->numVertexes; i++)
					{
					if (!visited[])
					{
					visited[i]=TRUE;
					print("%c ",GL-adiListi).data);/*打印顶点,也可以其它操作*/
					EnQueue(&Q,i);
					while(!QueueEmpty(Q))
												{
						DeQueue(&Q,&i);
						p= GL-adiListi.frstedge; /* 找到当前顶点的边表链表头指针*/
						while(p)
						if(lvisited[p->adjvex) /* 若此顶点未被访问*/
						visited[p->adjvex]=TRUE; 
						printf("%c ",GL->adjList[p->adjvex].data);
						EnQueue(&Q,p->adjvex); /* 将此顶点入队列*/
						p=p->next; /* 指针指向下一个邻接点*/
						}
					}}



};



void GraphUsage::Prim(MGraph G)//最小生成树
{
	/* Prim算法生成最小生成树*/
			int min, i,j, k;
			int adjvex[MAXVEX];
			/*保存相关顶点下标*/
			int lowcost[MAXVEX]; /* 保存相关顶点间边的权值*/
			lowcost[0] = 0;/*初始化第-一个权值为0，即vo加入生成树*/
			/* lowcost的值为0，在这里就是此下标的顶点已经加入生成树*/
			adjvex[0]= 0;
			/*初始化第一个顶点下标为0*/
			for(i= 1;i< G.numVertexes;++) /* 循环除下标为0外的全部顶点*/
			{
				lowcost[i] = G.arc[0][); /* 将v0顶点与之有边的权值存入数组*/
				adjvex[i] = 0;
				/*初始化都为v0的下标*/
			}
			for(i= 1;i< G.numVertexes; i++)
			{min = INFINITY;
			/*初始化最小权值为∞，*/
			/*通常设置为不可能的大数字如32767、65535 等*/
			j= 1;k=0;
			while(j < G.numVertexes) /* 循环全部顶点*/
			iflowcostj]!=0 && lowcot[j] < min)/*如果权值不为0且权值小于min */
			min= lowcostj]; /* 则让当前权值成为最小值*/
			k=j;
			/*将当前最小值的下标存入k*/
			}
			j++;
			prit("(%d, %d)\n", adjvex[k], k);:/*打印当前顶点边中权值最小的边*/
			lowcost[k] = 0;/*将当前顶点的权值设置为0,表示此顶点已经完成任务*/
			for(j= 1;j< G.numVertexe;j++) /* 循环所有顶点*/
			{
			iflowcost[j]!=0 && G.arc[k][j] < lowcost[i)
			{/*如果下标为k顶点各边权值小于此前这些顶点未被加入生成树权值*/
			lowcostj] = G.arc[k][i];/*将较小的权值存入lowcost相应位置*/
			adjvex[j]= k;
			/*将下标为k的顶点存入adjvex */
	
			}
			}


};

void GraphUsage::MiniSpanTree_Kruskal(MGraph G)
{
					int i,j, n, m;
					int k= 0; 
					int parent[MAXVEX];:/*定义一数组用来判断边 与边是否形成环路*/
					Edge edges[MAXEDGE);/*定义边集数组,edge的结构为begin,end,weight,均为整型*/
					/*用来构建边集数组并*序***************/
					for (i= 0; i< G.numVertexes-1; i++)
					for (j=i+ 1;j< G.numVertexes; j++)
					if (G.arc[jli]<INFINITY)
					edges[k].begin= i;
					edges[k].end=j;
					edges[k].weight = G.arc[)Ji];
					k++;
			
					sort(edges, &G);
					/* ******************************/
					for (i= 0; i< G.numVertexes; i++)
					parenti]=0; /* 初始化数组值为0*/
					printf("打印最小生成树: \n");
					for (i= 0; i< G.numEdges;i++) /* 循环每- -条边*/
					{
					n= Find(parent,edges[j].begin);
					m = Find(parent,edges[i].end);
					if(n!=m)/*假如n与m不等，说明此边没有与现有的生成树形成环路*/
					{
					parent[n] = m;/*将此边的结尾顶点放入下标为起点的parent中。*/
					/*表示此顶点已经在生成树集合中*/
					printf("(%d, %d) %d\n", edges[i].begin, edges[i].end, edgesi].weight);

					}}
};

void GraphUsage::ShortestPath_Djkstra(MGraph G,int v0,Patharc *P, ShortPathTable* D)// Vx源点到其他点的 最短路径P以及长度D
{
			int v,w,k,min;
			int final[MAXVEX];/* final|[w]=1表示求得顶点v0至ww的最短路径*/
			for(v=0; v<G.numVertexes;v++) /* 初始化数据*/
			{final[v]= 0;
			/*全部顶点初始化为未知最短路径状态*/
			(*D)M] = G.arc[v0][v];/*将与vo点有连线的顶点加上权值*/
			(*P)[V]=0;
			/*初始化路径数组P为0 */
			}
			(*D)|vO]=0; /* v0至v0路径为0*/
			final[v0] = 1;
			/* v0至v0不需要求路径*/
			/*开始主循环，每次求得v0到某个v顶点的最短路径*/
			for(v=1; v<G.numVertexes; V++)
			{
			min=INFINITY;
			/*当前所知离v0顶点的最近距离*/
			for(w=0; w<G.numVertexes; w++)/*寻找离v0最近的顶点*/
			{if(!final[w] && (*D)[w]<min)
			k=w;
			min= (*D)[w]; /* w顶点离vO顶点更近*/
				}
			}
			fial[k]=1; /* 将目前找到的最近的顶点置为1 */
			for(w=0; w<G.numVertexes; w++)/*修正当前最短路径及距离*/
			/*如果经过v顶点的路径比现在这条路径的长度短的话*/
			if(final[w] && (min+G.arc[k][w]<(*D)[wI))
			{/*说明找到了 更短的路径，修改D[w]和P[w] */
			(*D)[w] = min + G.arc[k][w]; /* 修改当前路径长度*/
			(*P)[w]=k;
			}


};
void GraphUsage::ShortestPath_Floyd(MGraph G, Patharc_ *p, ShortPathTable_ *D)/* Floyd算法,求网图G中各顶点v到其余顶点w的最短路径P[v][w]及带权长度D[v][w]。 */
{
	
					int v,w,k;
					for(v=0; v<G.numVertexes; ++v)/*初始化D与p*/
					{for(w=0; w<G.numVertexes; ++w)
					{(*D)[v][w]=6.arc[v]w]; /* D[V][w值即为对应点间的权值*/
					(*P)[V][w]=w;
					/*初始化P*/
					}
					for(k=0; k<G.numVertexes; ++k)
					for(v=0; v<G.numVertexes; ++v)
					for(w=0; w<G.numVertexes; ++w)
					if (*D)V][w]>(*D)[v][k]+(*D)[k][w])
					{/*如果经过下标为k顶点路径比原两点间路径更短*/
					(*D)[V][w)=(*D)V][k]+(*D)[k][];/* 将当前两点间权值设为更小的一
					个*/
					(*P)[V][w]=(*P)VI[k];/*路径设置为经过下标为k的顶点*/
					}
					}


};
void GraphUsage::TopologicalSort(GraphAdjList GL)//拓扑排序
{
				/*拓扑排序，若GL无回路，则输出拓扑排序序列并返回1,若有回路返回0。*/
				EdgeNode *e;
				int ik,gettop;
				int top=0; /* 用于栈指针下标*/
				int count=0;/*用于统计输出顶点的个数*/
				int *stack;
				/*建栈将入度为0的顶点入栈*/
				stack=(int *)malloc(GL->numVertexes * sizeof(int) );
				for(i = 0; i<GL->numVertexes; i++)
				if(0 == GL>adjListil.in)/*将入度为0的顶点入栈*/
				stackl++top]=i;
				while(top!=0)
				gettop=stack[top-];
				printf("%d -> ",GL->adjList(gettop].data);
				count++;
				/*输出1号顶点，并计数*/
				for(e = GL->adjListlettop]firstedge; e; e= e->next)
				k=e->adjvex;
				if( !-L-ajistk].inN) /* 将i号顶点的邻接点的入度减1,如果减1后为0,
				则入栈*/
				stack[++top]=k;
				prinf("n");
				if(count < GL->numVertexes)
				return ERROR;
				else
				return OK;


};


void GraphUsage::CriticalPath(GraphAdjList GL)//关键路径
{
	typedef int Status; /* Status是函数的类型,其值是函数结果状态代码，如OK等*/
	int *etv,*Itv;/*事件最早发生时间和最迟发生时间数组，全局变量*/
	int *stack2; /* 用于存储拓扑序列的栈*/
	int top2; /* 用于stack2的指针*/

						/*求关键路径,GL为有向网，输出G的各项关键活动*/
						void CriticalPath(GraphAdjList GL)
						EdgeNode *e;
						int i,gettop,kj;
						int ete,te; /* 声明活动最早发生时间和最迟发生时间变量*/
						TopologicalSort(GL); /* 求拓扑序列，计算数组etv和stack2的值*/
						ltv=(int *)malloc(GL->numVerexes*szgfit):/*事件最早发生时间数组*/
						for(i=0; i<GL->numVertexes; i++)
						Itv[]=etv[GL->numVertexes-1]; /* 初始化*/
						printf("etv:\t");
						for(i=0; i<GL->numVertexes; i++)
						printf("%d -> ",etv[l);
						pritf("\n"); .
						while(top2!=0) /* 出栈是求ltv*/
						gettop=stack2[top2--];
						for(e = GLdijlitettop]firstedge; e; e = e->next)
						/*求各顶点事件的最迟
						发生时间Itv值*/
						k=e->adjvex;
						if(ltv[k] - e->weight < ltv(gettop1)
							Itvlgettop] = Itv[k] - e->weight;
						}
						}
						printf("ltv:\t");
						for(i=0; i<GL->numVertexes; i++)
						printf("%d -> ",Itv[i]);
						pritf("n");
						for(j=0; j<GL->numVertexes; j++)
						/*求ete,Ite和关键活动*/
						for(e = GL->adjLstj].firstedge; e; e= e->next)
						k=e->adjvex;
						ete = etv[];
						/*活动最早发生时间*/
						Ite = ltv[k]- e->weight; /*活动最迟发生时间*/
						if(lete==lte) /* 两者相等即在关键路径上*/
						printf("<v%d
						v%d>
						length:
						%d
						\n'",GL-adjLiti].data,6L->adjistlk].data,e->weight);
						}




};