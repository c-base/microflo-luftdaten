microflo-luftdaten [![Build Status](https://travis-ci.org/c-base/microflo-luftdaten.svg?branch=master)](https://travis-ci.org/c-base/microflo-luftdaten) [![Greenkeeper badge](https://badges.greenkeeper.io/c-base/microflo-luftdaten.svg)](https://greenkeeper.io/)
==================

This repository provides a [MicroFlo](http://microflo.org/) powered firmware for the [luftdaten.info](https://luftdaten.info/) air quality sensor.

![MicroFlo luftdaten graph](https://d2vqpl3tx84ay5.cloudfront.net/800x/microflo-luftdaten-graph.png)

**[Open in Flowhub](http://app.flowhub.io/#github/c-base/microflo-luftdaten)**

## Status

In production.

* One sensor deployed outside c-base, [see public data](https://www.madavi.de/sensor/graph.php?sensor=msgflo-00000042-sds011)
* One sensor deployed in c-base main hall, [data visible in c-base crew network](http://c-flo.cbrp3.c-base.org/life-support/)

## Hardware

* ESP8266 microcontroller
* SDS011 fine particle sensor.
* DHT22 temperature and humidity sensor

See [luftdaten.info for details](https://luftdaten.info/feinstaubsensor-bauen/) and the [wiring plan](https://raw.githubusercontent.com/opendata-stuttgart/meta/master/files/nodemcu-v3-schaltplan-sds011.jpg).

[SDS011 datasheet](http://ecksteinimg.de/Datasheet/SDS011%20laser%20PM2.5%20sensor%20specification-V1.3.pdf)

## Connectivity

The firmware only sensor readout and conditioning on the data, and then transmit it over WiFi/MQTT.
Data logging and processing is done using [MsgFlo](https://msgflo.org/) components on the message queue.

Basic idea is to:

* Have a [Python component for uploading latest information to luftdaten.info](https://github.com/c-base/c-flo/pull/93) via HTTP API
* [Store air quality information in InfluxDB](https://github.com/c-base/cbeam-telemetry-server/pull/61) using [cbeam-telemetry-server](https://github.com/c-base/cbeam-telemetry-server) 
* Visualize in OpenMCT dashboards, and with the [infoscreens around the station](http://c-flo.cbrp3.c-base.org/life-support/)
* Potentially trigger alerts using custom Python logic

The MsgFlo side of this integration is in the [c-flo repository](https://github.com/c-base/c-flo).

MQTT connectivity is handled by the [MicroFlo ESP8266 MsgFlo integration](https://github.com/microflo/microflo/pull/143).
