// Api.h
#ifndef API_H
#define API_H

#include "Auth.h"
#include <string>
#include <vector>

class API
{
private:
    std::string Call(std::string method, bool authed, std::string path, std::string body);

public:
    API();
    ~API();
    Auth auth;
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






};



#endif // API_H
