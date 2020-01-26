#!/bin/sh
xterm -hold -e  "arduino --board arduino:avr:uno --port /dev/ttyACM0 --upload /home/arpg/arduino-1.8.10/examples/Sensirion_Reading/Sensirion_Reading/Sensirion_Reading.ino" &
sleep 2
xterm -hold -e  "arduino --board arduino:avr:uno --port /dev/ttyACM1 --upload /home/arpg/arduino-1.8.10/examples/Sensirion_Reading/Sensirion_Reading/Sensirion_Reading.ino" &
sleep 2
xterm -hold -e  "arduino --board arduino:avr:uno --port /dev/ttyACM2 --upload /home/arpg/arduino-1.8.10/examples/Sensirion_Reading/Sensirion_Reading/Sensirion_Reading.ino" &
sleep 2
xterm -hold -e  "arduino --board arduino:avr:uno --port /dev/ttyACM3 --upload /home/arpg/arduino-1.8.10/examples/Sensirion_Reading/Sensirion_Reading/Sensirion_Reading.ino" &
sleep 2
xterm -hold -e  "arduino --board arduino:avr:uno --port /dev/ttyACM4 --upload /home/arpg/arduino-1.8.10/examples/Sensirion_Reading/Sensirion_Reading/Sensirion_Reading.ino" &
sleep 2
xterm -hold -e  "arduino --board arduino:avr:uno --port /dev/ttyACM5 --upload /home/arpg/arduino-1.8.10/examples/Sensirion_Reading/Sensirion_Reading/Sensirion_Reading.ino" 

