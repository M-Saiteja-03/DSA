#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int top=-1;
char*infix="a+b";
char stack[100];
char*postfix;
void push(char value){
    if(top==strlen(infix)-2){
        printf("stack overflow\n");
    }
    else{
        stack[++top]=value;
    }
}
char pop(){
    if(top==-1){
        printf("stack underflow");
    }
    else{
        return stack[top--];
    }
}
int precedence(char value){
    if(value=='*'||value=='/'){
        return 2;
    }
    else if (value=='+'||value=='-')
    {
        return 1;
    }
    else{
        return 0;
    }
    
}
char* InfixtoPostfix(char * infix){
    postfix=(char*)malloc((strlen(infix)+1)*sizeof(char));
    int i=0;
    int j=0;
    while(infix[i]!='\0'){
        if(isalnum(infix[i])){
            postfix[j]=infix[i];
            i++;
            j++;
        }
        // else if(isoperator(infix[i])){
        //     push(infix[i]);
        //     i++;
        // }
        else if(infix[i]=='('){
            push(infix[i]);
            i++;
        }
        else if(infix[i]==')'){
            while(1){
                if(infix[i]!='('){
                    postfix=pop();
                }
            }
        }
        else{
            if(precedence(stack[top])<precedence(infix[i])){
                push(infix[i]);
                i++;
            }
            else{
                postfix=pop();
                j++;
            }
        }
    }
    while (top!=-1)
    {
        postfix[j]=pop();
        j++;
    }
    postfix[j]='\0';
    return postfix;


}
int main()
{
    char*infix="K + L - M*N";
    printf("Infix:%s\n",infix);
    postfix=InfixtoPostfix(infix);
    printf("Postfix:%s",postfix);
    return 0;
}