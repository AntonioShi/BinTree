//
// Created by antonio on 17-11-20.
//
//层序遍历是二叉树与队列的结合使用
#ifndef BINTREE_BINTREE_H
#define BINTREE_BINTREE_H

#include <stdio.h>
#include <malloc.h>


typedef char DataType ;

typedef struct Node{
    DataType data ;
    struct Node *leftChild ;
    struct Node *rightChild ;
} BiTreeNode;

//初始化
void Initiate(BiTreeNode **root){
    //初始化建立二叉树的头节点
    *root = (BiTreeNode *)malloc(sizeof(BiTreeNode)) ;
    (*root)->leftChild = NULL ;
    (*root)->rightChild = NULL ;
}

//左插入节点
//若当前结点curr非空，则在curr左子树插入元素值为x的新节点
//原curr所指结点的左子树成为新插入结点的左子树
//若插入成功，则返回新插入结点的指针，否则返回空指针
BiTreeNode* InsertLeftNode(BiTreeNode *curr, DataType x){

    BiTreeNode *s, *t ;
    if (curr == NULL)
        return NULL ;
    t = curr->leftChild ;//暂为保管地址
    s = (BiTreeNode *)malloc(sizeof(BiTreeNode)) ;//新节点
    s->data = x ;
    s->leftChild = t ;
    s->rightChild = NULL ;
    curr->leftChild = s ;//链接成功

    return curr->leftChild ;
}

//右插入结点
/*
 * 若当前结点curr非空，则在curr右子树插入元素值为x的新节点
 * 原curr所指结点的右子树成为新插入结点的右子树
 * 若插入成功，则返回新插入结点的指针，否则返回空指针
 */
BiTreeNode* InsertRightNode(BiTreeNode *curr, DataType x){

    BiTreeNode *s, *t ;
    if (curr == NULL)
        return NULL ;
    t = curr->rightChild ;//暂为保管地址
    s = (BiTreeNode *)malloc(sizeof(BiTreeNode)) ;//新节点
    s->data = x ;
    s->rightChild = t ;
    s->leftChild = NULL ;
    curr->rightChild = s ;//链接成功

    return curr->leftChild ;
}

//删除左子树
/*
 * 若curr非空，则在curr右子树插入元素值为x的新节点
 * 若删除成功，则返回删除结点的双亲结点指针，否则返回空指针
 */
BiTreeNode* DeleteLeftTree(BiTreeNode *curr){

    if (curr == NULL || curr->leftChild == NULL)
        return NULL ;
    //Destory(&curr->leftChild) ;
    curr->leftChild = NULL ;

    return curr ;
}


//删除右子树
#endif //BINTREE_BINTREE_H
BiTreeNode* DeleteRightTree(BiTreeNode *curr){

    if (curr == NULL || curr->rightChild == NULL)
        return NULL ;
    //Destory(&curr->rightChild) ;
    curr->rightChild = NULL ;

    return curr ;
}

//二叉树的遍历（递归的实现方法）
//前序遍历                        函数虚参
void PreOrder(BiTreeNode *root, void visit(DataType item)){
    //DLR
    if (root != NULL){
        visit(root->data) ;
        PreOrder(root->leftChild, visit) ;//DLR
        PreOrder(root->rightChild, visit) ;
    }

}
/*
 * int (*a)(int)
 * a指向函数的指针：函数指针
 * void func(int (*a)(int)){
    int r = 100l;
    (*a)(r);
}
 */

//中序遍历
void InOrder(BiTreeNode *root, void visit(DataType item)){
    if (root != NULL){
        InOrder(root->leftChild, visit) ;
        visit(root->data) ;
        InOrder(root->rightChild, visit) ;//LDR
    }
}

//后序遍历
void PostOrder(BiTreeNode *root, void visit(DataType item)){
    if (root != NULL){
        PreOrder(root->leftChild, visit) ;
        PreOrder(root->rightChild, visit) ;//LRD
        visit(root->data) ;
    }
}



//查找数据元素
BiTreeNode* Search(BiTreeNode *root, DataType x){
    BiTreeNode *find = NULL ;
    if(root != NULL){
        if(root->data == x){
            find = root ;
        }
        else{
            find = Search(root->leftChild, x) ;
            if(find == NULL)
                find = Search(root->rightChild, x) ;
        }
    }
    return find ;
}

//撤销
void Destory(BiTreeNode **root){
    if ((*root) != NULL && (*root)->leftChild != NULL){
        Destory(&(*root)->leftChild) ;
    }

    if ((*root) != NULL && (*root)->rightChild != NULL){
        Destory(&(*root)->rightChild) ;
    }

    free(*root) ;
}


void visit(DataType item){
    printf("%4c ", item) ;
}

