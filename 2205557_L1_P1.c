#include<stdio.h>
struct student{
    char name[50];
    char gender[12];
    int roll;
    int age;
    float marks;
};
void display(struct student *x)
{
    printf("Age: %d, Roll No.: %d, Name: %s, Gender: %s, Marks:%f", x->age, x->roll, x->name, x->gender, x->marks);
}
int main()
{
    struct student s;
    struct student *ptr = &s;
    printf("Enter name:\n");
    scanf("%[^\n]s", &s.name);
    printf("Enter age:\n");
    scanf("%d", &s.age);
    printf("Enter roll:\n");
    scanf("%d",&s.roll);
    fflush(stdin);
    printf("Enter gender:\n");
    scanf("%[^\n]s", &s.gender);
    printf("Enter marks\n");
    scanf("%f", &s.marks);
    display(ptr);
    return 0;
}