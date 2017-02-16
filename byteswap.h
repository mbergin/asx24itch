#pragma once
#include <cstdint>
#include "messages.h"

namespace asx24itch {

	// network_to_host converts big-endian data to host byte order.
	template<typename T>
	void network_to_host(T&)
	{
		static_assert(sizeof T != sizeof T , "must be specialised");
	}

	template <>
	inline void network_to_host(uint16_t& x)
	{
		x = (x & 0x00FF) << 8 |
			(x & 0xFF00) >> 8;
	}

	template <>
	inline void network_to_host(uint32_t& x)
	{
		x = (x & 0x000000FF) << 24 |
			(x & 0x0000FF00) << 8 |
			(x & 0x00FF0000) >> 8 |
			(x & 0xFF000000) >> 24;
	}

	template <>
	inline void network_to_host(int32_t& x)
	{
		x = (x & 0x000000FF) << 24 |
			(x & 0x0000FF00) << 8 |
			(x & 0x00FF0000) >> 8 |
			(x & 0xFF000000) >> 24;
	}

	template <>
	inline void network_to_host(uint64_t& x)
	{
		x = (x & 0xFF00000000000000ull) >> 56 |
			(x & 0x00FF000000000000ull) >> 40 |
			(x & 0x0000FF0000000000ull) >> 24 |
			(x & 0x000000FF00000000ull) >> 8 |
			(x & 0x00000000FF000000ull) << 8 |
			(x & 0x0000000000FF0000ull) << 24 |
			(x & 0x000000000000FF00ull) << 40 |
			(x & 0x00000000000000FFull) << 56;
	}

	template<>
	inline void network_to_host<TimeMessage>(TimeMessage& msg)
	{
		network_to_host(msg.second);
	}

	template<>
	inline void network_to_host<SystemEvent>(SystemEvent& msg)
	{
		network_to_host(msg.timestamp);
		network_to_host(msg.tradeDate);
	}

	template<>
	inline void network_to_host<FutureSymbolDirectory>(FutureSymbolDirectory& msg)
	{
		network_to_host(msg.timestamp);
		network_to_host(msg.tradeDate);
		network_to_host(msg.contractNumber);
		network_to_host(msg.expiryYear);
		network_to_host(msg.priceFractionalDenominator);
		network_to_host(msg.priceMinimumTick);
		network_to_host(msg.lastTradingDate);
		network_to_host(msg.priorDaySettlement);
		network_to_host(msg.lotSizeOrFaceValue);
		network_to_host(msg.couponRate);
	};

	template<>
	inline void network_to_host<SpreadSymbolDirectory>(SpreadSymbolDirectory& msg)
	{
		network_to_host(msg.timestamp);
		network_to_host(msg.tradeDate);
		network_to_host(msg.contractNumber);
		network_to_host(msg.firstLegContractNumber);
		network_to_host(msg.secondLegContractNumber);
		network_to_host(msg.priceFractionalDenominator);
		network_to_host(msg.priceMinimumTick);
	};

	template<>
	inline void network_to_host<OptionSymbolDirectory>(OptionSymbolDirectory& msg)
	{
		network_to_host(msg.timestamp);
		network_to_host(msg.tradeDate);
		network_to_host(msg.contractNumber);
		network_to_host(msg.expiryYear);
		network_to_host(msg.strike);
		network_to_host(msg.underlyingContractNumber);
		network_to_host(msg.priceFractionalDenominator);
		network_to_host(msg.priceMinimumTick);
		network_to_host(msg.strikePriceFractionalDenominator);
		network_to_host(msg.strikePriceMinimumTick);
		network_to_host(msg.lastTradingDate);
		network_to_host(msg.priorDaySettlement);
		network_to_host(msg.volatility);
		network_to_host(msg.lotSizeOrFaceValue);
		network_to_host(msg.couponRate);
	};

	template<>
	inline void network_to_host<OrderBookState>(OrderBookState& msg)
	{
		network_to_host(msg.timestamp);
		network_to_host(msg.tradeDate);
		network_to_host(msg.contractNumber);
	};

	template<>
	inline void network_to_host<OrderAdded>(OrderAdded& msg)
	{
		network_to_host(msg.timestamp);
		network_to_host(msg.tradeDate);
		network_to_host(msg.contractNumber);
		network_to_host(msg.orderNumber);
		network_to_host(msg.orderBookPriority);
		network_to_host(msg.quantity);
		network_to_host(msg.price);
	};

	template<>
	inline void network_to_host<OrderReplaced>(OrderReplaced& msg)
	{
		network_to_host(msg.timestamp);
		network_to_host(msg.tradeDate);
		network_to_host(msg.contractNumber);
		network_to_host(msg.orderNumber);
		network_to_host(msg.orderBookPriority);
		network_to_host(msg.quantity);
		network_to_host(msg.price);
	};

	template<>
	inline void network_to_host<OrderVolumeCancelled>(OrderVolumeCancelled& msg)
	{
		network_to_host(msg.timestamp);
		network_to_host(msg.tradeDate);
		network_to_host(msg.contractNumber);
		network_to_host(msg.orderNumber);
		network_to_host(msg.quantity);
	};

	template<>
	inline void network_to_host<OrderDeleted>(OrderDeleted& msg)
	{
		network_to_host(msg.timestamp);
		network_to_host(msg.tradeDate);
		network_to_host(msg.contractNumber);
		network_to_host(msg.orderNumber);
	};

	template<>
	inline void network_to_host<ImpliedOrderAdded>(ImpliedOrderAdded& msg)
	{
		network_to_host(msg.timestamp);
		network_to_host(msg.tradeDate);
		network_to_host(msg.contractNumber);
		network_to_host(msg.orderNumber);
		network_to_host(msg.orderBookPriority);
		network_to_host(msg.quantity);
		network_to_host(msg.price);
	};

	template<>
	inline void network_to_host<ImpliedOrderReplaced>(ImpliedOrderReplaced& msg)
	{
		network_to_host(msg.timestamp);
		network_to_host(msg.tradeDate);
		network_to_host(msg.contractNumber);
		network_to_host(msg.orderNumber);
		network_to_host(msg.orderBookPriority);
		network_to_host(msg.quantity);
		network_to_host(msg.price);
	};

	template<>
	inline void network_to_host<ImpliedOrderDeleted>(ImpliedOrderDeleted& msg)
	{
		network_to_host(msg.timestamp);
		network_to_host(msg.tradeDate);
		network_to_host(msg.contractNumber);
		network_to_host(msg.orderNumber);
	};

	template<>
	inline void network_to_host<CustomMarketOrderLeg>(CustomMarketOrderLeg& msg)
	{
		network_to_host(msg.contractNumber);
		network_to_host(msg.ratio);
		network_to_host(msg.price);
	};
	
	template<>
	inline void network_to_host<CustomMarketOrderAdded>(CustomMarketOrderAdded& msg)
	{
		network_to_host(msg.timestamp);
		network_to_host(msg.tradeDate);
		network_to_host(msg.orderNumber);
		network_to_host(msg.orderBookPriority);
		network_to_host(msg.quantity);
		for (int i = 0; i < 6; ++i)
		{
			network_to_host(msg.leg[i]);
		}
	};

	template<>
	inline void network_to_host<CustomMarketOrderReplaced>(CustomMarketOrderReplaced& msg)
	{
		network_to_host(msg.timestamp);
		network_to_host(msg.tradeDate);
		network_to_host(msg.orderNumber);
		network_to_host(msg.orderBookPriority);
		network_to_host(msg.quantity);
	};

	template<>
	inline void network_to_host<CustomMarketOrderDeleted>(CustomMarketOrderDeleted& msg)
	{
		network_to_host(msg.timestamp);
		network_to_host(msg.tradeDate);
		network_to_host(msg.orderNumber);
	};

	template<>
	inline void network_to_host<OrderExecuted>(OrderExecuted& msg)
	{
		network_to_host(msg.timestamp);
		network_to_host(msg.tradeDate);
		network_to_host(msg.contractNumber);
		network_to_host(msg.orderNumber);
		network_to_host(msg.quantityRemaining);
		network_to_host(msg.matchNumber);
		network_to_host(msg.executedQuantity);
		network_to_host(msg.tradePrice);
	};

	template<>
	inline void network_to_host<OrderExecutedWithPrice>(OrderExecutedWithPrice& msg)
	{
		network_to_host(msg.timestamp);
		network_to_host(msg.tradeDate);
		network_to_host(msg.contractNumber);
		network_to_host(msg.buyingOrderNumber);
		network_to_host(msg.buyersQuantityRemaining);
		network_to_host(msg.sellingOrderNumber);
		network_to_host(msg.sellersQuantityRemaining);
		network_to_host(msg.matchNumber);
		network_to_host(msg.executedQuantity);
		network_to_host(msg.tradePrice);
	};

	template<>
	inline void network_to_host<SpreadExecuted>(SpreadExecuted& msg)
	{
		network_to_host(msg.timestamp);
		network_to_host(msg.tradeDate);
		network_to_host(msg.contractNumber);
		network_to_host(msg.orderNumber);
		network_to_host(msg.quantityRemaining);
		network_to_host(msg.matchNumber);
		network_to_host(msg.executedQuantity);
		network_to_host(msg.tradePrice);
		network_to_host(msg.tradedContractNumber);
		network_to_host(msg.spreadTradePrice);
	};

	template<>
	inline void network_to_host<Trade>(Trade& msg)
	{
		network_to_host(msg.timestamp);
		network_to_host(msg.tradeDate);
		network_to_host(msg.buyersContractNumber);
		network_to_host(msg.buyersOrderNumber);
		network_to_host(msg.buyersQuantityRemaining);
		network_to_host(msg.sellersContractNumber);
		network_to_host(msg.sellingOrderNumber);
		network_to_host(msg.sellerQuantityRemaining);
		network_to_host(msg.matchNumber);
		network_to_host(msg.executedQuantity);
		network_to_host(msg.tradePrice);
		network_to_host(msg.tradedContractNumber);
		network_to_host(msg.spreadTradePrice);
	};

	template<>
	inline void network_to_host<CustomMarketExecuted>(CustomMarketExecuted& msg)
	{
		network_to_host(msg.timestamp);
		network_to_host(msg.tradeDate);
		network_to_host(msg.orderNumber);
		network_to_host(msg.quantityRemaining);
		network_to_host(msg.matchNumber);
		network_to_host(msg.executedQuantity);
		network_to_host(msg.tradePrice);
		network_to_host(msg.tradedContractNumber);
	};

	template<>
	inline void network_to_host<CustomMarketTrade>(CustomMarketTrade& msg)
	{
		network_to_host(msg.timestamp);
		network_to_host(msg.tradeDate);
		network_to_host(msg.contractNumber);
		network_to_host(msg.orderNumber);
		network_to_host(msg.quantityRemaining);
		network_to_host(msg.customMarketOrderNumber);
		network_to_host(msg.customMarketQuantityRemaining);
		network_to_host(msg.matchNumber);
		network_to_host(msg.executedQuantity);
		network_to_host(msg.tradePrice);
		network_to_host(msg.tradedContractNumber);
	};

	template<>
	inline void network_to_host<TradeCancellation>(TradeCancellation& msg)
	{
		network_to_host(msg.timestamp);
		network_to_host(msg.tradeDate);
		network_to_host(msg.matchNumber);
	};

	template<>
	inline void network_to_host<EquilibriumPrice>(EquilibriumPrice& msg)
	{
		network_to_host(msg.timestamp);
		network_to_host(msg.tradeDate);
		network_to_host(msg.contractNumber);
		network_to_host(msg.equilibriumPrice);
		network_to_host(msg.bestBidPrice);
		network_to_host(msg.bestAskPrice);
		network_to_host(msg.bestBidQuantity);
		network_to_host(msg.bestAskQuantity);
	};

	template<>
	inline void network_to_host<OpenHighLowLastTradeAdjustment>(OpenHighLowLastTradeAdjustment& msg)
	{
		network_to_host(msg.timestamp);
		network_to_host(msg.tradeDate);
		network_to_host(msg.contractNumber);
		network_to_host(msg.openingTrade);
		network_to_host(msg.highestTrade);
		network_to_host(msg.lowestTrade);
		network_to_host(msg.lastTrade);
		network_to_host(msg.lastVolume);
		network_to_host(msg.totalTradedVolume);
		network_to_host(msg.totalTrades);
	};

	template<>
	inline void network_to_host<MarketSettlement>(MarketSettlement& msg)
	{
		network_to_host(msg.timestamp);
		network_to_host(msg.tradeDate);
		network_to_host(msg.contractNumber);
		network_to_host(msg.settlementPrice);
		network_to_host(msg.volatility);
	};

	template<>
	inline void network_to_host<TextMessage>(TextMessage& msg)
	{
		network_to_host(msg.timestamp);
		network_to_host(msg.tradeDate);
	};

	template<>
	inline void network_to_host<RequestForQuote>(RequestForQuote& msg)
	{
		network_to_host(msg.timestamp);
		network_to_host(msg.tradeDate);
		network_to_host(msg.contractNumber);
		network_to_host(msg.price);
		network_to_host(msg.quantity);
	};

	template<>
	inline void network_to_host<AnomalousOrderThresholdPublish>(AnomalousOrderThresholdPublish& msg)
	{
		network_to_host(msg.timestamp);
		network_to_host(msg.tradeDate);
		network_to_host(msg.contractNumber);
		network_to_host(msg.aotPrice);
		network_to_host(msg.aotUpperPrice);
		network_to_host(msg.aotLowerPrice);
		network_to_host(msg.etrPrice);
		network_to_host(msg.etrUpperPrice);
		network_to_host(msg.etrLowerPrice);
	};

	template<>
	inline void network_to_host<VolumeAndOpenInterest>(VolumeAndOpenInterest& msg)
	{
		network_to_host(msg.timestamp);
		network_to_host(msg.tradeDate);
		network_to_host(msg.contractNumber);
		network_to_host(msg.cumulativeVolume);
		network_to_host(msg.openInterest);
		network_to_host(msg.voiTradeDate);
	};

}
