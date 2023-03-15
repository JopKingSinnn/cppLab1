#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<random>
#include<chrono>
#include<vector>
bool searchall(std::vector<int>& a, int i, int n) {
	for (int j = 0; j < n; ++j) {
		if (a[j] == i) { return true; }
	}
	return false;

}
bool searchln(std::vector<int>& a, int i, int n) {
	int min = 0, max = n - 1, l = n / 2;
	while (true) {
		if (a[l] == i) { return true; break; }
		if (a[l] > i) {
			max = l - 1;
			l = (max + min) / 2;
		}
		if (a[l] < i) {
			min = l + 1;
			l = (max + min) / 2;
		}

		if (min > max) { return false; break; }


	}

}

bool chislaall(std::vector<int>& a, int c, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if ((a[i] + a[j]) == c)return true;

		}
	}
	return false;

}

int main() {
	freopen("sources.csv", "w", stdout);
	int n, b;
	std::vector<int> A(100000001);
	for (int i = 0; i < 100000001; i++) {
		A[i] = i;
	}
	int N[] = { 10,100,1000,10000,100000,200000,300000,400000,500000,600000,700000,800000,900000,1000000 };
	//std::cout << "number,time,\n";
	for (int j = 0; j < 14; j++) {
		n = N[j];
		auto begin = std::chrono::steady_clock::now();
		for (int i = 0; i < 1; i++) {
			chislaall(A, n, n);

		}
		auto end = std::chrono::steady_clock::now();
		auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
	}
	//это пробег чтобы след данные плюс минус норм вышли
	for (int n = 1000; n < 1000000; n += 1000) {
		auto begin = std::chrono::steady_clock::now();
		for (int i = 0; i < 1000; i++) {
			std::default_random_engine rng(1001);
			std::uniform_int_distribution <unsigned> dstr(0, 2 * n - 1);
			b = A[dstr(rng)];
			//searchln(A, b, n);
			//searchall(A, b, n);
			chislaall(A, b, n);

		}
		auto end = std::chrono::steady_clock::now();
		auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
		std::cout << n << ',' << time_span.count() << std::endl;
	}

}
