void mensaje(String mensaje){
  bot->sendMessage(chatId, mensaje, "Markdown");  
  Serial.println(mensaje);
}

// Almacenar evento en la base de datos  
// Wish list - Lista de deseo
void log(){
  Serial.println("Almacenar en la base de datos, evento");
}

void apagarRouter(){
  Serial.println("Apagar Router");
  digitalWrite(pinRele, HIGH);
}

void encenderRouter(){
  Serial.println("Encender Router");
  digitalWrite(pinRele, LOW);
}

void terminar(){
  Serial.println("Terminar");
  modoConfiguracion = true;
  //esperar(1, 's'); //esperar 1 dia 'd'
  return; 
}

void resetRouter(){
  apagarRouter();
  esperar(TIMER_RESETROUTER_APAGAR);
  encenderRouter();
  log();
  esperar(TIMER_RESETROUTER_ENCENDER); // cambiar a 5 minutos 'm'
  if (ping()){
    return;
  }else {
    String textoMensaje = "No se ha podido establecer la conexión con internet, Contacte con el administrador\n";    
    mensaje(textoMensaje);
    terminar();
  }
}
