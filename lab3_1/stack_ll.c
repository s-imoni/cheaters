#include "stack_ll.h"
#include <stdlib.h>

void makeStack(Stack312 *s){
    s->top = NULL;
}

bool isFull(Stack312 s){
   return false;
}

bool isEmpty(Stack312 s){
    bool ret = false;
    if(s.top == NULL){
        ret = true;
    }
    return ret;
}

void push(StackEntry e,Stack312 *s){
    StackNode *temp = (StackNode*) malloc(sizeof(StackNode));
    temp->pixel = e;
    temp->next = s->top;
    s->top = temp;
}

StackEntry pop(Stack312 *s){
    StackNode *ret;
    ret = s->top;
    StackEntry val = ret->pixel;
    free(s->top);
    s->top = s->top->next;
    return val;
}