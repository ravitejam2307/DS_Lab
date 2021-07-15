//BST and Implementation of Traversing Techniques Recursively

# include <stdio.h>
# include <conio.h>
# include <stdlib.h>

typedef struct BST {
   int data;
   struct BST *left_child, *right_child;
} node;

int insert(node *, node *);
int inorder(node *);
int preorder(node *);
int postorder(node *);
node *search(node *, int, node **);

int main() {
   int ch;
   char ans = 'N';
   int key;
   node *new_node, *root, *temp, *parent;
   node *get_node();
   root = NULL;

   printf("\n Binary Search Tree\n");
   do {
      printf("\n****Main Menu****");
      printf("\n 1.Create");
      printf("\n 2.Search");
      printf("\n 3.Recursive Traversals");
      printf("\n 4.Exit");
      printf("\n Enter your choice :");
      scanf("%d", &ch);

      switch (ch)
      {
      case 1:
         do {
            new_node = get_node();
            printf("\nEnter The Element: ");
            scanf("%d", &new_node->data);

            if (root == NULL) /* Tree is not Created */
               root = new_node;
            else
               insert(root, new_node);

            printf("\nWant To enter More Elements?(y/n)");
            ans = getch();
         } while (ans == 'y');
         break;

      case 2:
         printf("\nEnter Element to be searched :");
         scanf("%d", &key);

         temp = search(root, key, &parent);
         printf("\nParent of node %d is %d", temp->data, parent->data);
         break;

      case 3:
         if (root == NULL)
            printf("Tree Is Not Created");
         else {
            printf("\n The Inorder display   : ");
            inorder(root);
            printf("\n The Preorder display  : ");
            preorder(root);
            printf("\n The Postorder display : ");
            postorder(root);
         }
         break;
      }
   } while (ch != 4);
   getch();
     return 0;
}
/*
 Get new Node
 */
node *get_node() {
   node *temp;
   temp = (node *) malloc(sizeof(node));
   temp->left_child = NULL;
   temp->right_child = NULL;
   return temp;
}
/*
 This function is for creating a binary search tree
 */
int insert(node *root, node *new_node) {
   if (new_node->data < root->data) {
      if (root->left_child == NULL)
         root->left_child = new_node;
      else
         insert(root->left_child, new_node);
   }

   if (new_node->data > root->data) {
      if (root->right_child == NULL)
         root->right_child = new_node;
      else
         insert(root->right_child, new_node);
   }
}
/*
 This function is for searching the node from
 binary Search Tree
 */
node *search(node *root, int key, node **parent) {
   node *temp;
   temp = root;
   while (temp != NULL) {
      if (temp->data == key) {
         printf("\n The %d Element is Present", temp->data);
         return temp;
      }
      *parent = temp;

      if (temp->data > key)
         temp = temp->left_child;
      else
         temp = temp->right_child;
   }
   return NULL;
}
/*
 This function displays the tree in inorder fashion
 */
int inorder(node *temp) {
   if (temp != NULL) {
      inorder(temp->left_child);
      printf("\t %d", temp->data);
      inorder(temp->right_child);
   }
}
/*
 This function displays the tree in preorder fashion
 */
int preorder(node *temp) {
   if (temp != NULL) {
      printf("\t %d", temp->data);
      preorder(temp->left_child);
      preorder(temp->right_child);
   }
}

/*
 This function displays the tree in postorder fashion
 */
int postorder(node *temp) {
   if (temp != NULL) {
      postorder(temp->left_child);
      postorder(temp->right_child);
      printf("\t %d", temp->data);
   }
}
