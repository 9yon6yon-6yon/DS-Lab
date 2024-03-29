#include <stdio.h>
#include <stdlib.h>

struct List
{
    int data;
    struct List *next;
};
typedef struct List node;

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
void menu()
{
    printf("1. Insert (head)\n");
    printf("2. Insert (nth position)\n");
    printf("3. Insert (tail)\n");
    printf("4. Delete (head)\n");
    printf("5. Delete (nth position)\n");
    printf("6. Delete (tail)\n");
    printf("9. Print List\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
}

int main()
{
    int ch, n, i;
    node *head = NULL, *temp, *newNode;
    menu();
    scanf("%d", &ch);

    while (ch)
    {
        if (ch == 1)
        {
            if (head == NULL)
            {
                head = malloc(sizeof(node));
                printf("enter data: ");
                scanf("%d", &head->data); // 1
                head->next = NULL;        // 1 -> null
            }
            else
            {
                newNode = malloc(sizeof(node));
                printf("enter data: ");
                scanf("%d", &newNode->data); // 2
                newNode->next = head;        // 2-> 1 -> null
                head = newNode;              // 2-> 1 -> null
            }
        }
        else if (ch == 2)
        {
            printf("enter position: ");
            scanf("%d", &n);
            if (n == 1)
            {
                if (head == NULL)
                {
                    head = malloc(sizeof(node));
                    printf("enter data: ");
                    scanf("%d", &head->data);
                    head->next = NULL;
                }
                else
                {
                    newNode = malloc(sizeof(node));
                    printf("enter data: ");
                    scanf("%d", &newNode->data);
                    newNode->next = head;
                    head = newNode;
                }
            }
            else
            {
                if (n >= 2 && n <= listSize(head) + 1) // n=6
                {                                      // 2->3->4->5->6->7->NULL
                    temp = head;
                    for (i = 1; i <= n - 2; i++)//6-2 = 4
                    {
                        temp = temp->next;//temp = 6
                    }
                    newNode = malloc(sizeof(node));
                    printf("enter data: ");
                    scanf("%d", &newNode->data);//7
                    // newNode->next = NULL;

                    newNode->next = temp->next;//newNode->next = NULL
                    temp->next = newNode;
                }
                else
                {
                    printf("invalid position...\n\n");
                }
            }
        }
        else if (ch == 3)
        {
            if (head == NULL)
            {
                head = malloc(sizeof(node));
                printf("enter data: ");
                scanf("%d", &head->data);
                head->next = NULL;
            }
            else
            {
                temp = head;

                while (temp->next != NULL)
                {
                    temp = temp->next;
                }

                newNode = malloc(sizeof(node));
                printf("enter data: ");
                scanf("%d", &newNode->data);
                newNode->next = NULL;
                temp->next = newNode;
            }
        }
        else if (ch == 4)
        {
            if (head == NULL)
            {
                printf("list is empty.\n\n");
            }
            else
            {
                temp = head;
                head = head->next;
                printf("%d deleted\n\n", temp->data);
                free(temp);
            }
        }
        else if (ch == 5)
        {
            if (head == NULL)
            {
                printf("list is empty.\n\n");
            }
            else
            {
                printf("enter position: ");
                scanf("%d", &n);

                if (n > listSize(head) || n < 1)
                {
                    printf("invalid position\n\n");
                }
                else
                {
                    temp = head;
                    if (n == 1)
                    {

                        head = head->next;
                        printf("%d deleted\n\n", temp->data);
                        free(temp);
                        //delete(temp)
                    }
                    else if (n == listSize(head))
                    {

                        if (head->next == NULL)
                        {
                            printf("%d freed\n\n", temp->data);
                            free(temp);
                            head = NULL;
                        }
                        else
                        {
                            while (temp->next->next != NULL)
                            {
                                temp = temp->next;
                            }
                            printf("%d deleted\n\n", temp->next->data);
                            free(temp->next);
                            temp->next = NULL;
                        }
                    }
                    else
                    {
                        for (i = 1; i <= n - 2; i++)
                        {
                            temp = temp->next;
                        }
                        node *dl = temp->next;
                        temp->next = dl->next;
                        printf("%d deleted\n\n", dl->data);
                        free(dl);
                    }
                }
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
                    printf("%d deleted\n\n", temp->next->data);
                    free(temp->next);
                    temp->next = NULL;
                }
            }
        }
        else if (ch == 9)
        {
            printList(head);
        }
        else
        {
            printf("invalid choice. please try again...\n\n");
        }
        menu();
        scanf("%d", &ch);
    }

    // printf("hello\n");
    return 0;
}
