microflo-luftdaten [![Build Status](https://travis-ci.org/c-base/microflo-luftdaten.svg?branch=master)](https://travis-ci.org/c-base/microflo-luftdaten) [![Greenkeeper badge](https://badges.greenkeeper.io/c-base/microflo-luftdaten.svg)](https://greenkeeper.io/)
==================

This repository aims to provide a [MicroFlo](http://microflo.org/) powered firmware for the [luftdaten.info](https://luftdaten.info/) air quality sensor.

## Hardware

* ESP8266 microcontroller
* SDS011 fine particle sensor
* DHT22 temperature and humidity sensor

See [luftdaten.info for details](https://luftdaten.info/feinstaubsensor-bauen/) and the [wiring plan](https://raw.githubusercontent.com/opendata-stuttgart/meta/master/files/nodemcu-v3-schaltplan-sds011.jpg).


## Connectivity

The firmware only sensor readout and conditioning on the data, and then transmit it over WiFi/MQTT.
Data logging and processing can be done using [MsgFlo](https://msgflo.org/) components on the message queue.

Basic idea is to:

* Have a Python component for uploading latest information to luftdaten.info via HTTP API
* Store air quality information in InfluxDB using [cbeam-telemetry-server](https://github.com/c-base/cbeam-telemetry-server) 
* Visualize in OpenMCT dashboards, and with the infoscreens around the station
* Potentially trigger alerts using custom Python logic

The MsgFlo side of this integration will be in the [c-flo repository](https://github.com/c-base/c-flo).

MQTT connectivity is handled by the [MicroFlo ESP8266 MsgFlo integration](https://github.com/microflo/microflo/pull/143).
