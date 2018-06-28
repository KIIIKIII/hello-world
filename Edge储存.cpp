#include<cstdlib>
#include<cstdio>
#include<queue>
#include<iostream>
using namespace std;

#define MAX_VERTEX_NUM 10000
typedef int InfoType;
typedef int VertexType;
typedef struct ArcNode {		//链表中的元素数据结构，即表节点
	int adjvex;					//该弧所指向的顶点位置
	struct ArcNode *next;		//指向下一条弧的指针
	InfoType *info;				//该数据域存储和边或者弧相关的信息，如权值等其他信息。
}ArcNode;
typedef struct VNode {
	VertexType data;			//存储顶点的名或其他信息的数据域
	ArcNode	*firstarc;			//指向链表中的第一个节点
}VNode, AdjList[MAX_VERTEX_NUM];
typedef struct {
	AdjList	vertices;
	int vexnum;
}ALGraph;

void CreatALGraph(ALGraph *G) {
	int ListNum = 0;
	int vex;
	int tempVex;
	int tempVexNum;
	ArcNode* node = NULL;
	ArcNode* tempPoint = NULL;
	scanf("%d", &vex);
	G->vexnum = vex;
	for (int i = 0; i < MAX_VERTEX_NUM; i++)
		G->vertices[i].data = -1;
	for (int i = 0; i < vex; i++) {
		scanf("%d", &tempVexNum);
		if (tempVexNum > 0) {	//存在指向，才执行下面
			G->vertices[ListNum].data = i;			//这个data用来存储头结点的号数
			if (ListNum >= MAX_VERTEX_NUM) {
				return;
			}
			for (int j = 0; j < tempVexNum; j++) {
				scanf("%d", &tempVex);
				node = (ArcNode*)malloc(sizeof(ArcNode));
				node->next = NULL;
				node->adjvex = tempVex;

				if (j == 0)
					G->vertices[i].firstarc = node;
				else
					tempPoint->next = node;
				tempPoint = node;
			}
		}
		else {
			G->vertices[ListNum].data = -1;
			G->vertices[i].firstarc = NULL;
		}
		ListNum++;
	}
	return;
}
void ShowGraph(ALGraph G) {
	ArcNode* temp;
	int p = 0;
	cin >> p;
	for (int i = 0; i < p; i++) {
		int u = 0;
		cin >> u;
		if (G.vertices[u - 1].data != -1) {
			temp = G.vertices[u - 1].firstarc;
			while (temp) {
				printf("%d ", temp->adjvex);
				temp = temp->next;
			}
		}
		printf("\n");
	}
}
int main() {
	ALGraph G;
	CreatALGraph(&G);
	ShowGraph(G);

	return 0;
}
