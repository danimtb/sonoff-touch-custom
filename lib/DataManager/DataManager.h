#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <Arduino.h>
#include <EEPROM.h>

#include <cstdint>
#include <string>

#define DM_BEGIN_ADDR 0
#define DM_TOTAL_MEM 512
#define DM_END_ADDR 511

#define DM_NETWORKDATA_ADDR_START 0
#define DM_WIFISSID_MEM 32
#define DM_WIFIPASS_MEM 32
#define DM_IP_MEM 4 //1+1+1+1
#define DM_MASK_MEM 4 //1+1+1+1
#define DM_GATEWAY_MEM 4 //1+1+1+1
#define DM_OTA_MEM 32
#define DM_NETWORKDATA_ADDR_END 107

#define DM_MQTT_ADDR_START 108
#define DM_MQTTSERVER_MEM 32
#define DM_MQTTPORT_MEM 2
#define DM_MQTTUSER_MEM 32
#define DM_MQTTPASS_MEM 32
#define DM_MQTT_ADDR_END 205

#define DM_DEVICEDATA_ADDR_START 206
#define DM_DEVICENAME_MEM 32
#define DM_MQTTTOPIC1_MEM 40
#define DM_MQTTTOPIC2_MEM 40
#define DM_MQTTTOPIC3_MEM 40
#define DM_MQTTTOPIC4_MEM 40
#define DM_MQTTTOPIC5_MEM 40
#define DM_MQTTTOPIC6_MEM 40
#define DM_DEVICEDATA_ADDR_END 489

class DataManager
{
private:
    template <class T> bool EEPROMwriteAnything(uint16_t startAddress, uint16_t maxMemory, const T& value);
    template <class T> void EEPROMreadAnything(uint16_t startAddress, uint16_t maxMemory, T& value);

public:
    DataManager();

    void setWifiSSID(std::string wifissid);
    void setWifiPass(std::string wifipass);
    void setIP(uint8_t ip1, uint8_t ip2, uint8_t ip3, uint8_t ip4);
    void setMask(uint8_t mask1, uint8_t mask2, uint8_t mask3, uint8_t mask4);
    void setGateway(uint8_t gateway1, uint8_t gateway2, uint8_t gateway3, uint8_t gateway4);
    void setOta(std::string ota);

    void setMqttServer(std::string mqttServer);
    void setMqttPort(uint16_t mqttPort);
    void setMqttUser(std::string mqttUser);
    void setMqttPass(std::string mqttPass);

    void setDeviceName(std::string deviceName);
    void setMqttTopic(uint8_t index, std::string mqttTopic);


    std::string getWifiSSID();
    std::string getWifiPass();
    std::string getIP();
    std::string getMask();
    std::string getGateway();
    std::string getOta();

    std::string getMqttServer();
    uint16_t getMqttPort();
    std::string getMqttUser();
    std::string getMqttPass();

    std::string getDeviceName();
    std::string getMqttTopic(uint8_t index);

    void setup();

    void loop();
};

#endif
