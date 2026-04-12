#include <iostream>
using namespace std;

#define MAX 5

struct Tiket {
    string nama;
    string rute;
};

struct Queue {
    Tiket data[MAX];
    int front, rear;
};

struct Stack {
    Tiket data[MAX];
    int top;
};

void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

void initStack(Stack *s) {
    s->top = -1;
}

bool isFullQueue(Queue *q) {
    return q->rear == MAX - 1;
}

bool isEmptyQueue(Queue *q) {
    return q->front == -1 || q->front > q->rear;
}

void enqueue(Queue *q, Tiket t) {
    if (isFullQueue(q)) {
        cout << "Antrian penuh\n";
        return;
    }
    if (q->front == -1) q->front = 0;

    q->rear++;
    *(q->data + q->rear) = t;
}

Tiket dequeue(Queue *q) {
    Tiket kosong = {"-", "-"};
    if (isEmptyQueue(q)) {
        cout << "Antrian kosong\n";
        return kosong;
    }

    Tiket t = *(q->data + q->front);
    q->front++;
    return t;
}

void tampilQueue(Queue *q) {
    if (isEmptyQueue(q)) {
        cout << "Kosong\n";
        return;
    }

    for (Tiket *p = q->data + q->front; p <= q->data + q->rear; p++) {
        cout << p->nama << " - " << p->rute << endl;
    }
}

bool isFullStack(Stack *s) {
    return s->top == MAX - 1;
}

bool isEmptyStack(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, Tiket t) {
    if (isFullStack(s)) {
        cout << "Riwayat penuh\n";
        return;
    }

    s->top++;
    *(s->data + s->top) = t;
}

void pop(Stack *s) {
    if (isEmptyStack(s)) {
        cout << "Riwayat kosong\n";
        return;
    }

    s->top--;
}

void tampilStack(Stack *s) {
    if (isEmptyStack(s)) {
        cout << "Belum ada\n";
        return;
    }

    for (Tiket *p = s->data; p <= s->data + s->top; p++) {
        cout << p->nama << " - " << p->rute << endl;
    }
}

int main() {
    Queue q;
    Stack s;

    initQueue(&q);
    initStack(&s);

    int pilih;
    Tiket t;

    do {
        cout << "\n1. Tambah\n2. Proses\n3. Antrian\n4. Riwayat\n0. Keluar\nPilih: ";
        cin >> pilih;

        if (pilih == 1) {
            cout << "Nama: ";
            cin >> t.nama;
            cout << "Rute: ";
            cin >> t.rute;
            enqueue(&q, t);
        }
        else if (pilih == 2) {
            Tiket hasil = dequeue(&q);
            if (hasil.nama != "-") {
                cout << "Diproses: " << hasil.nama << endl;
                push(&s, hasil);
            }
        }
        else if (pilih == 3) {
            tampilQueue(&q);
        }
        else if (pilih == 4) {
            tampilStack(&s);
        }

    } while (pilih != 0);

    return 0;
}