#include "widget.h"
#include "ui_widget.h"
#include<QSqlQuery>
#include <QMessageBox>

/******************************
 * le fichier contient la definition des Fonction AjouterNote ,afficherJoueurs
 * mais aussi la connexion a la BDD
 *
 *
 * **********************************/
Widget::Widget(QWidget *parent): QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);
    // Connexion à la base de données
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Driver={MySQL ODBC 8.2 ANSI Driver};DATABASE=player;");
    db.setUserName("student");
    db.setPassword("crif2024sn");

   if (db.open()) {
    qDebug() << "Connexion à la base de données établie avec succès";
    } else {
       qDebug() << "Erreur de connexion à la base de données"<<db.lastError().text();
    }

    
    connect(ui->boutonAfficher, &QPushButton::clicked, this, &Widget::afficherJoueurs);// Connecte le slot pour afficher les joueurs au signal bouton
 
    connect(ui->boutonAjouterNote, &QPushButton::clicked, this, &Widget::ajouterNote);   // Connecte le slot pour ajouter une note au signal bouton
}

Widget::~Widget()
{
    delete ui;
}

void Widget::afficherJoueurs()
{
    QSqlQueryModel *model = new QSqlQueryModel(); //crée un pointeur associé a un objet qui contient une requete SQL
    
    model->setQuery("SELECT id, nom, prenom, club, age, notejoueur FROM jeu");// Configure la requête SQL du modèle pour récupérer des données spécifiques de la table "jeu"

    ui->tableView->setModel(model);// Associe le modèle de requête SQL créé au composant tableView dans l'interface utilisateur
}

void Widget::ajouterNote()
{
    
    QModelIndexList selectedIndexes = ui->tableView->selectionModel()->selectedIndexes();// Récupère la liste des indices des cellules sélectionnées dans le tableau


    
    if (!selectedIndexes.isEmpty()) // Vérifie si des indices sont sélectionnés dans le tableau
    {
    
    int row = selectedIndexes.first().row();// Récupère le numéro de ligne du premier indice sélectionné
    
    
    int idJoueur = ui->tableView->model()->data(ui->tableView->model()->index(row, 0)).toInt();// Récupère l'ID du joueur à partir de la première colonne de la ligne sélectionnée

    int nouvelleNote= ui->lineEditNote->text().toInt();//crée un entier qui recuperer la note ecrit dans le lineEditNote
    if (nouvelleNote<=10)//création d’un if pour pas que la note dépasse 10
    {
        // Ajoute la note à la base de données (à adapter selon tes besoins)
        QSqlQuery query;// Crée un objet QSqlQuery pour effectuer une requête SQL
        query.prepare("UPDATE jeu SET notejoueur = :note WHERE id = :id");// Prépare une requête SQL pour mettre à jour la colonne "notejoueur" dans la table "jeu" pour un joueur spécifique
        query.bindValue(":note", ui->lineEditNote->text());// Lie la valeur du champ de texte ui->lineEditNote à la variable liée :note dans la requête SQL
        query.bindValue(":id", idJoueur);// Lie la valeur de l'ID du joueur à la variable liée :id dans la requête SQL
        query.exec();// Exécute la requête SQL pour mettre à jour la base de données avec la nouvelle note pour le joueur spécifié

        // Rafraîchit l'affichage
        afficherJoueurs();
    }else{
        QMessageBox::warning(this,"Erreur","La note peu pas dépaser 10");//affiche un message d'erreur si la note est superieur a 0
           }
}
}
