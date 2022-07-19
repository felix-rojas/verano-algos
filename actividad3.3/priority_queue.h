#ifndef __PRIORITY_QUEUE_H_
#define __PRIORITY_QUEUE_H_

#include <iostream>
#include <vector>

template <class T>
class priority_queue
{
private:
	std::vector<T> data;
    int maxCapacity;
    int numElements;
	int parent(T i);
	int left(T i);
	int right(T i);

public:
	priority_queue(int capacity);
	~priority_queue();
	bool Empty();
	int getCapacity();
	int getNumElements();
	void heapify(T index);
	void pop();
	void printHeap();
	void push(T num);
	T top();
};

template <class T>
priority_queue<T>::priority_queue(int capacity)
{
	std::cout << "--->Creando un Heap: " << this << std::endl;
	numElements = 0;
	maxCapacity = capacity;
	data.resize(maxCapacity);
}

template <class T>
priority_queue<T>::~priority_queue()
{
	std::cout << "--->Liberando memoria del Heap: " << this << std::endl;
	data.clear();
}

template <class T>
bool priority_queue<T>::Empty()
{
	return (numElements <= 0);
}

template <class T>
int priority_queue<T>::getCapacity()
{
    return maxCapacity;
}

template <class T>
int priority_queue<T>::getNumElements()
{
    return numElements;
}
template <class T>
void priority_queue<T>::printHeap()
{
	for (int i = 0; i < numElements; i++)
		std::cout << data[i] << " ";
	std::cout << std::endl;
}

template <class T>
int priority_queue<T>::parent(T i)
{
	return (i - 1) / 2;
}

template <class T>
int priority_queue<T>::left(T i)
{
	return (2 * i + 1);
}

template <class T>
int priority_queue<T>::right(T i)
{
	return (2 * i + 2);
}

template <class T>
void priority_queue<T>::push(T num)
{
	if (numElements == maxCapacity)
	{
		std::cout << "No se puede agregar el num: " << num << std::endl;
		return;
	}
	int i = numElements;
	data[i] = num;
	numElements++;
	while (i != 0 && data[parent(i)] < data[i])
	{
		std::swap(data[i], data[parent(i)]);
		i = parent(i);
	}
}

template <class T>
void priority_queue<T>::heapify(T index)
{
	int l = left(index);
	int r = right(index);
	int largest = index;
	if (l < getCapacity() && data[l] > data[index])
	{
		largest = l;
	}
	if (r < getCapacity() && data[r] > data[largest])
	{
		largest = r;
	}
	if (largest != index)
	{
		std::swap(data[index], data[largest]);
		heapify(largest);
	}
}

//  Saca de la fila priorizada el dato con mayor prioridad
template <class T>
void priority_queue<T>::pop()
{
	/* Usando la librería de algoritmos
	make_heap(data.begin(), data.end());
	pop_heap(data.begin(), data.end());
	int largest = data.back();
	data.pop_back();
	for (auto i : data)
		std::cout << i << ' ';
		*/
	if (Empty()){
		throw std::out_of_range("Heap vacio");
	}
	if (getCapacity() == 1){
		maxCapacity--;
		data.resize(maxCapacity);
	}
	std::swap(data[0], data[numElements-1]);
	numElements--;
	maxCapacity--;
	data.resize(maxCapacity);
	heapify(0);
}

template <class T>
T priority_queue<T>::top()
{
	if (Empty())
	{
		throw std::out_of_range("El heap está vacio");
	}
	return data[0];
}

#endif // __PRIORITY_QUEUE_H_
