

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
	
		void push(string word);
	
		void pop();
	
		void parseString(string sentence) ;
		
		int getTop ();
		
		void printStack(); 
		
		void readFile(string fileName);
};

#endif /* STACK_H_ */
