#include<stdio.h>

struct stk
{
  char item[20];
  int top;
};
typedef struct stk STK;

void push(char c, STK *s)
{
  if(s->top ==19)
   printf("stack full\n");
  else
 s->top++;
 s->item[s->top] = c;
}

char pop(STK *s)
 {
    char c;
   if(s->top == -1)
   printf("stack empty\n");
  else
   c = s->item[s->top];
    s->top--;
 return c; 
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
  case '^': return 7;
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
  case '^': return 8;
  case '(': return 9;
   case ')': return 0;
 }
}

void inpost(char in[], char po[])
{
  STK s;
  char c;
  int i=0, j=0;
  s.top = -1;
  while((c =in[i++]) !='\0') // SCAN INFIX EXPRESSION
 {
  if(isoperand(c))
   po[j++] = c;

    else
     {
      while(s.top != -1 && stkprc(s.item[s.top]) > inprc(c))
	{
	   if(c ==')')
	    {
		while(s.item[s.top] != '(')

			 po[j++] = pop(&s);
			pop(&s);
	    break;
	     }
	  else
	    po[j++] = pop(&s);


	}

     if(c!=')')   // ( A + B)   ( +
       push(c,&s);

     } // ELSE

 }  // OUTER WHILE

  while(s.top !=-1)
   po[j++] = pop(&s);

   po[j] = '\0';
} // END INPOS


void main()
{
 char in[30],po[30];
 for(;;)
 {
  printf("enter expression and 0 to stop execution\n");
  scanf("%s", in);
  if(strcmp(in,"0")==0)  
  break;
  inpost(in, po);
  printf("%s\n", po);
  }
}
