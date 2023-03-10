#ifndef GRADE_SCHOOL_H
#define GRADE_SCHOOL_H

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 20
#define MAX_STUDENTS 20

typedef struct {
   uint8_t grade;
   char name[MAX_NAME_LENGTH];
} student_t;

typedef struct {
   size_t count;
   student_t students[MAX_STUDENTS];
} roster_t;

void init_roster(roster_t *actual);
_Bool add_student(roster_t *actual,char* new_name, uint8_t new_grade);
int compare_roster(const void* a, const void* b);
roster_t get_grade(roster_t *actual,int desired_grade);

#endif
