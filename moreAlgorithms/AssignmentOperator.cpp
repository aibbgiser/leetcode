#include <iostream>
#include <string>
#ifndef _CMYSTRING_H
#define _CMYSTRING_H

using namespace std;

class CMyString{
public:
	CMyString(char* pData = NULL);	//Ĭ��ֵд�ں���������������ʱ�ɲ���д
	CMyString(const CMyString& str);	//�������죬������const�����ã�ע�⣬�綨��ɴ�ֵ��ʽ��������ѭ�����������
	~CMyString();
	CMyString& operator=(const CMyString &str);	//����Զ������͵ĸ�ֵ���������
	void Print();
private:
	char* m_pdata;
};

CMyString::CMyString(char* pData){
	//��Ҫֱ��ָ�븳ֵ���Ǿ�����ָ��ָ��ͬһ�ڴ�ռ䣬���ܴ�
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
	//����д��
	if ( this==&str ){
		return *this;
	}
	delete []m_pdata;	//ΪʲôҪ��[]
	m_pdata = NULL;
	m_pdata = new char[strlen(str.m_pdata)+1];
	strcpy(m_pdata, str.m_pdata);
	return *this;
	//����д�����ڲ���ȫ�ԣ����ڴ�new charʱ����ʧ�ܣ���m_pdataҲ�Ѿ��ͷţ��ǿ�ָ�룬������׵��³������
	//��һ���׳��쳣��CMyStringʵ�����ٱ�����Ч״̬����Υ�����쳣��ȫ��
	//���ַ����ı�.1.��new���ͷţ�ȷ������ʧ��ʱԭ����ʵ�����ᱻ���ģ�2.�ȴ�����ʱ�������ٽ���
	//�߼�д��
	if ( this != &str ){	//this�Ǹ�ָ�룬����Ҫ��strȡַ
		CMyString strTmp(str);
		char* pTmp = strTmp.m_pdata;
		strTmp.m_pdata = m_pdata;
		m_pdata = pTmp;
	}
	//��������ifʱ�����Զ�����strTmp��������������strTmpָ��ľ���ԭthis���ڴ�ռ䣬���Զ����������������ͷ�ԭʵ�����ڴ�ռ�
	return *this;
}

void CMyString::Print()
{
	//printf("%s", m_pdata);
	cout<<m_pdata;	//��ʽ������䲻Ҫд�����д�ڲ��Ժ�������������
}

//���Դ���
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
//����ֵ
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
//������ֵ
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