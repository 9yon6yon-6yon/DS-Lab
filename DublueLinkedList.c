#include <stdio.h>
void menu();
void printList(struct List *temp);
int listSize(struct List *temp);

struct List
{
    int data;
    struct List *next;
    struct List *prev;
};
typedef struct List node;

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
                scanf("%d", &head->data);
                head->next = NULL;
                head->prev = NULL;
            }
            else
            {
                newNode = malloc(sizeof(node));
                printf("enter data: ");
                scanf("%d", &newNode->data);
                newNode->next = head;
                newNode->prev = NULL;
                head->prev = newNode;
                head = newNode;
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
                    head->prev = NULL;
                }
                else
                {
                    newNode = malloc(sizeof(node));
                    printf("enter data: ");
                    scanf("%d", &newNode->data);
                    newNode->next = head;
                    newNode->prev = NULL;
                    head->prev = newNode;
                    head = newNode;
                }
            }
            else
            {
                if (n >= 2 && n <= listSize(head) + 1)
                {
                    if (n == listSize(head) + 1)
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
                        newNode->prev = temp;

                        temp->next = newNode;
                    }
                    else
                    {
                        temp = head;
                        for (i = 1; i <= n - 2; i++)
                        {
                            temp = temp->next;
                        }
                        newNode = malloc(sizeof(node));
                        printf("enter data: ");
                        scanf("%d", &newNode->data);
                        // newNode->next = NULL;

                        newNode->next = temp->next;
                        newNode->prev = temp;
                        temp->next = newNode;
                        newNode->next->prev = newNode;
                    }
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
                head->prev = NULL;
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
                newNode->prev = temp;

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
                head->prev = NULL;
                printf("%d deleted\n\n", temp->data);
                delete (temp);
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

                        temp = head;
                        head = head->next;
                        head->prev = NULL;
                        printf("%d deleted\n\n", temp->data);
                        delete (temp);
                    }
                    else if (n == listSize(head))
                    {

                        temp = head;
                        if (head->next == NULL)
                        {
                            printf("%d deleted\n\n", temp->data);
                            delete (temp);
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
                            delete (dl);
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
                        delete (temp);
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
                    delete (temp);
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
                    delete (dl);
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
