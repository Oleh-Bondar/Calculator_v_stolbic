#include<iostream>

using namespace std;

class Big_number {
private:
	int* number;
	int length;
	bool sign;
public:

	void enter() {
		string a;
		cin >> a;

		int j;
		if (a[0] == '-') {
			sign = true;
			j = 1;
			length = a.length() - 1;
		}
		else {
			sign = false;
			j = 0;
			length = a.length();
		}
		number = new int[length];

		for (int i = 0; i < length; i++) {
			number[i] = a[j] - '0';
			j++;
		}
	}

	void print() {
		if (sign)
			cout << '-';
		for (int i = 0; i < length; i++) {
			cout << number[i];
		}
	}

	Big_number& product(const Big_number& b) {
		Big_number result;
		result.length = length + b.length;
		result.number = new int[result.length];

		if (sign || b.sign) {
			if (sign && b.sign)
				result.sign = false;
			else
				result.sign = true;
		}
		else {
			result.sign = false;
		}

		for(int i = 0; i < result.length; i++) {
			result.number[i] = 0;
		}

		int k = result.length - 1;
		int count = result.length - 1;
		for (int i = length - 1; i > -1; i--) {
			for (int j = b.length - 1; j > -1; j--) {

				int sub_product = 0;
				
				result.number[k] += number[i] * b.number[j];

				if (result.number[k] > 9) {
					sub_product =  result.number[k] / 10;
					result.number[k] -= sub_product * 10;
					result.number[k - 1] += sub_product;
				}
				k--;
			}
			count--;
			k = count;
		}
		return result;
	}
	
};

int main() {
	Big_number a, b;
	a.enter();
	b.enter();

	a.product(b).print();

	return 0;
}