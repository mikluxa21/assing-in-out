//
// Created by user on 29.03.24.
//
#include "protobuf/parser/DelimitedMessagesStreamParser.h"
//I don't understand why it method don't work
/*template<class MessageType>
std::list<typename DelimitedMessagesStreamParser<MessageType>::PointerToConstValue>
        DelimitedMessagesStreamParser<MessageType>::parse(const std::string& data)
{
    std::list<PointerToConstValue> result;
    this->m_buffer.insert(this->m_buffer.end(), data.begin(), data.end());
    size_t bytesConsumed = 0;
    while(!this->m_buffer.empty())
    {
        auto msg = parseDelimited<MessageType>(this->m_buffer.data(),
                                               this->m_buffer.size(),
                                               &bytesConsumed
        );
        if(bytesConsumed > 0)
        {
            result.push_back(msg);
            this->m_buffer.erase(this->m_buffer.begin(),
            this->m_buffer.begin() + bytesConsumed);
        }
        else
        break;
    }
    return result;
}*/