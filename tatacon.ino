/*!
 * @file tatacon.ino
 * @brief tatacon controller
 * @auther kaneko
 * @date 2018-11-24 test release
 * @date 2018-11-25 1st release
 */

/*=========================================
  contents
===========================================*/
#define     LED     13      /*! LED pin         */
#define     S0      A0      /*! sensor0         */
#define     S1      A1      /*! sensor1         */
#define     S2      A2      /*! sensor2         */
#define     S3      A3      /*! sensor3         */
#define     B0      12      /*! button0         */
#define     B1      11      /*! button1         */
#define     B2      10      /*! button2         */
#define     B3      9       /*! button3         */

#define     T0      100     /*! OFF wait 0 5ms@100 */
#define     T1      100     /*! OFF wait 1 5ms@100 */
#define     T2      100     /*! OFF wait 2 5ms@100 */
#define     T3      100     /*! OFF wait 3 5ms@100 */

/*=========================================
  globals
===========================================*/
int         cnt0;           /*! counter 0       */
int         cnt1;           /*! counter 1       */
int         cnt2;           /*! counter 2       */
int         cnt3;           /*! counter 3       */
bool        led_on;         /*! LED flag        */

/*=========================================
  functions
===========================================*/
/*!
 * @brief setup
 * @return void
 */
void setup() {
  /*----- init. globals -----*/
  cnt0 = 0;
  cnt1 = 0;
  cnt2 = 0;
  cnt3 = 0;
  led_on = false;

  /*----- init. pins -----*/
  pinMode(LED, OUTPUT);
  pinMode(S0, INPUT);
  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);
  pinMode(B0, OUTPUT); digitalWrite(B0, HIGH);
  pinMode(B1, OUTPUT); digitalWrite(B1, HIGH);
  pinMode(B2, OUTPUT); digitalWrite(B2, HIGH);
  pinMode(B3, OUTPUT); digitalWrite(B3, HIGH);
  
}

/*!
 * @brief loop
 * @return void
 */
void loop() {
  /*----- update button -----*/
  if(cnt0 == 0) digitalWrite(B0, HIGH); else digitalWrite(B0, LOW);
  if(cnt1 == 0) digitalWrite(B1, HIGH); else digitalWrite(B1, LOW);
  if(cnt2 == 0) digitalWrite(B2, HIGH); else digitalWrite(B2, LOW);
  if(cnt3 == 0) digitalWrite(B3, HIGH); else digitalWrite(B3, LOW);

  led_on = false;
  /*----- check sensor 0 -----*/
  if(digitalRead(S0) == HIGH) {
    cnt0 = T0;
    led_on = true;
  } else {
    if(cnt0 != 0) --cnt0;
  }

  /*----- check sensor 1 -----*/
  if(digitalRead(S1) == HIGH) {
    cnt1 = T1;
    led_on = true;
  } else {
    if(cnt1 != 1) --cnt1;
  }

  /*----- check sensor 2 -----*/
  if(digitalRead(S2) == HIGH) {
    cnt2 = T2;
    led_on = true;
  } else {
    if(cnt2 != 2) --cnt2;
  }

  /*----- check sensor 3 -----*/
  if(digitalRead(S3) == HIGH) {
    cnt3 = T3;
    led_on = true;
  } else {
    if(cnt3 != 3) --cnt3;
  }

  /*----- LED control -----*/
  if(led_on) digitalWrite(LED, HIGH); else digitalWrite(LED, LOW);
  
}
