#ifndef __ARRAY_H__
#define __ARRAY_H__

#include "array/IArray.h"
#include "array/Array/SubArray.h"
#include "array/ArrayStrategy/ArrayOperator/AdditionOperator.h"
#include "array/Index.h"
#include "array/Range.h"
#include "array/Subscript.h"

namespace blackbox 
{
	template <typename T>
	class Array : public virtual IArray<T>, public virtual AdditionOperator<T> 
	{
		Array() = delete;

	public:
		Array(Subscript order);

		virtual ~Array() = default;
		
		// accessor methods
		using IArray<T>::at;
		auto at(Index index) -> T&;

		// const accessor methods
		auto at(Index index) const -> T const&;

		Array<T>& operator =(std::initializer_list<T> values);

		virtual std::auto_ptr<IArray<T>> create(Subscript order) const;

	protected:
		virtual std::auto_ptr<IArray<T>> getSubArray_(IArray<T>& array, Range range);
		virtual std::auto_ptr<IArray<T>> getSubArray_(IArray<T> const& array, Range range) const;

		std::vector<T> data_;

	};

	template <typename T>
	Array<T>::Array(Subscript order) : IArray<T>(order), data_(order.toIndex())
	{
		for (int i = 0; i < order.toIndex(); i++) {
			data_.at(i) = T();
		}
	}

	template <typename T>
	Array<T>& Array<T>::operator =(std::initializer_list<T> values)
	{
		ASSERT("", values.size() == order_.toIndex());
		int i = 0;
		for (T value : values) {
			data_.at(i) = value;
			i++;
		}
		return *this;
	}

	template <typename T>
	auto Array<T>::at(Index index) -> T&
	{
		//TODO implement new EventMessage for subscript/index out of bounds
		ASSERT("", index <= order_.toIndex());
		return data_.at(index - 1);
	}

	template <typename T>
	auto Array<T>::at(Index index) const -> T const&
	{
		//TODO implement new EventMessage for subscript/index out of bounds
		ASSERT("", index <= order_.toIndex());
		return data_.at(index - 1);
	}

	template <typename T>
	std::auto_ptr<IArray<T>> Array<T>::create(Subscript order) const
	{
		return std::auto_ptr<IArray<T>>(new Array<T>(order));
	}

	template <typename T>
	std::auto_ptr<IArray<T>> Array<T>::getSubArray_(IArray<T>& array, Range range)
	{
		return std::auto_ptr<IArray<T>>(new SubArray<T>(array, range));
	}

	template <typename T>
	std::auto_ptr<IArray<T>> Array<T>::getSubArray_(IArray<T> const& array, Range range) const
	{
		return std::auto_ptr<IArray<T>>(new SubArray<T>(array, range));
	}

} // blackbox

#include "Array.cpp"

#endif

