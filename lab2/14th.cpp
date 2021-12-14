#include <iostream>

using namespace std;

void Zamijeni(string *prvi, string *drugi) {
    string temp = *prvi;
    *prvi = *drugi;
    *drugi = temp;
}

void BubbleSortPoboljsani(string A[], int N, int smjer) {
    int i, j;
    bool bilaZamjena = 1;
    if (smjer == 1) {
        for (i = 0; bilaZamjena == 1; i++) {
            bilaZamjena = 0;
            for (j = 0; j < N-1-i; j++) {
                if (A[j+1] < A[j]) {
                    Zamijeni(&A[j], &A[j+1]);
                    bilaZamjena = 1;
                }
            }
        }
    }
    if (smjer == 0) {
        for (i = 0; bilaZamjena == 1; i++) {
            bilaZamjena = 0;
            for (j = 0; j < N-1-i; j++) {
                if (A[j+1] > A[j]) {
                    Zamijeni(&A[j], &A[j+1]);
                    bilaZamjena = 1;
                }
            }
        }
    }
}

int main (void) {
    string polje[] = {"Ivo", "Marko", "Juraj", "Pero", "Idora", "Idora", "Arian", "Bea", "Zvonimir", "Ana Marija"};
    BubbleSortPoboljsani(polje, 10, 0);
    for (int i = 0; i < 10; i++) {
        cout << polje[i] << " ";
    }
}