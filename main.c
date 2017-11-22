#include <stdio.h>
#include "LQueue.h"

int main() {

    BiTreeNode *root, *p ;
    Initiate(&root) ;
    p = InsertLeftNode(root, 'A') ;
    p = InsertLeftNode(p, 'B') ;
    p = InsertLeftNode(p, 'D') ;
    p = InsertRightNode(p, 'G') ;
    p = InsertRightNode(root->leftChild, 'C') ;
    InsertLeftNode(p, 'E') ;
    InsertRightNode(p, 'F') ;


    PreOrder(root->leftChild, visit) ;//因为前中后三种遍历的顺序L都在R前面，且对于D只是访问它的数据，不影响指针问题，所以首次调用传入左孩子
    printf("\nHello, World!\n");
    HierachyOrder(root) ;
    printf("层序遍历二叉树\n") ;


    printf("撤销树\n") ;
    Destory(&root) ;
    return 0;
}