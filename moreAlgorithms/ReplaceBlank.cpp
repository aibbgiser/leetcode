// ReplaceBlank.cpp : Defines the entry point for the console application.

//#include <iostream>
#include <cstring>
#include<stdio.h>	//for printf
#include<cstdlib>	//for system("pause");
//using namespace std;

void ReplaceBlank(char* str, int length){	//char string[],length是原串可用长度，这里的方法是原串上修改
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
	//位置索引
	int firstPos = originalLength;
	int secondPos = newLenght;
	while( firstPos>=0 && firstPos!=secondPos ){	//必须是大于等于0，等于0针对了空格在开头的情况!
		if( str[firstPos] == ' ' ){
			str[secondPos--] = '0';
			str[secondPos--] = '2';
			str[secondPos--] = '%';
		}else{
			str[secondPos--] = str[firstPos];	//连同\0一起复制移动
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

// 空格在句子中间
void Test1(){
	const int length = 100;

	char string[length] = "hello world";
	Test("Test1", string, length, "hello%20world");
}

// 空格在句子开头
void Test2(){
	const int length = 100;

	char string[length] = " helloworld";
	Test("Test2", string, length, "%20helloworld");
}

// 空格在句子末尾
void Test3(){
	const int length = 100;

	char string[length] = "helloworld ";
	Test("Test3", string, length, "helloworld%20");
}

// 连续有两个空格
void Test4(){
	const int length = 100;

	char string[length] = "hello  world";
	Test("Test4", string, length, "hello%20%20world");
}

// 传入NULL
void Test5(){
	Test("Test5", NULL, 0, NULL);
}

// 传入内容为空的字符串
void Test6(){
	const int length = 100;

	char string[length] = "";
	Test("Test6", string, length, "");
}

//传入内容为一个空格的字符串
void Test7(){
	const int length = 100;

	char string[length] = " ";
	Test("Test7", string, length, "%20");
}

// 传入的字符串没有空格
void Test8(){
	const int length = 100;

	char string[length] = "helloworld";
	Test("Test8", string, length, "helloworld");
}

// 传入的字符串全是空格
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

	system("pause");	//在#include<cstdlib>中，或者using namespace std;
	return 0;
}