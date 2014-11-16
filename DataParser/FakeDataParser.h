#ifndef FAKEDATAPARSER_H
#define FAKEDATAPARSER_H

#include "I_DataParser.h"

class FakeDataParser : public I_DataParser
{
public:
    FakeDataParser();
    void emitDataReceiver(int id, int value);
};


#endif // FAKEDATAPARSER_H
