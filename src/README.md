# Configuración 
El archivo de configuración es variables.h 
>Las variables más relvantes son:
```c
// Esperar
#define TIMER_PING_TEST ping(1, 'h')      //cambiar 1 hora 'h'
#define TIMER_PING_ERROR ping (5, 'm', 3) //cambiar 5 minutos 'm' 3 veces
#define TIMER_RESETROUTER_APAGAR 10, 's'
#define TIMER_RESETROUTER_ENCENDER 5, 'm' // cambiar a 5 minutos 'm'
```
Estas variables se pasa como parametros al método `esperar(unsigned long tiempo, char date);` 
> Que se encuentra en el arhivo `waitAbout.h`
```c++
// Esperar unidad de tiempo. d-dia, h-hora, m-minutos, s-segundos
void esperar(unsigned long tiempo, char date){
  unsigned long tiempoEspera = 1000;
  switch (date){
    case 'd':
    tiempoEspera = tiempo*(1000*60*60*24);
    break;
    case 'h':
    tiempoEspera = tiempo*(1000*60*60);
    break;
    case 'm':
    tiempoEspera = tiempo*(1000*60);
    break;
    case 's':
    tiempoEspera = (tiempo*1000);
    break;

  }  
  delay(tiempoEspera);
}
```
