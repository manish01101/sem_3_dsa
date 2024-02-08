#include<stdio.h>
#include<stdlib.h>

typedef struct bstnode {
  int data;
  struct bstnode* left;
  struct bstnode* right;
} node;

node* buildBST(int *arr, int *index) {
  if(arr[*index] == -1) {
    (*index)++;
    return NULL;
  }
  node* root = (node*)malloc(sizeof(node));
  root->data = arr[(*index)++];
  root->left = buildBST(arr, index);
  root->right = buildBST(arr, index);
  return root;
}

void inorder(node* root) {
  if(root == NULL) {
    return; 
  }
  inorder(root->left);
  printf("%d->", root->data);
  inorder(root->right);
}
void preorder(node* root) {
  if(root == NULL) {
    return; 
  }
  printf("%d->", root->data);
  preorder(root->left);
  preorder(root->right);
}
void postorder(node* root) {
  if(root == NULL) {
    return; 
  }
  postorder(root->left);
  postorder(root->right);
  printf("%d->", root->data);
}

int main() {
  int arr[15] = {10,7,5,-1,-1,8,-1,-1,12,11,-1,-1,15,-1,-1};
  int index = 0;
  node* root = buildBST(arr, &index);
  printf("\ninorder: ");
  inorder(root);
  printf("\npreorder: ");
  preorder(root);
  printf("\npostorder: ");
  postorder(root);
  return 0;
}
