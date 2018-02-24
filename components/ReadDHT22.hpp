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

#ifdef HAVE_DHT
#include <DHT.h>;
#endif

//Constants
#define DHTPIN 7     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)

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
        , dht(DHTPIN, DHTTYPE)
#endif
    {
        //// Initialize DHT sensor for normal 16mhz Arduino
        //dht = DHT(DHTPIN, DHTTYPE);
    }
    
    virtual void process(Packet in, MicroFlo::PortId port) {
        using namespace ReadDHT22Ports;
        
        if (port == InPorts::in) {
            float hum = -23.0;  //Stores humidity value
            float temp = -300.0; //Stores temperature value
#ifdef HAVE_DHT
            hum = dht.readHumidity();
            temp = dht.readTemperature();
#endif
            send(temp, OutPorts::temperature);
            send(hum, OutPorts::humidity);
            
        }
    }
};

