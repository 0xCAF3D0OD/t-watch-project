#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <TWatch_hal.h>

//attendre dans la loop l'entrée utilisateur 
//si il y a une entré utilisateur entré ici

bool verifyUser(String iduser) {
    // Ici, récupérez les informations de l'utilisateur depuis la base de données avec la fonction de bastien
    
    if (iduser.length() != storedIdUser.length()) {
        return 1;
    }

    for (int i = 0; i < iduser.length(); i++) {
        if (iduser[i] != storedIdUser[i]) {
            return 1;
        }
    }
    return 0;
}