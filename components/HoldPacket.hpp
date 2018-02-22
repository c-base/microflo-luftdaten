/* microflo_component yaml
name: HoldPacket
description: Hold and send latest packet
inports:
  data:
    type: all
    description: "Data to send"
  in:
    type: bang
    description: "Trigger a send"
outports:
  out:
    type: all
    description: ""
microflo_component */
class HoldPacket : public SingleOutputComponent {
public:
    virtual void process(Packet in, MicroFlo::PortId port) {
        if (in.isData()) {
            send(in, port);
        }
    }
};


