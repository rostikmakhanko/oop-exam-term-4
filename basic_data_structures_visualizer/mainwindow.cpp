#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QtGui>
#include <QtWidgets>
#include <QDebug>
#include <iostream>
#include "singlelinkedcircularlist.tpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(size());

    list=new SingleLinkedCircularList<int>();

    int x1=50,y1=200,x2=100,y2=200;
    for (int i=0;i<10;i++)
    {
        QTextEdit *x=new QTextEdit(this);
        x->setReadOnly(true);
        x->setText("");
        x->setGeometry(x1,y1,x2,y2);
        x1+=150;
        //x->hide();
        nodes.push_back(x);
    }
    painter_type="arrow";
    repaint();
    //auto t = new QTimer;
    //connect(t, SIGNAL(timeout()), this, SLOT(sayShit()));
    //t->singleShot(3000, this, [=]{qInfo() <<"hey";  x->hide(); });
    //delete x;
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::get_element()
{
    return ui->elementSpinBox->value();
}

int MainWindow::get_position()
{
    return ui->positionSpinBox->value();
}

void MainWindow::paintEvent(QPaintEvent *paint_event)
{
    if (flag)
    {
        QPainter painter(this);
        painter.setPen(QPen(Qt::blue, 3));

        std::cout<<9;
        for (int i=0;i<nodes.size();i++)
            nodes[i]->setVisible(false);
        if (list->get_size()>0)
        {
            Node<int> *cur_node=list->head;
            int i=0;
            nodes[i]->setVisible(true);
            nodes[i]->setText(QString::number(cur_node->value));
            i++;
            cur_node=cur_node->next;
            int x1=150,x2=200,y1=300,y2=300;
            while (cur_node!=list->head)
            {
                painter.drawLine(x1,y1,x2,y2);
                painter.drawLine(x2-5,y2-5,x2,y2);
                painter.drawLine(x2-5,y2+5,x2,y2);
                x1+=150; x2+=150;
                nodes[i]->setVisible(true);
                nodes[i]->setText(QString::number(cur_node->value));
                cur_node=cur_node->next;
                i++;
                std::cout<<i;
            }
            painter.drawLine(x1,y1,x2,y2);
            painter.drawLine(x2,y2,x2,y2+150);
            y2+=150;
            painter.drawLine(x2,y2,25,y2);
            x2=25;
            painter.drawLine(x2,y2,x2,y2-150);
            y2-=150;
            painter.drawLine(x2,y2,50,y2);
            x2=50;
            painter.drawLine(x2-5,y2-5,x2,y2);
            painter.drawLine(x2-5,y2+5,x2,y2);
        }
        flag=0;
    }
}

void MainWindow::on_pushBackButton_clicked()
{
    if (list->get_size()>=10) return;
    list->push_back(get_element());
    flag=1;
    repaint();
}

void MainWindow::on_pushFrontButton_clicked()
{
    if (list->get_size()>=10) return;
    list->push_front(get_element());
    flag=1;
    repaint();
}

void MainWindow::on_insertPushButton_clicked()
{
    if (list->get_size()>=10) return;
    list->insert(get_element(),get_position());
    flag=1;
    repaint();
}

void MainWindow::on_deletePushButton_clicked()
{
    list->erase(get_position());
    flag=1;
    repaint();
}

void MainWindow::on_clearPushButton_clicked()
{
    list->clear();
    flag=1;
    repaint();
}
