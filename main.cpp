#include <iostream>
using namespace std;

int main() {
    
    int hariMeminjam = 0;
    int pilihanUser; // penampung pilihan user


    // data
    string buku[4] = {"kalkulus","fisika","daspro","sistemOperasi"}; // daftar buku
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

        cout << "user memilih" << pilihanUser << endl;
    } while (pilihanUser != 4);
    

    return 0;
}