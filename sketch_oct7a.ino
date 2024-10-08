// Definición de pines para los motores
int motor1Pin1 = 9;
int motor1Pin2 = 10;
int motor2Pin1 = 11;
int motor2Pin2 = 12;

void setup() {
  // Iniciar comunicación serial con el módulo Bluetooth usando Serial (pines 0 y 1)
  Serial.begin(9600);

  // Configurar pines de los motores como salida
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    char command = Serial.read(); // Leer el comando enviado desde la app
    Serial.println(command);

    switch (command) {
      case 'F': // Avanzar (Forward)
        avanzar();
        break;
      case 'B': // Retroceder (Backward)
        retroceder();
        break;
      case 'L': // Girar a la izquierda (Left)
        girarIzquierda();
        break;
      case 'R': // Girar a la derecha (Right)
        girarDerecha();
        break;
      case 'S': // Detener (Stop)
        detener();
        break;
      default:
        detener(); // Si no es un comando válido, detener los motores
        break;
    }
  }
}

void avanzar() {
  // Ambos motores hacia adelante
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
}

void retroceder() {
  // Ambos motores hacia atrás
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
}

void girarIzquierda() {
  // Motor 1 hacia atrás, Motor 2 hacia adelante
  digitalWrite(motor1Pin1, LOW); // Motor 1 retrocede
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, HIGH); // Motor 2 avanza
  digitalWrite(motor2Pin2, LOW);
}

void girarDerecha() {
  // Motor 1 hacia adelante, Motor 2 hacia atrás
  digitalWrite(motor1Pin1, HIGH); // Motor 1 avanza
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW); // Motor 2 retrocede
  digitalWrite(motor2Pin2, HIGH);
}

void detener() {
  // Apagar ambos motores
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
}
