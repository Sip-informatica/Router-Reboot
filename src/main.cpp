/*
 * Resetear router si pierde la conexion a internet
 * Autor: sip-informatica.es
 */

#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>
#include <ESP8266Ping.h>
#include <stdio.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h> // instalar la version 5.x.x  ArduinoJson@5.13.4
#include <EEPROM.h>
#include <variables.h>
#include <waitAbout.h>
#include <pingRemoteComuter.h>
#include <optionsRouter.h>
#include <handleEeprom.h>
#include <buttonResetCredentials.h>
#include <handleMessages.h>
#include <setupSet.h>

void setup() {
  Serial.begin(115200);
  delay(10);  
  setupRele();  
  setupBotonResetCredenciales();  
  setupWifiManager(); 
  setupTelegram();
  
  mensaje("Entrar en /options y elegir \"Salir Configuración\"\n");
}

void loop() { 
  getUpdatesTelegram();
  while(modoConfiguracion){
  getUpdatesTelegram();
  }  
  //ping al equipo remoto (google.es)
  if(TIMER_PING_TEST) { //cambiar 1 hora 'h'
    Serial.println("Ping Exitoso!!");    
  } else {
    Serial.println("Ping Error :(");
    if(TIMER_PING_ERROR){ //cambiar 5 minutos 'm' 3 veces
    return;
    }else{
      resetRouter();
    }
  }
}