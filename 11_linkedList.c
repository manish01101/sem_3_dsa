#include<stdio.h>
#include<stdlib.h>

typedef struct link {
    int data;
    struct link* next;
}list;
// start pointer
list* start = NULL;

void createList() { // fn for creating list
    list* new_node = (list*)malloc(sizeof(list));
    printf("\nenter new_node data: ");
    scanf("%d", &new_node->data);
    new_node->next = NULL; //new node points to null
    if(start == NULL) // checking if list is made or not
        start = new_node;
    else
        printf("list is already created\n");
}
void insert_Node_At_Head() {
    list* new_node = (list*)malloc(sizeof(list));
    printf("\nenter new_node data: ");
    scanf("%d", &new_node->data);
    new_node->next = start;
    start = new_node;
}

void insert_Node_At_Tail() {
    list* new_node = (list*)malloc(sizeof(list));
    printf("\nenter new_node data: ");
    scanf("%d", &new_node->data);
    new_node->next = NULL;
    if(start == NULL)
        start = new_node;
    else {
        list* temp = start;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = new_node;
    }
}

void display() {
    if(start == NULL)
        printf("empty list!\n");
    else {
        list* temp = start;
        printf("\nprinting list:\n");
        while(temp!=NULL) {
            printf("%d->", temp->data);
            temp = temp->next;
        }
        printf("null\n");
    }
}

int main() {
    int choice;
    printf("\nenter choice: 0.exit, 1.display, 2.create-list, 3.insert_Node_At_Head, 4.insert_Node_At_Tail, : ");
    scanf("%d", &choice);
    while (choice) {
        switch (choice){
            case 1:
                display();
                break;
            case 2:
                createList();
                break;
            case 3:
                insert_Node_At_Head();
                break;
            case 4:
                insert_Node_At_Tail();
                break;
            default:
                printf("enter valid choice!");
                break;
        }
        printf("\nenter choice: 0.exit, 1.display, 2.create-list, 3.insert_Node_At_Head, 4.insert_Node_At_Tail, : ");
        scanf("%d", &choice);
    }
    return 0;
}
