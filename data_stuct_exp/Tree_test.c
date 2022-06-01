#include <stdio.h>
#include <stdlib.h>
#define MAX 50
typedef struct Treeline

{
    char Tree_data;
    struct Treeline *l_child;
    struct Treeline *r_child;
    int num;
} TreeLine;

typedef struct LINE
{
    TreeLine *data[MAX];
    int front, tail;
} LINE;

TreeLine *creat_tree_Init() 
{
    TreeLine *T;
    char t;
    scanf("%c", &t);
    getchar();
    if (t == '#')
    {
        T = NULL;
    }
    else
    {
        T = (TreeLine *)malloc(sizeof(TreeLine));
        T->Tree_data = t;
        printf("请输入%c的左孩子:\n", t);
        T->l_child = creat_tree_Init();
        printf("请输入%c的右孩子:\n", t);
        T->r_child = creat_tree_Init();
    }
    return T;
}

LINE creat_line(LINE *line)
{
    line = (LINE *)malloc(sizeof(LINE));
    line->front = line->tail = NULL;
}

void in_line(LINE *line, TreeLine tree)
{
    if (((line->tail + 1) % MAX) == (line->front))
    {
        printf("队列已满，无法入队！\n");
    }
    else
    {
        line->data[line->tail] = tree.Tree_data;
        line->tail = ((line->tail + 1) % MAX);
    }
}

void out_line(LINE *line)
{
    if (line->front == line->tail)
    {
        printf("队列Q为空 \n");
    }
    else
    {
        char d;
        d = line->data[line->front];
        line->data[line->front] = 0;
        line->front = (line->front + 1) % MAX;
        printf("出队节点%c \n", d);
    }
}

void behind_select(TreeLine *T)
{

    if (T)
    {
        behind_select(T->l_child);
        behind_select(T->r_child);
        printf("%c", T->Tree_data);
    }
}

void Normal_select(TreeLine *T)
{
    if (T)
    {
        printf("%c", T->Tree_data);
        Normal_select(T->l_child);
        Normal_select(T->r_child);
    }
}

void find_depth()
{
}

void classify_points()
{
}

int main()
{

    TreeLine *T;
    printf("录入节点数据：\n");
    for (int i = 0; i < 10; i++)
    {
        T = creat_tree_Init();
    }
    printf("后序遍历输出：\n");
    behind_select(T);
}
