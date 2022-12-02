#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsView>

class MainWindow: public QWidget {
    Q_OBJECT
public:
    explicit MainWindow();

    ~MainWindow();

protected:

    void mousePressEvent(QMouseEvent *event) override;

    void mouseMoveEvent(QMouseEvent *event) override;

    void mouseReleaseEvent(QMouseEvent *event) override;

    void paintEvent(QPaintEvent *event) override;

private:
    QGraphicsView *view_;

    QGraphicsScene *scene_;

    QPoint start_;

    QPen line_pen_;

    QPen ellipse_pen_;

    QBrush *brush_;

    QGraphicsLineItem *x_line_;

    QGraphicsLineItem *y_line_;

    bool is_pressed_;

    Q_DISABLE_COPY(MainWindow);
};

#endif // MAINWINDOW_H
