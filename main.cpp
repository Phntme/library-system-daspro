#include <iostream>
#include <vector>
using namespace std;

int main() {
    
    string namaPeminjam;
    int hariMeminjam = 0;
    int hariPengembalian = 0;
    int pilihanUser; // penampung pilihan user


    // data
    vector<string> daftarBuku = {"kalkulus","fisika","daspro","sistemOperasi"}; // daftar buku
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
                cout << "Masukkan hari pengembalian (misal: 5) :";
                cin >> hariMeminjam;
                cout << "Buku [ " << daftarBuku[nomorMeminjam - 1] << " ]" <<" berhasil dipinjam oleh " << namaPeminjam << endl;
                cout << "batas pengembalian buku adalah hari ke " << hariMeminjam + 7 << endl; // batas pengembalian 7 hari
                cout << endl;
                statusBuku[nomorMeminjam - 1] = true;

            }
            
        } else if (pilihanUser == 3) {
            // kembalikan buku
            cout << "============" << endl;
            cout << "KEMBALIKAN BUKU" << endl;
            cout << "============" << endl;
            cout << endl;
            
            bool bukuAktif = false;

            // cek apakah ada buku yang dipinjam
            for (int i = 0; i < statusBuku.size(); i++)
            {
                // ada buku dipinjam, cetak informasi nama buku yang dipinjam
                if (statusBuku[i] == true)
                {
                    bukuAktif = true;
                    cout << "buku [" << daftarBuku[i] << "] dipinjam" << endl;
                }
                
            }
            // tidak ada buku yang dipinjam
            if (!bukuAktif) {
                cout << "tidak ada buku yang dipinjam" << endl;
                cout << endl;
                }
            
        }

    } while (pilihanUser != 4);
    

    return 0;
}