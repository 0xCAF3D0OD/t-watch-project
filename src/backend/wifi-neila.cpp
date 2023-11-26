#include <WiFi.h>
#include <HTTPClient.h>
#include <TWatch_hal.h>

// Paramètres Wi-Fi
const char* ssid = "Manufacturing Lab";        // Nom du réseau Wi-Fi
const char* password = "Manufacturing2023!";   // Mot de passe du réseau Wi-Fi

// Fonction pour établir une connexion Wi-Fi
void wifi(TFT_eSPI *tft) 
{  
  bool ok = false;

  // Démarrage de la connexion Wi-Fi avec les identifiants fournis
  WiFi.begin(ssid, password);

  // Boucle jusqu'à ce que la connexion soit établie
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000); // Délai pour ne pas surcharger la boucle de tentative de connexion
    ok = true;
  }

  // Une fois connecté, configure l'affichage
  if (ok) 
  {
    tft->fillScreen(TFT_BLACK);     // Nettoie l'écran en le mettant en noir
    tft->setTextFont(2);            // Définit la police de texte
    tft->setTextColor(TFT_GREEN, TFT_BLACK); // Définit la couleur du texte et du fond
  }
}
