void setupRele(){
  pinMode(pinRele, OUTPUT);
  digitalWrite(pinRele, LOW);
}

void setupWifiManager(){   
  EEPROM.begin(TAMANO_EEPROM);
  delay(10);
  
  readFromEeprom(BOT_TOKEN_START, "BotToken");  
  readFromEeprom(CHAT_ID_START, "ChatId");
  EEPROM.commit();
    
  wifiManager.setSaveConfigCallback(saveConfigCallback);

  //Agregar configuracion adicional en la pagina web del administrador de WIFI
  // para el token y el chat_id del bot
  WiFiManagerParameter custom_bot_id("botid", "Bot Token", botToken, 50);
  WiFiManagerParameter custom_chat_id("chatid", "Cliente Id", chatId, 12);
  wifiManager.addParameter(&custom_bot_id);  
  wifiManager.addParameter(&custom_chat_id); 
  
  wifiManager.setBreakAfterConfig(true);  
  resetCredenciales();

  //wifiManager.resetSettings(); //Test, comentar esta linea
  if (!wifiManager.autoConnect("RouterReboot")) {
    Serial.println("Error al conectar, se procede a reiniciar para ver si se conecta");
    delay(3000);
    ESP.reset();
    delay(5000);
  }

  strcpy(botToken, custom_bot_id.getValue());
  strcpy(chatId, custom_chat_id.getValue());
  Serial.println(botToken);
  Serial.println(chatId);

  if (shouldSaveConfig) {
    writeToEeprom(BOT_TOKEN_START, "BotToken");   
    writeToEeprom(CHAT_ID_START, "ChatId");    
    EEPROM.commit();
  }

  bot = new UniversalTelegramBot (botToken, client);  
  
  Serial.println("Conectado... :)");
  Serial.println("Ip local: ");
  Serial.println(WiFi.localIP());
}

void setupTelegram(){
  // Only required on 2.5 Beta
  client.setInsecure();
  
  // longPoll mantiene abierta la solicitud de Telegram durante unos segundos si no hay mensajes
  // Esto mejora enormemente el tiempo de respuesta del bot, pero solo es realmente adecuado para proyectos
  // donde la interacción inicial proviene de Telegram ya que las solicitudes bloquearán el bucle para
  // la longitud de la encuesta larga
  bot->longPoll = 60;
  mensaje("Bot Funcionando!!\n");
}