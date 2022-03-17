/* 
 * rosserial Subscriber Example
 * Blinks an LED on callback
 */

#include <ros.h>
#include <std_msgs/String.h>

ros::NodeHandle nh;

class Led
{
  public:
  Led(int Pin){
    PIN=Pin;
    pinMode(PIN, OUTPUT);
  }
  bool turn_on()
  {
    digitalWrite(PIN, HIGH);   // blink the led
  }
  bool turn_off()
  {
    digitalWrite(PIN, LOW);   // blink the led
  }
  bool toggle()
  {
  digitalWrite(PIN, HIGH-digitalRead(PIN));   // blink the led
  }
protected:
  int PIN;
};

void messageCb( const std_msgs::String& msg);

Led LedBuiltIn(13);
std_msgs::String pub_msg;
ros::Subscriber<std_msgs::String> sub("test_commands", messageCb );
ros::Publisher pub("test_retVal", &pub_msg);

void messageCb( const std_msgs::String& msg){
  if(strcmp(msg.data,"turn_on") == 0)
  {
  LedBuiltIn.turn_on();
    pub_msg.data = "turned_on_ok";
    pub.publish(&pub_msg);
  }
  if(strcmp(msg.data,"turn_off") == 0)
  {
  LedBuiltIn.turn_off();
    pub_msg.data = "turned_off_ok";
    pub.publish(&pub_msg);
  }
  if(strcmp(msg.data,"toggle") == 0)
  {
LedBuiltIn.toggle();
    pub_msg.data = "toggled_ok";
    pub.publish(&pub_msg);
  }
}
void setup()
{ 
  
  nh.initNode();
  nh.subscribe(sub);
  nh.advertise(pub);
}

void loop()
{  
  nh.spinOnce();
  delay(50);
}

