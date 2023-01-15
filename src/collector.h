double get_voltage(){
    
    
    //variabile pentru masurarea voltilor si calcularea curentului
    double Vout = 0;
    double Current = 0;

   
    const double scale_factor = 0.1; 

    //Constante pentru rezolutia convertorului A/D
    //10-bit ADC, deci 1024 posibile valori
    //voltajul de referinta: 5V
    //zero point e jumatate din voltajul de referinta

    const double vRef = 5.00;
    const double resConvert = 1024;
    double resADC = vRef/resConvert;
    double zeroPoint = vRef/2;

    
        //Vout e citit de 1000 de ori, pentru precizie
        for (int i=0;i<1000;i++){
            Vout = (Vout + (resADC*analogRead(A0)));
            delay(1);
        }
        //Conversie in mV
        Vout=Vout/1000;

        
        Current=(Vout - zeroPoint)/scale_factor;

        //Printare
        Serial.print("Vout= ");
        Serial.print(Vout,2);
        Serial.print(" Volts");
        Serial.print("\t Current = ");
        Serial.print(Current,2);
        Serial.println(" Amps");

        delay(1000);

        
    return Vout;
}
