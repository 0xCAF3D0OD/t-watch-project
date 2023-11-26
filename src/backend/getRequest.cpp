#include "backend.hpp"

// Fonction pour effectuer une requête GET et récupérer un utilisateur
void getRequestUser(std::string url, User &user)
{
    // Initialiser un client HTTP
    HTTPClient http;

    // Commencer la connexion HTTP avec l'URL spécifiée
    http.begin(url.c_str());
    int httpCode = http.GET();

    // Vérifier si la requête a réussi
    if (httpCode > 0)
    {
        // Lire la réponse de la requête
        String response = http.getString();

        // Traiter la réponse JSON
        DynamicJsonDocument jsonDoc(1024);
        deserializeJson(jsonDoc, response);

        // Vérifier la présence des clés nécessaires dans la réponse JSON
        if (jsonDoc.containsKey("id") && jsonDoc.containsKey("cardId") && jsonDoc.containsKey("name"))
        {
            // Initialiser l'objet User avec les valeurs de la réponse JSON
            user.setId(jsonDoc["id"]);
            user.setCardID(jsonDoc["cardId"]);
            user.setName(jsonDoc["name"]);
        }
        http.end();
    }
    else
    {
        // Gérer les erreurs de la requête
        http.end();
    }
}

// Fonction pour effectuer une requête GET et récupérer un dispositif
void getRequestDevise(std::string url, Device &device)
{
    // Initialiser un client HTTP
    HTTPClient http;

    // Commencer la connexion HTTP avec l'URL spécifiée
    http.begin(url.c_str());
    int httpCode = http.GET();

    // Vérifier si la requête a réussi
    if (httpCode > 0)
    {
        // Lire la réponse de la requête
        String response = http.getString();

        // Traiter la réponse JSON
        DynamicJsonDocument jsonDoc(1024);
        deserializeJson(jsonDoc, response);

        // Vérifier la présence des clés nécessaires dans la réponse JSON
        if (jsonDoc.containsKey("id") && jsonDoc.containsKey("description") && jsonDoc.containsKey("pairedUserId"))
        {
            // Initialiser l'objet Device avec les valeurs de la réponse JSON
            device.setId(jsonDoc["id"]);
            device.setDescription(jsonDoc["description"]);
            device.setPairedUserID(jsonDoc["pairedUserId"]);
        }

        http.end();
    }
    else
    {
        // Gérer les erreurs de la requête
        http.end();
    }
}

// Fonction pour effectuer une requête GET et récupérer un équipement
void getRequestEquipment(std::string url, Equipment &equipment)
{
    // Initialiser un client HTTP
    HTTPClient http;

    // Commencer la connexion HTTP avec l'URL spécifiée
    http.begin(url.c_str());
    int httpCode = http.GET();

    // Vérifier si la requête a réussi
    if (httpCode > 0)
    {
        // Lire la réponse de la requête
        String response = http.getString();

        // Traiter la réponse JSON
        DynamicJsonDocument jsonDoc(1024);
        deserializeJson(jsonDoc, response);

        // Vérifier la présence des clés nécessaires dans la réponse JSON
        if (jsonDoc.containsKey("id") && jsonDoc.containsKey("description") && jsonDoc.containsKey("pairedUserId"))
        {
            // Initialiser l'objet Equipment avec les valeurs de la réponse JSON
            equipment.setId(jsonDoc["id"]);
            equipment.setDescription(jsonDoc["description"]);
            equipment.setPairedUserID(jsonDoc["pairedUserId"]);
        }

        http.end();
    }
    else
    {
        // Gérer les erreurs de la requête
        http.end();
    }
}

// Fonction pour effectuer une requête GET et récupérer une notification
void getRequestNotification(std::string url, Notification &notification)
{
    // Initialiser un client HTTP
    HTTPClient http;

    // Commencer la connexion HTTP avec l'URL spécifiée
    http.begin(url.c_str());
    int httpCode = http.GET();

    // Vérifier si la requête a réussi
    if (httpCode > 0)
    {
        // Lire la réponse de la requête
        String response = http.getString();

        // Traiter la réponse JSON
        DynamicJsonDocument jsonDoc(1024);
        deserializeJson(jsonDoc, response);

        // Vérifier la présence des clés nécessaires dans la réponse JSON
        if (jsonDoc.containsKey("eqtId") && jsonDoc.containsKey("title") && jsonDoc.containsKey("description") &&
            jsonDoc.containsKey("priority") && jsonDoc.containsKey("id") && jsonDoc.containsKey("acked"))
        {
            // Initialiser l'objet Notification avec les valeurs de la réponse JSON
            notification.setEqtID(jsonDoc["eqtId"]);
            notification.setTitle(jsonDoc["title"]);
            notification.setDescription(jsonDoc["description"]);
            notification.setPriority(jsonDoc["priority"]);
            notification.setID(jsonDoc["id"]);
            notification.setAcked(jsonDoc["acked"]);
        }

        http.end();
    }
    else
    {
        // Gérer les erreurs de la requête
        http.end();
    }
}
