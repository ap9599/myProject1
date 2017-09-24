
# this is the code for Bridge Rat
const int forward = 8;//H-Bridge pin 2 cnnctd to dgtl pin 8 on Arduino   
const int backward = 9;//H_Bridge pin 7 connected to digital pin 9 on Arduino
const int blink = 13;// built-in led is at pin 13 of arduino

long rndnum = 0;

void setup()
{
  pinMode(forward,OUTPUT);
  pinMode(backward,OUTPUT);
  pinMode(blink, OUTPUT);
  //all of the pins above are outputs and inputs
  randomSeed(analogRead(A0));
  Serial.begin(115200);//starts up serial monitor & provides baud rate
}
void loop()//keep repeating
{
    digitalWrite(blink, HIGH); // turn LED on
    digitalWrite(forward,HIGH);//motor movees foward
    
    rndnum = random(1,10)*100;
    Serial.print("I am moving forward by ");
    Serial.println(rndnum);

    delay(rndnum);//wait 3 seconds

    digitalWrite(forward,LOW);//stop the DC motor
    rndnum = random(1,10)*100;
    Serial.print("I am stopping for ");
    Serial.println(rndnum);

    delay(rndnum);//wait 3 seconds

    digitalWrite(backward,HIGH);//motor movees foward
    rndnum = random(1,10)*100;
    Serial.print("I am moving backwards by ");
    Serial.println(rndnum);

    delay(rndnum);//wait 3 seconds

    digitalWrite(backward,LOW);//stop the DC motor
    Serial.println("I am stopped!!!");
    digitalWrite(blink, LOW); // turn LED off

    delay(1000);//wait 1 seconds
}
