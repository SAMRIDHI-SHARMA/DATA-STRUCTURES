#include<stdio.h>
#define MAX 50

char stack[MAX];
int top = -1;
char ch;

void push(char data){

    top = top +1;
    stack[top] = data;
}
char pop(){
    char value;

    value = stack[top];
    top = top - 1;
    return value;
}


int priority(char operator){                                      //  ^    6  5
    if (operator == '^'){                                         //  */   3  4
        return 6;                                                 //  +-   1  2
    }
    else if ((operator == '*') || (operator == '/')){
        return 3;
    }
    else if ((operator == '+') || (operator == '-')){
        return 1;
    }
    else {
        return -1;
    }
}

int stack_precedence(char op){
    if (op == '^'){
        return 5;
    }
    else if ((op == '*') || (op == '/')){
        return 4;
    }
    else if ((op == '+') || (op == '-')){
        return 2;
    }
    else{
        return -1;
    }
}

int main(){
    char infix_exp[MAX],postfix_exp[MAX],element;
    printf("enter the infix expression: ");
    scanf("%s", infix_exp);
    push('#');
    int i =0;
    int k =0;
    while ((ch=infix_exp[i])!= '\0'){
        if (ch == '('){
            push(ch);
        }
        else if (( ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')){
            postfix_exp[k] = ch;
            k = k+1;
        }
        else if (ch == ')'){
            while(stack[top] != '('){
                postfix_exp[k]=pop();
                k = k+1;
            }
            element =pop();
            
        }
        else{
            while(priority(ch)<= stack_precedence(stack[top])){
                postfix_exp[k]=pop();
                k=k+1;
            }
            push(ch);
        }
    i=i+1;
    }    
    
    while(stack[top] != '#'){
        postfix_exp[k]=pop();
        k=k+1;
    }  
    postfix_exp[k]= '\0';
    printf("postfix expression is %s\n", postfix_exp);      

}