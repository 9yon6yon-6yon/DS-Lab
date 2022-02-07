#include <stdio.h>
#include <stdlib.h>
int arr[15], nt = 0, position = -1, flag = 0;
struct BST
{
    int data;
    struct BST *leftchild;
    struct BST *rightchild;
};
typedef struct BST node;
struct List
{
    int item;
    struct List *next;
    struct List *prev;
};
typedef struct List listNode;
int listSize(listNode *temp)
{
    int i = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        i++;
    }
    return i;
}

listNode *insert_head(listNode *head, int value)
{
    listNode *nn;
    nn = malloc(sizeof(node));
    nn->next = NULL;
    nn->prev = NULL;
    nn->item = value;
    if (head != NULL)
    {
        nn->next = head;
        head->prev = nn;
    }
    head = nn;
    return head;
}

void menu()
{
    printf("\n1. Insert \n");
    printf("2. Delete \n");
    printf("3. Print Tree(In-Order)\n");
    printf("4. Delete all (div by M)\n");
    printf("5. Substart smallest\n");
  
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
void print_inorder(node *root)
{
    if (root == NULL)
        return;
    print_inorder(root->leftchild);
    printf("%d -> ", root->data);
    arr[nt] = root->data;
    nt++;
    print_inorder(root->rightchild);
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

listNode *delete_Nth_Position(listNode *head, int n)
{
    int i;

    if (n > listSize(head) || n < 1)
    {
        printf("Invalid position\n\n");
    }
    else
    {
        listNode *temp = head;
        if (n == 1)
        {

            temp = head;
            head = head->next;
            head->prev = NULL;
            printf("%d deleted\n\n", temp->item);
            free(temp);
        }
        else if (n == listSize(head))
        {

            temp = head;
            if (head->next == NULL)
            {
                printf("%d deleted\n\n", temp->item);
                free(temp);
                head = NULL;
            }
            else
            {
                while (temp->next->next != NULL)
                {
                    temp = temp->next;
                }
                listNode *dl = temp->next;
                printf("%d deleted\n\n", dl->item);
                free(dl);
                temp->next = NULL;
            }
        }
        else
        {
            for (i = 1; i <= n - 1; i++)
            {
                temp = temp->next;
            }
            listNode *pr = temp->prev;
            listNode *fw = temp->next;

            pr->next = fw;
            fw->prev = pr;
            printf("%d deleted\n\n", temp->item);
            free(temp);
        }
    }
    return head;
}
listNode *delete_all_Nth_position(listNode *head, int n)
{
    int lsize = listSize(head);
    for (int i = lsize; i > 0; i--)
    {
        if (i % n == 0)
        {
            head = delete_Nth_Position(head, i);
        }
    }
    return head;
}
void printList(listNode *head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->item);
        head = head->next;
    }
    printf("\n\n");
}
int main()
{
    int choice, value;
    node *root = NULL;
    listNode *head = NULL;
    menu();
    scanf("%d", &choice);
    while (choice)
    {
        if (choice == 1)
        {
            printf("Enter value : ");
            scanf("%d", &value);
            root = insert(root, value);
            position++;
        }
        else if (choice == 2)
        {
            printf("Enter value to delete : ");
            scanf("%d", &value);
            root = delete (root, value);
        }
        else if (choice == 3)
        {

            print_inorder(root);

            if (flag == 0)
            {
                for (int i = position; i >= 0; i--)
                {
                    head = insert_head(head, arr[i]);
                }
            }
            else
                break;
            flag = 1;
        }
        else if (choice == 4)
        {
            printf("Enter Nth value : ");
            int s;
            scanf("%d", &s);
            head = delete_all_Nth_position(head, s);

            printf("\n");
        }

        else if (choice == 5)
        {

            int min_value = head->item;
            listNode *temp = head;
            while (temp != NULL)
            {
                if (min_value > temp->item)
                {
                    min_value = temp->item;
                }
                temp = temp->next;
            }
            temp = head;
            while (temp != NULL)
            {
                temp->item = temp->item - min_value;
                temp = temp->next;
            }
            temp = head;
            printf("\n");
        }

        else
            printf("Invalid choice. please try again...\n\n");
        menu();
        scanf("%d", &choice);
    }
    return 0;
}

/*For this problem, you need to use the BST code written in your class.

Implement the function “void delete(int N)” that deletes all nodes of the tree such that M mod
N = 0, where M is the value of the node. For example, if N = 3, the function should delete every node that contains a value divisible by 3.
The node pointed by head is the root node. Your implementation should be as efficient as possible.
Now subtract the smallest integer from each value of the BST and then show all elements inorder.


*/