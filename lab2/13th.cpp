#include <iostream>

using namespace std;

template <typename X> void Zamijeni(X &prvi, X &drugi) {
    X pomocni = prvi;
    prvi = drugi;
    drugi = pomocni;
}

template <typename T> void SelectionSort(T A[], int n) {
    int i, j, min;
    for (i = 0; i < n; i++) {
        min = i;
        for (j = i+1; j < n; j++) {
            if (A[j] < A[min]) min = j;
        }
        Zamijeni(A[i], A[min]);
    }
}

class Vozilo {
    string model;
    int godina;
  public:
    Vozilo() {};
    Vozilo(string model, int godina): model(model), godina(godina) {};
    string getModel() {
        return model;
    }
    int getGodina() {
        return godina;
    }
    void setModel(string model) {
        this->model = model;
    }
    void setGodina(int godina) {
        this->godina = godina;
    }
    friend bool operator< (const Vozilo& v1, const Vozilo& v2) {
        if (v1.model.compare(v2.model) == 0) {
            return (v1.godina > v2.godina);
        }
        if (v1.model.compare(v2.model) < 0) return true;
        return false;
    }
};

int main (void) {
    Vozilo polje[] =  {Vozilo("Pauegot",1981), Vozilo("Pauegot",1983), Vozilo("Ranulet",1967), Vozilo("Fait",1972), Vozilo("BWM",1985), Vozilo("Merdesec",1983)};
    SelectionSort(polje, 6);
    for (int i = 0; i < 6; i++) {
        cout << polje[i].getModel() << " " << polje[i].getGodina() << endl;
    }
}