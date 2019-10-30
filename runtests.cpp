#include <iostream>

// change the value below to 1 to run tests against your StringList class.
// change the value below to 0 to run tests against the built in std::list.

#include <string>

#if 1
#include "List.h"
typedef List<std::string> StringList;
typedef List<int> IntList;
#include "Stack.h"
typedef Stack<std::string> StringStack;
typedef Stack<int> IntStack;
#else
#include <list>
typedef std::list<std::string> StringList;
typedef std::list<int> IntList;
#include <stack>
typedef std::stack<std::string> StringStack;
typedef std::stack<int> IntStack;
#endif

void Assert(bool cond, std::string message)
{
	if (cond)
		std::cout << "Pass: " << message << std::endl;
	else
		std::cerr << "FAIL: " << message << std::endl;
}

int main()
{

	StringList a;
	StringList b;

	a.push_front("A");
	Assert(a.front() == "A", "front == A");
	a.push_front("B");
	Assert(a.front() == "B", "front == B");
	a.pop_front();
	Assert(a.front() == "A", "front == A");
	a.push_front("Z");
	Assert(a.front() == "Z", "front == Z");

	b = a;
	Assert(b == a, "Test operator == between a and b");
	Assert(b.front() == "Z", "b.front == Z");
	b.pop_front();
	Assert(b.front() == "A", "b.front == A");
	b.pop_front();
	Assert(b.empty() == true, "b is empty");
	Assert(a.empty() == false, "a is NOT empty");
	Assert(b != a, "Test operator != between a and b");

	StringList test;
	test.push_back("D");
	test.push_back("I");
	test.push_back("N");
	Assert(test.front() == "D", "test.front == D");
	test.push_back("H");
	test.push_front("G");
	test.push_front("N");
	test.push_front("O");
	test.push_front("C");
	Assert(test.front() == "C", "test.front == C");
	Assert(test.back() == "H", "test.back == H");
	Assert(test.size() == 8, "test.size == 8");
	test.pop_front();
	test.pop_back();
	Assert(test.front() == "O", "test.front = O after pop front");
	Assert(test.back() == "N", "test.back = N after pop back");
	test.reverse();
	Assert(test.front() == "N", "test.front = N after reverse");
	Assert(test.back() == "O", "test.back = O after reverse");
	test.push_back("G");
	test.push_back("G");
	test.print();
	Assert(test.back() == "G", "test.back = G before unique");
	test.unique();
	test.print();
	Assert(test.back() == "G", "test.back = O after unique");

	// TODO: check all methods on StringList...

	StringStack c;
	c.push("A");
	c.push("B");
	Assert(c.top() == "B", "B is at top");
	c.pop();
	Assert(c.empty() == false, "c is not empty");
	c.pop();
	Assert(c.empty() == true, "c is empty");
	Assert(c.size() == 0, "Check size = 0 when empty");
	c.push("A");
	c.push("B");
	Assert(c.size() == 2, "size == 2");

	StringStack test2;
	test2.push("N");
	test2.push("C");
	test2.push("D");
	Assert(test2.top() == "D", "Test test2.top = D");
	test2.push("D");
	test2.push("T");
	Assert(test2.top() == "T", "Test test2.top = T");
	c = test2;
	Assert(c.size() == 5, "Test size c = 5 after c = test2");
	Assert(c.top() == "T", "Test c.top = T after c = test2");
	Assert(c == test2, "Test make sure c == test2 ");
	c.pop();
	Assert(c.top() == "D", "Test c.top = D after c.pop");
	Assert(c != test2, "Test c!= d after c.pop");

	// TODO: check all methods on StringStack...

	IntList ia;
	ia.push_front(5);
	ia.push_front(6);
	Assert(ia.front() == 6, "front is 6");

	IntList test3;
	IntList test4;
	test3.push_back(0);
	test3.push_back(9);
	Assert(test3.back() == 9, "Test test3.back after push back");
	test3.push_front(2);
	test3.push_front(1);
	Assert(test3.front() == 1, "Test test3.front after push front");
	Assert(test3.size() == 4, "Test size = 4");

	test4 = test3;
	Assert(test4 == test3, "Test operator ==");
	Assert(test4.front() == 1, "Test test4 = test3");
	Assert(test4.back() == 9, "Test test4 = test3");
	test4.push_back(1);
	test4.push_back(9);
	test4.push_back(9);
	test4.push_back(8);
	Assert(test4 != test3, "Test operator !=");
	test4.reverse();
	Assert(test4.front() == 8, "Check test4.front = 8 after reverse");
	Assert(test4.size() == 8, "Size of test4 = 8 before unique");
	test4.unique();
	Assert(test4.size() == 7, "Size of test4 = 7 after unique");
	test4.pop_front();
	test4.pop_back();
	Assert(test4.front() == 9, "Check test4.front = 9 after pop front");
	Assert(test4.back() == 2, "Check test4.back = 9 after pop back");
	test4.clear();
	Assert(test3.empty() == false, "Test empty method on test 3");
	Assert(test4.empty() == true, "Test clear method is working");
	// TODO: check all methods on IntList...

	IntStack ic;
	ic.push(6);
	ic.push(5);
	Assert(ic.top() == 5, "top is 5");

	IntStack test5;
	IntStack test6;
	IntStack test7 {1,2,3,4,5,6};
	Assert(test5.empty() == true, "Test empty");
	test5.push(0);
	test5.push(7);
	Assert(test5.size() == 2, "Test size test5");
	Assert(test5.top() == 7, "Check test5.top = 7");
	test5.pop();
	Assert(test5.top() == 0, "Check test5.top = 0 after using pop");

	Assert(test5 != test6, "Test operator !=");
	test5.pop();
	test5.push(6);
	test5.push(5);

	test6 = ic;
	Assert(test6.size() == 2, "Check size after using test6 = ic");
	Assert(test6.top() == 5, "Check test6.top = 5 after using test6 = ic");
	Assert(test6 == test5, "Test operator == after push 5,6 into test5");

	Assert(test7.top() == 6, "Check stack initializer_list working");
	Assert(test7.size() == 6, "Check stack initializer_list working");
	test7.pop();
	Assert(test7.top() == 5, "Check test7.top");
	Assert(test7.empty() == false, "Test 7 is not empty");

	// TODO: check all methods on IntStack...

	return 0;
}
