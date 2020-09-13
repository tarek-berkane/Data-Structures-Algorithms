#include <stdio.h>
#include <stdlib.h>

#define null NULL

struct node
{
    int value;
    struct node *left;
    struct node *right;
};

typedef struct node nd;

nd *createNode(int value)
{
    nd *new_node = (nd *)malloc(sizeof(nd));
    new_node->left = null;
    new_node->right = null;
    new_node->value = value;

    return new_node;
}

void traverseInorder(nd *hd);
void traversePreorder(nd *hd);
void traversePostorder(nd *hd);

//            10
//           /  \
//          20   40
//         / \     \
//       10   90    50

int main(int argc, char const *argv[])
{
    nd *head = createNode(10);

    head->left = createNode(20);
    head->left->left = createNode(10);
    head->left->right = createNode(90);

    head->right = createNode(40);
    head->right->right = createNode(50);

    // head = null;

    traverseInorder(head);
    printf("\n");
    traversePreorder(head);
    printf("\n");
    traversePostorder(head);
    /* code */
    return EXIT_SUCCESS;
}

// Traversals

// Inorder (Left, Root, Right)
void traverseInorder(nd *hd)
{
    if (hd == null)
        return;

    if (hd->left != null)
    {
        traverseInorder(hd->left);
    }

    printf("%d ", hd->value);

    if (hd->right != null)
    {
        traverseInorder(hd->right);
    }
}

// Preorder (Root, Left, Right)
void traversePreorder(nd *hd)
{
    if (hd == null)
        return;

    printf("%d ", hd->value);

    if (hd->left != null)
    {
        traversePreorder(hd->left);
    }

    if (hd->right != null)
    {
        traversePreorder(hd->right);
    }
}

//  Postorder (Left, Right, Root)
void traversePostorder(nd *hd)
{

    if (hd->left != null)
    {
        traversePostorder(hd->left);
    }

    if (hd->right != null)
    {
        traversePostorder(hd->right);
    }

    printf("%d ", hd->value);
}