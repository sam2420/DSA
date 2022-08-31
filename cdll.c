#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;

} NODE;
NODE *init()
{
    NODE *mylist = malloc(sizeof(NODE));
    mylist->next = mylist;
    mylist->prev = mylist;
    return mylist;
}
void insertfront(NODE *ptr, int ele)
{
    NODE *temp = malloc(sizeof(NODE));
    temp->data = ele;
    temp->next = temp->prev = NULL;
    if (ptr->next == ptr)
    {
        ptr->next = temp;
        temp->next = ptr;
        ptr->prev = temp;
        temp->prev = ptr;
    }
    else
    {
        NODE *first = ptr->next;
        ptr->next = temp;
        temp->prev = ptr;
        temp->next = first;
        first->prev = temp;
    }
}
void insertrear(NODE *ptr, int ele)
{
    NODE *temp = malloc(sizeof(NODE));
    temp->data = ele;
    temp->prev = temp->next = NULL;
    if (ptr->next == ptr)
    {
        ptr->next = temp;
        temp->next = ptr;
        temp->prev = ptr;
        ptr->prev = temp;
    }
    else
    {
        NODE *last = ptr->prev;
        last->next = temp;
        temp->prev = last;
        temp->next = ptr;
        ptr->prev = temp;
    }
}
int deletefront(NODE *ptr)
{
    if (ptr->next == ptr)
        return 9999;
    else if (ptr->next->next == ptr)
    {
        NODE *cur = ptr->next;
        int x = cur->data;
        ptr->next = ptr;
        ptr->prev = ptr;
        free(cur);
        return x;
    }
    else
    {
        NODE *first = ptr->next;
        ptr->next = first->next;
        first->next->prev = ptr;
        int x = first->data;
        free(first);
        return x;
    }
}
int deleterear(NODE *ptr)
{
    if (ptr->next == ptr)
        return 9999;
    else if (ptr->next->next == ptr)
    {
        NODE *first = ptr->next;
        int x = first->data;
        ptr->next = ptr;
        ptr->prev = ptr;
        free(first);
        return x;
    }
    else
    {
        NODE *last = ptr->prev;
        NODE *second = last->prev;
        second->next = ptr;
        ptr->prev = second;
        int x = last->data;
        free(last);
        return x;
    }
}
void display(NODE *ptr)
{
    NODE *cur = ptr->next;
    while (cur != ptr)
    {
        printf("%d\t", cur->data);
        cur = cur->next;
    }
}
void rdisplay(NODE *ptr)
{
    NODE *cur = ptr->prev;
    while (cur != ptr)
    {
        printf("%d\t", cur->data);
        cur = cur->prev;
    }
}
int main()
{
    NODE *mylist = NULL;
    mylist = init();
    int choice, ele, x, pos;
    while (1)
    {
        printf("\n1.Insert front\n2.insesrt at rear\n3.delete front\n4.delete rear\n5.display\n6.reverse display\n");
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
        case 6:
            rdisplay(mylist);
            break;
        }
    }
    return 0;
}