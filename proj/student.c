//
// student.c
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"
#include "encrypt.h"


const char* STUFILE = "studentdata.txt";

// keeps track of the number of students in the students array
int numStudents = 0;

// holds the student pointer array
Student* students[100] = {0};


void createStudent(char* fname, char* lname, int age, int id)
{
  Student* st = (Student*)malloc(sizeof(Student));
  char* firstname = (char*)malloc(50*sizeof(fname));
  firstname = fname;
  char* lastname = (char*)malloc(50*sizeof(lname));
  lastname = lname;
  st->firstName = firstname;
  st->lastName = lastname;
  st->age = age;
  st->id = id;
  students[numStudents] = st;
  numStudents++;
  // createStudent dynamically creates a Student on the heap and adds that
  // student to the student array
  //  - the firstName and lastName strings should be dynamically created
  //    based on the size of the fname and lname args


}


void deleteStudent(Student* student)
{
  free(student->firstName);
  free(student->lastName);
  free(student);
  // free the memory associated with a student including the strings
}


void deleteStudents()
{
  // iterate over the students array deleting every student and setting te pointer
  // values to 0 and adjusting the numStudents to 0
  for(int i = 0; i < numStudents; i++){
    deleteStudent(students[i]);
    students[i]->firstName = 0;
    students[i]->lastName = 0;
  }
  numStudents = 0;
}


void saveStudents(int key)
{
FILE* fp;
fp = fopen(STUFILE, "w");
if (fp) 
{
  for(int i = 0; i < numStudents; i++)
    //add encryption for key later students[i].fname+=key;
    fprintf(fp, "%s %s %d %lu\n", students[i]->firstName, students[i]->lastName, students[i]->age, students[i]->id);
  fclose(fp);
}
  // save all students in the student array to a file 'studentdata.txt' overwriting
  // any existing file
  //   - the format of the file is one line per student as follows fname lname age id:
  //       tom thumb 15 1234 
  //       james dean 21 2345 
  //       katy jones 18 4532 
}


void loadStudents(int key)
{
  // load the students from the data file overwriting all exisiting students in memory
  FILE* fp;
  fp = fopen("studentdata.txt", "r");
  if (fp) 
  {
    numStudents = 0;
    while (1)
    {
      char* fname = (char*)malloc(50 * sizeof(char)); char* lname = (char*)malloc(50 * sizeof(char)); int age; long unsigned int id;
      if (fscanf(fp, "%s %s %d %lu\n", fname, lname, &age, &id) == 2)
      {
        //printf("test");
        //students[numStudents]->firstName = fname;
        //students[numStudents]->lastName = lname;
        //students[numStudents]->age = age;
        //students[numStudents]->id = id;
        //numStudents++;
      }
      else
      {
        free(fname);
        free(lname);
        break;
      }
      fclose(fp);
    }
  }
}


void printStudent(Student* student)
{
  printf("  Student: %s %s\n", student->firstName, student->lastName);
  printf("    age: %d\n", student->age);
  printf("    id: %ld\n", student->id); 
}


void printStudents()
{
  for (int i = 0; i < numStudents; i++) {
    printf("\n----- student %d ------\n", i);
    printStudent(students[i]);
  }
}




