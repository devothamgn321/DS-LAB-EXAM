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



void insertByOrder(Node H) {
    H->info++;
    Node newNode = (Node) malloc(sizeof(struct node));
    printf("Enter element to insert by order: ");
    scanf("%d", &newNode->info);

    if (H->link == NULL) {
        newNode->link = newNode;
        H->link = newNode;
        return;
    }

    if (H->link->info < newNode->info) {
        newNode->link = H->link->link;
        H->link->link = newNode;
        H->link = newNode;
        return;
    }

    Node tempNode = H->link->link, prevNode = H->link;

    while (tempNode->info < newNode->info){
        prevNode = tempNode;
        tempNode = tempNode->link;
    }

    newNode->link = tempNode;
    prevNode->link = newNode;
}

void deleteByPosition(Node H) {
    if (H->info == 0) {
        printf("List is empty. \n");
        return;
    }
    Node TN,PN;
    int pos,i=1;
    printf("Enter your position: ");
    scanf("%d", &pos);
    if(pos>=1 && pos<=H->info)
    {

        TN=H->link->link;
        if(pos==1 && H->info==1){
            free(TN);
            H->link=NULL;
            H->info--;
            return;
        }
        if(pos==1 && H->info!=1)
        {
            H->link->link=TN->link;
            free(TN);
            H->info--;
            return;
        }

        while(i<pos)
        {
            PN=TN;
            TN=TN->link;
            i++;
        }
        if(TN->link==H->link->link)
        {
            H->link=PN;
        }
        PN->link=TN->link;
        free(TN);
        H->info--;
        return;
    }
    else
        printf("Invalid Position");
        return;


}

void searchByKey(Node H) {
    if (H->info == 0) {
        printf("List is empty. \n");
        return;
    }

    int key;
    printf("Enter your key to search: ");
    scanf("%d", &key);

    if (H->link->link->info == key) {
        printf("Element %d found at position 1", key);
        return;
    }

    int cnt = 1;
    Node tempNode = H->link->link;
    do {
        tempNode = tempNode->link;
        cnt++;
    } while (tempNode != H->link->link && tempNode->info != key);

    if (tempNode == H->link->link) {
        printf("Key not found in list.\n");
        return;
    }

    printf("Element %d found at position %d\n", key, cnt);
}

int main() {
    Node header = createCLL();


   int ch;
   for(;;)
   {
      printf("\nEnter choice:\n 1.INSERT BY ORDER \n 2.DELETE BY POSITION \n 3.SEARCH BY KEY\n");
      scanf(" %d",&ch);
      switch(ch)
      {
	case 1: insertByOrder(header);
		display(header);
		break;
	case 2: deleteByPosition(header);display(header); break;
	case 3: searchByKey(header); display(header); break;
    default:
            printf("Invalid option. \n");
            break;
     }
   }
}
