#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node* link;
};

typedef struct node* Node;

Node createCLL() {
    Node header = (Node) malloc(sizeof(struct node));
    header->info = 0;
    header->link = NULL;
    return header;
}

void display(Node H) {
    if (H->info == 0) {
        printf("List is empty. \n");
        return;
    }

    Node tempNode = H->link->link;
    do {
        printf("%d ", tempNode->info);
        tempNode = tempNode->link;
    } while (tempNode != H->link->link);
    putchar('\n');
}

void insertFront(Node H) 
{
    H->info++;
    Node newNode = (Node) malloc(sizeof(struct node));
    printf("Enter item to insert: ");
    scanf("%d", &newNode->info);

    if (H->link == NULL) {
        newNode->link = newNode;
        H->link = newNode;
        return;
    }

    newNode->link = H->link->link;
    H->link->link = newNode;
}
void DeleteLeftofK(Node H)
{
    int cnt,pos;
    Node TN,PN;
    if(H->info==0)
    {
        printf("The list is empty\n");
        return;
    } 
    if(H->info==1)
    {
        printf("List contains only one node\n");
        return;
    }
    printf("Enter the position\n");
    scanf("%d",&pos);
    if(pos<=0 || pos>H->info)
    {
        printf("Invalid position\n");
        return;
    }
    if(H->info>=2 && pos<=H->info)
    {
        TN=H->link->link;
        PN=H->link;
        cnt=1;
        if(pos==1)
        {
            printf("Left node does not exist\n");
            return;
        }
        while(cnt<pos-1)
        {
            PN=TN;
            TN=TN->link;
            cnt++;
        }
        PN->link=TN->link;
        printf("Node with info %d is deleted at position %d\n",TN->info,pos-1);
        free(TN);
        H->info--;
        return;
    }
}
void SearchByPos(Node H)
{
    if(H->info==0)
    {
        printf("The list is empty\n");
        return;
    }
    int pos,cnt;
    Node TN;
    printf("Enter the position\n");
    scanf("%d",&pos);
    if(pos<=0 || pos>H->info)
    {
        printf("Invalid position\n");
        return;
    }
    if(H->info>=1 && pos<=H->info)
    {
        TN=H->link->link;
        cnt=1;
        while(cnt<pos)
        {
            TN=TN->link;
            cnt++;
        }
        printf("The node with info %d is present at position %d \n",TN->info,pos);
        return;
    }
}

int main() {
    Node header = createCLL();
    int isRunning = 1, ch;
    while(isRunning==1)
    {
        printf("0:Display\n1:Insert Front\n2:Left of kth node\n3:Search by position\n4:Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch (ch)
        {
        case 0: display(header);
                break;
        case 1: insertFront(header);
                display(header);
                break;            
        case 2: DeleteLeftofK(header);
                 display(header);
                 break; 
        case 3: SearchByPos(header);
                break;                                           
        default: exit(0);
        }
    }
    return 0;
}