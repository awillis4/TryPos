#include <Servo.h>

Servo myservo1;Servo myservo2;Servo myservo3;Servo myservo4;

int val1 = 42;int val2 = 90;int val3 = 50;int val4 = 111;

//кнопка приготовления чая на пине 4
int buttonPin = 4;

void setup(){
myservo1.attach(11);myservo2.attach(10);myservo3.attach(9);myservo4.attach(6);

  // активируем подтягивающий резистор на пине кнопки
  pinMode(buttonPin, INPUT_PULLUP);
  // индикатор приготовления чая
  pinMode(5, OUTPUT);

  myservo1.write(val1);myservo2.write(val2);myservo3.write(val3);myservo4.write(val4);}

//функция перемещающая манипулятор в заданную точку
void manipulator(int val1_new, int val2_new, int val3_new, int val4_new, int speedm){

  int val1_route = 0;int val2_route = 0;int val3_route = 0;int val4_route = 0;

  if (val1 < val1_new) val1_route = 1;if (val1 > val1_new) val1_route = -1;
  if (val2 < val2_new) val2_route = 1;if (val2 > val2_new) val2_route = -1;
  if (val3 < val3_new) val3_route = 1;if (val3 > val3_new) val3_route = -1;
  if (val4 < val4_new) val4_route = 1;if (val4 > val4_new) val4_route = -1;

  //синхронизируем переданные значения с текущими
  while (val1 != val1_new || val2 != val2_new || val3 != val3_new || val4 != val4_new){

val1 = val1 + val1_route;myservo1.write(val1);if (val1 == val1_new) val1_route = 0;
val2 = val2 + val2_route;myservo2.write(val2);if (val2 == val2_new) val2_route = 0;
val3 = val3 + val3_route;myservo3.write(val3);if (val3 == val3_new) val3_route = 0;
val4 = val4 + val4_route;myservo4.write(val4);if (val4 == val4_new) val4_route = 0;
delay(speedm);}}

void loop(){if (digitalRead(buttonPin) == LOW) {    //готовим чай если кнопка нажата!!!

    digitalWrite(5, HIGH); 

manipulator(42, 90, 50, 111, 50);   // сервы на исходную !!!
manipulator(70, 165, 26, 111, 50);  // идем за чайным пакетом !!!
manipulator(70, 163, 46, 111, 50);  // идем за чайным пакетом !!!
manipulator(30, 163, 46, 111, 50);  // идем за чайным пакетом !!!
manipulator(30, 178, 44, 111, 50);  // идем за чайным пакетом !!!
manipulator(30, 178, 44, 58, 50);   // идем за чайным пакетом !!!

    for (int i = 0; i <= 7; i++) {

      manipulator(30, 118, 62, 58, 50); // макаем пакет

      delay(250);

manipulator(30, 162, 50, 58, 50);}
manipulator(30, 179, 24, 58, 50);   // уносим пакет
manipulator(30, 179, 24, 162, 50);  // уносим пакет
manipulator(30, 104, 61, 162, 50);  // уносим пакет
manipulator(65, 50, 61, 162, 50);   // бросаем пакет
manipulator(42, 90, 50, 111, 50);   // сервы на исходную !!!
manipulator(75, 78, 88, 123, 50);   // первый кусок !!!
manipulator(45, 78, 88, 123, 50);   // первый кусок !!!
manipulator(45, 78, 55, 123, 50);   // первый кусок !!!
manipulator(45, 78, 55, 85, 50);    // первый кусок !!!
manipulator(45, 124, 48, 85, 50);   // первый кусок !!!
manipulator(45, 127, 56, 59, 50);   // первый кусок !!!
manipulator(60, 127, 56, 59, 50);   // первый кусок !!!
manipulator(42, 90, 50, 111, 50);   // сервы на исходную !!!
manipulator(75, 79, 90, 106, 50);   // второй кусок !!!
manipulator(45, 79, 90, 106, 50);   // второй кусок !!!
manipulator(45, 79, 55, 106, 50);   // второй кусок !!!
manipulator(45, 78, 55, 85, 50);    // второй кусок !!!
manipulator(45, 124, 48, 85, 50);   // второй кусок !!!
manipulator(45, 127, 56, 59, 50);   // второй кусок !!!
manipulator(60, 127, 56, 59, 50);   // второй кусок !!!
manipulator(60, 127, 45, 59, 50);   // идем за ложкой !!!
manipulator(60, 127, 25, 59, 50);   // идем за ложкой !!!
manipulator(65, 127, 25, 139, 50);  // идем за ложкой !!!
manipulator(65, 130, 61, 139, 50);  // идем за ложкой !!!
manipulator(35, 130, 61, 139, 50);  // идем за ложкой !!!
manipulator(35, 180, 61, 139, 50);  // идем за ложкой !!!
manipulator(35, 180, 20, 139, 50);  // идем за ложкой !!!
manipulator(35, 180, 20, 60, 50);   // идем за ложкой !!!
manipulator(35, 180, 35, 60, 50);   // идем за ложкой !!!

    for (int j = 0; j <= 10; j++) {

manipulator(38, 127, 50, 59, 20); // перемешиваем !!!
manipulator(38, 127, 47, 59, 20); // перемешиваем !!!!
manipulator(38, 127, 57, 51, 20); // перемешиваем !!!
manipulator(38, 127, 68, 54, 20); // перемешиваем !!!
manipulator(38, 127, 75, 61, 20); // перемешиваем !!!
manipulator(38, 127, 71, 67, 20); // перемешиваем !!!
manipulator(38, 127, 61, 71, 20); // перемешиваем !!!
manipulator(38, 127, 50, 71, 20); // перемешиваем !!!
manipulator(38, 127, 44, 66, 20); // перемешиваем !!!
manipulator(38, 127, 50, 59, 20);}// same thing   !!!

manipulator(38, 170, 65, 59, 50);   // уносим ложку !!!
manipulator(38, 179, 18, 59, 50);   // уносим ложку !!!
manipulator(38, 179, 18, 139, 50);  // уносим ложку !!!
manipulator(38, 179, 57, 139, 50);  // уносим ложку !!!
manipulator(38, 179, 54, 139, 50);  // уносим ложку !!!
manipulator(38, 179, 58, 137, 50);  // уносим ложку !!!
manipulator(50, 179, 58, 137, 250); // уносим ложку !!!
manipulator(50, 179, 27, 137, 50);  // сервы на исходную !!!
manipulator(50, 120, 27, 137, 50);  // сервы на исходную !!!
manipulator(42, 90, 50, 111, 50);   // сервы на исходную !!!
digitalWrite(5, LOW);}}
