#include <iostream>
#include "Queue.h"

using std::cout;
using std::endl;

void Test(char actual, char expected)
{
	if(actual == expected)
		printf("Test passed.\n");
	else
		printf("Test failed.\n");
}

int main()
{
	CQueue<char> queue;

	queue.appendTail('a');
	queue.appendTail('b');
	queue.appendTail('c');

	char head = queue.deleteHead();
	Test(head, 'a');

	head = queue.deleteHead();
	Test(head, 'b');

	queue.appendTail('d');
	head = queue.deleteHead();
	Test(head, 'c');

	queue.appendTail('e');
	head = queue.deleteHead();
	Test(head, 'd');

	head = queue.deleteHead();
	Test(head, 'e');
	try
	{
		head = queue.deleteHead();
	}
	catch (exception& exc)
	{	head = -1;
		cout<<"Invalid delete."<<endl;
	}
	Test(head, 'e');
	system("pause");
	return 0;
}