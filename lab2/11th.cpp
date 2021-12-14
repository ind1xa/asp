#include <iostream>

using namespace std;

struct Zapis {
    int sifra;
    string naziv;
};

void Swap(Zapis* left, Zapis* right) {
      Zapis temp = *left;
      *left = *right;
      *right = temp;
}

void obicanBubbleSort (Zapis A[], int n, char smjer) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-1-i; j++) {
            if (A[j+1].sifra < A[j].sifra && smjer == '0') Swap(&A[j], &A[j+1]);
            if (A[j+1].sifra > A[j].sifra && smjer == '1') Swap(&A[j], &A[j+1]);
        }
    }
}

int main (void) {
    int n;
    cin >> n;
    if (n <= 10) {
        Zapis polje[n];
        for (int i = 0; i < n; i++) {
            cin >> polje[i].sifra >> polje[i].naziv;
        }
        char smjer;
        cin >> smjer;

        obicanBubbleSort(polje, n, smjer);

        for (int i = 0; i < n; i++) {
            cout << polje[i].sifra << " " << polje[i].naziv << endl;
        }
    }
}