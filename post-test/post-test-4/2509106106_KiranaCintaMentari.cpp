#include <iostream>
using namespace std;

struct Node {
    string data;
    Node* next;
};

Node *front = NULL, *rear = NULL;

// Stack (Riwayat)
Node *top = NULL;

void enqueue(string nilai) {
    Node* baru = new Node;
    baru->data = nilai;
    baru->next = NULL;

    if (rear == NULL) {
        front = rear = baru;
    } else {
        rear->next = baru;
        rear = baru;
    }

    cout << "Data berhasil ditambahkan ke antrian.\n";
}

void dequeue() {
    if (front == NULL) {
        cout << "Antrian kosong (Underflow).\n";
        return;
    }

    Node* hapus = front;
    string nilai = hapus->data;

    front = front->next;
    if (front == NULL) rear = NULL;

    delete hapus;

    cout << "Data keluar dari antrian: " << nilai << endl;


    Node* baru = new Node;
    baru->data = nilai;
    baru->next = top;
    top = baru;
}

void tampilAntrian() {
    if (front == NULL) {
        cout << "Antrian kosong.\n";
        return;
    }

    Node* bantu = front;
    cout << "Isi Antrian: ";
    while (bantu != NULL) {
        cout << bantu->data << " -> ";
        bantu = bantu->next;
    }
    cout << "NULL\n";
}

void push(string nilai) {
    Node* baru = new Node;
    baru->data = nilai;
    baru->next = top;
    top = baru;

    cout << "Data masuk ke riwayat.\n";
}

void pop() {
    if (top == NULL) {
        cout << "Riwayat kosong (Underflow).\n";
        return;
    }

    Node* hapus = top;
    cout << "Data dihapus dari riwayat: " << hapus->data << endl;

    top = top->next;
    delete hapus;
}

void peek() {
    if (top == NULL) {
        cout << "Riwayat kosong.\n";
    } else {
        cout << "Data teratas: " << top->data << endl;
    }
}

void tampilRiwayat() {
    if (top == NULL) {
        cout << "Riwayat kosong.\n";
        return;
    }

    Node* bantu = top;
    cout << "Isi Riwayat: ";
    while (bantu != NULL) {
        cout << bantu->data << " -> ";
        bantu = bantu->next;
    }
    cout << "NULL\n";
}


int main() {
    int pilih;
    string data;

    do {
        cout << "\n=== MENU PROGRAM ===\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Push (Manual)\n";
        cout << "4. Pop\n";
        cout << "5. Peek\n";
        cout << "6. Tampil Antrian\n";
        cout << "7. Tampil Riwayat\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih) {
        case 1:
            cout << "Masukkan data: ";
            cin >> data;
            enqueue(data);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            cout << "Masukkan data: ";
            cin >> data;
            push(data);
            break;

        case 4:
            pop();
            break;

        case 5:
            peek();
            break;

        case 6:
            tampilAntrian();
            break;

        case 7:
            tampilRiwayat();
            break;

        case 0:
            cout << "Program selesai.\n";
            break;

        default:
            cout << "Pilihan tidak valid!\n";
        }

    } while (pilih != 0);

    return 0;
}