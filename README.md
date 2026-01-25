#The VoLTE Retrofit Project

## NOTE
This project is a work in progress and not complete by any means. No prototype currently exist but one is in development.

## Introduction
### Goal
Build a powerful and modular feature phone platform based on open source technologies which can be used to retrofit older cell phones or create entirely new devices. The project is heavily inspired by the Cyber Deck projects and SXMO.<br>
As the minimalist phone market is expanding, more and more options are becoming available. However, most if not all of these devices, while very capable hardware wise, have severely limiting software, or buggy/lacking implementations of basic functionality such as group MMS. Many of these devices run Android or KaiOS which are quite resource intensive for the intended feature set of these phones (almost over kill). 

### Core Features
- Voice Calling (obviously) <br>
- SMS<br>
- MMS (including Group MMS)<br>
- USB tethering<br>
- T-9 support with predictive text<br>
- Fast performance (core components written in C only, no bloat)<br>
- PIM features (contacts, detailed call statistics, calendar, reminders, etc.)<br>

### Extra Features
- Web portal for configuring and using certain features (SMS/MMS, etc.) [web server runs on phone hosting a website that other devices can access and use certain features of the phone]<br>
- Games<br>
- Speech to text (runs on device)<br>
- Music player<br>
- GPS navigation (for supported modems)<br>
- E-mail client<br>
- File Manager<br>
- Text Editor<br>
- Other linux programs/scripts (adapted for low resolution LCDs of course)<br>

### Hardware Features (potentially):
- Kill switches<br>
- External antennas<br> 
- Bluetooth (with hands free)<br>
- Whatever else you include<br>


## Techincal Overview
This is both a hardware and software project. We will provide both reference hardware and software that will allow anyone to build their own custom Linux based feature phone. 


### Terminology
- VRP Stack: The entire VRP reference software implementation.
- Adaptation: A device target, whether fully custom or based off an existing device.
- Interface Builder: Someone developing or adapting a custom user interface (display, buttons, etc.) to be used with the VRP project. Refers to both hardware and software.


### Software Stack
This repo contains, or will contain, basic implementations of core functionality (telephony, address book, SMS/MMS, etc.) that can be used by interface builders (i.e. anyone who wants to make feature phone interface). The cellular features will be implemented using ModemManager's libmm-glib API and mmsd-tng.


### How VoLTE is achieved
The most important part of this project is VoLTE support. This project uses ModemManager (MM) as the cellular software backend, MM supports many modems including Quectel's EG25 series, which supports VoLTE natively. This modem is also used in the PinePhone (an open source Linux smartphone) making it one of the very few Smartphones supported by mainline Linux with a working and somewhat reliable VoLTE implementation. Open source software VoLTE implementations are in the works but progress has been very slow. This project essentially relies on the modem itself having a working VoLTE implementation, so any VoLTE capable modem supported by MM should work with this project.
