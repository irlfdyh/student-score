#include <stdlib.h>
#include "student-score-file.h"

void starter_program();
void operation_menu();
void operation_determiner();
void operation_processor(int option);
void add_student_data();
void get_all_student_data();
void get_student_data_by_NIM();
void update_student_data();
void calculate_Q_letter();
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
            calculate_Q_letter();
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

}

void get_all_student_data()
{

}

void get_student_data_by_NIM()
{

}

void update_student_data()
{

}

void calculate_Q_letter()
{

}

void throw_exception()
{
    puts("Data tidak ditemukan, coba untuk menambahkan data di menu 1.\n");
    operation_menu();
}