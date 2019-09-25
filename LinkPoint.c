//
// Created by 27548 on 2019/9/23.
//

#include "LinkPoint.h"
#include "stdlib.h"
#include "stdio.h"

/**
 * 初始一个除了头节点算长度的链表，并赋值
 */
LinkList * create(int length){
    LinkList * node, * first ,* end;//定义头节点和普通节点
    first = (LinkList*)malloc(sizeof(LinkList));
    end = first;
    //初始化个数，并输入相应的数值
    for (int i = 0; i < length; ++i) {
        node = (LinkList*)malloc(sizeof(LinkList));
        scanf_s("%d",&node->data);
        end->next = node;
        //让新加的节点成为最后一个节点
        end = node;
    }
    //给终点封闭一下
    end->next=NULL;
    return first;
};

/**
 * 打印链表中的元素
 */
void print(LinkList *list){
    list = list->next;
    //看看是不是空链表,是的话直接输出空括号
    if (list == NULL){
        printf("[]\n");
        return ;
    }
    //不是空链表
    printf("[");
    while (1){
        //我就看看是不是最后一个节点
        LinkList * node = list->next;//往后面走一个
        if(node == NULL){
            //最后一个节点
            printf("%d]\n",list->data);
            break;
        } else{
            //后面的节点不空那就不是最后一点节点
            printf("%d,",list->data);
            list = node;
        }
    }
}

/**
 *  找到最后一个节点并连接上
 */
void addRear(LinkList *list ,int num) {
    //后插,找到最后一个节点然后插上去
    while(list->next != NULL){
        list = list->next;
    }
    LinkList * node = (LinkList*)malloc(sizeof(LinkList));
    node->next=NULL;
    node->data=num;
    list->next = node;
}

/**
 * 将头节点的next赋值给新节点的指向，将头节点的next指向新节点
 */
void addFront(LinkList *list ,int num){
    //先将新节点分配出来
    LinkList* node = (LinkList*)malloc(sizeof(LinkList));
    node->data=num;
    node->next = list->next;
    list->next = node;
}

/**
 * 删除链表对应下标的节点并输出对应的值
 * 得要有2个节点，一个节点指向被删除的元素的前面一个，一个指向被删除的节点
 */
int remote(LinkList *list ,int index){
    LinkList *pre,*cur;//一个是前一个节点，一个是当前节点
    //看是不是只有一个元素,如果只有一个头节点 就报错吧
    if (list->next == NULL){
        return NULL;
    }
    //指向第一个有值的节点
    cur = list->next;
    pre = list;
    //将cur移动到要删除的元素那里，pre放在cur的前面
    for (int i = 0; i < index; i++) {
        if(cur == NULL){
            //如果当前节点是空，那就说明传来的下标有问题，报错
            return NULL;
        }
        pre = cur;
        cur = cur->next;
    }
    //把当前节点从中间给他断开
    pre->next = cur->next;
    cur->next = NULL;

    return cur->data;
}

void main(void){
    LinkList * list = create(3);
    addFront(list,1);
    addRear(list,10);
    print(list);
    remote(list,0);
    print(list);
    remote(list,3);
    print(list);
    remote(list,1);
    print(list);
    remote(list,0);
    remote(list,0);
    print(list);
    remote(list,0);
    print(list);
}