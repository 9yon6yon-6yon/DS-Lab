#include <stdio.h>
#include <stdlib.h>
struct List
{
    int item;
    struct List *next;
    struct List *prev;
};
typedef struct List node;
void menu()
{
    printf("1. Insert (head)\n");
    printf("2. Insert (tail)\n");
    printf("3. Delete (Nth)\n");
    printf("4. Substract Smallest value from all\n");
    printf("9. Print List\n");
    printf("0. To Exit\n");
    printf("Enter Your Choice : ");
}
int listSize(node *temp)
{
    int i = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        i++;
    }
    return i;
}
node *insert_head(node *head, int value)
{
    node *nn;
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

node *insert_tail(node *head, int value)
{
    if (head == NULL)
    {
        head = insert_head(head, value);
    }
    else
    {
        node *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        node *newNode = malloc(sizeof(node));
        newNode->item = value;
        newNode->next = NULL;
        newNode->prev = temp;
        temp->next = newNode;
    }
    return head;
}
node *delete_Nth_Position(node *head, int n)
{
    int i;

    if (n > listSize(head) || n < 1)
    {
        printf("Invalid position\n\n");
    }
    else
    {
        node *temp = head;
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
                node *dl = temp->next;
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
            node *pr = temp->prev;
            node *fw = temp->next;

            pr->next = fw;
            fw->prev = pr;
            printf("%d deleted\n\n", temp->item);
            free(temp);
        }
    }
    return head;
}
node *delete_all_Nth_position(node *head, int n)
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
void printList(node *head)
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
    int choice, n, i;
    node *head = NULL;
    menu();
    scanf("%d", &choice);
    while (choice)
    {
        if (choice == 1)
        {
            printf("Enter value (head) : ");
            int val;
            scanf("%d", &val);
            head = insert_head(head, val);
        }
        else if (choice == 2)
        {
            printf("Enter value (tail) : ");
            int val;
            scanf("%d", &val);
            head = insert_tail(head, val);
        }
        else if (choice == 3)
        {
            printf("Enter Nth value : ");
            scanf("%d", &n);
            head = delete_all_Nth_position(head, n);
        }
        else if (choice == 9)
        {
            printList(head);
        }
        else if (choice == 4)
        {
            int min_value = head->item;
            node *temp = head;
            while (temp != NULL)
            {
                if (min_value > temp->item)
                {
                    min_value = temp->item;
                }
                temp = temp->next;
            }
            temp = head;
            while(temp!=NULL){
                temp->item = temp->item - min_value;
                temp = temp->next;
            }
            temp = head;
        }
        else
            printf("\tInvalid Choice. Try Again......\n\n");
        menu();
        scanf("%d", &choice);
    }

    return 0;
}
/*

Suppose that you are given the following doubly linked list implementation that uses head and
tail pointers.
struct listNode
{
int item;
listNode *next; // keep address of next node
listNode *prev; // keep address of previous node
};
struct listNode *head; // points to the first node of the list
struct listNode *trail; // points to the last node of the list
Implement the function “void delete(int N)” that deletes all Mth nodes of the list such that M mod N = 0.
For example, if N = 3, the function should delete 3rd node, 6th node, 9th node and so on.
The node pointed by head is the 1st node. Your implementation should be as efficient as possible.

Now subtract the smallest integer from each value of the linked list and then show all elements.*/