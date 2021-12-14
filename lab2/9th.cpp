#include <iostream>

using namespace std;

struct Zapis {
    int broj;
    string naziv;
};

void insertionSort (Zapis A[], int n, char smjer) {
    int i, j;
    Zapis pomocni;
    if (smjer == '0') {
        for (i = 0; i < n; i++) {
            pomocni = A[i];
            for (j = i; j >= 1 && A[j-1].broj > pomocni.broj; j--) {
                A[j] = A[j-1];
            }
            A[j] = pomocni;
        }
    }
    if (smjer == '1') {
        for (i = 0; i < n; i++) {
            pomocni = A[i];
            for (j = i; j >= 1 && A[j-1].broj < pomocni.broj; j--) {
                A[j] = A[j-1];
            }
            A[j] = pomocni;
        }
    }
}

int main (void) {
    int n;
    cin >> n;
    if (n <= 10) {
        Zapis polje[n];
        for (int i = 0; i < n; i++) {
            cin >> polje[i].broj >> polje[i].naziv;
        }
        char smjer;
        cin >> smjer;

        insertionSort(polje, n, smjer);

        for (int i = 0; i < n; i++) {
            cout << polje[i].broj << " " << polje[i].naziv << endl;
        }
    }
}