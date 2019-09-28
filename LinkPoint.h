//
// Created by 27548 on 2019/9/23.
//

/**
 * 链表
 * 是一种物理存储单元上非连续、非顺序的存储结构，数据元素的逻辑顺序是通过链表中的指针链接次序实现的。一般一个链表
 *      包含2个部分，数据与下一个节点的指针。
 * + 指针链表
 *      有一个头节点，一个接着一个，一个接着一个。
 *      - 单向链表
 *          一个接着一个，当前节点包含着下一个节点的指向
 *      - 双向链表
 *          一个接着一个，当前节点包含着上一个节点和下一个节点的指向
 *      - 循环链表
 *          就是在单向和双向的基础上，首位相连
 * + 数组链表
 *
 */
#ifndef CORC___LINKPOINT_H
#define CORC___LINKPOINT_H

typedef struct Node{
    struct Node * next;//下一个节点的位置
    int data;//内容
}LinkList;

LinkList * creatList(int n);//创建一个长度为n的链表
LinkList * createNode(int data);//创建一个有内容的节点
void addFront(LinkList *list ,int num);//添加节点先插
void addRear(LinkList *list ,int num);//添加节点后插
int remote(LinkList *list ,int index);//移除下标,并返回内容
void addIndex(LinkList *list ,int num,int index);//在特定下标添加节点
LinkList * copyList(LinkList *list);//拷贝链表并返回一个链表
void print(LinkList *list);//输出链表内容
int length(LinkList *list);//计算链表的长度，不算头节点，从第一个有效节点算起
#endif //CORC___LINKPOINT_H
