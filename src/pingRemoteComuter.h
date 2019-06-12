bool ping(){    
  return Ping.ping(remote_host);
}

bool ping(unsigned long tiempo, char date){  
  esperar(tiempo, date);
  return Ping.ping(remote_host);
}

// Ping al equipo remoto ? veces
bool ping(unsigned long tiempo, char date, int veces){  
  int contador = 0;
  for (int i=0; i<(veces+3); i++){ 
    esperar(tiempo, date);
    if(Ping.ping(remote_host)){
      contador++;
    }    
  }
  Serial.print (contador);
  Serial.println(" Ping exitosos");
  if (contador>=veces){    
    return true;
  }  
  return false;
}
