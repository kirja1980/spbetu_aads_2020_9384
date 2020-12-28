#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "finish_the_task.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    z = new Graphics_view_zoom(ui->graphicsView);
    z->set_modifiers(Qt::NoModifier);
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionCreate_variant_triggered(){
    int data = QInputDialog::getInt(this, "Create variant.", "Enter amount of elements: ");
    int random;
    for (int i = 0; i < 100; i++) {
        treap.erase(i);
    }
    for(int i = 0; i < data; i++){
        random = rand() % 100;
        treap.insert(random);
    }
    scene->clear();
    treap.draw(scene);
}

void MainWindow::on_Open_triggered()
{
    QString filepath = QFileDialog::getOpenFileName(this, "Explorer", QDir::homePath(), tr("Load File (*.DOCX)"));

    QFile file(filepath);
    if(!file.open(QFile::ReadOnly | QFile::ReadOnly))
    {
        QMessageBox::warning(this, "Warning!", "File not open.");
    }
    else
    {
        QTextStream in(&file);
        QString str = in.readLine();

        QStringList lst = str.split(" ");

        QVector<int> data;

        for (qsizetype index = 0; index < lst.size(); index++)
        {
            QString num = lst[index];
            data.push_back(num.toInt());
        }

        for(QVector<int>::iterator iter = data.begin();iter != data.end();iter++)
        {
                treap.insert(*iter);
        }

        scene->clear();
        treap.draw(scene);
    }

    file.close();
}

void MainWindow::on_Enter_triggered()
{
    QString str = QInputDialog::getText(this, "Enter Traversal.", "Enter Preorder Traversal: ");

    QStringList lst = str.split(" ");

    QVector<int> data;

    for (qsizetype index = 0; index < lst.size(); index++)
    {
        QString num = lst[index];
        data.push_back(num.toInt());
    }

    for(QVector<int>::iterator iter = data.begin();iter != data.end();iter++)
    {
            treap.insert(*iter);
    }

    scene->clear();
    treap.draw(scene);
}

void MainWindow::on_actionEnter_Key_triggered()
{
    int data = QInputDialog::getInt(this, "Enter Key.", "Enter Key: ");
    treap.insert(data);
    scene->clear();
    treap.draw(scene);
}

void MainWindow::on_actionErase_Key_triggered()
{
    int data = QInputDialog::getInt(this, "Erase Key.", "Enter Key: ");
    treap.erase(data);
    scene->clear();
    treap.draw(scene);
}



void MainWindow::on_FINISH_THE_TASK_clicked()
{
    QString str;
    unsigned count = 0;
    double percent = 100;
    treap.KLR(str);
    str.chop(1);
    if(MainWindow::ui->lineEditKLR->text() == str){
        count++;
    }
    str.clear();
    treap.LKR(str);
    str.chop(1);
    if(MainWindow::ui->lineEditLKR->text() == str){
        count++;
    }
    str.clear();
    treap.LRK(str);
    str.chop(1);
    if(MainWindow::ui->lineEditLRK->text() == str){
        count++;
    }
    str.clear();
    str.push_back("Your results: ");
    str.push_back(QString::number(count));
    str.push_back("/3 (");
    str.push_back(QString::number(count*percent/3));
    str.push_back("%)");
    MainWindow::ui->FinishResults->setText(str);

    finish_the_task window;
    window.setModal(true);
    window.exec();
}
