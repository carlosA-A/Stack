#include "Stack.h"

#include <iostream>

#include <fstream>

#include <cstdlib>

using namespace std;

Stack::Stack(){
		string stack[10000];
		top = -1;

	
	}
void Stack::printStack(string *array,int sizeArray) {
	
	for (int element = 0; element < sizeArray; element++) {
		
		cout<<array[element]<<" ";
	}
	cout<<endl;
		
	
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
		
		
		return "fail";
		
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
	//arrays to store and compare values, every array has a item counter to track the number of items in the array.
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
	int trackOperators = 0;
	
	string delimiter[20];
	int trackDelimeter = 0;
	
	string syntaxError[20];
	int trackSyntaxErrors = 0; 
	
	string poppedString;
		
	int sizeStack =  top+1;
	

	for (int element = 0; element < sizeStack; element++) {
		

		poppedString = pop();
		//Check if there is a keyword
		if (((((int)poppedString.at(0)>=65 )&& ((int)poppedString.at(0)<=90))) ){

			//Checks if items have already been added to the list with all words
			//loops through all the used words
			//If no elements exist in used list, check if they are the ywords we have, if not they are syntax errors
			if (trackUsedWords == 0 && (poppedString == Upperkeywoards[0] || poppedString == Upperkeywoards[1]|| 
					poppedString == Upperkeywoards[2])){

				usedWords[trackUsedWords] = poppedString;
				trackUsedWords++;
				keywords[trackKeywords] = poppedString;
				trackKeywords++;
				
				}
				//If no words have been aded to list of used words and it isn't a key word, it is a syntax error
			else if (trackUsedWords == 0 && (poppedString != Upperkeywoards[0] || poppedString != Upperkeywoards[1]|| 
					poppedString != Upperkeywoards[2])){

					syntaxError[trackSyntaxErrors] = poppedString;
					trackSyntaxErrors++;
				
				}
			else{
				//Boolean values to let loop continue or stop  
				bool continueLoop = true;
				bool isRepeat = false;
				for (int element = 0; element <= trackUsedWords && continueLoop==true; element++) {

					//If the word is a keyword check if it has been used
					if((poppedString == Upperkeywoards[0] || poppedString == Upperkeywoards[1]|| 
					poppedString == Upperkeywoards[2])){

						//If word has already bee added dismiss it
						if(poppedString == usedWords[element] ){
							isRepeat = true;

						
							}
						//If keyword is not in used words, then add it to keyword array and to used words 
						//while increasing the reference size of the usedWords array
						else if (poppedString != usedWords[element] && element == trackUsedWords && isRepeat == false){

							usedWords[trackUsedWords] = poppedString;
							trackUsedWords++;
							keywords[trackKeywords] = poppedString;
							trackKeywords++;
							continueLoop = false;
							
							}
			
			
						}
					//Word is not a keyword and must be a syntax error
					else{

						syntaxError[trackSyntaxErrors] = poppedString;
						trackSyntaxErrors++;
						break;
					
						}	
				
					}
				}
		}
			//check if word is lowercase
			else if ((int)poppedString.at(0)>=97 && (int)poppedString.at(0)<=122){
				
				
				//Check if there is an empty list of identifiers
				if (trackIdentifier == 0){

					usedWords[trackUsedWords] = poppedString;
					trackUsedWords++;
					identifier[trackIdentifier] = poppedString;
					trackIdentifier++;
					
					}
				
				
				else{
					bool continueLoop = true;
					bool isRepeat = false;

					for (int element = 0; element <= trackUsedWords && continueLoop==true; element++) {
				
					//If word has already bee added dismiss it
						if(poppedString == usedWords[element] ){
							isRepeat = true;

							}
						//If keyword is not in used words, then add it to keyword array and to used words 
						//while increasing the reference size of the usedWords array
						else if (poppedString != usedWords[element] && element == trackUsedWords && isRepeat == false){

							usedWords[trackUsedWords] = poppedString;
							trackUsedWords++;
							identifier[trackIdentifier] = poppedString;
							trackIdentifier++;
							continueLoop = false;
							
							}
					
						
						
					}
				}
				
				
		}
				//check if there is a number in the stack
		else if ((int)poppedString.at(0)>=48 && (int)poppedString.at(0)<=57){
			int numberFormStack = atoi(poppedString.c_str());
				
				//Check if there is an empty list of identifiers
				if (trackIdentifier == 0){

					usedWords[trackUsedWords] = poppedString;
					trackUsedWords++;
					identifier[trackIdentifier] = poppedString;
					trackIdentifier++;
					
					}
				
				
				else{
					bool continueLoop = true;
					bool isRepeat = false;

					for (int element = 0; element <= trackUsedWords && continueLoop==true; element++) {
				

					//If word has already bee added dismiss it
						if(numberFormStack == atoi(usedWords[element].c_str()) ){
							isRepeat = true;
						
							}
						//If keyword is not in used words, then add it to keyword array and to used words 
						//while increasing the reference size of the usedWords array
						else if ((numberFormStack != atoi(usedWords[element].c_str())) && (element == trackUsedWords) && (isRepeat == false)){

							usedWords[trackUsedWords] = poppedString;
							trackUsedWords++;
							constant[trackConstant] = poppedString;
							trackConstant++;
							continueLoop = false;
							
							}
					
						
					}
					
				}
			
			
			}
		//Checks for the operator in the stack
		else if (poppedString == characthers[0] || poppedString == characthers[1]|| 
					poppedString == characthers[2] || poppedString == characthers[3] || poppedString == characthers[4]||poppedString == characthers[5]){
						
				
				//Check if there is an empty list of identifiers
				if (trackIdentifier == 0){

					usedWords[trackUsedWords] = poppedString;
					trackUsedWords++;
					operatros[trackOperators] = poppedString;
					trackOperators++;
					
					}
				
				
				else{
					bool continueLoop = true;
					bool isRepeat = false;

					for (int element = 0; element <= trackUsedWords && continueLoop==true; element++) {
				

					//If word has already bee added dismiss it
						if(poppedString == usedWords[element] ){
							isRepeat = true;

						
							}
						//If keyword is not in used words, then add it to keyword array and to used words 
						//while increasing the reference size of the usedWords array
						else if (poppedString != usedWords[element] && element == trackUsedWords && isRepeat == false){

							usedWords[trackUsedWords] = poppedString;
							trackUsedWords++;
							operatros[trackOperators] = poppedString;
							trackOperators++;
							continueLoop = false;
							
							}
					
					}
					
				}
			
			
			}
			//Checks for the delimeters in the stack
		else if (poppedString == characthers[6] || poppedString == characthers[7]){
						
				//Check if there is an empty list of identifiers
				if (trackIdentifier == 0){

					usedWords[trackUsedWords] = poppedString;
					trackUsedWords++;
					delimiter[trackDelimeter] = poppedString;
					trackDelimeter++;					
					}
				
				
				else{
					bool continueLoop = true;
					bool isRepeat = false;

					for (int element = 0; element <= trackUsedWords && continueLoop==true; element++) {
				

					//If word has already bee added dismiss it
						if(poppedString == usedWords[element] ){
							isRepeat = true;

						
							}
						//If keyword is not in used words, then add it to keyword array and to used words 
						//while increasing the reference size of the usedWords array
						else if (poppedString != usedWords[element] && element == trackUsedWords && isRepeat == false){

							usedWords[trackUsedWords] = poppedString;
							trackUsedWords++;
							delimiter[trackDelimeter] = poppedString;
							trackDelimeter++;
							
							continueLoop = false;
							
							}
					
						
					}
					
				}
			
			
			}

	}
	//Prints out all the keywords, constants,etc
		cout<<"Keywords: ";
		printStack(keywords,trackKeywords);
		
		cout<<"Identifiers: ";
		printStack(identifier,trackIdentifier);
		
		cout<<"Constants: ";
		printStack(constant,trackConstant);
			
		cout<<"Delimeters: ";
		printStack(delimiter,trackDelimeter);

		cout<<"Operators: ";		
		printStack(operatros,trackOperators);


		cout<<"Syntax Errors: ";		
		printStack(syntaxError,trackSyntaxErrors);

 
	
	}
//Prints out depth of for loop
void Stack::forLoopDepth (){
	int numberOfLoops = 0;
	int tempLoops = 0;
	int numberEnds = 0;
	int tempReplace = 0;
	bool whichSpot = true;
	
	for (int element = 0; element < top; element++) {

		//if the number of nested loops we found at the start is bigger than the number of nested loops found later, then reser temp loops to 0
		if (numberOfLoops > tempLoops && tempLoops == numberEnds ){
			cout<< "Works 1"<<endl;

			
			tempLoops = 0;
			if(whichSpot == false){
				cout<< "Works 999"<<endl;

				tempReplace = 0;
				numberEnds = 0;
				}
		}
		else if (numberOfLoops < tempLoops) {
cout<< "Works 2"<<endl;

			numberOfLoops = 0;
		}
		if(tempReplace!=0 && numberOfLoops==numberEnds){
cout<< "Works 3"<<endl;

			tempReplace = tempLoops;
			whichSpot = false;
			numberEnds = 0;

			
			}
			
			//When the number of temp loops is equal to the number of ends, 
			//then start using numberLoops again
		
		else if((tempReplace!=0) &&(tempLoops == numberEnds)) {
cout<< "Works 4"<<endl;

			tempReplace = numberOfLoops;
			whichSpot = true;
			numberEnds = 0;

			
			}
		
		if(stack[element]=="FOR"){
			
cout<< "Works 5"<<endl;

			tempReplace++;
			
			}
		else if(stack[element]== "END"){
cout<< "Works 6"<<endl;

			numberEnds++;
			}
			
			//At the end check whether the replaced variable belonged to tempSpot1 or 2
				if(whichSpot == false){
cout<< "Works 7"<<endl;

					tempLoops=tempReplace;
				}
				else{
cout<< "Works 8"<<endl;

					numberOfLoops=tempReplace;
				}
		
		
	}
	
	if (numberOfLoops > tempLoops){
		
		cout<<"OUTPUT> The maximum depth of nested loop(s) is "<<numberOfLoops <<endl;		
		}
	
	else{
		
		cout<<"OUTPUT> The maximum depth of nested loop(s) is "<<tempLoops <<endl;

		
		}
	
	}
