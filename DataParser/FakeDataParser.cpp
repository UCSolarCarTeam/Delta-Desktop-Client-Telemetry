#include "FakeDataParser.h"
#include <stdio.h>

FakeDataParser::FakeDataParser()
{  
}
void FakeDataParser::emitDataReceiver(int id, int value){
    emit dataReceived(id, value);
    printf("Fake value: %d\n", value);
}
