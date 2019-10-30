#include <cstddef>
#include <initializer_list>
#include "List.h"

template<typename T>
class Stack
{
  protected:
     List<T> c;
  public:

    Stack()
    {
    }

    Stack(std::initializer_list<T> l): c(l)
    {
    }

    T& top()
    {
      return c.back();
    }
    const T& top() const
    {
      return c.back();
    }
    void push(const T& val)
    {
      c.push_back(val);
    }
    void pop()
    {
      c.pop_back();
    }
    size_t size() const
    {
      return c.size();
    }
    bool empty() const
    {
      return c.empty();
    }
    Stack<T>& operator=(const Stack<T>& other)
    {
      c = other.c;
      return *this;
    }
    template<typename TT>
    friend bool operator==(const Stack<TT>&, const Stack<TT>&);
    template<typename TT>
    friend bool operator!=(const Stack<TT>&, const Stack<TT>&);
};

template<typename T>
bool operator==(const Stack<T>& a, const Stack<T>& b)
{
  return a.c == b.c;
}
template<typename T>
bool operator!=(const Stack<T>& a, const Stack<T>& b)
{
  return a.c != b.c;
}
