#include<iostream>
using namespace std;
template<typename T>
class Suitcase
{
private:
	T* arr;
	int capacity;
	int count;
	void resize();
	void Free();
	void CopyFrom(const Suitcase& other);
public:
	Suitcase();
	Suitcase(const Suitcase& other);
	Suitcase& operator=(const Suitcase& other);
	Suitcase& operator+(const Suitcase& other);
	~Suitcase();

	void Add(T element);
	void Get();
	void print();
};

template<typename T>
Suitcase<T>::Suitcase()
{  
	arr = new T[4];
	this->count = 1;
	this->capacity = 8;
}
template<typename T>
void Suitcase<T> ::Free()
{
	delete[] arr;
	count = capacity = 0;
}
template<typename T>
void  Suitcase<T>::CopyFrom(const Suitcase& other)
{
	arr = new T[other.capacity];
	for (size_t i = 0; i < count; i++)
	{
		this->arr[i] = other.arr[i];
	}
	this->capacity = other.capacity;
	this->count = other.count;
}
template<typename T>
Suitcase<T>::Suitcase(const Suitcase& other)
{
	CopyFrom(other);
}
template<typename T>
Suitcase<T>& Suitcase<T>::operator=(const Suitcase& other)
{
	if (this != &other)
	{
		Free();
		CopyFrom(other);
	}
	return *this;
}
template <typename T>
Suitcase<T>::~Suitcase()
{
	Free();
}
template<typename T>
void Suitcase<T>::resize()
{
	T* temp = new T[(capacity * 2)+1];
	for (size_t i = 0; i < capacity; i++)
	{
		temp[i] = arr[i];
	}
	capacity *= 2;
	delete[] arr;
	arr = temp;
}

template <typename T>
void Suitcase<T>::Add(T element)
{
	if (count == capacity)
	{
		resize();
	}
	if (count != 1)
	{
		for (int i = count - 1; i >=0; i--)
		{
			arr[i+1 ] = arr[i];
		}
	}
	arr[0] = element;
	count++;
}

template<typename T>
void Suitcase<T>::print()
{
	for (size_t i = 0; i < count - 1; i++)
	{
		cout << arr[i] << "  ";

	}cout << endl;
}

template<typename T>
void Suitcase<T>::Get()
{
	cout << arr[0]<<endl;
	for (int i= 0; i < count-2; i++)
	{
		arr[i] = arr[i +1 ];
	}
}

template <typename T>
Suitcase<T>& Suitcase<T>::operator+(const Suitcase& other)
{
	Suitcase<T> result;
	result.capacity = this->capacity + other.capacity;
	for (size_t i=0 ; i < this->count - 1; i++)
	{
		result.arr[i] = this->arr[i];
		
	}
	for (size_t i = this->count; i < this->count+other.count-1; i++)
	{
		result.arr[i] = other.arr[i - this->count];
	}
	result.count = this->count + other.count - 1;
	return result;
}