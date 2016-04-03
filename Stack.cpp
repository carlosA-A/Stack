#include "Stack.h"

#include <iostream>

using namespace std;

Stack::Stack(){
		string stack[10000];
		top = -1;

	
	}

void Stack::push(int array[]){
	top++;
	
	}
void Stack::pop(){
	
	top--;
	
	}
void Stack::parseString(string sentence){
	int startWord = 0;
		//Creates a vector of strings
		string addToStack[10000];
		
		for (int spaceFinder = 0, counter = 0 ,length = 0; spaceFinder < sentence.length();spaceFinder++,length++){
		if (sentence[spaceFinder] == ' '){
			addToStack[counter] = sentence.substr(startWord,length);
			//starts tracking lenght again
			length = 0;
			//tracks spot in vector
			counter++;
			//sets new starting position for word
			startWord = spaceFinder + 1;
	
		//If sentence is about to end, then create the las substring
		} else if(spaceFinder + 1 == sentence.length()){
			//length of word is calculated by substracting from the total characters the ammount that have been already traversed
			int lengthWord = spaceFinder-startWord+1;
			addToStack[counter] = sentence.substr(startWord,lengthWord);
			
			}
				
	}
	cout<<addToStack[0]<<endl;


	
	}
int Stack::getTop (){
	return top;	
	
	}
