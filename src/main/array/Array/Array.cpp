#ifdef __ARRAY_H__

namespace blackbox 
{
	
	template <typename T>
	Array<T>::Array(Subscript order): 
		IArray<T>(order), 
		data_(order.toIndex()) 
	{
		for (int i = 0; i < order.toIndex(); i++) {
			data_.at(i) = T();
		}
	}
	
	template <typename T>
	Array<T>::~Array() 
	{
		//noop
	}

	template <typename T>
	Array<T>& Array<T>::operator =(std::initializer_list<T> values) 
	{
		int i = 0;
		for (T value : values) {
			data_.at(i) = value;
			i++;
		}
		return *this;
	}
	
	template <typename T>
	auto Array<T>::at(Index index) 
		-> T& 
	{
		return data_.at(index - 1);
	}
	
	template <typename T>
	auto Array<T>::at(Index index) const 
		-> T const& 
	{
		return data_.at(index - 1);
	}

	template <typename T>
	std::auto_ptr<IArray<T>> Array<T>::create(Subscript order) const 
	{
		return std::auto_ptr<IArray<T>>(new Array<T>(order));
	}

	template <typename T>
	std::auto_ptr<IArray<T>> Array<T>::createSubArray(IArray<T>& array, Range range)
	{
		return std::auto_ptr<IArray<T>>(new SubArray<T>(array, range));
	}

}

#endif