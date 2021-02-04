#include "API.h"
#include "App.h"
#include "Util.h"
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


int main()
{
	App app;
	int choice = 0;

	do
	{
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
		std::cout << "\t" << std::left << std::setw(45) << "20) Returns the user's fees for a given currency pair" << std::endl;
		std::cout << "\t" << std::left << std::setw(45) << "21) List your currently open orders" << std::endl;
		std::cout << "\t" << std::left << std::setw(45) << "22) Delete all active orders" << std::endl;
		std::cout << "\t" << std::left << std::setw(45) << "23) List your currently open orders for given currency pair" << std::endl;
		std::cout << "\t" << std::left << std::setw(45) << "24) Delete active orders for given currency pair" << std::endl;
		std::cout << "\t" << std::left << std::setw(45) << "25) Create new order and put it to the orders processing queue" << std::endl;
		std::cout << "\t" << std::left << std::setw(45) << "26) Get a single order" << std::endl;
		std::cout << "\t" << std::left << std::setw(45) << "27) Cancel order" << std::endl;
		std::cout << "\t" << std::left << std::setw(45) << "28) Get a list of currencies user had any activity in" << std::endl;
		std::cout << "\t" << std::left << std::setw(45) << "29) Gets the list of currency pairs the user had orders in for all the time" << std::endl;
		std::cout << "\t" << std::left << std::setw(45) << "30) Get past orders" << std::endl;
		std::cout << "\t" << std::left << std::setw(45) << "31) Get specified order details" << std::endl;
		std::cout << "\t" << std::left << std::setw(45) << "32) Get a list of user trades according to request parameters" << std::endl;
		std::cout << "\t" << std::left << std::setw(45) << "33) Get reports list for category" << std::endl;
		std::cout << "\t" << std::left << std::setw(45) << "34) Get some report info" << std::endl;
		std::cout << "\t" << std::left << std::setw(45) << "35) Remove report by id" << std::endl;
		std::cout << "\t" << std::left << std::setw(45) << "36) Create new report" << std::endl;
		std::cout << "\t" << std::left << std::setw(45) << "37) Get file by id" << std::endl;
		std::cout << "\t" << std::left << std::setw(45) << "38) User event notification settings by event" << std::endl;
		std::cout << "\t" << std::left << std::setw(45) << "39) User event notification settings" << std::endl;
		std::cout << "\t" << std::left << std::setw(45) << "40) Set notification settings in specific channel for the user" << std::endl;
		std::cout << "\t" << std::left << std::setw(45) << "41) Set notification settings in many channels for the user at one request" << std::endl;
		std::cout << "\t" << std::left << std::setw(45) << "42) Exit" << std::setw(45) << std::endl;

		choice = GetInput();

		switch (choice)
		{
			case 1: 	app.Get_list_currencies(); 						break;
			case 2: 	app.Get_currency_info(); 						break;
			case 3: 	app.Get_list_markets(); 						break;
			case 4: 	app.Get_list_currency_pairs_groups(); 			break;
			case 5: 	app.Get_currency_pairs(); 						break;
			case 6: 	app.Get_currency_pairs_given_group(); 			break;
			case 7: 	app.Get_currency_pair_information(); 			break;
			case 8: 	app.Get_ticker_list_currency_pairs(); 			break;
			case 9: 	app.Get_ticker_currency_pair();					break;
			case 10:	app.Get_trades_currency_pair();					break;
			case 11:	app.Get_orderbook_currency_pair();				break;
			case 12:	app.Get_list_candles_currency_pair(); 			break;
			case 13:	app.Get_list_deposit_statuses();				break;
			case 14:	app.Get_deposit_status();						break;
			case 15:	app.Get_list_withdrawal_statuses();				break;
			case 16:	app.Get_withdrawal_status();					break;
			case 17:	app.ping();										break;
			case 18:	app.Get_mobile_version();						break;
			case 19:	app.Get_twitter();								break;
			case 20:	app.Get_user_fee_currency_pair();				break;
			case 21:	app.Get_list_open_all_orders();					break;
			case 22:	app.Delete_all_active_orders();					break;
			case 23:	app.Get_list_open_order_by_currency_pair();		break;
			case 24:	app.Delete_order_by_currency_pair();			break;
			case 25:	app.Creat_new_order();							break;
			case 26:	app.Get_single_order();							break;
			case 27:	app.Delete_order();								break;
			case 28:	app.Get_list_currency_user_activity();			break;
			case 29:	app.Get_list_all_currencypairs_by_user();		break;
			case 30:	app.Get_past_orders();							break;
			case 31:	app.Get_order_details();						break;
			case 32:	app.Get_list_user_spec_trades();				break;
			case 33:	app.Get_reports_list_category();				break;
			case 34:	app.Get_report_info();							break;
			case 35:	app.Delete_report_by_id();						break;
			case 36:	app.Create_new_report();						break;
			case 37:	app.Get_file_by_id();							break;
			case 38:	app.Get_list_notification_by_event();			break;
			case 39:	app.Get_list_notification();					break;
			case 40:	app.Set_notification_settings();				break;
			case 41:	app.Set_notification_settings_one_request();	break;
			case 42:	break;
			default:	break;
		}
		std::cout << std::endl;
		std::cout << "================================================================= " << std::endl << std::endl;

	} while (choice < 42);

	return 0;
}
