#include <stdio.h>
#include <stdlib.h>
typedef struct list
{
    struct node *head;
} LIST;
typedef struct node
{
    int data;
    struct node *link;
} NODE;

void insertfront(NODE *ptr, int ele)
{
    NODE *temp = malloc(sizeof(NODE));
    temp->data = ele;
    temp->link = NULL;
    if (ptr->link == ptr)
    {
        ptr->link = temp;
        temp->link = ptr;
    }
    else
    {
        NODE *first = ptr->link;
        ptr->link = temp;
        temp->link = first;
    }
}
void insertrear(NODE *ptr, int ele)
{
    NODE *temp = malloc(sizeof(NODE));
    temp->data = ele;
    temp->link = NULL;
    if (ptr->link == ptr)
    {
        ptr->link = temp;
        temp->link = ptr;
    }
    else
    {
        NODE *cur = ptr->link;
        while (cur->link != ptr)
        {
            cur = cur->link;
        }
        cur->link = temp;
        temp->link = ptr;
    }
}
void display(NODE *ptr)
{
    NODE *cur = ptr->link;
    while (cur != ptr)
    {
        printf("%d\t", cur->data);
        cur = cur->link;
    }
}
int deletefront(NODE *ptr)
{
    if (ptr->link == ptr)
        return 9999;
    else if (ptr->link->link == ptr)
    {
        NODE *cur = ptr->link;
        int x = cur->data;
        ptr->link = ptr;
        free(cur);
        return x;
    }
    else
    {
        NODE *cur = ptr->link;
        ptr->link = cur->link;
        int x = cur->data;
        free(cur);
        return x;
    }
}
int deleterear(NODE *ptr)
{
    if (ptr->link == ptr)
    {
        return 9999;
    }
    else if (ptr->link->link == ptr)
    {
        NODE *first = ptr->link;
        int x = first->data;
        free(first);
        ptr->link = ptr;
        return x;
    }
    else
    {
        NODE *cur = ptr->link;
        NODE *prev = NULL;
        while (cur->link != ptr)
        {
            prev = cur;
            cur = cur->link;
        }
        prev->link = ptr;
        int x = cur->data;
        free(cur);
        return x;
    }
}
NODE *init()
{
    NODE *head = malloc(sizeof(NODE));
    head->link = head;
}
int main()
{
    NODE *mylist = NULL;
    mylist = init();
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