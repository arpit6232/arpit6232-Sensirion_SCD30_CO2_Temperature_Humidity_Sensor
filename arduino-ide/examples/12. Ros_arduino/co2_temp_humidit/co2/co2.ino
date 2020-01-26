#include <Wire.h>
#include <ros.h>
#include <ros/time.h>
#include <sensor_msgs/co2_temp_humidity.h>

ros::NodeHandle  nh;
  sensor_msgs::co2_temp_humidity val_msg;
  ros::Publisher pub_range( "/co2_temp_humidity", &val_msg);
  char frameid[] = "/co2_temp_humidity";


#include "SparkFun_SCD30_Arduino_Library.h"

SCD30 airSensor;

void setup()
{

  
  Wire.begin();
  nh.initNode();
  nh.advertise(pub_range);

  val_msg.header.frame_id =  frameid;
  val_msg.temperature = 0;
  val_msg.co2 = 0;
  val_msg.humidity = 0;
  
  Serial.begin(9600);
  Serial.println("SCD30 Example");

  airSensor.begin(); //This will cause readings to occur every two seconds

  airSensor.setMeasurementInterval(4); //Change number of seconds between measurements: 2 to 1800 (30 minutes)

  //My desk is ~1600m above sealevel
  airSensor.setAltitudeCompensation(1600); //Set altitude of the sensor in m

  //Pressure in Boulder, CO is 24.65inHg or 834.74mBar
  airSensor.setAmbientPressure(835); //Current ambient pressure in mBar: 700 to 1200
}

void loop()
{
  if (airSensor.dataAvailable())
  {
    Serial.print("co2(ppm):");
    Serial.print(airSensor.getCO2());

    Serial.print(" temp(C):");
    Serial.print(airSensor.getTemperature(), 1);

    Serial.print(" humidity(%):");
    Serial.print(airSensor.getHumidity(), 1);

    Serial.println();

    val_msg.humidity=airSensor.getCO2();
    val_msg.humidity=airSensor.getHumidity();
    val_msg.temperature=airSensor.getTemperature();
    val_msg.header.stamp = nh.now();
    pub_range.publish(&val_msg);
  }
  else
    Serial.print(".");

   nh.spinOnce();
   delay(1000);
}
