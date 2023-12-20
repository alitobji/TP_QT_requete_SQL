#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets>
#include <QtSql>
#include <QModelIndexList>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    QSqlDatabase db;

private slots:
    void afficherJoueurs();
    void ajouterNote();
};
#endif // WIDGET_H
