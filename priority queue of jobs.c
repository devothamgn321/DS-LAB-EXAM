#include<stdio.h>
#include<stdlib.h>
struct Job{
    int JobID;
    char name[20];
    int priority;
};
typedef struct {
    struct Job *items;
    int fIdx, rIdx;
    int capacity;
} PriorityQueue;

void initQueue(PriorityQueue* q) {
    q->capacity = 10;
    q->fIdx = 0;
    q->rIdx = -1;

    q->items = (struct Job*) malloc(q->capacity * sizeof(struct Job));
}

void deleteQueue(PriorityQueue *q){
    free(q->items);
}

void enqueue(PriorityQueue* q) {
    if (q->rIdx == q->capacity-1) {
        // Queue is full
        printf("Reallocating queue. \n");
        q->capacity *= 2;
        q->items = (struct Job*) realloc(q->items, q->capacity * sizeof(struct Job));
    }

    struct Job item;
    printf("Enter JobID JobName Job priority to enqueue: ");
    scanf("%d", &item.JobID);
    fflush(stdin);
    gets(item.name);
    fflush(stdin);
    scanf("%d",&item.priority); 
    *(q->items + ++q->rIdx) = item;
}

void dequeue(PriorityQueue* q) {
    if (q->fIdx > q->rIdx) {
        printf("Queue is empty. \n");
        return;
    }

    int minIdx = 0,i;
    struct Job min = *q->items;
    for (i = q->fIdx; i <= q->rIdx; i++) {
        if ((q->items + i)->priority < min.priority) {
            min = *(q->items + i);
            minIdx = i;
        }
    }

    for (i = minIdx; i < q->rIdx; i++)
        *(q->items + i) = *(q->items + i + 1);

    q->rIdx--;
    printf("Dequeued\nJobID   JobName    Priority\n");
    printf(" %d   %s    %d \n", min.JobID,min.name,min.priority);
}

void display(PriorityQueue *q) {
    if (q->fIdx > q->rIdx) {
        // Queue is empty
        printf("Queue is empty. \n");
        return;
    }

    int i;
    printf("\nJobID   JobName    Priority\n");
    for (i = q->fIdx; i <= q->rIdx; i++)
         printf("%d    %s      %d \n", ((q->items + i)->JobID),((q->items + i)->name),((q->items + i)->priority));
    printf("\n");
}

void printMenu() {
    printf("1. Enqueue \n");
    printf("2. Dequeue \n");
    printf("3. Display queue \n");
    printf("4. Exit \n");
}

int main() {
    PriorityQueue q;
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