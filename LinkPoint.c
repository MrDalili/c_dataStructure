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

void main(void){
    LinkList * list = create(3);
    print(list);
}