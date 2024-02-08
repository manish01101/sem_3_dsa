#include<stdio.h>
#include<stdlib.h>

typedef struct node {
  int data;
  struct node* left;
  struct node* right;
} node;

node* buildTree(int *arr, int *index) {
  if(arr[*index] == -1) {
    (*index)++;
    return NULL;
  }
  node* root = (node*)malloc(sizeof(node));
  root->data = arr[(*index)++];
  root->left = buildTree(arr, index);
  root->right = buildTree(arr, index);
  return root;
}
node* buildBST(node* root, int data) {
  if(root == NULL) {
    root = (node*)malloc(sizeof(node));
    root->data = data;
    root->left = NULL;
    root->right = NULL;
  }
  else if(data <= root->data) {
    root->left = buildBST(root->left, data);
  }
  else {
    root->right = buildBST(root->right, data);
  }
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
  // int arr[15] = {10,7,5,-1,-1,8,-1,-1,12,11,-1,-1,15,-1,-1};
  // int index = 0;
  // node*root = buildTree(arr, &index);

  // BST
  node* root = NULL;
  // int arr[8] = {4,6,2,5,8,9,1,3};
  // for(int i=0; i<8; i++) {
  //   root = buildBST(root, arr[i]);
  // }
  root = buildBST(root, 10);
  root = buildBST(root, 5);
  root = buildBST(root, 15);
  root = buildBST(root, 3);
  root = buildBST(root, 7);

  printf("\ninorder: ");
  inorder(root);
  printf("\npreorder: ");
  preorder(root);
  printf("\npostorder: ");
  postorder(root);
  return 0;
}
