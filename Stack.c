#include<stdio.h>
#define SIZE 5

int stack[SIZE];
int top = -1;  // Empty stack


//  Push function
void push(int num)
{
    // check if stack is full
    if(top == SIZE-1)
    {
        printf("Stack is full\n");
    }
    else{   // Increment top and add element
        top++;
        stack[top] = num;
    }
}

int empty()
{
    // when stack is empty
    if(top == -1)
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
    // check if stack is empty
    if(empty())
    {
        printf("Stack UNDEFLOW\n");
        return -1;
    }else{
        return stack[top--];
    }
}


void display()
{
    int i;
    for (i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);   
    }
}

int peek()
{
    if (empty())
    {
        return -1;
    }
    else{
        return stack[top];
    }   
}

int peep(int location)
{
    int index;
    if(top == -1)
    {
        return -1;
    }
    else{
        index = top - location + 1;  // 0
        if(index < 0 || index > SIZE-1)
        {
            return -1;
        }
        else{
            return stack[top - location + 1];
        }
    }
}

int main()
{
    int choice, num, location;


    printf("1. Push\n");
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
        num = pop();  // -1
        if (num != -1)
        {
            printf("%d Poped",num);
        }        
        break;

    case 3:
        display();
        break;    

    case 4:
        printf("Enter the location to peek: ");
        scanf("%d", &location);
        num = peep(location);

        if (num != -1)
        {
            printf("The number at %d is %d", location, num);
        }
        break;

    case 5:
        num = peek();
        if (num != -1)
        {
            printf("The number at the top is %d", num);
        }
        break;

    case 0:
        exit(0);
    default:
        printf("Invalid choice\n");
        break;
    }
    return 0;
}