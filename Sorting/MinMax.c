#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define n 100000

int a[n], min, max;

void MinMax(int low, int high) {
	int mid, min1, max1;
	if (low == high) {
		max = min = a[low];
	}
	else if (low == high - 1) {
		if (a[low] < a[high]) {
			min = a[low];
			max = a[high];
		}
		else {
			min = a[high];
			max = a[low];
		}
	}
	else {
		mid = (low + high) / 2;
		MinMax(low, mid);
		min1 = min;
		max1 = max;
		MinMax(mid + 1, high);
		if (max1 > max){
			max = max1;
        }
		if (min1 < min){
			min = min1;
        }
	}
}

void main(){
	MinMax(0,n-1);
}

