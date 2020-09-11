/* Code Written By : Sukanta Mazumder
    Gmail : sukanta.uf6@gmail.com
*/
////////////////////////////////////////////////   Smart_Wheel_Chair    //////////////////////////////////////////////////
char data = 'S';

// for right motor
#define R_R_En 4
#define R_L_En 5
#define R_R_PWM 6 //forward PWM
#define R_L_PWM 7 //reverse PWM

// for left motor
#define L_R_En 8
#define L_L_En 9
#define L_R_PWM 10 //forward PWM
#define L_L_PWM 11 //reverse PWM


void setup() {

  pinMode(R_R_En, OUTPUT);
  pinMode(R_L_En, OUTPUT);
  pinMode(R_R_PWM, OUTPUT);
  pinMode(R_L_PWM, OUTPUT);

  pinMode(L_R_En, OUTPUT);
  pinMode(L_L_En, OUTPUT);
  pinMode(L_R_PWM, OUTPUT);
  pinMode(L_L_PWM, OUTPUT);

  Serial.begin(9600);
}

//motor_controlling_function

void forward( int a, int b)
{

  digitalWrite(R_R_En, HIGH);
  digitalWrite(R_L_En, HIGH);
  digitalWrite(L_R_En, HIGH);
  digitalWrite(L_L_En, HIGH);



  analogWrite(R_R_PWM, a );
  analogWrite(R_L_PWM, 0 );


  analogWrite(L_R_PWM, b );
  analogWrite(L_L_PWM, 0 );

}

void backward( int a, int b)
{

  digitalWrite(R_R_En, HIGH);
  digitalWrite(R_L_En, HIGH);
  digitalWrite(L_R_En, HIGH);
  digitalWrite(L_L_En, HIGH);



  analogWrite(R_R_PWM, 0 );
  analogWrite(R_L_PWM, a );


  analogWrite(L_R_PWM, 0 );
  analogWrite(L_L_PWM, b );
}

void left( int a, int b)
{

  digitalWrite(R_R_En, HIGH);
  digitalWrite(R_L_En, HIGH);
  digitalWrite(L_R_En, HIGH);
  digitalWrite(L_L_En, HIGH);



  analogWrite(R_R_PWM, a );
  analogWrite(R_L_PWM, 0 );


  analogWrite(L_R_PWM, 0 );
  analogWrite(L_L_PWM, b );
}

void left_forward( int a, int b)
{

  digitalWrite(R_R_En, HIGH);
  digitalWrite(R_L_En, HIGH);
  digitalWrite(L_R_En, LOW);
  digitalWrite(L_L_En, LOW);



  analogWrite(R_R_PWM, a );
  analogWrite(R_L_PWM, 0 );


  analogWrite(L_R_PWM, 0 );
  analogWrite(L_L_PWM, b );
}

void left_backward( int a, int b)
{

  digitalWrite(R_R_En, HIGH);
  digitalWrite(R_L_En, HIGH);
  digitalWrite(L_R_En, LOW);
  digitalWrite(L_L_En, LOW);



  analogWrite(R_R_PWM, 0 );
  analogWrite(R_L_PWM, a );


  analogWrite(L_R_PWM, 0 );
  analogWrite(L_L_PWM, b );
}

void right( int a, int b)
{
  digitalWrite(R_R_En, HIGH);
  digitalWrite(R_L_En, HIGH);
  digitalWrite(L_R_En, HIGH);
  digitalWrite(L_L_En, HIGH);



  analogWrite(R_R_PWM, 0 );
  analogWrite(R_L_PWM, a );


  analogWrite(L_R_PWM, b );
  analogWrite(L_L_PWM, 0 );
}

void right_forward( int a, int b)
{
  digitalWrite(R_R_En, LOW);
  digitalWrite(R_L_En, LOW);
  digitalWrite(L_R_En, HIGH);
  digitalWrite(L_L_En, HIGH);



  analogWrite(R_R_PWM, 0 );
  analogWrite(R_L_PWM, a );


  analogWrite(L_R_PWM, b );
  analogWrite(L_L_PWM, 0 );
}

void right_backward( int a, int b)
{
  digitalWrite(R_R_En, LOW);
  digitalWrite(R_L_En, LOW);
  digitalWrite(L_R_En, HIGH);
  digitalWrite(L_L_En, HIGH);



  analogWrite(R_R_PWM, 0 );
  analogWrite(R_L_PWM, a );


  analogWrite(L_R_PWM, 0 );
  analogWrite(L_L_PWM, b );
}


void stop()
{
  digitalWrite(R_R_En, LOW);
  digitalWrite(R_L_En, LOW);
  digitalWrite(L_R_En, LOW);
  digitalWrite(L_L_En, LOW);



  analogWrite(R_R_PWM, 0 );
  analogWrite(R_L_PWM, 0 );


  analogWrite(L_R_PWM, 0 );
  analogWrite(L_L_PWM, 0 );

}


void loop() {

  if (Serial.available() > 0)

  { data = Serial.read();
    if (data == 'F') {
      forward(200, 200); //change the speed according to your comfort
    }
    else if (data == 'B') {
      backward(200, 200); //change the speed according to your comfort
    }
    else if (data == 'R') {
      right(200, 200); //change the speed according to your comfort
    }
    else if (data == 'L') {
      left(200, 200); //change the speed according to your comfort
    }

    //can be ignored
    
    else if (data == 'I') {
      right_forward(200, 0); //change the speed according to your comfort except 0
    }
    
    //can be ignored
    
    else if (data == 'G') {
      left_forward(0, 200); //change the speed according to your comfort except 0
    }
    
    //can be ignored
    
    else if (data == 'J') {
      right_backward(200, 0); //change the speed according to your comfort except 0
    }
    
    //can be ignored
    
    else if (data == 'H') {
      left_backward(0, 200); //change the speed according to your comfort except 0
    }
    else if (data == 'S') {
      stop();
    }
  }

}
