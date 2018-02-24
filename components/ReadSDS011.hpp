#ifdef HAVE_SDS011
//#include <SDS011-select-serial.h> // XXX: not safe to include twice, and config.h
#include <SoftwareSerial.h>
#else
#warning "SDS011 support not enabled, you must define HAVE_SDS011"
#endif

// FIXME: make configurable
const int RX_PIN = 11;
const int TX_PIN = 10;

/* microflo_component yaml
name: ReadSDS011
description: Read particle concentration from a SDS011 sensor
icon: "cloud"
inports:
  in:
    type: all
    description: "Trigger a reading"
outports:
  pm25:
    type: integer
    description: ""
  pm10:
    type: integer
    description: ""
microflo_component */
class ReadSDS011 : public Component {
private:
    Connection outPorts[ReadSDS011Ports::OutPorts::pm10+1];
    SoftwareSerial serial;
    SDS011 sds;

public:
    ReadSDS011()
        : Component(outPorts, ReadSDS011Ports::OutPorts::pm10+1)
        , serial(RX_PIN, TX_PIN)
        , sds(serial)
    {
    }

    virtual void process(Packet in, MicroFlo::PortId port) {
        using namespace ReadSDS011Ports;

        if (port == InPorts::in) {
            float pm25 = -999;
            float pm10 = -666;
            bool error = false;
#ifdef HAVE_SDS011
	        serial.begin(9600); // XXX: only do once?
	        error = sds.read(&pm25, &pm10);
#else
            if (!error) {
                send((long)(pm25*1000.0), OutPorts::pm25);
                send((long)(pm10*1000.0), OutPorts::pm10);    
            }
#endif
        }
    }
};
