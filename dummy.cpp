#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	string line ="JG-10214   Imanul    Pb meletup       5          Sent to mfg";
	
//	std::string::iterator end_pos = std::remove(line.begin(), line.end(), ' '); //remove trailling/any white spaces in between (eg admin Admin123 --> adminAdmin123)
//				line.erase(end_pos, line.end());
//            	cout << line;
            //	concatID = line; //assign to a global variable
            	
	int lengthstr= line.length();
    cout << lengthstr;
    int diff= lengthstr - 8;
	line.erase(line.begin()+8,line.end());
	cout << line;
}
