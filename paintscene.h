#ifndef PAINTSCENE_H
#define PAINTSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>
#include <QDebug>
#include <QColorDialog>

class PaintScene : public QGraphicsScene
{

    Q_OBJECT

public:
    /**
     * @brief PaintScene конструктор рисовательской сцены
     * @param parent Люк, Я твой отец
     */
    explicit PaintScene(QObject *parent = 0);
    ~PaintScene();
    /**
     * @brief color цвет кисточки
     */
    QColor color;
    /**
     * @brief pickColor функция выбора цвет кисточки
     */
    void pickColor();
private:
    /**
     * @brief previousPoint Координаты предыдущей точки
     */
    QPointF previousPoint;
private:
    // Для рисования используем события мыши (из гайда по ссылке)
    /**
     * @brief mousePressEvent обработка зажима
     * @param event событие
     */
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    /**
     * @brief mouseMoveEvent обработка ведения
     * @param event событие
     */
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

};

#endif // PAINTSCENE_H
