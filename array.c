// // Addition of 2 Numbers using Array


// #include<stdio.h>
// #include<conio.h>

// void main()
// {
//     int num[1], i;

//     printf("Enter the 1ts Number :");
//     scanf("%d",&num[0]);

//     printf("Enter the 2nd Number :");
//     scanf("%d",&num[1]);

//     i = num[0] + num[1];

//     printf("Addition of 2 Numbers : %d",i);

// }


// #include<stdio.h>

// void main() {
//     int no[2], n;
//     printf("Enter a number: ");
//     scanf("%d", &no[0]);  
//     printf("Enter another number: ");
//     scanf("%d", &no[1]);  
//     n = no[0] + no[1];    
//     printf("Sum of the two numbers: %d\n", n);
// }




// Structured syntax of C program

#include<stdio.h>
#include<conio.h>

struct student
{
    char name[50];
    int roll;
    float marks;
    
};

void main()
{
    struct student s[3];
    int i;

    // Take information for 3 students 
    for (i = 0; i < 3; i++)
    {
        printf("Enter information of student %d\n", i+1);
        
        printf("Enter name : ");
        scanf("%s", s[i].name);

        printf("Enter roll number : ");
        scanf("%d", &s[i].roll);

        printf("Enter marks : ");
        scanf("%f", &s[i].marks);
    }

    // Displaying information of students

    for (i = 0; i < 3; i++)
    {
        printf("------------------------------------------------------------");
        printf("Information of student %d\n", i+1);
        printf("Name : %s\n", s[i].name);
        printf("Roll number : %d\n", s[i].roll);
        printf("Marks : %.2f\n", s[i].marks);
    }
    

}