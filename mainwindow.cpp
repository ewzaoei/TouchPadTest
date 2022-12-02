#include <QGraphicsLineItem>
#include <QKeyEvent>
#include "mainwindow.h"

MainWindow::MainWindow():
    is_pressed_(false)
{
    setMouseTracking(true);
    view_ = new QGraphicsView(this);
    view_->setAttribute(Qt::WA_TransparentForMouseEvents);
    view_->setStyleSheet("background:transparent;");
    view_->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    view_->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view_->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view_->setGeometry(0, 0, width(), height());
    view_->show();
    scene_ = new QGraphicsScene();
    view_->setScene(scene_);
    view_->setSceneRect(0, 0, width(), height());

    ellipse_pen_.setStyle(Qt::NoPen);
    brush_ = new QBrush(Qt::red);
    line_pen_.setStyle(Qt::SolidLine);
    line_pen_.setColor(QColor(11, 31, 147));
    line_pen_.setWidth(1);

    x_line_ = new QGraphicsLineItem;
    x_line_->setPen(line_pen_);
    y_line_ = new QGraphicsLineItem;
    y_line_->setPen(line_pen_);

    move(0, 0);
}

MainWindow::~MainWindow() {

}


void MainWindow::mousePressEvent(QMouseEvent *event) {
    is_pressed_ = true;
    scene_->clear();
    start_ = event->pos();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event) {
    if (is_pressed_) {
        QPoint pt = event->pos();
        //绘制图像
        scene_->addEllipse(start_.x() - 3, start_.y() - 3, 5, 5, ellipse_pen_, *brush_);
        scene_->addEllipse(pt.x() - 3, pt.y() - 3, 5, 5, ellipse_pen_, *brush_);
        scene_->addLine(start_.x(), start_.y(), pt.x(), pt.y(), line_pen_);

        x_line_->setLine(pt.x(), 0, pt.x(), view_->height());
        y_line_->setLine(0, pt.y(), view_->width(), pt.y());
        scene_->addItem(x_line_);
        scene_->addItem(y_line_);
        start_ = pt;
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event) {
    is_pressed_ = false;
    scene_->removeItem(x_line_);
    scene_->removeItem(y_line_);
}

void MainWindow::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.fillRect(view_->rect(), QColor(255, 255, 255));
}
