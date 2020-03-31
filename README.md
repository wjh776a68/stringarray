# stringarray
customize c++ stringarray
    
		void clear();			                                    //clear all the string in the stringarray
		void add(string income,int index);			              //add a string with specific index(default at the end) to the stringarray
		void remove(int index);			                          //remove the string with specific index of the stringarray
		string stringat(int index);			                      //return the string with specific index
		int length();			                                    //return the string number of stringarray			
		string tostring(string dividestring);		              //return all stringarray elements into a string, default divde elements by " | "

		void spilt(string income,char dividechar);	          //divide an string into an stringarray, default divide by blank space' '
		void dividestringlevel(string income);			          //transfer "(xxx 123 123)(yyy 234 234)" into an stringarray with two elements: "xxx 123 123" and "yyy 234 234" and return it
		string merge(int start, int end, char dividechar);		//return a stringarray elements index from start to end into a string, default divde elements by blank space' '
		string mergeAll(char dividechar);			                //return all stringarray elements into a string, default divde elements by blank space' '
