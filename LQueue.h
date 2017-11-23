//
// Created by antonio on 17-11-22.
//

#ifndef BINTREE_LQUEUE_H
#define BINTREE_LQUEUE_H

#include <stdio.h>
#include <malloc.h>
#include "bintree.h"

//队列的结构体
typedef struct qnode
{//结点数据
    BiTreeNode *data;//二叉树结点的数据
    struct qnode *next;
} LQNode;

typedef struct
{//队列整体
    LQNode *front;
    LQNode *rear;
} LQueue;
/************************改h文件有问题（通过使用c++的泛形容器得到结论）******************************/

void QueueInitiate(LQueue *Q)
{

    Q = (LQueue *) malloc(sizeof(LQueue));//申请队列空间
    Q->front = NULL;
    Q->rear = NULL;

}

int QueueNotEmpty(LQueue Q)
{
    if (Q.front->data == NULL)
    {//判断队列是否为空
        return 0;
    }
    else
    {
        return 1;
    }
}

//入队列
int QueuePush(LQueue *Q, BiTreeNode *x)
{//入队列
    LQNode *p;
    p = (LQNode *) malloc(sizeof(LQNode));
    p->data = x;
    p->next = NULL;
    if (Q->rear != NULL)
    {
        Q->rear->next = p;//队列原来非空时,在队尾加入新节点
    }
    Q->rear = p;//修改队尾指针
    if (Q->front == NULL)
    {//如果队列为空
        Q->front = p;//修改队头指针
    }
    printf(" %c\n", p->data->data);
    return 1;
}

//出队列
int QueuePop(LQueue *Q, BiTreeNode **d)
{
    //删除队列头结点并传送数据
    LQNode *p;
    if (Q->front == NULL)
    {
        printf("队列为空\n");
        return 0;
    }
    else
    {
        *d = Q->front->data;
        p = Q->front;
        Q->front = Q->front->next;//出队列节点脱链
        if (Q->front == NULL)
        {//如果队列已被删除致空
            Q->rear = NULL;//删除最后一个节点,要置队尾指针为空
        }

        free(p);
        return 1;
    }
}

int QueueGet(LQueue Q, BiTreeNode **d)
{
    if (Q.front == NULL)
    {
        printf("队列已空\n");
        return 0;
    }
    else
    {
        *d = Q.front->data;
        return 1;
    }
}

void DestoryQueue(LQueue Q)
{
    LQNode *p, *p1;
    p = Q.front;
    while (p != NULL)
    {
        p1 = p;
        p = p->next;
        free(p1);
    }
}



#endif //BINTREE_LQUEUE_H
