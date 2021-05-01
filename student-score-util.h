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
) {
    printf("---------\n");
    printf("  A | %d\n", aLtr);
    printf("  B | %d\n", bLtr);
    printf("  C | %d\n", cLtr);
    printf("  D | %d\n", dLtr);
    printf("  E | %d\n", eLtr);
    printf("---------\n\n");
}

char calculate_Q_letter(float fs)
{
	if (fs >= 80 && fs <= 100)
    {
		return 'A';
	}
	else if (fs >= 68 && fs <=79 )
    {
		return 'B';
	} 
	else if (fs >= 45 && fs<= 67) 
    {
		return 'C';
	}
	else if (fs >= 31 && fs <= 44)
    {
		return 'D';
	}
	else if (fs >= 0 && fs <= 30)
    {
		return 'E';
	}
	else
	{
		return 'Z';
	}
}

float calculate_final_score(
    float nilai_tugas, 
    float nilai_quiz, 
    float nilai_UTS, 
    float nilai_UAS
) {
	return  (0.2 * nilai_quiz) + 
            (0.2 * nilai_tugas) + 
            (0.3 * nilai_UTS) + 
            ( 0.3 *nilai_UAS);
}

// get string input to allowing space
void ginps(char obj[], int mvl)
{
    char c; int i = 0, end = 0;
    do
    {
        c = getchar();
        if (c == '\n' || i > mvl)
        {
            end++;
        }
        else
        {
            obj[i] = c;
            i++;
        }
    }
    while (end == 1);
}

#endif
