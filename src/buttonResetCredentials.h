void setupBotonResetCredenciales(){
  pinMode(botonResetCredenciales, INPUT_PULLUP);    
}

void resetCredenciales(){  
  // Reset Wemos y pulsar boton de reset Settings, para borrar credenciales 10sg
  esperar(5,'s'); 
  if (digitalRead(botonResetCredenciales) == LOW){      
    esperar(5, 's');
    if (digitalRead(botonResetCredenciales) == LOW){
      wifiManager.resetSettings();      
    }
  }
}
