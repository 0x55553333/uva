
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <memory.h>
using namespace std;
typedef unsigned long long ull;
struct barray {
	ull* b;
	size_t len;
	barray(size_t capacity) {
		this->len = capacity / 64 + 1;
		this->b = new ull[this->len];
		memset(this->b, 0, this->len * sizeof(ull));
	}
	~barray() {
		delete[] this->b;
		this->len = 0;
	}
	void set(size_t k) {
		size_t k_a = k / 64, k_b = k % 64;
		b[k_a] |= 1<<k_b;
	}
	unsigned get(size_t k) {
		size_t k_a = k / 64, k_b = k % 64;
		return (unsigned) (b[k_a]>>k_b) & 1;
	}
	void unset(size_t k) {
		size_t k_a = k / 64, k_b = k % 64;
		b[k_a] &= ~(1 << k_b);
	}
	void toggle(size_t k) {
		size_t k_a = k /64, k_b = k % 64;
		b[k_a] ^= ~(1 << k_b);
	}
};
int main()
{
	cout << "bit array supporting dynamic initialization." << endl;
	return 0;
}
