void wait(size_t duration){
 long arduinoFrequency=16000000;
 long looptime=arduinoFrequency*duration;
 for(int i=0;i<looptime;i++){
 }
}
