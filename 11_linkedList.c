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
void insert_afterVal() {
    int val;
    printf("enter val: \n");
    scanf("%d", &val);
    list* temp = start;
    while(temp->data != val && temp != NULL) {
        temp = temp->next;
    }
    if(temp == NULL) {
        printf("node not found\n");
        return;
    }
    list* new_node = (list*)malloc(sizeof(list));
    printf("\nenter new_node data: ");
    scanf("%d", &new_node->data);
    new_node->next = NULL;

    list* temp2 = temp->next;
    temp->next = new_node; 
    new_node->next = temp2;   
}
void insert_beforeVal() {
    int val;
    printf("enter val: \n");
    scanf("%d", &val);

    list* temp = start;
    if(temp->data == val) {
        insert_Node_At_Head();
        return;
    }

    list* prev = NULL;
    while(temp->data != val && temp != NULL) {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) {
        printf("node not found\n");
        return;
    }
    list* new_node = (list*)malloc(sizeof(list));
    printf("\nenter new_node data: ");
    scanf("%d", &new_node->data);
    new_node->next = NULL;

    prev->next = new_node; 
    new_node->next = temp;
}
void insertatPos() {
    int pos;
    printf("enter pos: ");
    scanf("%d", &pos);
    list* temp = start;
    list* prev = NULL;
    int cnt = 0;
    while(cnt < pos && temp != NULL) {
        prev = temp;
        temp = temp->next;
        cnt++;
    }
    list* new_node = (list*)malloc(sizeof(list));
    printf("\nenter new_node data: ");
    scanf("%d", &new_node->data);
    new_node->next = NULL;

    prev->next = new_node;
    new_node->next = temp;
}
void delete_atBegin() {
    list* temp = start;
    start = start->next;
    free(temp);
}
void delete_atEnd() {
    list* temp = start;
    list* prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
}

void deleteNode_atPos() {
    int pos;
    printf("enter pos: ");
    scanf("%d", &pos);

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
    int choice, val;
    printf("\nenter choice: 0.exit, 1.display, 2.create-list, 3.insert_Node_At_Head, 4.insert_Node_At_Tail, 5.insert_afterVal, 6.insert_beforeVal, 7.insertatPos : ");
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
            case 5:
                insert_afterVal();
                break;
            case 6:
                insert_beforeVal();
                break;
            case 7:
                insertatPos();
                break;
            default:
                printf("enter valid choice!");
                break;
        }
        printf("\nenter choice: 0.exit, 1.display, 2.create-list, 3.insert_Node_At_Head, 4.insert_Node_At_Tail, 5.insert_afterVal, 6.insert_beforeVal, 7.insertatPos : ");
        scanf("%d", &choice);
    }
    return 0;
}
