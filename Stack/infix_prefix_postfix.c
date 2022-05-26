#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct stud{
    char ch;
    struct stud* next;
}Stack;

void push(Stack** stack, char ch){
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->ch = ch;
    s->next = NULL;

    if((*stack) == NULL){
        (*stack) = s;
    }else{
        Stack *ptr = (*stack);
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = s;
    }
}
char pop(Stack** stack){
    char elm;
    if((*stack)->next == NULL){
        elm = (*stack)->ch;
        (*stack) = NULL;
    }else{
        Stack* ptr = (*stack);
        while(ptr->next->next != NULL){
            ptr = ptr->next;
        }
        elm = ptr->next->ch;
        ptr->next = NULL;
    }
    return elm;
}
char top(Stack* stack){
    Stack* ptr = stack;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    return ptr->ch;
}

int isOperator(char ch){
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}
int isOperand(char ch){
    return ((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9'));
}
int prec(char ch){
    if(ch == '+' || ch == '-') return 1;
    else if(ch == '*' || ch == '/' || ch == '%') return 2;
    else if(ch == '^') return 3;
    else return 0;
}
int valid(char* str){
    Stack* st = NULL;
    for(int i=0; i<strlen(str); i++){
        if(str[i] == '(' || str[i] == '{' || str[i] == '['){
            push(&st, str[i]);
            continue;
        }
        if ((str[i] == ')' && top(st) == '(') || (str[i] == '}' && top(st) == '{') || (str[i] == ']' && top(st) == '[')){
            pop(&st);
        }
    }
    if(st == NULL){
        return 1;
    }
    return 0;
}

char* to_postfix(char* infix){
    Stack* stack = NULL;
    char* postfix = (char*)malloc(strlen(infix) * sizeof(char));
    int i=0, j=0;
    while(i < strlen(infix)){
        char ch = infix[i++];
        if(ch == '(' || ch == '{' || ch == '['){
            push(&stack, ch);
        }else if(isOperator(ch)){
            while(stack != NULL && isOperator(top(stack)) && prec(ch) <= prec(top(stack))){
                postfix[j++] = pop(&stack);
            }
            push(&stack, ch);
        }else if(ch == ')'){
            char elm;
            while((elm = pop(&stack)) != '('){
                postfix[j++] = elm;
            }
        }else if(ch == '}'){
            char elm;
            while((elm = pop(&stack)) != '{'){
                postfix[j++] = elm;
            }
        }else if(ch == ']'){
            char elm;
            while((elm = pop(&stack)) != '['){
                postfix[j++] = elm;
            }
        }else if(isOperand(ch)){
            postfix[j++] = ch;
        }
    }
    while(stack != NULL){
        postfix[j++] = pop(&stack);
    }
    postfix[j] = '\0';
    return postfix;
}

char* to_prefix(char* infix){
    Stack* stack = NULL;
    char* prefix = (char*)malloc(strlen(infix) * sizeof(char));
    int i=strlen(infix), j=0;
    while(i--){
        char ch = infix[i];
        if(ch == ')' || ch == '}' || ch == ']'){
            push(&stack, ch);
        }else if(isOperator(ch)){
            while(stack != NULL && isOperator(top(stack)) && prec(ch) <= prec(top(stack))){
                prefix[j++] = pop(&stack);
            }
            push(&stack, ch);
        }else if(ch == '('){
            char elm;
            while((elm = pop(&stack)) != ')'){
                prefix[j++] = elm;
            }
        }else if(ch == '{'){
            char elm;
            while((elm = pop(&stack)) != '}'){
                prefix[j++] = elm;
            }
        }else if(ch == '['){
            char elm;
            while((elm = pop(&stack)) != ']'){
                prefix[j++] = elm;
            }
        }else if(isOperand(ch)){
            prefix[j++] = ch;
        }
    }
    while(stack != NULL){
        prefix[j++] = pop(&stack);
    }
    prefix[j] = '\0';
    return strrev(prefix);
}

int main(){
    char choice;
    char* infix = (char*)malloc(sizeof(char) * 21);
    printf("Enter your infix expression(max length 20): ");
    gets(infix);

    if(valid(infix)){
        printf("Enter 1 to for prefix or 2 for postfix or 3 for both: ");
        scanf(" %c",&choice);

        if(choice == '1'){
            printf("Prefix expression is: %s\n", to_prefix(infix));
        }else if(choice == '2'){
            printf("Postfix expression is: %s\n", to_postfix(infix));
        }else if(choice == '3'){
            printf("Prefix expression is: %s\n", to_prefix(infix));
            printf("Postfix expression is: %s\n", to_postfix(infix));
        }else{
            exit(0);
        }
    }else{
        printf("This is not a valid infix expression.\n");
    }
    return 0;
}