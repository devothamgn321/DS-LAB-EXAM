#include<stdio.h>
#include<stdlib.h>

struct NODE{
 int info;
 struct NODE *link;
 };
 typedef struct NODE *node;
 
 void InsertRear(node);
 void DeleteRight(node);
 void SearchItem(node);
 void Display(node);
 
 void main()
 {
  int choice;
  node head;
  head = (node)malloc(sizeof(struct NODE));
  head->info = 0;
  head->link = NULL;
  for(;;)
  {
   printf("Enter your choice:\n");
   printf("1.InsertRear\n2.DeleteRight\n3.SearchByItem\n4.Display\n5.Exit\n");
   scanf("%d",&choice);
   switch(choice)
   {
    case 1: InsertRear(head);
            Display(head);
            break;
            
    case 2: DeleteRight(head);
            Display(head);
            break;
            
    case 3: SearchItem(head);
            Display(head);
            break;
            
    case 4: Display(head);
            break;
            
    case 5:exit(0);        
            
    default:printf("Invaid option\n");
    
    }
 }
}

void InsertRear(node H)
{
 node NN;
 int info; 
 NN = (node)malloc(sizeof(struct NODE));
 printf("Enter the info field:");
 scanf("%d",&NN->info);
 if(H->info == 0)
 {
  H->link = NN;
  NN->link = NN;
  H->info++;
  return;
  }
  
 NN->link = H->link->link;
 H->link->link = NN;
 H->link = NN;
 H->info++;
 }
 
void Display(node H)
{
 node TP;
 if(H->info == 0){
 printf("Empty!\n"); 
 return;
 }
  TP = H->link->link;
  printf("The list is:\n");
  do
  {
   printf("%d\t",TP->info);
   TP = TP->link;
   }
   while(TP!=H->link->link);
}        

void DeleteRight(node H)
{
 int k,cnt;
 node TN,PN;
 TN = H->link->link;
 PN = NULL;
 if(H->info == 0)
 {
 printf("Empty!\n");
 return;
 }
 printf("Enter the value of k:\n");
 scanf("%d",&k);
 if(k == H->info || k == 0)
 {
 printf("Deletion not possible try again!\n");
 return;
 }
 cnt = 1;
 while(cnt<k+1)
 {
  PN = TN;
  TN = TN->link;
  cnt++;
 }
 if(TN->link == H->link->link)
 {
  PN->link = TN->link;
  H->link = PN;
  printf("%d deleted\n",TN->info);
 free(TN);
 H->info--;
 return;
  }
 else
 PN->link = TN->link;
 printf("%d deleted\n",TN->info);
 free(TN);
 H->info--;
 return;
 } 

   
void SearchItem(node H)
{
 node TN;
 int info,pos;
 if(H->info == 0)
 {     
   printf("Empty!\n");
   return;
 }
 printf("Enter the info to be searched:\n");
 scanf("%d",&info);
 TN = H->link->link;
 pos = 1;
 if(TN->info == info){
 printf("Node with info %d is found at position %d\n",TN->info,pos);
 return;
 }
 do
 {
 TN = TN->link;
 pos++;
 }
 while(TN!=H->link->link && TN->info!=info);
 if(TN == H->link->link)
 printf("Node dosent exist\n");else{
  printf("Node with info %d is found at position %d\n",TN->info,pos);
  }
}