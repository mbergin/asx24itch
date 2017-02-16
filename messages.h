#pragma once
#include <cstdint>

#include "enums.h"

// These are the messages as defined in the specification.
// They do not include the packet header or length.

namespace asx24itch
{

#pragma pack(push, 1)

    struct Instrument
    {
        uint8_t data[6];
    };

    struct Currency
    {
        uint8_t data[3];
    };

    struct Exchange
    {
        uint8_t data[6];
    };

    struct TimeMessage
    {
        MessageType messageType;
        uint32_t second;
    };

    struct SystemEvent
    {
        MessageType messageType;
        uint32_t timestamp;
        uint16_t tradeDate;
        EventCode eventCode;
    };

    struct FutureSymbolDirectory
    {
        MessageType messageType;
        uint32_t timestamp;
        uint16_t tradeDate;
        uint32_t contractNumber;
        Exchange exchange;
        Instrument instrument;
        ContractType contractType;
        uint16_t expiryYear;
        uint8_t expiryMonth;
        uint8_t priceDecimalPosition;
        uint32_t priceFractionalDenominator;
        uint16_t priceMinimumTick;
        uint32_t lastTradingDate;
        int32_t priorDaySettlement;
        FinancialType financialType;
        Currency currency;
        uint32_t lotSizeOrFaceValue;
        uint8_t maturityValue;
        uint16_t couponRate;
        uint8_t paymentsPerYear;
    };

    struct SpreadSymbolDirectory
    {
        MessageType messageType;
        uint32_t timestamp;
        uint16_t tradeDate;
        uint32_t contractNumber;
        Exchange exchange;
        ContractType contractType;
        uint32_t firstLegContractNumber;
        uint32_t secondLegContractNumber;
        uint8_t primaryRatio;
        uint8_t secondaryRatio;
        uint8_t priceDecimalPosition;
        uint32_t priceFractionalDenominator;
        uint16_t priceMinimumTick;
    };

    struct OptionSymbolDirectory
    {
        MessageType messageType;
        uint32_t timestamp;
        uint16_t tradeDate;
        uint32_t contractNumber;
        Exchange exchange;
        Instrument instrument;
        ContractType contractType;
        uint16_t expiryYear;
        uint8_t expiryMonth;
        OptionType optionType;
        uint32_t strike;
        uint32_t underlyingContractNumber;
        uint8_t priceDecimalPosition;
        uint32_t priceFractionalDenominator;
        uint16_t priceMinimumTick;
        uint8_t strikePriceDecimalPosition;
        uint32_t strikePriceFractionalDenominator;
        uint16_t strikePriceMinimumTick;
        uint32_t lastTradingDate;
        int32_t priorDaySettlement;
        uint32_t volatility;
        FinancialType financialType;
        Currency currency;
        uint32_t lotSizeOrFaceValue;
        uint8_t maturityValue;
        uint16_t couponRate;
        uint8_t paymentsPerYear;
        OptionActivated activated;
    };

    struct OrderBookState
    {
        MessageType messageType;
        uint32_t timestamp;
        uint16_t tradeDate;
        uint32_t contractNumber;
        TradingStatus tradingStatus;
    };

    struct OrderAdded
    {
        MessageType messageType;
        uint32_t timestamp;
        uint16_t tradeDate;
        uint32_t contractNumber;
        Side side;
        uint64_t orderNumber;
        uint32_t orderBookPriority;
        uint32_t quantity;
        int32_t price;
    };

    struct OrderReplaced
    {
        MessageType messageType;
        uint32_t timestamp;
        uint16_t tradeDate;
        uint32_t contractNumber;
        Side side;
        uint64_t orderNumber;
        uint32_t orderBookPriority;
        uint32_t quantity;
        int32_t price;
    };

    struct OrderVolumeCancelled
    {
        MessageType messageType;
        uint32_t timestamp;
        uint16_t tradeDate;
        uint32_t contractNumber;
        Side side;
        uint64_t orderNumber;
        uint32_t quantity;
    };

    struct OrderDeleted
    {
        MessageType messageType;
        uint32_t timestamp;
        uint16_t tradeDate;
        uint32_t contractNumber;
        Side side;
        uint64_t orderNumber;
    };

    struct ImpliedOrderAdded
    {
        MessageType messageType;
        uint32_t timestamp;
        uint16_t tradeDate;
        uint32_t contractNumber;
        Side side;
        uint64_t orderNumber;
        uint32_t orderBookPriority;
        uint32_t quantity;
        int32_t price;
    };

    struct ImpliedOrderReplaced
    {
        MessageType messageType;
        uint32_t timestamp;
        uint16_t tradeDate;
        uint32_t contractNumber;
        Side side;
        uint64_t orderNumber;
        uint32_t orderBookPriority;
        uint32_t quantity;
        int32_t price;
    };

    struct ImpliedOrderDeleted
    {
        MessageType messageType;
        uint32_t timestamp;
        uint16_t tradeDate;
        uint32_t contractNumber;
        Side side;
        uint64_t orderNumber;
    };

    struct CustomMarketOrderLeg
    {
        uint32_t contractNumber;
        Side side;
        uint16_t ratio;
        int32_t price;
    };

    struct CustomMarketOrderAdded
    {
        MessageType messageType;
        uint32_t timestamp;
        uint16_t tradeDate;
        uint64_t orderNumber;
        uint32_t orderBookPriority;
        uint32_t quantity;
        uint8_t legs;
        CustomMarketOrderLeg leg[6];
    };

    struct CustomMarketOrderReplaced
    {
        MessageType messageType;
        uint32_t timestamp;
        uint16_t tradeDate;
        uint64_t orderNumber;
        uint32_t orderBookPriority;
        uint32_t quantity;
    };

    struct CustomMarketOrderDeleted
    {
        MessageType messageType;
        uint32_t timestamp;
        uint16_t tradeDate;
        uint64_t orderNumber;
    };

    struct OrderExecuted
    {
        MessageType messageType;
        uint32_t timestamp;
        uint16_t tradeDate;
        uint32_t contractNumber;
        Side side;
        uint64_t orderNumber;
        uint32_t quantityRemaining;
        TradeType tradeType;
        uint32_t matchNumber;
        uint32_t executedQuantity;
        int32_t tradePrice;
    };

    struct OrderExecutedWithPrice
    {
        MessageType messageType;
        uint32_t timestamp;
        uint16_t tradeDate;
        uint32_t contractNumber;
        uint64_t buyingOrderNumber;
        uint32_t buyersQuantityRemaining;
        uint64_t sellingOrderNumber;
        uint32_t sellersQuantityRemaining;
        TradeType tradeType;
        uint32_t matchNumber;
        uint32_t executedQuantity;
        int32_t tradePrice;
    };

    struct SpreadExecuted
    {
        MessageType messageType;
        uint32_t timestamp;
        uint16_t tradeDate;
        uint32_t contractNumber;
        Side side;
        uint64_t orderNumber;
        uint32_t quantityRemaining;
        TradeType tradeType;
        uint32_t matchNumber;
        uint32_t executedQuantity;
        int32_t tradePrice;
        uint32_t tradedContractNumber;
        int32_t spreadTradePrice;
        Side tradeSideOfLeg;
        Printable printable;
    };

    struct Trade
    {
        MessageType messageType;
        uint32_t timestamp;
        uint16_t tradeDate;
        uint32_t buyersContractNumber;
        Side sideOfBuyer;
        uint64_t buyersOrderNumber;
        uint32_t buyersQuantityRemaining;
        uint32_t sellersContractNumber;
        Side sideOfSeller;
        uint64_t sellingOrderNumber;
        uint32_t sellerQuantityRemaining;
        TradeType tradeType;
        uint32_t matchNumber;
        uint32_t executedQuantity;
        int32_t tradePrice;
        uint32_t tradedContractNumber;
        int32_t spreadTradePrice;
        Printable printable;
    };

    struct CustomMarketExecuted
    {
        MessageType messageType;
        uint32_t timestamp;
        uint16_t tradeDate;
        uint64_t orderNumber;
        uint32_t quantityRemaining;
        TradeType tradeType;
        uint32_t matchNumber;
        uint32_t executedQuantity;
        int32_t tradePrice;
        uint32_t tradedContractNumber;
        Side tradeSideOfLeg;
        Printable printable;
    };

    struct CustomMarketTrade
    {
        MessageType messageType;
        uint32_t timestamp;
        uint16_t tradeDate;
        uint32_t contractNumber;
        Side side;
        uint64_t orderNumber;
        uint32_t quantityRemaining;
        uint64_t customMarketOrderNumber;
        uint32_t customMarketQuantityRemaining;
        TradeType tradeType;
        uint32_t matchNumber;
        uint32_t executedQuantity;
        int32_t tradePrice;
        uint32_t tradedContractNumber;
        Side tradeSideOfNonCustomOrder;
        Printable printable;
    };

    struct TradeCancellation
    {
        MessageType messageType;
        uint32_t timestamp;
        uint16_t tradeDate;
        uint32_t matchNumber;
    };

    struct EquilibriumPrice
    {
        MessageType messageType;
        uint32_t timestamp;
        uint16_t tradeDate;
        uint32_t contractNumber;
        int32_t equilibriumPrice;
        int32_t bestBidPrice;
        int32_t bestAskPrice;
        uint32_t bestBidQuantity;
        uint32_t bestAskQuantity;
    };

    struct OpenHighLowLastTradeAdjustment
    {
        MessageType messageType;
        uint32_t timestamp;
        uint16_t tradeDate;
        uint32_t contractNumber;
        int32_t openingTrade;
        int32_t highestTrade;
        int32_t lowestTrade;
        int32_t lastTrade;
        uint32_t lastVolume;
        uint32_t totalTradedVolume;
        uint32_t totalTrades;
        MarketUpdates marketUpdates;
    };

    struct MarketSettlement
    {
        MessageType messageType;
        uint32_t timestamp;
        uint16_t tradeDate;
        uint32_t contractNumber;
        int32_t settlementPrice;
        uint32_t volatility;
        SettlementType settlementType;
    };

    struct TextMessage
    {
        MessageType messageType;
        uint32_t timestamp;
        uint16_t tradeDate;
        uint8_t sourceId[6];
        uint8_t textMessage[100];
    };

    struct RequestForQuote
    {
        MessageType messageType;
        uint32_t timestamp;
        uint16_t tradeDate;
        uint32_t contractNumber;
        int32_t price;
        uint32_t quantity;
    };

    struct AnomalousOrderThresholdPublish
    {
        MessageType messageType;
        uint32_t timestamp;
        uint16_t tradeDate;
        uint32_t contractNumber;
        int32_t aotPrice;
        int32_t aotUpperPrice;
        int32_t aotLowerPrice;
        int32_t etrPrice;
        int32_t etrUpperPrice;
        int32_t etrLowerPrice;
    };

    struct VolumeAndOpenInterest
    {
        MessageType messageType;
        uint32_t timestamp;
        uint16_t tradeDate;
        uint32_t contractNumber;
        uint32_t cumulativeVolume;
        uint32_t openInterest;
        uint16_t voiTradeDate;
    };

#pragma pack(pop)

// If these asserts fire, the compiler probably doesn't regognise #pragma pack
// and you will need to provide a replacement to ensure there is no padding.
static_assert(sizeof TimeMessage == 5, "TimeMessage struct packing incorrect");
static_assert(sizeof SystemEvent == 8, "SystemEvent struct packing incorrect");
static_assert(sizeof FutureSymbolDirectory == 54, "FutureSymbolDirectory struct packing incorrect");
static_assert(sizeof SpreadSymbolDirectory == 35, "SpreadSymbolDirectory struct packing incorrect");
static_assert(sizeof OptionSymbolDirectory == 75, "OptionSymbolDirectory struct packing incorrect");
static_assert(sizeof OrderBookState == 12, "OrderBookState struct packing incorrect");
static_assert(sizeof OrderAdded == 32, "OrderAdded struct packing incorrect");
static_assert(sizeof OrderReplaced == 32, "OrderReplaced struct packing incorrect");
static_assert(sizeof OrderVolumeCancelled == 24, "OrderVolumeCancelled struct packing incorrect");
static_assert(sizeof OrderDeleted == 20, "OrderDeleted struct packing incorrect");
static_assert(sizeof ImpliedOrderAdded == 32, "ImpliedOrderAdded struct packing incorrect");
static_assert(sizeof ImpliedOrderReplaced == 32, "ImpliedOrderReplaced struct packing incorrect");
static_assert(sizeof ImpliedOrderDeleted == 20, "ImpliedOrderDeleted struct packing incorrect");
static_assert(sizeof CustomMarketOrderAdded == 90, "CustomMarketOrderAdded struct packing incorrect");
static_assert(sizeof CustomMarketOrderReplaced == 23, "CustomMarketOrderReplaced struct packing incorrect");
static_assert(sizeof CustomMarketOrderDeleted == 15, "CustomMarketOrderDeleted struct packing incorrect");
static_assert(sizeof OrderExecuted == 37, "OrderExecuted struct packing incorrect");
static_assert(sizeof OrderExecutedWithPrice == 48, "OrderExecutedWithPrice struct packing incorrect");
static_assert(sizeof SpreadExecuted == 47, "SpreadExecuted struct packing incorrect");
static_assert(sizeof Trade == 63, "Trade struct packing incorrect");
static_assert(sizeof CustomMarketExecuted == 38, "CustomMarketExecuted struct packing incorrect");
static_assert(sizeof CustomMarketTrade == 55, "CustomMarketTrade struct packing incorrect");
static_assert(sizeof TradeCancellation == 11, "TradeCancellation struct packing incorrect");
static_assert(sizeof EquilibriumPrice == 31, "EquilibriumPrice struct packing incorrect");
static_assert(sizeof OpenHighLowLastTradeAdjustment == 40, "OpenHighLowLastTradeAdjustment struct packing incorrect");
static_assert(sizeof MarketSettlement == 20, "MarketSettlement struct packing incorrect");
static_assert(sizeof TextMessage == 113, "TextMessage struct packing incorrect");
static_assert(sizeof RequestForQuote == 19, "RequestForQuote struct packing incorrect");
static_assert(sizeof AnomalousOrderThresholdPublish == 35, "AnomalousOrderThresholdPublish struct packing incorrect");
static_assert(sizeof VolumeAndOpenInterest == 21, "VolumeAndOpenInterest struct packing incorrect");

}
