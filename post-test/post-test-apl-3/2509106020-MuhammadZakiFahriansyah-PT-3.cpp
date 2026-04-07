#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
using namespace std;

struct Nutrisi { float kalori, protein, karbohidrat, lemak; };
struct DataGizi { string namaMakanan, kategori; Nutrisi nutrisi; bool isConfirmed; string peminta; };
struct AkunUser { string username, password; };

const string LINE = "+----+----------------------+-----------------+---------------+-------------+-----------+-----------+\n";
const string HEAD = "| No | Nama Makanan         | Kategori        | Kalori (kkal) | Protein (g) | Karbo (g) | Lemak (g) |\n";

void cetakBaris(int nomorUrut, DataGizi& gizi) {
    cout << "| " << left << setw(2) << nomorUrut << " | " << setw(20) << gizi.namaMakanan << " | " << setw(15) << gizi.kategori
         << " | " << setw(13) << gizi.nutrisi.kalori << " | " << setw(11) << gizi.nutrisi.protein
         << " | " << setw(9)  << gizi.nutrisi.karbohidrat << " | " << setw(9) << gizi.nutrisi.lemak << " |\n";
}

void cetakTabelGizi(DataGizi gizi[], int jumlahData) {
    cout << "\n===== DAFTAR DATA GIZI MAKANAN =====\n";
    cout << LINE << HEAD << LINE;
    bool ada = false; int nomorUrut = 1;
    for (int i = 0; i < jumlahData; i++)
        if (gizi[i].isConfirmed) { cetakBaris(nomorUrut++, gizi[i]); ada = true; }
    if (!ada) cout << "| " << left << setw(97) << "Belum ada data." << " |\n";
    cout << LINE << "\n";
}

void cetakTabelGizi(DataGizi gizi[], int jumlahData, string kategoriCari) {
    cout << "\n===== HASIL FILTER KATEGORI: " << kategoriCari << " =====\n";
    cout << LINE << HEAD << LINE;
    bool ada = false; int nomorUrut = 1;
    for (int i = 0; i < jumlahData; i++)
        if (gizi[i].isConfirmed && gizi[i].kategori == kategoriCari) { cetakBaris(nomorUrut++, gizi[i]); ada = true; }
    if (!ada) cout << "| " << left << setw(97) << "Data tidak ditemukan." << " |\n";
    cout << LINE << "\n";
}

float totalKaloriRekursif(DataGizi gizi[], int jumlahData) {
    if (jumlahData == 0) return 0;
    return (gizi[jumlahData-1].isConfirmed ? gizi[jumlahData-1].nutrisi.kalori : 0) + totalKaloriRekursif(gizi, jumlahData-1);
}

int cariIndex(DataGizi gizi[], int jumlahData, int pilihan, bool confirmed) {
    int currentNo = 1;
    for (int i = 0; i < jumlahData; i++)
        if (gizi[i].isConfirmed == confirmed && currentNo++ == pilihan) return i;
    return -1;
}

void tambahAtauRequestData(DataGizi gizi[], int& jumlahData, string peminta, bool isConfirmed) {
    if (jumlahData >= 100) { cout << "Kapasitas penuh!\n"; return; }
    cout << "--- " << (isConfirmed ? "TAMBAH DATA" : "REQUEST MAKANAN BARU") << " ---\n";
    cout << "Nama Makanan : "; getline(cin, gizi[jumlahData].namaMakanan);
    cout << "Kategori     : "; getline(cin, gizi[jumlahData].kategori);
    if (isConfirmed) {
        cout << "Kalori  : "; cin >> gizi[jumlahData].nutrisi.kalori;
        cout << "Protein : "; cin >> gizi[jumlahData].nutrisi.protein;
        cout << "Karbo   : "; cin >> gizi[jumlahData].nutrisi.karbohidrat;
        cout << "Lemak   : "; cin >> gizi[jumlahData].nutrisi.lemak;
        cin.ignore(1000, '\n');
    } else gizi[jumlahData].nutrisi = {0, 0, 0, 0};
    gizi[jumlahData].isConfirmed = isConfirmed; gizi[jumlahData].peminta = peminta; jumlahData++;
    cout << "\n" << (isConfirmed ? "Data berhasil ditambahkan!" : "Request terkirim ke Admin!") << "\n";
}

void ubahData(DataGizi gizi[], int jumlahData) {
    cout << "Nomor yang diubah: "; int pilihan; cin >> pilihan; cin.ignore(1000, '\n');
    int targetIndex = cariIndex(gizi, jumlahData, pilihan, true);
    if (targetIndex == -1) { cout << "Nomor tidak valid!\n"; return; }
    cout << "Nama Baru    : "; getline(cin, gizi[targetIndex].namaMakanan);
    cout << "Kategori     : "; getline(cin, gizi[targetIndex].kategori);
    cout << "Kalori       : "; cin >> gizi[targetIndex].nutrisi.kalori;
    cout << "Protein      : "; cin >> gizi[targetIndex].nutrisi.protein;
    cout << "Karbo        : "; cin >> gizi[targetIndex].nutrisi.karbohidrat;
    cout << "Lemak        : "; cin >> gizi[targetIndex].nutrisi.lemak;
    cin.ignore(1000, '\n'); cout << "\nData berhasil diperbarui!\n";
}

void hapusData(DataGizi gizi[], int& jumlahData) {
    cout << "Nomor yang dihapus: "; int pilihan; cin >> pilihan; cin.ignore(1000, '\n');
    int targetIndex = cariIndex(gizi, jumlahData, pilihan, true);
    if (targetIndex == -1) { cout << "Nomor tidak valid!\n"; return; }
    for (int i = targetIndex; i < jumlahData - 1; i++) gizi[i] = gizi[i + 1];
    jumlahData--; cout << "\nData berhasil dihapus!\n";
}

void konfirmasiRequest(DataGizi gizi[], int jumlahData) {
    const string LINE2 = "+----+----------------------+-----------------+-----------------+\n";
    cout << "===== REQUEST PENGGUNA =====\n" << LINE2;
    cout << "| No | Nama Makanan         | Kategori        | Peminta         |\n" << LINE2;
    bool ada = false; int nomorUrut = 1;
    for (int i = 0; i < jumlahData; i++)
        if (!gizi[i].isConfirmed) {
            cout << "| " << left << setw(2) << nomorUrut++ << " | " << setw(20) << gizi[i].namaMakanan
                 << " | " << setw(15) << gizi[i].kategori << " | " << setw(15) << gizi[i].peminta << " |\n";
            ada = true;
        }
    if (!ada) cout << "| " << left << setw(61) << "Tidak ada request." << " |\n";
    cout << LINE2 << "\n";
    if (!ada) return;
    cout << "Nomor Request (0=batal): "; int pilihan; cin >> pilihan; cin.ignore(1000, '\n');
    if (pilihan <= 0) return;
    int targetIndex = cariIndex(gizi, jumlahData, pilihan, false);
    if (targetIndex == -1) { cout << "Nomor tidak valid!\n"; return; }
    cout << "\n--- LENGKAPI GIZI: " << gizi[targetIndex].namaMakanan << " ---\n";
    cout << "Kalori  : "; cin >> gizi[targetIndex].nutrisi.kalori;
    cout << "Protein : "; cin >> gizi[targetIndex].nutrisi.protein;
    cout << "Karbo   : "; cin >> gizi[targetIndex].nutrisi.karbohidrat;
    cout << "Lemak   : "; cin >> gizi[targetIndex].nutrisi.lemak;
    cin.ignore(1000, '\n'); gizi[targetIndex].isConfirmed = true;
    cout << "\nRequest dikonfirmasi!\n";
}

void menuAdmin(DataGizi gizi[], int& jumlahData, string inputUsername) {
    string pilihanFilter; int menuPilihan;
    do {
        system("cls");
        cout << "===== DASHBOARD ADMIN =====\n";
        cout << "1. Lihat Data\n2. Tambah Data\n3. Ubah Data\n4. Hapus Data\n5. Konfirmasi Request\n0. Logout\nPilihan: ";
        cin >> menuPilihan; cin.ignore(1000, '\n'); system("cls");
        if (menuPilihan == 1) {
            cetakTabelGizi(gizi, jumlahData);
            cout << "=> [Rekursif] Total Kalori: " << totalKaloriRekursif(gizi, jumlahData) << " kkal\n\n";
            cout << "Filter Kategori? (y/n): "; cin >> pilihanFilter; cin.ignore(1000, '\n');
            if (pilihanFilter == "y" || pilihanFilter == "Y") {
                cout << "Kategori: "; string kategoriCari; getline(cin, kategoriCari);
                cetakTabelGizi(gizi, jumlahData, kategoriCari);
            }
        }
        else if (menuPilihan == 2) { cetakTabelGizi(gizi, jumlahData); tambahAtauRequestData(gizi, jumlahData, "Admin", true); }
        else if (menuPilihan == 3) { cetakTabelGizi(gizi, jumlahData); ubahData(gizi, jumlahData); }
        else if (menuPilihan == 4) { cetakTabelGizi(gizi, jumlahData); hapusData(gizi, jumlahData); }
        else if (menuPilihan == 5) konfirmasiRequest(gizi, jumlahData);
        else if (menuPilihan != 0) cout << "Pilihan tidak valid!\n";
        if (menuPilihan != 0) { cout << "\nTekan Enter Untuk Kembali..."; cin.get(); }
    } while (menuPilihan != 0);
}

void menuUser(DataGizi gizi[], int& jumlahData, string inputUsername) {
    int menuPilihan;
    do {
        system("cls");
        cout << "===== USER: " << inputUsername << " =====\n";
        cout << "1. Lihat Data\n2. Request Makanan\n0. Logout\nPilihan: ";
        cin >> menuPilihan; cin.ignore(1000, '\n'); system("cls");
        if (menuPilihan == 1)      cetakTabelGizi(gizi, jumlahData);
        else if (menuPilihan == 2) tambahAtauRequestData(gizi, jumlahData, inputUsername, false);
        else if (menuPilihan != 0) cout << "Pilihan tidak valid!\n";
        if (menuPilihan != 0) { cout << "\nTekan Enter Untuk Kembali..."; cin.get(); }
    } while (menuPilihan != 0);
}

void menuLogin(DataGizi gizi[], int& jumlahData, AkunUser users[], int jumlahUser) {
    int percobaan = 0, role = 0; bool loginBerhasil = false;
    string inputUsername, inputPassword;
    while (percobaan < 3 && !loginBerhasil) {
        system("cls"); cout << "=== MENU LOGIN ===\n";
        if (percobaan > 0) cout << "[!] Gagal. Sisa: " << 3 - percobaan << "\n";
        cout << "Username: "; cin >> inputUsername;
        cout << "Password: "; cin >> inputPassword;
        if (inputUsername == "zaki" && inputPassword == "020") { loginBerhasil = true; role = 1; }
        else for (int i = 0; i < jumlahUser; i++)
            if (users[i].username == inputUsername && users[i].password == inputPassword) { loginBerhasil = true; role = 2; break; }
        if (!loginBerhasil && ++percobaan == 3) { system("cls"); cout << "[!] Gagal 3 kali. Program dihentikan.\n"; exit(0); }
    }
    cout << "\nSelamat datang, " << inputUsername << "!\nTekan Enter Untuk Kembali..."; cin.ignore(1000, '\n'); cin.get();
    if (role == 1) menuAdmin(gizi, jumlahData, inputUsername);
    else           menuUser(gizi, jumlahData, inputUsername);
}

void menuRegister(AkunUser users[], int& jumlahUser) {
    system("cls"); string inputBaru; bool isDuplicate;
    if (jumlahUser >= 100) { cout << "Kapasitas penuh!\n"; }
    else {
        cout << "===== REGISTER USER =====\n";
        do {
            isDuplicate = false; cout << "Username: "; cin >> inputBaru;
            if (inputBaru == "zaki") isDuplicate = true;
            for (int i = 0; i < jumlahUser; i++) if (users[i].username == inputBaru) isDuplicate = true;
            if (isDuplicate) cout << "[!] Username sudah dipakai!\n";
        } while (isDuplicate);
        users[jumlahUser].username = inputBaru;
        cout << "Password: "; cin >> users[jumlahUser].password;
        jumlahUser++; cout << "\nRegistrasi berhasil!\n";
    }
    cout << "Tekan Enter Untuk Kembali..."; cin.ignore(1000, '\n'); cin.get();
}

int main() {
    DataGizi gizi[100]; int jumlahData = 0;
    AkunUser users[100]; int jumlahUser = 0;
    gizi[0] = {"Nasi Putih", "Makanan Utama", {130.0, 2.7, 28.2, 0.3}, true, "Admin"};
    gizi[1] = {"Ayam Goreng", "Lauk Pauk",   {260.0, 27.3, 1.8, 16.8}, true, "Admin"};
    jumlahData = 2;

    string inputMenuAwal; int menuAwal;
    do {
        system("cls");
        cout << "========================================\n";
        cout << " SISTEM INFORMASI MANAJEMEN DATA GIZI\n";
        cout << "========================================\n";
        cout << "1. Login\n2. Register\n0. Keluar\nPilihan: "; cin >> inputMenuAwal;
        if      (inputMenuAwal == "1") menuAwal = 1;
        else if (inputMenuAwal == "2") menuAwal = 2;
        else if (inputMenuAwal == "0") menuAwal = 0;
        else                           menuAwal = -1;

        if      (menuAwal == 1)  menuLogin(gizi, jumlahData, users, jumlahUser);
        else if (menuAwal == 2)  menuRegister(users, jumlahUser);
        else if (menuAwal == -1) {
            cout << "\n[!] Pilihan tidak valid!\nTekan Enter Untuk Kembali...";
            cin.ignore(1000, '\n'); cin.get();
        }
    } while (menuAwal != 0);

    system("cls");
    cout << "\nTerima kasih telah menggunakan Sistem Informasi Manajemen Data Gizi!\n";
    return 0;
}