#include "backend.hpp"

// Fonction pour envoyer une requête POST pour les notifications
void postRequestNotification(const string &url, Notification &notification)
{
    // Créer un document JSON pour la notification
    DynamicJsonDocument jsonDoc(128);
    jsonDoc["acked"] = true;

    // Convertir le document JSON en chaîne
    String postData;
    serializeJson(jsonDoc, postData);

    // Initialiser un client HTTP
    HTTPClient http;

    // Commencer la connexion HTTP
    http.begin(url.c_str());
    http.addHeader("Content-Type", "application/json");

    // Envoyer la requête POST avec les données JSON
    int httpCode = http.POST(postData);

    // Gérer la réponse de la requête
    if (httpCode > 0)
    {
        // Lire la réponse de la requête
        String response = http.getString();
        http.end();
    }
    else
    {
        // Gérer les erreurs de la requête
        Serial.println("Error in HTTP request");
    }

    // Toujours fermer la connexion HTTP, même en cas d'erreur
    http.end();
}

// Fonction pour envoyer une requête POST pour le pairing
void postRequestPairing(const string &userId, const string &deviceId)
{
    // Initialiser un client HTTP
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

    // Gérer la réponse de la requête
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
        // Gérer les erreurs de la requête
    }

    // Toujours fermer la connexion HTTP, même en cas d'erreur
    http.end();
}

// Fonction pour envoyer une requête POST pour supprimer le pairing
void postRequestPairingDelete(const string &deviceId)
{
    // Initialiser un client HTTP
    HTTPClient http;

    // Construire l'URL avec le deviceId
    string url = "http://mes.42lausanne.ch/api/v1/Pairing/DeletePairingUserDeviceByDeviceId?deviceId=" + deviceId;

    // Commencer la connexion HTTP
    http.begin(url.c_str());

    // Envoyer la requête POST (le corps de la requête est vide ici)
    int httpCode = http.POST("");

    // Gérer la réponse de la requête
    if (httpCode > 0)
    {
        // Lire la réponse de la requête
        String response = http.getString();

        // Traiter la réponse JSON si nécessaire
        DynamicJsonDocument jsonDoc(1024);
        deserializeJson(jsonDoc, response);

        // Votre logique de traitement de la réponse ici

        // Toujours fermer la connexion HTTP, même en cas de succès
        http.end();
    }
    else
    {
        // Gérer les erreurs de la requête
        http.end();
    }
}