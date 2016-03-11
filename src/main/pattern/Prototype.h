#ifndef __PROTOTYPE_H__
#define __PROTOTYPE_H__

#include <memory>

namespace blackbox {

	template <class Class>
	class Prototype {
	public:
		Prototype() = default;
		~Prototype() = default;

		virtual std::auto_ptr<Class> create() = 0;
		virtual std::auto_ptr<Class> clone() = 0;
	};

}

#endif
