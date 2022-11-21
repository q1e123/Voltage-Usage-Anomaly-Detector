#include "list.h"
#include <SPI.h>
#include <SD.h>
#include <string>

char* read(char* file_path){
    
    init();
    File myFile = SD.open(file_path);
    std::string text;
    if(myFile){
        //read from the file until there's nothing else in int:
        while(myFile.available()){
            text.append(myFile.read());
        }
        myFile.close();
        char resultArray[text.length()];
        text.copy(resultArray, text.length());
        return resultArray;
    }
    else 
    {
        Serial.prin("error opening file")''
    }
}

void write(char* file_path, char* message){
   
   init();
   File myFile = SD.open(file_path, FILE_WRITE);
    // if the file opened okay, write to it:
   if(myFile) {
    Serial.print("Writing to file...");
    myFile.println(message);
    // close the file
    myFile.close();
    Serial.print("done.");
   }else {
    // if the file didn't open, print an error:
    Serial.println("error opening file");
   }

void init(){
    // Open serial communications and wait for port to open:
    Serial.begin(9600);
    while(!Serial)
    {
    ; // wait for the serial port to connect. Needed for native USB port only
    }

    Serial.print("Initializing SD card...");
    if(!SD.begin(4)){
    Serial.println("initializantion failed!");
    while(1);
    }
    Serial.println("initialization done.");
    }

}