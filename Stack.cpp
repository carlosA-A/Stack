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
	int sizeSentence;
		//Creates a vector of strings
		string addToStack[10000];
		
		for (unsigned int spaceFinder = 0, counter = 0 ,length = 0; spaceFinder < sentence.length();spaceFinder++,length++){
		if (sentence[spaceFinder] == ' ' ||sentence[spaceFinder] == ',' || sentence[spaceFinder] == ';' || 
		sentence[spaceFinder] == '(' || sentence[spaceFinder] == ')' || sentence[spaceFinder] == '='||
		(sentence[spaceFinder] == '+' && sentence[spaceFinder+1] == ' ') ){
			
			if (sentence[spaceFinder] == ' '){
			//remove white space and create a substring
			
			addToStack[counter] = sentence.substr(startWord,length);
			if(!sentence.substr(startWord,length).empty()){
				push(sentence.substr(startWord,length));
			}
		}
		else{
			//add the text that is before the character "FOR"(
			addToStack[counter] = sentence.substr(startWord,length);
			if(!sentence.substr(startWord,length).empty()){
			push(sentence.substr(startWord,length));
			
			}
			counter++;
			//remove the character itself FOR"("
			
			addToStack[counter] = sentence.substr(startWord+length,1);
				if(!sentence.substr(startWord+length,1).empty()){
					push(sentence.substr(startWord+length,1));
				}
			}
			//starts tracking lenght again
			length = -1;
			//tracks spot in array
			counter++;
			//sets new starting position for word
			startWord = spaceFinder + 1;
	
		//If sentence is about to end, then create the las substring
		} else if(spaceFinder + 1 == sentence.length()){
			//length of word is calculated by substracting from the total characters the ammount that have been already traversed
			int lengthWord = spaceFinder-startWord+1;
			addToStack[counter] = sentence.substr(startWord,lengthWord);
			push(sentence.substr(startWord,lengthWord));
			}
			sizeSentence = counter;	
	}
	//Substract 1 because counter starts at 0
	
	for(int num = 0; num < sizeSentence - 1; num++){
	cout<<addToStack[num]<<endl;
	
	}
	
}
//Read a file and create an array with all the words
string Stack::readFile(string fileName)	{
	//Bool to track if an empty space was found
	
	
	ifstream myfile;
	
	myfile.open(fileName.c_str());	
		
	string sentence;
	//First spot where a space appears
		
	if ( !myfile.is_open() ) {
		//The file could not be opened
		
		cout<<"Could not open file"<<endl;
		
		}
	
	else {
		// Safely use the file stream
				
		string line;
		

		while ( !myfile.eof() )	{			
		
			getline(myfile,line); // Saves the line in line.
			
			line = formatSentence(line);
			//Create a single string with all the lines everything separeated by 1 space
	       sentence.append(line);
	       sentence.append(" ");
	        
	       // cout<<line<<endl; // Prints our line.
	        	        			
		}
			
	cout<<sentence<<endl;
	
	
	}
	return sentence;
		
  
}
	
string Stack::formatSentence(string line){
	
	int length = 0;
	
	int counter = 0;
	
	int firstSpace;

	bool isSpace = false;

	for (std::string::size_type spaceFinder = 0; spaceFinder < line.length();spaceFinder++,counter++){
			
			length =  0;
			//While there are spaces in the string transverse them to later remove them
			while ((line[spaceFinder] == ' ')  && ( spaceFinder < line.size())){
				if (isSpace == false) {
					firstSpace = spaceFinder;
				}
				spaceFinder++;
				
				length ++;
				
				isSpace = true;
				
				}
				//If a space was found then remove it
				if (isSpace == true) {
					line.erase(firstSpace,length);
					
					isSpace = false;
					}
				
			}
		return line;
	}	
	
void Stack::keywoard() {
	string keywoards[]={"BEGIN","FOR","END","+","-","*","/","++","=",",",";"};
 
	
	}
	
int Stack::getTop (){
	return top;	
	
	}
