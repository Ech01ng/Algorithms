#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node
{
   int data;
   struct Node *left;
   struct Node *right;
};

// Function to create a new node
struct Node *createNode(int data)
{
   struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
   newNode->data = data;
   newNode->left = NULL;
   newNode->right = NULL;
   return newNode;
}

// Function to insert a node
struct Node *insert(struct Node *root, int data)
{
   if (root == NULL)
   {
      return createNode(data);
   }
   else
   {
      if (data < root->data)
      {
         root->left = insert(root->left, data);
      }
      else
      {
         root->right = insert(root->right, data);
      }
      return root;
   }
}

// Function to print the tree in inorder traversal
void inorderTraversal(struct Node *root)
{
   if (root != NULL)
   {
      inorderTraversal(root->left);
      printf("%d ", root->data);
      inorderTraversal(root->right);
   }
}

int main()
{
   struct Node *root = NULL;

   // Insert nodes into the tree
   // Change the values to test different cases
   root = insert(root, 3);
   root = insert(root, 5);
   root = insert(root, 6);
   root = insert(root, 1);
   root = insert(root, 2);
   root = insert(root, 4);
   root = insert(root, 7);

   // Print the tree in inorder traversal
   printf("Inorder traversal: ");
   inorderTraversal(root);

   return 0;
}

// what is the pre-order traversal of the tree?
// The pre-order traversal of the tree is: 3 1 2 5 4 6 7
// what is the post-order traversal of the tree?
// The post-order traversal of the tree is: 2 1 4 7 6 5 3
// what is the in-order traversal of the tree?
// The in-order traversal of the tree is: 1 2 3 4 5 6 7