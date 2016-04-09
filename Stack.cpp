#include "Stack.h"

#include <iostream>

#include <fstream>

#include <cstdlib>

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
string Stack::pop(){
	//String being popped to pass into another function.
	string stringToPass;
	stringToPass = stack[top];
	stack[top] = "";
	//stack moves spot when being popped
	top--;
	return stringToPass;
	}
void Stack::parseString(string sentence){
	int startWord = 0;
	
		//Creates a vector of strings
		string addToStack[10000];
		
		//Parses string based on spaces and characters
		for (unsigned int spaceFinder = 0, counter = 0 ,length = 0; spaceFinder < sentence.length();spaceFinder++,length++){
			if (sentence[spaceFinder] == ' ' ||sentence[spaceFinder] == ',' || sentence[spaceFinder] == ';' || 
			sentence[spaceFinder] == '(' || sentence[spaceFinder] == ')' || sentence[spaceFinder] == '='||
			sentence[spaceFinder] == '*' || sentence[spaceFinder] == '/' || sentence[spaceFinder] == '-'||
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
	//arrays to store and compare values
	string Upperkeywoards[]={"BEGIN","FOR","END"};
	string characthers [] = {"+","-","*","/","++","=",",",";"};
	string usedWords[100];
	int trackUsedWords = 0;
	string keywords [3];
	int trackKeywords = 0;

	string identifier[20];
	
	int trackIdentifier = 0;
	
	string constant [20];
	int trackConstant = 0;
	
	string operatros[20];
	
	string delimiter[20];
	
	string syntaxError[20];
	int trackSyntaxErrors = 0; 
	
	string poppedString;
		
	int sizeStack =  top+1;
	
	cout<<"Works 1"<<endl;

	for (int element = 0; element < sizeStack; element++) {
		
		cout<<"Works 2"<<endl;

		poppedString = pop();
		//Check if there is a keyword
		if (((((int)poppedString.at(0)>=65 )&& ((int)poppedString.at(0)<=90))) ){
		cout<<"Works 3"<<endl;

			//Checks if items have already been added to the list with all words
			//loops through all the used words
			//If no elements exist in used list, check if they are the ywords we have, if not they are syntax errors
			if (trackUsedWords == 0 && (poppedString == Upperkeywoards[0] || poppedString == Upperkeywoards[1]|| 
					poppedString == Upperkeywoards[2])){
						cout<<"Works 4"<<endl;

				usedWords[trackUsedWords] = poppedString;
				trackUsedWords++;
				keywords[trackKeywords] = poppedString;
				trackKeywords++;
				cout<<poppedString<<endl;
				
				}
				//If no words have been aded to list of used words and it isn't a key word, it is a syntax error
			else if (trackUsedWords == 0 && (poppedString != Upperkeywoards[0] || poppedString != Upperkeywoards[1]|| 
					poppedString != Upperkeywoards[2])){
							cout<<"Works 5"<<endl;

					syntaxError[trackSyntaxErrors] = poppedString;
					trackSyntaxErrors++;
				
				}
			else{
				//Boolean values to let loop continue or stop  
				bool continueLoop = true;
				bool isRepeat = false;
				for (int element = 0; element <= trackUsedWords && continueLoop==true; element++) {
					cout<<"Works 6"<<endl;

					//If the word is a keyword check if it has been used
					if((poppedString == Upperkeywoards[0] || poppedString == Upperkeywoards[1]|| 
					poppedString == Upperkeywoards[2])){
						cout<<"Works 7"<<endl;

						//If word has already bee added dismiss it
						if(poppedString == usedWords[element] ){
							isRepeat = true;
							cout<<"Works 8"<<endl;

						
							}
						//If keyword is not in used words, then add it to keyword array and to used words 
						//while increasing the reference size of the usedWords array
						else if (poppedString != usedWords[element] && element == trackUsedWords && isRepeat == false){
									cout<<"Works 9"<<endl;

							usedWords[trackUsedWords] = poppedString;
							trackUsedWords++;
							keywords[trackKeywords] = poppedString;
							trackKeywords++;
							cout<<poppedString<<endl;
							continueLoop = false;
							
							}
			
			
						}
					//Word is not a keyword and must be a syntax error
					else{
								cout<<"Works 10"<<endl;

						syntaxError[trackSyntaxErrors] = poppedString;
						trackSyntaxErrors++;
						break;
					
						}	
				
					}
				}
			
			
				
				
			
		
		}
			//check if word is lowercase
			else if ((int)poppedString.at(0)>=97 && (int)poppedString.at(0)<=122){
				
				cout<<"Works 11"<<endl;
				
				//Check if there is an empty list of identifiers
				if (trackIdentifier == 0){
									cout<<"Works 12"<<endl;

					usedWords[trackUsedWords] = poppedString;
					trackUsedWords++;
					identifier[trackIdentifier] = poppedString;
					trackIdentifier++;
					cout<<poppedString<<endl;
					
					}
				
				
				else{
					bool continueLoop = true;
					bool isRepeat = false;

					for (int element = 0; element <= trackUsedWords && continueLoop==true; element++) {
				
									cout<<"Works 13"<<endl;

					//If word has already bee added dismiss it
						if(poppedString == usedWords[element] ){
							isRepeat = true;
							cout<<"Works 14"<<endl;

						
							}
						//If keyword is not in used words, then add it to keyword array and to used words 
						//while increasing the reference size of the usedWords array
						else if (poppedString != usedWords[element] && element == trackUsedWords && isRepeat == false){
									cout<<"Works 15"<<endl;

							usedWords[trackUsedWords] = poppedString;
							trackUsedWords++;
							identifier[trackIdentifier] = poppedString;
							trackIdentifier++;
							cout<<poppedString<<endl;
							continueLoop = false;
							
							}
					
						
						
					}
				}
				
				
		}
				//check if there is a number in the stack
		else if ((int)poppedString.at(0)>=48 && (int)poppedString.at(0)<=57){
			int numberFormStack = atoi(poppedString.c_str());
			cout<<"Works 16"<<endl;
				
				//Check if there is an empty list of identifiers
				if (trackIdentifier == 0){
									cout<<"Works 17"<<endl;

					usedWords[trackUsedWords] = poppedString;
					trackUsedWords++;
					identifier[trackIdentifier] = poppedString;
					trackIdentifier++;
					cout<<poppedString<<endl;
					
					}
				
				
				else{
					bool continueLoop = true;
					bool isRepeat = false;

					for (int element = 0; element <= trackUsedWords && continueLoop==true; element++) {
				
									cout<<"Works 18"<<endl;

					//If word has already bee added dismiss it
						if(numberFormStack == atoi(usedWords[element].c_str()) ){
							isRepeat = true;
							cout<<"Works 19"<<endl;

						
							}
						//If keyword is not in used words, then add it to keyword array and to used words 
						//while increasing the reference size of the usedWords array
						else if ((numberFormStack != atoi(usedWords[element].c_str())) && (element == trackUsedWords) && (isRepeat == false)){
									cout<<"Works 20"<<endl;

							usedWords[trackUsedWords] = poppedString;
							trackUsedWords++;
							constant[trackConstant] = poppedString;
							trackConstant++;
							cout<<poppedString<<endl;
							continueLoop = false;
							
							}
					
						
					}
					
				}
			
			
			}

	}
 
	
	}
	
int Stack::getTop (){
	return top;	
	
	}
