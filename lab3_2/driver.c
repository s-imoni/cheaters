#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack_arr.h"

bool validate(char* exp, char* missing);

int main(int argc, char** argv){
    FILE *fptr;
    fptr = fopen(argv[1], "r");
    const int MAX_LEN = 80;
    char expression[MAX_LEN];

    // Exit on error
    if(fptr == NULL){
        printf("Error in Opening File");
        exit(-1);
    }
    char ret;
    while (fgets(expression, MAX_LEN, fptr) != NULL) {
        if(expression[strlen(expression)-1] == '\n'){
            expression[strlen(expression)-1] = '\0';
        }
        if(validate(expression, &ret)){
            printf("%s === valid expression\n", expression);
        }
        else{
            printf("%s === missing %c\n", expression, ret);
        }
    }
    free(fptr);
    return 0;
}

bool validate(char* exp, char* missing){
    Stack312 *s = malloc(sizeof(Stack312));
    bool ret = true;
    makeStack(s);
    StackEntry e;
    for(int i = 0; i < strlen(exp); i++) {
        if (exp[i] == '<' || exp[i] == '{' || exp[i] == '[' || exp[i] == '(') {
            e = exp[i];
            push(e, s);
        }
        if (exp[i] == '>' || exp[i] == ']' || exp[i] == '}' || exp[i] == ')') {
            if(!isEmpty(*s)) {
                e = pop(s);
                if (!(e == '(' && exp[i] == ')') && !(e == '[' && exp[i] == ']') && !(e == '{' && exp[i] == '}') &&
                    !(e == '<' && exp[i] == '>')) {
                    ret = false;
                    if(e == '('){
                        *missing = ')';
                    }
                    if(e == '<'){
                        *missing = '>';
                    }
                    if(e == '{'){
                        *missing = '}';
                    }
                    if(e == '['){
                        *missing = ']';
                    }
                }
            }
            else{
                ret = false;
                if(exp[i] == ')'){
                    *missing = '(';
                }
                if(exp[i] == '}'){
                    *missing = '{';
                }
                if(exp[i] == '>'){
                    *missing = '<';
                }if(exp[i] == ']'){
                    *missing = '[';
                }
            }
        }
    }
    if(!isEmpty(*s) && ret == true){
        ret = false;
        char temp = pop(s);
        if(temp == '('){
            *missing = ')';
        }
        if(temp == '<'){
            *missing = '>';
        }
        if(temp == '{'){
            *missing = '}';
        }
        if(temp == '['){
            *missing = ']';
        }
    }
    free(s);
    return ret;
}