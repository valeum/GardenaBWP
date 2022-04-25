# GardenaBWP
Gardena Battery Rain Water Tank Pump 2000/2 18V P4A - Article No. 14602

Manuel: https://www.gardena.com/tdrdownload//pub000081324/doc000149307

![Gardena Battery Rain Water Tank Pump 2000/2](Documentation/2022-04-25_Gardena-2000-2.png)

## Reverse Engineering

### Akku
System Battery P4A PBA 18V/45 - Article No. 14903-20

Manuel: https://www.gardena.com/tdrdownload//pub000081354/doc000149497

| Description | Pin |
| --- | --- |
| Plus (+) | 1 |
| Data? | 2 |
| Data? | 3 |
| Minus (-) | 4 |


### Control Panel
![Control Panel Back](Documentation/2022-04-25_Control-Panel_Back.png)

![Schematic](Documentation/2022-04-25_Schematic_v1.png)

Label Description:

HW: 3.1.4A3 | SW: 3.1.0 | 20210819

#### UART-Port
| Description | Pin | Pin | Description |
| --- | --- | --- | --- |
| GND | 1 | 2 | TX |
| - | 3 | 4 | - |
| - | 5 | 6 | - |

#### Logic Analyzer
![OLS](Documentation/2022-04-24_la-1.png)
![OLS](Documentation/2022-04-24_la-2.png)
![OLS](Documentation/2022-04-24_la-3.png)

Baudrate: 9600

#### Revived Data
| First Byte | ? | Batt. V | Batt. A | Batt. Temp | Error | SMO | Batt. Type. Rev | Software Ver. | Temp | Batt. Type | Auto Incremental | Checksum | Last Byte |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | 
| FB | ? | U | I | TA | Err | SMO | BTR | SVN | TS | BT | AI | CS | LB |
| 0xFE | 2 | 20.46 | 4.08 | 25.4 | 0 | 23 | 047k5 | 3.1 | 24.8 | 3_1 | 2100 | 0x3B | 0xFD |

# Notes
## Gardena
- https://gitlab.com/nbrgmn/wall-e-esp8266-automower/-/tree/develop
- https://www.roboter-forum.com/index.php?thread/12310-wlan-anbindung-gardena-r40li-hausautomatisierung-fernbedienung-etc/&pageNo=2
- https://www.youtube.com/watch?v=DqCoxzLTGXg&t=567s

## Arduino Logic Analyzer
- https://github.com/gillham/logic_analyzer
- https://github.com/jawi/ols

## Arduino Baudrate Finder
- https://github.com/Sjord/autobaud
