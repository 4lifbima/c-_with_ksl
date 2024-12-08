#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

struct Barang {
    string nama;
    string kode;
    string harga;
};

vector<Barang> daftarBarang;

void inputData() {
    Barang barang;
    cout << "Masukkan nama barang: ";
    cin >> barang.nama;
    cout << "Masukkan kode barang: ";
    cin >> barang.kode;
    cout << "Masukan Data Harga:";
    cin >> barang.harga;

    daftarBarang.push_back(barang);
    cout << "Data berhasil dimasukkan." << endl;
}

void tampilkanData() {
    if (daftarBarang.empty()) {
        cout << "Data kosong." << endl;
        return;
    }

    cout << "Daftar Barang:" << endl;
    cout << "==================================================" << endl;
    cout << setw(20) << left << "Nama"
         << setw(15) << left << "Kode"
         << setw(15) << right << "Harga" << endl;
    cout << "==================================================" << endl;
    for (const auto& barang : daftarBarang) {
         cout << setw(20) << left << barang.nama
             << setw(15) << left << barang.kode
             << setw(15) << right << "Rp." +(barang.harga) << endl;
    }
    cout << "==================================================" << endl;
    }


void cariData() {
    string cariKode;
    cout << "Masukkan kode barang yang ingin dicari: ";
    cin >> cariKode;

    auto it = find_if(daftarBarang.begin(), daftarBarang.end(), [cariKode](const Barang& barang) {
        return barang.kode == cariKode;
    });

   if (it != daftarBarang.end()) {
        // Header tabel
        cout << "==================================================" << endl;
        cout << setw(20) << left << "Nama"
             << setw(15) << left << "Kode"
             << setw(15) << right << "Harga" << endl;
        cout << "==================================================" << endl;

        // Isi tabel
        cout << setw(20) << left << it->nama
             << setw(15) << left << it->kode
             << setw(15) << right << "Rp." +(it->harga) << endl;

        // Garis penutup
        cout << "==================================================" << endl;
    } else {
        cout << "Data tidak ditemukan." << endl;
    }
}

void urutkanData() {
    if (daftarBarang.empty()) {
        cout << "Data kosong." << endl;
        return;
    }

    sort(daftarBarang.begin(), daftarBarang.end(), [](const Barang& a, const Barang& b) {
        return a.harga < b.harga;
    });

    cout << "Data berhasil diurutkan berdasarkan harga." << endl;
}

int main() {
    int pilihan;

    do {
        cout << "\nMenu:\n";
        cout << "1. Input Data\n";
        cout << "2. Tampilkan Data\n";
        cout << "3. Cari Berdasarkn kode\n";
        cout << "4. Urutkan Berdasarkan harga\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu (1-5): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                inputData();
                break;
            case 2:
                tampilkanData();
                break;
            case 3:
                cariData();
                break;
            case 4:
                urutkanData();
                break;
            case 5:
                cout << "Program selesai. Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan pilih lagi." << endl;
        }

    } while (pilihan != 5);

    return 0;
}

