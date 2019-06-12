void manejarNuevosMsj(int numNuevosMensajes){
  for (int i = 0; i < numNuevosMensajes; i++){
    // Si el type es un "callback_query", se presiono un boton del teclado en linea
    if (bot->messages[i].type == F("callback_query")){
      String text = bot->messages[i].text;
      Serial.println(text);
      mensaje(text);

      if (text == F("Reset credenciales")){
        wifiManager.resetSettings();
      }
      else if (text == F("Reset Wifi")){
        wifiManager.autoConnect("RouterReboot");
      }else if (text == F("Reset router")){
        resetRouter();
      }else if (text == F("Salir Configuracion"))
      {
        modoConfiguracion = false;
      }    
    }
    else{

      String chat_id = String(bot->messages[i].chat_id);
      String text = bot->messages[i].text;

      if (text == F("/options"))
      {
        String keyboardJson = F("[[{ \"text\" : \"Reset credenciales\", \"callback_data\" : \"Reset credenciales\" },{ \"text\" : \"Reset Wifi\", \"callback_data\" : \"Reset Wifi\" }],");        
        keyboardJson += F("[{ \"text\" : \"Reset router\", \"callback_data\" : \"Reset router\" },{ \"text\" : \"Salir Configuracion\", \"callback_data\" : \"Salir Configuracion\" }]]");
        bot->sendMessageWithInlineKeyboard(chat_id, "Elije una opción: ", "", keyboardJson);
      }
      if (text == F("/start")){
        bot->sendMessage(chat_id, "/options : Devuelve opciones del bot", "Markdown");
      }
    }
  }
}

void getUpdatesTelegram(){
  int numNuevosMensajes = bot->getUpdates(bot->last_message_received + 1);

    if (numNuevosMensajes) {
      Serial.println("respuesta");
      manejarNuevosMsj(numNuevosMensajes);  
    }
}
