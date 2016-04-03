#include <iostream>
#include <string>
#include "Stack.cpp"

using namespace std;




int main(){
	
	Stack *stack = new Stack();
	stack -> push("hello");
	stack -> push("hello");
	stack -> push("hello");
	stack -> push("hello");

	stack-> printStack();
	stack->pop();
	stack-> printStack();

		
	}
