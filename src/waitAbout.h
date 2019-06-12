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