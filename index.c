#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct pasien{
    int idpasien;
    char namapasien[50];
    char alamatpasien[50];
    char jeniskelamin[20];
    char notelpon[15];
    char date[12];
}p;

struct dokter{
    int iddokter;
    char namadokter[50];
    char alamatdokter[50];
    char jeniskelamindokter[20];
    char notelpondokter[15];
    char date[12];
}d;

struct pemeriksaan{
    int koderesep;
    char datepemeriksaan[12];
    char keluhan[50];
    int idpasienpemeriksaan;
    char namapasienpemeriksaan[50];
    char alamatpasienpemeriksaan[50];
    char jeniskelaminpemeriksaan[20];
    char notelponpemeriksaan[15];
    char datepasienpemeriksaan[12];
    int iddokterpemeriksaan;
    char namadokterpemeriksaan[50];
    char alamatdokterpemeriksaan[50];
    char jeniskelamindokterpemeriksaan[20];
    char notelpondokterpemeriksaan[15];
    char datedokterpemeriksaan[12];
}m;

FILE *fp;
FILE *fpDokter;
FILE *fpmeriksa;

int main(){

    int ch;

    while(1){
        system("cls");
        printf("         <===========================================================================>\n");
        printf("         |     Selamat Datang di Sistem Pendaftaran Pasien Rumah Sakit Gunadarma     |\n");
        printf("         |               Kota Depok, Jawa Barat  (021) 29428935                      |\n");
        printf("         |                        Melayani Dengan Tulus   :)                         |\n");
        printf("         ----------------------------------------------------------------------------|\n");
        printf("         |                       Silahkan Pilih Menu Berikut                         |\n");
        printf("         ----------------------------------------------------------------------------|\n");
        printf("         |                            1. Data Pasien                                 |\n");
        printf("         |                            2. Data Dokter                                 |\n");
        printf("         |                            3. Pemeriksaan                                 |\n");
        printf("         |                            0. Exit                                        |\n");
        printf("         <===========================================================================>\n");
        printf("                                                                                      \n");
        printf("                                                                                      \n");
        printf("                                                                                      \n");
        printf("                                      Pilih : ");
        scanf("%d", &ch);

        switch(ch){
        case 0:
            exit(0);

        case 1:
            datapasien();
            break;

        case 2:
            datadokter();
            break;

        case 3:
            pemeriksaan();
            break;

        default:
            printf("Pilihan Tidak Valid...\n\n");

        }
        printf("\n\nTekan Tombol Apa Saja Untuk Melanjutkan ...");
        getch();
    }

    return 0;
}

void datapasien(){

    int ch;

    while(1){
        system("cls");
        printf("         <===========================================================================>\n");
        printf("         |     Selamat Datang di Sistem Pendaftaran Pasien Rumah Sakit Gunadarma     |\n");
        printf("         |                 Kota Depok, Jawa Barat (021) 29428935                     |\n");
        printf("         |                        Melayani Dengan Tulus   :)                         |\n");
        printf("         ----------------------------------------------------------------------------|\n");
        printf("         |                       Silahkan Pilih Menu Berikut                         |\n");
        printf("         ----------------------------------------------------------------------------|\n");
        printf("         |                            1. Tambah Pasien                               |\n");
        printf("         |                            2. Ubah Pasien                                 |\n");
        printf("         |                            3. Hapus Pasien                                |\n");
        printf("         |                            4. Tampilan Pasien                             |\n");
        printf("         |                            0. Back                                        |\n");
        printf("         <===========================================================================>\n");
        printf("                                                                                      \n");
        printf("                                                                                      \n");
        printf("                                                                                      \n");
        printf("                                      Pilih : ");
        scanf("%d", &ch);

        switch(ch){
        case 0:
            return;

        case 1:
            tambahpasien();
            break;

        case 2:
            ubahpasien();
            break;

        case 3:
            hapuspasien();
            break;

        case 4:
            tampilanpasien();
            break;

        default:
            printf("Pilihan Tidak Valid...\n\n");

        }
        printf("\n\nTekan Tombol Apa Saja Untuk Melanjutkan ...");
        getch();
    }

    return 0;
}

void tambahpasien(){

    system("cls");
    char myDate[12];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(myDate, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year + 1900);
    strcpy(p.date, myDate);

    fp = fopen("pasien.txt", "ab");
    printf("       ----------------------------------------------------------------------------------------------------------\n");
    printf("       |                                             Tambah Pasien                                              |\n");
    printf("       ----------------------------------------------------------------------------------------------------------\n");
    printf("         Masukkan id Pasien     : ");
    scanf("%d", &p.idpasien);

    printf("         Masukkan Nama Pasien   : ");
    fflush(stdin);
    gets(p.namapasien);

    printf("         Masukkan Alamat Pasien : ");
    fflush(stdin);
    gets(p.alamatpasien);

    printf("         Masukkan Jenis Kelamin (1. Laki-Laki / 2. Wanita): ");
    int jenisKelaminOption;
    scanf("%d", &jenisKelaminOption);

    switch (jenisKelaminOption) {
        case 1:
            strcpy(p.jeniskelamin, "Laki-Laki");
            break;
        case 2:
            strcpy(p.jeniskelamin, "Wanita");
            break;
        default:
            strcpy(p.jeniskelamin, "Tidak Valid");
            break;
    }

    printf("         Masukkan No Telepon    : ");
    fflush(stdin);
    gets(p.notelpon);

    printf("         \nPasien Berhasil Ditambahkan");

    fwrite(&p, sizeof(p), 1, fp);
    fclose(fp);
}

void ubahpasien() {
    int idpasien, found = 0;
    system("cls");
    printf("----------------------------------------------------------------------------------------------------------\n");
    printf("|                                             Ubah Pasien                                                |\n");
    printf("----------------------------------------------------------------------------------------------------------\n");
    printf("Masukkan id pasien yang ingin diubah: ");
    scanf("%d", &idpasien);

    FILE *ft;

    fp = fopen("pasien.txt", "rb+");
    if (fp == NULL) {
        printf("File pasien.txt tidak dapat dibuka.");
        return;
    }

    while (fread(&p, sizeof(p), 1, fp) == 1) {
        if (idpasien == p.idpasien) {
            found = 1;

            printf("\nData Pasien Saat Ini:\n");
            printf("ID Pasien     : %d\n", p.idpasien);
            printf("Nama Pasien   : %s\n", p.namapasien);
            printf("Alamat        : %s\n", p.alamatpasien);
            printf("Jenis Kelamin : %s\n", p.jeniskelamin);
            printf("No Telepon    : %s\n", p.notelpon);
            printf("Date          : %s\n", p.date);

            // Ask for new information
            printf("\nMasukkan informasi baru:\n");
            printf("Masukkan Nama Pasien   : ");
            fflush(stdin);
            gets(p.namapasien);

            printf("Masukkan Alamat Pasien : ");
            fflush(stdin);
            gets(p.alamatpasien);

            printf("Masukkan Jenis Kelamin (1. Laki-Laki / 2. Wanita): ");
            int jenisKelaminOption;
            scanf("%d", &jenisKelaminOption);

            switch (jenisKelaminOption) {
                case 1:
                    strcpy(p.jeniskelamin, "Laki-Laki");
                    break;
                case 2:
                    strcpy(p.jeniskelamin, "Wanita");
                    break;
                default:
                    strcpy(p.jeniskelamin, "Tidak Valid");
                    break;
            }

            printf("Masukkan No Telepon    : ");
            fflush(stdin);
            gets(p.notelpon);

            printf("Masukkan Tanggal Baru  : ");
            fflush(stdin);
            gets(p.date);

            // Move the file pointer to the beginning of the record
            fseek(fp, -sizeof(p), SEEK_CUR);

            // Update the record with new information
            fwrite(&p, sizeof(p), 1, fp);

            printf("\nData Pasien Berhasil Diubah.");
            break; // Exit the loop after updating the record
        }
    }

    if (!found) {
        printf("\nData Pasien Tidak Ditemukan !");
    }

    fclose(fp);
}

void hapuspasien(){
    int idpasien, f=0;
    system("cls");
    printf("----------------------------------------------------------------------------------------------------------\n");
    printf("|                                             Hapus Pasien                                               |\n");
    printf("----------------------------------------------------------------------------------------------------------\n");
    printf("Masukkan id pasien yang ingin dihapus: ");
    scanf("%d", &idpasien);

    FILE *ft;

    fp = fopen("pasien.txt", "rb");
    ft = fopen("temp.txt", "wb");

    while(fread(&p, sizeof(p), 1, fp) == 1){

        if(idpasien == p.idpasien){
            f=1;
        }else{
            fwrite(&p, sizeof(p), 1, ft);
        }
    }

    if(f==1){
        printf("\n\Berhasil Menghapus Pasien.");
    }else{
        printf("\n\nData Pasien Tidak Ditemukan !");
    }

    fclose(fp);
    fclose(ft);

    remove("pasien.txt");
    rename("temp.txt", "pasien.txt");

}

void tampilanpasien(){

    system("cls");
    printf("       -------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("       |                                                                       Tampilan Pasien                                                               |\n");
    printf("       -------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("         %-20s %-30s %-30s %-30s %-20s %s\n", "Id Pasien", "Nama Pasien", "Alamat", "Jenis Kelamin", "No Telpon", "Date");
    printf("       -------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    fp = fopen("pasien.txt", "rb");
    while(fread(&p, sizeof(p), 1, fp) == 1){
        printf("          %-20d %-30s %-30s %-30s %-20s %s\n", p.idpasien, p.namapasien, p.alamatpasien, p.jeniskelamin, p.notelpon, p.date);
    }

    fclose(fp);
}

void datadokter() {
    int hc;

        system ("cls");
        printf("         ----------------------------------------------------------------------------|\n");
        printf("         |                       Silahkan Pilih Menu Berikut                         |\n");
        printf("         ----------------------------------------------------------------------------|\n");
        printf("         |                            1. Tambah Dokter                               |\n");
        printf("         |                            2. Ubah Dokter                                 |\n");
        printf("         |                            3. Hapus Dokter                                |\n");
        printf("         |                            4. Tampilan Dokter                             |\n");
        printf("         |                            0. Back                                        |\n");
        printf("         <===========================================================================>\n");
        printf("                                                                                      \n");
        printf("                                                                                      \n");
        printf("                                                                                      \n");
        printf("                                      Pilih : ");
        scanf("%d", &hc);

        switch(hc){
        case 0:
            return;

        case 1:
            tambahdokter();
            break;

        case 2:
            ubahdokter();
            break;

        case 3:
            hapusdokter();
            break;

        case 4:
            tampilandokter();
            break;

        default:
            printf("Pilihan Tidak Valid...\n\n");

        }
    return 0;
}

void tambahdokter(){

    system("cls");
    char myDate[12];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(myDate, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year + 1900);
    strcpy(d.date, myDate);

    int f=0;

    fpDokter = fopen("dokter.txt", "ab");
    printf("       ----------------------------------------------------------------------------------------------------------\n");
    printf("       |                                             Tambah Dokter                                              |\n");
    printf("       ----------------------------------------------------------------------------------------------------------\n");
    printf("         Masukkan id Dokter     : ");
    scanf("%d", &d.iddokter);

    printf("         Masukkan Nama Dokter   : ");
    fflush(stdin);
    gets(d.namadokter);

    printf("         Masukkan Alamat Dokter : ");
    fflush(stdin);
    gets(d.alamatdokter);

    printf("         Masukkan Jenis Kelamin (1. Laki-Laki / 2. Wanita): ");
    int jeniskelamindokterOption;
    scanf("%d", &jeniskelamindokterOption);

    switch (jeniskelamindokterOption) {
        case 1:
            strcpy(d.jeniskelamindokter, "Laki-Laki");
            break;
        case 2:
            strcpy(d.jeniskelamindokter, "Wanita");
            break;
        default:
            strcpy(d.jeniskelamindokter, "Tidak Valid");
            break;
    }

    printf("         Masukkan No Telepon    : ");
    fflush(stdin);
    gets(d.notelpondokter);

    printf("       \nDokter Berhasil Ditambahkan");

    fwrite(&d, sizeof(d), 1, fpDokter);
    fclose(fpDokter);
}

void ubahdokter() {
    int iddokter, found = 0;
    system("cls");
    printf("----------------------------------------------------------------------------------------------------------\n");
    printf("|                                             Ubah Dokter                                                |\n");
    printf("----------------------------------------------------------------------------------------------------------\n");
    printf("Masukkan Id Dokter yang ingin diubah: ");
    scanf("%d", &iddokter);

    FILE *fu;

    fpDokter = fopen("dokter.txt", "rb+");
    if (fpDokter == NULL) {
        printf("File dokter.txt tidak dapat dibuka.");
        return;
    }

    while (fread(&d, sizeof(d), 1, fpDokter) == 1) {
        if (iddokter == d.iddokter) {
            found = 1;

            printf("\nData Pasien Saat Ini:\n");
            printf("ID Dokter     : %d\n", d.iddokter);
            printf("Nama Dokter   : %s\n", d.namadokter);
            printf("Alamat        : %s\n", d.alamatdokter);
            printf("Jenis Kelamin : %s\n", d.jeniskelamindokter);
            printf("No Telepon    : %s\n", d.notelpondokter);
            printf("Date          : %s\n", d.date);

            // Ask for new information
            printf("\nMasukkan informasi baru:\n");
            printf("Masukkan Nama Dokter   : ");
            fflush(stdin);
            gets(d.namadokter);

            printf("Masukkan Alamat Dokter : ");
            fflush(stdin);
            gets(d.alamatdokter);

            printf("Masukkan Jenis Kelamin (1. Laki-Laki / 2. Wanita): ");
            int jenisKelamindokterOption;
            scanf("%d", &jenisKelamindokterOption);

            switch (jenisKelamindokterOption) {
                case 1:
                    strcpy(d.jeniskelamindokter, "Laki-Laki");
                    break;
                case 2:
                    strcpy(d.jeniskelamindokter, "Wanita");
                    break;
                default:
                    strcpy(d.jeniskelamindokter, "Tidak Valid");
                    break;
            }

            printf("Masukkan No Telepon    : ");
            fflush(stdin);
            gets(d.notelpondokter);

            printf("Masukkan Tanggal Baru  : ");
            fflush(stdin);
            gets(d.date);

            // Move the file pointer to the beginning of the record
            fseek(fpDokter, -sizeof(d), SEEK_CUR);

            // Update the record with new information
            fwrite(&d, sizeof(d), 1, fpDokter);

            printf("\nData Dokter Berhasil Diubah.");
            break; // Exit the loop after updating the record
        }
    }

    if (!found) {
        printf("\nData Dokter Tidak Ditemukan !");
    }

    fclose(fpDokter);
}

void hapusdokter(){
    int iddokter, f=0;
    system("cls");
    printf("----------------------------------------------------------------------------------------------------------\n");
    printf("|                                             Hapus Dokter                                               |\n");
    printf("----------------------------------------------------------------------------------------------------------\n");
    printf("Masukkan id dokter yang ingin dihapus: ");
    scanf("%d", &iddokter);

    FILE *ftDokter;

    fpDokter = fopen("dokter.txt", "rb");
    ftDokter = fopen("temp.txt", "wb");

    while(fread(&d, sizeof(d), 1, fpDokter) == 1){

        if(iddokter == d.iddokter){
            f=1;
        }else{
            fwrite(&d, sizeof(d), 1, ftDokter);
        }
    }

    if(f==1){
        printf("  \n\nBerhasil Menghapus Pasien.");
    }else{
        printf("  \n\nData Pasien Tidak Ditemukan !");
    }

    fclose(fpDokter);
    fclose(ftDokter);

    remove("dokter.txt");
    rename("temp.txt", "dokter.txt");

}

void tampilandokter(){

    system("cls");
    printf("       -------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("       |                                                                       Tampilan Dokter                                                               |\n");
    printf("       -------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("         %-20s %-30s %-30s %-30s %-20s %s\n", "Id Dokter", "Nama Dokter", "Alamat", "Jenis Kelamin", "No Telpon", "Date");
    printf("       -------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    fpDokter = fopen("dokter.txt", "rb");
    while(fread(&d, sizeof(d), 1, fpDokter) == 1){
        printf("          %-20d %-30s %-30s %-30s %-20s %s\n", d.iddokter, d.namadokter, d.alamatdokter, d.jeniskelamindokter, d.notelpondokter, d.date);
    }

    fclose(fpDokter);
}

void pemeriksaan() {
    int idCari;
    int ketemuPasien = 0;
    int ketemuDokter = 0;
    int cariId;

    system("cls");
    printf("----------------------------------------------------------------------------------------------------------\n");
    printf("|                                             Pemeriksaan                                                |\n");
    printf("----------------------------------------------------------------------------------------------------------\n");

    fpmeriksa = fopen("pemeriksaan.txt", "ab");

    printf("Masukkan Kode Resep: ");
    scanf("%d", &m.koderesep);

    char myDatepemeriksaan[12];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(myDatepemeriksaan, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year + 1900);
    strcpy(m.datepemeriksaan, myDatepemeriksaan);

    printf("Masukkan Keluhan: ");
    fflush(stdin);
    gets(m.keluhan);

    printf("Masukkan ID Pasien: ");
    scanf("%d", &idCari);

    FILE *fp = fopen("pasien.txt", "rb");
    while(fread(&p, sizeof(p), 1, fp) == 1){
        if(idCari == p.idpasien){
            ketemuPasien = 1;
            m.idpasienpemeriksaan = p.idpasien;
            printf("\nData Pasien Ditemukan:\n");
            printf("ID Pasien     : %d\n", p.idpasien);
            printf("Nama Pasien   : %s\n", p.namapasien);
            strcpy(m.namapasienpemeriksaan, p.namapasien);
            printf("Alamat        : %s\n", p.alamatpasien);
            strcpy(m.alamatpasienpemeriksaan, p.alamatpasien);
            printf("Jenis Kelamin : %s\n", p.jeniskelamin);
            strcpy(m.jeniskelaminpemeriksaan, p.jeniskelamin);
            printf("No Telepon    : %s\n", p.notelpon);
            strcpy(m.notelponpemeriksaan, p.notelpon);
            printf("Date          : %s\n", p.date);
            strcpy(m.datepasienpemeriksaan, p.date);

            // Simpan data pasien ke dalam file pemeriksaan.txt
            break; // Keluar dari loop setelah menemukan data
        }
    }

    if (!ketemuPasien) {
        printf("\nData Pasien Tidak Ditemukan !");
    }

    fclose(fp);

    printf("Masukkan ID Dokter: ");
    scanf("%d", &cariId);

    // Gunakan variabel baru untuk membaca dokter
    FILE *fpDokter = fopen("dokter.txt", "rb");
    while(fread(&d, sizeof(d), 1, fpDokter) == 1){
        if(cariId == d.iddokter){
            ketemuDokter = 1;
            m.iddokterpemeriksaan = d.iddokter;
            printf("\nData Dokter Ditemukan:\n");
            printf("ID Dokter     : %d\n", d.iddokter);
            printf("Nama Dokter   : %s\n", d.namadokter);
            strcpy(m.namadokterpemeriksaan, d.namadokter);
            printf("Alamat        : %s\n", d.alamatdokter);
            strcpy(m.alamatdokterpemeriksaan, d.alamatdokter);
            printf("Jenis Kelamin : %s\n", d.jeniskelamindokter);
            strcpy(m.jeniskelamindokterpemeriksaan, d.jeniskelamindokter);
            printf("No Telepon    : %s\n", d.notelpondokter);
            strcpy(m.notelpondokterpemeriksaan, d.notelpondokter);
            // Simpan data dokter ke dalam file pemeriksaan.txt
            break; // Keluar dari loop setelah menemukan data
        }
    }

    if (!ketemuDokter) {
        printf("\nData Dokter Tidak Ditemukan !");
    }

    fclose(fpDokter);

    fwrite(&m, sizeof(m), 1, fpmeriksa);
    fclose(fpmeriksa);

    tampilkanPemeriksaan();
}

void tampilkanPemeriksaan() {
    int cariResep;
    int ketemuResep = 0;

    printf("Masukkan Kode Resep: ");
    scanf("%d", &cariResep);

    FILE *fpmeriksa = fopen("pemeriksaan.txt", "rb");
    while(fread(&m, sizeof(m), 1, fpmeriksa) == 1){
        if (cariResep == m.koderesep) {
            ketemuResep = 1;
            printf("                                                                                      \n");
            printf("                                                                                      \n");
            printf("                                                                                      \n");
            printf("                                                                                      \n");
            printf("         -----------------------------------------------------------------------------\n");
            printf("                                   Rumah Sakit Gunadarma                              \n");
            printf("                            Kota Depok, Jawa Barat (021) 29428935                     \n");
            printf("                                   Melayani Dengan Tulus   :)                         \n");
            printf("         =============================================================================\n");
            printf("            Nama Dokter           : %s\n", m.namadokterpemeriksaan                       );
            printf("            Alamat Dokter         : %s\n", m.alamatdokterpemeriksaan                     );
            printf("            Jenis Kelamin         : %s\n", m.jeniskelamindokterpemeriksaan               );
            printf("            No Telepon Dokter     : %s\n", m.notelpondokterpemeriksaan                   );
            printf("         -----------------------------------------------------------------------------\n");
            printf("                                                         Tanggal Peiksa : %s\n", m.datepemeriksaan);
            printf("            Keluhan       : %s\n", m.keluhan                                             );
            printf("                                                                                      \n");
            printf("            R/                                                                        \n");
            printf("                                                                                      \n");
            printf("            1. Apyalis Syrup                   No II           3 X   sehari           \n");
            printf("            2. Proclatacita                    No 50           3 X   sehari           \n");
            printf("            3. Pedrasure couplete 400 gram     No X            1 X   sehari           \n");
            printf("                                                                                      \n");
            printf("                                                                                      \n");
            printf("                                                                                      \n");
            printf("                                                                                      \n");
            printf("                                                                                      \n");
            printf("         =============================================================================\n");
            printf("            Nama Pasien           : %s\n", m.namapasienpemeriksaan                       );
            printf("            Jenis Kelamin Pasien  : %s\n", m.jeniskelaminpemeriksaan                     );
            printf("            Alamat Pasien         : %s\n", m.alamatpasienpemeriksaan                     );
            printf("            No Telepon Pasien     : %s\n", m.notelponpemeriksaan                         );
            printf("                                                                                      \n");
            printf("                                                                             Paraf    \n");
            printf("                                                                                      \n");
            printf("                                                                                      \n");
            printf("                                                                                      \n");
            printf("                                                                                      \n");
            printf("                                                                            %s\n", m.namadokterpemeriksaan);
            printf("         -----------------------------------------------------------------------------\n");

            break; // Keluar dari loop setelah menemukan data
        }
    }

    if (!ketemuResep) {
        printf("\nData Pemeriksaan Tidak Ditemukan!\n");
    }

    fclose(fpmeriksa);
}


