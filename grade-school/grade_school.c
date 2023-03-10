/*
    This program create a roster for the school.
    The program includes functions to initialize a roster, add a student to the roster, compare two rosters, and get a roster for a specific grade.
*/

#include "grade_school.h"
#include <string.h>

// Initialize a roster by setting the count to 0
void init_roster(roster_t *actual)
{
    actual->count=0;
}

_Bool add_student(roster_t *actual,char* new_name, uint8_t new_grade)
{
    _Bool flag=1;
    int i;

    if(actual->count >= MAX_STUDENTS)
        flag=0;// Maximum of number of students added.
    for(i=0;i<actual->count;i++)
    {
        //Check if the new student name is already in the roaster.
        if(strcmp(actual->students[i].name,new_name) == 0)
        {
            flag=0;
        }
    }
    //If the flag is still true a new student is added to the roaster.
    if(flag!=0)
    {
        strcpy(actual->students[actual->count].name,new_name);// Copy the name
        actual->students[actual->count].grade=new_grade; // Copy the grade
        actual->count++; // Increment the count of students
        qsort(actual->students,actual->count,sizeof(student_t),compare_roster); // Sort the roaster using 'qsort' function
        /*
        The structures is sort in ascending order of the grade, then by ascending order of the name within each grade
        */
        flag=1;
    }
    return flag;
}

//The function compare two students in the roaster by grade and name.
int compare_roster(const void* a, const void* b)
{
    student_t *s1=(student_t *)a;//cast 'a' and 'b' into 'student_t' pointer
    student_t *s2=(student_t *)b;
    int flag=0;
    //First it compares the grade
    if(s1->grade > s2->grade)
        flag=1;
    else if(s1->grade < s2->grade)
        flag=-1;
    //If student's are at the same grade it compares the name of students
    if(strcmp(s1->name,s2->name)>0&&flag==0)
        flag=1;
    else if(strcmp(s1->name,s2->name)<0&&flag==0)
        flag=-1;

    return flag;//It returns the 'flag' which is used by 'qsort'
}

roster_t get_grade(roster_t *actual,int desired_grade)
{
    roster_t grade;
    int i;
    init_roster(&grade);

    // Loop through each student in the actual roster
    for(i=0;i<actual->count;i++)
    {
        // If the student's grade matches the desired grade, add them to the new roster
        if(actual->students[i].grade==desired_grade)
        {
            add_student(&grade,actual->students[i].name,actual->students[i].grade);
        }
    }
    return grade;
}
