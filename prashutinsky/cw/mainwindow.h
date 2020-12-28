#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QVector>
#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QInputDialog>
#include <QTextStream>
#include "graphics_view_zoom.h"

#include "treap.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_actionCreate_variant_triggered();

    void on_Open_triggered();

    void on_Enter_triggered();

    void on_actionEnter_Key_triggered();

    void on_actionErase_Key_triggered();

    void on_FINISH_THE_TASK_clicked();

private:
    Treap<int> treap;

    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    Graphics_view_zoom* z;
};
#endif // MAINWINDOW_H
