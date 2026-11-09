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
    vector<bool> statusBuku = {false,false,false,false}; // status pinjaman buku, false = buku tersedia

    do
    {
        // daftar menu
        cout << "=== Selamat datang di sistem manajemen Perpustakaan ===" << endl;
        cout << "1. Daftar Buku" << endl;
        cout << "2. Pinjam Buku" << endl;
        cout << "3. Kembalikan Buku" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilihan Anda: ";
        cin >> pilihanUser;

        cout << endl;

        if (pilihanUser == 1) {
            // pilihan 1
            cout << "============" << endl;
            cout << "DAFTAR BUKU" << endl;
            cout << "============" << endl;
            for (int i = 0; i < daftarBuku.size(); i++)
            {
                if(statusBuku[i] == false) {

                    cout << i + 1 << "." << daftarBuku[i] << " [TERSEDIA]" << endl;
                } else {
                    cout << i + 1 << "." << daftarBuku[i] << " [TIDAK TERSEDIA]" << endl;

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
                cout << i + 1 << "." << daftarBuku[i] << endl;
            }
            cout << "Pilih buku yang ingin dipinjam: ";
            cin >> nomorMeminjam;

            if (statusBuku[nomorMeminjam - 1] == true)
            {
                cout << "Buku tidak tersedia untuk dipinjam!";
            } else {
                cout << "Masukkan tanggal peminjaman" << endl;
                cin >> tanggalPinjam;
                cout << "Masukkan bulan peminjaman" << endl;
                cin >> bulanPinjam;
                cout << "Masukkan tahun peminjaman" << endl;
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
                
                cout << "Kamu berhasil meminjam buku [" << daftarBuku[nomorMeminjam - 1] << "]!" << endl;
                statusBuku[nomorMeminjam - 1] = true;
                cout << "Terima Kasih telah meminjam buku di Perpustakaan Gratis" << endl;
                cout << "Maksimal pengembalian buku 7 hari dari hari peminjaman :)" << endl;
            }
            cout << endl;
            
        } else if (pilihanUser == 3) {
            // kembalikan buku
            string namaCari;
            
            cout << "=================" << endl;
            cout << "PENGEMBALIAN BUKU" << endl;
            cout << "=================" << endl;
            cout << " " << endl;

            cout << "Masukkan nama peminjam: ";
            cin >> namaCari;
            bool ditemukan = false;
            
            for (int i = 0; i < daftarPeminjam.size(); i++) {
                if (daftarPeminjam[i].nama == namaCari && daftarPeminjam[i].sudahKembali == false) {
                    ditemukan = true;
                    cout << "Buku yang dipinjam: " << daftarPeminjam[i].buku << endl;

                    cout << "Masukkan tanggal" << endl;
                    cin >> tanggalKemb;

                    cout << "Masukkan bulan" << endl;
                    cin >> bulanKemb;

                    cout << "Masukkan tahun" << endl;
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
                    }else{
                        cout << "Terimakasih sudah mengembalikan buku tepat waktu ;)" << endl;
                    }
                    daftarPeminjam[i].sudahKembali = true;
                    // Mengubah status ketersediaan buku
                    for (int j = 0; j < daftarBuku.size(); j++) {
                        if (daftarBuku[j] == daftarPeminjam[i].buku) {
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
        }

    } while (pilihanUser != 4);
    

    return 0;
}