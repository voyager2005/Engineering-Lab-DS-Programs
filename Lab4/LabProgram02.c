// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>

#define MAX_LEN 500
// creating structure
struct Student{
    char name[MAX_LEN];
    int roll_no;
    float CGPA;
};


void main()
{
    // declaration and initialization
    int total_records, i, j;


    // reading the number of entries from the user
    printf("How many student records are to be enterd?: ");
    scanf("%d", &total_records);

    // creating a structure of size [total records]
    struct Student student[total_records];

    // reading student record from the user
    for(i = 0; i < total_records; i++)
    {
        printf("Please enter student name: ");
        scanf("%s", student[i].name);
        printf("Please enter student roll number: ");
        scanf("%d", &(student[i].roll_no));
        printf("Please enter student CGPA: ");
        scanf("%f", &(student[i].CGPA));
    }

    // bubble sort algorthm so sort the student records in roll number order
    for(i =0; i < total_records; i++)
    {
        for(j = i; j < total_records-i-1; j++)
        {
            if(student[i].roll_no>student[j].roll_no)
            {
                // swapping information
                int student_holder = student[i].roll_no;
                student[i].roll_no = student[j].roll_no;
                student[j].roll_no = student_holder;
            }
        }
    }

    // displaying the sorted student array
    for(i = 0; i < total_records; i++)
    {
        printf("Student %d records: \n", (i+1));
        printf("\nroll number: %d", student[i].roll_no);
        printf("\nstudent name: %s", student[i].name);
        printf("\nCGPA: %f", student[i].CGPA);
        printf("\n\n");
    }
}
