#include <Arduino.h>
#include <IotMessages.h>
#include <IotPublisher.h>

#define SER_ADR 6
#define FL_ADR 9
#define NST_ADR 10
#define UNIT_ADR 11

IotDataText iotModel = IotDataText("config", "model");
IotDataText iotSerial = IotDataText("config", "serial");
IotDataInt iotFl = IotDataInt("config", "fl");
IotDataInt iotNstation = IotDataInt("config", "nstation");
IotDataText iotUnits = IotDataText("config", "units");
IotDataBool iotEnUv = IotDataBool("config", "enuv");
IotDataBool iotEnPout = IotDataBool("config", "enpout");
IotDataBool iotEnTemp = IotDataBool("config", "entemp");
IotDataBool iotEnFlow1 = IotDataBool("config", "enflujo1");
IotDataBool iotEnFlow2 = IotDataBool("config", "enflujo2");
IotDataInt iotFanHr = IotDataInt("station", "fanhm");
IotDataFloat iotPress = IotDataFloat("station", "pressure");
IotSubtopicBool iotFanAlarm = IotSubtopicBool("station", "alarm", "fanfail");

IotPublisher iotMsg = IotPublisher(&Serial);

uint16_t data[64];

void printHeader(const char *message);

void setup()
{
  const char modelo[] = "Veco-2";
  const char serial[] = "E1-250";
  const char units[] = "CA";

  uint32_t fanHour = 999999;
  uint16_t pressure = 32767;

  iotMsg.begin(9600);

  data[0] = (modelo[0] << 8) + modelo[1];
  data[1] = (modelo[2] << 8) + modelo[3];
  data[2] = (modelo[4] << 8) + modelo[5];
  data[6] = (serial[0] << 8) + serial[1];
  data[7] = (serial[2] << 8) + serial[3];
  data[8] = (serial[4] << 8) + serial[5];
  data[9] = 9999;
  data[10] = 64;
  data[11] = (units[0] << 8) + units[1];

  iotModel.setPayload(data, 3);
  iotSerial.setPayload(&data[SER_ADR], 3);
  iotFl.setPayload(data[FL_ADR]);
  iotNstation.setPayload(data[NST_ADR]);
  iotUnits.setPayload(&data[UNIT_ADR], 1);
  iotEnUv.setPayload(1);
  iotEnTemp.setPayload(0);
  iotEnPout.setPayload(1);
  iotEnFlow1.setPayload(1);
  iotEnFlow2.setPayload(0);
  iotFanHr.setPayload(fanHour);
  iotPress.setPayload((pressure / 100.00));
  iotFanAlarm.setPayload(1);

  delay(500);

  iotMsg.publish(iotModel.getGroup(), iotModel.getTopic(), iotModel.getPayload());
  iotMsg.publish(iotSerial.getGroup(), iotSerial.getTopic(), iotSerial.getPayload());
  iotMsg.publish(iotFl.getGroup(), iotFl.getTopic(), iotFl.getPayload());
  iotMsg.publish(iotNstation.getGroup(), iotNstation.getTopic(), iotNstation.getPayload());
  iotMsg.publish(iotUnits.getGroup(), iotUnits.getTopic(), iotUnits.getPayload());
  iotMsg.publish(iotEnUv.getGroup(), iotEnUv.getTopic(), iotEnUv.getPayload());
  iotMsg.publish(iotEnPout.getGroup(), iotEnPout.getTopic(), iotEnPout.getPayload());
  iotMsg.publish(iotEnTemp.getGroup(), iotEnTemp.getTopic(), iotEnTemp.getPayload());
  iotMsg.publish(iotEnFlow1.getGroup(), iotEnFlow1.getTopic(), iotEnFlow1.getPayload());
  iotMsg.publish(iotEnFlow2.getGroup(), iotEnFlow2.getTopic(), iotEnFlow2.getPayload());
  iotMsg.publish(iotFanHr.getGroup(), 2, iotFanHr.getTopic(), iotFanHr.getPayload());
  iotMsg.publish(iotPress.getGroup(), 64, iotPress.getTopic(), iotPress.getPayload());
  iotMsg.publish(iotFanAlarm.getGroup(),
                 1,
                 iotFanAlarm.getTopic(),
                 iotFanAlarm.getSubtopic(),
                 iotFanAlarm.getPayload());
}

void loop()
{
  // put your main code here, to run repeatedly:
}
// End of file
