#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct BST
{
    int data;
    struct BST *leftchild;
    struct BST *rightchild;
};
typedef struct BST node;

void menu()
{
    printf("1. Insert \n");
    printf("2. Delete \n");
    printf("7. Print Tree(Pre-Order)\n");
    printf("8. Print Tree(In-Order)\n");
    printf("9. Print Tree(Post-Order)\n");

    printf("0. Exit\n");
    printf("Enter your choice: ");
}

node *insert(node *root, int x)
{
    if (root == NULL)
    {
        root = malloc(sizeof(node));
        root->leftchild = NULL;
        root->rightchild = NULL;
        root->data = x;
    }
    else if (x < root->data)
    {
        root->leftchild = insert(root->leftchild, x);
    }
    else
    {
        root->rightchild = insert(root->rightchild, x);
    }
    return root;
}
void print_preorder(node *root)
{

    if (root == NULL)
        return;
    printf("%d -> ", root->data);
    print_preorder(root->leftchild);
    print_preorder(root->rightchild);
}
void print_inorder(node *root)
{
    if (root == NULL)
        return;
    print_inorder(root->leftchild);
    printf("%d -> ", root->data);
    print_inorder(root->rightchild);
}

void print_postorder(node *root)
{

    if (root == NULL)
        return;
    print_postorder(root->leftchild);
    print_postorder(root->rightchild);
    printf("%d -> ", root->data);
}
node *minValueNode(node *root)
{
    node *current = root;
    while (current && current->leftchild != NULL)
        current = current->leftchild;

    return current;
}
node *delete (node *root, int value)
{
    if (root == NULL)
        return root;
    if (value < root->data)
        root->leftchild = delete (root->leftchild, value);

    else if (value > root->data)
        root->rightchild = delete (root->rightchild, value);
    else
    {

        if (root->leftchild == NULL)
        {
            node *temp = root->rightchild;
            free(root);
            return temp;
        }
        else if (root->rightchild == NULL)
        {
            node *temp = root->leftchild;
            free(root);
            return temp;
        }
        node *temp = minValueNode(root->rightchild);
        root->data = temp->data;
        root->rightchild = delete (root->rightchild, temp->data);
    }
    return root;
}

bool isleaf(node *root)
{
    return root->leftchild == NULL && root->rightchild == NULL;
}
int height(node *root)
{
    if (root == NULL)
        return -1;
    if (isleaf(root))
        return 0;
    return 1 + max(height(root->leftchild), height(root->rightchild));
}
int max(int n1, int n2)
{
    return (n1 > n2) ? n1 : n2;
}
int size(node *root)
{
    if (root == NULL)
        return 0;
    if (isleaf(root))
        return 1;
    return 1 + size(root->leftchild) + size(root->rightchild);
}
int leaves(node *root)
{
    if (root == NULL)
        return 0;
    if (isleaf(root))
        return 1;
    return leaves(root->leftchild) + leaves(root->rightchild);
}
bool contains(node *root, int value)
{
    if (root == NULL)
        return false;

    if (root->data == value)
        return true;
    return contains(root->leftchild, value) || contains(root->rightchild, value);
}
int main()
{
    int choice, value;
    node *root = NULL;
    menu();
    scanf("%d", &choice);
    while (choice)
    {
        if (choice == 1)
        {
            printf("Enter value : ");
            scanf("%d", &value);
            root = insert(root, value);
        }
        else if (choice == 2)
        {
            printf("Enter value to delete : ");
            scanf("%d", &value);
            root = delete (root, value);
        }
        else if (choice == 7)
        {
            print_preorder(root);
            printf("\n");
        }

        else if (choice == 8)
        {

            print_inorder(root);
            printf("\n");
        }

        else if (choice == 9)
        {
            print_postorder(root);
            printf("\n");
        }

        else
            printf("Invalid choice. please try again...\n\n");
        menu();
        scanf("%d", &choice);
    }
    return 0;
}
