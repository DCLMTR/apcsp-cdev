#include <stdio.h>
#include <string.h>

// student structure
//struct Student...
struct Student {
  char firstname[100];
  char lastname[100];
  int age;
  int studentid;
};

void printStudent(struct Student* student)
{
printf("----student----\nStudent: %s %s\nage: %d\nid: %d\n", student->firstname, student->lastname, student->age, student->studentid);
}


void printAllStudents(struct Student students[], int num)
{
  // call printStudent for each student in students
  for(int i = 0; i < num; i++){
    printStudent(&students[i]);
  }
}


int main()
{
  char input[256];
  // an array of students
  //xxx students;
  struct Student students[100];
  int numStudents = 0;
  while (1)
  {
    char c;
    printf("\nEnter a to add, p to print, q to quit:");
    fgets(input, 256, stdin);
    if (sscanf(input, "%c", &c) != 1) continue;
    if (c == 'q') 
    {
      break;
    }
    else if (c == 'p')
    {
      // print all students
      printAllStudents(students, numStudents);
      continue;
    }
    else if (c == 'a')
    {
      // enter a new student
      printf("\nFirst Name: ");
      fgets(input, 256, stdin);
      sscanf(input, "%s", students[numStudents].firstname);
      printf("\nLast Name: ");
      fgets(input, 256, stdin);
      sscanf(input, "%s", students[numStudents].lastname);
      printf("\nEnter age: ");
      fgets(input, 256, stdin);
      sscanf(input, "%d", &students[numStudents].age);
      printf("\nEnter id: ");
      fgets(input, 256, stdin);
      sscanf(input, "%d", &students[numStudents].studentid);
      numStudents++;
    }
  }
  
  printf("\nGoodbye!\n");
}
