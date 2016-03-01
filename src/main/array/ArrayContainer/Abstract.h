#ifndef __ABSTRACTARRAYCONTAINER_H__
#define __ABSTRACTARRAYCONTAINER_H__

#include <memory>

#include "modifier/Cloneable.h"
#include "array/Index.h"
#include "array/Range.h"
#include "array/Subscript.h"

namespace blackbox {
	template <typename T>
	class ArrayContainer::Abstract : public modifier::Cloneable<Abstract<T>> {
	public:
		Abstract() = delete;
		Abstract(Subscript order);
		~Abstract();

		auto at(Subscript subscript) -> std::shared_ptr<T>&;
		auto at(Subscript floor, Subscript ceiling) -> std::auto_ptr<Abstract<T>>;
			
		// pure virtual
		virtual std::auto_ptr<Abstract<T>> create(Subscript order) = 0;
		virtual auto at(Index index) -> std::shared_ptr<T>& = 0;

		// virtual
		virtual void duplicateTo(Abstract<T>& replica, Range range);
		virtual void translateTo(Abstract<T>& replica, Range range);
		virtual auto at(Range range) -> std::auto_ptr<Abstract<T>>;
		virtual Integer getSize();
		virtual Subscript getOrder();

		// Cloneable override declarations
		void duplicateTo(Abstract<T>& replica);
		void translateTo(Abstract<T>& replica);

	protected:
		Subscript order_;
	};
}

#include "Abstract.cpp"

#endif