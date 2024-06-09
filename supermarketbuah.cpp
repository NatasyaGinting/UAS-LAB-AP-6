#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Definisi struct Buah
struct Buah {
    string nama;
    float berat;
    float harga;

    // Constructor untuk struct Buah
    Buah(string n, float b, float h) : nama(n), berat(b), harga(h) {}
};

// Definisi class Supermarket
class Supermarket {
private:
    vector<Buah*> keranjangBuah;

public:
    // Destructor untuk membersihkan memori
    ~Supermarket() {
        for(auto buah : keranjangBuah) {
            delete buah;
        }
    }

    // Fungsi untuk menambah buah ke keranjang
    void tambahBuah(string nama, float berat, float harga) {
        Buah* buahBaru = new Buah(nama, berat, harga);
        keranjangBuah.push_back(buahBaru);
    }

    // Fungsi untuk menampilkan semua buah dalam keranjang
    void tampilkanKeranjang() {
        for(auto buah : keranjangBuah) {
            cout << "Nama: " << buah->nama 
                 << ", Berat: " << buah->berat << " kg, Harga: Rp " << buah->harga << endl;
        }
    }

    // Fungsi untuk menghitung total harga semua buah dalam keranjang
    float hitungTotalHarga() {
        float total = 0;
        for(auto buah : keranjangBuah) {
            total += buah->harga;
        }
        return total;
    }
};

int main() {
    Supermarket supermarket;

    cout << "-------------------------------------------------------" << endl;
    cout << "Selamat datang di Supermarket Buah kami!" << endl;
    cout << "-------------------------------------------------------" << endl;
    
    // Daftar buah yang sudah diketahui
    vector<Buah> daftarBuah = {
        Buah("Apel", 0.2, 10000),
        Buah("Pisang", 0.15, 5000),
        Buah("Jeruk", 0.3, 8000),
        Buah("Mangga", 0.5, 15000),
        Buah("Anggur", 0.05, 20000)
    };

    int pilihan, jumlahBeli;
    char lanjut;

    cout << "Daftar buah yang dijual di Supermarket:" << endl;
    cout << "-------------------------------------------------------" << endl;
    for (int i = 0; i < daftarBuah.size(); ++i) {
        cout << i + 1 << ". " << daftarBuah[i].nama << " - Rp " << daftarBuah[i].harga << " per buah" << endl;
    }
    cout << "-------------------------------------------------------" << endl;

    do {
        cout << "\nPilih buah yang ingin dibeli (1-" << daftarBuah.size() << "): ";
        cin >> pilihan;

        if (pilihan < 1 || pilihan > daftarBuah.size()) {
            cout << "Pilihan tidak valid, silakan coba lagi." << endl;
            continue;
        }

        cout << "Masukkan jumlah buah " << daftarBuah[pilihan - 1].nama << " yang ingin dibeli: ";
        cin >> jumlahBeli;

        supermarket.tambahBuah(daftarBuah[pilihan - 1].nama, daftarBuah[pilihan - 1].berat, daftarBuah[pilihan - 1].harga * jumlahBeli);

        cout << "Apakah Anda ingin membeli buah yang lain? (y/n): ";
        cin >> lanjut;

    } while (lanjut == 'y' || lanjut == 'Y');
    cout << "-------------------------------------------------------" << endl;

    // Menampilkan daftar buah yang dibeli
    cout << "\nDaftar buah yang dibeli:" << endl;
    cout << "-------------------------------------------------------" << endl;
    supermarket.tampilkanKeranjang();
    cout << "-------------------------------------------------------" << endl;

    // Menghitung dan menampilkan total harga semua buah yang dibeli
    float totalHarga = supermarket.hitungTotalHarga();
    cout << "Total harga semua buah yang dibeli: Rp " << totalHarga << endl;
    cout << "-------------------------------------------------------" << endl;
    cout << "Terima kasih telah berbelanja di Supermarket Buah kami!" << endl;
    cout << "-------------------------------------------------------" << endl;

    return 0;
}