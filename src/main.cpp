
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
	
	app.Get_ticker_list_currency_pairs();

	return 0;
}