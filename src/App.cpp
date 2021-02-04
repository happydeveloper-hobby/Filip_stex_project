#include "App.h"
#include "Auth.h"
#include "API.h"
#include "Util.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>

#include <iostream>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

// #include "Util.cpp"

using namespace rapidjson;



//Public
// Available Currencies
void App::Get_list_currencies()
{
	api.Get_list_currencies();
}

// Get currency info
void App::Get_currency_info()
{
	std::string currencyId;
	std::cout << "please enter currencyId:\t";
	std::cin >> currencyId;
	std::cout << std::endl;
	api.Get_currency_info(currencyId);
}

// Available markets
void App::Get_list_markets()
{
	api.Get_list_markets();
}

// Get list of all avialable currency pairs groups
void App::Get_list_currency_pairs_groups()
{
	api.Get_list_currency_pairs_groups();
}

// Available currency pairs
void App::Get_currency_pairs()
{
	std::string code;
	std::cout << "please enter code (Available values : ALL, marketSymbol):\t";
	std::cin >> code;
	std::cout << std::endl;
	api.Get_currency_pairs(code);
}

// Available currency pairs for a given group
void App::Get_currency_pairs_given_group()
{
	std::string currencyPairGroupId;
	std::cout << "please enter currencyPairGroupId:\t";
	std::cin >> currencyPairGroupId;
	std::cout << std::endl;
	api.Get_currency_pairs_given_group(currencyPairGroupId);
}

// Get currency pair information
void App::Get_currency_pair_information()
{
	std::string currencyPairId;
	std::cout << "please enter currencyPairId:\t";
	std::cin >> currencyPairId;
	std::cout << std::endl;
	api.Get_currency_pair_information(currencyPairId);
}

// Tickers list for all currency pairs
void App::Get_ticker_list_currency_pairs()
{
	api.Get_ticker_list_currency_pairs();
}

// Ticker for currency pair
void App::Get_ticker_currency_pair()
{
	std::string currencyPairId;
	std::cout << "please enter currencyPairId:\t";
	std::cin >> currencyPairId;
	std::cout << std::endl;
	api.Get_ticker_currency_pair(currencyPairId);
}

// Trades for given currency pair
void App::Get_trades_currency_pair()
{
	std::string currencyPairId;
	std::cout << "please enter currencyPairId:\t";
	std::cin >> currencyPairId;
	std::cout << std::endl;

	api.Get_trades_currency_pair(currencyPairId);
}

// Orderbook for given currency pair
void App::Get_orderbook_currency_pair()
{
	std::string currencyPairId;
	std::cout << "please enter currencyPairId:\t";
	std::cin >> currencyPairId;
	std::cout << std::endl;

	api.Get_orderbook_currency_pair(currencyPairId);
}

// A list of candles for given currency pair
void App::Get_list_candles_currency_pair()
{
	std::string currencyPairId;
	std::cout << "please enter currencyPairId:\t";
	std::cin >> currencyPairId;
	std::cout << std::endl;

	std::string candlesType;
	std::cout << "please enter candlesType (1, 5, 30, 60, 240, 720, 1D):\t";
	std::cin >> candlesType;
	std::cout << std::endl;

	std::string timeStart;
	std::cout << "please enter timeStart (e.g  1609459200):\t";
	std::cin >> timeStart;
	std::cout << std::endl;

	std::string timeEnd;
	std::cout << "please enter timeEnd (e.g  1612354600):\t";
	std::cin >> timeEnd;
	std::cout << std::endl;

	api.Get_list_candles_currency_pair(currencyPairId, candlesType, timeStart, timeEnd);
}

// Available Deposit Statuses
void App::Get_list_deposit_statuses()
{
	api.Get_list_deposit_statuses();
}

// Get deposit status info
void App::Get_deposit_status()
{
	std::string statusId;
	std::cout << "please enter statusId:\t";
	std::cin >> statusId;
	std::cout << std::endl;
	api.Get_orderbook_currency_pair(statusId);
}

// Available Withdrawal Statuses
void App::Get_list_withdrawal_statuses()
{
	api.Get_list_withdrawal_statuses();
}

// Get status info
void App::Get_withdrawal_status()
{
	std::string statusId;
	std::cout << "please enter statusId:\t";
	std::cin >> statusId;
	std::cout << std::endl;
	api.Get_orderbook_currency_pair(statusId);
}

// Test API is working and get server time
void App::ping()
{
	api.ping();
}

// Shows the official mobile applications data
void App::Get_mobile_version()
{
	api.Get_mobile_version();
}

// Get the last 20 posts (stex.com) on Twitter
void App::Get_twitter()
{
	api.Get_twitter();
}









App::App()
{
	// std::string line;
	// std::ifstream myfile("key.conf");
	// std::string api_key = "";
	// std::string secret = "";
	// std::string passcode = "";
	// Util util;

	// if (myfile.is_open())
	// {
	// 	while (std::getline(myfile, line))
	// 	{
	// 		std::vector<std::string> temp;
	// 		util.tokenize(line, ':', temp);
	// 		std::string key_name = temp[0];
	// 		std::string key_value = temp[1];
	// 		if (key_name == "api_key")
	// 		{
	// 			api_key = key_value;
	// 		}
	// 		if (key_name == "secret")
	// 		{
	// 			secret = key_value;
	// 		}
	// 		if (key_name == "passcode")
	// 		{
	// 			passcode = key_value;
	// 		}
	// 	}
	// 	myfile.close();
	// }
	// else
	// {
	// 	std::cout << "Unable to open conf file";
	// }
	// // std::string uri = "https://api-public.sandbox.pro.coinbase.com";
	std::string uri = "https://api3.stex.com";

	// std::string product_id = "BTC-USD";
	// std::string currency = "BTC";

	// Auth auth(api_key, secret, passcode);
	api.uri = uri;
	// api.product_id = product_id;
	// api.auth = auth;
}

App::~App()
{
}
