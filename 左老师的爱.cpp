#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <iostream>
using namespace std;

int arr[100000];
int B[100000]; 

int BiSearch(int *b, int len, int w) {
	int left = 0, right = len - 1;
	int mid;
	while (left <= right) {
		mid = left + (right - left) / 2;
		if (b[mid] > w)
			right = mid - 1;
		else if (b[mid] < w)
			left = mid + 1;
		else    //找到了该元素，则直接返回  
			return mid;
	}
	return left;//数组b中不存在该元素，则返回该元素应该插入的位置  
}

long long LIS(int *arr, int n) {
	long long len = 1;
	B[0] = arr[0];
	int i, pos = 0;
	for (i = 1; i<n; ++i) {
		if (arr[i] > B[len - 1]){ //如果大于B中最大的元素，则直接插入到B数组末尾 
			B[len] = arr[i];
			len++;
		}
		else {
			pos = BiSearch(B, len, arr[i]); //二分查找需要插入的位置  
			B[pos] = arr[i];
		}
	}

	return len;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	long long len = LIS(arr, n);
	cout << len << endl;

	return 0;
}
