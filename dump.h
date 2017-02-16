#pragma once
#include "messages.h"
#include <iostream>

namespace asx24itch
{
	inline std::ostream& operator<<(std::ostream& os, Currency currency) {
		os.write(reinterpret_cast<char*>(currency.data), sizeof currency.data);
		return os;
	}

	inline std::ostream& operator<<(std::ostream& os, Instrument instrument) {
		os.write(reinterpret_cast<char*>(instrument.data), sizeof instrument.data);
		return os;
	}

	inline std::ostream& operator<<(std::ostream& os, Exchange exchange) {
		os.write(reinterpret_cast<char*>(exchange.data), sizeof exchange.data);
		return os;
	}

	inline std::ostream& operator<<(std::ostream& os, ContractType type)
	{
		auto text = "<unknown>";
		switch (type)
		{
		case ContractType::FutureOrForward: text = "FutureOrForward"; break;
		case ContractType::RegularOption: text = "RegularOption"; break;
		case ContractType::EquityOption: text = "EquityOption"; break;
		case ContractType::SingleSessionOption: text = "SingleSessionOption"; break;
		case ContractType::CalendarOrIntraSpread: text = "CalendarOrIntraSpread"; break;
		case ContractType::ArbitrageOrInterSpread: text = "ArbitrageOrInterSpread"; break;
		case ContractType::EquityCFDOrShareFuture: text = "EquityCFDOrShareFuture"; break;
		}
		os << text;
		return os;
	}

	inline std::ostream& operator<<(std::ostream& os, EventCode code)
	{
		auto text = "<unknown>";
		switch (code)
		{
		case EventCode::Open: text = "Open"; break;
		case EventCode::Start: text = "Start"; break;
		case EventCode::Close: text = "Close"; break;
		case EventCode::Pause: text = "Pause"; break;
		case EventCode::Resume: text = "Resume"; break;
		}
		os << text;
		return os;
	}


	inline std::ostream& operator<<(std::ostream& os, FinancialType type)
	{
		auto text = "<unknown>";
		switch (type)
		{
		case FinancialType::Commodity: text = "Commodity"; break;
		case FinancialType::CFD: text = "CFD"; break;
		case FinancialType::Equity: text = "Equity"; break;
		case FinancialType::GovernmentBond: text = "GovernmentBond"; break;
		case FinancialType::BankBill: text = "BankBill"; break;
		}
		os << text;
		return os;
	}

	inline std::ostream& operator<<(std::ostream& os, MessageType type)
	{
		auto text = "<unknown>";
		switch (type)
		{
		case MessageType::TimeMessage: text = "TimeMessage"; break;
		case MessageType::SystemEvent: text = "SystemEvent"; break;
		case MessageType::FutureSymbolDirectory: text = "FutureSymbolDirectory"; break;
		case MessageType::SpreadSymbolDirectory: text = "SpreadSymbolDirectory"; break;
		case MessageType::OptionSymbolDirectory: text = "OptionSymbolDirectory"; break;
		case MessageType::OrderBookState: text = "OrderBookState"; break;
		case MessageType::OrderAdded: text = "OrderAdded"; break;
		case MessageType::OrderReplaced: text = "OrderReplaced"; break;
		case MessageType::OrderVolumeCancelled: text = "OrderVolumeCancelled"; break;
		case MessageType::OrderDeleted: text = "OrderDeleted"; break;
		case MessageType::ImpliedOrderAdded: text = "ImpliedOrderAdded"; break;
		case MessageType::ImpliedOrderReplaced: text = "ImpliedOrderReplaced"; break;
		case MessageType::ImpliedOrderDeleted: text = "ImpliedOrderDeleted"; break;
		case MessageType::CustomMarketOrderAdded: text = "CustomMarketOrderAdded"; break;
		case MessageType::CustomMarketOrderReplaced: text = "CustomMarketOrderReplaced"; break;
		case MessageType::CustomMarketOrderDeleted: text = "CustomMarketOrderDeleted"; break;
		case MessageType::OrderExecuted: text = "OrderExecuted"; break;
		case MessageType::OrderExecutedWithPrice: text = "OrderExecutedWithPrice"; break;
		case MessageType::SpreadExecuted: text = "SpreadExecuted"; break;
		case MessageType::TradeSpreadExecutionChain: text = "TradeSpreadExecutionChain"; break;
		case MessageType::CustomMarketExecuted: text = "CustomMarketExecuted"; break;
		case MessageType::CustomMarketTrade: text = "CustomMarketTrade"; break;
		case MessageType::TradeCancellation: text = "TradeCancellation"; break;
		case MessageType::EquilibriumPrice: text = "EquilibriumPrice"; break;
		case MessageType::OpenHighLowLastTradeAdjustment: text = "OpenHighLowLastTradeAdjustment"; break;
		case MessageType::MarketSettlement: text = "MarketSettlement"; break;
		case MessageType::TextMessage: text = "TextMessage"; break;
		case MessageType::RequestForQuote: text = "RequestForQuote"; break;
		case MessageType::SnapshotComplete: text = "SnapshotComplete"; break;
		case MessageType::AnomalousOrderThresholdPublish: text = "AnomalousOrderThresholdPublish"; break;
		case MessageType::VolumeAndOpenInterest: text = "VolumeAndOpenInterest"; break;
		}
		os << text;
		return os;
	};

	inline std::ostream& operator<<(std::ostream& os, OptionActivated type)
	{
		auto text = "<unknown>";
		switch (type)
		{
		case OptionActivated::Activated: text = "Activated"; break;
		case OptionActivated::Deactivated: text = "Deactivated"; break;
		}
		os << text;
		return os;
	}

	inline std::ostream& operator<<(std::ostream& os, OptionType type)
	{
		auto text = "<unknown>";
		switch (type)
		{
		case OptionType::Put: text = "Put"; break;
		case OptionType::Call: text = "Call"; break;
		}
		os << text;
		return os;
	}

	inline std::ostream& operator<<(std::ostream& os, Printable type)
	{
		auto text = "<unknown>";
		switch (type)
		{
		case Printable::IsPrintable: text = "IsPrintable"; break;
		case Printable::NonPrintable: text = "NonPrintable"; break;
		}
		os << text;
		return os;
	}

	inline std::ostream& operator<<(std::ostream& os, SettlementType type)
	{
		auto text = "<unknown>";
		switch (type)
		{
		case SettlementType::Interim: text = "Interim"; break;
		case SettlementType::Final: text = "Final"; break;
		case SettlementType::Adjustment: text = "Adjustment"; break;
		}
		os << text;
		return os;
	}

	inline std::ostream& operator<<(std::ostream& os, Side type)
	{
		auto text = "<unknown>";
		switch (type)
		{
		case Side::Buy: text = "Buy"; break;
		case Side::Sell: text = "Sell"; break;
		}
		os << text;
		return os;
	}

	inline std::ostream& operator<<(std::ostream& os, TradeType type)
	{
		auto text = "<unknown>";
		switch (type)
		{
		case TradeType::Normal: text = "Normal"; break;
		case TradeType::Sweeping: text = "Sweeping"; break;
		case TradeType::Levelling: text = "Levelling"; break;
		case TradeType::SpreadToUnderlying: text = "SpreadToUnderlying"; break;
		case TradeType::IntraSpread: text = "IntraSpread"; break;
		case TradeType::InterSpread: text = "InterSpread"; break;
		case TradeType::Custom: text = "Custom"; break;
		case TradeType::CrossNormal: text = "CrossNormal"; break;
		case TradeType::CrossSweeping: text = "CrossSweeping"; break;
		case TradeType::CrossLevelling: text = "CrossLevelling"; break;
		case TradeType::CrossSpreadToUnderlying: text = "CrossSpreadToUnderlying"; break;
		case TradeType::CrossIntraSpread: text = "CrossIntraSpread"; break;
		case TradeType::CrossInterSpread: text = "CrossInterSpread"; break;
		case TradeType::CrossCustom: text = "CrossCustom"; break;
		}
		os << text;
		return os;
	}

	inline std::ostream& operator<<(std::ostream& os, TradingStatus type)
	{
		auto text = "<unknown>";
		switch (type)
		{
		case TradingStatus::Pending: text = "Pending"; break;
		case TradingStatus::Halted: text = "Halted"; break;
		case TradingStatus::PreOpen: text = "PreOpen"; break;
		case TradingStatus::Closed: text = "Closed"; break;
		case TradingStatus::Levelling: text = "Levelling"; break;
		case TradingStatus::Locked: text = "Locked"; break;
		case TradingStatus::Opened: text = "Opened"; break;
		case TradingStatus::EndLockOrUnavailable: text = "EndLockOrUnavailable"; break;
		case TradingStatus::PrePriceDiscovery: text = "PrePriceDiscovery"; break;
		case TradingStatus::Inactive: text = "Inactive"; break;
		case TradingStatus::PriceDiscovery: text = "PriceDiscovery"; break;
		case TradingStatus::Activated: text = "Activated"; break;
		case TradingStatus::RegulatoryHalt: text = "RegulatoryHalt"; break;
		}
		os << text;
		return os;
	}


	inline std::ostream& operator<<(std::ostream& os, const TimeMessage& msg)
	{
		os << "messageType: " << msg.messageType << "\n";
		os << "second: " << msg.second << "\n";
		return os;
	};

	inline std::ostream& operator<<(std::ostream& os, const SystemEvent& msg)
	{
		os << "messageType: " << msg.messageType << "\n";
		os << "timestamp: " << msg.timestamp << "\n";
		os << "tradeDate: " << msg.tradeDate << "\n";
		os << "eventCode: " << msg.eventCode << "\n";
		return os;
	};

	inline std::ostream& operator<<(std::ostream& os, const FutureSymbolDirectory& msg)
	{
		os << "messageType: " << msg.messageType << "\n";
		os << "timestamp: " << msg.timestamp << "\n";
		os << "tradeDate: " << msg.tradeDate << "\n";
		os << "contractNumber: " << msg.contractNumber << "\n";
		os << "exchange: " << msg.exchange << "\n";
		os << "instrument: " << msg.instrument << "\n";
		os << "contractType: " << msg.contractType << "\n";
		os << "expiryYear: " << msg.expiryYear << "\n";
		os << "expiryMonth: " << uint32_t(msg.expiryMonth) << "\n";
		os << "priceDecimalPosition: " << uint32_t(msg.priceDecimalPosition) << "\n";
		os << "priceFractionalDenominator: " << msg.priceFractionalDenominator << "\n";
		os << "priceMinimumTick: " << msg.priceMinimumTick << "\n";
		os << "lastTradingDate: " << msg.lastTradingDate << "\n";
		os << "priorDaySettlement: " << msg.priorDaySettlement << "\n";
		os << "financialType: " << msg.financialType << "\n";
		os << "currency: " << msg.currency << "\n";
		os << "lotSizeOrFaceValue: " << msg.lotSizeOrFaceValue << "\n";
		os << "maturityValue: " << uint32_t(msg.maturityValue) << "\n";
		os << "couponRate: " << msg.couponRate << "\n";
		os << "paymentsPerYear: " << uint32_t(msg.paymentsPerYear) << "\n";
		return os;
	};

	inline std::ostream& operator<<(std::ostream& os, const SpreadSymbolDirectory& msg)
	{
		os << "messageType: " << msg.messageType << "\n";
		os << "timestamp: " << msg.timestamp << "\n";
		os << "tradeDate: " << msg.tradeDate << "\n";
		os << "contractNumber: " << msg.contractNumber << "\n";
		os << "exchange: " << msg.exchange << "\n";
		os << "contractType: " << msg.contractType << "\n";
		os << "firstLegContractNumber: " << msg.firstLegContractNumber << "\n";
		os << "secondLegContractNumber: " << msg.secondLegContractNumber << "\n";
		os << "primaryRatio: " << uint32_t(msg.primaryRatio) << "\n";
		os << "secondaryRatio: " << uint32_t(msg.secondaryRatio) << "\n";
		os << "priceDecimalPosition: " << uint32_t(msg.priceDecimalPosition) << "\n";
		os << "priceFractionalDenominator: " << msg.priceFractionalDenominator << "\n";
		os << "priceMinimumTick: " << msg.priceMinimumTick << "\n";
		return os;
	};

	inline std::ostream& operator<<(std::ostream& os, const OptionSymbolDirectory& msg)
	{
		os << "timestamp: " << msg.timestamp << "\n";
		os << "tradeDate: " << msg.tradeDate << "\n";
		os << "contractNumber: " << msg.contractNumber << "\n";
		os << "exchange: " << msg.exchange << "\n";
		os << "instrument: " << msg.instrument << "\n";
		os << "contractType: " << msg.contractType << "\n";
		os << "expiryYear: " << msg.expiryYear << "\n";
		os << "expiryMonth: " << uint32_t(msg.expiryMonth) << "\n";
		os << "optionType: " << msg.optionType << "\n";
		os << "strike: " << msg.strike << "\n";
		os << "underlyingContractNumber: " << msg.underlyingContractNumber << "\n";
		os << "priceDecimalPosition: " << uint32_t(msg.priceDecimalPosition) << "\n";
		os << "priceFractionalDenominator: " << msg.priceFractionalDenominator << "\n";
		os << "priceMinimumTick: " << msg.priceMinimumTick << "\n";
		os << "strikePriceDecimalPosition: " << uint32_t(msg.strikePriceDecimalPosition) << "\n";
		os << "strikePriceFractionalDenominator: " << msg.strikePriceFractionalDenominator << "\n";
		os << "strikePriceMinimumTick: " << msg.strikePriceMinimumTick << "\n";
		os << "lastTradingDate: " << msg.lastTradingDate << "\n";
		os << "priorDaySettlement: " << msg.priorDaySettlement << "\n";
		os << "volatility: " << msg.volatility << "\n";
		os << "financialType: " << msg.financialType << "\n";
		os << "currency: " << msg.currency << "\n";
		os << "lotSizeOrFaceValue: " << msg.lotSizeOrFaceValue << "\n";
		os << "maturityValue: " << uint32_t(msg.maturityValue) << "\n";
		os << "couponRate: " << msg.couponRate << "\n";
		os << "paymentsPerYear: " << uint32_t(msg.paymentsPerYear) << "\n";
		os << "activated: " << msg.activated << "\n";
		return os;
	};

	inline std::ostream& operator<<(std::ostream& os, const OrderBookState& msg)
	{
		os << "messageType: " << msg.messageType << "\n";
		os << "timestamp: " << msg.timestamp << "\n";
		os << "tradeDate: " << msg.tradeDate << "\n";
		os << "contractNumber: " << msg.contractNumber << "\n";
		os << "tradingStatus: " << msg.tradingStatus << "\n";
		return os;
	};

	inline std::ostream& operator<<(std::ostream& os, const OrderAdded& msg)
	{
		os << "messageType: " << msg.messageType << "\n";
		os << "timestamp: " << msg.timestamp << "\n";
		os << "tradeDate: " << msg.tradeDate << "\n";
		os << "contractNumber: " << msg.contractNumber << "\n";
		os << "side: " << msg.side << "\n";
		os << "orderNumber: " << msg.orderNumber << "\n";
		os << "orderBookPriority: " << msg.orderBookPriority << "\n";
		os << "quantity: " << msg.quantity << "\n";
		os << "price: " << msg.price << "\n";
		return os;
	};

	inline std::ostream& operator<<(std::ostream& os, const OrderReplaced& msg)
	{
		os << "messageType: " << msg.messageType << "\n";
		os << "timestamp: " << msg.timestamp << "\n";
		os << "tradeDate: " << msg.tradeDate << "\n";
		os << "contractNumber: " << msg.contractNumber << "\n";
		os << "side: " << msg.side << "\n";
		os << "orderNumber: " << msg.orderNumber << "\n";
		os << "orderBookPriority: " << msg.orderBookPriority << "\n";
		os << "quantity: " << msg.quantity << "\n";
		os << "price: " << msg.price << "\n";
		return os;
	};

	inline std::ostream& operator<<(std::ostream& os, const OrderVolumeCancelled& msg)
	{
		os << "messageType: " << msg.messageType << "\n";
		os << "timestamp: " << msg.timestamp << "\n";
		os << "tradeDate: " << msg.tradeDate << "\n";
		os << "contractNumber: " << msg.contractNumber << "\n";
		os << "side: " << msg.side << "\n";
		os << "orderNumber: " << msg.orderNumber << "\n";
		os << "quantity: " << msg.quantity << "\n";
		return os;
	};

	inline std::ostream& operator<<(std::ostream& os, const OrderDeleted& msg)
	{
		os << "messageType: " << msg.messageType << "\n";
		os << "timestamp: " << msg.timestamp << "\n";
		os << "tradeDate: " << msg.tradeDate << "\n";
		os << "contractNumber: " << msg.contractNumber << "\n";
		os << "side: " << msg.side << "\n";
		os << "orderNumber: " << msg.orderNumber << "\n";
		return os;
	};

	inline std::ostream& operator<<(std::ostream& os, const ImpliedOrderAdded& msg)
	{
		os << "messageType: " << msg.messageType << "\n";
		os << "timestamp: " << msg.timestamp << "\n";
		os << "tradeDate: " << msg.tradeDate << "\n";
		os << "contractNumber: " << msg.contractNumber << "\n";
		os << "side: " << msg.side << "\n";
		os << "orderNumber: " << msg.orderNumber << "\n";
		os << "orderBookPriority: " << msg.orderBookPriority << "\n";
		os << "quantity: " << msg.quantity << "\n";
		os << "price: " << msg.price << "\n";
		return os;
	};

	inline std::ostream& operator<<(std::ostream& os, const ImpliedOrderReplaced& msg)
	{
		os << "messageType: " << msg.messageType << "\n";
		os << "timestamp: " << msg.timestamp << "\n";
		os << "tradeDate: " << msg.tradeDate << "\n";
		os << "contractNumber: " << msg.contractNumber << "\n";
		os << "side: " << msg.side << "\n";
		os << "orderNumber: " << msg.orderNumber << "\n";
		os << "orderBookPriority: " << msg.orderBookPriority << "\n";
		os << "quantity: " << msg.quantity << "\n";
		os << "price: " << msg.price << "\n";
		return os;
	};

	inline std::ostream& operator<<(std::ostream& os, const ImpliedOrderDeleted& msg)
	{
		os << "messageType: " << msg.messageType << "\n";
		os << "timestamp: " << msg.timestamp << "\n";
		os << "tradeDate: " << msg.tradeDate << "\n";
		os << "contractNumber: " << msg.contractNumber << "\n";
		os << "side: " << msg.side << "\n";
		os << "orderNumber: " << msg.orderNumber << "\n";
		return os;
	};

	inline std::ostream& operator<<(std::ostream& os, const CustomMarketOrderAdded& msg)
	{
		os << "messageType: " << msg.messageType << "\n";
		os << "timestamp: " << msg.timestamp << "\n";
		os << "tradeDate: " << msg.tradeDate << "\n";
		os << "orderNumber: " << msg.orderNumber << "\n";
		os << "orderBookPriority: " << msg.orderBookPriority << "\n";
		os << "quantity: " << msg.quantity << "\n";
		os << "legs: " << uint32_t(msg.legs) << "\n";
		for (int i = 0; i < msg.legs; ++i)
		{
			os << "leg[" << i << "]:\n";
			os << "    contractNumber: " << msg.leg[i].contractNumber << "\n";
			os << "    side: " << msg.leg[i].side << "\n";
			os << "    ratio: " << msg.leg[i].ratio << "\n";
			os << "    price: " << msg.leg[i].price << "\n";
		}
		return os;
	};

	inline std::ostream& operator<<(std::ostream& os, const CustomMarketOrderReplaced& msg)
	{
		os << "messageType: " << msg.messageType << "\n";
		os << "timestamp: " << msg.timestamp << "\n";
		os << "tradeDate: " << msg.tradeDate << "\n";
		os << "orderNumber: " << msg.orderNumber << "\n";
		os << "orderBookPriority: " << msg.orderBookPriority << "\n";
		os << "quantity: " << msg.quantity << "\n";
		return os;
	};

	inline std::ostream& operator<<(std::ostream& os, const CustomMarketOrderDeleted& msg)
	{
		os << "messageType: " << msg.messageType << "\n";
		os << "timestamp: " << msg.timestamp << "\n";
		os << "tradeDate: " << msg.tradeDate << "\n";
		os << "orderNumber: " << msg.orderNumber << "\n";
		return os;
	};

	inline std::ostream& operator<<(std::ostream& os, const OrderExecuted& msg)
	{
		os << "messageType: " << msg.messageType << "\n";
		os << "timestamp: " << msg.timestamp << "\n";
		os << "tradeDate: " << msg.tradeDate << "\n";
		os << "contractNumber: " << msg.contractNumber << "\n";
		os << "side: " << msg.side << "\n";
		os << "orderNumber: " << msg.orderNumber << "\n";
		os << "quantityRemaining: " << msg.quantityRemaining << "\n";
		os << "tradeType: " << msg.tradeType << "\n";
		os << "matchNumber: " << msg.matchNumber << "\n";
		os << "executedQuantity: " << msg.executedQuantity << "\n";
		os << "tradePrice: " << msg.tradePrice << "\n";
		return os;
	};

	inline std::ostream& operator<<(std::ostream& os, const OrderExecutedWithPrice& msg)
	{
		os << "messageType: " << msg.messageType << "\n";
		os << "timestamp: " << msg.timestamp << "\n";
		os << "tradeDate: " << msg.tradeDate << "\n";
		os << "contractNumber: " << msg.contractNumber << "\n";
		os << "buyingOrderNumber: " << msg.buyingOrderNumber << "\n";
		os << "buyersQuantityRemaining: " << msg.buyersQuantityRemaining << "\n";
		os << "sellingOrderNumber: " << msg.sellingOrderNumber << "\n";
		os << "sellersQuantityRemaining: " << msg.sellersQuantityRemaining << "\n";
		os << "tradeType: " << msg.tradeType << "\n";
		os << "matchNumber: " << msg.matchNumber << "\n";
		os << "executedQuantity: " << msg.executedQuantity << "\n";
		os << "tradePrice: " << msg.tradePrice << "\n";
		return os;
	};

	inline std::ostream& operator<<(std::ostream& os, const SpreadExecuted& msg)
	{
		os << "messageType: " << msg.messageType << "\n";
		os << "timestamp: " << msg.timestamp << "\n";
		os << "tradeDate: " << msg.tradeDate << "\n";
		os << "contractNumber: " << msg.contractNumber << "\n";
		os << "side: " << msg.side << "\n";
		os << "orderNumber: " << msg.orderNumber << "\n";
		os << "quantityRemaining: " << msg.quantityRemaining << "\n";
		os << "tradeType: " << msg.tradeType << "\n";
		os << "matchNumber: " << msg.matchNumber << "\n";
		os << "executedQuantity: " << msg.executedQuantity << "\n";
		os << "tradePrice: " << msg.tradePrice << "\n";
		os << "tradedContractNumber: " << msg.tradedContractNumber << "\n";
		os << "spreadTradePrice: " << msg.spreadTradePrice << "\n";
		os << "tradeSideOfLeg: " << msg.tradeSideOfLeg << "\n";
		os << "printable: " << msg.printable << "\n";
		return os;
	};

	inline std::ostream& operator<<(std::ostream& os, const Trade& msg)
	{
		os << "messageType: " << msg.messageType << "\n";
		os << "timestamp: " << msg.timestamp << "\n";
		os << "tradeDate: " << msg.tradeDate << "\n";
		os << "buyersContractNumber: " << msg.buyersContractNumber << "\n";
		os << "sideOfBuyer: " << msg.sideOfBuyer << "\n";
		os << "buyersOrderNumber: " << msg.buyersOrderNumber << "\n";
		os << "buyersQuantityRemaining: " << msg.buyersQuantityRemaining << "\n";
		os << "sellersContractNumber: " << msg.sellersContractNumber << "\n";
		os << "sideOfSeller: " << msg.sideOfSeller << "\n";
		os << "sellingOrderNumber: " << msg.sellingOrderNumber << "\n";
		os << "sellerQuantityRemaining: " << msg.sellerQuantityRemaining << "\n";
		os << "tradeType: " << msg.tradeType << "\n";
		os << "matchNumber: " << msg.matchNumber << "\n";
		os << "executedQuantity: " << msg.executedQuantity << "\n";
		os << "tradePrice: " << msg.tradePrice << "\n";
		os << "tradedContractNumber: " << msg.tradedContractNumber << "\n";
		os << "spreadTradePrice: " << msg.spreadTradePrice << "\n";
		os << "printable: " << msg.printable << "\n";
		return os;
	};

	inline std::ostream& operator<<(std::ostream& os, const CustomMarketExecuted& msg)
	{
		os << "messageType: " << msg.messageType << "\n";
		os << "timestamp: " << msg.timestamp << "\n";
		os << "tradeDate: " << msg.tradeDate << "\n";
		os << "orderNumber: " << msg.orderNumber << "\n";
		os << "quantityRemaining: " << msg.quantityRemaining << "\n";
		os << "tradeType: " << msg.tradeType << "\n";
		os << "matchNumber: " << msg.matchNumber << "\n";
		os << "executedQuantity: " << msg.executedQuantity << "\n";
		os << "tradePrice: " << msg.tradePrice << "\n";
		os << "tradedContractNumber: " << msg.tradedContractNumber << "\n";
		os << "tradeSideOfLeg: " << msg.tradeSideOfLeg << "\n";
		os << "printable: " << msg.printable << "\n";
		return os;
	};

	inline std::ostream& operator<<(std::ostream& os, const CustomMarketTrade& msg)
	{
		os << "messageType: " << msg.messageType << "\n";
		os << "timestamp: " << msg.timestamp << "\n";
		os << "tradeDate: " << msg.tradeDate << "\n";
		os << "contractNumber: " << msg.contractNumber << "\n";
		os << "side: " << msg.side << "\n";
		os << "orderNumber: " << msg.orderNumber << "\n";
		os << "quantityRemaining: " << msg.quantityRemaining << "\n";
		os << "customMarketOrderNumber: " << msg.customMarketOrderNumber << "\n";
		os << "customMarketQuantityRemaining: " << msg.customMarketQuantityRemaining << "\n";
		os << "tradeType: " << msg.tradeType << "\n";
		os << "matchNumber: " << msg.matchNumber << "\n";
		os << "executedQuantity: " << msg.executedQuantity << "\n";
		os << "tradePrice: " << msg.tradePrice << "\n";
		os << "tradedContractNumber: " << msg.tradedContractNumber << "\n";
		os << "tradeSideOfNonCustomOrder: " << msg.tradeSideOfNonCustomOrder << "\n";
		os << "printable: " << msg.printable << "\n";
		return os;
	};

	inline std::ostream& operator<<(std::ostream& os, const TradeCancellation& msg)
	{
		os << "messageType: " << msg.messageType << "\n";
		os << "timestamp: " << msg.timestamp << "\n";
		os << "tradeDate: " << msg.tradeDate << "\n";
		os << "matchNumber: " << msg.matchNumber << "\n";
		return os;
	};

	inline std::ostream& operator<<(std::ostream& os, const EquilibriumPrice& msg)
	{
		os << "messageType: " << msg.messageType << "\n";
		os << "timestamp: " << msg.timestamp << "\n";
		os << "tradeDate: " << msg.tradeDate << "\n";
		os << "contractNumber: " << msg.contractNumber << "\n";
		os << "equilibriumPrice: " << msg.equilibriumPrice << "\n";
		os << "bestBidPrice: " << msg.bestBidPrice << "\n";
		os << "bestAskPrice: " << msg.bestAskPrice << "\n";
		os << "bestBidQuantity: " << msg.bestBidQuantity << "\n";
		os << "bestAskQuantity: " << msg.bestAskQuantity << "\n";
		return os;
	};

	inline std::ostream& operator<<(std::ostream& os, const OpenHighLowLastTradeAdjustment& msg)
	{
		os << "messageType: " << msg.messageType << "\n";
		os << "timestamp: " << msg.timestamp << "\n";
		os << "tradeDate: " << msg.tradeDate << "\n";
		os << "contractNumber: " << msg.contractNumber << "\n";
		os << "openingTrade: " << msg.openingTrade << "\n";
		os << "highestTrade: " << msg.highestTrade << "\n";
		os << "lowestTrade: " << msg.lowestTrade << "\n";
		os << "lastTrade: " << msg.lastTrade << "\n";
		os << "lastVolume: " << msg.lastVolume << "\n";
		os << "totalTradedVolume: " << msg.totalTradedVolume << "\n";
		os << "totalTrades: " << msg.totalTrades << "\n";
		os << "marketUpdates: " << uint32_t(msg.marketUpdates) << "\n";
		return os;
	};

	inline std::ostream& operator<<(std::ostream& os, const MarketSettlement& msg)
	{
		os << "messageType: " << msg.messageType << "\n";
		os << "timestamp: " << msg.timestamp << "\n";
		os << "tradeDate: " << msg.tradeDate << "\n";
		os << "contractNumber: " << msg.contractNumber << "\n";
		os << "settlementPrice: " << msg.settlementPrice << "\n";
		os << "volatility: " << msg.volatility << "\n";
		os << "settlementType: " << msg.settlementType << "\n";
		return os;
	};

	inline std::ostream& operator<<(std::ostream& os, const TextMessage& msg)
	{
		os << "messageType: " << msg.messageType << "\n";
		os << "timestamp: " << msg.timestamp << "\n";
		os << "tradeDate: " << msg.tradeDate << "\n";
		os << "sourceId: " << msg.sourceId << "\n";
		os << "textMessage: " << msg.textMessage << "\n";
		return os;
	};

	inline std::ostream& operator<<(std::ostream& os, const RequestForQuote& msg)
	{
		os << "messageType: " << msg.messageType << "\n";
		os << "timestamp: " << msg.timestamp << "\n";
		os << "tradeDate: " << msg.tradeDate << "\n";
		os << "contractNumber: " << msg.contractNumber << "\n";
		os << "price: " << msg.price << "\n";
		os << "quantity: " << msg.quantity << "\n";
		return os;
	};

	inline std::ostream& operator<<(std::ostream& os, const AnomalousOrderThresholdPublish& msg)
	{
		os << "messageType: " << msg.messageType << "\n";
		os << "timestamp: " << msg.timestamp << "\n";
		os << "tradeDate: " << msg.tradeDate << "\n";
		os << "contractNumber: " << msg.contractNumber << "\n";
		os << "aotPrice: " << msg.aotPrice << "\n";
		os << "aotUpperPrice: " << msg.aotUpperPrice << "\n";
		os << "aotLowerPrice: " << msg.aotLowerPrice << "\n";
		os << "etrPrice: " << msg.etrPrice << "\n";
		os << "etrUpperPrice: " << msg.etrUpperPrice << "\n";
		os << "etrLowerPrice: " << msg.etrLowerPrice << "\n";
		return os;
	};

	inline std::ostream& operator<<(std::ostream& os, const VolumeAndOpenInterest& msg)
	{
		os << "messageType: " << msg.messageType << "\n";
		os << "timestamp: " << msg.timestamp << "\n";
		os << "tradeDate: " << msg.tradeDate << "\n";
		os << "contractNumber: " << msg.contractNumber << "\n";
		os << "cumulativeVolume: " << msg.cumulativeVolume << "\n";
		os << "openInterest: " << msg.openInterest << "\n";
		os << "voiTradeDate: " << msg.voiTradeDate << "\n";
		return os;
	};

}
