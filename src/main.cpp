
#include "API.h"
#include "App.h"
#include "Util.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <climits>
#include <chrono>
#include <algorithm>
#include <thread>
#include <iomanip>

using namespace std;

int main()
{
	App app;
	string str = "";
	bool f = false;
	cout<< "Will you use all currency pairs, or your currency pairs in conf file? [Y/n]\t";
	cin >> str;
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	if(str == "y"){
		f = false;
	}else if(str == "n"){
		f = true;
	}else return 0;
	app.Get_ticker_list_currency_pairs(f);

	return 0;
}