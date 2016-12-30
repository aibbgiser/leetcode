#include<exception>
#include <iostream>

using std::cout;
using std::endl;
using std::exception;

int MinInOrder( int* numbers, int index1, int index2 ){
	int result = numbers[index1];
	for ( int i=index1+1; i<=index2 ;++i ){
		if ( result>numbers[i] ){
			result = numbers[i];
		}
	}
	return result;
}

int min( int* numbers, int length ){
	if ( numbers==NULL || length<=0 ){
		throw new exception("Invalid parameters");
	}
	int index1 = 0;
	int index2 = length - 1;
	int indexMid = index1;	//��󷵻����
	while( numbers[index1]>=numbers[index2] ){
		if ( index2-index1 == 1 ){
			indexMid = index2;
			break;
		}
		indexMid = (index1 + index2) / 2;
		if ( numbers[index1]==numbers[index2] && numbers[index1]==numbers[indexMid] ){
			return MinInOrder(numbers, index1, index2);
		}
		if(numbers[indexMid] >= numbers[index1]){
			index1 = indexMid;
		}else{
			if(numbers[indexMid] <= numbers[index2])
				index2 = indexMid;
		}
	}
	return numbers[indexMid];
}

void Test(int* numbers, int length, int expected){
	int result;
	try{
		result = min(numbers,length);
		for ( int i=0; i<length; ++i ){
			cout<<numbers[i]<<" ";
		}
		if(result==expected)
			cout<<"test passed."<<endl;
		else
			cout<<"test failed."<<endl;
	}
	catch(...){
		if(numbers==NULL)
			cout<<"test passed."<<endl;
		else
			cout<<"test failed."<<endl;
	}
}

int main(){
	// �������룬��������������һ����ת
	int array1[] = {3, 4, 5, 1, 2};
	Test(array1, sizeof(array1) / sizeof(int), 1);

	// ���ظ����֣������ظ������ָպõ���С������
	int array2[] = {3, 4, 5, 1, 1, 2};
	Test(array2, sizeof(array2) / sizeof(int), 1);

	// ���ظ����֣����ظ������ֲ��ǵ�һ�����ֺ����һ������
	int array3[] = {3, 4, 5, 1, 2, 2};
	Test(array3, sizeof(array3) / sizeof(int), 1);

	// ���ظ������֣������ظ������ָպ��ǵ�һ�����ֺ����һ������
	int array4[] = {1, 0, 1, 1, 1};
	Test(array4, sizeof(array4) / sizeof(int), 0);

	// �����������飬��ת0��Ԫ�أ�Ҳ���ǵ����������鱾��
	int array5[] = {1, 2, 3, 4, 5};
	Test(array5, sizeof(array5) / sizeof(int), 1);

	// ������ֻ��һ������
	int array6[] = {2};
	Test(array6, sizeof(array6) / sizeof(int), 2);

	// ����NULL
	Test(NULL, 0, 0);

	system("pause");
	return 0;
}