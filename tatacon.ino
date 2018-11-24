/*!
 * @file tatacon.ino
 * @brief tatacon controller
 * @auther kaneko
 * @date 2018-11-24 test release
 */

/*=========================================
  contents
===========================================*/
#define     LED     13      /*! LED pin         */

/*=========================================
  globals
===========================================*/

/*=========================================
  functions
===========================================*/
/*!
 * @brief setup
 * @return void
 */
void setup() {
  pinMode(LED, OUTPUT);
}

/*!
 * @brief loop
 * @return void
 */
void loop() {
  digitalWrite(LED, HIGH);
  delay(500);
  digitalWrite(LED, LOW);
  delay(500);
}
