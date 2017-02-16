#pragma once
#include <cstdint>

// Type-safe representations of the single character alphanumeric codes used in the spec.
// See the specification for documentation.
namespace asx24itch
{
	enum class ContractType : uint8_t
	{
		FutureOrForward = 'F',
		RegularOption = 'O',
		EquityOption = 'E',
		SingleSessionOption = 'N',
		CalendarOrIntraSpread = 'S',
		ArbitrageOrInterSpread = 'A',
		EquityCFDOrShareFuture = 'D'
	};

	enum class EventCode : uint8_t
	{
		Open = 'O',
		Start = 'S',
		Close = 'C',
		Pause = 'P',
		Resume = 'R'
	};

	enum class FinancialType : uint8_t
	{
		Commodity = 'C',
		CFD = 'D',
		Equity = 'E',
		GovernmentBond = 'X',
		BankBill = 'B'
	};

	enum class MessageType : uint8_t
	{
		TimeMessage = 'T',
		SystemEvent = 'S',
		FutureSymbolDirectory = 'f',
		SpreadSymbolDirectory = 'g',
		OptionSymbolDirectory = 'h',
		OrderBookState = 'O',
		OrderAdded = 'A',
		OrderReplaced = 'U',
		OrderVolumeCancelled = 'X',
		OrderDeleted = 'D',
		ImpliedOrderAdded = 'j',
		ImpliedOrderReplaced = 'l',
		ImpliedOrderDeleted = 'k',
		CustomMarketOrderAdded = 'm',
		CustomMarketOrderReplaced = 'n',
		CustomMarketOrderDeleted = 'r',
		OrderExecuted = 'E',
		OrderExecutedWithPrice = 'C',
		SpreadExecuted = 'e',
		TradeSpreadExecutionChain = 'P',
		CustomMarketExecuted = 'u',
		CustomMarketTrade = 'p',
		TradeCancellation = 'B',
		EquilibriumPrice = 'Z',
		OpenHighLowLastTradeAdjustment = 't',
		MarketSettlement = 'Y',
		TextMessage = 'x',
		RequestForQuote = 'q',
		SnapshotComplete = 'G',
		AnomalousOrderThresholdPublish = 'W',
		VolumeAndOpenInterest = 'V'
	};

	enum class OptionActivated : uint8_t
	{
		Activated = 'Y',
		Deactivated = 'N'
	};

	enum OptionType : uint8_t
	{
		Put = 'P',
		Call = 'C'
	};

	enum class Printable : uint8_t
	{
		IsPrintable = 'Y',
		NonPrintable = 'N'
	};

	enum class SettlementType : uint8_t
	{
		Interim = 'I',
		Final = 'F',
		Adjustment = 'A'
	};

	enum class Side : uint8_t
	{
		Buy = 'B',
		Sell = 'S',
		Undefined = ' ',
	};

	enum class TradeType : uint8_t
	{
		Normal = 'T',
		Sweeping = 'W',
		Levelling = 'L',
		SpreadToUnderlying = 'S',
		IntraSpread = 'R',
		InterSpread = 'Q',
		Custom = 'U',
		CrossNormal = 't',
		CrossSweeping = 'w',
		CrossLevelling = 'l',
		CrossSpreadToUnderlying = 's',
		CrossIntraSpread = 'r',
		CrossInterSpread = 'q',
		CrossCustom = 'u'
	};

	enum class TradingStatus : uint8_t
	{
		Pending = 'p',
		Halted = 'H',
		PreOpen = 'P',
		Closed = 'C',
		Levelling = 'l',
		Locked = 'L',
		Opened = 'O',
		EndLockOrUnavailable = 'U',
		PrePriceDiscovery = 'd',
		Inactive = 'I',
		PriceDiscovery = 'D',
		Activated = 'A',
		RegulatoryHalt = 'R'
	};

	enum class MarketUpdates : uint8_t
	{
		OpeningTradePrice = 0x01,
		HighestTradedPrice = 0x02,
		LowestTradedPrice = 0x04,
		TotalTradedVolumeAndTotalTrades = 0x08,
		LastTradedPrice = 0x10,
		LastTradedVolume = 0x20
	};
}
