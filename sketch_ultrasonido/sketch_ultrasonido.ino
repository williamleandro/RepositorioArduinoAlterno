const int Trigger = 2;   //Pin digital 2 para el Trigger del sensor
const int Echo = 3;   //Pin digital 3 para el Echo del sensor
bool prendido=true;
long valorAnterior=0;

void setup() {
  Serial.begin(9600);//iniciailzamos la comunicación
  pinMode(Trigger, OUTPUT); //pin como salida
  pinMode(Echo, INPUT);  //pin como entrada
  pinMode(13,OUTPUT);
  digitalWrite(Trigger, LOW);//Inicializamos el pin con 0
 
}

void loop()
{

  unsigned long t; //timepo que demora en llegar el eco
  long d; //distancia en centimetros
  

  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(Trigger, LOW);
  
  t = pulseIn(Echo, HIGH); //obtenemos el ancho del pulso
  d = ( (t/2) / 29.1 );             //escalamos el tiempo a una distancia en cm


  if( ( (d < valorAnterior - 5) || (d > valorAnterior + 5 )   ) )
  {
    prendido=true; 
    valorAnterior=d; 
  }

  if(prendido)
  {
    digitalWrite(13,HIGH);
      
  }
  else
  {
    digitalWrite(13,LOW);
      
  }


  delay(1000);
  prendido=false;  

  Serial.print("Distancia: ");
  Serial.print(d);      //Enviamos serialmente el valor de la distancia
  Serial.print("cm");
  Serial.println();
}
