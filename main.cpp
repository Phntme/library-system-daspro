#include <iostream>
#include <vector>
using namespace std;

struct Peminjaman {
    string nama;
    string buku;
    int tanggal;
    int bulan;
    int tahun;
    int totalPinjam;
    bool sudahKembali;
};

int main() {
    
    vector<string> username = {"Zain", "Budi"}; 
    vector<bool> admin = {true, false};
    
    bool statusLogin = false;
    int indexUser = -1;
    int pilihanAwal;

    while (!statusLogin) {
        cout << "=== APLIKASI PERPUSTAKAAN ===" << endl;
        cout << "1. Login" << endl;
        cout << "2. Buat Akun Baru" << endl;
        cout << "Pilihan: ";
        cin >> pilihanAwal;
        cout << endl;

        if (pilihanAwal == 1) {
            string inputUsername;
            cout << "=== MENU LOGIN ===" << endl;
            cout << "Masukkan Username: ";
            cin >> inputUsername;

            for (int i = 0; i < username.size(); i++) {
                if (username[i] == inputUsername) {
                    statusLogin = true;
                    indexUser = i;
                    break;
                }
            }
        } else if (pilihanAwal == 2) {
            string akunBaru;
            int tipeAkun;
            cout << "=== BUAT AKUN BARU ===" << endl;
            cout << "Masukkan Username baru: ";
            cin >> akunBaru;

            bool sudahAda = false;
            for (int i = 0; i < username.size(); i++) {
                if (username[i] == akunBaru) {
                    sudahAda = true;
                    break;
                }
            }
            
            if (sudahAda) {
                cout << "Gagal membuat akun! Username " << akunBaru << " sudah terdaftar." << endl;
            } else {
                cout << "Pilih Tipe Akun:" << endl;
                cout << "1. User Biasa" << endl;
                cout << "2. Admin" << endl;
                cout << "Pilihan tipe: ";
                cin >> tipeAkun;

                username.push_back(akunBaru);
                if (tipeAkun == 2) {
                    admin.push_back(true);
                } else {
                    admin.push_back(false);
                }
                cout << "Akun berhasil dibuat! Silakan login ulang." << endl;
            }
        } else {
            cout << "Pilihan salah!" << endl;
        }
    }

    string namaPeminjam;
    int hariMeminjam = 0;
    int pilihanUser; // penampung pilihan user
    int tanggal[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int totalPinjam = 0;
    int totalKemb = 0;
    int tanggalPinjam;
    int bulanPinjam;
    int tahunPinjam;
    int tanggalKemb;
    int bulanKemb;
    int tahunKemb;


    // data
    vector<Peminjaman> daftarPeminjam;
    vector<string> daftarBuku = {"Kalkulus","Fisika","Dasar Pemrograman","Sistem Operasi"}; // daftar buku
    vector<int> stockBuku = {20, 32, 61, 25};
    vector<bool> statusBuku = {false,false,false,false}; // status pinjaman buku, false = buku tersedia

    do
    {
        // daftar menu
        cout << "=== Selamat datang di sistem manajemen Perpustakaan ===" << endl;
        cout << "1. Daftar Buku" << endl;
        cout << "2. Pinjam Buku" << endl;
        cout << "3. Kembalikan Buku" << endl;

        if (admin[indexUser]) {
            cout << "4. Manajemen Stok Buku (Khusus Admin)" << endl;
            cout << "5. Keluar" << endl;
            cout << "Pilihan Anda: ";
            cin >> pilihanUser;

            if (pilihanUser == 5) {
                pilihanUser = 99;
            }
        } else {
            cout << "4. Keluar" << endl;
            cout << "Pilihan Anda: ";
            cin >> pilihanUser;
        }

        cout << endl;

        if (pilihanUser == 1) {
            // pilihan 1
            cout << "============" << endl;
            cout << "DAFTAR BUKU" << endl;
            cout << "============" << endl;
            for (int i = 0; i < daftarBuku.size(); i++)
            {
                cout << i + 1 << ". " << daftarBuku[i] << " (Stok: " << stockBuku[i] << ") ";
                if(statusBuku[i] == false) {
                    cout << "[TERSEDIA]" << endl;
                } else {
                    cout << "[TIDAK TERSEDIA]" << endl;
                }
            }

            cout << endl;
            
        } else if (pilihanUser == 2) {
            // pilihan 2
            int nomorMeminjam;
            cout << "============" << endl;
            cout << "PINJAM BUKU" << endl;
            cout << "============" << endl;
            cout << endl;
            cout << "Masukkan Nama Peminjam: ";
            cin >> namaPeminjam;
            for (int i = 0; i < daftarBuku.size(); i++)
            {
                cout << i + 1 << ". " << daftarBuku[i] << " (Stok: " << stockBuku[i] << ")" << endl;
            }
            cout << "Pilih buku yang ingin dipinjam: ";
            cin >> nomorMeminjam;

            if (nomorMeminjam < 1 || nomorMeminjam > daftarBuku.size()) {
                cout << "Pilihan buku tidak valid!" << endl;
            } else if (stockBuku[nomorMeminjam - 1] <= 0 || statusBuku[nomorMeminjam - 1] == true)
            {
                cout << "Maaf, stok buku habis atau tidak tersedia!" << endl;
            } else {
                cout << "Masukkan tanggal peminjaman: ";
                cin >> tanggalPinjam;
                cout << "Masukkan bulan peminjaman: ";
                cin >> bulanPinjam;
                cout << "Masukkan tahun peminjaman: ";
                cin >> tahunPinjam;

                totalPinjam = ((tahunPinjam - 1) * 365) + tanggalPinjam;
                for (int i = 0; i < bulanPinjam - 1; i++) {
                     totalPinjam += tanggal[i];
                }         
                
                daftarPeminjam.push_back( {
                    namaPeminjam,
                    daftarBuku[nomorMeminjam - 1],
                    tanggalPinjam,
                    bulanPinjam,
                    tahunPinjam,
                    totalPinjam,
                    false
                });
                
                stockBuku[nomorMeminjam - 1]--;
                if (stockBuku[nomorMeminjam - 1] == 0) {
                    statusBuku[nomorMeminjam - 1] = true;
                }
                
                cout << "Kamu berhasil meminjam buku [" << daftarBuku[nomorMeminjam - 1] << "]!" << endl;
                cout << "Maksimal pengembalian buku 7 hari dari hari peminjaman :)" << endl;
            }
            cout << endl;
            
        } else if (pilihanUser == 3) {
            // kembalikan buku
            string namaCari;
            
            cout << "=================" << endl;
            cout << "PENGEMBALIAN BUKU" << endl;
            cout << "=================" << endl;
            cout << endl;

            cout << "Masukkan nama peminjam: ";
            cin >> namaCari;
            bool ditemukan = false;
            
            for (int i = 0; i < daftarPeminjam.size(); i++) {
                if (daftarPeminjam[i].nama == namaCari && daftarPeminjam[i].sudahKembali == false) {
                    ditemukan = true;
                    cout << "Buku yang dipinjam: " << daftarPeminjam[i].buku << endl;

                    cout << "Masukkan tanggal pengembalian: ";
                    cin >> tanggalKemb;
                    cout << "Masukkan bulan pengembalian: ";
                    cin >> bulanKemb;
                    cout << "Masukkan tahun pengembalian: ";
                    cin >> tahunKemb;
    
                    totalKemb = ((tahunKemb - 1) * 365) + tanggalKemb;
                    for (int j = 0; j < bulanKemb - 1; j++) {
                        totalKemb += tanggal[j];
                    }
                    int lamaPinjam = totalKemb - daftarPeminjam[i].totalPinjam;
                    int terlambat = lamaPinjam - 7;
                    if (terlambat < 0) {
                        terlambat = 0;
                    }
                    int denda = terlambat * 2000;
                    cout << "Lama peminjaman: " << lamaPinjam << " hari" << endl;
            
                    if (terlambat > 0) {
                        cout << "Anda terlambat selama " << terlambat << " hari" << endl;
                        cout << "Denda yang harus dibayar: Rp." << denda << endl;
                    } else {
                        cout << "Terimakasih sudah mengembalikan buku tepat waktu ;)" << endl;
                    }
                    
                    daftarPeminjam[i].sudahKembali = true;
                    
                    for (int j = 0; j < daftarBuku.size(); j++) {
                        if (daftarBuku[j] == daftarPeminjam[i].buku) {
                            stockBuku[j]++;
                            statusBuku[j] = false;
                            break;
                        }
                    }
                    break;
                }
            }

            if (!ditemukan) {
                cout << "Data peminjam tidak ditemukan!" << endl;
            }
            cout << " " << endl;

        } else if (pilihanUser == 4 && admin[indexUser]) {
            int pilihanAdmin, targetBuku, tambahanStok;
            cout << "=========================" << endl;
            cout << "MANAJEMEN STOK BUKU (ADMIN)" << endl;
            cout << "=========================" << endl;
            for (int i = 0; i < daftarBuku.size(); i++) {
                cout << i + 1 << ". " << daftarBuku[i] << " Stok Saat Ini: " << stockBuku[i] << endl;
            }
            cout << "Pilih nomor buku yang ingin ditambah stoknya: ";
            cin >> targetBuku;

            if (targetBuku >= 1 && targetBuku <= daftarBuku.size()) {
                cout << "Masukkan jumlah penambahan stok: ";
                cin >> tambahanStok;
                stockBuku[targetBuku - 1] += tambahanStok;
                
                if (stockBuku[targetBuku - 1] > 0) {
                    statusBuku[targetBuku - 1] = false;
                }
                
                cout << "Stok buku " << daftarBuku[targetBuku - 1] << " berhasil diperbarui menjadi: " << stockBuku[targetBuku - 1] << endl;
            } else {
                cout << "Pilihan buku tidak valid!" << endl;
            }
            cout << endl;
            pilihanUser = 0;
        }

    } while (pilihanUser != 4 && pilihanUser != 99);
    

    return 0;
}