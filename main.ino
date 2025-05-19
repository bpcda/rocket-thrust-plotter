#include "HX711.h"

#define LOADCELL_DOUT_PIN  2
#define LOADCELL_SCK_PIN   3

HX711 scale;
float calibration_factor = 204.16;  // Impostare il calibration factor pre-calibrato
bool recording = false;             // Stato della registrazione
unsigned long startTime = 0;        // Tempo di inizio registrazione

void setup() {
  Serial.begin(9600);
  Serial.println("Inserisci 'start' per iniziare la registrazione.");
  
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  scale.set_scale(calibration_factor);
  scale.tare(); // Tara la cella una volta all'avvio
}

void loop() {
  // Controllo dei comandi Serial
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    command.trim();
    if (command.equalsIgnoreCase("start")) {
      scale.tare();
      recording = true;
      startTime = millis();
      Serial.println("Registrazione avviata. Invia 'stop' per terminare.");
    }
    else if (command.equalsIgnoreCase("stop")) {
      recording = false;
      Serial.println("Registrazione terminata.");
    }
    else if (command.equalsIgnoreCase("tara")) {
      scale.tare();
    }
  }
  
  // Se siamo in registrazione, leggi la cella e invia dati
  if (recording) {
    // Leggi la massa in grammi (con 2 decimali)
    float mass = scale.get_units(2);
    // Converte la massa in forza in newton (massa in kg * 9.81)
    float force = (mass / 1000.0) * 9.81;
    // Calcola il tempo trascorso dall'inizio della registrazione (in ms)
    unsigned long elapsedTime = millis() - startTime;
    
    // Invia i dati in formato "tempo, forza"
    Serial.print(elapsedTime);
    Serial.print(",");
    Serial.println(force, 3);
    
    delay(5); // Campiona ogni 5 ms
  }
}
