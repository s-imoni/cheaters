#include "stack_arr.h"
#include <stdlib.h>

void makeStack(Stack312 *s){
    s->top = -1;
}

bool isFull(Stack312 s){
    return (s.top == MAX_ELEMENTS - 1);
}

bool isEmpty(Stack312 s){
    return (s.top == -1);
}

void push(StackEntry e, Stack312 *s){
    s->top = (s->top) + 1;
    s->elements[s->top] = e;
}

StackEntry pop(Stack312 *s){
    StackEntry ret = s->elements[s->top];
    s->top = s->top - 1;
    return ret;
}