#include <AFMotor.h>
#include <Servo.h> 

Servo servoX;
Servo servoY;

int XMIN=1;
int XMAX=180;
int YMIN=40;
int YMAX=140;

int X=0;
int Y=0;


void setup() {
    Serial.begin(9600);
    Serial.println("Pan and tilt!");
  
    // Get initial position of the servos
    servoX.attach(9);
    servoY.attach(10);
    X = servoX.read();
    Y = servoY.read();
    servoX.detach();
    servoY.detach();
}

void loop() {
    char c, string[256];
    int xpos = 0, ypos = 0;
    
    if (Serial.available())
    {
        c = Serial.read();
        xpos = servoX.read();
        ypos = servoY.read();
        
        sprintf(string,"xpos = %3d     ypos = %3d",xpos,ypos);
        Serial.println(string);
        
        switch(c)
        {
            case 'l':
                if ( X < XMAX )
                {
                    X = X + 10;
                    servoX.attach(9);
                    servoX.write(X);
                    delay(30);
                    servoX.detach();
                }
                break;
            case 'r':
                if ( X > XMIN )
                {
                    X = X - 10;
                    servoX.attach(9);
                    servoX.write(X);
                    delay(30);
                    servoX.detach();
                }
                break;
            case 'd':
                if ( Y < YMAX )
                {
                    Y = Y + 10;
                    servoY.attach(10);
                    servoY.write(Y);
                    delay(30);
                    servoY.detach();                    
                }
                break;
            case 'u':
                if ( Y > YMIN )
                {
                    Y = Y - 10;
                    servoY.attach(10);
                    servoY.write(Y);
                    delay(30);
                    servoY.detach();
                }
                break;
                
        }
    }
}
