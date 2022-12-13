double get_voltage(){
    
    
    //variables for measured voltage and calculated current
    double Vout = 0;
    double Current = 0;

    //constants for scale factor
    const double scale_factor = 0.1; //20A

    //Constants for A/D converter resolution
    //10-bit ADC, so 1024 possible values
    //reference voltage is 5V
    //zero point is half of reference voltage

    const double vRef = 5.00;
    const double resConvert = 1024;
    double resADC = vRef/resConvert;
    double zeroPoint = vRef/2;

    
        //Vout is read 1000 times for precision
        for (int i=0;i<1000;i++){
            Vout = (Vout + (resADC*analogRead(A0)));
            delay(1);
        }
        //Get Vout in mV
        Vout=Vout/1000;

        //Convert Vout into Current using scale Factor
        Current=(Vout - zeroPoint)/scale_factor;

        //print Vout and Current to two Current 
        Serial.print("Vout= ");
        Serial.print(Vout,2);
        Serial.print(" Volts");
        Serial.print("\t Current = ");
        Serial.print(Current,2);
        Serial.println(" Amps");

        delay(1000);

        
    return Vout;
}