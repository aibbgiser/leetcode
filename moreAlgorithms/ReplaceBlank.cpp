// ReplaceBlank.cpp : Defines the entry point for the console application.

//#include <iostream>
#include <cstring>
#include<stdio.h>	//for printf
#include<cstdlib>	//for system("pause");
//using namespace std;

void ReplaceBlank(char* str, int length){	//char string[],length��ԭ�����ó��ȣ�����ķ�����ԭ�����޸�
	if ( str==NULL && length<=0 ){
		return;
	}
	int originalLength = 0;
	int blankCount = 0;
	int i=0;
	while( str[i]!='\0' ){
		++originalLength;
		if ( str[i]==' ' ){
			++blankCount;
		}
		++i;
	}
	int newLenght = originalLength+blankCount*2;
	if ( newLenght>length ){
		return;
	}
	//λ������
	int firstPos = originalLength;
	int secondPos = newLenght;
	while( firstPos>=0 && firstPos!=secondPos ){	//�����Ǵ��ڵ���0������0����˿ո��ڿ�ͷ�����!
		if( str[firstPos] == ' ' ){
			str[secondPos--] = '0';
			str[secondPos--] = '2';
			str[secondPos--] = '%';
		}else{
			str[secondPos--] = str[firstPos];	//��ͬ\0һ�����ƶ�
		}
		--firstPos;
	}
}
void Test(char* testName, char string[], int length, char expected[])
{
	if(testName != NULL)
		printf("%s begins: ", testName);

	ReplaceBlank(string, length);

	if(expected == NULL && string == NULL)
		printf("passed.\n");
	else if(expected == NULL && string != NULL)
		printf("failed.\n");
	else if(strcmp(string, expected) == 0)
		printf("passed.\n");
	else
		printf("failed.\n");
}

// �ո��ھ����м�
void Test1(){
	const int length = 100;

	char string[length] = "hello world";
	Test("Test1", string, length, "hello%20world");
}

// �ո��ھ��ӿ�ͷ
void Test2(){
	const int length = 100;

	char string[length] = " helloworld";
	Test("Test2", string, length, "%20helloworld");
}

// �ո��ھ���ĩβ
void Test3(){
	const int length = 100;

	char string[length] = "helloworld ";
	Test("Test3", string, length, "helloworld%20");
}

// �����������ո�
void Test4(){
	const int length = 100;

	char string[length] = "hello  world";
	Test("Test4", string, length, "hello%20%20world");
}

// ����NULL
void Test5(){
	Test("Test5", NULL, 0, NULL);
}

// ��������Ϊ�յ��ַ���
void Test6(){
	const int length = 100;

	char string[length] = "";
	Test("Test6", string, length, "");
}

//��������Ϊһ���ո���ַ���
void Test7(){
	const int length = 100;

	char string[length] = " ";
	Test("Test7", string, length, "%20");
}

// ������ַ���û�пո�
void Test8(){
	const int length = 100;

	char string[length] = "helloworld";
	Test("Test8", string, length, "helloworld");
}

// ������ַ���ȫ�ǿո�
void Test9(){
	const int length = 100;

	char string[length] = "   ";
	Test("Test9", string, length, "%20%20%20");
}

int main(){
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();
	Test7();
	Test8();
	Test9();

	system("pause");	//��#include<cstdlib>�У�����using namespace std;
	return 0;
}