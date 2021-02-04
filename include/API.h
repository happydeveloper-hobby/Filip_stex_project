// Api.h
#ifndef API_H
#define API_H

#include <string>
#include <vector>

class API
{
private:
    std::string Call(std::string method, bool authed, std::string path, std::string body);

public:
    API();
    ~API();
    std::string uri;
    std::string access_token;
    std::string product_id;
    std::string Get_Buy_Price();
    double Get_Balance(std::string currency);
    std::string Place_Limit_Order(std::string side, std::string price, std::string size);

    //Public
    // Available Currencies
    std::string Get_list_currencies();

    // Get currency info
    std::string Get_currency_info(std::string currencyId);

    // Available markets
    std::string Get_list_markets();

    // Get list of all avialable currency pairs groups
    std::string Get_list_currency_pairs_groups();

    // Available currency pairs
    std::string Get_currency_pairs(std::string code);

    // Available currency pairs for a given group
    std::string Get_currency_pairs_given_group(std::string currencyPairGroupId);

    // Get currency pair information
    std::string Get_currency_pair_information(std::string currencyPairId);

    // Tickers list for all currency pairs
    std::string Get_ticker_list_currency_pairs();

    // Ticker for currency pair
    std::string Get_ticker_currency_pair(std::string currencyPairId);

    // Trades for given currency pair
    /* parameter
    sort
    string
    (query)	
    Direction of the sort - ASCending or DESCending by trade timestamp

    Available values : DESC, ASC

    Default value : DESC

    from
    integer
    (query)	
    The timestamp in seconds

    till
    integer
    (query)	
    The timestamp in seconds

    limit
    integer
    (query)	
    Default value : 100

    offset
    integer
    (query) 
     */
    std::string Get_trades_currency_pair(std::string currencyPairId, std::string sort = "", std::string from = "", std::string till = "", std::string limit = "", std::string offset = "");

    // Orderbook for given currency pair
    /*
    parameter
    limit_bids
    integer
    (query)	
    Return only top N bids. Returns all if set to -1

    Default value : 20

    limit_asks
    integer
    (query)	
    Return only top N asks. Returns all if set to -1

    Default value : 20
    */
    std::string Get_orderbook_currency_pair(std::string currencyPairId, std::string limit_bids = "", std::string limit_asks = "");

    // A list of candles for given currency pair
    /*
    parameter
    currencyPairId *
    string
    (path)	
    A currency pair ID you want to get candles for

    candlesType *
    string
    (path)	
    Candle size 1 stays for 1 minute, 5 - 5 minutes and so on. 1D - stays for 1 day

    Available values : 1, 5, 30, 60, 240, 720, 1D

    Default value : 1D

    timeStart *
    integer
    (query)	
    Timestamp in second. Should be less then timeEnd

    timeEnd *
    integer
    (query)	
    Timestamp in second. Should be greater then timeStart

    limit
    integer
    (query)	
    Default value : 100

    offset
    integer
    (query)	
    */
    std::string Get_list_candles_currency_pair(std::string currencyPairId, std::string candlesType, std::string timeStart, std::string timeEnd, std::string limit = "", std::string offset = "");

    // Available Deposit Statuses
    std::string Get_list_deposit_statuses();

    // Get deposit status info
    std::string Get_deposit_status(std::string statusId);

    // Available Withdrawal Statuses
    std::string Get_list_withdrawal_statuses();

    // Get status info
    std::string Get_withdrawal_status(std::string statusId);

    // Test API is working and get server time
    std::string ping();

    // Shows the official mobile applications data
    std::string Get_mobile_version();

    // Get the last 20 posts (stex.com) on Twitter
    std::string Get_twitter();


    //Trading
    //Returns the user's fees for a given currency pair
    std::string Get_user_fee_currency_pair(std::string currencyPairId);

    //List your currently open orders
    /*
    parameter
    limit   integer(query)	    Default value : 100

    offset  integer(query)
    */
    std::string Get_list_open_all_orders(std::string limit = "", std::string offset = "");

    //Delete all active orders
    std::string Delete_all_active_orders();

    //List your currently open orders for given currency pair
    std::string Get_list_open_order_by_currency_pair(std::string currencyPairId, std::string limit = "", std::string offset = "");

    //Delete active orders for given currency pair
    std::string Delete_order_by_currency_pair(std::string currencyPairId);

    //Create new order and put it to the orders processing queue
    /*
    parameter
    type *          string      order type (BUY / SELL / STOP_LIMIT_BUY / STOP_LIMIT_SELL)

    amount *        number
    price *         number
    trigger_price   number      stop price for stop-limit orders. Required if the order is of type STOP_LIMIT_BUY or STOP_LIMIT_SELL
    */
    std::string Creat_new_order(std::string currencyPairId, std::string type, std::string amount, std::string price, std::string trigger_price = "");

    //Get a single order
    std::string Get_single_order(std::string orderId);

    //Cancel order
    std::string Delete_order(std::string orderId);

    //Trading History & Reports
    //Get a list of currencies user had any activity in
    /*
    parameter
    key *       Available values : Deposits, Withdrawals, Burn, Reward, Investments
    string
    (query)	
    */
    std::string Get_list_currency_user_activity(std::string key);

    //Gets the list of currency pairs the user had orders in for all the time
    std::string Get_list_all_currencypairs_by_user();

    //Get past orders
    /*
    parameter
    currencyPairId  integer (query)	
    orderStatus     string  (query)	    Available values : ALL, FINISHED, CANCELLED, PARTIAL, WITH_TRADES   Default value : ALL
    timeStart       integer (query)	    Timestamp in seconds.
    timeEnd         integer (query)	    Timestamp in seconds.
    limit           integer (query)	    Default value : 100
    offset          integer (query)	
    */
    std::string Get_past_orders(std::string currencyPairId = "", std::string orderStatus = "", std::string timeStart = "", std::string timeEnd = "", std::string limit = "", std::string offset = "");

    //Get specified order details
    std::string Get_order_details(std::string orderId);

    //Get a list of user trades according to request parameters
    std::string Get_list_user_spec_trades(std::string currencyPairId, std::string timeStart = "", std::string timeEnd = "", std::string limit = "", std::string offset = "");

    //Get reports list for category
    /*
    listMode *      string(path)	Available values : all, recently, scheduled
    */
    std::string Get_reports_list_category(std::string listMode, std::string limit = "", std::string offset = "");

    //Get some report info
    std::string Get_report_info(std::string id);

    //Remove report by id
    std::string Delete_report_by_id(std::string id);

    //Create new report
    /*
    type        array[string](query)	["All", "Deposits", "Withdrawals", "Orders"]
    format *    string(query)	        Available values : Html, Csv, Xls, Pdf
    */
    std::string Create_new_report(std::string name, std::string date_from, std::string date_to, std::string format, std::string type = "");

    //Get file by id
    std::string Get_file_by_id(std::string id);

    //Settings
    //User event notification settings
    std::string Get_list_notification_by_event(std::string event);

    //User event notification settings
    std::string Get_list_notification();

    //Set notification settings
    /*
    event *     string(query)	An event name you want to subscribe.
    channel *   string(query)	A channel name you want to receive the notification through.
    value *     integer(query)	1 - to subscribe to the notifications of the given event in the specified channel, 0 - to remove subscription of the specified event in the specified channel 
    Available values : 0, 1
    */
    std::string Set_notification_settings(std::string event, std::string channel, std::string value);

    //Set notification settings
    std::string Set_notification_settings_one_request();

};



#endif // API_H
