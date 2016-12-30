// FindInPartiallySortedMatrix.cpp : Defines the entry point for the console application.
#include <iostream>

using namespace std;

bool find( int* matrix, int nRows, int nCols, int number ){	//��ά���鱻ת��Ϊһά��ʽ
	if(matrix != NULL && nRows > 0 && nCols > 0){	//���뿼����Ч�ԣ�����
		//�����Ͻ�����,�ҵ����½�Ϊֹ
		int row = 0;
		int col = nCols-1;
		while( (col>=0)&&(row<nRows) ){
			if( matrix[row*nCols+col]==number ){
				return true;
			}else{
				if( matrix[row*nCols+col]>number ){
					--col;
				}else{
					++row;
				}
			}
		}
	}
	return false;
}

//���Գ���
void Test(char* testName, int* matrix, int rows, int columns, int number, bool expected)
{
	if(testName != NULL)
		printf("%s begins: ", testName);

	bool result = find(matrix, rows, columns, number);
	if(result == expected)
		printf("Passed.\n");
	else
		printf("Failed.\n");
}
//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// Ҫ���ҵ�����������
void Test1()
{
	int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
	Test("Test1", (int*)matrix, 4, 4, 7, true);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// Ҫ���ҵ�������������
void Test2()
{
	int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
	Test("Test2", (int*)matrix, 4, 4, 5, false);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// Ҫ���ҵ�������������С������
void Test3()
{
	int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
	Test("Test3", (int*)matrix, 4, 4, 1, true);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// Ҫ���ҵ�������������������
void Test4()
{
	int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
	Test("Test4", (int*)matrix, 4, 4, 15, true);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// Ҫ���ҵ�������������С�����ֻ�С
void Test5()
{
	int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
	Test("Test5", (int*)matrix, 4, 4, 0, false);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// Ҫ���ҵ������������������ֻ���
void Test6()
{
	int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
	Test("Test6", (int*)matrix, 4, 4, 16, false);
}

// ³���Բ��ԣ������ָ��
void Test7()
{
	Test("Test7", NULL, 0, 0, 16, false);	//�����false
}

int main(){
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();
	Test7();

	system("pause");
	return 0;
}