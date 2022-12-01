#include "IotPublisher.h"

IotPublisher::IotPublisher(HardwareSerial *txPort) : printPort(txPort)
{
}

void IotPublisher::begin(unsigned long bauds)
{
    printPort->begin(bauds);
}

void IotPublisher::publish(String group, String topic, String payload)
{
    String message = group + "/" + topic + ":" + payload;
    printPort->println(message);
}

void IotPublisher::publish(String group, int groupId, String topic, String payload)
{
    String message = group + String(groupId) + "/" + topic + ":" + payload;
    printPort->println(message);
}

void IotPublisher::publish(String group,
                           int groupId,
                           String topic,
                           String subtopic,
                           String payload)
{
    String message = group + String(groupId) + "/" + topic + "/" + subtopic + ":" + payload;
    printPort->println(message);
}