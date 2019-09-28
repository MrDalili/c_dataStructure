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
    if (length == 0){
        //需要一个空链表,或者是一个新节点
        LinkList * node, * first ,* end;//定义头节点和普通节点
        first = (LinkList*)malloc(sizeof(LinkList));
        first->next = NULL;
        first->data = NULL;
    }
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

    //如果一开始就是空链表的话
    if (list == NULL){
        return;
    }
    LinkList * node;
    node = list->next;
    //看看是不是空链表,是的话直接输出空括号
    if (node == NULL){
        printf("[]\n");
        return ;
    }
    //不是空链表
    printf("[");
    while (1){
        //我就看看是不是最后一个节点
        LinkList * last = node->next;//往后面走一个
        if(last == NULL){
            //最后一个节点
            printf("%d]\n",node->data);
            break;
        } else{
            //后面的节点不空那就不是最后一点节点
            printf("%d,",node->data);
            node = last;
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

/**
 * 找到对应节点的位置添加即可,前插
 */
void addIndex(LinkList *list ,int num,int index){
    LinkList * node,* cur,* pre ;
    node = (LinkList*)malloc(sizeof(LinkList));
    node->data = num;
    //找2个节点，一个是cur，一个是pre
    cur = list->next;
    pre = list;
    //遍历到index的位置
    for (int i = 0; i < index; i++) {
        if (cur == NULL){
            return;
        }
        pre = cur;
        cur = cur->next;
    }
    node->next = pre->next;
    pre->next = node;
}

/**
 * 复制一个长得一摸一样的链表,那就是从头开始就好了
 */
LinkList * copyList(LinkList *list){
    LinkList * copyList = create(0);//返回一个头指针
    LinkList *cur,*copyCur,*node;//一个指向要拷贝的链表的头节点，一个指向要复制的链表，一个拟定为新的节点

    cur = list->next;//指向下一个
    copyCur = copyList;//新List的当前节点
    //当cur指向空的时候，表明已经到末尾节点了
    while(cur != NULL){
        node = (LinkList*)malloc(sizeof(LinkList));
        //如果不为空，那就直接往需要加长度的链表尾端加一个元素就好了
        node->data = cur->data;//把要赋值的内容放在新节点里面
        copyCur->next = node;//上一个节点指向新节点
        cur = cur->next;//指向下一个节点
        copyCur = copyCur->next;//指向下一个节点
    }
    //到这里说明cur已经到最后一个节点后面的那个NULL节点了，但是copyCur指向的为最后一个节点，最后一个节点指向一个不知道的内存，需要设为NULL
    node->next = NULL;
    //返回复制的链表
    return copyList;
}
/**
 * 从第二个节点开始便利，遍历到NULL节点即可
 */
int lengthOfList(LinkList *list){
    int length = 0;//先初始化长度为0
    LinkList * cur = list->next;//指向第一个有效元素
    while(cur != NULL){
        length++;
        cur = cur->next;
    }
    //返回长度
    return length;
}

void main(void){
    LinkList * list = create(3);
    print(list);
    addIndex(list,100,2);
    print(list);
    int length = lengthOfList(list);
    printf("%d\n",length);
    LinkList * new = copyList(list);
    print(new);
}