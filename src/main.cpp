#include "Auth.h"
#include "API.h"
#include "App.h"
#include "Util.h"
#include "Websock.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include <iomanip>

bool stop = false;

int GetInput()
{
	int choice;
	std::cout << std::endl;
	std::cout << "Please select item number!   ";
	std::cin >> choice;
	std::cout << std::endl;
	std::cout << "Result : " << std::endl;
	std::cout << "================================================================= " << std::endl
			  << std::endl;
	return choice;
}


int main1()
{
	App app;
	Util util;
	util.GetTimestamp();
	int choice = 0;





	do
	{
		// system("clear");

		std::cout << std::endl
				  << std::endl
				  << std::endl;
		std::cout << "\t" << std::left << std::setw(60) << "STEX API" << std::endl << std::endl;
		std::cout << "\t" << std::left << std::setw(45) << "1) Available Currencies" << std::endl;
		std::cout << "\t" << std::left << std::setw(45) << "2) Get currency info" << std::endl;
		std::cout << "\t" << std::left << std::setw(45) << "3) Available markets" << std::endl;
		std::cout << "\t" << std::left << std::setw(45) << "4) Get list of all avialable currency pairs groups" << std::endl;
		std::cout << "\t" << std::left << std::setw(45) << "5) Available currency pairs" << std::endl;
		std::cout << "\t" << std::left << std::setw(45) << "6) Available currency pairs for a given group" << std::endl;
		std::cout << "\t" << std::left << std::setw(45) << "7) Get currency pair information" << std::endl;
		std::cout << "\t" << std::left << std::setw(45) << "8) Tickers list for all currency pairs" << std::endl;
		std::cout << "\t" << std::left << std::setw(45) << "9) Ticker for currency pair" << std::endl;
		std::cout << "\t" << std::left << std::setw(45) << "10) Trades for given currency pair" << std::endl;
		std::cout << "\t" << std::left << std::setw(45) << "11) Orderbook for given currency pair" << std::endl;
		std::cout << "\t" << std::left << std::setw(45) << "12) A list of candles for given currency pair" << std::endl;
		std::cout << "\t" << std::left << std::setw(45) << "13) Available Deposit Statuses" << std::endl;
		std::cout << "\t" << std::left << std::setw(45) << "14) Get deposit status info" << std::endl;
		std::cout << "\t" << std::left << std::setw(45) << "15) Available Withdrawal Statuses" << std::endl;
		std::cout << "\t" << std::left << std::setw(45) << "16) Get status info" << std::endl;
		std::cout << "\t" << std::left << std::setw(45) << "17) Test API is working and get server time" << std::endl;
		std::cout << "\t" << std::left << std::setw(45) << "18) Shows the official mobile applications data" << std::endl;
		std::cout << "\t" << std::left << std::setw(45) << "19) Get the last 20 posts (stex.com) on Twitter" << std::endl;
		std::cout << "\t" << std::left << std::setw(45) << "20) Exit" << std::setw(45) << std::endl;

		choice = GetInput();

		switch (choice)
		{
		case 1:
			app.Get_list_currencies();
			break;
		case 2:
			app.Get_currency_info();
			break;
		case 3:
			app.Get_list_markets();
			break;
		case 4:
			app.Get_list_currency_pairs_groups();
			break;
		case 5:
			app.Get_currency_pairs();
			break;
		case 6:
			app.Get_currency_pairs_given_group();
			break;
		case 7:
			app.Get_currency_pair_information();
			break;
		case 8:
			app.Get_ticker_list_currency_pairs();
			break;
		case 9:
			app.Get_ticker_currency_pair();
			break;
		case 10:
			app.Get_trades_currency_pair();
			break;
		case 11:
			app.Get_orderbook_currency_pair();
			break;
		case 12:
			app.Get_list_candles_currency_pair();
			break;
		case 13:
			app.Get_list_deposit_statuses();
			break;
		case 14:
			app.Get_deposit_status();
			break;
		case 15:
			app.Get_list_withdrawal_statuses();
			break;
		case 16:
			app.Get_withdrawal_status();
			break;
		case 17:
			app.ping();
			break;
		case 18:
			app.Get_mobile_version();
			break;
		case 19:
			app.Get_twitter();
			break;
		case 20:
			break;
		default:
			break;
		
		}
		std::cout << std::endl;
		std::cout << "================================================================= " << std::endl
				  << std::endl;

	} while (choice < 20);

	return 0;
}
