#include "FakeDataParser.h"

FakeDataParser::FakeDataParser()
{  

}
void FakeDataParser::emitDataReceiver(int id, int value){
    emit dataReceived(id, value);
}
