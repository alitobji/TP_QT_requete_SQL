# PROJET JOUEUR DE FOOT permet d'afficher des joueur de foot et rentrer une note de match.

 ## Prérequis - il faut installer QT et WORKBENCH 
- video QT CREATOR : https://www.youtube.com/watch?v=JDIV3DZTWSY
- video WORKBENCH : https://www.youtube.com/watch?v=jc7yBdv1pns


## Télécharger le fichier ZIP et ouvrir le projet dans QT creator 
- Configuration de la Base de Données Sur Windows vous devez Utilisez le connecteur MySQL ODBC : - Téléchargez et installez le [pilote MySQL ODBC](https://dev.mysql.com/downloads/connector/odbc/).
- dans le fichier widget.cpp utilisez cette les lignes de commande pour connecté le programme avec la BDD :
   
 db = QSqlDatabase::addDatabase("QODBC"); 
 
 db.setDatabaseName("Driver={MySQL ODBC 8.2 ANSI Driver};DATABASE=player;");

- le fichier est déja formaté pour windows vous n'aurez pas a changé .


 #### Sur Linux 1. Utilisez le connecteur natif MySQL :
 - Installez le paquet `libqt5sql5-mysql` : `sudo apt-get install libqt5sql5-mysql`.
 - Assurez-vous que MYSQL est déja installé
 - Dans le fichier widget.cpp utilisez cette ligne de commande pour connecté le programme avec la BDD : 

 db.QSqlDatabase::addDatabase("QMYSQL");

### METTRE LA BASE DE DONNEES SUR WORKBENCH

utilisez le fichier player_jeu.sql et l'ouvrir avec workbench puis executé afin d'obtenir la base de données.

## Utilisation  Compilez et exécutez le programme.
- L'interface graphique s'ouvrira
- Interagissez avec l'interface pour afficher et noter les joueurs.
 ## Fonctionnalités - Affichage des joueurs depuis la base de données.
 - Ajout de notes aux joueurs avec vérification de la limite à 10.
