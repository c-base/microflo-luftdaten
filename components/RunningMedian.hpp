/* microflo_component yaml
name: RunningMedian
description: Calculate a running median of latest values
inports:
  in:
    type: integer
    description: ""
outports:
  out:
    type: integer
    description: ""
microflo_component */
class RunningMedian : public SingleOutputComponent {
public:
    virtual void process(Packet in, MicroFlo::PortId port) {
        if (in.isData()) {
            send(in, port);
        }
    }
};


