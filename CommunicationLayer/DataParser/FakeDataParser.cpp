#include "FakeDataParser.h"
#include <stdio.h>

FakeDataParser::FakeDataParser()
{  
}
void FakeDataParser::emitDataReceiver(int id, double value){
    emit dataReceived(id, value);
}
