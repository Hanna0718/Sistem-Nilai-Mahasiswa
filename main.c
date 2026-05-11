#include <stdio.h>
#include <stdlib.h>

int main()
{
    int menu;
    int n = 0;
    char nama[50][50];
    int nilai[50];

    do {
        printf("\n===== SISTEM PENGELOMPOKKAN NILAI UJIAN =====\n");
        printf("1. Input Data Mahasiswa\n");
        printf("2. Tampilkan Data & Grade\n");
        printf("3. Sorting Nilai (Tertinggi -> Terendah)\n");
        printf("4. Cari Mahasiswa (Searching)\n");
        printf("5. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &menu);

        // ======================= MENU =======================
        switch(menu) {

        // -------------------- MENU 1 --------------------
        case 1:
            printf("\nMasukkan jumlah mahasiswa: ");
            scanf("%d", &n);

            for(int i = 0; i < n; i++) {
                printf("\nNama mahasiswa ke-%d: ", i+1);
                scanf("%s", nama[i]);

                printf("Nilai: ");
                scanf("%d", &nilai[i]);
            }
            printf("\nData berhasil disimpan!\n");
            break;

        // -------------------- MENU 2 --------------------
        case 2:
            if(n == 0) {
                printf("\nData masih kosong!\n");
                break;
            }

            printf("\n===== DATA MAHASISWA =====\n");
            for(int i = 0; i < n; i++) {
                char grade;

                if(nilai[i] >= 85) grade = 'A';
                else if(nilai[i] >= 75) grade = 'B';
                else if(nilai[i] >= 65) grade = 'C';
                else if(nilai[i] >= 50) grade = 'D';
                else grade = 'E';

                printf("%d. %s - Nilai: %d - Grade: %c\n",
                       i+1, nama[i], nilai[i], grade);
            }
            break;

        // -------------------- MENU 3 --------------------
        case 3:
            if(n == 0) {
                printf("\nData masih kosong!\n");
                break;
            }

            // Bubble Sort (Descending)
            for(int i = 0; i < n-1; i++) {
                for(int j = 0; j < n-1-i; j++) {
                    if(nilai[j] < nilai[j+1]) {
                        // Tukar nilai
                        int tempNilai = nilai[j];
                        nilai[j] = nilai[j+1];
                        nilai[j+1] = tempNilai;

                        // Tukar nama
                        char tempNama[50];
                        strcpy(tempNama, nama[j]);
                        strcpy(nama[j], nama[j+1]);
                        strcpy(nama[j+1], tempNama);
                    }
                }
            }

            printf("\nNilai berhasil diurutkan!\n");
            for(int i = 0; i < n; i++) {
                printf("%d. %s - %d\n", i+1, nama[i], nilai[i]);
            }
            break;

        // -------------------- MENU 4 --------------------
        case 4:
            if(n == 0) {
                printf("\nData masih kosong!\n");
                break;
            }

            char cari[50];
            int ketemu = 0;

            printf("\nMasukkan nama mahasiswa yang dicari: ");
            scanf("%s", cari);

            for(int i = 0; i < n; i++) {
                if(strcmp(nama[i], cari) == 0) {
                    char grade;

                    if(nilai[i] >= 85) grade = 'A';
                    else if(nilai[i] >= 75) grade = 'B';
                    else if(nilai[i] >= 65) grade = 'C';
                    else if(nilai[i] >= 50) grade = 'D';
                    else grade = 'E';

                    printf("\nData ditemukan!\n");
                    printf("Nama  : %s\n", nama[i]);
                    printf("Nilai : %d\n", nilai[i]);
                    printf("Grade : %c\n", grade);
                    ketemu = 1;
                    break;
                }
            }

            if(ketemu == 0) {
                printf("\nNama tidak ditemukan!\n");
            }
            break;

        // -------------------- MENU 5 --------------------
        case 5:
            printf("\nProgram selesai.\n");
            break;

        default:
            printf("\nMenu tidak valid!\n");
        }

    } while(menu != 5);



    return 0;
}
