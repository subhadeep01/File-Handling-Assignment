#include<stdio.h> // Declaration of header files
#include<string.h>
struct student // Creating structures
{
 char name[50];
 int roll_no;
 int marks;
};

int main()
{
 struct student arr_student[5], t;
 for(int i = 0; i < 5; i++ )
 {
   printf("Enter details of student %d\n", i+1);
   printf("Enter name: ");
   scanf("%s", arr_student[i].name);
   printf("Enter roll no: ");
   scanf("%d", &arr_student[i].roll_no);
   printf("Enter marks: \n");
   scanf("%d", &arr_student[i].marks);
 }
 printf("\n");
 FILE *fp;
 fp = fopen("datafile.dat", "w+");
 fwrite(arr_student, sizeof(struct student), sizeof(arr_student), fp);
 fread(arr_student, sizeof(struct student), sizeof(arr_student), fp);
 printf("Array of Structures before sorting : \n");
 for(int i = 0; i < 5; i++ )
 {
   printf("Name: %s, Roll: %d, Marks: %d\n", arr_student[i].name,
   arr_student[i].roll_no, arr_student[i].marks);
 }
 printf("\nArray of Structures after sorting : \n");
 for(int i=0;i<5;i++) // Sorting marks in descending order
 {
  for(int j=0;j<4;j++)
  {
    if(arr_student[j].marks < arr_student[j+1].marks)
    {
      t = arr_student[j];
      arr_student[j] = arr_student[j+1];
      arr_student[j+1] = t;
    }
  }
 }
 for(int i = 0; i <5; i++ )
 {
  printf("Name: %s, Roll: %d, Marks: %d\n", arr_student[i].name,
  arr_student[i].roll_no, arr_student[i].marks);
 }
 FILE *fp1;
 fp1 = fopen("sorteddatafile.dat", "w+");
 fwrite(arr_student, sizeof(struct student), sizeof(arr_student), fp1);
 fclose(fp);
 fclose(fp1);
 return 0;
}
