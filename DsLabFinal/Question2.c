#include <stdio.h>
#include <stdlib.h>
int *delete_queue[100], *insert_queue[100], d_t = 0, d_h = 0, d_q_size = 0, i_t = 0, i_h = 0, i_q_size = 0;

struct List
{
    int data;
    struct List *next;
    struct List *prev;
};
typedef struct List node;

void menu()
{
    printf("\n\t\t1. Insert (head)\n");
    printf("\t\t2. Insert (nth position)\n");
    printf("\t\t3. Insert (tail)\n");
    printf("\t\t4. Delete (head)\n");
    printf("\t\t5. Delete (nth position)\n");
    printf("\t\t6. Delete (tail)\n");
    printf("\t\t7. Insert (Ascending order)\n");
    printf("\t\t9. Print List\n");
    printf("\t\t10. UNDO\n");
    printf("\t\t11. Redo\n");
    printf("\t\t0. Exit\n");
    printf("\t\tEnter your choice: ");
}

node *insert_head(node *head, int val)
{
    node *nn;
    nn = malloc(sizeof(node));
    nn->next = NULL;
    nn->prev = NULL;

    nn->data = val;
    if (head != NULL)
    {
        nn->next = head;
        head->prev = nn;
    }
    head = nn;
    return head;
}

node *insert_tail(node *head, int val)
{
    if (head == NULL)
    {
        head = insert_head(head, val);
    }
    else
    {
        node *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        node *newNode = malloc(sizeof(node));
        newNode->data = val;
        newNode->next = NULL;
        newNode->prev = temp;

        temp->next = newNode;
    }
    return head;
}

node *insert_at_N(node *head, int n, int val)
{
    if (n == 1)
    {
        head = insert_head(head, val);
    }
    else
    {
        if (n >= 2 && n <= listSize(head) + 1)
        {
            if (n == listSize(head) + 1)
            {
                head = insert_tail(head, val);
            }
            else
            {
                node *temp;
                int i;
                temp = head;
                for (i = 1; i <= n - 2; i++)
                {
                    temp = temp->next;
                }
                node *newNode = malloc(sizeof(node));
                printf("Enter data: ");
                scanf("%d", &newNode->data);
                newNode->next = temp->next;
                newNode->prev = temp;
                temp->next = newNode;
                newNode->next->prev = newNode;
            }
        }
        else
        {
            printf("Invalid position...\n\n");
        }
    }
    return head;
}
node *delete_head(node *head)
{
    if (head == NULL)
    {
        printf("list is empty.\n\n");
    }
    else
    {
        node *temp = head;
        head = head->next;
        head->prev = NULL;
        printf("%d deleted\n\n", temp->data);
        free(temp);
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
            printf("%d deleted\n\n", temp->data);
            free(temp);
        }
        else if (n == listSize(head))
        {

            temp = head;
            if (head->next == NULL)
            {
                printf("%d deleted\n\n", temp->data);
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
                printf("%d deleted\n\n", dl->data);
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
            printf("%d deleted\n\n", temp->data);
            free(temp);
        }
    }
    return head;
}
node *delete_tail(node *head)
{
    node *temp = head;
    if (head->next == NULL)
    {
        printf("%d deleted\n\n", temp->data);
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
        printf("%d deleted\n\n", dl->data);
        free(dl);
        temp->next = NULL;
    }
    return head;
}

node *insert_ascending(node *head, int val)
{
    node *temp = head, *nn;

    if (head == NULL)
        head = insert_head(head, val);
    else
    {
        nn = malloc(sizeof(node));
        nn->next = NULL;
        nn->prev = NULL;
        nn->data = val;

        while (temp->data <= nn->data && temp->next != NULL)
            temp = temp->next;
        if (temp->next == NULL)
        {
            nn->next = NULL;
            nn->prev = temp;
            temp->next = nn;
        }
        else if (temp->prev == NULL)
        {
            if (head != NULL)
            {
                nn->next = head;
                head->prev = nn;
            }
            head = nn;
        }
        else
        {
            node *pr = temp->prev;
            nn->next = temp;
            nn->prev = pr;
            temp->prev = nn;
            pr->next = nn;
        }
    }
    return head;
}
node *undo(node *head, int val)
{

    int n = listSize(head);
    delete_queue[d_t] = delete_head(head);
    insert_queue[d_t] = insert_head(head, val);
    d_t = (d_t + 1) % n;
    d_q_size++;
    i_t = (d_t + 1) % n;
    i_q_size++;
    return head;
}
node *redo(node *head, int val)
{
    int n = listSize(head);
    int i_val = insert_queue[d_h];
    insert_head(i_val, val);
    d_h = (d_h + 1) % n;
    d_q_size--;
    int d_val = delete_queue[d_h];
    delete_head(i_val);
    i_h = (d_h + 1) % n;
    i_q_size--;
    return head;
}
void printList(node *temp)
{
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n\n");
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
int main()
{
    int ch, n, i;
    node *head = NULL, *temp, *newNode;
    menu();
    scanf("%d", &ch);

    while (ch)
    {
        int val = 0;
        if (ch == 1)
        {

            printf("Enter the value : ");
            scanf("%d", &val);
            head = insert_head(head, val);
        }
        else if (ch == 2)
        {
            printf("Enter position: ");
            scanf("%d", &n);
            head = insert_at_N(head, n, val);
        }
        else if (ch == 3)
        {
            printf("Enter the value : ");
            scanf("%d", &val);
            head = insert_tail(head, val);
        }
        else if (ch == 4)
        {
            head = delete_head(head);
        }
        else if (ch == 5)
        {
            if (head == NULL)
            {
                printf("list is empty.\n\n");
            }
            else
            {
                printf("Enter position: ");
                scanf("%d", &n);
                head = delete_Nth_Position(head, n);
            }
        }
        else if (ch == 6)
        {
            if (head == NULL)
            {
                printf("list is empty.\n\n");
            }
            else
            {
                head = delete_tail(head);
            }
        }
        else if (ch == 9)
        {
            printList(head);
        }
        else if (ch == 7)
        {
            printf("Enter the value : ");
            scanf("%d", &val);
            head = insert_ascending(head, val);
        }
        else if (ch == 10)
        {

            undo(head, val);
        }
        else if (ch == 11)
        {
            redo(head, val);
        }
        else
        {
            printf("Invalid choice. please try again...\n\n");
        }
        menu();
        scanf("%d", &ch);
    }

    return 0;
}
/*For this problem, you need to modify the doubly linked list code from your class.

Implement 2 function void undo() , void redo().

undo function will undone the changes (insert, delete, update) you have made.

redo function will undone the changes of undo function.

Please keep in mind that multiple occasion of undo and redo should be handled in your code.


*/