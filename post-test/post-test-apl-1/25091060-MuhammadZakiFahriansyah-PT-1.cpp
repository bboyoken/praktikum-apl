#include <iostream>
using namespace std;

int main() {
    string nama_input;
    string password_input;
    string nama_benar     = "zaki";
    string password_benar = "020";
    int    percobaan_login = 0;
    bool   login_berhasil  = false;

    cout << "==========================================" << endl;
    cout << "       PROGRAM KONVERSI WAKTU             " << endl;
    cout << "==========================================" << endl;
    cout << endl;

    while (percobaan_login < 3 && login_berhasil == false) {

        cout << "------------------------------------------" << endl;
        cout << "             SILAKAN LOGIN                " << endl;
        cout << "------------------------------------------" << endl;
        cout << "Nama     : ";
        cin  >> nama_input;
        cout << "Password : ";
        cin  >> password_input;
        cout << endl;

        if (nama_input == nama_benar && password_input == password_benar) {
            login_berhasil = true;
        } else {
            percobaan_login++;

            if (percobaan_login < 3) {
                cout << "Nama atau password salah!" << endl;
                cout << "Sisa percobaan : " << (3 - percobaan_login) << " kali" << endl;
                cout << endl;
            } else {
                cout << "Percobaan login telah habis." << endl;
                cout << "Program dihentikan. Sampai jumpa!" << endl;
                cout << endl;
            }
        }
    }

    if (login_berhasil == false) {
        return 0;
    }

    cout << "==========================================" << endl;
    cout << "  Login berhasil! Selamat datang, " << nama_input << "!" << endl;
    cout << "==========================================" << endl;
    cout << endl;

    int    pilihan_menu;
    double nilai_waktu;
    double hasil_pertama;
    double hasil_kedua;
    bool   program_berjalan = true;

    while (program_berjalan) {

        cout << "==========================================" << endl;
        cout << "               MENU UTAMA                 " << endl;
        cout << "==========================================" << endl;
        cout << "  1. Konversi Jam   --> Menit dan Detik   " << endl;
        cout << "  2. Konversi Menit --> Jam   dan Detik   " << endl;
        cout << "  3. Konversi Detik --> Jam   dan Menit   " << endl;
        cout << "  4. Keluar                               " << endl;
        cout << "==========================================" << endl;
        cout << "Pilih menu (1-4) : ";
        cin  >> pilihan_menu;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            pilihan_menu = -1;
        }

        cout << endl;

        if (pilihan_menu == 1) {
            cout << "------------------------------------------" << endl;
            cout << "   Konversi JAM --> Menit dan Detik       " << endl;
            cout << "------------------------------------------" << endl;
            cout << "Masukkan nilai Jam : ";
            cin  >> nilai_waktu;

            if (nilai_waktu < 0) {
                cout << endl;
                cout << "Nilai waktu tidak boleh negatif!" << endl;
            } else {
                hasil_pertama = nilai_waktu * 60;
                hasil_kedua   = nilai_waktu * 3600;

                cout << endl;
                cout << "========== HASIL KONVERSI ============" << endl;
                cout << nilai_waktu << " Jam = " << hasil_pertama << " Menit" << endl;
                cout << nilai_waktu << " Jam = " << hasil_kedua   << " Detik" << endl;
                cout << "======================================" << endl;
            }
            cout << endl;

        } else if (pilihan_menu == 2) {

            cout << "------------------------------------------" << endl;
            cout << "   Konversi MENIT --> Jam dan Detik       " << endl;
            cout << "------------------------------------------" << endl;
            cout << "Masukkan nilai Menit : ";
            cin  >> nilai_waktu;

            if (nilai_waktu < 0) {
                cout << endl;
                cout << "Nilai waktu tidak boleh negatif!" << endl;
            } else {
                hasil_pertama = nilai_waktu / 60;
                hasil_kedua   = nilai_waktu * 60;

                cout << endl;
                cout << "========== HASIL KONVERSI ============" << endl;
                cout << nilai_waktu << " Menit = " << hasil_pertama << " Jam"   << endl;
                cout << nilai_waktu << " Menit = " << hasil_kedua   << " Detik" << endl;
                cout << "======================================" << endl;
            }
            cout << endl;

        } else if (pilihan_menu == 3) {

            cout << "------------------------------------------" << endl;
            cout << "   Konversi DETIK --> Jam dan Menit       " << endl;
            cout << "------------------------------------------" << endl;
            cout << "Masukkan nilai Detik : ";
            cin  >> nilai_waktu;

            if (nilai_waktu < 0) {
                cout << endl;
                cout << "Nilai waktu tidak boleh negatif!" << endl;
            } else {
                hasil_pertama = nilai_waktu / 3600;
                hasil_kedua   = nilai_waktu / 60;

                cout << endl;
                cout << "========== HASIL KONVERSI ============" << endl;
                cout << nilai_waktu << " Detik = " << hasil_pertama << " Jam"   << endl;
                cout << nilai_waktu << " Detik = " << hasil_kedua   << " Menit" << endl;
                cout << "======================================" << endl;
            }
            cout << endl;

        } else if (pilihan_menu == 4) {

            cout << "==========================================" << endl;
            cout << "  Terima kasih, " << nama_input << "! Sampai jumpa!" << endl;
            cout << "==========================================" << endl;
            cout << endl;

            program_berjalan = false;

        } else {
            cout << "Pilihan tidak valid! Masukkan angka 1-4." << endl;
            cout << endl;
        }
    }

    return 0;
}