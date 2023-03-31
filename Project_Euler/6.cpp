#include <bits/stdc++.h>

using namespace std;

int main() {
    long long squareOfSums = 0;
    long long sumsOfSquares = 0;

    for (int i = 1; i <= 100; i++) {
        sumsOfSquares += pow(i, 2);
    }
    squareOfSums = pow(100*(100+1)/2, 2);
    cout << squareOfSums - sumsOfSquares << endl;
}
