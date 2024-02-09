#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
}node;
node* start = NULL;

void deleteNode_afterval() {
  int val;
  printf("Enter val: ");
  scanf("%d", &val);
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    node* temp = start;
    while (temp->next != NULL && temp->data != val) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("Node with value %d not found\n", val);
        return;
    }
    node* nodetodelete = temp->next;
    temp->next = nodetodelete->next;
    if (nodetodelete->next != NULL) {
        nodetodelete->next->prev = temp;
    }
    free(nodetodelete);
}

void insertathead() {
  int val;
  printf("enter val: ");
  scanf("%d", &val);
  node* temp = (node*)malloc(sizeof(node));
  temp->data = val;
  temp->next = NULL;
  temp->prev = NULL;
  if(start == NULL) {
    start = temp;
  }
  else {
    temp->next = start;
    start->prev = temp;
    start = temp;
  }
}
void display() {
    if(start == NULL)
        printf("empty list!\n");
    else {
        node* temp = start;
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
  printf("\nenter choice: 0.exit, 1.display, 2.insert at head, 3.delete after val:");
  scanf("%d", &choice);
  while (choice) {
    switch (choice){
      case 1:
        display();
        break;
      case 2:
        insertathead();
        break;
      case 3: 
        deleteNode_afterval();
        break;
      default: 
        printf("enter valid choice\n");
        break;
    }
    printf("\nenter choice: 0.exit, 1.display, 2.insert at head, 3.delete after val:");
    scanf("%d", &choice);
  }
}