#include <stdio.h>
#include <stdlib.h>
typedef struct list
{
    struct node *head;
} LIST;
typedef struct node
{
    int data;
    struct node *next;
} NODE;
LIST *init()
{
    // LIST* mylist;
    LIST *mylist = malloc(sizeof(LIST));
    mylist->head = NULL;
    return mylist;
}
void insertfront(LIST *ptr, int ele)
{
    NODE *temp = malloc(sizeof(NODE));
    temp->data = ele;
    temp->next = NULL;
    if (ptr->head == NULL)
    {
        ptr->head = temp;
    }
    else
    {
        NODE *first = ptr->head;
        ptr->head = temp;
        temp->next = first;
    }
}
void display(LIST *ptr)
{
    NODE *cur = ptr->head;
    while (cur != NULL)
    {
        printf("%d\t", cur->data);
        cur = cur->next;
    }
}
void insertrear(LIST *ptr, int ele)
{
    NODE *temp = malloc(sizeof(NODE));
    temp->data = ele;
    temp->next = NULL;
    NODE *cur = ptr->head;
    if (ptr->head == NULL)
        ptr->head = temp;
    else
    {
        while (cur->next != NULL)
        {
            cur = cur->next;
        }
        cur->next = temp;
    }
}
int deletefront(LIST *ptr)
{
    if (ptr->head == NULL)
        return 9999;
    else
    {
        NODE *first = ptr->head;
        ptr->head = first->next;
        int x = first->data;
        free(first);
        return x;
    }
}
int deleterear(LIST *ptr)
{
    if (ptr->head == NULL)
    {
        return 9999;
    }
    else if (ptr->head->next == NULL)
    {
        NODE *cur = ptr->head;
        int x = cur->data;
        ptr->head = NULL;
        free(cur);
        return x;
    }
    else
    {
        NODE *cur = ptr->head;
        NODE *prev = NULL;
        while (cur->next != NULL)
        {
            prev = cur;
            cur = cur->next;
        }
        prev->next = NULL;
        int x = cur->data;
        free(cur);
        return x;
    }
}
int main()

{
    LIST *mylist = init();
    int choice, ele, x, pos;
    while (1)
    {
        printf("\n1.Insert front\n2.insesrt at rear\n3.delete front\n4.delete rear\n5.display\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element");
            scanf("%d", &ele);
            insertfront(mylist, ele);
            break;
        case 2:
            printf("Enter the element");
            scanf("%d", &ele);
            insertrear(mylist, ele);
            break;
        case 3:
            x = deletefront(mylist);
            if (x == 9999)
                printf("the list iis empty");
            else
            {
                printf("The deleted element is :%d", x);
            }
            break;
        case 4:
            x = deleterear(mylist);
            if (x == 9999)
                printf("The list is emmpty");
            else
            {
                printf("the deleted element is %d", x);
            }
            break;

        case 5:
            display(mylist);
            break;
        }
    }
    return 0;
}