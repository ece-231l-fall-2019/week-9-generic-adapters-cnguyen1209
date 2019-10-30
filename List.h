#ifndef __EE231_List_h__
#define __EE231_List_h__

#include <cstddef>
#include <iostream>
#include <initializer_list>

template<typename T>
class List
{
	private:

	typedef struct llist {
		T val;
		struct llist *next;
		struct llist *prev;
	} llist;

	llist *_head;
	llist *_tail;
	size_t _size;

	// private recursive copy so elements
	// end up in the same order.
	void reccopy(const llist *ptr)
	{
		if (ptr)
		{
			reccopy(ptr->next);
			push_front(ptr->val); //push front or back?
		}
	}

	public:

	// default constructor
	List()
	{
		_head = nullptr;
		_tail = nullptr;
		_size = 0;
	}

	// copy constructor
	List(const List& other)
	{
		_head = nullptr;
		_size = 0;
		//llist *ptr = other.getHead();
		//for (; ptr != nullptr; ptr = ptr->next)
		//	push_back(ptr->value);
		reccopy(other.getHead());
	}

	List(std::initializer_list<T> l) : _head(nullptr), _tail(nullptr), _size(0)
	{
		for(auto value: l)
			push_back(value);
	}

	// destructor
	~List()
	{
		clear();
	}

	// copy operator
	List& operator=(const List& other)
	{
		clear();
		_head = nullptr;
		_size = 0;
		reccopy(other.getHead());
		return *this;
	}

	 List::llist * getHead() const
	{
	  return _head;
	}
	 List::llist * getTail() const
	{
	  return _tail;
	}
	void clear()
	{
		while(!empty())
			pop_front();
	}
	bool empty() const
	{
		return (_head == nullptr) && (_tail == nullptr);
	}
	size_t size() const
	{
		return _size;
	}

	T& front()
	{
		return _head->val;
	}
	const T& front() const
	{
		return _head->val;
	}
	T& back()
	{
	  return _tail->val;
	}
	const T& back() const
	{
		return _tail->val;
	}

	void push_front(const T& val)
	{
		llist *newItem = new llist;
		newItem->val = val;
		newItem->next = _head;
		newItem->prev = nullptr;
		if (_head != nullptr)
			_head->prev = newItem;
		if (_tail == nullptr)
			_tail = newItem;
		_head = newItem;
		_size++;
	}
	void push_back(const T& val)
	{
		llist *newItem = new llist;
		newItem->val = val;
		newItem->prev = _tail;
		newItem->next = nullptr;
		if (_tail != nullptr)
			_tail->next = newItem;
		if (_head == nullptr)
			_head = newItem;
		_tail = newItem;
		_size++;
}

	void pop_front()
	{
		if (!empty())
		{
			llist *front = _head;
			_head = _head->next;
			if (_head != nullptr)
				_head->prev = _head->prev->prev;
			else
				_tail = nullptr;
			delete front;
			_size--;
		}
	}
	void pop_back()
	{
		if (!empty())
		{
			llist *back = _tail;
			_tail = _tail->prev;
			if (_tail != nullptr)
				_tail->next = _tail->next->next;
			else
				_head = nullptr;
			delete back;
			_size--;
		}
	}

	void reverse()
	{
	  if ((!empty()) && (_head->next != nullptr))
	  {
	    llist *temp;
	    llist *ptr = _head;

	    while (ptr != nullptr)
	    {
	      temp = ptr->prev;
	      ptr->prev = ptr->next;
	      ptr->next = temp;
	      ptr = ptr->prev;
	    }

	    temp = temp->prev;
	    _tail = _head;
	    _head = temp;
	  }
	}
	void unique()
	{
	  for(llist *ptr = _head; ptr != nullptr; ptr = ptr->next)
	    {
	    	while ((ptr->next != nullptr) && (ptr->val == ptr->next->val))
	    	{
	        llist *saveptr = ptr->next;
	        ptr->next = saveptr->next;

	        if (saveptr->next != nullptr)
	          saveptr->next->prev = ptr;
	        else
	          _tail = ptr;

	        delete saveptr;
	        _size--;
	      }
	    }
	}

	void print() const
	{
	  for (llist *ptr = _head; ptr != NULL; ptr = ptr->next)
	      std::cout << ptr->val << " ";
	  std::cout << std::endl;
	}

	template<typename V>
	friend bool operator==(const List<V>&, const List<V>&);
	template<typename V>
	friend bool operator!=(const List<V>&, const List<V>&);
};

template<typename T>
bool operator==(const List<T>& a, const List<T>& b)
{
	if(a.size() != b.size())
		return false;

	auto aptr = a.getHead();
	auto bptr = b.getHead();

	for(; aptr != nullptr && bptr != nullptr; aptr = aptr->next, bptr = bptr->next)
	{
		if(aptr->val != bptr->val)
			return false;
	}
	return true;
}

template<typename T>
bool operator!=(const List<T>& a, const List<T>& b)
{
	if(a.size() != b.size())
		return true;

	auto aptr = a.getHead(); // const typename List<T>::llist *aptr = a.getHead();
	auto bptr = b.getHead();

	for(; aptr != nullptr && bptr != nullptr; aptr = aptr->next, bptr = bptr->next)
	{
		if(aptr->val != bptr->val)
			return true;
	}
	return false;
}

#endif // __EE231_List_h__
