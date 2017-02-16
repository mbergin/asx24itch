#include <iostream>
#include <string>
#include "parse.h"
#include "dump.h"

int main()
{
    // An "Order Added" message
    const char msg[] = {
        'A',                                                             // messageType: OrderAdded
        '\xFF', '\xEE', '\xDD', '\xCC',                                 // timestamp: 4293844428
        '\xFF', '\xEE',                                                 // tradeDate: 65518
        '\xFF', '\xEE', '\xDD', '\xCC',                                 // contractNumber: 4293844428
        'B',                                                            // side: Buy
        '\xFF', '\xEE', '\xDD', '\xCC', '\xBB', '\xAA', '\x99', '\x88', // orderNumber: 18441921395520346504
        '\xFF', '\xEE', '\xDD', '\xCC',                                 // orderBookPriority: 4293844428
        '\xFF', '\xEE', '\xDD', '\xCC',                                 // quantity: 4293844428
        '\xFF', '\xEE', '\xDD', '\xCC'                                  // price: -1122868
    };

    // Parse and print out a human-readable version of the message
    auto status = asx24itch::parse(msg, sizeof msg, [](const auto& msg)
    {
        std::cout << msg << std::endl;
    });
    return status == asx24itch::ParseStatus::OK ? 0 : 1;
}
