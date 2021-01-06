#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stk1
{
  char item[20];
  int top;
};
typedef struct stk1  Oprstk;
struct stk2
{
  char item[10][20];
  int top;
};

typedef struct stk2  Opndstk;
void push(char c, Oprstk *s)
{
  if(s->top ==19)
   printf("stack full\n");
  else
 s->top++;
  s->item[s->top] = c;
}

char pop(Oprstk *s)
 {
    char c;
   if(s->top ==-1)
   printf("stack empty\n");
  else
   c = s->item[s->top];
    s->top--;
 return c;
}
void push1(char c[], Opndstk *s)
{
  if(s->top ==19)
   printf("stack full\n");
  else
 s->top++;
  strcpy(s->item[s->top], c);
}

char* pop1(Opndstk *s)
 {
    char *c; //  char c[10]
   if(s->top ==-1)
   {
   printf("stack empty\n");
	}
  else

   c = s->item[s->top];
    s->top--;
 return c;

}
void par(Oprstk *oprtr, Opndstk *opnd)
{
  char *op1, *op2, opr, t[2], pexp[20];
   opr = pop(oprtr);
   t[0] = opr;
   t[1]='\0';
    op2=pop1(opnd);
    op1=pop1(opnd);
    strcpy(pexp,t);
    strcat(pexp,op1);
    strcat(pexp,op2);
    push1(pexp, opnd);
}




int isoperand(char c)
{
   switch(c)
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

int stkprc(char c)
{
   switch(c)
{
   case '+':
  case '-': return 2;
   case '*':
   case '/':  return 4;
  case '$':
  case '^': return 6;
  case '(': return 0;
 }
}

int inprc(char c)
{
 switch(c)
{
   case '+':
  case '-': return 1;
   case '*':
   case '/':  return 3;
  case '$':
  case '^': return 7;
  case '(': return 8;
   case ')': return 0;
 }
}

void inpre(char in[], char pre[])
{
  Oprstk s;
  Opndstk s1;
char c,temp[2];
  int i=0;
  s.top = -1;
  s1.top=-1;
  while((c =in[i++]) !='\0')
{
  if(isoperand(c))
   {
     temp[0]= c;
     temp[1]='\0';
      push1(temp,&s1);
  }


    else
     {
      while(s.top != -1 && stkprc(s.item[s.top]) > inprc(c))
	{
	   if(c ==')')
	    {
		while(s.item[s.top] !='(')
		       par(&s,&s1);
			// po[j++] = pop(&s);
			pop(&s);
			break;
	     }
	  else
	    par(&s,&s1);

	}

    if(c!=')')
 push(c,&s);

     }

 }


  while(s.top !=-1)
    par(&s,&s1);
   // printf("Prefix :%s\n", s1.item[s1.top]);
   strcpy(pre, s1.item[s1.top]);

}


void main()
{
 char in[30],pre[30];
  for(;;)
  {
  printf("enter expression and 0 to terminate\n");
  scanf("%s", in);
  if(strcmp(in, "0") == 0) break;
  inpre(in, pre);
  printf("%s\n", pre);
  }
}