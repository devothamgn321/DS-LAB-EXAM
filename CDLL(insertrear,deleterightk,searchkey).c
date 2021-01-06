/*implement circular double linked list with header node to perfrom 
1. insert Rear
2.delete immediate right node of kth node
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

void insertRear(node);
void deleteRight(node);
void searchByValue(node);
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
      printf("\nenter choice:\n1:InsertRear\n2:Delete immdediate right\n3:SearchByValue\n4:display\n");
      scanf("%d",&ch);
      switch(ch)
      {
	
    case 1: insertRear(Head);Disp(Head);break;
    case 2:  deleteRight(Head); Disp(Head);break;
    case 3: searchByValue(Head);Disp(Head);break;
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
 
void deleteRight(node H)
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
        if(pos==H->info)
        {
            printf("\ndeletion of the immediate right node is not possible\n");
            return;
        }
	 TN = H->rlink;
	 cnt = 1;
     pos=pos+1;
	 while(cnt !=pos)
	 {
	   TN=TN->rlink ;
	   cnt++;
	 }
	 TN->llink->rlink = TN->rlink;
	 TN->rlink->llink = TN->llink;
	 printf("Deleted (k+1)th element %d\n",TN->info);
	 free(TN);
	 H->info--;
      }
      else
      printf("Invalid position retry\n");
}

void  insertRear(node H)
    {
       node NN;
       NN = (node)malloc(sizeof(struct NODE));
       printf("enter info field:");
       scanf("%d",&NN->info);


       NN->rlink = H;
       NN->llink = H->llink;
       H->llink->rlink = NN;
       H->llink = NN;
       H->info++;
	 }
void searchByValue(node H)
{
    node  TN;
    int pos, info;
     if(H->info==0)
       {
	 printf("empty\n");
	 return ;
       }
       printf("enter the info of the node to be searched\n");
       scanf("%d", &info);
      TN = H->rlink;
      pos = 1;
      while(TN!=H && TN->info !=info)
      {
	  TN=TN->rlink;  pos++;
      }
       if(TN == H)
       printf("Node does not exist\n");
       else

	 printf("node with the info %dwhich  is present at position %d \n", TN->info, pos);


}

