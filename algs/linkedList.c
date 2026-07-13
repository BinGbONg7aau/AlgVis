#include "linkedList.h"
#include "../helperFunctions.h"

typedef struct Node {
    int value;
    struct Node *next;
} Node;

static Node *createNode(int value);
static Node *insertAtHead(Node *head, int value);
static void printList(const Node *head);
static void freeList(Node *head);

void linkedList() {
    int length = -1;
    int *array;
    Node *head = NULL;

    printf("LINKED LIST\n");

    promptArrayLength(&length);
    array = generateArray(length);
    populateArrayRandom(array, length);

    printf("Generated array:\n");
    printArray(array, length);

    printf("\nBuilding linked list from array...\n");

    for (int i = 0; i < length; i++) {
        head = insertAtHead(head, array[i]);
        printf("Inserted %d at head\n", array[i]);
        printf("Current list: ");
        printList(head);
    }

    printf("\nFinal linked list:\n");
    printList(head);

    freeList(head);
    free(array);
}

static Node *createNode(int value) {
    Node *node = malloc(sizeof(Node));
    if (node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    node->value = value;
    node->next = NULL;
    return node;
}

static Node *insertAtHead(Node *head, int value) {
    Node *node = createNode(value);
    node->next = head;
    return node;
}

static void printList(const Node *head)
{
    printf("HEAD\n");
    printf(" |\n");
    printf(" v\n");

    while (head != NULL) {

        printf("[%d]", head->value);

        if (head->next)
            printf(" -> ");

        head = head->next;
    }

    printf(" -> NULL\n\n");
}

static void freeList(Node *head) {
    Node *current = head;

    while (current != NULL) {
        Node *next = current->next;
        free(current);
        current = next;
    }
}
