/**
 * @file IotPublisher.h
 * @author Francisco Armenta (sistron@sistron.com.mx)
 * @brief Class for transmit message to mqtt publisher
 * @version 0.1
 * @date 2022-11-29
 *
 * @copyright Copyright (c) 2022 SITRN SISTEMAS ELECTRONICOS S DE RL DE CV
 *
 */
#ifndef IOTPUBLISHER_H_INCLUDED
#define IOTPUBLISHER_H_INCLUDED

#include <Arduino.h>

class IotPublisher
{
private:
    HardwareSerial *printPort;

public:
    IotPublisher(HardwareSerial *txPort);
    void begin(unsigned long bauds);
    void publish(String group, String topic, String payload);
    void publish(String group, int groupId, String topic, String payload);
    void publish(String group, int groupId, String topic, String subtopic, String payload);
};

#endif
// End of File