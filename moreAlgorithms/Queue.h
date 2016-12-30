#pragma once
#include <stack>
#include <exception>

using namespace std;

//两个栈实现一个队列
template <typename T> class CQueue
{
public:
	CQueue(void){}
	~CQueue(void){}

	// 在队列末尾添加一个结点
	void appendTail(const T& node);

	// 删除队列的头结点
	T deleteHead();

private:
	stack<T> stack1;
	stack<T> stack2;
};

template<typename T> void CQueue<T>::appendTail(const T& element)
{
	stack1.push(element);
} 

template<typename T> T CQueue<T>::deleteHead()
{
	if(stack2.size()<= 0){
		while( stack1.size()>0 ){
			T& tmpData = stack1.top();
			stack1.pop();
			stack2.push(tmpData);
		}
	}
	if ( stack2.size()<= 0 ){
		throw exception("empty queue");
	}
	T head = stack2.top();
	stack2.pop();

	return head;
}
