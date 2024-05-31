#pragma config(UART_Usage, UART1, uartUserControl, baudRate115200, IOPins, None, None)
#pragma config(Sensor, in1, pot1, sensorPotentiometer)
#pragma config(Sensor, in2, pot2, sensorPotentiometer)
#pragma config(Sensor, in3, pot3, sensorPotentiometer)
#pragma config(Sensor, in4, pot4, sensorPotentiometer)
#pragma config(Sensor, dgtl1, quad1, sensorQuadEncoder)
#pragma config(Sensor, dgtl3, quad2, sensorQuadEncoder)
#pragma config(Sensor, dgtl5, sw1, sensorTouch)
#pragma config(Sensor, dgtl6, sw2, sensorTouch)
#pragma config(Sensor, dgtl7, sw3, sensorTouch)
#pragma config(Sensor, dgtl8, sw4, sensorTouch)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "uart_comms.c"

void ReadSensors()
{
  /** MODIFY THIS FUNCTION TO READ SENSORS **/
  // Preset configuration for sensors, change as needed
  SerialWriteSensor(pot1);
  SerialWriteSensor(pot2);
  SerialWriteSensor(pot3);
  SerialWriteSensor(pot4);
  SerialWriteSensor(quad1);
  SerialWriteSensor(quad2);
  SerialWriteSensor(sw1);
  SerialWriteSensor(sw2);
  SerialWriteSensor(sw3);
  SerialWriteSensor(sw4);
}

void RunMotors(int *val)
{
  motor[port1]  = val[0];
  motor[port2]  = val[1];
  motor[port3]  = val[2];
  motor[port4]  = val[3];
  motor[port5]  = val[4];
  motor[port6]  = val[5];
  motor[port7]  = val[6];
  motor[port8]  = val[7];
  motor[port9]  = val[8];
  motor[port10] = val[9];
}

task serialCommsTask()
{
  setTaskPriority(serialCommsTask, 20); // bump our priority
  while (true) {
    SerialUpdate();
    wait1Msec(2); // comms task expects to be run every 2mS
  }
}

task main()
{
  if (SerialInit(UART1, baudRate115200)) {
    startTask(serialCommsTask);
  }

  while (true) {
    // nothing to do here, event-based handling by other tasks
    wait1Msec(100);
  }
}
