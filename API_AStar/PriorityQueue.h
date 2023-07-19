#pragma once
#include "Include.h"

template<typename T>
class PriorityQueue
{
private:
	vector<T*> _heap;
public:

	public void Push(T value, void (*cmp)(T, T));
	public T Pop();

public:
	PriorityQueue();
	~PriorityQueue();
};

template<typename T>
inline void PriorityQueue<T>::Push(T value, void(*cmp)(T, T))
{
}

template<typename T>
inline T PriorityQueue<T>::Pop()
{
	return T();
}

template<typename T>
inline PriorityQueue<T>::PriorityQueue() {}

template<typename T>
inline PriorityQueue<T>::~PriorityQueue() {}
