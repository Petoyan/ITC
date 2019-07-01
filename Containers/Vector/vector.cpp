#include <iostream>
#include <cassert>

template<typename T>
class DynVector
{
private:
	int* data;
	unsigned int size;
	unsigned int capacity;
public:
	DynVector():size(0),capacity(16)
	{
		data = new T[capacity];
	}
//	DynVector(unsigned int s):size(0),capacity(s)
//	{
//		data = new T[capacity];
//	}
	DynVector(const DynVector<T>& vec)
	{
		size = vec.size;
		capacity = vec.capacity;
		data = new T[capacity];
		copyElements(vec.data, data, size);
	}
	DynVector<T>& operator=(const DynVector<T>& vec)
	{
		T* temp = new T[capacity];
		copyElements(vec.data, temp, size);
		delete [] data;
		data = temp;
		return *this;

	}
	void copyElements(const T* from, const T* to, unsigned int size)
	{
		for(int i = 0; i < size; ++i)
		{
			to[i] = from[i];
		}
	}
	void push_back(T val)
	{
		if(capacity == size)
		{
			reallocateMemory();
		}
		data[size] = val;
		++size;
	}
	void insert(unsigned int index,T val)
	{
		if(capacity == size)
		{
			reallocateMemory();
		}
		for(int i = size; i >=index; --i)
		{
			data[i+1] = data [i];
		}
		data[index] = val;
		++size;
	}
	void removeByIndex(unsigned int index)
	{
		for(int i = index; i < size; ++i)
		{
			data[i] = data[i+1];
		}
		--size;
	}
	void reallocateMemory()
	{
		capacity *=2;
		T* const temp = new T[size];
		for(int i = 0; i < size; ++i)
		{
			temp[i] = data[i];
		}
		delete [] data;
		data = temp;
	}
	T& getElement(unsigned int index)
	{
		return data[index];
	}
	unsigned int& getSize()
	{
		return size;
	}
	unsigned int& getCapacity()
	{
		return capacity;
	}
	T& operator[ ](unsigned int index)
	{
		if(index < (size - 1))
		return data[index];
	}
};

int main()
{
	DynVector<int>* vec = new DynVector<int>();
	std::cout << "Capasity of vector = " << vec->getCapacity() << "\n";
	for(int i = 0; i < 20; ++i)
	{
		vec->push_back(i);
	}
	DynVector<int>* vec1 = new DynVector<int>();
	vec1 = vec;
	vec1->removeByIndex(2);
	vec1->insert(5,123);
	DynVector<int>* vec2 = vec1;
	for(int i = 0; i < vec1->getSize() ; ++i)
	{
		std::cout << vec2->getElement(i)  << "\n";
	}
	std::cout << " Size of vector = "<< vec1->getSize() << "\n";
	std::cout << "Capacity of vector = " << vec1->getCapacity() << "\n";

}
