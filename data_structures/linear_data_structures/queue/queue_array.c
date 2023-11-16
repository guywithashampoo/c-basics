#include <stdio.h>
#include <stdlib.h>
#define maxsize 5

int front = -1, rear = -1;
int queue[maxsize];
void insert(int item)
{
    if (rear == maxsize - 1)
    {
        printf("\nOVERFLOW\n");
        return;
    }
    if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = rear + 1;
    }
    queue[rear] = item;
}
int delete()
{
    int item;
    if (front == -1 || front > rear)
    {
        printf("\nUNDERFLOW\n");
        return -1;
    }
    else
    {
        item = queue[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = front + 1;
        }
        return item;
    }
}
void display()
{
    if (rear == -1)
    {
        printf("\nEmpty queue\n");
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf("\n%d\n", queue[i]);
        }
    }
}

void main()
{
    int choice;
    while (choice != 4)
    {
        printf("\n1.insert an element\n2.Delete an element\n3.Display the queue\n4.Exit\n");
        printf("\nEnter your choice ?");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            int item;
            printf("\nEnter the element\n");
            scanf("\n%d", &item);
            insert(item);
            break;
        case 2:
            printf("%d dequeued\n", delete ());
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nEnter valid choice??\n");
        }
    }
}
