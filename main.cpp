// #include <iostream>
// using namespace std;

// int main() {
//     // daftar buku
//     int userIndex; // penampung pilihan user
//     int hari = 1;
//     string buku[] = {"kalkulus","fisika","daspro","sistemOperasi"};

//     cout << "Daftar buku perpoose: " << endl;
//     cout << "1. kalkulus" << endl;
//     cout << "2. fisika" << endl;
//     cout << "3. daspro" << endl;
//     cout << "4. sistem operasi" << endl;
//     cout << "\nPilih buku yang ingin anda pinjam: ";
//     cin >> userIndex;
//     cout << buku[userIndex - 1];

    
//     return 0;
// }

#include <iostream>
#include <string>
using namespace std;

int main() {
    int userIndex;
    string buku[] = {"kalkulus", "fisika", "daspro", "sistem operasi"};
    int totalBuku = sizeof(buku) / sizeof(buku[0]); // Menghitung total elemen array secara otomatis (4)

    cout << "Daftar buku perpoose: " << endl;
    for (int i = 0; i < totalBuku; i++) {
        cout << i + 1 << ". " << buku[i] << endl;
    }

    cout << "\nPilih buku yang ingin anda pinjam: ";

    // Pengecekan input
    if (!(cin >> userIndex) || userIndex < 1 || userIndex > totalBuku) {
        cout << "Error: Pilihan tidak valid! Harap masukkan angka antara 1 sampai " << totalBuku << "." << endl;
    } else {
        cout << "Buku yang Anda pilih: " << buku[userIndex - 1] << endl;
    }

    return 0;
}