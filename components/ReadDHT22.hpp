/* microflo_component yaml
name: ReadDHT22
description: Read pressure and humidity from DHT22 sensor
icon: "thermometer-3"
inports:
  in:
    type: all
    description: "Trigger a reading"
outports:
  temperature:
    type: integer
    description: ""
  humidity:
    type: integer
    description: ""
microflo_component */

#ifdef HAVE_DHT
#include <DHT.h>;
#else
#warning "DHT library not enabled, you must #define HAVE_DHT"
#endif

#ifndef D7
#warning "D7 pin not defined. This only works on a ESP8266 target"
#define D7 97
#endif

//Constants
class ReadDHT22 : public Component {
private:
    Connection outPorts[ReadDHT22Ports::OutPorts::humidity+1];
#ifdef HAVE_DHT
    DHT dht;
#endif
public:
    ReadDHT22()
        : Component(outPorts, ReadDHT22Ports::OutPorts::humidity+1)
#ifdef HAVE_DHT
        , dht(D7, DHT22)
#endif
    {
    }
    
    virtual void process(Packet in, MicroFlo::PortId port) {
        using namespace ReadDHT22Ports;

        if (port == InPorts::in) {
            float hum = -23.0;  //Stores humidity value
            float temp = -300.0; //Stores temperature value
            bool error = false;
#ifdef HAVE_DHT
            hum = dht.readHumidity();
            temp = dht.readTemperature();
            error = isnan(hum) || isnan(temp);
#endif
            if (!error) {
                send((long)(temp*1000.0), OutPorts::temperature);
                send((long)(hum*1000.0), OutPorts::humidity);
            }
            
        }
    }
};

