//
// Created by 27548 on 2019/9/23.
//

#include "LinkPoint.h"
#include "stdlib.h"
#include "stdio.h"

LinkList * create(int length){
    LinkList * node, * first ,* end;//定义头节点和普通节点
    first = (LinkList*)malloc(sizeof(LinkList));
    end = first;
    for (int i = 0; i < length; ++i) {
        node = (LinkList*)malloc(sizeof(LinkList));
        scanf_s("%d",&node->data);
        end->next = node;
        end = node;
    }
    end->next=NULL;
    return first;
};

void print(LinkList *list){
    printf("[");
    list = list->next;
    while (1){
        //我就看看是不是最后一个节点
        LinkList * node = list->next;//往后面走一个
        if(node == NULL){
            //最后一个节点
            printf("%d]",list->data);
            break;
        } else{
            //后面的节点不空那就不是最后一点节点
            printf("%d,",list->data);
            list = node;
        }
    }
}

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

void main(void){
    LinkList * list = create(3);
    addFront(list,1);
    addRear(list,10);
    print(list);
}