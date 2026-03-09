#include <iostream>
#include <string>
#include <cstdlib> 
#include <iomanip> 
using namespace std;

struct KandunganNutrisi {
    float kalori;
    float protein;
    float karbohidrat;
    float lemak;
};

struct DataGizi {
    string namaMakanan;
    string kategori;
    KandunganNutrisi nutrisi; 
    bool isConfirmed; 
    string peminta;
};

struct AkunUser {
    string username;
    string password;
};

int main() {
    DataGizi gizi[100];
    int jumlahData = 0;

    AkunUser users[100];
    int jumlahUser = 0;

    gizi[0].namaMakanan = "Nasi Putih"; gizi[0].nutrisi.karbohidrat = 28.2; gizi[0].nutrisi.protein = 2.7;
    gizi[0].kategori = "Makanan Utama"; gizi[0].nutrisi.lemak = 0.3; gizi[0].peminta = "Admin";
    gizi[0].nutrisi.kalori = 130.0; gizi[0].isConfirmed = true; 
    
    gizi[1].namaMakanan = "Ayam Goreng"; gizi[1].nutrisi.karbohidrat = 1.8; gizi[1].nutrisi.protein = 27.3;
    gizi[1].kategori = "Lauk Pauk"; gizi[1].nutrisi.lemak = 16.8; gizi[1].peminta = "Admin";
    gizi[1].nutrisi.kalori = 260.0; gizi[1].isConfirmed = true;
    
    jumlahData = 2;

    string inputUsername, inputPassword;
    string menuAwalStr; 
    int menuAwal;

    do {
        system("cls"); 
        cout << "========================================\n";
        cout << " SISTEM INFORMASI MANAJEMEN DATA GIZI\n";
        cout << "========================================\n";
        cout << "1. Login\n";
        cout << "2. Register\n";
        cout << "0. Keluar Program\n";
        cout << "Pilihan Anda: ";
        cin >> menuAwalStr;

        if (menuAwalStr == "1") menuAwal = 1;
        else if (menuAwalStr == "2") menuAwal = 2;
        else if (menuAwalStr == "0") menuAwal = 0;
        else menuAwal = -1; 

        if (menuAwal == 1) {
            int percobaan = 0;
            bool loginBerhasil = false;
            int role = 0;

            while (percobaan < 3 && !loginBerhasil) {
                system("cls");
                cout << "=== MENU LOGIN ===\n";
                if (percobaan > 0) cout << "[!] Percobaan gagal. Sisa kesempatan: " << 3 - percobaan << "\n";
                cout << "Username : "; cin >> inputUsername;
                cout << "Password : "; cin >> inputPassword;

                if (inputUsername == "zaki" && inputPassword == "020") {
                    loginBerhasil = true; role = 1; 
                } else {
                    for (int i = 0; i < jumlahUser; i++) {
                        if (users[i].username == inputUsername && users[i].password == inputPassword) {
                            loginBerhasil = true; role = 2; break; 
                        }
                    }
                }

                if (!loginBerhasil) {
                    percobaan++; 
                    if (percobaan == 3) {
                        system("cls");
                        cout << "[!] Anda gagal login 3 kali. Program dihentikan.\n";
                        return 0; 
                    }
                }
            }

            if (loginBerhasil) {
                if (role == 1) {
                    cout << "\nLogin Berhasil! Selamat datang Admin Zaki.\n";
                    cout << "Tekan Enter untuk melanjutkan..."; 
                    cin.ignore(1000, '\n'); cin.get();

                    int menuAdmin;
                    do {
                        system("cls");
                        cout << "===== DASHBOARD ADMIN =====\n";
                        cout << "1. Lihat Data Gizi Makanan\n";
                        cout << "2. Tambah Data Makanan Baru\n";
                        cout << "3. Ubah Data Gizi\n";
                        cout << "4. Hapus Data Makanan\n";
                        cout << "5. Konfirmasi Request User\n";
                        cout << "0. Logout\n";
                        cout << "Pilihan: ";
                        cin >> menuAdmin;
                        cin.ignore(1000, '\n'); 

                        system("cls");

                        if (menuAdmin >= 1 && menuAdmin <= 4) {
                            cout << "\n===== DAFTAR DATA GIZI MAKANAN =====\n";
                            cout << "+----+----------------------+-----------------+---------------+-------------+-----------+-----------+\n";
                            cout << "| " << left << setw(2) << "No" << " | " << setw(20) << "Nama Makanan" << " | "
                                << setw(15) << "Kategori" << " | "
                                << setw(13) << "Kalori (kkal)" << " | " << setw(11) << "Protein (g)" << " | "
                                << setw(9) << "Karbo (g)" << " | " << setw(9) << "Lemak (g)" << " |\n";
                            cout << "+----+----------------------+-----------------+---------------+-------------+-----------+-----------+\n";

                            bool adaDataTampil = false;
                            int noTampil = 1; 
                            for (int i = 0; i < jumlahData; i++) {
                                if (gizi[i].isConfirmed) {
                                    cout << "| " << left << setw(2) << noTampil << " | " 
                                        << setw(20) << gizi[i].namaMakanan << " | " 
                                        << setw(15) << gizi[i].kategori << " | " 
                                        << setw(13) << gizi[i].nutrisi.kalori << " | " 
                                        << setw(11) << gizi[i].nutrisi.protein << " | " 
                                        << setw(9) << gizi[i].nutrisi.karbohidrat << " | " 
                                        << setw(9) << gizi[i].nutrisi.lemak << " |\n";
                                    noTampil++;
                                    adaDataTampil = true;
                                }
                            }
                            if (!adaDataTampil) cout << "| " << left << setw(97) << "Belum ada data tersedia." << " |\n";
                            cout << "+----+----------------------+-----------------+---------------+-------------+-----------+-----------+\n\n";
                        }

                        if (menuAdmin == 1) {
                            cout << "Menampilkan seluruh data gizi...\n";
                        } 
                        else if (menuAdmin == 2) {
                            if (jumlahData >= 100) cout << "Kapasitas penuh!\n";
                            else {
                                cout << "--- TAMBAH DATA MAKANAN ---\n";
                                cout << "Nama Makanan  : "; getline(cin, gizi[jumlahData].namaMakanan);
                                cout << "Kategori      : "; getline(cin, gizi[jumlahData].kategori);
                                cout << "Kalori (kkal) : "; cin >> gizi[jumlahData].nutrisi.kalori;
                                cout << "Protein (g)   : "; cin >> gizi[jumlahData].nutrisi.protein;
                                cout << "Karbo (g)     : "; cin >> gizi[jumlahData].nutrisi.karbohidrat;
                                cout << "Lemak (g)     : "; cin >> gizi[jumlahData].nutrisi.lemak;
                                cin.ignore(1000, '\n'); 
                                gizi[jumlahData].isConfirmed = true; 
                                gizi[jumlahData].peminta = "Admin";
                                jumlahData++;
                                cout << "\nData berhasil ditambahkan!\n";
                            }
                        }
                        else if (menuAdmin == 3) {
                            cout << "Masukkan Nomor Makanan yang ingin diubah: ";
                            int pilihan; cin >> pilihan;
                            cin.ignore(1000, '\n');
                            int targetIndex = -1, currentNo = 1;
                            for (int i = 0; i < jumlahData; i++) {
                                if (gizi[i].isConfirmed) {
                                    if (currentNo == pilihan) { targetIndex = i; break; }
                                    currentNo++;
                                }
                            }
                            if (targetIndex != -1) {
                                cout << "Nama Makanan Baru : "; getline(cin, gizi[targetIndex].namaMakanan);
                                cout << "Kategori Baru     : "; getline(cin, gizi[targetIndex].kategori);
                                cout << "Kalori Baru (kkal): "; cin >> gizi[targetIndex].nutrisi.kalori;
                                cout << "Protein Baru (g)  : "; cin >> gizi[targetIndex].nutrisi.protein;
                                cout << "Karbo Baru (g)    : "; cin >> gizi[targetIndex].nutrisi.karbohidrat;
                                cout << "Lemak Baru (g)    : "; cin >> gizi[targetIndex].nutrisi.lemak;
                                cin.ignore(1000, '\n'); 
                                cout << "\nData berhasil diperbarui!\n";
                            } else cout << "Nomor tidak valid!\n";
                        }
                        else if (menuAdmin == 4) {
                            cout << "Masukkan Nomor Makanan yang akan dihapus: ";
                            int pilihan; cin >> pilihan;
                            cin.ignore(1000, '\n');
                            int targetIndex = -1, currentNo = 1;
                            for (int i = 0; i < jumlahData; i++) {
                                if (gizi[i].isConfirmed) {
                                    if (currentNo == pilihan) { targetIndex = i; break; }
                                    currentNo++;
                                }
                            }
                            if (targetIndex != -1) {
                                for (int i = targetIndex; i < jumlahData - 1; i++) gizi[i] = gizi[i + 1];
                                jumlahData--;
                                cout << "\nData berhasil dihapus\n";
                            } else cout << "Nomor tidak valid!\n";
                        }
                        else if (menuAdmin == 5) {
                            cout << "===== DAFTAR REQUEST PENGGUNA =====\n";
                            cout << "+----+----------------------+-----------------+-----------------+\n";
                            cout << "| " << left << setw(2) << "No" << " | " << setw(20) << "Nama Makanan" << " | " << setw(15) << "Kategori" << " | " << setw(15) << "Peminta" << " |\n";
                            cout << "+----+----------------------+-----------------+-----------------+\n";
                            
                            int noRequest = 1; 
                            bool adaRequest = false;
                            for (int i = 0; i < jumlahData; i++) {
                                if (!gizi[i].isConfirmed) {
                                    cout << "| " << left << setw(2) << noRequest << " | " 
                                         << setw(20) << gizi[i].namaMakanan << " | " 
                                         << setw(15) << gizi[i].kategori << " | " 
                                         << setw(15) << gizi[i].peminta << " |\n";
                                    noRequest++;
                                    adaRequest = true;
                                }
                            }
                            if(!adaRequest) cout << "| " << left << setw(61) << "Tidak ada request." << " |\n";
                            cout << "+----+----------------------+-----------------+-----------------+\n\n";

                            if (adaRequest) {
                                cout << "Masukkan Nomor Request yang dikonfirmasi (0 batal): ";
                                int pilihan; cin >> pilihan;
                                cin.ignore(1000, '\n');
                                
                                if (pilihan > 0) {
                                    int targetIndex = -1, currentReq = 1;
                                    for (int i = 0; i < jumlahData; i++) {
                                        if (!gizi[i].isConfirmed) {
                                            if (currentReq == pilihan) { targetIndex = i; break; }
                                            currentReq++;
                                        }
                                    }
                                    if (targetIndex != -1) {
                                        cout << "\n--- LENGKAPI GIZI: " << gizi[targetIndex].namaMakanan << " (" << gizi[targetIndex].kategori << ") ---\n";
                                        cout << "Kalori (kkal) : "; cin >> gizi[targetIndex].nutrisi.kalori;
                                        cout << "Protein (g)   : "; cin >> gizi[targetIndex].nutrisi.protein;
                                        cout << "Karbo (g)     : "; cin >> gizi[targetIndex].nutrisi.karbohidrat;
                                        cout << "Lemak (g)     : "; cin >> gizi[targetIndex].nutrisi.lemak;
                                        cin.ignore(1000, '\n');
                                        gizi[targetIndex].isConfirmed = true; 
                                        cout << "\nRequest berhasil dikonfirmasi!\n";
                                    } else cout << "Nomor tidak valid!\n";
                                }
                            }
                        } else if (menuAdmin != 0) {
                            cout << "Pilihan tidak valid!\n";
                        }
                        
                        if (menuAdmin != 0) {
                            cout << "\nTekan Enter untuk kembali..."; 
                            cin.get(); 
                        }
                    } while (menuAdmin != 0);

                } else if (role == 2) {
                    cout << "\nLogin Berhasil! Selamat datang, " << inputUsername << ".\n";
                    cout << "Tekan Enter untuk melanjutkan..."; 
                    cin.ignore(1000, '\n'); cin.get();

                    int menuUser;
                    do {
                        system("cls");
                        cout << "===== DASHBOARD USER (" << inputUsername << ") =====\n";
                        cout << "1. Lihat Data Gizi Makanan\n";
                        cout << "2. Request Info Makanan\n";
                        cout << "0. Logout\n";
                        cout << "Pilihan: ";
                        cin >> menuUser;
                        cin.ignore(1000, '\n'); 

                        system("cls");
                        if (menuUser == 1) {
                            cout << "\n===== INFORMASI GIZI MAKANAN =====\n";
                            cout << "+----+----------------------+-----------------+---------------+-------------+-----------+-----------+\n";
                            cout << "| " << left << setw(2) << "No" << " | " << setw(20) << "Nama Makanan" << " | "
                                << setw(15) << "Kategori" << " | "
                                << setw(13) << "Kalori (kkal)" << " | " << setw(11) << "Protein (g)" << " | "
                                << setw(9) << "Karbo (g)" << " | " << setw(9) << "Lemak (g)" << " |\n";
                            cout << "+----+----------------------+-----------------+---------------+-------------+-----------+-----------+\n";

                            bool adaDataUser = false;
                            int noTampil = 1;
                            for (int i = 0; i < jumlahData; i++) {
                                if (gizi[i].isConfirmed) {
                                    cout << "| " << left << setw(2) << noTampil << " | " 
                                        << setw(20) << gizi[i].namaMakanan << " | " 
                                        << setw(15) << gizi[i].kategori << " | " 
                                        << setw(13) << gizi[i].nutrisi.kalori << " | " 
                                        << setw(11) << gizi[i].nutrisi.protein << " | " 
                                        << setw(9) << gizi[i].nutrisi.karbohidrat << " | " 
                                        << setw(9) << gizi[i].nutrisi.lemak << " |\n";
                                    noTampil++;
                                    adaDataUser = true;
                                }
                            }
                            if (!adaDataUser) cout << "| " << left << setw(97) << "Belum ada data tersedia." << " |\n";
                            cout << "+----+----------------------+-----------------+---------------+-------------+-----------+-----------+\n\n";
                        } 
                        else if (menuUser == 2) {
                            if (jumlahData >= 100) cout << "Sistem penuh!\n";
                            else {
                                cout << "--- REQUEST MAKANAN BARU ---\n";
                                cout << "Nama Makanan  : "; getline(cin, gizi[jumlahData].namaMakanan); 
                                cout << "Kategori      : "; getline(cin, gizi[jumlahData].kategori);
                                gizi[jumlahData].nutrisi.kalori = 0; 
                                gizi[jumlahData].nutrisi.protein = 0;
                                gizi[jumlahData].nutrisi.karbohidrat = 0; 
                                gizi[jumlahData].nutrisi.lemak = 0;
                                gizi[jumlahData].isConfirmed = false; 
                                gizi[jumlahData].peminta = inputUsername;
                                jumlahData++;
                                cout << "\nRequest berhasil dikirim ke Admin!\n";
                            }
                        }
                        else if (menuUser != 0) {
                            cout << "Pilihan tidak valid!\n";
                        }
                        
                        if (menuUser != 0) {
                            cout << "\nTekan Enter untuk kembali..."; 
                            cin.get();
                        }
                    } while (menuUser != 0);
                }
            }

        } else if (menuAwal == 2) {
            system("cls");
            if (jumlahUser >= 100) cout << "Kapasitas user penuh!\n";
            else {
                cout << "===== REGISTER USER =====\n";
                string inputBaru;
                bool isDuplicate;
                
                do {
                    isDuplicate = false;
                    cout << "Masukkan Username baru : "; cin >> inputBaru;
                    
                    if (inputBaru == "zaki") isDuplicate = true; 
                    for (int i = 0; i < jumlahUser; i++) {
                        if (users[i].username == inputBaru) isDuplicate = true;
                    }
                    
                    if (isDuplicate) cout << "[!] Username sudah dipakai! Silakan cari yang lain.\n\n";
                } while (isDuplicate);

                users[jumlahUser].username = inputBaru;
                cout << "Masukkan Password baru : "; cin >> users[jumlahUser].password;
                jumlahUser++;
                cout << "\nRegistrasi berhasil! Silakan login melalui menu utama.\n";
            }
            cout << "Tekan Enter untuk kembali..."; 
            cin.ignore(1000, '\n'); cin.get();
        } 
        else if (menuAwal == -1) {
            cout << "\n[!] Pilihan tidak valid! Silakan pilih 1, 2, atau 0.\n";
            cout << "Tekan Enter untuk mencoba lagi..."; 
            cin.ignore(1000, '\n'); cin.get();
        }

    } while (menuAwal != 0);

    system("cls");
    cout << "\nTerima kasih telah menggunakan Sistem Informasi Manajemen Data Gizi!\n";
    return 0;
}