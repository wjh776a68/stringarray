/*
Javatify c++ string[]
wjh776a68 20200325

*/
#ifndef stringarray_H 
#define stringarray_H 

#include<iostream>
#include<malloc.h>
using namespace std;
typedef struct stringarrayunitstruct{
	struct stringarrayunitstruct* next;
	string String;
}stringarrayunit;

typedef struct stringarraystruct{
	stringarrayunit* Stringhead;	
	int count;
}stringarray;

class stringarrayclass{

	public:
		stringarrayclass(){		
			me.count = 0;
			me.Stringhead = NULL;
		}
		//Functions fundamental
		void clear();												//clear all the string of the stringarray
		void add(string income,int index);							//add the string with specific index(default the end) from the stringarray
		void remove(int index);										//remove the string with specific index from the stringarray
		string stringat(int index);									//return the string with specific index
		int length();												//return the strings amount of stringarray			
		string tostring(string dividestring);						//return all stringarray elements into a string, default divde elements by " | "
		//Functions interact with string
		void spilt(string income,char dividechar);					//divide an string into an stringarray, default divide by space' '
		void dividestringlevel(string income);						//make "(xxx 123 123)(yyy 234 234)" to an stringarray with two elements: "xxx 123 123" and "yyy 234 234"
		string merge(int start, int end, char dividechar);			//return stringarray elements index from start to end into a string, default divde elements by space' '
		string mergeAll(char dividechar);							//return all stringarray elements into a string, default divde elements by space' '
	private:
		stringarray me;
};


int stringarrayclass::length(){
	return me.count;
}

string stringarrayclass::tostring(string dividestring = " | "){
	int i=0;
	string result="";
	stringarrayunit* stringnode = me.Stringhead;
	while(i<me.count - 1){
		result += stringnode->String + dividestring;
		stringnode = stringnode->next;
		i++;
	}
	result += stringnode->String;
	return result;
}


string stringarrayclass::stringat(int index){
	if (index >= 0) {
		if (me.count < index) {
			cout << "Error when stringat : index: " << index << " out of range" << endl;
			return "";
		}
		else {
			int i = 0;
			stringarrayunit* nextnode = me.Stringhead;
			while (i != index) {
				nextnode = nextnode->next;
				i++;
			}
			return nextnode->String;
		}
		
	}
	else if (index < 0) {
		if (me.count > -index) {
			cout << "Error when stringat : index: " << index << " out of range" << endl;
			return "";
		}
		else {
			int i = 0;
			stringarrayunit* nextnode = me.Stringhead;
			while (i != me.count + index) {
				nextnode = nextnode->next;
				i++;
			}
			return nextnode->String;
		}
		
	}

	return "";
}

void stringarrayclass::remove(int index){
	if(me.count<index)	{
		cout<<"Error when remove string to stringarray: index: "<<index<<" out of range"<<endl;
		return;
	}
	else {
		int i = 0;
		stringarrayunit* lnextnode = me.Stringhead, * nextnode = me.Stringhead;
		while (i != index) {
			lnextnode = nextnode;
			nextnode = nextnode->next;
			i++;
		}
		lnextnode->next = nextnode->next;
		free(nextnode);
		me.count--;
	}
	
}

void stringarrayclass::add(string income,int index=0){
	if(me.count + 1<index)	{
		cout<<"Error when add string to stringarray: index: "<<index<<" out of range"<<endl;
		return;
	}
	else {
		int i = 0;
		//stringarrayunit* newunit = (stringarrayunit*)malloc(sizeof(stringarrayunit));
		stringarrayunit* newunit = new stringarrayunit;
		//stringarrayunit newunit{ NULL,"" };
		newunit->next = NULL;
		newunit->String = income;


		stringarrayunit* lnextnode = NULL;
		stringarrayunit* nextnode = me.Stringhead;
		while (i < index) {
			lnextnode = nextnode;
			nextnode = nextnode->next;
			i++;
		}
		if (lnextnode == NULL) {
			me.Stringhead = newunit;
		}
		else {
			lnextnode->next = newunit;
		}
		newunit->next = nextnode;
		me.count++;
		return;
	}

}

void stringarrayclass::clear(){
	stringarrayunit* del;
	while(me.count>0){
		del = me.Stringhead;
		me.Stringhead = me.Stringhead->next;
		delete(del);
		//free(del);
		
		me.count--;
	}
}


void stringarrayclass::spilt(string income, char spiltchar=' ') {
	//stringarrayclass result;
	stringarrayclass::clear();
	int start = 0, end = -1;
	int i = 0;
	for (i = 0; i < income.length(); i++) {
		if (income.at(i) == spiltchar)
		{
			start = end + 1;
			end = i;
			//cout <<"["<< income.substr(start, end - start)<<"]";
			stringarrayclass::add(income.substr(start, end - start), stringarrayclass::length());
		}
	}

	stringarrayclass::add(income.substr(end + 1, i - end), stringarrayclass::length());
	//cout<<result.tostring();
	//return result;
}

void stringarrayclass::dividestringlevel(string income) {
	//stringarrayclass result;
	stringarrayclass::clear();
	string composebuffer = "";
	int informlevel = 0;
	for (int i = 0; i < income.length(); i++) {
		//linformlevel = informlevel; // 用于比较层数以便分割字符串
		if (income.at(i) == '(') {
			if (informlevel != 0) {
				composebuffer += income.at(i);
			}
			informlevel++;
			//i++;//很遗憾，括号在这里只是一个分隔符，利用完成直接跳过，有无比拼音输入更好用的中文输入如法？-……-
		}
		else if (income.at(i) == ')') {
			informlevel--;
			if (informlevel != 0) {
				composebuffer += income.at(i);
			}
			//i++;//很遗憾，括号在这里只是一个分隔符，利用完成直接跳过
		}
		else {
			composebuffer += income.at(i);
		}

		if (informlevel == 0 && composebuffer._Equal("") == false) {
			stringarrayclass::add(composebuffer, stringarrayclass::length());
			composebuffer = "";
		}
	}

	//return result;
}

string stringarrayclass::mergeAll(char dividechar = ' ') {
	return stringarrayclass::merge(0, stringarrayclass::length() - 1, dividechar);
}

string stringarrayclass::merge(int start, int end, char dividechar = ' ') {
	if (end >= stringarrayclass::length()) {
		cout << "Error when merge stringarray to string: end index: " << end << " out of range" << endl;
		return "";
	}
	if (start < 0) {
		cout << "Error when merge stringarray to string: start index: " << start << " out of range" << endl;
		return "";
	}

	string objinfo = "";
	for (int objnum = start; objnum < end; objnum++) {
		objinfo += stringarrayclass::stringat(objnum) + dividechar;
	}
	objinfo += stringarrayclass::stringat(end);

	return objinfo;
}





#endif
