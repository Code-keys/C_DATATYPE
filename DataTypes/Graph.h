#pragma once
#include"stdio.h"
#include"stdlib.h"
#include"io.h"
#include"time.h"
#include"math.h"
/*
������ϸ��Щ��������ͼ����ض�����
				�����㷨�͸߼�ʹ���㷨��
				������ķ�װ���䶨�塣
base operation������

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

Advance operation������
	 Prim();//��С������
	 Kruskal();

	 Djkstra();//���·��
	 Floyd();

	 TopologicalSort();//��������
	 CriticalPath());//�ؼ�·��

*/
//template<class GElemType>
#define	ERROR  0 
#define	OK  1
#define	TURE 1
#define	FALSE  0

#define MAXVEX  100
#define MAXSIZE 9 /*�洢�ռ��ʼ������*/
#define MAXEDGE 15
#define INFINITY  65535

typedef int GElemType;

class pre /*��д��֮ǰ��һЩ����*/
{
public:
	/*�õ��Ķ��нṹ��************************* */
	/*ѭ�����е�˳��洢�ṹ*/
	typedef struct
	{
		int begin;
		int end;
		int weight;
	}Edge; /* �Ա߼�����Edge�ṹ�Ķ���*/

	typedef struct
	{
		int data[MAXSIZE];
		int front;
		/*ͷָ��*/
		int rear; 
		/*βָ�룬�����в��գ�ָ�����βԪ�ص���һ��λ��*/
	}Queue;

	/*��ʼ��һ���ն���Q*/
	bool InitQueue(Queue *Q)
	{
		Q->front=0;
		Q->rear=0;
		return OK;
	};
	/*������QΪ�ն��У��򷵻�TRUE,���򷵻�FALSE */
	bool QueueEmpty(Queue Q)
	{
		if(Q.front==Q.rear) /*���пյı�־*/
			return TRUE;
		else 
			return FALSE;
	};
	/*������δ���������Ԫ��eΪQ�µĶ�βԪ��*/
	bool EnQueue(Queue *Q,int e)
	{
		if( (Q->rear+1) % MAXSIZE == Q->front)/*���������ж�*/
			return ERROR;
		Q->data[Q->rear]=e;
		/*��Ԫ��e��ֵ����β*/
		Q->rear=(Q->rear+1)%MAXSIZE;/* rearָ�������- -λ�ã� */
		/*���������ת������ͷ��*/
		return OK;
	};
	/*�����в��գ���ɾ��Q�ж�ͷԪ������e������ֵ*/
	bool DeQueue(Queue *Q,int *e)
	{
		if (Q->front == Q->rear)
		/*���пյ��ж�*/
		return ERROR;
		*e=Q->data[Q->front];
		/*����ͷԪ�ظ�ֵ��e*/
		Q->front=(Q->front+1)%MAXSIZE; /* frontָ�������- -λ�ã�*/
		/*���������ת������ͷ��*/
		return OK;
	};


	
	void Swapn(Edge *edges,int i, int j)/*����Ȩֵ�Լ�ͷ��β*/
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
	
	void sort(Edge edges[],MGraph *G)/*��Ȩֵ��������*/
	{
		int i, j;
		for (i= 0; i< G->numEdges; i++)
		{	for(j=i+ 1;j< G->numEdges; j++)
			{	
				if (edges[i].weight > edgesj].weight)
					Swapn(edges, i, j);
			}
		}
		printf("Ȩ����֮���Ϊ:\n");
		for (i= 0; i< G->numEdges; i++)
			printf("(%d, %d) %d\n", edges[i].begin, edges[i].end, edges[i].weight);
	};
	
	int Find(int * parent, int f)/*�������߶����β���±�*/
	{
		while ( parent[f]> 0)
		{f= parent[f];}
		return f;
	}


};
class M_Graph :public pre
{
private:
	typedef int Status; /* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK��*/
	typedef char VertexType;/*��������Ӧ���û�����*/
	typedef int EdgeType;/*���ϵ�Ȩֵ����Ӧ���û�����*/
	typedef int Boolean; /* Boolean�ǲ�������,��ֵ��TRUE��FALSE */
protected:
public:
	/*�ڽӾ���*/
	typedef struct MGraph
	{
		VertexType vexs[MAXVEX];/*�����*/
		EdgeType arc[MAXVEX][MAXVEX];/*�ڽӾ��󣬿ɿ����߱�*/
		int numVertexes, numEdges; /*ͼ�е�ǰ�Ķ������ͱ���*/
	}*MGraphptr;
	/*�ڽӱ�*/
	typedef struct EdgeNode/*�߱���*/
	{
		int adjvex; /* �ڽӵ���洢�ö����Ӧ���±�*/
		EdgeType info;/*���ڴ洢Ȩֵ,���ڷ���ͼ���Բ���Ҫ*/
		struct EdgeNode *next;/*����,ָ����һ���ڽӵ�*/
	}EdgeNode;
	typedef struct VertexNode/*�������*/
	{
		int in;/*�������*/
		VertexType data;/*������,�洢������Ϣ*/
		EdgeNode *firstedge;/*�߱�ͷָ��*/
	}VertexNode, AdjList[MAXVEX];
	typedef struct graphAdjList 
	{
		AdjList adjList;
		int numNodes,numEdges; /*ͼ�е�ǰ�������ͱ���*/
	}graphAdjList,*GraphAdjList;

	graphAdjList *G;
	Boolean visited[MAXVEX]; /*���ʱ�־������*/

	

public:	
	bool _initial(){/*to do*/};

	/*�ڽӾ����ʾ������������ͼ*/
	virtual void CreateMGraph(MGraph *MG)
	{
		int i,j,k,w;
		printf("���붥�����ͱ���:\n");
		scanf_s("%d,%d",&MG->numVertexes,&MG->numEdges);/*���붥�����ͱ���*/
		for(i = 0;i < MG->numVertexes;i++)/*���붥����Ϣ,���������*/
			scanf_s(&MG->vexs[i]);
		for(i = 0;i < MG->numVertexes;i++)
			for(j= 0;j < MG->numVertexes;j++)
				MG->arc[i][j]=INFINITY; /* �ڽӾ����ʼ��*/
				for(k = 0;k < MG->numEdges;k++)/*����numEdges���ߣ������ڽӾ���*/
				{
					printf("�����(i,vj)�ϵ��±�i���±�j��Ȩw:\n");
					scanf_s("%d,%d,%d",&i,&j,&w); /*�����(i,vj)�ϵ�Ȩw*/
					MG->arc[i][j]=w;
					MG->arc[j][i]= MG->arc[i][j]; /*��Ϊ������ͼ������Գ�*/
				};
	};	
	virtual MGraph DefaultGraphV(void);
	/*�ڽӾ�����Ⱥ͹�ȱ���DFS_ BFS */
	virtual void DFS();
	void DFSTraverse(GraphAdjList GL);
	void BFSTraverse(MGraph G);
.
	
	/*�ڽӱ� -> ����������ͼ*/
	virtual void CreateALGraph()
	{
		int i,j,k;
		EdgeNode *e;
		printf("���붥�����ͱ���:\n");
		scanf_s("%d,%d" ,&G->numNodes,&G->numEdges); /*���붥�����ͱ���*/
		for(i = 0;i < G->numNodes;i++)/*���붥����Ϣ,���������*/
		{
			scanf_s(&G->adjList[i].data); /* ���붥����Ϣ*/
			G->adjList[i].firstedge=NULL; /* ���߱���Ϊ�ձ�*/
		}
		for(k = 0;k < G->numEdges;k++)/*�����߱�*/
		{
			printf("�����(vi,vj).�ϵĶ������:\n");
			scanf_s("%d,%d" ,&i,&j);/*�����(i,vi)l �ϵĶ������*/
			e=(EdgeNode *)malloc(sizeof(EdgeNode)); /*���ڴ�����ռ�,���ɱ߱���*/
			e->adjvex=j;/*�ڽ����Ϊj*/
			
			e->next = G->adjList[i].firstedge; /* ��e��ָ��ָ��ǰ������ָ��Ľ��*/
			G->adjList[i].firstedge = e; /* ����ǰ�����ָ��ָ��e*/
			e=(EdgeNode *)malloc(sizeof(EdgeNode)); /*���ڴ�����ռ�,���ɱ߱���*/
			e->adjvex = i;/*�ڽ����Ϊi*/
			
			e->next=G->adjList[j].firstedge; /* ��e��ָ��ָ��ǰ������ָ��Ľ��*/
			G->adjList[j].firstedge=e; /* ����ǰ�����ָ��ָ��e*/
		}
	};
	GraphAdjList DefaultGraphT(MGraph G);

	/*�ڽӱ���Ⱥ͹�ȱ���DFS_ BFS */
	virtual void DFS1();
	void DFSTraverse(GraphAdjList GL);
	void BFST1raverse(MGraph G);
};

class GraphUsage:public M_Graph
{
public:

	void MiniSpanTree_Prim();//��С������
	void MiniSpanTree_Kruskal();

	typedef int Patharc[MAXVEX];/*���ڴ洢���·���±������*/ .
	typedef int ShortPathTable[MAXVEX];/*���ڴ洢���������·����Ȩֵ��*/
	void ShortestPath_Djkstra(MGraph G,int v0,Patharc *P, ShortPathTable* D);//���·��

	typedef int Patharc_[MAXVEX][MAXVEX];/*���ڴ洢���·���±������*/ .
	typedef int ShortPathTable_[MAXVEX][MAXVEX];/*���ڴ洢���������·����Ȩֵ��*/
	void ShortestPath_Floyd(MGraph G, Patharc *p, ShortPathTable *D);

	void TopologicalSort(GraphAdjList GL);//��������
	void CriticalPath(GraphAdjList GL);//�ؼ�·��


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
							/*�ڽӾ����������ȵݹ��㷨*/
						void DFS(MGraph G, int i)
						int j; .
						visited[i] = TRUE;
						printf("%c ", G.vexs[);/*��ӡ���㣬Ҳ������������*/
						for(j = 0; j < G.numVertexes; j++)
						if(G.arc[)[j] == 1 && !visited[j])
						DFS(G, j);/*��Ϊ���ʵ��ڽӶ���ݹ����*/


};
void M_Graph::DFSTraverse()
{
							/*�ڽӾ������ȱ�������*/
							void DFSTraverse(MGraph G)
							inti;
							for(i= 0; i< G.numVertexes; i++)
							visited[i] = FALSE; /*��ʼ���ж���״̬����δ���ʹ�״̬*/
							for(i= 0; i < G.numVertexes; i++)
							if(visited[i) /*��δ���ʹ��Ķ������DFS,������ͨͼ��ֻ��ִ��һ��*/ 
							DFS(G, i);

};
void M_Graph::BFSTraverse()
{
								/*�ڽӾ���Ĺ�ȱ����㷨*/
							void BFSTraverse(MGraph G)
							inti, j;
							Queue Q;
							for(i = 0; i < G.numVertexes; i++)
							visited[i] = FALSE;
							InitQueue(&Q);
							/*��ʼ��һ�����õĶ���*/
							for(i = 0; i< G.numVertexes;i++) /* ��ÿ-һ��������ѭ��*/
							if (visited[i) /* ����δ���ʹ��ʹ���*/
							visited[)=TRUE;
							/*���õ�ǰ������ʹ�*/
							printf("%c " G.vex5[);/*��ӡ���㣬Ҳ������������*/
							EnQueue(&Q,i);
							/*���˶��������*/
							while(!QueueEmpty(Q)) /*����ǰ���в�Ϊ��*/
							DeQueue(&Q,&i); /* ���Ӷ�Ԫ�س����У���ֵ��i*/
							for(j=0;j<G.numVertexes;j++)
							/*�ж������������뵱ǰ������ڱ���δ���ʹ�*/
							if(G.arc[)[j] = 1 && !visited[j])
							visited[j]=TRUE;
							/*���ҵ��Ĵ˶�����Ϊ�ѷ���
							*/
							printf("%c ", G.vexs[j]); /* ��ӡ����*/
							EnQueue(&Q,j);
							/*���ҵ��Ĵ˶��������*/
};
M_Graph::GraphAdjList M_Graph::DefaultGraphT(MGraph G)
{	/*�����ڽӾ��󹹽��ڽӱ�*/
						int i,j;
						EdgeNode *e;
						*GL = (GraphAdjLit)malloc(sizeof(graphAdjList);
						(*GL)->numVertexes=G.numVertexes;
						(*GL)->numEdges=G.numEdges;
						for(i= 0;i <G.numVertexes,;++)/*���붥����Ϣ,���������*/
						(*QGL)->adjist[ij.in=0;
						(*GL)->adjList[i].data=G.vexs[i];
						(*G)->adjLiti.firstedge=NULL; /* ���߱���Ϊ�ձ�*/
						for(i=;<G.numVertexes,;++)/*�����߱�*/
						for(j=0;j<G.numVertexes;j++)
						if (G.arCi)i)==1)
						e=(EdgeNode *laliszeof(Edgeodell;
						e->adjvex=j;
						/*�ڽ����Ϊj*/ 
						e->ext-(*G)-adjLitij.firstedge; /* ����ǰ�����ϵ�ָ��Ľ��ָ��
						��ֵ��e*/
						(*G)->adjLit(i.firstedge=e;
						/*����ǰ�����ָ��ָ��e*/
						(96G)->adjistjl.in+t;


	return GL;
}

void M_Graph::DFS1()
{
							/*�ڽӱ��������ȵݹ��㷨*/
						void DFS(GraphAdjList GL, int i)
					
						EdgeNode *p;
						visited[i] = TRUE;
						printf("%c ",GL>adjLstij.data);:/*��ӡ����Ҳ������������*/
						p= GL->adjListij_firstedge;
						while(p)
						if(!visited[p->adjvex)
						DFS(GL, p->adjvex);/*��Ϊ���ʵ��ڽӶ���ݹ����*/
						p= p->next;
				


};
void M_Graph::DFS1Traverse()
{
			/*�ڽӱ����ȱ�������*/
					void DFSTraverse(GraphAdjList GL)
				
					int i;
					for(i = 0; i< GL->numVertexes; it+)
					visited[i] = FALSE; /*��ʼ���ж���״̬����δ���ʹ�״̬*/
					for(i= 0;i< GL->numVertexes; i++)
					if(visited[i]) /*��δ���ʹ��Ķ������DFS,������ͨͼ,ֻ��ִ��һ��*/
					DFS(GL, i);

};

void M_Graph::BFS1Traverse()
{
						/*�ڽӱ�Ĺ�ȱ����㷨*/
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
					print("%c ",GL-adiListi).data);/*��ӡ����,Ҳ������������*/
					EnQueue(&Q,i);
					while(!QueueEmpty(Q))
												{
						DeQueue(&Q,&i);
						p= GL-adiListi.frstedge; /* �ҵ���ǰ����ı߱�����ͷָ��*/
						while(p)
						if(lvisited[p->adjvex) /* ���˶���δ������*/
						visited[p->adjvex]=TRUE; 
						printf("%c ",GL->adjList[p->adjvex].data);
						EnQueue(&Q,p->adjvex); /* ���˶��������*/
						p=p->next; /* ָ��ָ����һ���ڽӵ�*/
						}
					}}



};



void GraphUsage::Prim(MGraph G)//��С������
{
	/* Prim�㷨������С������*/
			int min, i,j, k;
			int adjvex[MAXVEX];
			/*������ض����±�*/
			int lowcost[MAXVEX]; /* ������ض����ߵ�Ȩֵ*/
			lowcost[0] = 0;/*��ʼ����-һ��ȨֵΪ0����vo����������*/
			/* lowcost��ֵΪ0����������Ǵ��±�Ķ����Ѿ�����������*/
			adjvex[0]= 0;
			/*��ʼ����һ�������±�Ϊ0*/
			for(i= 1;i< G.numVertexes;++) /* ѭ�����±�Ϊ0���ȫ������*/
			{
				lowcost[i] = G.arc[0][); /* ��v0������֮�бߵ�Ȩֵ��������*/
				adjvex[i] = 0;
				/*��ʼ����Ϊv0���±�*/
			}
			for(i= 1;i< G.numVertexes; i++)
			{min = INFINITY;
			/*��ʼ����СȨֵΪ�ޣ�*/
			/*ͨ������Ϊ�����ܵĴ�������32767��65535 ��*/
			j= 1;k=0;
			while(j < G.numVertexes) /* ѭ��ȫ������*/
			iflowcostj]!=0 && lowcot[j] < min)/*���Ȩֵ��Ϊ0��ȨֵС��min */
			min= lowcostj]; /* ���õ�ǰȨֵ��Ϊ��Сֵ*/
			k=j;
			/*����ǰ��Сֵ���±����k*/
			}
			j++;
			prit("(%d, %d)\n", adjvex[k], k);:/*��ӡ��ǰ�������Ȩֵ��С�ı�*/
			lowcost[k] = 0;/*����ǰ�����Ȩֵ����Ϊ0,��ʾ�˶����Ѿ��������*/
			for(j= 1;j< G.numVertexe;j++) /* ѭ�����ж���*/
			{
			iflowcost[j]!=0 && G.arc[k][j] < lowcost[i)
			{/*����±�Ϊk�������ȨֵС�ڴ�ǰ��Щ����δ������������Ȩֵ*/
			lowcostj] = G.arc[k][i];/*����С��Ȩֵ����lowcost��Ӧλ��*/
			adjvex[j]= k;
			/*���±�Ϊk�Ķ������adjvex */
	
			}
			}


};

void GraphUsage::MiniSpanTree_Kruskal(MGraph G)
{
					int i,j, n, m;
					int k= 0; 
					int parent[MAXVEX];:/*����һ���������жϱ� ����Ƿ��γɻ�·*/
					Edge edges[MAXEDGE);/*����߼�����,edge�ĽṹΪbegin,end,weight,��Ϊ����*/
					/*���������߼����鲢*��***************/
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
					parenti]=0; /* ��ʼ������ֵΪ0*/
					printf("��ӡ��С������: \n");
					for (i= 0; i< G.numEdges;i++) /* ѭ��ÿ- -����*/
					{
					n= Find(parent,edges[j].begin);
					m = Find(parent,edges[i].end);
					if(n!=m)/*����n��m���ȣ�˵���˱�û�������е��������γɻ�·*/
					{
					parent[n] = m;/*���˱ߵĽ�β��������±�Ϊ����parent�С�*/
					/*��ʾ�˶����Ѿ���������������*/
					printf("(%d, %d) %d\n", edges[i].begin, edges[i].end, edgesi].weight);

					}}
};

void GraphUsage::ShortestPath_Djkstra(MGraph G,int v0,Patharc *P, ShortPathTable* D)// VxԴ�㵽������� ���·��P�Լ�����D
{
			int v,w,k,min;
			int final[MAXVEX];/* final|[w]=1��ʾ��ö���v0��ww�����·��*/
			for(v=0; v<G.numVertexes;v++) /* ��ʼ������*/
			{final[v]= 0;
			/*ȫ�������ʼ��Ϊδ֪���·��״̬*/
			(*D)M] = G.arc[v0][v];/*����vo�������ߵĶ������Ȩֵ*/
			(*P)[V]=0;
			/*��ʼ��·������PΪ0 */
			}
			(*D)|vO]=0; /* v0��v0·��Ϊ0*/
			final[v0] = 1;
			/* v0��v0����Ҫ��·��*/
			/*��ʼ��ѭ����ÿ�����v0��ĳ��v��������·��*/
			for(v=1; v<G.numVertexes; V++)
			{
			min=INFINITY;
			/*��ǰ��֪��v0������������*/
			for(w=0; w<G.numVertexes; w++)/*Ѱ����v0����Ķ���*/
			{if(!final[w] && (*D)[w]<min)
			k=w;
			min= (*D)[w]; /* w������vO�������*/
				}
			}
			fial[k]=1; /* ��Ŀǰ�ҵ�������Ķ�����Ϊ1 */
			for(w=0; w<G.numVertexes; w++)/*������ǰ���·��������*/
			/*�������v�����·������������·���ĳ��ȶ̵Ļ�*/
			if(final[w] && (min+G.arc[k][w]<(*D)[wI))
			{/*˵���ҵ��� ���̵�·�����޸�D[w]��P[w] */
			(*D)[w] = min + G.arc[k][w]; /* �޸ĵ�ǰ·������*/
			(*P)[w]=k;
			}


};
void GraphUsage::ShortestPath_Floyd(MGraph G, Patharc_ *p, ShortPathTable_ *D)/* Floyd�㷨,����ͼG�и�����v�����ඥ��w�����·��P[v][w]����Ȩ����D[v][w]�� */
{
	
					int v,w,k;
					for(v=0; v<G.numVertexes; ++v)/*��ʼ��D��p*/
					{for(w=0; w<G.numVertexes; ++w)
					{(*D)[v][w]=6.arc[v]w]; /* D[V][wֵ��Ϊ��Ӧ����Ȩֵ*/
					(*P)[V][w]=w;
					/*��ʼ��P*/
					}
					for(k=0; k<G.numVertexes; ++k)
					for(v=0; v<G.numVertexes; ++v)
					for(w=0; w<G.numVertexes; ++w)
					if (*D)V][w]>(*D)[v][k]+(*D)[k][w])
					{/*��������±�Ϊk����·����ԭ�����·������*/
					(*D)[V][w)=(*D)V][k]+(*D)[k][];/* ����ǰ�����Ȩֵ��Ϊ��С��һ
					��*/
					(*P)[V][w]=(*P)VI[k];/*·������Ϊ�����±�Ϊk�Ķ���*/
					}
					}


};
void GraphUsage::TopologicalSort(GraphAdjList GL)//��������
{
				/*����������GL�޻�·������������������в�����1,���л�·����0��*/
				EdgeNode *e;
				int ik,gettop;
				int top=0; /* ����ջָ���±�*/
				int count=0;/*����ͳ���������ĸ���*/
				int *stack;
				/*��ջ�����Ϊ0�Ķ�����ջ*/
				stack=(int *)malloc(GL->numVertexes * sizeof(int) );
				for(i = 0; i<GL->numVertexes; i++)
				if(0 == GL>adjListil.in)/*�����Ϊ0�Ķ�����ջ*/
				stackl++top]=i;
				while(top!=0)
				gettop=stack[top-];
				printf("%d -> ",GL->adjList(gettop].data);
				count++;
				/*���1�Ŷ��㣬������*/
				for(e = GL->adjListlettop]firstedge; e; e= e->next)
				k=e->adjvex;
				if( !-L-ajistk].inN) /* ��i�Ŷ�����ڽӵ����ȼ�1,�����1��Ϊ0,
				����ջ*/
				stack[++top]=k;
				prinf("n");
				if(count < GL->numVertexes)
				return ERROR;
				else
				return OK;


};


void GraphUsage::CriticalPath(GraphAdjList GL)//�ؼ�·��
{
	typedef int Status; /* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK��*/
	int *etv,*Itv;/*�¼����緢��ʱ�����ٷ���ʱ�����飬ȫ�ֱ���*/
	int *stack2; /* ���ڴ洢�������е�ջ*/
	int top2; /* ����stack2��ָ��*/

						/*��ؼ�·��,GLΪ�����������G�ĸ���ؼ��*/
						void CriticalPath(GraphAdjList GL)
						EdgeNode *e;
						int i,gettop,kj;
						int ete,te; /* ��������緢��ʱ�����ٷ���ʱ�����*/
						TopologicalSort(GL); /* ���������У���������etv��stack2��ֵ*/
						ltv=(int *)malloc(GL->numVerexes*szgfit):/*�¼����緢��ʱ������*/
						for(i=0; i<GL->numVertexes; i++)
						Itv[]=etv[GL->numVertexes-1]; /* ��ʼ��*/
						printf("etv:\t");
						for(i=0; i<GL->numVertexes; i++)
						printf("%d -> ",etv[l);
						pritf("\n"); .
						while(top2!=0) /* ��ջ����ltv*/
						gettop=stack2[top2--];
						for(e = GLdijlitettop]firstedge; e; e = e->next)
						/*��������¼������
						����ʱ��Itvֵ*/
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
						/*��ete,Ite�͹ؼ��*/
						for(e = GL->adjLstj].firstedge; e; e= e->next)
						k=e->adjvex;
						ete = etv[];
						/*����緢��ʱ��*/
						Ite = ltv[k]- e->weight; /*���ٷ���ʱ��*/
						if(lete==lte) /* ������ȼ��ڹؼ�·����*/
						printf("<v%d
						v%d>
						length:
						%d
						\n'",GL-adjLiti].data,6L->adjistlk].data,e->weight);
						}




};