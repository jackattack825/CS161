/*********************************************************************
** Program Filename: Program #1
** Author: Jackson Perry
** Date: 9/27/18
** Description: Printing max/min values based upon number of bytes
** Input: # of bytes
** Output: Text into terminal window
*********************************************************************/

#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

int main() {

	cout << "Max signed int is " << INT_MAX <<
		" Min signed int is " << INT_MIN << endl;
	cout << " Max unsigned int is " << UINT_MAX <<
		" Min unsigned int is " << "0" << endl;
	cout << " Max signed long is " << LONG_MAX <<
		" Min signed long is " << LONG_MIN << endl;
	cout << " Max unsigned long is " << ULONG_MAX <<
		" Min unsigned long is " << "0.0" << endl;
	cout << " Max signed short is " << SHRT_MAX <<
		" Min signed short is " << SHRT_MIN << endl;
	cout << " Max unsigned short is " << USHRT_MAX <<
		" Min unsigned short is " << "0.0" << endl;

	int bytes; //hold # of bytes from user
	unsigned long long int max; // hold max # based upon bytes
	
	cout << "How many bytes" << endl;

	cin >> bytes;
	if (bytes > 0 && bytes <= 8) {
		max = pow((long double) 2, bytes * 8) - 1;

		unsigned long long int max_unsigned = pow((long double)2, (bytes *8)) - 1;
		unsigned long long int min_signed = pow((long double)2, (bytes *8)) / 2;
		unsigned long long int max_signed = pow((long double)2, (bytes *8)) / 2 - 1;

		//regular values
		cout << "Max # in " << bytes << " unsigned bytes is " << max_unsigned << endl;
		cout << "Min # in " << bytes << " unsigned bytes is " << "0" << endl;

		cout << "Max # in " << bytes << " signed bytes is " << max_signed << endl;
		cout << "Min # in " << bytes << " signed bytes is -  " << min_signed << endl;

		//add or subtract 1
		cout << "Max # in " << bytes << " unsigned bytes +1 is " << "0" << endl;
		cout << "Min # in " << bytes << " unsigned bytes -1 is " << max_unsigned << endl;

		cout << "Max # in " << bytes << " signed bytes +1 is -  " << min_signed << endl;
		cout << "Min # in " << bytes << " signed bytes -1 is " << max_signed << endl;
	}
	else {
		cout << "You entered a number 0 or below, or above 8!" << endl;
		return -1;
	}

	return 0;
}
