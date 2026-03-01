#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
#define FILE_NAME "student.txt"
struct student
{
    int roll_no;
    char name[50];
    char course[50];
    int marks;
};
void add_record()
{
    struct student s;
    FILE *fp;
    fp = fopen(FILE_NAME, "ab");
    if (fp == NULL)
    {
        printf("File not found\n");
        return;
    }
    printf("Enter roll no: ");
    scanf("%d", &s.roll_no);
    printf("Enter name: ");
    scanf("%s", s.name);
    printf("Enter course: ");
    scanf("%s", s.course);
    printf("Enter marks: ");
    scanf("%d", &s.marks);
    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);
    printf("Record added successfully\n");
}
void delete_record()
{
    struct student s;
    FILE *fp, *temp;
    int roll_no, found = 0;
    fp = fopen(FILE_NAME, "rb");
    temp = fopen("temp.txt", "wb");
    if (fp == NULL || temp == NULL)
    {
        printf("File not found\n");
        return;
    }
    printf("Enter roll no to delete: ");
    scanf("%d", &roll_no);
    while(fread(&s, sizeof(s), 1, fp) == 1)
    {
        if(s.roll_no != roll_no)
        {
            fwrite(&s, sizeof(s), 1, temp);
        }
        else
        {
            found = 1;
        }
    }
    fclose(fp);
    fclose(temp);
    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);
    if (found == 1)
    {
        printf("Record deleted successfully\n");
    }
    else
    {
        printf("Record not found\n");
    }
}
void update_record()
{
    struct student s;
    FILE *fp, *temp;
    int roll_no, found = 0;
    fp = fopen(FILE_NAME, "rb");
    temp = fopen("temp.txt", "wb");
    if (fp == NULL || temp == NULL)
    {
        printf("File not found\n");
        return;
    }
    printf("Enter roll no to update: ");
    scanf("%d", &roll_no);
    while(fread(&s, sizeof(s), 1, fp) == 1)
    {
        if(s.roll_no == roll_no)
        {
            printf("Enter new name: ");
            scanf("%s", s.name);
            printf("Enter new course: ");
            scanf("%s", s.course);
            printf("Enter new marks: ");
            scanf("%d", &s.marks);
            found = 1;
        }
        fwrite(&s, sizeof(s), 1, temp);
    }
    fclose(fp);
    fclose(temp);
    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);
    if (found == 1)
    {
        printf("Record updated successfully\n");
    }
    else
    {
        printf("Record not found\n");
    }
}
void search_record()
{
    struct student s;
    FILE *fp;
    int roll_no, found = 0;
    fp = fopen(FILE_NAME, "rb");
    if (fp == NULL)
    {
        printf("File not found\n");
        return;
    }
    printf("Enter roll no to search: ");
    scanf("%d", &roll_no);
    while(fread(&s, sizeof(s), 1, fp) == 1)
    {
        if(s.roll_no == roll_no)
        {
            printf("Name: %s\n", s.name);
            printf("Course: %s\n", s.course);
            printf("Marks: %d\n", s.marks);
            found = 1;
            break;
        }
    }
    fclose(fp);
    if (found == 0)
    {
        printf("Record not found\n");
    }
}
void display_record()
{
    struct student s;
    FILE *fp;
    fp = fopen(FILE_NAME, "rb");
    if (fp == NULL)
    {
        printf("File not found\n");
        return;
    }
   while(fread(&s, sizeof(s), 1, fp) == 1)
    {
        printf("Roll No: %d\n", s.roll_no);
        printf("Name: %s\n", s.name);
        printf("Course: %s\n", s.course);
        printf("Marks: %d\n\n", s.marks);
    }
    fclose(fp);
}
int main()
{
    int choice;
    while (1)
    {
        printf("1. Add Record\n");
        printf("2. Delete Record\n");
        printf("3. Update Record\n");
        printf("4. Search Record\n");
        printf("5. Display Record\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {

            case 1:
                add_record();
                break;
            case 2:
                delete_record();
                break;
            case 3:
                update_record();
                break;
            case 4:
                search_record();
                break;
            case 5:
                display_record();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choicce\n");
        }
    }
    return 0;
}
