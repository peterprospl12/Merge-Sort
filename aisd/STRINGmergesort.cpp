#include <iostream>
#include <string>
using namespace std;
void printarray(int nr_of_num, string* array);


bool operator<=(string num1, string num2) {
	if (num1.length() < num2.length()) {
		return true;
	}
	else if(num1.length() == num2.length()) {
		for (int i = 0; i < num1.length(); i++) {
			if ((num1[i] - '0') < (num2[i] - '0')) {
				return true;
			}
			else if ((num1[i] - '0') > (num2[i] - '0')) {
				return false;
			}
		}
		return true;
	}
	else {
		return false;
	}

}

void mergesort(int nr_of_num, string* arr) {
	if (nr_of_num > 1) {
		int left_size, right_size, x, y, z;
		
		
		left_size = nr_of_num / 2;
		right_size = nr_of_num / 2;
		if (nr_of_num % 2 == 1) {
			left_size += 1;
		}
		
		string* left_arr = new string[left_size];
		string* right_arr = new string[right_size];
		
		for (int i = 0; i < left_size; i++) {
			left_arr[i] = arr[i];
		}
		for (int i = 0; i < right_size; i++) {
			right_arr[i] = arr[i+left_size];
		}
		
		mergesort(left_size, left_arr);
		mergesort(right_size, right_arr);
		
		x = y = z = 0;

		while (x < left_size && y < right_size) {
			if (left_arr[x] <= right_arr[y]) {
				arr[z] = left_arr[x];
				x += 1;
			}
			else {
				arr[z] = right_arr[y];
				y += 1;
			}
			z += 1;
		}

		while (x < left_size) {
			arr[z] = left_arr[x];
			x += 1;
			z += 1;
		}
		while (y < right_size) {
			arr[z] = right_arr[y];
			y += 1;
			z += 1;
		}
		delete[] left_arr;
		delete[] right_arr;
	}
	

}

	void printarray(int nr_of_num, string* array) {
		for (int i = 0; i < nr_of_num; i++) {
			cout << array[i] << endl;
		}
		cout << endl;
	}




int main() {
	
	string p = "123";


	int nr_of_num;
	cin >> nr_of_num;

	string* arr = new string[nr_of_num];
	for (int i = 0; i < nr_of_num; i++) {
		cin >> arr[i];
	}
	cout << "Array before sort" << endl;
	printarray(nr_of_num, arr);
	mergesort(nr_of_num, arr);
	cout << "Array after sort" << endl;
	printarray(nr_of_num, arr);

	delete[] arr;
	

	return 0;

}
