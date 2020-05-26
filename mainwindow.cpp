#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Paint 4d");

    scene = new PaintScene();       // Инициализируем графическую сцену

    ui->graphicsView->setScene(scene);  // Устанавливаем графическую сцену

    connect(ui->pickB, &QPushButton::pressed, scene, &PaintScene::pickColor);

    timer = new QTimer();       // Инициализируем таймер
    connect(timer, &QTimer::timeout, this, &MainWindow::slotTimer);
    timer->start(100);          // Запускаем таймер

    connect(ui->openB, &QPushButton::pressed, this, &MainWindow::handleOpenFile);
    connect(ui->saveB, &QPushButton::pressed, this, &MainWindow::handleSaveFile);
    connect(this, &MainWindow::setPicInGraphView, ui->graphicsView, &QGraphicsView::setBackgroundBrush);
}

void MainWindow::slotTimer()
{
    /* Переопределяем размеры графической сцены в зависимости
     * от размеров окна
     * */
    timer->stop();
    scene->setSceneRect(0,0, ui->graphicsView->width() - 20, ui->graphicsView->height() - 20);
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    timer->start(100);
    QWidget::resizeEvent(event);
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleOpenFile()
{
    this->picName = QFileDialog::getOpenFileName(this,"Open Picture",QDir::currentPath(),"PNG files (*.png)");
    if( !picName.isNull() ) {
          qDebug() << "selected file path : " << picName.toUtf8();
          QPixmap m(picName);
          emit setPicInGraphView(m.scaled(600,400));
    }
}
void MainWindow::handleSaveFile()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), picName,
        tr("PNG files (*.png)"));
    qDebug() << fileName;

    QPixmap pixMap = ui->graphicsView->grab(ui->graphicsView->sceneRect().toRect());
    pixMap.save(fileName);

}
