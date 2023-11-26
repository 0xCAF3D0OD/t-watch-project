#include "backend.hpp"

void    postRequestNotification(string url, Notification &notification)
{
    DynamicJsonDocument jsonDoc(128);
    jsonDoc["acked"] = true;

    String postData;
    serializeJson(jsonDoc, postData);

    HTTPClient http;

    http.begin(url.c_str());
    http.addHeader("Content-Type", "application/json");

    int httpCode = http.POST(postData);

    if (httpCode > 0)
    {
        String response = http.getString();
        http.end();
    }
    else
    {
        // Gérer les erreurs de la requête
        Serial.println("Error in HTTP request");
    }
    // N'oubliez pas de gérer la fin de la requête même en cas d'erreur
    http.end();
}

void    postRequestPairing(const string &userId, const string &deviceId)
{
    HTTPClient http;

    // Construire l'URL avec les paramètres
    string url = "http://mes.42lausanne.ch/api/v1/Pairing/PairingUserDevice";
    url += "?userId=" + userId;
    url += "&deviceId=" + deviceId;

    // Commencer la connexion HTTP
    http.begin(url.c_str());

    // Spécifier le type de contenu de la requête (application/json dans votre cas)
    http.addHeader("Content-Type", "application/json");

    // Envoyer la requête POST (vide car les paramètres sont dans l'URL)
    int httpCode = http.POST("{}");

    if (httpCode == HTTP_CODE_OK)
    {
        // La requête a réussi
        String response = http.getString();

        // Traiter la réponse JSON si nécessaire
        DynamicJsonDocument jsonDoc(1024);
        deserializeJson(jsonDoc, response);
    }
    else
    {
        // erreur
    }
    http.end();
}

void postRequestPairingDelete(const string& deviceId)
{
    HTTPClient http;

    // Construire l'URL avec le deviceId
    std::__cxx11::string url = "http://mes.42lausanne.ch/api/v1/Pairing/DeletePairingUserDeviceByDeviceId?deviceId=" + deviceId;

    // Commencer la connexion HTTP
    http.begin(url.c_str());

    // Envoyer la requête POST (le corps de la requête est vide ici)
    int httpCode = http.POST("");

    if (httpCode > 0) {
        String response = http.getString();

        // Traiter la réponse ici
        DynamicJsonDocument jsonDoc(1024);
        deserializeJson(jsonDoc, response);

        // Votre logique de traitement de la réponse ici

        http.end();
    } else {
        // Gérer les erreurs
        http.end();
    }
}
