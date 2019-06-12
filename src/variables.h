#define TAMANO_EEPROM 64
#define BOT_TOKEN_START 0
#define BOT_TOKEN_LENGTH 46
#define CHAT_ID_START 50
#define CHAT_ID_LENGTH 9
// Esperar
#define TIMER_PING_TEST ping(1, 'h')      //cambiar 1 hora 'h'
#define TIMER_PING_ERROR ping (5, 'm', 3) //cambiar 5 minutos 'm' 3 veces
#define TIMER_RESETROUTER_APAGAR 10, 's'
#define TIMER_RESETROUTER_ENCENDER 5, 'm' // cambiar a 5 minutos 'm'

const char* remote_host = "www.google.com";                                    
const int pinRele = 5;                    // Pin D1 --> GPIO 05, Wemos 8286
const int botonResetCredenciales = 0;     // Pin D3 - Gpio0 - 10k pullUp interrupt

char botToken[BOT_TOKEN_LENGTH] = "";     // TELEGRAM_BOT_TOKEN config.h
char chatId[CHAT_ID_LENGTH] = "";
bool shouldSaveConfig = false;            // bandera para grabar datos
bool modoConfiguracion = true;            // bandera configuracion inicio Telegram

WiFiManager wifiManager; 
WiFiClientSecure client;
UniversalTelegramBot *bot;
