#ifdef HAVE_SDS011
//#include <somelib.h>
#else
#warning "SDS011 support not enabled, you must define HAVE_SDS011"
#endif

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

public:
    ReadSDS011()
        : Component(outPorts, ReadSDS011Ports::OutPorts::pm10+1)
    {

    }

    virtual void process(Packet in, MicroFlo::PortId port) {
        using namespace ReadSDS011Ports;

        if (port == InPorts::in) {
#ifdef HAVE_SDS011

#else
            send((long)666, OutPorts::pm25);
            send((long)999, OutPorts::pm10);
#endif
        }
    }
};


