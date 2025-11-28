#ifndef __STACK_H__
#define __STACK_H__
#include <iostream>
using namespace std;

template<typename T>
class stack
{
protected:
	int sz;
	int len;
	T* mem;
public:
	stack() :sz(0), len(10), mem(new T[10]) {}
	~stack() {
		sz = 0;
		len = 0;
		delete[] mem;
	}
	bool is_empty()const noexcept { return sz == 0; }
	size_t size() const noexcept { return sz; }
	void clear() noexcept { sz = 0; }

	void push(const T& t) {
		if (sz == len) {
			len = len * 1.5 + 10;
			T* t = mem;
			mem = new T[len];
			std::copy(t, t + sz, mem);
			delete[] t;
		}
		mem[sz++] = t;
	}
	T& get()
	{
		if (is_empty())throw runtime_error("empty stack");
		return mem[sz - 1];
	}
	T& pop()
	{
		if (is_empty())throw runtime_error("empty stack");
		return mem[sz-- - 1];
	}
};
#endif