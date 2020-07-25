#include "mainwindow.h"
#include "ui_mainwindow.h"

#define DEBUG


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
    QString filename = QFileDialog::getOpenFileName(this,
                                                    tr("Load Image"),
                                                    mResourceDir,
                                                    tr("Images (*.png *.jpg)"));

    if (filename.isEmpty())  {
        return;
    }

    QPixmap p(filename);


#ifdef DEBUG
    qDebug() << "File: " << filename;
    qDebug() << "Depth: " << p.depth();
    qDebug() << "Width: " << p.width();
    qDebug() << "Height: " << p.height();
    qDebug() << "alpha: " << p.hasAlphaChannel();
#endif

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
