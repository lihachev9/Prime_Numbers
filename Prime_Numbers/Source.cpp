#include <iostream>
#include <cmath>
#include <time.h>
#include <omp.h>

using namespace std;

bool isPrime(int num) {
    if (num == 2) return true;
    if (num <= 1 || num % 2 == 0) return false;
    double sqrt_num = sqrt(num);
    for (int div = 3; div <= sqrt_num; div += 2)
        if (num % div == 0) return false;
    return true;
}

bool run_program(int N) {
    bool tmp;
#pragma omp parallel for
    for (int i = 0; i < N; i++) tmp = isPrime(i);
    return tmp;
}

int main() {
    int N = 10000000;
    clock_t start, end;
    start = clock();
    cout << run_program(N) << endl;
    end = clock();
    cout << (end - start) / ((double)CLOCKS_PER_SEC) << endl;
    system("pause");
    return 0;
}