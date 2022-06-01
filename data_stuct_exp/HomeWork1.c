/************************** Dongguan-University of Technology -ACE**************************
 * @file HomeWork1.c
 * @author pansyhou侯文辉 (1677195845lyb@gmail.com)
 * @brief 
    1. 用邻接矩阵作为储结构存储图G并输出该邻接矩阵；
    2. 用邻接链表作为储结构存储图G并输出该邻接链表；
    3. 按DFS算法输出图G中顶点的遍历序列；
    4. 按BFS算法输出图G中顶点的遍历序列；
    5. 主函数通过函数调用实现以上各项操作。
 * @version 0.1
 * @date 2022-06-01
 * 
 * @copyright Copyright (c) 2022
 * 
 ************************** Dongguan-University of Technology -ACE***************************/
#include "stdio.h"
#include "stdlib.h"

#define MAX_VEX 3 //最大顶点数

/**********邻接矩阵宏定义**********/
#define VexType char //顶点向量，类型可自定义，
#define AdjType int  //邻接矩阵,权值类型可自定义

/**********邻接表宏定义**********/
#define InfoType int // 与边或弧相关的信息, 如权值

typedef struct
{
    int vexnum, arcnum;            /*  图的当前顶点数和弧数  */
    VexType vexs[MAX_VEX];         /*  顶点向量组  */
    AdjType adj[MAX_VEX][MAX_VEX]; //邻接矩阵,
} MGraph;

/*  表结点类型定义   */
typedef struct LinkNode
{
    int adjvex;               // 邻接点在头结点数组中的位置(下标)
    InfoType info;            // 与边或弧相关的信息, 如权值
    struct LinkNode *nextarc; // 指向下一个表结点
} LinkNode;

/*  顶点结点类型定义   */
typedef struct VexNode
{
    VexType data;       // 顶点信息
    int indegree;       // 顶点的度, 有向图是入度或出度或没有
    LinkNode *firstarc; // 指向第一个表结点
} VexNode;

/*  图的结构定义   */
typedef struct
{
    int vexnum;               //图的当前顶点数
    int visited[MAX_VEX];     //访问标志数组,for DFS、BFS
    VexNode AdjList[MAX_VEX]; //顶点表
} ALGraph;

/***********图的实现***********/

//邻接矩阵初始化
void InitGraph(MGraph *G)
{
    int i, j;
    G->vexnum = 0; //初始化顶点数
    G->arcnum = 0; //初始化弧数
    for (i = 0; i < MAX_VEX; i++)
    {
        for (j = 0; j < MAX_VEX; j++)
        {
            if (i == j)
                G->adj[i][j] = 0;
            else
                G->adj[i][j] = INT_MAX;//初始化为无穷大
        }
    }
}

//插入顶点
void InsertVertex(MGraph *G, VexType Vertex)
{
    if (G->vexnum > MAX_VEX)
    {
        printf("顶点已满");
        return;
    }
    G->vexs[G->vexnum++] = Vertex;
}

//插入边
void InsertEdge(MGraph *G, int v1, int v2, int weight)
{
    if (G->vexnum < v1 || G->vexnum < v2||v1<0||v2<0)
    {
        printf("顶点不存在");
        return;
    }
    G->adj[v1][v2] = weight;
    G->arcnum++;
}

//删除边
void DelEdge(MGraph *G, int v1, int v2)
{
    if(G->vexnum < v1 || G->vexnum < v2||v1<0||v2<0)//处理越界
    {
        printf("参数错误");
        return;
    }
    if(G->adj[v1][v2]==INT_MAX||v1==v2)//处理越界
    {
        printf("该边不存在");
        return;
    }
    G->adj[v1][v2]=INT_MAX;
    G->arcnum--;
}

//图的创建
void CreatGraph(MGraph *G)
{
    //先插入顶点
    for(int i=0;i<MAX_VEX;i++)
    {
        printf("请输入第%d个顶点的值:",i+1);
        scanf(" %c",&G->vexs[i]);
        InsertVertex(G,G->vexs[i]);
    }
    for(int i=0;i<G->vexnum;i++)
    {
        for(int j=0;j<G->vexnum;j++)
        {
            if(i==j)
                continue;//跳过对角线
            printf("请输入第%d个顶点和第%d个顶点的权值:",i+1,j+1);
            scanf("%d",&G->adj[i][j]);
            InsertEdge(G,i,j,G->adj[i][j]);
        }
    }
}

//输出邻接矩阵
void PrintMgraph(MGraph *G)
{
    for(int i=0;i<G->vexnum+1;i++)
    {
        for(int j=0;j<G->vexnum+1;j++)
        {
            if(i==0&&j==0)printf("\t");
            else if(i==0&&j!=0)printf("%c\t",G->vexs[j-1]);//输出一个好看的矩阵将第一行和第一列化为顶点的信息
            else if(i!=0&&j==0)printf("%c\t",G->vexs[i-1]);
            else {
                printf("%d\t",G->adj[i-1][j-1]);
            }
        }
        printf("\n");
    }
}
//输出邻接表
void PrintAlgraph(ALGraph *G)
{
    for(int i=0;i<G->vexnum;i++)
    {
        printf("%c ",G->AdjList[i].data);
        LinkNode *p=G->AdjList[i].firstarc;
        while (p!=NULL)
        {
            printf("->");
            printf(" %c (weight=%d)",G->AdjList[p->adjvex].data,p->info);
            p=p->nextarc;
        }
        printf("\n");
    }
}

//邻接矩阵转换为邻接表
void MGraphToALGraph(MGraph *G, ALGraph *AL)
{
    int i, j;
    AL->vexnum = G->vexnum;
    //初始化邻接表
    for (i = 0; i < MAX_VEX; i++)
    {
        AL->AdjList[i].data = G->vexs[i];
        AL->AdjList[i].indegree = 0;        //初始化入度
        AL->AdjList[i].firstarc = NULL;     //第一个表结点先为空
        AL->visited[i] = 0;                 //初始化访问标志
    }
    //每个顶点计算相连的边，加入LinkNode，
    for (i = 0; i < G->vexnum; i++)
    {
        for (j = 0; j < G->vexnum; j++)
        {
            if (G->adj[i][j] != INT_MAX)
            {
                LinkNode *p = (LinkNode *)malloc(sizeof(LinkNode));
                p->adjvex = j;                          //下标            
                p->info = G->adj[i][j];                 //权值
                //（头插法，将新建的p看作新的头，p->next连接旧头）
                p->nextarc = AL->AdjList[i].firstarc;   //插入到链表头
                AL->AdjList[i].firstarc = p;            //更新链表头
                AL->AdjList[j].indegree++;              //度数++
            }
        }
    }
    return;
}

//dfs算法遍历顶点
void DFS(ALGraph *G, int v)
{
    LinkNode *p;
    G->visited[v] = 1;
    printf("%c ", G->AdjList[v].data);
    p = G->AdjList[v].firstarc;
    while (p != NULL)
    {
        if (G->visited[p->adjvex] == 0)
            DFS(G, p->adjvex);
        p = p->nextarc;
    }
}

//清楚访问标志
void ClearVisited(ALGraph *G)
{
    for (int i = 0; i < G->vexnum; i++)
        G->visited[i] = 0;
}

//bfs算法遍历顶点
void BFS(ALGraph *G, int v)
{
    LinkNode *p;
    int i;
    G->visited[v] = 1;
    printf("%c ", G->AdjList[v].data);
    p = G->AdjList[v].firstarc;
    while (p != NULL)
    {
        if (G->visited[p->adjvex] == 0)
        {
            G->visited[p->adjvex] = 1;
            printf("%c ", G->AdjList[p->adjvex].data);
        }
        p = p->nextarc;
    }
    for (i = 0; i < G->vexnum; i++)
    {
        if (G->visited[i] == 0)
            BFS(G, i);
    }
}

int main(void)
{
    MGraph *MGraph=malloc(sizeof(MGraph));
    ALGraph *ALGraph1=malloc(sizeof(ALGraph));

    //初始化邻接矩阵
    InitGraph(MGraph);
    //初始化邻接表
    CreatGraph(MGraph);
    //输出邻接矩阵
    PrintMgraph(MGraph);
    printf("\n");
    //转换为邻接表
    MGraphToALGraph(MGraph,ALGraph1);
    //输出邻接表
    PrintAlgraph(ALGraph1); 
    //dfs算法遍历顶点
    printf("dfs遍历顶点：");
    DFS(ALGraph1,0);
    printf("\n");
    //清楚访问标志
    ClearVisited(ALGraph1);
    //bfs算法遍历顶点
    printf("bfs遍历顶点：");
    BFS(ALGraph1,0);
    printf("\n");
    return 1;
}