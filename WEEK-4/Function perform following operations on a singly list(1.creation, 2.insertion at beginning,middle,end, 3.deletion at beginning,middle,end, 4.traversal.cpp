#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory full!\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(int data) {
    struct node* newNode= createNode(data);
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int data) {
    struct node* newNode = createNode(data);
    if (head == NULL){
        head = newNode;
        return;
    }
    struct node* ptr = head;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = newNode;
}

void insertAtPosition(int data, int pos) {
    if (pos == 1) {
        insertAtBeginning(data);
        return;
    }
    struct node* newNode = createNode(data);
    struct node* ptr = head;
    for (int i = 1; i < pos - 1 && ptr != NULL; i++)
        ptr = ptr->next;
    if (ptr == NULL) {
        printf("Invalid position!\n");
        return;
    }
    newNode->next = ptr->next;
    ptr->next = newNode;
}

void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct node* ptr = head; //ptr is the temporary address of the first element
    head = head->next; //disconnect the head from the first element and points towards the next element of the head.
    free(ptr); // deallocate the memory pf the function we used.
}

void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct node *ptr = head, *prev = NULL;
    if (head->next == NULL) { //if head is the null.
        free(head);
        head = NULL;
        return;
    }
    ptr=head;
    while (ptr->next != NULL) {
        prev = ptr;
        ptr = ptr->next;
    }
    prev->next = NULL; //now we point pointer to the null that the last node of the list is delete.
    free(ptr);
}

void deleteAtPosition(int pos) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct node *ptr = head, *prev = NULL;
    if (pos == 1) {
        deleteAtBeginning();
        return;
    }
    for (int i = 1; i < pos && ptr != NULL; i++) {
        prev = ptr;
        ptr = ptr->next;
    }
    if (ptr == NULL) {
        printf("Invalid position!\n");
        return;
    }
    prev->next = ptr->next;
    free(ptr);
}

void traverse() { 
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct node* ptr = head;
    printf("List: ");
    while (ptr != NULL) {
        printf("%d -> ",ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

void createList(int n) {
    head = NULL;
    int data;
    for (int i = 1; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        insertAtEnd(data);
    }
}

int main() {
    int choice, data, pos, n;

    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Create List\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Traverse\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("How many nodes to create? ");
                scanf("%d", &n);
                createList(n);
                break;

            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Where to insert? 1-Beginning 2-Middle 3-End: ");
                scanf("%d", &pos);
                if (pos == 1)
                    insertAtBeginning(data);
                else if (pos == 2) {
                    int position;
                    printf("Enter position to insert: ");
                    scanf("%d", &position);
                    insertAtPosition(data, position);
                } else if (pos == 3)
                    insertAtEnd(data);
                else
                    printf("Invalid choice!\n");
                break;

            case 3:
                printf("Where to delete? 1-Beginning 2-Middle 3-End: ");
                scanf("%d", &pos);
                if (pos == 1)
                    deleteAtBeginning();
                else if (pos == 2) {
                    int position;
                    printf("Enter position to delete: ");
                    scanf("%d", &position);
                    deleteAtPosition(position);
                } else if (pos == 3)
                    deleteAtEnd();
                else
                    printf("Invalid choice!\n");
                break;

            case 4:
                traverse();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
