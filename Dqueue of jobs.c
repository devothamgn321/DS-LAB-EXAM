#include <stdio.h>
#include <stdlib.h>
typedef struct Job{
    int JobID;
    char name[20];
    int hrs;
};

typedef struct {
    struct Job *items;
    int fIdx, rIdx;
    int capacity;
} DEQueue;

void initQueue(DEQueue* q) {
    q->capacity = 10;
    q->fIdx = 0;
    q->rIdx = -1;

    q->items = (struct Job*) malloc(q->capacity * sizeof(struct Job));
}

void deleteQueue(DEQueue* q) {
    free(q->items);
}

void insertFront(DEQueue* q) {
    if (q->fIdx <= q->rIdx && q->fIdx == 0) {
        printf("This operation cannot be performed. \n");
        return;
    }

    struct Job item;
    printf("Enter id name and time of job to insert at front: ");
    scanf("%d", &item.JobID);
    fflush(stdin);
    gets(item.name);
    fflush(stdin);
    scanf("%d",&item.hrs);
    if (q->fIdx == 0) {
        // Empty queue. Just rear insert
        *(q->items + ++q->rIdx) = item;
    } else {
        *(q->items + --q->fIdx) = item;
    }
}

void deleteFront(DEQueue* q) {
    if (q->fIdx > q->rIdx) {
        printf("Queue is empty. \n");
        return;
    }

    struct Job item = *(q->items + q->fIdx++);
    printf("Deleted from front.\nid: %d \nname: %s \nhrs: %d\n", item.JobID,item.name,item.hrs);

    if (q->fIdx > q->rIdx) {
        q->fIdx = 0;
        q->rIdx = -1;
    }
}

void insertRear(DEQueue* q) {
    if (q->rIdx == q->capacity-1) {
        // Queue is full
        printf("Reallocating queue. \n");
        q->capacity *= 2;
        q->items = (int*) realloc(q->items, q->capacity * sizeof(int));
    }

    struct Job item;
    printf("Enter id name and time of job to insert at rear: ");
    scanf("%d", &item.JobID);
    fflush(stdin);
    gets(item.name);
    fflush(stdin);
    scanf("%d",&item.hrs);
    *(q->items + ++q->rIdx) = item;
}

void deleteRear(DEQueue* q) {
    if (q->fIdx > q->rIdx) {
        printf("Queue is empty. \n");
        return;
    }

    struct Job item = *(q->items + q->rIdx--);
    printf("Deleted from Rear.\nid: %d \nname: %s \nhrs: %d\n", item.JobID,item.name,item.hrs);

    if (q->fIdx > q->rIdx) {
        q->fIdx = 0;
        q->rIdx = -1;
    }
}

void display(DEQueue *q) {
    if (q->fIdx > q->rIdx) {
        // Queue is empty
        printf("Queue is empty. \n");
        return;
    }

    int i;
    printf("\nID    name    Hrs\n");
    for (i = q->fIdx; i <= q->rIdx; i++)
        printf("%d  %s   %d \n", (q->items + i)->JobID,(q->items + i)->name,(q->items + i)->hrs);
    printf("\n");
}

void printMenu() {
    printf("1. InsertFront\n");
    printf("2. DeleteFront\n");
    printf("3. InsertRear\n");
    printf("4. DeleteRear\n");
    printf("5. Display\n");
    printf("6. Exit\n");
}

int main() {
    DEQueue q;
    initQueue(&q);

    int isRunning = 1;
    while (isRunning) {
        printMenu();
        printf("Enter your choice: ");
        int ch;
        scanf("%d", &ch);
        switch(ch) {
            case 1: insertFront(&q);
                    display(&q);
                    break;
            case 2: deleteFront(&q);
                    display(&q);
                    break;
            case 3: insertRear(&q);
                    display(&q);
                    break;
            case 4: deleteRear(&q);
                    display(&q);
                    break;
            case 5: display(&q);
                    break;
            case 6: isRunning = 0;
                    break;
            default:
                    printf("Invalid choice. \n");
        }
    }
    deleteQueue(&q);
    return 0;
}

