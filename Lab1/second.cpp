#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<chrono>
#include<random>


bool chislaall(int a[], int c, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if ((a[i] + a[j]) == c)return true;

		}
	}
	return false;

}

int main() {
	freopen("source.csv", "w", stdout);
	int a[100000], b;
	unsigned seed = 1001;
	std::default_random_engine rng(seed);
	std::uniform_int_distribution <unsigned> dstr(0, 8000000);
	for (int i = 0; i < 100000; i++) {
		a[i] = dstr(rng);
	}
	int N[] = { 100,500,750,1000,2500,5000,10000,25000 };
	for (int i = 0; i < 7; i++) {
		auto begin = std::chrono::steady_clock::now();
		for (int j = 0; j < 1000; j++) {
			std::uniform_int_distribution <unsigned> dstr(0, N[i] - 1);
			b = a[dstr(rng)] + a[dstr(rng)];
			chislaall(a, 16000000, N[i]);

		}
		auto end = std::chrono::steady_clock::now();
		auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
		std::cout << N[i] << ',' << time_span.count() << std::endl;
	}
	return 0;
}
