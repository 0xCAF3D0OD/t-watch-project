#include "backend.hpp"

void	getRequestUser(std::string url, User &user)
{
	// Effectuer une requête HTTP
    HTTPClient http;

    http.begin(url.c_str());
    int httpCode = http.GET();

    if (httpCode > 0)
    {
        String response = http.getString();

        // Traiter la réponse ici
        DynamicJsonDocument jsonDoc(1024); // Définissez la taille du document JSON en fonction de vos besoins
        deserializeJson(jsonDoc, response);

        // Assurez-vous que les champs "id", "cardId" et "name" existent dans la réponse JSON
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
        // error handling
        http.end();
    }
}

void	getRequestDevise(std::string url, Device &device)
{
	// Effectuer une requête HTTP
    HTTPClient http;

    http.begin(url.c_str());
    int httpCode = http.GET();

    if (httpCode > 0)
    {
        String response = http.getString();

        // Traiter la réponse ici
        DynamicJsonDocument jsonDoc(1024); // Définissez la taille du document JSON en fonction de vos besoins
        deserializeJson(jsonDoc, response);

        // Assurez-vous que les champs "id", "cardId" et "name" existent dans la réponse JSON
        if (jsonDoc.containsKey("id") && jsonDoc.containsKey("description") && jsonDoc.containsKey("pairedUserId"))
        {
            // Initialiser l'objet User avec les valeurs de la réponse JSON
            device.setId(jsonDoc["id"]);
            device.setDescription(jsonDoc["description"]);
            device.setPairedUserID(jsonDoc["pairedUserId"]);
        }

        http.end();
    }
    else
    {
        // error handling
        http.end();
    }
}

void	getRequestEquipment(std::string url, Equipment &equipment)
{
	// Effectuer une requête HTTP
    HTTPClient http;

    http.begin(url.c_str());
    int httpCode = http.GET();

    if (httpCode > 0)
    {
        String response = http.getString();

        // Traiter la réponse ici
        DynamicJsonDocument jsonDoc(1024); // Définissez la taille du document JSON en fonction de vos besoins
        deserializeJson(jsonDoc, response);

        // Assurez-vous que les champs "id", "cardId" et "name" existent dans la réponse JSON
        if (jsonDoc.containsKey("id") && jsonDoc.containsKey("description") && jsonDoc.containsKey("pairedUserId"))
        {
            // Initialiser l'objet User avec les valeurs de la réponse JSON
            equipment.setId(jsonDoc["id"]);
            equipment.setDescription(jsonDoc["description"]);
            equipment.setPairedUserID(jsonDoc["pairedUserId"]);
        }

        http.end();
    }
    else
    {
        // error handling
        http.end();
    }
}

void	getRequestNotification(std::string url, Notification &notification)
{
	// Effectuer une requête HTTP
    HTTPClient http;

    http.begin(url.c_str());
    int httpCode = http.GET();

    if (httpCode > 0)
    {
        String response = http.getString();

        // Traiter la réponse ici
        DynamicJsonDocument jsonDoc(1024); // Définissez la taille du document JSON en fonction de vos besoins
        deserializeJson(jsonDoc, response);

        // Assurez-vous que les champs "id", "cardId" et "name" existent dans la réponse JSON
        if (jsonDoc.containsKey("eqtId") && jsonDoc.containsKey("title") && jsonDoc.containsKey("description")
				&& jsonDoc.containsKey("priority") && jsonDoc.containsKey("id") && jsonDoc.containsKey("acked"))
        {
            // Initialiser l'objet User avec les valeurs de la réponse JSON
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
        // error handling
        http.end();
    }
}