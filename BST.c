#include <stdio.h>
#include <stdlib.h>

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
