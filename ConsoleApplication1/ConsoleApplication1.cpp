#include <iostream>
#include <Windows.h>
#include <algorithm>
#include <numeric>
#include <climits>

using namespace std;

int minimalMinutesToCollect(int* candies, int n) {
    int res = INT_MAX;
    int allNuts = accumulate(candies, candies + n, 0, std::plus<int>());

    for (int x = 1; x <= allNuts; ++x) {
        int remnuts = 0;
        for (int i = 0; i < n; ++i) {
            remnuts += candies[i] % x;
        }
        res = min(res, remnuts + (n - 1) * x);
    }

    return res;
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int n;
    cout << "Введiть кiлькiсть тарiлок: ";
    cin >> n;

    int* nuts = new int[n];

    for (int i = 0; i < n; ++i) {
        cout << "Введiть кiлькiсть горiшкiв в тарiлцi " << i + 1 << ": ";
        cin >> nuts[i];
    }

    int resul = minimalMinutesToCollect(nuts, n);
    cout << "Мiнiмальна кiлькiсть хвилин для збору горiшкiв: " << resul << endl;

    delete[] nuts;

    return 0;
}

