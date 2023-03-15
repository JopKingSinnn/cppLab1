#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<random>
#include<chrono>
#include<vector>

bool searchall(std::vector<int> a, int i, int n) {
	for (int j = 0; j < n; ++j) {
		if (a[j] == i) { return true; }
	}
	return false;

}
void swap(int& a, int& b) {
	int c;
	c = a;
	a = b;
	b = c;
}

bool AA(std::vector<int> a, int c, int n) {
	for (int i = 0; i < n; i++) {
		if (a[i] == c) {
			swap(a[i], a[0]);
			return true;
		}
	}
	return false;
}
bool B(std::vector<int> a, int c, int n) {
	for (int i = 0; i < n; i++) {
		if (i == 0 && a[i] == c)return true;
		if (a[i] == c) {
			swap(a[i], a[i - 1]);
			return true;
		}
	}
	return false;
}

bool searchln(std::vector<int> a, int i, int n) {
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



int main() {
	freopen("sourcex.csv", "w", stdout);
	int n, b;;
	int N[] = { 10,100,1000,10000,100000,200000,300000,400000,500000,600000,700000,800000,900000,1000000 };
	for (int j = 0; j < 14; j++) {
		n = N[j];
		std::vector<int> A(1000001);
		std::default_random_engine rng(1001);
		std::uniform_int_distribution <unsigned> dstr(0, 1000000);
		for (int i = 0; i < n; i++) {
			A[i] = dstr(rng);
		}
		std::default_random_engine rng1(1002);
		auto begin = std::chrono::steady_clock::now();
		for (int i = 0; i < 1000; i++) {

			std::uniform_int_distribution <unsigned> dstr(0, n - 1);
			b = A[dstr(rng1)];
			searchln(A, b, n);


		}
		auto end = std::chrono::steady_clock::now();
		auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
		std::cout << n << ',' << time_span.count() << std::endl;
	}



}
