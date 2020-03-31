# stringarray
自定义 c++ 字符串数组
    
		void clear();			                                    //清空字符串数组
		void add(string income,int index);			              //添加一个字符串到字符串数组中，默认添加到数组最后
		void remove(int index);			                          //删除字符串数组指定位置的字符串
		string stringat(int index);			                      //返回字符串数组指定位置的字符串
		int length();			                                    //返回字符串数组字符串数量			
		string tostring(string dividestring);		              //返回字符串数组所包含的字符串，默认以|分隔

		void spilt(string income,char dividechar);	          //将一串字符串分割存入字符串数组，默认以空格分隔符
		void dividestringlevel(string income);			          //将形如 "(xxx 123 123)(yyy 234 234)" 的字符串分割成形如 "xxx 123 123" "yyy 234 234" 的字符串存入字符串数组
		string merge(int start, int end, char dividechar);		//返回字符串数组从start到end的字符串，默认以空格分隔
		string mergeAll(char dividechar);			                //返回字符串数组的字符串，默认以空格分隔
