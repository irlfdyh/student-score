#include <stdlib.h>
#include <string.h>
#include "student-score-file.h"

void starter_program();
void operation_menu();
void operation_determiner();
void operation_processor(int option);
void add_student_data();
void get_all_student_data();
void get_student_data_by_NIM();
void update_student_data();
void get_Q_letter_statistics();
char calculate_Q_letter(float fs);
void throw_exception();

int main()
{
    starter_program();
    return 0;
}

void starter_program()
{   
    puts("\nPROGRAM PENILAIAN MAHASISWA\n");
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
	float nilai_akhir, nilai_tugas, nilai_UTS, nilai_quiz, nilai_UAS;

	if(configure_file("a")==NULL){
		throw_exception();
	}

    printf("Masukan NIM = ");
    scanf("%s", student.NIM); fflush(stdin);
    printf("Nama = ");
    scanf("%s", student.name); fflush(stdin);
    printf("Nilai Tugas = ");
    scanf("%f", &nilai_tugas); fflush(stdin);
    printf("Nilai Quiz = ");
    scanf("%f", &nilai_quiz); fflush(stdin);
    printf("Nilai UTS = ");
    scanf("%f", &nilai_UTS); fflush(stdin);
    printf("Nilai UAS = ");
    scanf("%f", &nilai_UAS); fflush(stdin);

    nilai_akhir = (0.2 * nilai_quiz) + (0.2 * nilai_tugas) + (0.3 * nilai_UTS) + ( 0.3 *nilai_UAS);

    student.task_score = nilai_tugas;
    student.mid_exam_score = nilai_UTS;
    student.quiz_score = nilai_quiz;
    student.final_exam_score = nilai_UAS;
    student.final_score = nilai_akhir;
    student.q_letter = calculate_Q_letter(nilai_akhir);

    puts("\nOK\n");
    save_student_data(student);
    close_file();
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
    printf("masukkan NIM anda = ");
    scanf("%s", q); fflush(stdin);

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

char calculate_Q_letter(float fs)
{
	if(fs >= 80 && fs <= 100)
    {
		return 'A';
	}
	else if(fs >= 68 && fs <=79 )
    {
		return 'B';
	} 
	else if(fs >= 45 && fs<= 67) 
    {
		return 'C';
	}
	else if(fs >= 31 && fs <= 44)
    {
		return 'D';
	}
	else if(fs >= 0 && fs <= 30)
    {
		return 'E';
	}
	else
	{
		return 'Z';
	}
}

void throw_exception()
{
    puts("Data tidak ditemukan, coba untuk menambahkan data di menu 1.\n");
    operation_menu();
}