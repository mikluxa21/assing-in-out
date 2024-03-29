#include <list>
#include <algorithm>
#include "Parser.h"


#ifndef PROTOBUF_PARSER_DELIMITEDMESSAGESSTREAMPARSER_H
#define PROTOBUF_PARSER_DELIMITEDMESSAGESSTREAMPARSER_H

template<class MessageType>
class DelimitedMessagesStreamParser
{
public:
  typedef std::shared_ptr<const MessageType> PointerToConstValue;
  std::list<PointerToConstValue> parse(const std::string&);
private:
  std::vector<char> m_buffer = {};
};

#endif /* PROTOBUF_PARSER_DELIMITEDMESSAGESSTREAMPARSER_H */
