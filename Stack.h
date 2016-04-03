

#ifndef STACK_H_
#define STACK_H_

#include <string>

using namespace std;

class Stack{

	private:

	int top;

	public:

		Stack();

		string stack[10000];
	
		void push(int array[]);
	
		void pop();
	
		void parseString(string sentence) ;
		
		int getTop ();
	
};

#endif /* STACK_H_ */
