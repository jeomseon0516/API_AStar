#pragma once
#include "Include.h"

template<typename T>
class PriorityQueue
{
private:
	vector<T> _heap;
public:

	public void Push(T value, bool(*cmp)(T, T));
	public void Push(T value, bool(T::*cmp)(T)); // 클래스의 멤버 함수로 정렬 시켜야할때

	public T Pop();

public:
	 PriorityQueue();
	~PriorityQueue();
};

template<typename T>
inline void PriorityQueue<T>::Push(T value, bool(*cmp)(T, T)) // 컴페어 함수를 통해 정렬한다.
{
}

// .. 클래스 멤버 컴페어 함수를 통해 정렬한다. 그러므로 항상 해당 자료구조를 사용할 클래스는 컴페어 함수를 정의 해야한다.
template<typename T>
inline void PriorityQueue<T>::Push(T value, bool(T::*cmp)(T))
{

}

// .. 최소 힙으로 정렬 된 값으로 
template<typename T>
inline T PriorityQueue<T>::Pop()
{
	return T();
}

template<typename T>
inline PriorityQueue<T>::PriorityQueue() {}

template<typename T>
inline PriorityQueue<T>::~PriorityQueue() {}
