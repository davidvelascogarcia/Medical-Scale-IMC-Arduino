#include <LiquidCrystal.h> // Incluir Libreria

// Programa en C, de Cálculo de IMC


int ir_sensor0 = A0;  // Sensor Optico

int ir_sensor1 = A1;  //  Tension de Salida del AD620
int ir_sensor2 = A2;  //  GND del Circuito de Peso


LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Inicializar Display

void setup() {

  lcd.begin(16, 2); // Iniciar el LCD
  lcd.setCursor(0, 1); // Posicionar Cursor

  
  // Medidor de Peso de la Bascula de IMC
  
  // inicializa la comunicación serial en 9600 bits por segundo
  
  Serial.begin(9600);

  lcd.print("Iniciando Programa de Medición del Peso");
  lcd.setCursor(0, 2); // Posicionar Cursor
  lcd.print("Programa de ");
  delay(1000); // Tiempo de espera de 1 segundo
  lcd.setCursor(0, 1); // Posicionar Cursor
  lcd.print("Medición del Peso");
  lcd.setCursor(0, 2); // Posicionar Cursor
  lcd.print("");
  
  delay(1000); // Tiempo de espera de 1 segundo
  lcd.setCursor(0, 1); // Posicionar Cursor
  lcd.print("Iniciando....");
  delay(1000); // Tiempo de espera de 1 segundo
  lcd.print("Pesando...");
  delay(2000); // Tiempo de espera de 2 segundos


   
      int j=0;
      float tension1[10];
      float tension2[10];
      float tension3[10];
      int peso;
      int pesosuma;
      pesosuma=0;
      int pesofinalsinaprox;
      int pesofinalaprox;
      
         for (j=0;j<10;j=j+1) {


    
  // lee el pin de entrada analogico (pin A1)
  int valor_sensor1 = analogRead(A1);
  
  // Convierto la lectura analogica (la cual va desde 0 - 1023) hacia un voltaje (0 - 5V):
  float voltaje1 = valor_sensor1 * (5.0 / 1023.0);
  // muestra el valor

  tension1[j]=voltaje1;

    // lee el pin de entrada analogico (pin A0)
  int valor_sensor2 = analogRead(A2);
  
  // Convierto la lectura analogica (la cual va desde 0 - 1023) hacia un voltaje (0 - 5V):
  float voltaje2 = valor_sensor2 * (5.0 / 1023.0);
  // muestra el valor

  tension2[j]=voltaje2;

  
  tension3[j]=tension1[j]-tension2[j];
  
  lcd.print("El Peso medido es de: ");
  lcd.setCursor(0, 2); // Posicionar Cursor
  lcd.print("es de: ");
  delay(2000); // Tiempo de espera de 2 segundos
  
  //Convertimos a Kg
  
  peso=((tension3[j])-1.78) * 363.64;

  lcd.setCursor(0, 1); // Posicionar Cursor
  lcd.print(peso);
  lcd.setCursor(0, 2); // Posicionar Cursor
  lcd.print(" Kg");
  delay(1000); // Tiempo de espera de 1 segundo

  pesosuma=peso+pesosuma;
  }
  pesofinalsinaprox=pesosuma/j;
  pesofinalaprox=pesofinalsinaprox-4;


  lcd.setCursor(0, 2); // Posicionar Cursor
  lcd.print("");
  lcd.setCursor(0, 1); // Posicionar Cursor
  lcd.print("Restando pesos");
  
  lcd.setCursor(0, 2); // Posicionar Cursor
  lcd.print("medios de");
  delay(1000); // Un segundo de Espera
  lcd.setCursor(0, 1); // Posicionar Cursor
  lcd.print("vestimenta...");
  lcd.setCursor(0, 2); // Posicionar Cursor
  lcd.print("");
  

  delay(2000); // tiempo de espera
  lcd.setCursor(0, 1); // Posicionar Cursor
  
  lcd.print("Su peso final es de: ");
  lcd.setCursor(0, 2); // Posicionar Cursor
  lcd.print("es de: ");
  delay(1500); // Un segundo y medio de espera
  lcd.setCursor(0, 1); // Posicionar Cursor
  lcd.print(pesofinalaprox);
  lcd.setCursor(0, 2); // Posicionar Cursor
  lcd.print(" Kg");
  delay(1500); // Un segundo y medio de espera
    

    // Código de Medición de Altura
  
 
      int lectura;
      int suma=0;
      int media,i=0;
      int vector[10];
      int altura_final;
      int altura_metros;
      int altura_definitiva;

    lcd.setCursor(0, 1); // Posicionar Cursor
    lcd.print("Iniciando Programa de ");
    lcd.setCursor(0, 2); // Posicionar Cursor
    lcd.print("Medición del Sensor Optico");
    delay(1500); // Un segundo y medio de espera
    lcd.setCursor(0, 1); // Posicionar Cursor
    lcd.print("Sensor Optico");
    lcd.setCursor(0, 2); // Posicionar Cursor
    lcd.print("");
    delay(1000); // Tiempo de espera de 1 segundo
    lcd.setCursor(0, 1); // Posicionar Cursor
    lcd.print("Iniciando....");
    delay(1000); // Tiempo de espera de 1 segundo
    lcd.print("Midiendo...");
    delay(2000); // Tiempo de espera de 2 segundos
 

      for (i=0;i<10;i=i+1) {
    

  lectura = analogRead(ir_sensor0); // Lectura del sensor 0
  vector[i]=pow(3027.4 / lectura, 1.2134);
  
  lcd.setCursor(0, 1); // Posicionar Cursor
  lcd.print("La Altura Medida");
  lcd.setCursor(0, 2); // Posicionar Cursor
  lcd.print("es de: ");
  delay(1000); // Tiempo de espera de 1 segundo
  lcd.setCursor(0, 1); // Posicionar Cursor
  lcd.print(vector[i]);
  lcd.setCursor(0, 2); // Posicionar Cursor
  lcd.print("cm");
 
  delay(1000); // Tiempo de espera de 1 segundo

  suma=suma+vector[i];
  }
  
  media=suma/i;


  lcd.setCursor(0, 1); // Posicionar Cursor
  lcd.print("El Valor Final ");
  lcd.setCursor(0, 2); // Posicionar Cursor
  lcd.print("Medio de");
  delay(1000); // Tiempo de espera de 1 segundos
  lcd.setCursor(0, 1); // Posicionar Cursor
  lcd.print("Medicción es:  ");
  lcd.setCursor(0, 2); // Posicionar Cursor
  lcd.print("");

  delay(2000); // Tiempo de espera de 2 segundos

  lcd.setCursor(0, 1); // Posicionar Cursor
  lcd.print(media);
  lcd.setCursor(0, 2); // Posicionar Cursor
  lcd.print("cm");
  delay(2000); // Tiempo de espera de 2 segundos
  
  altura_final=200-media;
  altura_metros=altura_final/100; //Convertir a Metros
  altura_definitiva=((altura_metros)-(3/100)); // Restamos la altura de la propia Báscula

  lcd.setCursor(0, 1); // Posicionar Cursor
  lcd.print("Su altura es de:");
  lcd.setCursor(0, 2); // Posicionar Cursor
  lcd.print("");
  delay(2000); // Tiempo de espera de 2 segundos
  lcd.print(altura_definitiva);
  lcd.setCursor(0, 2); // Posicionar Cursor
  lcd.print(" m");
  delay(2000); //Esperamos 2 segundos


 // Calculo de IMC

  lcd.setCursor(0, 1); // Posicionar Cursor
  lcd.print("Se procedera al");
  lcd.setCursor(0, 2); // Posicionar Cursor
  lcd.print("calculo del IMC");
  delay(2000); //Esperamos 2 segundos
  lcd.setCursor(0, 2); // Posicionar Cursor
  lcd.print("");
  lcd.setCursor(0, 1); // Posicionar Cursor
  lcd.print("Calculando IMC..."); //Imprimimos un mensaje 
  delay(2000); //Esperamos 2 segundos
  

  lcd.print("Su IMC es: "); //Imprimimos un mensaje 
  delay(4000); //Esperamos 4 segundos
 

  int imc;

  imc=((pesofinalaprox)/((altura_definitiva)*(altura_definitiva)));

  lcd.print(imc); //Imprimimos un mensaje inicial
  delay(6000); //Esperamos 6 segundos
  

  lcd.print("Dado su IMC, y parametros"); //Imprimimos un mensaje 
  lcd.setCursor(0, 2); // Posicionar Cursor
  lcd.print("parametros");
  delay(2000); //Esperamos 2 segundos
  
  lcd.setCursor(0, 2); // Posicionar Cursor
  lcd.print("");
  lcd.setCursor(0, 1); // Posicionar Cursor
  
  lcd.print("Podemos estimar"); //Imprimimos un mensaje 
  lcd.setCursor(0, 2); // Posicionar Cursor
  lcd.print("que:");
  delay(2000); //Esperamos 2 segundos
  lcd.setCursor(0, 2); // Posicionar Cursor
  lcd.print("");

  lcd.setCursor(0, 1); // Posicionar Cursor
  lcd.print("Su rango es:"); //Imprimimos un mensaje 
  delay(2000); //Esperamos 2 segundos
  

if (18.5<imc<24.99) {
  lcd.print("Peso Normal"); //Imprimimos un mensaje 
  delay(6000); //Esperamos 6 segundos
  
  
}
if (25<imc<29.99) {
  lcd.print("Sobrepeso"); //Imprimimos un mensaje 
  delay(6000); //Esperamos 6 segundos
 
  
}
if (30<imc<34.99) {
  lcd.print("Obesidad Tipo I"); //Imprimimos un mensaje 
  delay(6000); //Esperamos 6 segundos
  
  
}

if (35<imc<40) {
  lcd.print("Obesidad Tipo II"); //Imprimimos un mensaje 
  delay(6000); //Esperamos 6 segundos
  
  
}
if (imc>40) {
  lcd.print("Obesidad Tipo III"); //Imprimimos un mensaje 
  delay(6000); //Esperamos 6 segundos

}
if (17<imc<18.49) {
  lcd.print("Delgadez Aceptable"); //Imprimimos un mensaje 
  delay(6000); //Esperamos 6 segundos

}
if (16<imc<16.99) {
  lcd.print("Delgadez Moderada"); //Imprimimos un mensaje 
  delay(6000); //Esperamos 6 segundos
  
  
}
if (imc<15.99) {
  lcd.print("Delgadez Severa"); //Imprimimos un mensaje 
  delay(6000); //Esperamos 6 segundos
  }

  
  delay(3000); //Esperamos 6 segundos

 lcd.print("Fin del Programa   "); //Imprimimos un mensaje 

}
  
void loop() {

  
   
}
