

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
	
		string pop();
	
		void parseString(string sentence) ;
		
		int getTop ();
		
		void printStack(); 
		
		void keywoard();
		
		string readFile(string fileName);
		
		string formatSentence(string line);
};

#endif /* STACK_H_ */
