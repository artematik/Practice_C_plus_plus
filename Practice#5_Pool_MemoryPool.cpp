#include <algorithm>
#include <chrono>
#include <functional>
#include <iostream>
#include <memory>
#include <random>
#include <thread>
#include <vector>
using namespace std;
template<typename El>
class MemoryPool
{
	vector<El*> p;
	size_t size, ind;
public:
	MemoryPool() :size(0), ind(0) {}
	MemoryPool(size_t power) :size(power), ind(0)
	{
		p.resize(size, nullptr);
		for (auto** elem : p)
		{
			elem = reinterpret_cast<El*>(operator new)(sizeof(El));
		}
	}
	~MemoryPool()
	{
		for (auto** elem : p)
		{
			operator delete(elem);
		}
	}
	void resize(size_t newsize)
	{
		if (size >= newsize)
			return;
		for (size_t i = size; i < newsize;++i)
			p.push_back(reinterpret_cast<El*>(operator new(sizeof(El))));
		size = newsize;
	}
	template<class ...Arguments>
	El* get(Arguments&&... args)
	{
		if (size <= ind)
			return false;
		El* aspect = new(p[ind++])El(forward<Arguments>(args)...);
		return aspect;
	}
	bool place(El* elem)
	{
		if (ind == 0)
			return false;
		elem->~El();
		--ind;
		p[ind] = elem;
		return true;
	}
	template<class... Arguments>
	unique_ptr<El, function<void(El*)>> unique(Arguments&&... args)
	{
		return unique_ptr<El, function<void(El*)>>(get(forward<Arguments>(args)...), [this](El* pointer) {this->place(pointer);});
	}
	template<class ...Arguments>
	shared_ptr<El> shared(Arguments&&... args)
	{
		return shared_ptr<El>(get(forward<Arguments>(args)...), [this](El* pointer) {this->place(pointer);});
	}
};

template<typename Rec>
class PoolMix {
public:
	static void* operator new(size_t n)
	{
		return p.get();
	}
	static void operator delete(void* ptr, size_t size)
	{
		p.place(static_cast<Rec*>(ptr));
	}
	static void* operator new(size_t n, void* ptr)
	{
		return::operator new(n, n);
	}
	static void operator delete(void* ptr, void* p)
	{
		return::default_delete(ptr, p);

	}
protected:
	static MemoryPool<Rec> p;
};

template<typename Rec>
MemoryPool<Rec> PoolMix<Rec>::p(100);
