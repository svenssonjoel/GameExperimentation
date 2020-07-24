#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /* Directory containing:
     *  Character Creator - Graphics Pack
     *  Indie Graphics Bundle
     *  Space Galaxy - Graphics Pack
     *
     *  All avaialable from Steam at low price!
     */
    mResourceDir = "../../../Resources";
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loadPushButton_clicked()
{
    QFileDialog fd(this, tr("Load Image"), "../../../Resources", "*.png");
    QString filename = fd.getOpenFileName();

    if (filename.isEmpty())  {
        return;
    }

    QPixmap p(filename);
    if (! ui->graphicsView->scene()) {
        qDebug() << "No Scene!";

        QGraphicsScene *scene = new QGraphicsScene(this);
        ui->graphicsView->setScene(scene);
    }
    ui->graphicsView->scene()->addPixmap(p);
}

void MainWindow::on_clearPushButton_clicked()
{
    if (ui->graphicsView->scene()) {
        ui->graphicsView->scene()->clear();
    }
}
