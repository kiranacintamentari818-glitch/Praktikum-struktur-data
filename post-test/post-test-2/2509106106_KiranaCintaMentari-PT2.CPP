#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct Kereta {
    int nomor;
    string nama;
    string asal;
    string tujuan;
    int harga;
};

int jumlah = 0;

void swapKereta(Kereta *a, Kereta *b) {
    Kereta temp = *a;
    *a = *b;
    *b = temp;
}

void tambahData(Kereta *&arr) {
    cout << "\n=== Tambah Data ===\n";

    cout << "Nomor: ";
    cin >> (arr + jumlah)->nomor;
    cin.ignore();

    cout << "Nama: ";
    getline(cin, (arr + jumlah)->nama);

    cout << "Asal: ";
    getline(cin, (arr + jumlah)->asal);

    cout << "Tujuan: ";
    getline(cin, (arr + jumlah)->tujuan);

    cout << "Harga: ";
    cin >> (arr + jumlah)->harga;

    jumlah++;
}

void tampilData(Kereta *arr) {
    if (jumlah == 0) {
        cout << "Data kosong!\n";
        return;
    }

    cout << "\n=== Jadwal Kereta ===\n";
    for (int i = 0; i < jumlah; i++) {
        cout << "\nData ke-" << i + 1 << endl;
        cout << "Nomor  : " << (arr + i)->nomor << endl;
        cout << "Nama   : " << (arr + i)->nama << endl;
        cout << "Asal   : " << (arr + i)->asal << endl;
        cout << "Tujuan : " << (arr + i)->tujuan << endl;
        cout << "Harga  : " << (arr + i)->harga << endl;
    }
}

void linearSearch(Kereta *arr) {
    if (jumlah == 0) {
        cout << "Data kosong!\n";
        return;
    }

    string asal, tujuan;
    cin.ignore();

    cout << "\nCari Rute\n";
    cout << "Asal   : ";
    getline(cin, asal);
    cout << "Tujuan : ";
    getline(cin, tujuan);

    bool ketemu = false;

    for (int i = 0; i < jumlah; i++) {
        if ((arr + i)->asal == asal && (arr + i)->tujuan == tujuan) {
            cout << "\nDitemukan:\n";
            cout << "Nama  : " << (arr + i)->nama << endl;
            cout << "Harga : " << (arr + i)->harga << endl;
            ketemu = true;
        }
    }

    if (!ketemu) cout << "Tidak ditemukan!\n";
}

void jumpSearch(Kereta *arr) {
    if (jumlah == 0) {
        cout << "Data kosong!\n";
        return;
    }

    int cari;
    cout << "\nCari Nomor Kereta: ";
    cin >> cari;

    int step = sqrt(jumlah);
    int prev = 0;

    cout << "\nProses pencarian:\n";

    while (prev < jumlah && (arr + (step < jumlah ? step : jumlah) - 1)->nomor < cari) {
        cout << "Loncat ke index: " << step << endl;
        prev = step;
        step += sqrt(jumlah);

        if (prev >= jumlah) {
            cout << "Tidak ditemukan!\n";
            return;
        }
    }

    for (int i = prev; i < step && i < jumlah; i++) {
        cout << "Cek index: " << i << endl;

        if ((arr + i)->nomor == cari) {
            cout << "Ditemukan: " << (arr + i)->nama << endl;
            return;
        }
    }

    cout << "Tidak ditemukan!\n";
}

void merge(Kereta *arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    Kereta L[100], R[100];

    for (int i = 0; i < n1; i++)
        L[i] = *(arr + l + i);

    for (int j = 0; j < n2; j++)
        R[j] = *(arr + m + 1 + j);

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i].nama <= R[j].nama) {
            *(arr + k) = L[i];
            i++;
        } else {
            *(arr + k) = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        *(arr + k) = L[i];
        i++; k++;
    }

    while (j < n2) {
        *(arr + k) = R[j];
        j++; k++;
    }
}

void mergeSort(Kereta *arr, int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void selectionSort(Kereta *arr) {
    for (int i = 0; i < jumlah - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < jumlah; j++) {
            if ((arr + j)->harga < (arr + minIdx)->harga) {
                minIdx = j;
            }
        }
        swapKereta(arr + i, arr + minIdx);
    }
}

int main() {
    Kereta *data = new Kereta[100];
    int pilih;

    do {
        cout << "\n=== MENU KERETA API ===\n";
        cout << "1. Tambah Data\n";
        cout << "2. Tampilkan Data\n";
        cout << "3. Cari Rute (Linear Search)\n";
        cout << "4. Cari Nomor (Jump Search)\n";
        cout << "5. Urutkan Nama (Merge Sort)\n";
        cout << "6. Urutkan Harga (Selection Sort)\n";
        cout << "7. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih) {
            case 1: tambahData(data); break;
            case 2: tampilData(data); break;
            case 3: linearSearch(data); break;
            case 4: jumpSearch(data); break;
            case 5:
                if (jumlah > 0) {
                    mergeSort(data, 0, jumlah - 1);
                    cout << "Data berhasil diurutkan (Nama A-Z)\n";
                }
                break;
            case 6:
                selectionSort(data);
                cout << "Data berhasil diurutkan (Harga termurah)\n";
                break;
        }

    } while (pilih != 7);

    delete[] data;
    return 0;
}