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



void deleteRear(Node H) {
    if (H->info == 0) {
        printf("Empty List");
        return;
    }
    H->info--;

    Node last = H->link;
    Node deleteNode = last;

    if (deleteNode->link == deleteNode) {
        H->link = NULL;
    } else {
        Node prevNode = deleteNode->link;
        while (prevNode->link != deleteNode)
            prevNode = prevNode->link;

        prevNode->link = deleteNode->link;
        H->link = prevNode;
    }

    free(deleteNode);
}

void insertAtPos(Node H) {
    int pos;
    printf("Enter position to insert at: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > H->info + 1) {
        printf("Invalid position.\n");
        return;
    }

    Node newNode = (Node) malloc(sizeof(struct node));
    printf("Enter item to insert into list: ");
    scanf("%d", &newNode->info);

    if (H->link == NULL) {
        newNode->link = newNode;
        H->link = newNode;
    } else if (pos == H->info + 1) {
        newNode->link = H->link->link;
        H->link->link = newNode;
        H->link = newNode;
    } else {
        int cnt = 1;
        Node tempNode = H->link->link, prevNode = H->link;
        while (cnt < pos) {
            prevNode = tempNode;
            tempNode = tempNode->link;
            cnt++;
        }

        prevNode->link = newNode;
        newNode->link = tempNode;
    }

    H->info++;
}




void search(Node H) {
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
      printf("\nEnter choice:\n 1.DELETE REAR \n 2.INSERT AT POSITION \n 3.SEARCH BY KEY\n");
      scanf("%d",&ch);
      switch(ch)
      {


	case 1:  deleteRear(header); display(header); break;
	case 2:  insertAtPos(header); display(header); break;

	case 3: search(header); break;
	 default:
            printf("Invalid option. \n");
            break;

     }
   }}

