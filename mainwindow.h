#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QColorDialog>
#include "paintscene.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    /**
     * @brief handleOpenFile обработка открытия файла
     */
    void handleOpenFile();
    /**
     * @brief handleSaveFile обработка сохранения
     */
    void handleSaveFile();
    /**
     * @brief picName имя картинки вместе с URL
     */
    QString picName;
signals:
    /**
     * @brief setPicInGraphView положить картинку на задний план график вю
     * @param fileName имя файла
     */
    void setPicInGraphView(QPixmap fileName);
private:
    /**
     * @brief timer Таймер для подготовки актуальных размеров графической сцены
     */
    QTimer *timer;
    /**
     * @brief scene рисовательская сцена
     */
    PaintScene *scene;
    /**
     * @brief resizeEvent Кастомная графическая сцена с переопределением события изменения размера окна для пересчёта размеров графической сцены
     * @param event событие
     */
    void resizeEvent(QResizeEvent * event);
    /**
     * @brief ui юай
     */
    Ui::MainWindow *ui;

private slots:
    /**
     * @brief slotTimer слот для того самого таймера актуального размера
     */
    void slotTimer();
};
#endif // MAINWINDOW_H
