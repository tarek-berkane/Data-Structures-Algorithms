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

int numberOfLeaf(nd *hd);
int heightOfTree(nd *hd);

int max_number(int a, int b);

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
    // head->left->right->right = createNode(90);

    head->right = createNode(40);
    head->right->right = createNode(50);

    // head = null;
    // head = createNode(30);

    traverseInorder(head);
    printf("\n");
    traversePreorder(head);
    printf("\n");
    traversePostorder(head);
    printf("\n");
    printf("number of leaf is : %d \n", numberOfLeaf(head));
    printf("height is : %d \n", heightOfTree(head));

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
    if (hd == null)
        return;

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

//

int numberOfLeaf(nd *hd)
{

    if (hd == null)
        return 0;

    if (hd->left != null && hd->right != null)
        return 1 + numberOfLeaf(hd->left) + numberOfLeaf(hd->right);

    if (hd->left != null)
        return 1 + numberOfLeaf(hd->left);

    if (hd->right != null)
        return 1 + numberOfLeaf(hd->right);

    return 1;
}

int heightOfTree(nd *hd)
{
    if (hd == null)
        return 0;

    if (hd->left != null && hd->right != null)
    {
        return 1 + max_number(heightOfTree(hd->left), heightOfTree(hd->right));
    }

    if (hd->left != null)
    {
        return 1 + heightOfTree(hd->left);
    }

    if (hd->right != null)
    {
        return 1 + heightOfTree(hd->right);
    }
    
    return 1;
}

int max_number(int a, int b)
{
    if (a >= b)
        return a;
    return b;
}