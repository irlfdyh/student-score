#include <stdlib.h>
#include <string.h>
#include "student-score-file.h"

#define MAX_NAME 15
#define MAX_NIM 8

void starter_program();
void operation_menu();
void operation_determiner();
void operation_processor(int option);
void add_student_data();
void get_all_student_data();
void get_student_data_by_NIM();
void update_student_data();
void get_Q_letter_statistics();
void throw_exception();

int main()
{
    starter_program();
    return 0;
}

void starter_program()
{   
    puts("\nPROGRAM PENCATATAN NILAI MAHASISWA\n");
    operation_menu();
}

void operation_menu()
{
    puts("Pilih operasi yang akan dilakukan :");
    puts("1. Menambahkan data mahasiswa");
    puts("2. Melihat seluruh data mahasiswa");
    puts("3. Melihat data mahasiswa berdasarkan NIM");
    puts("4. Mengubah data mahasiswa berdasarkan NIM");
    puts("5. Mengkalkulasi Huruf Mutu");
    puts("0. Keluar");
    operation_determiner();
}

void operation_determiner()
{
    short int option;
    printf("Pilihan : "); scanf("%hd", &option);
    operation_processor(option);
}

void operation_processor(int option)
{
    puts("");
    switch (option)
    {
        case 0 : 
        {
            puts("Keluar.");
            exit(1);
            break;
        }
        case 1 : 
        {
            add_student_data();
            break;
        }
        case 2 : 
        {
            get_all_student_data();
            break;
        }
        case 3 : 
        {
            get_student_data_by_NIM();
            break;
        }
        case 4 : 
        {
            update_student_data();
            break;
        }
        case 5 : 
        {
            get_Q_letter_statistics();
            break;
        }
        default : 
        {
            puts("Pilihan tidak valid!!");
            puts("Ulangi penginputan\n");
            operation_determiner();
            break;
        }
    }
}

void add_student_data()
{
    float	nilai_akhir, nilai_tugas, nilai_quiz, 
            nilai_UTS, nilai_UAS;
	struct Student_Data std;

    if (configure_file("a") == NULL)
    {
		throw_exception();
    }

    printf("Masukan NIM     : ");
    scanf("%s", std.NIM);
    printf("Nama            : ");
    ginps(std.name, MAX_NAME);
    printf("Nilai Tugas     : ");
    scanf("%f", &nilai_tugas); fflush(stdin);
    printf("Nilai Quiz      : ");
    scanf("%f", &nilai_quiz); fflush(stdin);
    printf("Nilai UTS       : ");
    scanf("%f", &nilai_UTS); fflush(stdin);
    printf("Nilai UAS       : ");
    scanf("%f", &nilai_UAS); fflush(stdin);

    nilai_akhir = calculate_final_score(nilai_tugas, nilai_quiz, nilai_UTS, nilai_UAS);

    std.task_score = nilai_tugas;
    std.mid_exam_score = nilai_UTS;
    std.quiz_score = nilai_quiz;
    std.final_exam_score = nilai_UAS;
    std.final_score = nilai_akhir;
    std.q_letter = calculate_Q_letter(nilai_akhir);

    puts("\nOK\n");
    save_student_data(std);
    operation_menu();
}

void get_all_student_data()
{
    if (configure_file("rb") == NULL)
    {
		throw_exception();
    }
    while (read_student_data() == 1) {
        print_data(student);
    }
    close_file();
    operation_menu();
}

void get_student_data_by_NIM()
{
    char q[8];
    int ict = 0;

    if (configure_file("rb") == NULL)
    {
        throw_exception();
    }
    printf("Masukkan NIM    : ");
    scanf("%s", q); fflush(stdin);

    puts(" ");

    while (read_student_data() == 1)
    {
        if (strcmp(student.NIM, q) == 0)
        {
            ict++;
	        print_data(student);
        }
    }

    if (ict < 1)
    {
        throw_exception();
    }

    close_file();
    operation_menu();
}

void update_student_data()
{
    char q[8];
    int ict = 0;
	struct Student_Data std;

    if (configure_file("rb+") == NULL)
    {     
        throw_exception();
    }

    printf("Masukkan NIM :  ");
    scanf("%s", q); fflush(stdin);

    while (read_student_data() == 1)
    {
        ict++;
        if (strcmp(student.NIM, q) == 0)
        {
            break;
        }
    }

    int offset_byte = (ict - 1) * sizeof(student);
    seek_file_position(offset_byte);

    int result = read_student_data();
    float nilai_tugas, nilai_quiz, nilai_uts, nilai_uas, nilai_akhir;
	
    if (result == 0)
    {
		throw_exception();
    }
    else 
    {
        puts("\nData Sebelumnya ");
        print_data(student);
        puts("Masukkan data nilai yang baru :");
        printf("Nilai Tugas     : ");
        scanf("%f", &nilai_tugas);
        printf("NIlai Quiz      : ");
        scanf("%f", &nilai_quiz);
        printf("Nilai UTS       : ");
        scanf("%f", &nilai_uts);
        printf("NIlai UAS       : ");
        scanf("%f", &nilai_uas);
        
        nilai_akhir = calculate_final_score(nilai_tugas, nilai_quiz, nilai_uts, nilai_uas);

        cpy_ar(std.NIM, student.NIM, MAX_NIM);
        cpy_ar(std.name, student.name, MAX_NAME);
        std.task_score = nilai_tugas;
        std.mid_exam_score = nilai_uts;
        std.quiz_score = nilai_quiz;
        std.final_exam_score = nilai_uas;
        std.final_score = nilai_akhir;
        std.q_letter = calculate_Q_letter(nilai_akhir);	

        seek_file_position(offset_byte);
        save_student_data(std);

        printf("\n");
        operation_menu();
    }
}

void get_Q_letter_statistics()
{
    int aLtr = 0,
        bLtr = 0,
        cLtr = 0,
        dLtr = 0,
        eLtr = 0,
        ict = 0;

    if (configure_file("rb") == NULL)
    {
        throw_exception();
    }

    while (read_student_data() == 1)
    {
        ict++;
        switch (student.q_letter)
        {
            case 'A' : aLtr++; break;
            case 'B' : bLtr++; break;
            case 'C' : cLtr++; break;
            case 'D' : dLtr++; break;
            case 'E' : eLtr++; break;
        }
    }

    if (ict < 1)
    {
        throw_exception();
    }
    else 
    {
        puts("Tabel statistik nilai mutu mahasiswa");
        print_letter_statistic(aLtr, bLtr, cLtr, dLtr, eLtr);
        close_file();
        operation_menu();
    }
}

void throw_exception()
{
    puts("Data tidak ditemukan, coba untuk menambahkan data di menu 1.\n");
    operation_menu();
}
