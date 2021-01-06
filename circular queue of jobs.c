#include <stdio.h>
#include <stdlib.h>
typedef struct Job{
    int JobID;
    char name[20];
    int hrs;
};
typedef struct {
    struct Job *items;
    int fidx, ridx;
    int size;
    int capacity;
} CircularQueue;

void initQueue(CircularQueue* q) {
    q->capacity = 10;
    q->fidx = 0;
    q->ridx = -1;
    q->size = 0;

    q->items = (struct Job*) malloc(q->capacity * sizeof(struct Job));
}

void deleteQueue(CircularQueue *q) {
    free(q->items);
}

void enqueue(CircularQueue* q) {
    if (q->size == q->capacity) {
        printf("Reallocating queue. \n");
        q->capacity *= 2;
        q->items = (struct Job*) realloc(q->items, q->capacity * sizeof(struct Job));
    }

    struct Job item;
    printf("Enter JobId JobName and Time to enqueue: ");
    scanf("%d", &item.JobID);
    fflush(stdin);
    gets(item.name);
    scanf("%d",&item.hrs);

    *(q->items + (++q->ridx % q->capacity)) = item;
    q->size++;
}

void dequeue(CircularQueue* q) {
    if (q->size == 0) {
        printf("Queue is empty. \n");
        return;
    }

    struct Job item = *(q->items + (q->fidx++ % q->capacity));
    printf("Dequeued %d\n", item);
    q->size--;
}

void display(CircularQueue* q) {
    if (q->size == 0) {
        printf("Queue is empty. \n");
        return;
    }

    int i;
    printf("JobID   JobName    Time required\n");
    for (i = 0; i < q->size; i++) {
        printf("%d    %s      %d \n", ((q->items + ((q->fidx + i) % q->capacity))->JobID),((q->items + ((q->fidx + i) % q->capacity))->name),((q->items + ((q->fidx + i) % q->capacity))->hrs));
    }
    printf("\n");
}

void printMenu() {
    printf("1. Enqueue \n");
    printf("2. Dequeue \n");
    printf("3. Display queue \n");
    printf("4. Exit \n");
}

int main() {
    CircularQueue q;
    initQueue(&q);

    int isRunning = 1;
    while (isRunning) {
        printMenu();
        printf("Enter your choice: ");
        int ch;
        scanf("%d", &ch);
        switch(ch) {
            case 1: enqueue(&q);
                    display(&q);
                    break;
            case 2: dequeue(&q);
                    display(&q);
                    break;
            case 3: display(&q);
                    break;
            case 4: isRunning = 0;
                    break;
            default:
                    printf("Invalid choice. \n");
        }
    }
    deleteQueue(&q);
    return 0;
}