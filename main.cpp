#include <iostream>
#include <vector>
using namespace std;

int main() {
    
    int hariMeminjam = 0;
    int pilihanUser; // penampung pilihan user


    // data
    vector<string> daftarBuku = {"kalkulus","fisika","daspro","sistemOperasi"}; // daftar buku
    bool statusBuku[4] = {false,false,false,false}; // status pinjaman buku, false = buku tersedia

    do
    {
        cout << "=== Selamat datang di sistem manajemen Perpustakaan ===" << endl;
        cout << "1. Daftar Buku" << endl;
        cout << "2. Pinjam Buku" << endl;
        cout << "3. Kembalikan Buku" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilihan Anda: ";
        cin >> pilihanUser;

        cout << endl;

        if (pilihanUser == 1) {
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
            
        }

    } while (pilihanUser != 4);
    

    return 0;
}