# t-watch-project
Project de montre connectee
En suivant les étapes suivantes, nous avons <strong>configuré notre environnement de développement</strong> pour coder et afficher le code sur la montre intelligente. Cela a préparé le terrain pour un développement efficace et ciblé sur le modèle spécifique de montre que nous utilisons. 

1. Choix de l'Environnement de Développement : Nous avons opté pour Visual Studio Code (VSCode), un éditeur de code polyvalent et populaire.

2. Installation de l'Extension PlatformIO : Dans VSCode, nous avons ajouté l'extension PlatformIO. Cette extension est essentielle pour développer des applications pour des appareils IoT comme notre montre.

3. Configuration du Fichier de Projet : Nous avons créé un fichier de configuration pour notre projet dans VSCode. Ce fichier, nommé «t-watch-project », contient les paramètres spécifiques pour notre montre basée sur ESP32. Voici la configuration utilisée :

[env:esp32dev]
<br />platform = espressif32
<br />board = esp32dev
<br />framework = arduino

4. Clonage de la Bibliothèque Officielle : Nous avons cloné la bibliothèque officielle de la montre depuis le dépôt GitHub https://github.com/Xinyuan-LilyGO/T-Watch-2021/tree/main. Cette étape est cruciale pour obtenir les librairies et exemples spécifiques à notre modèle de montre.

5. Ajout de la Bibliothèque au Projet : Après avoir cloné la bibliothèque, nous l'avons ajoutée au dossier « lib » dans notre projet « t-watch-project ». Cela permet à notre environnement de développement d'accéder aux fonctionnalités spécifiques de la montre.

6. Décommenter la Bibliothèque Spécifique à la Montre : Dans le fichier « TWatch_config.h »(chemin : « twatch_fourmi/lib/TWatch_2021_Library/src/TWatch_config.h »), nous avons décommenté la ligne correspondant au modèle de notre montre, en l'occurrence « TWatch2021_V1_2 ». Cela active les configurations spécifiques à ce modèle dans le code du projet.

<strong>Intégration de la connectivité Wi-Fi et des requêtes HTTP</strong> pour communiquer avec l'api web :

1. Importation des Bibliothèques Nécessaires :

WiFi.h : Permet la connexion au réseau Wi-Fi.
<br />HTTPClient.h : Utilisé pour envoyer des requêtes HTTP.
<br />ArduinoJson.h : Nécessaire pour traiter les données JSON reçues des requêtes HTTP.
<br />TWatch_hal.h : Bibliothèque spécifique pour la montre, utilisée pour gérer les fonctionnalités du matériel comme l'affichage.

3. Configuration Wi-Fi :

Les constantes ssid et password sont définies pour se connecter au réseau Wi-Fi spécifié.
<br />Fonction "wifi" : Cette fonction prend un pointeur vers un objet TFT_eSPI, qui est utilisé pour gérer l'affichage sur la montre.
<br />Connexion au Wi-Fi : La montre tente de se connecter au réseau Wi-Fi spécifié par ssid et password. Un délai d'une seconde (delay(1000)) est appliqué entre les tentatives de connexion pour éviter de surcharger le processeur.
<br />Affichage de l'État de Connexion : Si la connexion est établie, l'écran de la montre affiche le message "Connected to WiFi".

3. Requête HTTP :

Une requête HTTP est envoyée à l'URL spécifiée. Si la requête réussit (httpCode > 0), la réponse est stockée dans la variable response. En cas d'échec, un message d'erreur est affiché.
<br />Traitement de la Réponse HTTP : Le code contient un emplacement pour traiter la réponse reçue de la requête HTTP.
<br />Clôture de la Requête HTTP : La connexion HTTP est terminée avec http.end(), libérant les ressources réseau.

