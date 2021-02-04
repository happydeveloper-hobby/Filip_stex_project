#include "API.h"
#include <iostream>
#include "curl/curl.h"
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

using namespace rapidjson;

/* Used by API::Call to put websource into a string type */
static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
  ((std::string *)userp)->append((char *)contents, size * nmemb);
  return size * nmemb;
}

/* Uses libcurl to get Data From API */
std::string API::Call(std::string method, bool authed, std::string path, std::string body)
{
  CURL *curl;
  CURLcode res;
  std::string readBuffer;
  curl = curl_easy_init();
  if (curl)
  {
    struct curl_slist *chunk = NULL;
    curl_easy_setopt(curl, CURLOPT_URL, (uri + path).c_str());
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "libcurl/1.0");
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
    chunk = curl_slist_append(chunk, "Content-Type: application/json");
    if (authed)
    {
      // std::string time_stamp = auth.GetTimestamp();
      // std::string sign = auth.Sign(time_stamp, method, path, body);
      // chunk = curl_slist_append(chunk, ("CB-ACCESS-KEY: " + auth.Key).c_str());
      // chunk = curl_slist_append(chunk, ("CB-ACCESS-SIGN: " + sign).c_str());
      // chunk = curl_slist_append(chunk, ("CB-ACCESS-TIMESTAMP: " + time_stamp).c_str());
      // chunk = curl_slist_append(chunk, ("CB-ACCESS-PASSPHRASE: " + auth.Passphrase).c_str());
    }
    res = curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);
    if (method == "POST")
    {
      curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, -1L);
      curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body.c_str());
    }
    if (method == "DELETE")
    {
      curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "DELETE");
    }
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
    res = curl_easy_perform(curl);
    /* Check for errors */
    if (res != CURLE_OK)
      std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
    /* always cleanup */
    curl_easy_cleanup(curl);
    /* free the custom headers */
    curl_slist_free_all(chunk);
  }
  return readBuffer;
}

std::string API::Get_Buy_Price()
{
  std::string ret;
  std::string st = Call("GET", false, "/products/" + product_id + "/book", "");
  Document d;
  d.Parse(st.c_str());
  if (d.HasMember("message"))
  {
    assert(d["message"].IsString());
    std::cout << "(Get_Buy_Price) Message: " << d["message"].GetString() << std::endl;
  }
  if (d.HasMember("bids"))
  {
    assert(d["bids"].IsArray());
    const Value &c = d["bids"];
    assert(c[0].IsArray());
    const Value &b = c[0];
    assert(b[0].IsString());
    ret = b[0].GetString();
  }
  return ret;
}

double API::Get_Balance(std::string currency)
{
  double ret = 0;
  std::string txt = Call("GET", true, "/accounts", "");
  Document d;
  d.Parse(txt.c_str());
  assert(d.IsArray());
  for (SizeType i = 0; i < d.Size(); i++)
  {
    assert(d[i].HasMember("currency"));
    assert(d[i]["currency"].IsString());
    std::string cur = d[i]["currency"].GetString();
    if (cur == currency)
    {
      assert(d[i].HasMember("available"));
      assert(d[i]["available"].IsString());
      ret = std::stod(d[i]["available"].GetString());
      return ret;
    }
  }
  return ret;
}

std::string API::Place_Limit_Order(std::string side, std::string price, std::string size)
{
  std::string order_id;
  Document d;
  d.SetObject();
  rapidjson::Document::AllocatorType &allocator = d.GetAllocator();

  /* adds type */
  d.AddMember("type", "limit", allocator);

  /* Adds the Size */
  Value v_side;
  v_side = StringRef(side.c_str());
  d.AddMember("side", v_side, allocator);

  /* Adds the Product id */
  Value v_product_id;
  v_product_id = StringRef(product_id.c_str());
  d.AddMember("product_id", v_product_id, allocator);

  /* Adds the price (USD) */
  Value v_price;
  v_price = StringRef(price.c_str());
  d.AddMember("price", v_price, allocator);

  /* Adds the size (BTC, ETH, LTC) */
  Value v_size;
  v_size = StringRef(size.c_str());
  d.AddMember("size", v_size, allocator);

  /* Gets the Order to be a maker and not a taker */
  d.AddMember("post_only", true, allocator);

  /* creates the string in json */
  StringBuffer strbuf;
  Writer<StringBuffer> writer(strbuf);
  d.Accept(writer);
  std::string returned = Call("POST", true, "/orders", strbuf.GetString());
  // std::cout << "returned = " << returned << std::endl;
  // std::cout << "returned strbuf.GetString = " << strbuf.GetString() << std::endl;
  Document d_1;
  d_1.Parse(returned.c_str());
  // std::cout << "returned.c_str() = " << returned.c_str() << std::endl;
  if (d_1.HasMember("id"))
  {
    assert(d_1["id"].IsString());
    order_id = d_1["id"].GetString();
  }
  if (d_1.HasMember("message"))
  {
    assert(d_1["message"].IsString());
    std::cout << "(Limit_Order) Message: " << d_1["message"].GetString() << std::endl;
  }
  return order_id;
}

//Public
// Available Currencies
std::string API::Get_list_currencies()
{
  std::string res = Call("GET", false, "/public/currencies", "");
  std::cout << res << std::endl;
  return "";
}

// Get currency info
std::string API::Get_currency_info(std::string currencyId)
{
  std::string url = "/public/currencies/" + currencyId;
  std::string res = Call("GET", false, url, "");
  std::cout << res << std::endl;
  return "";
}

// Available markets
std::string API::Get_list_markets()
{
  std::string url = "/public/markets/";
  std::string res = Call("GET", false, url, "");
  std::cout << res << std::endl;
  return "";
}

// Get list of all avialable currency pairs groups
std::string API::Get_list_currency_pairs_groups()
{
  std::string url = "/public/pairs-groups";
  std::string res = Call("GET", false, url, "");
  std::cout << res << std::endl;
  return "";
}

// Available currency pairs
std::string API::Get_currency_pairs(std::string code)
{
  std::string url = "/public/currency_pairs/list/" + code;
  std::string res = Call("GET", false, url, "");
  std::cout << res << std::endl;
  return "";
}

// Available currency pairs for a given group
std::string API::Get_currency_pairs_given_group(std::string currencyPairGroupId)
{
  std::string url = "/public/currency_pairs/group/" + currencyPairGroupId;
  std::string res = Call("GET", false, url, "");
  std::cout << res << std::endl;
  return "";
}

// Get currency pair information
std::string API::Get_currency_pair_information(std::string currencyPairId)
{
  std::string url = "/public/currency_pairs/" + currencyPairId;
  std::string res = Call("GET", false, url, "");
  std::cout << res << std::endl;
  return "";
}

// Tickers list for all currency pairs
std::string API::Get_ticker_list_currency_pairs()
{
  std::string url = "/public/ticker";
  std::string res = Call("GET", false, url, "");
  std::cout << res << std::endl;
  return "";
}

// Ticker for currency pair
std::string API::Get_ticker_currency_pair(std::string currencyPairId)
{
  std::string url = "/public/ticker/" + currencyPairId;
  std::string res = Call("GET", false, url, "");
  std::cout << res << std::endl;
  return "";
}

// Trades for given currency pair
std::string API::Get_trades_currency_pair(std::string currencyPairId, std::string sort , std::string from , std::string till , std::string limit, std::string offset)
{
  std::string url = "/public/trades/" + currencyPairId;
  url += "?sort=" + sort;
  url += "&from=" + from;
  url += "&till=" + till;
  url += "&limit=" + limit;
  std::string res = Call("GET", false, url, "");
  std::cout << res << std::endl;
  return "";
}

// Orderbook for given currency pair
std::string API::Get_orderbook_currency_pair(std::string currencyPairId, std::string limit_bids, std::string limit_asks)
{
  std::string url = "/public/orderbook/" + currencyPairId;
  url += "?limit_bids=" + limit_bids;
  url += "&limit_asks=" + limit_asks;
  std::string res = Call("GET", false, url, "");
  std::cout << res << std::endl;
  return "";
}

// A list of candles for given currency pair
std::string API::Get_list_candles_currency_pair(std::string currencyPairId, std::string candlesType, std::string timeStart, std::string timeEnd, std::string limit, std::string offset)
{
  std::string url = "/public/trades/" + currencyPairId + "/" + candlesType;
  url += "?timeStart=" + timeStart;
  url += "&timeEnd=" + timeEnd;
  url += "&limit=" + limit;
  url += "&offset=" + offset;
  std::string res = Call("GET", false, url, "");
  std::cout << res << std::endl;
  return "";
}

// Available Deposit Statuses
std::string API::Get_list_deposit_statuses()
{
  std::string url = "/public/deposit-statuses";
  std::string res = Call("GET", false, url, "");
  std::cout << res << std::endl;
  return "";
}

// Get deposit status info
std::string API::Get_deposit_status(std::string statusId)
{
  std::string url = "/public/deposit-statuses/" + statusId;
  std::string res = Call("GET", false, url, "");
  std::cout << res << std::endl;
  return "";
}

// Available Withdrawal Statuses
std::string API::Get_list_withdrawal_statuses()
{
  std::string url = "/public/withdrawal-statuses";
  std::string res = Call("GET", false, url, "");
  std::cout << res << std::endl;
  return "";
}

// Get status info
std::string API::Get_withdrawal_status(std::string statusId)
{
  std::string url = "/public/withdrawal-statuses/" + statusId;
  std::string res = Call("GET", false, url, "");
  std::cout << res << std::endl;
  return "";
}

// Test API is working and get server time
std::string API::ping()
{
  std::string url = "/public/ping";
  std::string res = Call("GET", false, url, "");
  std::cout << res << std::endl;
  return "";
}

// Shows the official mobile applications data
std::string API::Get_mobile_version()
{
  std::string url = "/public/mobile-versions";
  std::string res = Call("GET", false, url, "");
  std::cout << res << std::endl;
  return "";
}

// Get the last 20 posts (stex.com) on Twitter
std::string API::Get_twitter()
{
  std::string url = "/public/twitter";
  std::string res = Call("GET", false, url, "");
  std::cout << res << std::endl;
  return "";
}








API::API()
{
  curl_global_init(CURL_GLOBAL_DEFAULT);
}

API::~API()
{
  curl_global_cleanup();
}
