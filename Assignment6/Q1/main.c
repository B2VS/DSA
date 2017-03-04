#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student
{
    char name[100];
    char branch[100];
    float cgpa;
    int year;
    int group;
    struct Student *next;
} Student;

void input(Student *s)
{
    int i;
    printf("\n");
    for (i = 0; s != NULL; ++i)
    {
        gets(s->name);
        printf("Student %d\n", i + 1);
        printf("Enter name: ");
        gets(s->name);
//        printf("Enter branch: ");
//        gets(s->branch);
//        printf("Enter CGPA: ");
//        scanf("%f", &(s->cgpa));
//        printf("Enter year: ");
//        scanf("%d", &(s->year));
        printf("Enter group number: ");
        scanf("%d", &(s->group));
        printf("\n");
        s = s->next;
    }
}

void output(Student *s)
{
    int i;
    for (i = 0; s != NULL; ++i)
    {
        printf("Student %d\n", i + 1);
        printf("Name: ");
        puts(s->name);
//        printf("Branch: ");
//        puts(s->branch);
//        printf("CGPA: ");
//        printf("%f\n", s->cgpa);
//        printf("Year: ");
//        printf("%d\n", s->year);
        printf("Group number: ");
        printf("%d\n", s->group);
        printf("\n");
        s = s->next;
    }
}

int main()
{
    int n, i;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    Student *h, *prev, *curr, *gs[3], *ge[3];
    for (i = 0; i < n; ++i)
    {
        curr = (Student *) malloc (sizeof(Student));
        if (i == 0)
            h = curr;
        else
            prev->next = curr;
        prev = curr;
    }
    curr->next = NULL;
    input(h);
    curr = h;
    gs[0] = gs[1] = gs[2] = ge[0] = ge[1] = ge[2] = NULL;
    while(curr != NULL)
    {
        int index = curr->group - 1;
        if (gs[index] == NULL)
            gs[index] = ge[index] = curr;
        else
        {
            ge[index]->next = curr;
            ge[index] = curr;
        }
        prev = curr;
        curr = curr->next;
        prev->next = NULL;
    }
    output(gs[0]);
    output(gs[1]);
    output(gs[2]);
}
