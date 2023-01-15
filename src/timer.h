void wait(size_t duration){
 //frecventa in hz a placii Arduino Uno ATMega 328p
 long arduinoFrequency=16000000;
 //aflarea numarului de cicluri, din formula: 'frecventa=cicluri/secunde'
 long looptime=arduinoFrequency*duration;
 //cream un for gol pentru a simula trecerea secundelor
 for(int i=0;i<looptime;i++){
 }
}
