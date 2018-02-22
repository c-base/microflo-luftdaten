microflo-luftdaten [![Build Status](https://travis-ci.org/c-base/microflo-luftdaten.svg?branch=master)](https://travis-ci.org/c-base/microflo-luftdaten)
==================

This repository aims to provide a [MicroFlo](http://microflo.org/) powered firmware for the [luftdaten.info](https://luftdaten.info/) air quality sensor.

## Hardware

* ESP8266 microcontroller
* SDS011 fine particle sensor
* DHT22 temperature and humidity sensor

See [luftdaten.info for details](https://luftdaten.info/feinstaubsensor-bauen/) and the [wiring plan](https://raw.githubusercontent.com/opendata-stuttgart/meta/master/files/nodemcu-v3-schaltplan-sds011.jpg).

## Connectivity

The microcontroller connects to a WiFi network and transmits its information via MQTT. Data logging and processing can be done using [MsgFlo](https://msgflo.org/) components on the message queue.

Basic idea is to:

* Have a Python component for uploading latest information to luftdaten.info via HTTP API
* Store air quality information in InfluxDB using [cbeam-telemetry-server](https://github.com/c-base/cbeam-telemetry-server) and visualize using NASA OpenMCT
* Potentially trigger alerts using custom Python logic

MQTT connectivity is handled by the [MicroFlo ESP8266 MsgFlo integration](https://github.com/microflo/microflo/pull/143).
