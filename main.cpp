//
// Created by antonio on 17-11-22.
//
/* 二叉树的建立、遍历及其应用
 * 设树结点的元素类型为char，实现以下二叉树的各种基本操作的程序：
 * ① 建立不少于10个结点的二叉树T；
 * ② 用非递归方式先序遍历方式输出树T的结点；
 * ③ 用非递归方式中序遍历方式输出树T的结点；
 * ④ 用后序遍历方式输出树T的结点；
 * ⑤ 用层次遍历方式输出树T的结点；
 * ⑥ 输出树T的深度；
 * ⑦ 输出树T的叶子结点和非叶子结点；
 * ⑧ 主函数通过函数调用实现以上各项操作。
 */

#include <stdio.h>
#include "LQueue.h"
#include <queue>
#include <stack>
#include <iostream>
using namespace std;
int NumNode = 0 ;//结点总数
int LeaveNode = 0 ;//叶结点总数
int Height = 0 ;//高度

//层序遍历
void HierachyOrder(BiTreeNode *root) {

    if (root == NULL)
        return;
    queue<BiTreeNode *> Q;//生成队列
    BiTreeNode *p = root;//没有数据，不用输出

    if (p->leftChild)
        Q.push(p->leftChild);
    if (p->rightChild)
        Q.push(p->rightChild);

    while (!Q.empty())
    {//出队列：队列非空
        p = Q.front();
        Q.pop();

        printf("%c  ", p->data);
        NumNode++ ;
        if (p->leftChild)
            Q.push(p->leftChild);
        if (p->rightChild)
            Q.push(p->rightChild);
    }

}

//二叉树遍历（非递归）

void DLR(BiTreeNode *root){
//对于非递归式的前序遍历，使用队列几乎是无法实现的，因为队列的特性如此。
//所以，极度建议使用栈
    if (!root)
        return;
    stack <BiTreeNode *> S ;
    BiTreeNode *p = root ;

    S.push(p) ;
    while (!S.empty()){
        p = S.top() ;//出栈顶
        cout <<p->data << " " ;
        S.pop() ;

        if (p->rightChild)
            S.push(p->rightChild) ;
        if (p->leftChild)
            S.push(p->leftChild) ;

    }
    cout << endl ;
}

/*回溯算法
 * void preOrderIter2(struct node *root){
    stack<struct node *> s;
    while (root != NULL || !s.empty()) {
        if (root != NULL) {
            cout << root->data << " "; //访问结点并入栈
            s.push(root);
            root = root->left;         //访问左子树
        } else {
            root = s.top();            //回溯至父亲结点
            s.pop();
            root = root->right;        //访问右子树
        }
    }
    cout << endl;
}
 */

void LDR(BiTreeNode *root) {
    stack<BiTreeNode *> s;
    while (root != NULL || !s.empty()) {
        if (root != NULL) {
            s.push(root);
            root = root->leftChild ;
        }
        else {
            root = s.top();
            cout << root->data << " ";  //访问完左子树后才访问根结点
            s.pop();
            root = root->rightChild ;        //访问右子树
        }
    }
    cout << endl;
}

void LRD(BiTreeNode *root) {
    if (!root) return;
    stack<BiTreeNode *> s, output;
    s.push(root);
    while (!s.empty()) {
        BiTreeNode *curr = s.top();
        output.push(curr);
        s.pop();
        if (curr->leftChild)
            s.push(curr->leftChild);
        if (curr->rightChild)
            s.push(curr->rightChild);
    }

    while (!output.empty()) {
        cout << output.top()->data << " ";
        output.pop();
    }
    cout << endl;
}

int BTreeLeaves(BiTreeNode *cur) {
    //当为空时，返回0；当找到叶子时返回1
    if (!cur) return 0;
    else if (!cur->leftChild && !cur->rightChild)
        return 1;
    else
        return BTreeLeaves(cur->leftChild) + BTreeLeaves(cur->rightChild);
}

int BTreeHeight(BiTreeNode *cur) {
    if (!cur) return 0;
    else {
        //二叉树的高度为左右子树的最大者+1
        int leftHei = BTreeHeight(cur->leftChild);
        int rightHei = BTreeHeight(cur->rightChild);
        return (leftHei > rightHei) ? leftHei + 1 : rightHei + 1;
    }
}

int main() {
//
    BiTreeNode *root, *p ;
    Initiate(&root) ;
    p = InsertLeftNode(root, 'A') ;
    p = InsertLeftNode(p, 'B') ;
    p = InsertLeftNode(p, 'D') ;
    InsertLeftNode(p, 'G') ;
    p = InsertRightNode(p, 'H') ;
    p = InsertRightNode(root->leftChild, 'C') ;
    InsertLeftNode(p, 'E') ;
    p = InsertRightNode(p, 'F') ;
    InsertLeftNode(p, 'I') ;
    InsertRightNode(p, 'J') ;


    printf("层序遍历二叉树\n") ;
    HierachyOrder(root);
    cout << "\n前序遍历：" << endl ;
    DLR(root->leftChild) ;
    cout << "中序遍历：" << endl ;
    LDR(root->leftChild) ;
    cout << "后序遍历：" << endl ;
    LRD(root->leftChild) ;

    LeaveNode = BTreeLeaves(root) ;//求叶子数目
    Height = BTreeHeight(root) ;//二叉树高度
    cout << "\n总结点数：" << NumNode << " 叶子结点总数 : " << LeaveNode << " 树的高度：" << Height << endl;
    printf("\n撤销树\n") ;
    Destory(&root) ;
    return 0;
}
