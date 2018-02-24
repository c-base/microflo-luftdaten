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
    type: float
    description: ""
  humidity:
    type: float
    description: ""
microflo_component */

#include <DHT.h>;

//Constants
#define DHTPIN 7     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)

class ReadDHT22 : public Component {
private:
    Connection outPorts[ReadDHT22Ports::OutPorts::humidity+1];
    DHT dht;
public:
    ReadDHT22()
        : Component(outPorts, ReadDHT22Ports::OutPorts::humidity+1)
        , dht(DHTPIN, DHTTYPE)
    {
        //// Initialize DHT sensor for normal 16mhz Arduino
        //dht = DHT(DHTPIN, DHTTYPE);
    }
    
    virtual void process(Packet in, MicroFlo::PortId port) {
        using namespace ReadDHT22Ports;
        
        float hum;  //Stores humidity value
        float temp; //Stores temperature value
        
        if (port == InPorts::in) {
            hum = dht.readHumidity();
            temp = dht.readTemperature();
            
            send(temp, OutPorts::temperature);
            send(hum, OutPorts::humidity);
            
        }
    }
};

