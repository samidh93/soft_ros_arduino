


#include <ros.h>


template<typename PublishT,typename SubscribeT>
class PublisherSubscriber
{
public:
 PublisherSubscriber(){}
 PublisherSubscriber(String publishTopicName, String subscriberTopicName, int queueSize)
{
    publisherObject = nh.advertise<PublishT>(publishTopicName, queueSize);
    subscriberObject = nh.subscribe<SubscribeT>(subscriberTopicName,queueSize,&PublisherSubscriber::subscriberCallback,this)
}
 void subscriberCallback(const typename SubscribeT& recievedMsg);
protected:
ros::Subscriber subscriberObject;
ros::Publisher publisherObject;
ros::NodeHandle nh;

};
template<>
void PublisherSubscriber<std_msgs::String,std_msgs::String>::subscriberCallback(const std_msgs::String& recievedMsg)
{
  std_msgs::String echo_msg;
  echo_msg.data = recievedMsg->data;
  publisherObject.publish(echo_msg);

}
PublisherSubscriber<std_msgs::String,std_msgs::String> PubSubNode("echo", "chatter",1);