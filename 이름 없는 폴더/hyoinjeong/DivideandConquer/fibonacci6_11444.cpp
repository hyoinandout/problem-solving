//나중에 한번 다시 풀어보자
#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<long long>> Matrix;
const int MOD = 1e9 + 7;
long long n;
Matrix init = { {1, 1}, {1, 0} };

Matrix matrixMul(Matrix a, Matrix b) {
	Matrix ret(2);
	int i, j, k;
	for (i = 0; i < 2; i++) {
		ret[i].resize(2);
		for (j = 0; j < 2; j++) {
			ret[i][j] = 0;
			for (k = 0; k < 2; k++) {
				ret[i][j] += a[i][k] * b[k][j];
				ret[i][j] %= MOD;
			}
		}
	}
	return ret;
}

Matrix func(long long n) {
	if (n == 1) return init;
	Matrix tmp;
	if (n % 2) { // n 홀수
		tmp = func(n - 1);
		return matrixMul(init, tmp);
	}
	else { // n 짝수
		tmp = func(n / 2);
		return matrixMul(tmp, tmp);
	}
}

int main(){
	cin >> n;
	if (n == 0) {
		cout << 0;
		return 0;
	}

	Matrix ret = func(n);
	cout << ret[1][0];
}