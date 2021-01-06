#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node* llink;
    int info;
    struct node* rlink;
};

typedef struct node* Node;

Node createCDLL() {
    Node newList = (Node) malloc(sizeof(struct node));
    newList->info = 0;
    newList->llink = newList->rlink = newList;
    return newList;
}




void display(Node H) {
    if (H->info == 0) {
        printf("Empty list. \n");
        return;
    }
    Node tempNode = H->rlink;
    printf("List is:\n");
    while (tempNode != H) {
        printf("%d ", tempNode->info);
        tempNode = tempNode->rlink;
    }
    printf("\n");
}


void deleteRear(Node H) {
    if (H->info == 0) {
        printf("List is empty. \n");
        return;
    }
    H->info--;

    Node deleteNode = H->llink;
    deleteNode->llink->rlink = H;
    H->llink = deleteNode->llink;
    free(deleteNode);
}

void insertAtPos(Node H) {
    int pos;
    printf("Enter the position at which the element is to be inserted: ");
    scanf("%d", &pos);

    if (pos >= 1 && pos <= H->info + 1) {
        H->info++;
        Node newNode = (Node) malloc(sizeof(struct node));
        printf("Enter the element to be inserted: ");
        scanf("%d", &newNode->info);

        int cnt = 1;
        Node tempNode = H;
        while (cnt < pos) {
            tempNode = tempNode->rlink;
            cnt++;
        }

        newNode->rlink = tempNode->rlink;
        newNode->llink = tempNode;
        newNode->rlink->llink = newNode;
        newNode->llink->rlink = newNode;
    } else {
        printf("Invalid position. \n");
        return;
    }
}





void search(Node H) {
    if (H->info == 0) {
        printf("List is empty. \n");
        return;
    }

    int key;
    printf("Enter value of item to be searched: ");
    scanf("%d", &key);
    int pos = 1;
    Node tempNode = H->rlink;
    while (tempNode != H && tempNode->info != key) {
        tempNode = tempNode->rlink;
        pos++;
    }

    if (tempNode == H) {
        printf("Key %d not found in list. \n", key);
        return;
    }

    printf("Node with info %d found at position %d \n", tempNode->info, pos);
}





void printMenu() {
    printf("\n\n");
    printf("1. Display \n");
    printf("2. Insert at position \n");
  
    printf("3. Delete Rear \n");
   
   
    printf("4. Search for an item by value \n");
  
    printf("5. Exit \n");
}

int main() {
    Node header = createCDLL(), copy = NULL;
    int isRunning = 1;
    while (isRunning) {
        printMenu();
        printf("Enter your choice: ");
        int ch;
        scanf("%d", &ch);
        switch(ch) {
        case 1:
            display(header);
            break;
       
       
      
        case 3:
            deleteRear(header);
            display(header);
            break;
        case 2:
            insertAtPos(header);
            display(header);
            break;
       
        case 4:
            search(header);
            break;
     
        case 5:
            isRunning = 0;
            break;
        default:
            printf("Invalid option. \n");
            break;
        }
    }

    return 0;
}
