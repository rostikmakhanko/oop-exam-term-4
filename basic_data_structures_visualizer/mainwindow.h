#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>
#include <QString>
#include <QVector>
#include <QTextEdit>
#include "singlelinkedcircularlist.h"
#include "node.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString painter_type;

private:
    Ui::MainWindow *ui;

    SingleLinkedCircularList *list;

    int get_element();
    int get_position();

    bool flag;

    QVector<QTextEdit*> nodes;

protected:
    void paintEvent(QPaintEvent *paint_event);

private slots:
    void on_pushBackButton_clicked();
    void on_pushFrontButton_clicked();
    void on_insertPushButton_clicked();
    void on_deletePushButton_clicked();
    void on_clearPushButton_clicked();
};

#endif // MAINWINDOW_H
