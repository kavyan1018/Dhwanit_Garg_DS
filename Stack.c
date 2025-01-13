#include <stdio.h>
#include <stdlib.h>  // For exit()
#define SIZE 5

int stack[SIZE];
int top = -1;  // Empty stack

// Push function
void push(int num)
{
    // Check if stack is full
    if (top == SIZE - 1)
    {
        printf("Stack is full\n");
    }
    else
    { 
        top++;
        stack[top] = num;
        printf("%d pushed to the stack\n", num);
    }
}

int empty()
{
    // Check if stack is empty
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int pop()
{
    // Check if stack is empty
    if (empty())
    {
        printf("Stack UNDERFLOW\n");
        return -1;
    }
    else
    {
        return stack[top--];
    }
}

void display()
{
    int i;
    if (empty())
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack elements are:\n");
        for (i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

int peek()
{
    if (empty())
    {
        printf("Stack is empty\n");
        return -1;
    }
    else
    {
        return stack[top];
    }
}

int peep(int location)
{
    int index;
    if (empty())
    {
        printf("Stack is empty\n");
        return -1;
    }
    else
    {
        index = top - location + 1;  
        if (index < 0 || index > top)
        {
            printf("Invalid location\n");
            return -1;
        }
        else
        {
            return stack[index];
        }
    }
}

int main()
{
    int choice, num, location;

    while (1)
    {
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("5. Peep\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the number to push: ");
            scanf("%d", &num);
            push(num);
            break;

        case 2:
            num = pop();
            if (num != -1)
            {
                printf("%d popped from the stack\n", num);
            }
            break;

        case 3:
            display();
            break;

        case 4:
            num = peek();
            if (num != -1)
            {
                printf("The number at the top is %d\n", num);
            }
            break;

        case 5:
            printf("Enter the location to peep: ");
            scanf("%d", &location);
            num = peep(location);
            if (num != -1)
            {
                printf("The number at location %d is %d\n", location, num);
            }
            break;

        case 6:
            printf("Exiting program...\n");
            exit(0);

        default:
            printf("Invalid choice\n");
            break;
        }
    }
    return 0;
}
