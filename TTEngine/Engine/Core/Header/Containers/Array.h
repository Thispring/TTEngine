#pragma once

#include "../CorePCH.h"

#define CAPACITY_SIZE 4

namespace tte
{
	template <typename T>
	class TArray
	{
	public:
		TArray();
		~TArray();

		void Add(T item);
		void* At(int32 Index);
		void Remove(int32 Index);
		void RemoveBack();

	private:
		T* mPtr;
		int32 mCapacity;
		int32 mSize;
	};
}

template<typename T>
inline tte::TArray<T>::TArray()
	: mPtr(nullptr), mCapacity(0), mSize(0)
{
}

template<typename T>
inline tte::TArray<T>::~TArray()
{
	if (mPtr != nullptr)
	{
		delete[] mPtr;
	}
}

template<typename T>
inline void tte::TArray<T>::Add(T item)
{
	if (mCapacity == 0)
	{
		mCapacity = sizeof(T);
		mPtr = new T[mCapacity];
		*(mPtr + mSize) = item;
		++mSize;
	}
	else if (mCapacity == mSize)
	{
		mCapacity += sizeof(T) * CAPACITY_SIZE;
		T* temp = new T[mCapacity];

		for (int32 i = 0; i < mSize; ++i)
		{
			temp[i] = mPtr[i];
		}

		delete[] mPtr;
		mPtr = nullptr;
		mPtr = temp;

		*(mPtr + mSize) = item;
		++mSize;
	}
	else if (mCapacity > mSize)
	{
		*(mPtr + mSize) = item;
		++mSize;
	}
}

template<typename T>
inline void* tte::TArray<T>::At(int32 Index)
{
	if (mPtr == nullptr || mPtr[Index] == nullptr)
		return nullptr;

	return (T*)mPtr[Index];
}

template<typename T>
inline void tte::TArray<T>::Remove(int32 Index)
{
}

template<typename T>
inline void tte::TArray<T>::RemoveBack()
{
	if (mPtr == nullptr) 
		return;

	mPtr[mSize] = nullptr;
	--mSize;
}
