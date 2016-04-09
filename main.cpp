#include <iostream>
#include <string>
#include "Stack.cpp"

using namespace std;




int main(){
	
	Stack *stack = new Stack();
	
	string sentence = stack -> readFile("test.txt");
	
	stack -> parseString (sentence);
	//stack -> keywoard();
	stack ->printStack();
}
