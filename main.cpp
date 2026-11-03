#include <iostream>
using namespace std;

int main() {
    
    int hariMeminjam = 0;
    int pilihanUser; // penampung pilihan user
    string buku[4] = {"kalkulus","fisika","daspro","sistemOperasi"}; // daftar buku
    bool statusBuku[4] = {false,false,false,false}; // status pinjaman buku, false = buku tersedia

    cout << "=== Daftar buku Perpustakaan ===" << endl;
    cout << "1. kalkulus" << endl;
    cout << "2. fisika" << endl;
    cout << "3. daspro" << endl;
    cout << "4. sistem operasi" << endl;
    cout << "\nPilih buku yang ingin anda pinjam: ";
    cin >> pilihanUser;
    cout << "anda meminjam buku " << buku[pilihanUser - 1] << endl;

    return 0;
}