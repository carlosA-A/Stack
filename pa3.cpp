#include <iostream>
#include <string>
#include "Stack.cpp"

using namespace std;




int main(int argc, char ** argv) {
//Checks number of arguments passed in terminal
	if (argc > 2){

	//Stop program if an invalid command is entered
		cout<<"Cannot run program"<<endl;
	}else{
		
	//create a new stack		
		
	Stack *stack = new Stack();
	//Read file with file name specified
	string sentence = stack -> readFile(std::string(argv[1]));
	//If we are able to run the file, execute our code
	if (sentence != "fail"){
		
		//parse the text found
		stack -> parseString (sentence);
		//determine depth of for loop
		stack -> forLoopDepth ();
		//pop stack and determine the keywords, constants, syntax errors,etc
		stack -> keywoard();
		}
		//If file could not be opened, give user an error message
		else{
			cout<<"File does not exist, please try a different name"<<endl;

			
			}
	
	

		}
			
	
}
