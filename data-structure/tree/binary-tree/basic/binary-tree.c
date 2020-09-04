#include <stdio.h>
#include <stdlib.h>

struct Node 
{
  int data;
  struct Node* left;
  struct Node* right;
};  

struct Node* createNode(int value) {
  struct Node* newNode = malloc(sizeof(struct Node));
  newNode->data = value;
  newNode->left = NULL;
  newNode->right = NULL;

  return newNode;
}

struct Node* insertLeft(struct Node* node, int value) {
  node->left = createNode(value);
  return node->left;
}

struct Node* insertRight(struct Node* node, int value) {
  node->right = createNode(value);
  return node->right;
}

int main(void)
{
  struct Node* root = createNode(1);
  
  /*
         1
       /   \
    NULL    NULL
  */

  insertLeft(root, 2);
  
  /*
         1
       /   \
      2     NULL
    /   \
  NULL  NULL
  */

  insertRight(root, 3);

  /*
            1
        /        \
      2           3
    /   \        /  \
  NULL  NULL  NULL   NULL
  */

  insertRight(root->left, 4);

  /*
  Tree:

                  1            <-- root
              /       \      
            2           3      
          /   \        /  \
        4     NULL  NULL   NULL
       /  \
    NULL  NULL
  */

  return 0;
}