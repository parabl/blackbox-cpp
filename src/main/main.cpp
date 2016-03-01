// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include <vector>
#include <memory>

//index.h
class index {
public:
	operator int();
private:
	int i_;
};

//index.cpp
//#include index.h
index::operator int() {
	return i_;
}

/*
//subscript.h
class Order;
class Subscript : public std::vector <int> {
public:
	Subscript(std::vector<int> s);
	//operator order();
	index toIndex(Order o);
};

//order.h
class Order : public Subscript {
public:
	Order(std::vector<int> o);
	//operator subscript();
	index toIndex();
};

//order.cpp
//#include order.h
Order::Order(std::vector<int> o) : Subscript(o) {}
//order::operator subscript() {
//	return subscript(*this);
//}
index Order::toIndex() {
	return Subscript::toIndex(*this);
}

//subscript.cpp
//#include subscript.h
Subscript::Subscript(std::vector<int> s) : std::vector<int>(s) {}
//subscript::operator order() {
//	return order(*this);
//}
index Subscript::toIndex(Order o) {
	return index();
}
*/
/*

	Copy

*/

#include <typeinfo>
#include <iostream>

class Base {
public:
	virtual void copyTo(Base& replica) {
		std::cout << typeid(replica).raw_name() << '|' << typeid(*this).raw_name() << std::endl;
		if (typeid(replica) == typeid(*this)) {
			duplicateTo(replica);
		}
		else {
			translateTo(replica);
		}
	}
	virtual void duplicateTo(Base& replica) {
		// default
		translateTo(replica);
	}
	virtual void translateTo(Base& replica) {
		// translate this to base using interface
	}
	int i_ = 0;
};

class A : public Base {
public:
	virtual void duplicateTo(Base& replica) {
		replica = A(*this);
	}
};

class B : public Base {
public:
	virtual void duplicateTo(Base& replica) {
		replica = B(*this);
	}
};

void test3() {
	Base* a1 = new A();
	a1->i_ = 1;
	Base* a2 = new A();
	a2->i_ = 2;
	Base* b1 = new B();
	Base* b2 = new B();
	a1->copyTo(*b1);
	a2->copyTo(*a1);
}

/*

template <typename Type>
class AbstractContainer {
public:
	AbstractContainer() = delete;
	virtual ~AbstractContainer();
	virtual std::unique_ptr<AbstractContainer<Type>> create(Order order) = 0;
	virtual std::unique_ptr<AbstractContainer<Type>> clone() = 0;

	virtual std::unique_ptr<AbstractContainer<Type>> getRange() = 0;
};

template <typename Type>
AbstractContainer<Type>::AbstractContainer() {}

template <typename Type>
AbstractContainer<Type>::~AbstractContainer() {}





template <typename Type>
class SimpleContainer : public AbstractContainer<Type> {
public:
	SimpleContainer(Order order);
	~SimpleContainer();

	SimpleContainer& SimpleContainer(const AbstractContainer& container);
protected:
	std::vector<std::shared_ptr<Type>> data_;
	Order order_;
};

template <typename Type>
SimpleContainer<Type>::SimpleContainer(Order order) : order_(order) {
	data_.assign(order.toIndex());
}

template <typename Type>
std::unique_ptr<AbstractContainer<Type>> SimpleContainer<Type>::create(Order order) {
	return std::unique_ptr < new SimpleContainer<Type>(order) > ;
}





template <typename Type, typename Container = SimpleContainer<Type>>
class Array {
public:
	Array(Order order);
	~Array();
private:
	std::unique_ptr<Container> container_;
};



*/

/*

	Templates

*/

template <typename T = Base>
class X {};

template <typename T>
void example(X<T> x) {

}

void test4() {
	X<Base> x;
	example(x);

}

/*
void test1(Subscript s) {
	Order o({ 1, 2, 3 });
	s.toIndex(o);
}

void test2(Order o) {
	o.toIndex();
}
*/
#define LOG_VERBOSITY 2

//#include "array/SimpleContainer.h"
//#include "array/AbstractContainer.h"
#include "array/ArrayContainer.h"
#include "log/LogStream.h"
#include "log/Log.h"

void test5() {
	using namespace blackbox;
	ERROR("Error occurred here");
	int three = 3;
	ArrayContainer::Simple<int> a({ three, 3 });
	a = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	ArrayContainer::Abstract<int>* b = new ArrayContainer::Simple<int>({ 1, 3 });
	Subscript s({ 1, 3 });
	Index I = s.toIndex();
	std::shared_ptr<int> i = a.at(4);
	std::shared_ptr<int> j = a.at(s);
	Range r(s);
	std::auto_ptr<ArrayContainer::Abstract<int>> test = a.at(r);
}

void fake(int& i) {

}

int main()
{
	test5();
	//test3();
	/*
	Subscript s({ 1, 2, 3 });
	Order o({ 1, 2, 3 });
	test2(s);
	test2(o);
	*/
	return 0;
}

/*


class AbstractOperatorStrategy {}

class SimpleOperatorStrategy : public AbstractOperatorStrategy {}

class Simple


*/