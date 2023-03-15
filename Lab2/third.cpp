#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include <type_traits>


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

unsigned search_numbers(unsigned const n) {
	vector<unsigned> numbers;
	numbers.push_back(1);
	numbers.push_back(1);
	unsigned d = 0;
	while (d <= n) {
		int m = numbers[size(numbers) - 1] + numbers[size(numbers) - 2];
		numbers.push_back(m);
		d = m;
	}
	numbers.pop_back();
    return numbers.size();
}

unsigned *create_numbers(unsigned const amount) {
	unsigned* numbers = new unsigned[amount];
	numbers[0] = 1;
	numbers[1] = 1;
	for (unsigned i = 2; i != amount; ++i)
		numbers[i] = numbers[i - 1] + numbers[i - 2];
	return numbers;
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

void fibonacci_sort(unsigned arr[], unsigned const begin_idx, unsigned const end_idx, unsigned numbers[], unsigned amount, unsigned &sorts) {
	unsigned p;
	for (unsigned i = amount; i != 0; --i) {
		p = numbers[i - 1];
		step(arr, begin_idx, end_idx, p, sorts);
	}
	bubble_sort(arr, begin_idx, end_idx, sorts);
}

auto time_counter(unsigned arr[], unsigned const begin_idx, unsigned const end_idx, unsigned numbers[], unsigned amount, unsigned &sorts) {
	auto begin = std::chrono::steady_clock::now();
	for (unsigned cnt = 100; cnt != 0; --cnt) {
		initialization(arr, end_idx);
		fibonacci_sort(arr, begin_idx, end_idx, numbers, amount, sorts);
	}
	auto end = std::chrono::steady_clock::now();
	auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
	return time_span.count();
}

int main() {
	unsigned const n = 10000;
	unsigned begin_idx = 0;
	unsigned end_idx = n;
	unsigned data[n] = { 0 };
	unsigned time;
	unsigned sorts = 0;
	unsigned const amount = search_numbers(n);
	unsigned* numbers = new unsigned[amount];
	numbers = create_numbers(amount);
	time = time_counter(data, begin_idx, end_idx, numbers, amount, sorts);;
	cout << time;
	cout << '\n';
	cout << sorts;
}
