#include "App.h"
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

App::App()
{
	std::string line;
	std::ifstream myfile("key.conf");
	std::string access_token = "";
	Util util;

	if (myfile.is_open())
	{
		while (std::getline(myfile, line))
		{
			std::vector<std::string> temp;
			util.split(line, ':', temp);
			std::string key_name = temp[0];
			std::string key_value = temp[1];
			if (key_name == "access_token")
			{
				access_token = key_value;
			}
		}
		myfile.close();
	}
	else
	{
		std::cout << "Unable to open conf file";
	}
	std::string uri = "https://api3.stex.com";

	api.uri = uri;
	api.access_token = access_token;
}

App::~App()
{
}

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

//Trading
//Returns the user's fees for a given currency pair
void App::Get_user_fee_currency_pair()
{
	std::string currencyPairId;
	std::cout << "please enter currencyPairId (1, 2, 3..):\t";
	std::cin >> currencyPairId;
	std::cout << std::endl;
	api.Get_user_fee_currency_pair(currencyPairId);
}

//List your currently open orders
void App::Get_list_open_all_orders()
{
	api.Get_list_open_all_orders();
}

//Delete all active orders
void App::Delete_all_active_orders()
{
	api.Delete_all_active_orders();
}

//List your currently open orders for given currency pair
void App::Get_list_open_order_by_currency_pair()
{
	std::string currencyPairId;
	std::cout << "please enter currencyPairId (1, 2, 3..):\t";
	std::cin >> currencyPairId;
	std::cout << std::endl;
	api.Get_list_open_order_by_currency_pair(currencyPairId);
}

//Delete active orders for given currency pair
void App::Delete_order_by_currency_pair()
{
	std::string currencyPairId;
	std::cout << "please enter currencyPairId (1, 2, 3..):\t";
	std::cin >> currencyPairId;
	std::cout << std::endl;
	api.Get_list_open_order_by_currency_pair(currencyPairId);
}

//Create new order and put it to the orders processing queue
void App::Creat_new_order()
{
	std::string currencyPairId;
	std::cout << "please enter currencyPairId (1, 2, 3..):\t";
	std::cin >> currencyPairId;
	std::cout << std::endl;

	std::string type;
	std::cout << "please enter type (BUY / SELL / STOP_LIMIT_BUY / STOP_LIMIT_SELL):\t";
	std::cin >> type;
	std::cout << std::endl;

	std::string amount;
	std::cout << "please enter amount :\t";
	std::cin >> amount;
	std::cout << std::endl;

	std::string price;
	std::cout << "please enter price :\t";
	std::cin >> price;
	std::cout << std::endl;

	std::string trigger_price;
	std::cout << "please enter trigger_price :\t";
	std::cin >> trigger_price;
	std::cout << std::endl;

	api.Creat_new_order(currencyPairId, type, amount, price, trigger_price);
}

//Get a single order
void App::Get_single_order()
{
	std::string orderId;
	std::cout << "please enter orderId:\t";
	std::cin >> orderId;
	std::cout << std::endl;
	api.Get_list_open_order_by_currency_pair(orderId);
}

//Cancel order
void App::Delete_order()
{
	std::string orderId;
	std::cout << "please enter orderId:\t";
	std::cin >> orderId;
	std::cout << std::endl;
	api.Delete_order(orderId);
}

//Get a list of currencies user had any activity in
void App::Get_list_currency_user_activity()
{
	std::string key;
	std::cout << "please enter key ( Deposits, Withdrawals, Burn, Reward, Investments ):\t";
	std::cin >> key;
	std::cout << std::endl;
	api.Get_list_currency_user_activity(key);
}

//Gets the list of currency pairs the user had orders in for all the time
void App::Get_list_all_currencypairs_by_user()
{
	api.Get_list_all_currencypairs_by_user();
}

//Get past orders
void App::Get_past_orders()
{
	api.Get_past_orders();
}

//Get specified order details
void App::Get_order_details()
{
	std::string orderId;
	std::cout << "please enter orderId :\t";
	std::cin >> orderId;
	std::cout << std::endl;
	api.Get_order_details(orderId);
}

//Get a list of user trades according to request parameters
void App::Get_list_user_spec_trades()
{
	std::string currencyPairId;
	std::cout << "please enter currencyPairId :\t";
	std::cin >> currencyPairId;
	std::cout << std::endl;
	api.Get_list_user_spec_trades(currencyPairId);
}

//Get reports list for category
void App::Get_reports_list_category()
{
	std::string listMode;
	std::cout << "please enter listMode ( all, recently, scheduled ):\t";
	std::cin >> listMode;
	std::cout << std::endl;
	api.Get_reports_list_category(listMode);
}

//Get some report info
void App::Get_report_info()
{
	std::string id;
	std::cout << "please enter id :\t";
	std::cin >> id;
	std::cout << std::endl;
	api.Get_report_info(id);
}

//Remove report by id
void App::Delete_report_by_id()
{
	std::string id;
	std::cout << "please enter id :\t";
	std::cin >> id;
	std::cout << std::endl;
	api.Delete_report_by_id(id);
}

//Create new report
void App::Create_new_report()
{
	std::string name;
	std::cout << "please enter name :\t";
	std::cin >> name;
	std::cout << std::endl;
	std::string date_from;
	std::cout << "please enter date_from :\t";
	std::cin >> date_from;
	std::cout << std::endl;
	std::string date_to;
	std::cout << "please enter date_to :\t";
	std::cin >> date_to;
	std::cout << std::endl;
	std::string format;
	std::cout << "please enter format  ( Html, Csv, Xls, Pdf ) :\t";
	std::cin >> format;
	std::cout << std::endl;
	std::string type;
	std::cout << "please enter type array 	['All', 'Deposits', 'Withdrawals', 'Orders'] :\t";
	std::cin >> type;
	std::cout << std::endl;
	api.Create_new_report(name, date_from, date_to, format, type);
}

//Get file by id
void App::Get_file_by_id()
{
	std::string id;
	std::cout << "please enter id :\t";
	std::cin >> id;
	std::cout << std::endl;
	api.Delete_report_by_id(id);
}

//Settings
//User event notification settings
void App::Get_list_notification_by_event()
{
	std::string event;
	std::cout << "please enter event (An event name you want to subscribe.) :\t";
	std::cin >> event;
	std::cout << std::endl;
	api.Get_list_notification_by_event(event);
}

//User event notification settings
void App::Get_list_notification()
{
	api.Get_list_notification();
}

//Set notification settings
void App::Set_notification_settings()
{
	std::string event;
	std::cout << "please enter event (An event name you want to subscribe.) :\t";
	std::cin >> event;
	std::cout << std::endl;
	std::string channel;
	std::cout << "please enter channel (A channel name you want to receive the notification through.) :\t";
	std::cin >> channel;
	std::cout << std::endl;
	std::string value;
	std::cout << "please enter value (1, 0) :\t";
	std::cin >> value;
	std::cout << std::endl;

	api.Set_notification_settings(event, channel, value);
}

//Set notification settings
void App::Set_notification_settings_one_request()
{
	api.Set_notification_settings_one_request();
}

//Profile
//Account Information
void App::Get_accoutn_information()
{
	api.Get_accoutn_information();
}

//Get a list of user wallets
void App::Get_list_user_wallets()
{
	api.Get_list_user_wallets();
}

//Single wallet information
void App::Get_single_user_wallet()
{
	std::string walletId;
	std::cout << "please enter walletId :\t";
	std::cin >> walletId;
	std::cout << std::endl;
	api.Get_single_user_wallet(walletId);
}

//Burns the given wallet
void App::Burn_wallet()
{
	std::string walletId;
	std::cout << "please enter walletId :\t";
	std::cin >> walletId;
	std::cout << std::endl;
	api.Burn_wallet(walletId);
}

//Create a wallet for given currency
void App::Create_wallet()
{
	std::string currencyId;
	std::cout << "please enter currencyId :\t";
	std::cin >> currencyId;
	std::cout << std::endl;
	api.Create_wallet(currencyId);
}

//Get deposit address for given wallet
void App::Get_deposit_address_wallet()
{
	std::string walletId;
	std::cout << "please enter walletId :\t";
	std::cin >> walletId;
	std::cout << std::endl;
	api.Get_deposit_address_wallet(walletId);
}

//Create new deposit address
void App::Create_new_deposit_address()
{
	std::string walletId;
	std::cout << "please enter walletId :\t";
	std::cin >> walletId;
	std::cout << std::endl;
	api.Create_new_deposit_address(walletId);
}

//Get a list of deposits made by user
void App::Get_list_user_deposit()
{
	api.Get_list_user_deposit();
}

//Get deposit by id
void App::Get_deposit()
{
	std::string id;
	std::cout << "please enter id :\t";
	std::cin >> id;
	std::cout << std::endl;
	api.Get_deposit(id);
}

//Get a list of rewards obtained by user (e.g. in trading competitions)
void App::Get_list_rewards()
{
	api.Get_list_rewards();
}

//Get reward by id
void App::Get_reward()
{
	std::string id;
	std::cout << "please enter id :\t";
	std::cin >> id;
	std::cout << std::endl;
	api.Get_reward(id);
}

//Get a list of user address book items
void App::Get_list_user_address()
{
	api.Get_list_user_address();
}

//Single address book item
void App::Get_single_address()
{
	std::string itemId;
	std::cout << "please enter itemId :\t";
	std::cin >> itemId;
	std::cout << std::endl;
	api.Get_single_address(itemId);
}

//Deletes address book item
void App::Delete_address_book()
{
	std::string itemId;
	std::cout << "please enter itemId :\t";
	std::cin >> itemId;
	std::cout << std::endl;
	api.Delete_address_book(itemId);
}

//Disables the address book item
void App::Disable_address_book_item()
{
	std::string itemId;
	std::cout << "please enter itemId :\t";
	std::cin >> itemId;
	std::cout << std::endl;
	api.Disable_address_book_item(itemId);
}

//Enable the address book item
void App::Enable_address_book_item()
{
	std::string itemId;
	std::cout << "please enter itemId :\t";
	std::cin >> itemId;
	std::cout << std::endl;
	api.Enable_address_book_item(itemId);
}

//Restrict the withdrawals to only addresses that are active in addressbook
void App::Restrict_withdrawal_addressbook()
{
	api.Restrict_withdrawal_addressbook();
}

//Remove restriction to withdraw to only addresses that are active in addressbook. E.g. allow to withdraw to any address.
void App::Allow_withdrawal_addressbook()
{
	api.Allow_withdrawal_addressbook();
}

//Get a list of withdrawals made by user
void App::Get_list_withdrawal()
{
	api.Get_list_withdrawal();
}

//Get withdrawal by id
void App::Get_withdrawal()
{
	std::string id;
	std::cout << "please enter id :\t";
	std::cin >> id;
	std::cout << std::endl;
	api.Get_withdrawal(id);
}

//Create withdrawal request
void App::Create_withdrawal_request()
{
	std::string currencyId;
	std::cout << "please enter currencyId :\t";
	std::cin >> currencyId;
	std::cout << std::endl;
	std::string amount;
	std::cout << "please enter amount :\t";
	std::cin >> amount;
	std::cout << std::endl;
	std::string address;
	std::cout << "please enter address :\t";
	std::cin >> address;
	std::cout << std::endl;
	api.Create_withdrawal_request(currencyId, amount, address);
}

//Cancel unconfirmed withdrawal
void App::Cancel_unconfirmed_withdrawal()
{
	std::string withdrawalId;
	std::cout << "please enter withdrawalId :\t";
	std::cin >> withdrawalId;
	std::cout << std::endl;
	api.Cancel_unconfirmed_withdrawal(withdrawalId);
}

//Get notifications
void App::Get_notifications()
{
	api.Get_notifications();
}

//Get a list of active price alerts
void App::Get_list_active_price_alert()
{
	api.Get_list_active_price_alert();
}

//Create new price alert
void App::Create_new_price_alert()
{
	std::string currencyPairId;
	std::cout << "please enter currencyPairId :\t";
	std::cin >> currencyPairId;
	std::cout << std::endl;
	std::string comarison;
	std::cout << "please enter comarison ( 'GREATER' or 'LESS') :\t";
	std::cin >> comarison;
	std::cout << std::endl;
	std::string price;
	std::cout << "please enter price :\t";
	std::cin >> price;
	std::cout << std::endl;
	api.Create_new_price_alert(currencyPairId, comarison, price);
}

//Delete the price alert by ID
void App::Delete_price_alert()
{
	std::string priceAlertId;
	std::cout << "please enter priceAlertId :\t";
	std::cin >> priceAlertId;
	std::cout << std::endl;
	api.Delete_price_alert(priceAlertId);
}

//Create referral program
void App::Create_referral_program()
{
	api.Create_referral_program();
}

//Insert referral code
void App::Insert_referral_code()
{
	std::string code;
	std::cout << "please enter code :\t";
	std::cin >> code;
	std::cout << std::endl;
	api.Delete_price_alert(code);
}

//Transfer referral bonuses balance to main balance for given currency
void App::Transfer_referral_bonuses()
{
	std::string currencyId;
	std::cout << "please enter currencyId :\t";
	std::cin >> currencyId;
	std::cout << std::endl;
	api.Transfer_referral_bonuses(currencyId);
}

//Get favorite currency pairs
void App::Get_fav_currency_pair()
{
	api.Get_fav_currency_pair();
}

//Set favorite currency pairs
/*
    addPairIds  array[integer](query)	add ids of currency pairs to list
    removePairIds   array[integer](query)	remove ids of currency pairs from list
    show        boolean(query)
    */
void App::Set_fav_currency_pair()
{
	std::string addPairIds;
	std::cout << "please enter addPairIds(1,2,3...) :\t";
	std::cin >> addPairIds;
	std::cout << std::endl;
	api.Set_fav_currency_pair(addPairIds);
}

//Get current token scopes
void App::Get_current_token_scopes()
{
	api.Get_current_token_scopes();
}