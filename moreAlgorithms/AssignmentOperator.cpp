#include <iostream>
#include <string>
#ifndef _CMYSTRING_H
#define _CMYSTRING_H

using namespace std;

class CMyString{
public:
	CMyString(char* pData = NULL);	//默认值写在函数声明处，定义时可不再写
	CMyString(const CMyString& str);	//拷贝构造，所以用const和引用；注意，如定义成传值形式，会无限循环，编译出错
	~CMyString();
	CMyString& operator=(const CMyString &str);	//添加自定义类型的赋值运算符函数
	void Print();
private:
	char* m_pdata;
};

CMyString::CMyString(char* pData){
	//不要直接指针赋值，那就两个指针指向同一内存空间，可能错
	if ( pData==NULL ){
		m_pdata = new char[1];
		m_pdata[0] = '\0';
	}else{
		int length = strlen(pData);
		m_pdata = new char[length+1];
		strcpy(m_pdata,pData);
	}
}

CMyString::CMyString(const CMyString& str){
	int length = strlen(str.m_pdata);
	m_pdata = new char[length+1];
	strcpy(m_pdata,str.m_pdata);

}

CMyString:: ~CMyString(){
	delete []m_pdata;
}

CMyString& CMyString::operator=(const CMyString& str){
	//初级写法
	if ( this==&str ){
		return *this;
	}
	delete []m_pdata;	//为什么要用[]
	m_pdata = NULL;
	m_pdata = new char[strlen(str.m_pdata)+1];
	strcpy(m_pdata, str.m_pdata);
	return *this;
	//上述写法存在不安全性，若内存new char时分配失败，则m_pdata也已经释放，是空指针，这很容易导致程序崩溃
	//即一旦抛出异常，CMyString实例不再保持有效状态，这违背了异常安全性
	//两种方法改变.1.先new再释放，确保分配失败时原来的实例不会被更改；2.先创建临时变量，再交换
	//高级写法
	if ( this != &str ){	//this是个指针，所以要对str取址
		CMyString strTmp(str);
		char* pTmp = strTmp.m_pdata;
		strTmp.m_pdata = m_pdata;
		m_pdata = pTmp;
	}
	//程序跳出if时，会自动调用strTmp的析构函数，而strTmp指向的就是原this的内存空间，即自动调用了析构函数释放原实例的内存空间
	return *this;
}

void CMyString::Print()
{
	//printf("%s", m_pdata);
	cout<<m_pdata;	//格式控制语句不要写在这里，写在测试函数或主函数内
}

//测试代码
void test1(){
	cout<<"test1 begins."<<endl;
	char* text = "Hello world";
	CMyString str1(text);
	CMyString str2;
	str2 = str1;
	//printf("The expected result is: %s.\n", text);
	cout<<"The expected result is:"<<text;
	cout<<"The actual result is: ";
	str1.Print();
	str2.Print();
	cout<<endl;
}
//自身赋值
void test2(){
	cout<<"test2 begins."<<endl;
	char* text = "Hello world";
	CMyString str1(text);
	str1 = str1;
	//printf("The expected result is: %s.\n", text);
	cout<<"The expected result is:"<<text;
	cout<<"The actual result is: ";
	str1.Print();
	cout<<endl;

}
//连续赋值
void test3(){
	cout<<"test2 begins."<<endl;
	char* text = "Hello world";
	CMyString str1(text);
	CMyString str2, str3;
	str3 = str2 = str1;
	//printf("The expected result is: %s.\n", text);
	cout<<"The expected result is:"<<text;
	cout<<"The actual result is: ";
	str2.Print();
	str3.Print();
	cout<<endl;

}

int main(){
	test1();
	test2();
	test3();
	system("pause");
}

#endif