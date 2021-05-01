#include <stdio.h>
#include "student-score-util.h"

FILE *fl;

FILE *configure_file(char opr[])
{
    fl = fopen("fnilai.dat", opr);
}

void close_file()
{
    fclose(fl);
}

int read_student_data()
{
    return fread(&student, sizeof(student), 1, fl);
}

void save_student_data(struct Student_Data data)
{
    fwrite(&data, sizeof(data), 1, fl);
    close_file();
}

void seek_file_position(int offset)
{
    fseek(fl, offset, SEEK_SET);
}