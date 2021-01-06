/*implement circular double linked list with header node to perfrom 
1. insert by order
2.delete immediate left node of kth node
3.search by key */


#include<stdio.h>
#include<stdlib.h>
struct NODE
{
  int info;
  struct NODE *llink;
  struct NODE *rlink;
};
typedef struct NODE * node;

void insertFront(node);
void deleteLeft(node);
void searchByPosition(node);
void Disp(node);

void main()
{
   int ch;
   node Head;
   Head = (node)malloc(sizeof(struct NODE));
   Head->info = 0;
   Head->llink=Head->rlink = Head; 
  
   for(;;)
   {
      printf("\nenter choice:\n1:InsertFront\n2:Delete immdediate left\n3:SearchByPosition\n4:display\n");
      scanf("%d",&ch);
      switch(ch)
      {
	
    case 1: insertFront(Head);Disp(Head);break;
    case 2:  deleteLeft(Head); Disp(Head);break;
    case 3: searchByPosition(Head);Disp(Head);break;
    case 4: Disp(Head); break;
	default:exit(0);

     }
 }

 }


  void Disp(node H)
   {    node TP;
       if(H->info==0)
       {
	 printf("empty\n");
	 return;

	 }
	 TP = H->rlink;
       printf("\nList is:\n");
      while(TP!=H)
       {
	  printf("%d ", TP->info);
	  TP =TP->rlink;
      }
  }
 
void deleteLeft(node H)
{
    node  TN;
    int pos, cnt;
     if(H->info==0)
       {
	 printf("empty\n");
	 return ;
       }
	printf("\nenter kth position:" );
       scanf("%d",&pos);
       if(pos>=1 && pos<=H->info)
       {
        if(pos==1)
        {
            printf("\ndeletion of the previous node is not possible\n");
            return;
        }
	 TN = H->rlink;
	 cnt = 1;
     pos=pos-1;
	 while(cnt !=pos)
	 {
	   TN=TN->rlink ;
	   cnt++;
	 }
	 TN->llink->rlink = TN->rlink;
	 TN->rlink->llink = TN->llink;
	 printf("Deleted (k-1)th element %d\n",TN->info);
	 free(TN);
	 H->info--;
      }
      else
      printf("Invalid position retry\n");
}

void insertFront(node H)
    {
       node NN;
       NN = (node)malloc(sizeof(struct NODE));
       printf("enter info field:");
       scanf("%d",&NN->info);
       NN->llink = H;
       NN->rlink = H->rlink;
       NN->rlink->llink = NN;
       H->rlink = NN;
       H->info++;
    }

void searchByPosition(node H)
{
    node  TN;
    int pos, cnt;
     if(H->info==0)
       {
	 printf("empty\n");
	 return ;
       }
	printf("\nenter position   from 1 to %d:" ,H->info);
       scanf("%d",&pos);
       if(pos>=1 && pos<=H->info)
       {
	 TN = H->rlink;
	 cnt = 1;
	 while(cnt !=pos)
	 {
	   TN=TN->rlink ;
	   cnt++;
	 }
	 printf("%d is present at position %d", TN->info, pos);
      }
      else
      printf("Invalid position retry\n");
}

