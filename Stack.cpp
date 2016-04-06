#include "Stack.h"

#include <iostream>

#include <fstream>

#include <cstring>

using namespace std;

Stack::Stack(){
		string stack[10000];
		top = -1;

	
	}
void Stack::printStack() {
	
	for (int element = 0; element < top+1; element++) {
		cout<<stack[element]<<" "<<endl;
		
		}
	
	}
//Add an item to the empty spot in the stack
void Stack::push(string word){
	
	top++;
	
	stack[top] = word;
	
	}
//Remove item at last spot in the stack
void Stack::pop(){
	
	stack[top] = "";
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
//Read a file and create an array with all the words
void Stack::readFile(string fileName)	{
	
	ifstream myfile;
	
	myfile.open(fileName.c_str());	
	
	
	string line;

	//if ( inputFile.is_open() ) {
		// The file could not be opened
		
		//}
	
//	else {
		// Safely use the file stream
	//	while ( !inputFile.eof() )	{
		
		//cout << line << '\n';
			
			//}
   
  }
		
  
		//}
	
	
	

int Stack::getTop (){
	return top;	
	
	}
