
//devolucion de la llamada notificando la necesidad de guardar la configuracion
void saveConfigCallback () {
  Serial.println("Guardar la configuración");
  shouldSaveConfig = true;
}

void readFromEeprom(int offset, String campo){  
  Serial.println("Leer campos desde Eeprom");
  if (campo == "BotToken"){
    for(int i = offset; i<BOT_TOKEN_LENGTH; i++ ){
    botToken[i] = EEPROM.read(i);    
    Serial.print(botToken[i]);
    }
  }
  if (campo == "ChatId"){
    int index = 0;
    for(int i = offset; i<(offset+CHAT_ID_LENGTH); i++ ){
    chatId[index] = EEPROM.read(i);    
    Serial.print(chatId[index]);
    index++;
    }
  }  
}

void writeToEeprom(int offset, String campo){
  Serial.println("Escribir valores de los campos en la Eeprom");
  if (campo == "BotToken"){
    for(int i = offset; i<BOT_TOKEN_LENGTH; i++ ){
      EEPROM.write(i, botToken[i]);      
      Serial.print(botToken[i]);
    }
  }
  if (campo == "ChatId"){
    int index = 0;
    for(int i = offset; i<(offset+CHAT_ID_LENGTH); i++ ){      
      EEPROM.write(i, chatId[index]);            
      Serial.print(chatId[index]);
      index++;    
    }
  } 
   delay(10);   
}
