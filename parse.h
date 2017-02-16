#pragma once
#include "messages.h"
#include "byteswap.h"

namespace asx24itch
{
	// ParseStatus represents the outcome of parsing an ITCH message.
	enum class ParseStatus
	{
		// The message was parsed successfully and the handler was invoked.
		OK,

		// The message was of a type not in the specification.
		UnknownMessageType,

		// The message was too short for the given message type and is possibly corrupted.
		Truncated,
	};


	// parseAs parses a message as one of the specific message types from messages.h, from
	// the buffer at buf with length len. It invokes the handler with a reference to the parsed
	// message if it was parsed successfully.
	template<typename MsgType, typename Handler>
	ParseStatus parseAs(const char* buf, size_t len, Handler&& handler)
	{
		if (len < sizeof MsgType)
			return ParseStatus::Truncated;
		MsgType msg{*reinterpret_cast<const MsgType*>(buf)};
		network_to_host(msg);
		std::invoke(std::forward<Handler>(handler), msg);
		return ParseStatus::OK;
	}

	// parse parses a message from the buffer given by msg and len. It invokes the handler
	// with a reference to the message if it was parsed successfully.
	//
	// If the message is shorter than expected, the handler is not invoked and ParseStatus::Truncated is returned.
	// If the message is longer than expected then the handler is invoked but 
	// the remaining data is ignored, for forward compatibility.
	// 
	// If the message is of an unknown type, ParseStatus::UnknownMessageType is returned and the handler is not invoked.
	template<typename Handler>
	ParseStatus parse(const char* msg, size_t len, Handler&& handler)
	{
		if (len < 1)
			return ParseStatus::Truncated;
		switch (MessageType(msg[0])) {
		case MessageType::TimeMessage:
			return parseAs<TimeMessage>(msg, len, std::forward<Handler>(handler));
		case MessageType::SystemEvent:
			return parseAs<SystemEvent>(msg, len, std::forward<Handler>(handler));
		case MessageType::FutureSymbolDirectory:
			return parseAs<FutureSymbolDirectory>(msg, len, std::forward<Handler>(handler));
		case MessageType::SpreadSymbolDirectory:
			return parseAs<SpreadSymbolDirectory>(msg, len, std::forward<Handler>(handler));
		case MessageType::OptionSymbolDirectory:
			return parseAs<OptionSymbolDirectory>(msg, len, std::forward<Handler>(handler));
		case MessageType::OrderBookState:
			return parseAs<OrderBookState>(msg, len, std::forward<Handler>(handler));
		case MessageType::OrderAdded:
			return parseAs<OrderAdded>(msg, len, std::forward<Handler>(handler));
		case MessageType::OrderReplaced:
			return parseAs<OrderReplaced>(msg, len, std::forward<Handler>(handler));
		case MessageType::OrderVolumeCancelled:
			return parseAs<OrderVolumeCancelled>(msg, len, std::forward<Handler>(handler));
		case MessageType::OrderDeleted:
			return parseAs<OrderDeleted>(msg, len, std::forward<Handler>(handler));
		case MessageType::ImpliedOrderAdded:
			return parseAs<ImpliedOrderAdded>(msg, len, std::forward<Handler>(handler));
		case MessageType::ImpliedOrderReplaced:
			return parseAs<ImpliedOrderReplaced>(msg, len, std::forward<Handler>(handler));
		case MessageType::ImpliedOrderDeleted:
			return parseAs<ImpliedOrderDeleted>(msg, len, std::forward<Handler>(handler));
		case MessageType::CustomMarketOrderAdded:
			return parseAs<CustomMarketOrderAdded>(msg, len, std::forward<Handler>(handler));
		case MessageType::CustomMarketOrderReplaced:
			return parseAs<CustomMarketOrderReplaced>(msg, len, std::forward<Handler>(handler));
		case MessageType::CustomMarketOrderDeleted:
			return parseAs<CustomMarketOrderDeleted>(msg, len, std::forward<Handler>(handler));
		case MessageType::OrderExecuted:
			return parseAs<OrderExecuted>(msg, len, std::forward<Handler>(handler));
		case MessageType::OrderExecutedWithPrice:
			return parseAs<OrderExecutedWithPrice>(msg, len, std::forward<Handler>(handler));
		case MessageType::SpreadExecuted:
			return parseAs<SpreadExecuted>(msg, len, std::forward<Handler>(handler));
		case MessageType::TradeSpreadExecutionChain:
			return parseAs<Trade>(msg, len, std::forward<Handler>(handler));
		case MessageType::CustomMarketExecuted:
			return parseAs<CustomMarketExecuted>(msg, len, std::forward<Handler>(handler));
		case MessageType::CustomMarketTrade:
			return parseAs<CustomMarketTrade>(msg, len, std::forward<Handler>(handler));
		case MessageType::TradeCancellation:
			return parseAs<TradeCancellation>(msg, len, std::forward<Handler>(handler));
		case MessageType::EquilibriumPrice:
			return parseAs<EquilibriumPrice>(msg, len, std::forward<Handler>(handler));
		case MessageType::OpenHighLowLastTradeAdjustment:
			return parseAs<OpenHighLowLastTradeAdjustment>(msg, len, std::forward<Handler>(handler));
		case MessageType::MarketSettlement:
			return parseAs<MarketSettlement>(msg, len, std::forward<Handler>(handler));
		case MessageType::TextMessage:
			return parseAs<TextMessage>(msg, len, std::forward<Handler>(handler));
		case MessageType::RequestForQuote:
			return parseAs<RequestForQuote>(msg, len, std::forward<Handler>(handler));
		case MessageType::AnomalousOrderThresholdPublish:
			return parseAs<AnomalousOrderThresholdPublish>(msg, len, std::forward<Handler>(handler));
		case MessageType::VolumeAndOpenInterest:
			return parseAs<VolumeAndOpenInterest>(msg, len, std::forward<Handler>(handler));
		default:
			return ParseStatus::UnknownMessageType;
		}
	}
}
