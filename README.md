# t-watch-project
Project de montre connectee
En suivant les étapes suivantes, nous avons configuré notre environnement de développement pour coder et afficher le code sur la montre intelligente. Cela a préparé le terrain pour un développement efficace et ciblé sur le modèle spécifique de montre que nous utilisons. 

1. Choix de l'Environnement de Développement : Nous avons opté pour Visual Studio Code (VSCode), un éditeur de code polyvalent et populaire.

2. Installation de l'Extension PlatformIO : Dans VSCode, nous avons ajouté l'extension PlatformIO. Cette extension est essentielle pour développer des applications pour des appareils IoT comme notre montre.

3. Configuration du Fichier de Projet : Nous avons créé un fichier de configuration pour notre projet dans VSCode. Ce fichier, nommé «t-watch-project », contient les paramètres spécifiques pour notre montre basée sur ESP32. Voici la configuration utilisée :

[env:esp32dev]
platform = espressif32
board = esp32dev
framework = arduino

4. Clonage de la Bibliothèque Officielle : Nous avons cloné la bibliothèque officielle de la montre depuis le dépôt GitHub https://github.com/Xinyuan-LilyGO/T-Watch-2021/tree/main. Cette étape est cruciale pour obtenir les librairies et exemples spécifiques à notre modèle de montre.

5. Ajout de la Bibliothèque au Projet : Après avoir cloné la bibliothèque, nous l'avons ajoutée au dossier « lib » dans notre projet « t-watch-project ». Cela permet à notre environnement de développement d'accéder aux fonctionnalités spécifiques de la montre.

6. Décommenter la Bibliothèque Spécifique à la Montre : Dans le fichier « TWatch_config.h »(chemin : « twatch_fourmi/lib/TWatch_2021_Library/src/TWatch_config.h »), nous avons décommenté la ligne correspondant au modèle de notre montre, en l'occurrence « TWatch2021_V1_2 ». Cela active les configurations spécifiques à ce modèle dans le code du projet.
