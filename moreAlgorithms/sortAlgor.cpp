#include <iostream>

using std::cout;
using std::endl;

void swap( int*a, int*b ){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int partion( int* numbers, int low, int high ){
	int clipValue = numbers[low];
	while( low<high && numbers[high]>=clipValue ) --high;
	swap(&numbers[low],&numbers[high]);
	while( low<high && numbers[low]<=clipValue ) ++low;
	swap(&numbers[low],&numbers[high]);
	return low;
}

void quickSort( int* numbers, int low, int high ){
	if ( low<high ){
		int clipLoc = partion(numbers, low, high);
		quickSort(numbers,low,clipLoc-1);
		quickSort(numbers,clipLoc+1,high);
	}
}

void test( int* numbers, int length ){
	int low = 0;
	int high = length-1;
	for ( int i=0; i<length; ++i ){
		cout<<numbers[i]<<" ";
	}
	cout<<endl;
	quickSort(numbers, low, high);
	for ( int i=0; i<length; ++i ){
		cout<<numbers[i]<<" ";
	}
	cout<<endl;
}

int main(){
	int a[10] = {3,1,5,7,2,4,9,6,10,8};
	test(a,10);
	int b[10] = {3,1,5,3,2,4,9,1,10,8};
	test(b,10);
	int* c = NULL;
	test(c,0);
	system("pause");
	return 0;
}