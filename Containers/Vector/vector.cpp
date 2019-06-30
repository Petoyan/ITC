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
	DynVector():size(16),capacity(0)
	{
		data = new T[size];
	}
	DynVector(unsigned int s):size(s),capacity(0)
	{
		data = new T[size];
	}
	DynVector(const DynVector<T>& vec):size(vec.size),capacity(vec.capacity)
	{
		data = new T[size];
		copyElements(vec.data, data, capacity);
	}
	DynVector<T>& operator=(const DynVector<T>& vec)
	{
		T* temp = new T[vec.size];
		copyElements(vec.data, temp, capacity);
		delete [] data;
		data = temp;
		return *this;

	}
	void copyElements(const T* from, const T* to, unsigned int capacity)
	{
		for(int i = 0; i < capacity; ++i)
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
		data[capacity] = val;
		++capacity;
	}
	void insert(unsigned int index,T val)
	{
		if(capacity == size)
		{
			reallocateMemory();
		}
		for(int i = capacity; i >=index; --i)
		{
			data[i+1] = data [i];
		}
		data[index] = val;
		++capacity;
	}
	void removeByIndex(unsigned int index)
	{
		for(int i = index; i < capacity; ++i)
		{
			data[i] = data[i+1];
		}
		--capacity;
	}
	void reallocateMemory()
	{
		size *=2;
		T* const temp = new T[size];
		for(int i = 0; i < capacity; ++i)
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
	std::cout << "Size of vector = " << vec->getSize() << "\n";
	for(int i = 0; i < 20; ++i)
	{
		vec->push_back(i);
	}
	DynVector<int>* vec1 = new DynVector<int>();
	vec1 = vec;
	vec1->removeByIndex(2);
	vec1->insert(5,123);
	for(int i = 0; i < vec1->getCapacity() ; ++i)
	{
		std::cout << vec1->getElement(i)  << "\n";
	}
	std::cout << " Size of vector = "<< vec1->getSize() << "\n";
	std::cout << "Capacity of vector = " << vec1->getCapacity() << "\n";

}
