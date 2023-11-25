#include "../backend.hpp"

void	rfid()
{
	if (Serial1.available() > 0)
	{
		// Lire les données du port série
		String receivedData = Serial1.readStringUntil('\n');

		// Faites quelque chose avec la chaîne reçue (par exemple, envoyez-la à un serveur, affichez-la sur un écran, etc.)
		Serial1.println("Données reçues : " + receivedData);
	}
}