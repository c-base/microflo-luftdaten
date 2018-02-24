/* microflo_component yaml
name: ValueToFloat
description: "Convert integer input to float, dividing to 1000"
inports:
  in:
    type: integer
    description: ""
outports:
  out:
    type: number
    description: ""
microflo_component */
class ValueToFloat : public SingleOutputComponent {
public:
    virtual void process(Packet in, MicroFlo::PortId port) {
      using namespace ValueToFloatPorts;
      if (port == InPorts::in && in.isInteger()) {
        const float val = in.asInteger() / 1000.0;
        send(val, OutPorts::out);
      }
    }
};
