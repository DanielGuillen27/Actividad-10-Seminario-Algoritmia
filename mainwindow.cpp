#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QTableWidget>

bool ok;
QString fileName;
QBrush redBrush(Qt::red);
QBrush blueBrush(Qt::blue);
QPen blackPen(Qt::black);



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString fileName;
    scene = new QGraphicsScene(this);
    text = new QGraphicsTextItem();
    ui->graphicsView->setScene(scene);

}

MainWindow::~MainWindow()
{
    delete ui;


}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Seleccione un archivo"), "C:\\Users\\Daniel\\Downloads", tr("Text File (*.txt)"));

    QMessageBox T;

    T.setText(fileName);

    T.exec();

}
void MainWindow::on_txtId_textChanged(const QString &arg1)
{

}
void MainWindow::vaciar(){
    ui->txtId->setText("");
    ui->txtVoltaje->setText("");
    ui->txtPosX->setText("");
    ui->txtPosY->setText("");
    ui->txtRed->setText("");
    ui->txtGreen->setText("");
    ui->txtBlue->setText("");
}

void MainWindow::on_btnGuardar_clicked()
{

    //primero obtenemos los datos de cada caja de texto
    id=ui->txtId->text();
    voltaje=ui->txtVoltaje->text();
    posX = ui->txtPosX->text();
    posY =ui->txtPosY->text();
    red = ui->txtRed->text();
    green = ui->txtGreen->text();
    blue = ui->txtBlue->text();
    //en el objeto que tenemos lo agregamos los datos a cada atributo del objeto
    n.setId(id.toInt(&ok));
    n.setVoltaje(voltaje.toFloat(&ok));
    n.setPosicionX(posX.toInt(&ok));
    n.setPosicionY(posY.toInt(&ok));
    n.setBlue(blue.toInt(&ok));
    n.setGreen(green.toInt(&ok));
    n.setRed(red.toInt(&ok));

    //creamos una neurona y agregamos datos, despues lo metemos en la lista

    lista.insertData(lista.getFirstPos(),n); // se inserta al principio

    vaciar();
}

void MainWindow::on_btnMostrar_clicked()
{
    ui->tableWidget->clear();
    int fila;
    ui->tableWidget->setColumnCount(7);

    QStringList encabezado;



    encabezado << "ID" << "voltaje" << "Pos X" << "Pos y" << "Red"<< "Blue" << "Green";
    ui->tableWidget->setHorizontalHeaderLabels(encabezado);

    //ui->tableWidget->setItem(0,0,MyItem);



    //metodo de busqueda lineal
    //aqui podemos hacer que recorra y si es nullptr entonces asi sabemos que es el ultimo y nos salimos
 nuevo = lista.getFirstPos();

    ui->tableWidget->setRowCount(0);
    while(nuevo != nullptr){

        n = lista.retrieve(nuevo);
        nuevo = lista.getNextPos(nuevo);
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
          fila = ui->tableWidget->rowCount() - 1;
        ui->tableWidget->setItem(fila, ID, new QTableWidgetItem(QString::number(n.getId())));
        ui->tableWidget->setItem(fila, VOLTAJE, new QTableWidgetItem(QString::number(n.getVoltaje())));
        ui->tableWidget->setItem(fila, POSX, new QTableWidgetItem(QString::number(n.getPosicionX())));
        ui->tableWidget->setItem(fila, POSY, new QTableWidgetItem(QString::number(n.getPosicionY())));
        ui->tableWidget->setItem(fila, RED, new QTableWidgetItem(QString::number(n.getRed())));
        ui->tableWidget->setItem(fila, BLUE, new QTableWidgetItem(QString::number(n.getBlue())));
        ui->tableWidget->setItem(fila, GREEN, new QTableWidgetItem(QString::number(n.getGreen())));
    }
}


void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{

}


void MainWindow::on_txtRed_textChanged(const QString &arg1)
{

}


void MainWindow::on_txtBlue_textChanged(const QString &arg1)
{

}


void MainWindow::on_btnGuardarFinal_clicked()
{
    //primero obtenemos los datos de cada caja de texto
    id=ui->txtId->text();
    voltaje=ui->txtVoltaje->text();
    posX = ui->txtPosX->text();
    posY =ui->txtPosY->text();
    red = ui->txtRed->text();
    green = ui->txtGreen->text();
    blue = ui->txtBlue->text();
    //en el objeto que tenemos lo agregamos los datos a cada atributo del objeto
    n.setId(id.toInt(&ok));
    n.setVoltaje(voltaje.toFloat(&ok));
    n.setPosicionX(posX.toInt(&ok));
    n.setPosicionY(posY.toInt(&ok));
    n.setBlue(blue.toInt(&ok));
    n.setGreen(green.toInt(&ok));
    n.setRed(red.toInt(&ok));
    //creamos una neurona y agregamos datos, despues lo metemos en la lista

    lista.insertData(lista.getLastPos(),n); // se inserta al final
    vaciar();
}

void MainWindow::on_actionguardar_triggered()
{
    //aqui vamos a guardar en el archivo
}


void MainWindow::on_pushButton_clicked()
{
     fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Seleccione un archivo"), "C:\\Users\\usuario\\Downloads", tr("Text File (*.txt)"));

    QMessageBox T;

    T.setText(fileName);



    T.exec();
}


void MainWindow::on_btnLeer_clicked()
{
     lista.leer(fileName);
}


void MainWindow::on_btnEscribir_clicked()
{
    lista.escribir(fileName);
}


void MainWindow::on_btnUbicacion_clicked()
{

    fileName = QFileDialog::getOpenFileName(this,
                                            tr("Seleccione un archivo"), "C:\\Users\\usuario\\Downloads", tr("Text File (*.txt)"));

    QMessageBox T;

    T.setText(fileName);

    T.exec();

}


void MainWindow::on_txtUbicacion_textChanged(const QString &arg1)
{



}


void MainWindow::on_buscarbtn_clicked()
{
    int fila;
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());

    Neurona otraNeurona;
    try{

    otraNeurona.setId(ui->lineEdit->text().toInt(&ok));
    nuevo = lista.findData(otraNeurona);

    n1 = lista.retrieve(nuevo);
    }catch(exception ex){
    QMessageBox::information(this,"Alerta", "Ingrese un valor exitente");

    }
 fila = ui->tableWidget->rowCount() - 1;
    ui->txtGreen->setText(QString::number(n1.getId()));
    ui->tableWidget->setItem(fila, ID, new QTableWidgetItem(QString::number(n1.getId())));
    ui->tableWidget->setItem(fila, VOLTAJE, new QTableWidgetItem(QString::number(n1.getVoltaje())));
    ui->tableWidget->setItem(fila, POSX, new QTableWidgetItem(QString::number(n1.getPosicionX())));
    ui->tableWidget->setItem(fila, POSY, new QTableWidgetItem(QString::number(n1.getPosicionY())));
    ui->tableWidget->setItem(fila, RED, new QTableWidgetItem(QString::number(n1.getRed())));
    ui->tableWidget->setItem(fila, BLUE, new QTableWidgetItem(QString::number(n1.getBlue())));
    ui->tableWidget->setItem(fila, GREEN, new QTableWidgetItem(QString::number(n1.getGreen())));

}


void MainWindow::on_txtBuscar_textChanged(const QString &arg1)
{

}


void MainWindow::on_btnOrdenar_clicked()
{
    lista.sortBurbuja(Neurona::compareByID);
}


void MainWindow::on_btnVer_clicked()
{
    blackPen.setWidth(3);
    int x = 10;
    nuevo = lista.getFirstPos();

    QColor color;

    while(nuevo != nullptr){

    n = lista.retrieve(nuevo);
    nuevo = lista.getNextPos(nuevo);
    color.setGreen(n.getGreen());
    color.setBlue(n.getBlue());
    color.setRed(n.getRed());

    QGraphicsEllipseItem *ellipse = scene->addEllipse(n.getPosicionX(), n.getPosicionY(), n.getVoltaje(), n.getVoltaje(), blackPen, color);

    scene->addItem(ellipse);

    }


}


void MainWindow::on_btnLimpiar_clicked()
{
    scene->clear();
}


void MainWindow::on_btnOrdenarVoltaje_clicked()
{
    lista.sortBurbuja(Neurona::compareByVoltaje);
}

