#include <stdio.h>
#include <stdlib.h>
#include <string.h>


///**************QUEUE**********//////////

typedef struct NodE {
    char* data;
    struct NodE* next,*prev;
}NodE;

// Structure for the queue
typedef struct Queue {
    NodE* front;
    NodE* rear;
}Queue;

void initializeQueue(Queue* queue) {
    queue->front = queue->rear = NULL;
}

int isEmptyQ(Queue* queue) {
    return queue->front == NULL;
}
int QSize(Queue* queue) {
    int size = 0;
    NodE* current = queue->front;

    while (current != NULL) {
        size++;
        current = current->next;
    }

    return size;
}


const char* dequeue(Queue* queue) {
    if (isEmptyQ(queue)) {
        printf("There is nothing in history.\n");
        exit(1);
    }
    
    NodE* temp = queue->front;
    char* data = temp->data;
    queue->front = queue->front->next;
    queue->front->prev = NULL;
    free(temp);
    
    if (queue->front == NULL) {
        queue->rear = NULL; // Queue is empty
    }
    
    return data;
}

NodE *prevTemp=NULL;
void enqueue(Queue* queue,const char* data) {
    // printf("Q::%d",QSize(queue));
    if(QSize(queue)==5){             //Queue checked dequeue
        dequeue(queue);
    }
    NodE* newNode = (NodE*)malloc(sizeof(NodE));
    if(newNode == NULL){
        dequeue(queue);
        NodE* newNode = (NodE*)malloc(sizeof(NodE));
    }
    
    newNode->data =  strdup(data);
    newNode->next = NULL;
    newNode->prev=prevTemp;
    
    if (isEmptyQ(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    prevTemp=newNode;
}



const char* front(Queue* queue) {
    if (isEmptyQ(queue)) {
        printf("Queue is empty. Front operation failed.\n");
        exit(1);
    }
    
    return queue->front->data;
}

void displayReverseQueue(Queue* queue) {
    if (isEmptyQ(queue)) {
        printf("There in no history.\n");
        return;
    }
    printf("\n\nYour search history:\n");

    NodE* current = queue->rear;
    while (current != NULL) {
        printf("%s\n\n", current->data);
        current = current->prev;
    }
    printf("\n");
}


///**********QUEUE END***********/////////




///********STACK********///
typedef struct Node {
    char* data;
    struct Node* next;
}Stack;


Stack* createNode(const char* data) {
    Stack* newNode = (Stack*)malloc(sizeof(Stack));
    newNode->data = strdup(data);
    newNode->next = NULL;
    return newNode;
}


void push(Stack** top, const char* data) {
    Stack* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
}


char* pop(Stack** top) {
    if (*top == NULL) {
        return NULL;
    }
    Stack* temp = *top;
    *top = (*top)->next;
    char* data = temp->data;
    free(temp);
    return data;
}


int isEmpty(Stack* top) {
    return top == NULL;
}

//**********STACK END***************//

int main() {
    
        Stack* stk = NULL;  // Stack for visited addresses
        Stack* stk_back = NULL;  // Stack for addresses to go back
        Queue historyQ;
        initializeQueue(&historyQ);

        // push(&stk, "http//.lightoj.com/");

        printf("\n\nAvailavle comands:\n\n");
        printf("VISIT website_address\n");
        printf("FORWARD\n");
        printf("BACK\n");
        printf("HISTORY\n");
        printf("QUIT\n\n\n");



        char cmnd[10];
        while (scanf("%s", cmnd) == 1 && strcmp(cmnd, "QUIT") != 0) {
            if (strcmp(cmnd, "VISIT") == 0) {
                getchar();  // Consume the whitespace
                char addrs[1024];
                fgets(addrs, sizeof(addrs), stdin);
                addrs[strcspn(addrs, "\n")] = '\0';  // Removing  newline
                push(&stk,addrs);
                enqueue(&historyQ,addrs);
                printf("%s\n\n", addrs);

                // Clear the backward stack
                while (!isEmpty(stk_back)) {
                    pop(&stk_back);
                }
            } else if (strcmp(cmnd, "BACK") == 0) {
                if (isEmpty(stk) || stk->next == NULL) {
                    printf("Ignored\n");
                } else {
                    push(&stk_back, pop(&stk));
                    printf("%s\n\n", stk->data);
                    enqueue(&historyQ,stk->data);
                }
            } 
            else if (strcmp(cmnd, "FORWARD") == 0) {
                if (isEmpty(stk_back)) {
                    printf("Ignored\n");
                } else {
                    push(&stk, pop(&stk_back));
                    printf("%s\n\n", stk->data);
                }
            }
            else if (strcmp(cmnd, "HISTORY") == 0) {
                displayReverseQueue(&historyQ);
            }
        }

        
        // while (!isEmpty(stk)) {
        //     pop(&stk);
        // }
        // while (!isEmpty(stk_back)) {
        //     pop(&stk_back);
        // }
    

    return 0;
}
