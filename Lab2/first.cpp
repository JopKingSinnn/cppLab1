#include <iostream>
#include <string>
#include <random>
#include <chrono>

using namespace std;

void initialization(unsigned data[], unsigned const n) {
	vector<int> types;
	vector<int>::iterator it;
	int number;
	unsigned seed = 1001;
	for (unsigned m = 0; m < n; m++)
		types.push_back(m);
	for (unsigned counter = 0; counter != n; ++counter) {
		std::default_random_engine rng(seed);
		std::uniform_int_distribution <unsigned> dstr(0, types.size() - 1);
		number = dstr(rng);
		it = types.begin();
		advance(it, number);
		data[counter] = types[number];
		types.erase(it);
	}
}

void step(unsigned arr[], unsigned const begin_idx, unsigned const end_idx, unsigned pace, unsigned &sorts) {
	for (unsigned i = begin_idx; i != end_idx - pace; ++i)
		if (arr[i] > arr[i + pace]) {
			int a = arr[i];
			arr[i] = arr[i + pace];
			arr[i + pace] = a;
			sorts += 1;
		}
}

void bubble_sort(unsigned arr[], unsigned const begin_idx, unsigned const end_idx, unsigned &sorts) {
	bool flag = true;
	while (flag == true) {
		flag = false;
		for (unsigned i = begin_idx; i != end_idx; ++i)
			if (arr[i] > arr[i + 1]) {
				int a = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = a;
				sorts += 1;
				flag = true;
			}
	}
}

void shell_sort(unsigned arr[], unsigned const begin_idx, unsigned const end_idx, unsigned &sorts) {
	unsigned d = end_idx;
	while (d > 0) {
		step(arr, begin_idx, end_idx, d, sorts);
		d = d / 2;
	}
	bubble_sort(arr, begin_idx, end_idx, sorts);
}

auto time_counter(unsigned arr[], unsigned const begin_idx, unsigned const end_idx, unsigned &sorts) {
	auto begin = std::chrono::steady_clock::now();
	for (unsigned cnt = 100; cnt != 0; --cnt) {
		initialization(arr, end_idx);
		shell_sort(arr, begin_idx, end_idx, sorts);
	}
	auto end = std::chrono::steady_clock::now();
	auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
	return time_span.count();
}

int main() {
	unsigned const n = 1000;
	unsigned const begin_idx = 0;
	unsigned const end_idx = n;
	unsigned data[n] = { 0 };
	double time;
	unsigned sorts = 0;
	time = time_counter(data, begin_idx, end_idx, sorts);
	cout << time;
	cout << '\n';
	cout << sorts;
}
