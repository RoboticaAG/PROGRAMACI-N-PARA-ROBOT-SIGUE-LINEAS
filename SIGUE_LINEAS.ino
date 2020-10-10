//CÓDIGO DE ROBOT SIGUE LINEA CON ARDUINO HECHO POR EL CANAL ROBÓTICA AG EN YOUTUBE

int M1D1=2; //pin digital 1 para el motor 1 establecido en el pin 2 de arduino
int M1D2=4; //pin digital 2 para el motor 1 establecido en el pin 4 de arduino
int M1IN=3; //pin analogico para el motor 1 establecido en el pin 3 de arduino

int M2D1=5; //pin digital 1 para el motor 2 establecido en el pin 5 de arduino
int M2D2=7; //pin digital 2 para el motor 2 establecido en el pin 7 de arduino
int M2IN=6; //pin analogico para el motor 2 establecido en el pin 6 de arduino

int SENSORDER=8; //sensor puesto para el lado derecho del robot establecido en el pin 8 de arduino
int SENSORIZQ=9; //sensor puesto para el lado izquierdo del robot establecido en el pin 9 de arduino

int VELRAPIDA=150; //numero de tiempo en milisegundos para velocidad rapida 
int VELMEDIA=100; //numero de tiempo en milisegundos para velocidad media
int VELLENTA=0; //numero de tiempo en milisegundos para velocidad lenta

void GIRARDERECHA() { //función hecha para girar a la derecha

  digitalWrite(M1D1, LOW);
  digitalWrite(M1D2, HIGH);
  digitalWrite(M2D1, LOW);
  digitalWrite(M2D2, HIGH);
  analogWrite(M1IN, VELLENTA);
  analogWrite(M2IN, VELRAPIDA);
}

void GIRARIZQUIERDA() { //función hecha para girar a la izquierda

  digitalWrite(M1D1, LOW);
  digitalWrite(M1D2, HIGH);
  digitalWrite(M2D1, LOW);
  digitalWrite(M2D2, HIGH);
  analogWrite(M1IN, VELRAPIDA);
  analogWrite(M2IN, VELLENTA);
}

void IRDERECHO() { //función hecha para ir derecho

  digitalWrite(M1D1, LOW);
  digitalWrite(M1D2, HIGH);
  digitalWrite(M2D1, LOW);
  digitalWrite(M2D2, HIGH);
  analogWrite(M1IN, VELMEDIA);
  analogWrite(M2IN, VELMEDIA);
}

void setup() {
  
pinMode(M1D1, OUTPUT); //declaramos como salida
pinMode(M1D2, OUTPUT); //declaramos como salida
pinMode(M1IN, OUTPUT); //declaramos como salida
pinMode(M2D1, OUTPUT); //declaramos como salida
pinMode(M2D2, OUTPUT); //declaramos como salida
pinMode(M2IN, OUTPUT); //declaramos como salida
pinMode(SENSORDER, INPUT); //declaramos como entrada
pinMode(SENSORIZQ, INPUT); //declaramos como entrada
}

void loop() {

  if ((digitalRead(SENSORDER)==LOW)&&(digitalRead(SENSORIZQ)==LOW)) {
    IRDERECHO(); //si ambos sensores detectan algo va a ir derecho 
  }

  if ((digitalRead(SENSORDER)==HIGH)&&(digitalRead(SENSORIZQ)==LOW)) {
    GIRARIZQUIERDA(); //si el sensor izquierdo detecta algo y el sensor derecho nada, va a girar a la izquierda
  }

  if ((digitalRead(SENSORDER)==LOW)&&(digitalRead(SENSORIZQ)==HIGH)) {
    GIRARDERECHA(); //si el sensor derecho detecta algo y el sensor izquierdo nada, va a girar a la derecha
  }

  if ((digitalRead(SENSORDER)==HIGH)&&(digitalRead(SENSORIZQ)==HIGH)) {
    IRDERECHO(); //si ambos sensores no detectan nada va a ir derecho
  }

}
