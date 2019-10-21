#ifndef __EE231_List_h__
#define __EE231_List_h__

#include <cstddef>

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
		_head = 0;
		_tail = 0;
		_size = 0;
	}

	// copy constructor
	List(const List& other)
	{
		_head = 0;
		_size = 0;
		reccopy(other.getHead());
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
		reccopy(other.getHead());
		_size = other.size();
		return *this;
	}

	T::llist * getHead() const
	{
	  return _head;
	}
	T::llist * getTail() const
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
		return _head == 0;
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
		newItem->prev = 0;
		if (_head != 0)
			_head->prev = newItem;
		if (_tail == 0)
			_tail = newItem;
		_head = newItem;
		_size++;
	}
	void push_back(const T& val)
	{
		llist *newItem = new llist;
		newItem->val = val;
		newItem->prev = _tail;
		newItem->next = 0;
		if (_tail != 0)
			_tail->next = newItem;
		if (_head == 0)
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
			if (_head != 0)
				_head->prev = _head->prev->prev;
			else
				_tail = 0;
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
			if (_tail != 0)
				_tail->next = _tail->next->next;
			else
				_head = 0;
			delete back;
			_size--;
		}
	}

	void reverse()
	{
	  if ((!empty()) && (_head->next != 0))
	  {
	    llist *temp;
	    llist *ptr = _head;

	    while (ptr != 0)
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
	  for(llist *ptr = _head; ptr != 0; ptr = ptr->next)
	    {
	    	while ((ptr->next != 0) && (ptr->str == ptr->next->str))
	    	{
	        llist *saveptr = ptr->next;
	        ptr->next = saveptr->next;

	        if (saveptr->next != 0)
	          saveptr->next->prev = ptr;
	        else
	          _tail = ptr;

	        delete saveptr;
	        _size--;
	      }
	    }
	}


};

#endif // __EE231_List_h__
