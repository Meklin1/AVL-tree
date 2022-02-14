#include <stdio.h>
#include <stdlib.h>
#include "avl_tree_header.h"

int main ()
{
    Node *root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 35);
    root = insert(root, 60);
    root = insert(root, 80);
    root = insert(root, 25);
    root = insert(root, 9);
    root = insert(root, 11);

   /*Before deletion
            35
           /  \
         20   60
        /  \     \
       10  25    80
      /  \
     9    11
    */


    root = deleteNode(root, 10);
    /*After deletion
            35
           /  \
         20   60
        /  \     \
       9   25    80
         \
          11
    */
    printf(checkValue(root, 10) ? "Value 10 exists in the three.\n" : "Value 10 does not exist in the three.\n" );



    printf("AVL tree elements in ascending order.\n");
    printInorder(root);

	return 0;
}
