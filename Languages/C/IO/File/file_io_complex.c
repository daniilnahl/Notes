#include <stdio.h>
#include <stdlib.h>

// Structure to represent a student
typedef struct {
    int id;
    char name[50];
    float marks;
} Student;

int main() {
    // Writing student data to a binary file
    FILE *outfile_bin = fopen("students.dat", "wb");
    if (outfile_bin == NULL) {
        perror("Error opening binary output file");
        return 1;
    }
    Student student1 = {1, "Alice", 85.5};
    Student student2 = {2, "Bob", 92.0};
    fwrite(&student1, sizeof(Student), 1, outfile_bin);
    fwrite(&student2, sizeof(Student), 1, outfile_bin);
    fclose(outfile_bin);
    printf("Student data written to students.dat\n");

    // Reading student data from the binary file
    FILE *infile_bin = fopen("students.dat", "rb");
    if (infile_bin == NULL) {
        perror("Error opening binary input file");
        return 1;
    }
    Student read_student;
    printf("\nReading student data from students.dat:\n");
    while (fread(&read_student, sizeof(Student), 1, infile_bin) == 1) {
        printf("ID: %d, Name: %s, Marks: %.2f\n", read_student.id, read_student.name, read_student.marks);
    }
    fclose(infile_bin);

    // Writing formatted text data to a file
    FILE *outfile_txt = fopen("grades.txt", "w");
    if (outfile_txt == NULL) {
        perror("Error opening text output file");
        return 1;
    }
    fprintf(outfile_txt, "Student ID: %d, Grade: A\n", student1.id);
    fprintf(outfile_txt, "Student ID: %d, Grade: A+\n", student2.id);
    fclose(outfile_txt);
    printf("\nGrades written to grades.txt\n");

    // Reading formatted text data from a file
    FILE *infile_txt = fopen("grades.txt", "r");
    if (infile_txt == NULL) {
        perror("Error opening text input file");
        return 1;
    }
    int id;
    char grade[10];
    printf("\nReading grades from grades.txt:\n");
    while (fscanf(infile_txt, "Student ID: %d, Grade: %s", &id, grade) == 2) {
        printf("ID: %d, Grade: %s\n", id, grade);
    }
    fclose(infile_txt);

    return 0;
}