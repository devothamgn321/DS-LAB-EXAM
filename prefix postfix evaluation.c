#include <stdio.h>
#include  <math.h>
#include<string.h>
#include<stdlib.h>

struct stack
 {
   float a[20];
   int top;
 };

typedef struct stack stk;

 void push(float x, stk *s)
  {
   if(s->top ==19)
    printf("Overflow!!\n");
   else
    s->top++;
   s->a[s->top]=x;
   return;
  }

 float  pop(stk *s)
  {
   float x;
   if(s->top == -1)
      printf("Underflow\n");
   else
      x=s->a[s->top];
   s->top--;
   return x;
  }

 int isoperand(char ch)
  {
    switch(ch)
    {
      case '+':
      case '-':
      case '*':
      case '/':
      case '(':
      case ')':
      case '$':
      case '^': return 0;
      default : return 1;
    }
  }

 float compute(float op1, float op2, char opr)
 {
   switch(opr)
   {
     case '+' : return(op1+op2);
     case '-' : return(op1-op2);
     case '*' : return(op1*op2);
     case '/' : return(op1/op2);
     case '^' : return pow(op1,op2);
     case '$' : return pow(op1,op2);
     default  : printf("Invalid expression\n");
        return 0;
   }
 }

 void posteval(char  po[])
 {
  float op1,op2,res;
  char ch;
  int i=0;
  stk s;
  s.top = -1;
  while((ch=po[i++]) !='\0')
   {
     if(isoperand(ch))
    push(ch-'0', &s);
     else
       {
     op2=pop(&s);
     op1=pop(&s);
     res=compute(op1, op2, ch);
     push(res,&s);
       }
   }
  res = pop(&s);
  if(s.top != -1)
     printf("Invalid expression\n");
  else
     printf("Value of the expression is %.2f\n",res);
 }

 void preeval(char pre[])
 {
  float op1,op2,res;
  char ch;
  int i=0;
  stk s;
  s.top = -1;
  i=strlen(pre)-1;
  while(i>=0)
   {
    ch=pre[i] ;
    if(isoperand(ch))
      push(ch-'0',&s);
    else
      {
       op1=pop(&s);
       op2=pop(&s);
       res=compute(op1,op2,ch);
       push(res,&s);
      }
    i--;
   }
  res=pop(&s);
  if(s.top!=-1)
     printf("Invalid Experession\n");
  else
     printf("Value of the expression is %.2f\n",res);
 }

void main()
{
 int choice;
 char exp[30];
 
 for(;;)
 {
   printf("Enter your choice\n");
   printf("1.Postfix evaluation\n2.Prefix evaluation\n3.Exit the program\n");
    scanf("%d",&choice);
   switch(choice)
     {
      case 1: printf("Enter your postfix expression:\n");
          scanf("%s",exp);
          if(strcmp(exp,"0")==0)
        {
         printf("Empty exp!!\n");
         break;
        }
          posteval(exp);
          break;
      case 2: printf("Enter your prefix expression:\n");
          scanf("%s",exp);
          if(strcmp(exp,"0")==0)
        {
         printf("Empty exp!!\n");
         break;
        }
          preeval(exp);
          break;
      default:exit(0);
     }
 }
}
 
