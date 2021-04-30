#ifndef STUDENT_SCORE_UTIL_H
#define STUDENT_SCORE_UTIL_H

struct Student_Data
{
    char NIM[10], name[15], q_letter;
    float quiz_score, task_score, mid_exam_score, final_exam_score, final_score;
} student;

void print_data(struct Student_Data data)
{
    printf("NIM             : %s\n", data.NIM);
    printf("Nama            : %s\n", data.name);
    printf("Nilai Tugas     : %.2f\n", data.task_score);
    printf("NIlai Quiz      : %.2f\n", data.quiz_score);
    printf("Nilai UTS       : %.2f\n", data.mid_exam_score);
    printf("Nilai UAS       : %.2f\n", data.final_exam_score);
    printf("Nilai Akhir     : %.2f\n", data.final_score);
    printf("Huruf Mutu      : %c\n", data.q_letter);
    printf("\n");
}

void print_letter_statistic(
    int aLtr,
    int bLtr,
    int cLtr,
    int dLtr,
    int eLtr
)
{
    printf("---------\n");
    printf("  A | %d\n", aLtr);
    printf("  B | %d\n", bLtr);
    printf("  C | %d\n", cLtr);
    printf("  D | %d\n", dLtr);
    printf("  E | %d\n", eLtr);
    printf("---------\n\n");
}

#endif
