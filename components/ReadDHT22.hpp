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
class ReadDHT22 : public SingleOutputComponent {
public:
    virtual void process(Packet in, MicroFlo::PortId port) {
        if (in.isData()) {
            send(in, port);
        }
    }
};

