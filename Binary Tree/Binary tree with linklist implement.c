#include<stdio.h>
#include <stdlib.h>

struct Node {
int data;
struct Node* left;
struct Node* right;
};

struct Node* newNode(int data) {
struct Node* node = (struct Node*) malloc(sizeof(struct Node));
node->data = data;
node->left = NULL;
node->right = NULL;
return node;
}

void print_In_Order(struct Node* node) {
if (node == NULL) return;
print_In_Order(node->left);
printf("%d ", node->data);
print_In_Order(node->right);
}

int main()
{
struct Node* root = newNode(10);
root->left = newNode(20);
root->right = newNode(30);
root->left->left = newNode(40);
root->left->right = newNode(50);
printf("Traversal of a binary tree: \n");
print_In_Order(root);
return 0;
}

