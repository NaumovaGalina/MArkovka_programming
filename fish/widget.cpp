#include "widget.h"
#include "ui_widget.h"
#include <QRectF>
#include <QPointF>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

/*Рисование рыбки*/

void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);

    //Описание расположения частей рыбки
    //Спинка
    QRectF rectangle(80.0, 100.0, 200.0, 200.0);
      int startAngle = 30 * 16;
      int spanAngle = 120 * 16;
    //Животик
    QRectF rectangle1(80.0, 0.0, 200.0, 200.0);
      int startAngle1 = 210 * 16;
      int spanAngle1 = 120 * 16;
    painter.setPen(QPen(Qt::yellow, 1, Qt::SolidLine, Qt::FlatCap));

    //Хвостичек
    static const QPointF points[3] = {
          QPointF(266.0, 149.0),
          QPointF(300.0, 110.0),
          QPointF(300.0, 188.0)
      };

    //Голова
    QRectF rectangle2(10.0, 100.0, 200.0, 100.0);
    int startAngle2 = 320 * 16;
    int spanAngle2 = 120 * 16;

    //Рисование частей рыбки
    painter.setBrush(QBrush(Qt::yellow, Qt::SolidPattern));
    painter.drawChord(rectangle, startAngle, spanAngle);
    painter.drawChord(rectangle1, startAngle1, spanAngle1);
    painter.drawConvexPolygon(points, 3);

    QPainter painter1(this);

    painter1.setPen(QPen(Qt::red, 1, Qt::SolidLine, Qt::FlatCap));
    painter1.drawArc(rectangle2, startAngle2, spanAngle2);

}
