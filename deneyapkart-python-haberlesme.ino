void setup() {
  pinMode(D12, OUTPUT); // red
  pinMode(D13, OUTPUT); // green
  pinMode(D14, OUTPUT); // blue
  pinMode(D15, INPUT); // button
  Serial.begin(9600);
}

int mavi = LOW;
int kirmizi = LOW;
int yesil = LOW;

void led(String input){
    if (input == "kirmizi" or input == "kırmızı"){
      kirmizi = !kirmizi;  
    } else if (input == "yesil" or input == "yeşil"){
      yesil = !yesil;  
    } else if (input == "mavi"){
      mavi = !mavi;  
    }
    digitalWrite(D12, kirmizi);
    digitalWrite(D13, yesil);
    digitalWrite(D14, mavi);
}

void button(){
  Serial.println(digitalRead(D15));
  // buton ile ilgili diğer kodlar
}

void pMetre(){
  Serial.println(analogRead(A0));  
  // potansiyometre ile ilgili diğer kodlar
}

void iSensor(){
  Serial.println(analogRead(A1));  
  // ışık sensörü ile ilgili diğer kodlar
}

void loop() {
  String input = Serial.readString();
  input.replace("\n", "");
  input.replace("\r", "");
  input.trim(); // sağ ve solundaki boşlukları kaldır
  if (input == "button" or input == "buton"){
    button();
  } else if (input == "pmetre" or input == "potansiyometre"){
    pMetre();
  } else if (input == "isensor" or input == "ışık sensörü") {
    iSensor();
  } else {
    led(input); 
  }
}
