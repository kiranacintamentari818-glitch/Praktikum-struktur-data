#include <iostream>
using namespace std;

void reverseArray(int* arr, int n) {
    int* start = arr;
    int* end = arr + n - 1;

    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

int main() {

    int angka[7] = {2, 3, 5, 7, 11, 13, 17};

    cout << "Array sebelum dibalik:\n";
    for (int i = 0; i < 7; i++) {
        cout << "Nilai: " << angka[i];
        cout << " | Alamat: " << &angka[i] << endl;
    }

    reverseArray(angka, 7);

    cout << "\nArray sesudah dibalik:\n";
    for (int i = 0; i < 7; i++) {
        cout << "Nilai: " << angka[i];
        cout << " | Alamat: " << &angka[i] << endl;
    }

    return 0;
}