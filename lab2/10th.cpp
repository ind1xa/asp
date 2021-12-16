#include <iostream>
#include <algorithm>

using namespace std;

void Swap(int* left, int* right) {
      int temp = *left;
      *left = *right;
      *right = temp;
}

void selection2Sort (int A[], int n, char smjer) {
    int i, j, min, max;
    if (smjer == '0') {
        for (i = 0; i < n/2; i++) {
            min = i;
            max = n-1-i;
            for (j = i; j < n-i; j++) {
                if (A[j] < A[min]) min = j;
                if (A[j] > A[max]) max = j;
            }
            Swap(&A[i], &A[min]);
            if (max == i) Swap(&A[n-1-i], &A[min]);
            else Swap(&A[n-1-i], &A[max]);
        }
    }
    if (smjer == '1') {
        for (i = 0; i < n/2; i++) {
            min = i;
            max = n-1-i;
            for (j = i; j < n-i; j++) {
                if (A[j] < A[min]) min = j;
                if (A[j] > A[max]) max = j;
            }
            Swap(&A[i], &A[max]);
            if (min == i) Swap(&A[n-1-i], &A[max]);
            else Swap(&A[n-1-i], &A[min]);
        }
    }
}

int main (void) {
    int n;
    cin >> n;
    if (n <= 10) {
        int polje[n];
        for (int i = 0; i < n; i++) {
            cin >> polje[i];
        }
        char smjer;
        cin >> smjer;

        selection2Sort(polje, n, smjer);

        for (int i = 0; i < n; i++) {
            cout << polje[i] << " ";
        }
    }
}