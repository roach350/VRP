# The VoLTE Retrofit Project

## NOTE
This project is a work in progress and not complete by any means. No prototype currently exists, however this soon shouldn't be the case as the project is under heavy development.

## Goal
Build a powerful and modular feature phone platform based on open source technologies which can be used to retrofit older cell phones or create entirely new device. The project is heavily inspired by the Cyber Deck projects and SXMO.<br>
As the minimalist phone market is expanding, there are more and more options becoming available. However, most if not all of these devices, while very capable hardware wise, have severely limiting software, or buggy/lacking implementations of basic functionality such as Group MMS. Many of these devices run Android or KaiOS which are quite resource intensive for the feature set that these phones have. 



## Core Features
- Voice Calling (obviously) <br>
- SMS<br>
- MMS (including Group MMS)<br>
- USB tethering<br>
- T-9 support with predictive text<br>
- Fast performance (written in C, C++ only, no bloat)<br>
- PIM features (contacts, detailed call statistics, calendar, reminders, etc.)<br>
- File manager<br>
- Text Editor<br>
- Other linux programs/scripts (adapted for low resolution LCDs of course)<br>

## Extra Features
- Web portal for configuring and using certain features (SMS/MMS, etc.) [web server runs on phone hosting a site and other devices can log into that site and use certain features of the phone]<br>
- Games<br>
- Speech to text (runs on device)<br>
- Music player<br>
- GPS navigation (for supported modems)<br>
- E-mail client<br>


## Hardware Features (potentially):
- Kill switches<br>
- External antennas<br> 
- Bluetooth (with hands free)<br>
- Whatever else you include<br>


## Techincal Overview

### How VoLTE is achieved
The most important part of this project is VoLTE support. This project uses ModemManager (MM) as the cellular software backend, MM supports many modems including Quectel's EG25 series, which supports VoLTE natively. This modem is also used in the PinePhone (an open source Linux smartphone) making it one of the very few Smartphones supported by mainline Linux with a working and somewhat reliable VoLTE implementation. Open source software VoLTE implementations are in the works but progress has been very slow.




