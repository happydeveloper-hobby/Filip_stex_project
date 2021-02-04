// Api.h
#ifndef APP_H
#define APP_H

#include "API.h"
#include <string>
#include <vector>

class App
{
public:
    App();
    ~App();
    /* Declare Variables */
    std::string uri;
    std::string product_id;
    API api;


    //Public
    //1 Available Currencies
    void Get_list_currencies();

    //2 Get currency info
    void Get_currency_info();

    //3 Available markets
    void Get_list_markets();

    //4 Get list of all avialable currency pairs groups
    void Get_list_currency_pairs_groups();

    //5 Available currency pairs
    void Get_currency_pairs();

    //6 Available currency pairs for a given group
    void Get_currency_pairs_given_group();

    //7 Get currency pair information
    void Get_currency_pair_information();

    //8 Tickers list for all currency pairs
    void Get_ticker_list_currency_pairs();

    //9 Ticker for currency pair
    void Get_ticker_currency_pair();

    //10 Trades for given currency pair
    void Get_trades_currency_pair();

    //11 Orderbook for given currency pair
    void Get_orderbook_currency_pair();

    //12 A list of candles for given currency pair
    void Get_list_candles_currency_pair();

    //13 Available Deposit Statuses
    void Get_list_deposit_statuses();

    //14 Get deposit status info
    void Get_deposit_status();

    //15 Available Withdrawal Statuses
    void Get_list_withdrawal_statuses();

    //16 Get status info
    void Get_withdrawal_status();

    //17 Test API is working and get server time
    void ping();

    //18 Shows the official mobile applications data
    void Get_mobile_version();

    //19 Get the last 20 posts (stex.com) on Twitter
    void Get_twitter();

    //Trading
    //20 Returns the user's fees for a given currency pair
    void Get_user_fee_currency_pair();

    //21 List your currently open orders
    void Get_list_open_all_orders();

    //22 Delete all active orders
    void Delete_all_active_orders();

    //23 List your currently open orders for given currency pair
    void Get_list_open_order_by_currency_pair();

    //24 Delete active orders for given currency pair
    void Delete_order_by_currency_pair();

    //25 Create new order and put it to the orders processing queue
    void Creat_new_order();

    //26 Get a single order
    void Get_single_order();

    //27 Cancel order
    void Delete_order();

    //trading history
    //28 Get a list of currencies user had any activity in
    void Get_list_currency_user_activity();

    //29 Gets the list of currency pairs the user had orders in for all the time
    void Get_list_all_currencypairs_by_user();

    //30 Get past orders
    void Get_past_orders();

    //31 Get specified order details
    void Get_order_details();

    //32 Get a list of user trades according to request parameters
    void Get_list_user_spec_trades();

    //33 Get reports list for category
    void Get_reports_list_category();

    //34 Get some report info
    void Get_report_info();

    //35 Remove report by id
    void Delete_report_by_id();

    //36 Create new report
    void Create_new_report();

    //37 Get file by id
    void Get_file_by_id();

    //Settings
    //38 User event notification settings by event
    void Get_list_notification_by_event();

    //39 User event notification settings
    void Get_list_notification();

    //40 Set notification settings in specific channel for the user
    void Set_notification_settings();

    //41 Set notification settings in many channels for the user at one request
    void Set_notification_settings_one_request();




};

#endif // APP_H
