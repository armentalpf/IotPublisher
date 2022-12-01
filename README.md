# IotPublisher
Transmit formatted message to mqtt client by serial port
include IotPublisher.h for use this library

This library trasnmit using serial port a formatted message to mqtt publisher client.
Format generated are
message = topic + ":" + payload + "\r\n"

Topic formats:
group + "/" + topic
group + "/" + topic + "/" + subtopic
group + groupId + "/" + topic
group + groupId + "/" + topic + "/" + subtopic
