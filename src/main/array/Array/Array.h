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
	class Array: 
		public virtual IArray<T>, 
		public virtual AdditionOperator<T> 
	{

	public:

		// Array concrete declarations
		Array() = delete;

		Array(Subscript order);

		Array<T>& operator =(std::initializer_list<T> values);

		// Array virtual declarations
		virtual ~Array();

		// IArray concrete override declarations
		using IArray<T>::at;

		auto at(Index index) 
			-> T&;

		auto at(Index index) const 
			-> T const&;

		// IArray virtual override declarations
		virtual std::auto_ptr<IArray<T>> create(Subscript order) const;

		virtual std::auto_ptr<IArray<T>> createSubArray(IArray<T>& array, Range range);

	protected:

		std::vector<T> data_;

	};

}

#include "Array.cpp"

#endif
