#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /// Memory allocation for objects
    dataJson = new Data();
    settings = new UserSettings();

    /// Settings structure setup
    QString text;
    text = settings->searchElements(elements[0]);
    settings->settings.temperature = text;

    text = settings->searchElements(elements[1]);
    settings->settings.pressure = text;
}

MainWindow::~MainWindow()
{
    delete dataJson;
    delete settings;
    delete ui;
}

void MainWindow::on_pushButtonInfo_clicked()
{
    /// Delete layout content and info widget setup
    ui->DeleteLayoutContent();
    ui->InfoWidget();

    /// Connect combo boxes signal with currentTextChanged slot
    QObject::connect(ui->comboBoxInfo[0],&QComboBox::currentTextChanged,this, &MainWindow::currentTextChangedInfo);
    QObject::connect(ui->comboBoxInfo[1],&QComboBox::currentTextChanged,this, &MainWindow::currentTextChangedInfo_2);

    /// Fill line edit with data
    double arr[3];
    dataJson->readJsonFile(arr);
    for (int i = 0; i < 3; i++)
    {
        ui->lineEditInfo[i]->setText(QString::number(arr[i]));
    }

    /// Fill combo boxes with data
    ui->comboBoxInfo[0]->setCurrentText(settings->settings.temperature);
    ui->comboBoxInfo[1]->setCurrentText(settings->settings.pressure);
}
void MainWindow::on_pushButtonControl_clicked()
{
    /// Delete layout content and control widget setup
    ui->DeleteLayoutContent();
    ui->ControlWidget();

    /// Check powerSystem
    if (!powerSystem)
    {
        onPushButtonControlOffClicked();
    }

    /// Fill double spin box with data
    double arr[3];
    dataJson->readJsonFile(arr);
    ui->doubleSpinBoxControl->setValue(arr[0]);

    /// Fill temperature label with data
    ui->labelTemperatureControl->setText(", " + settings->settings.temperature);

    /// Connect save button signal with onPushButtonControlClicked slot
    QObject::connect(ui->pushButtonSaveControl,&QPushButton::clicked,this, &MainWindow::onPushButtonControlClicked);

    /// Connect off and on button signal with onPushButtonControlOnClicked slot
    QObject::connect(ui->buttonOffOn[0],&QPushButton::clicked,this, &MainWindow::onPushButtonControlOnClicked);
    QObject::connect(ui->buttonOffOn[1],&QPushButton::clicked,this, &MainWindow::onPushButtonControlOffClicked);


}

void MainWindow::on_pushButtonSystem_clicked()
{
    /// Delete layout content and system widget setup
    ui->DeleteLayoutContent();

    /// Select state
    if (dataJson->data.humidity < 50.)
    {
        if (settings->settings.pressure == "мм.рт.ст")
        {
            if (dataJson->data.pressure < 752.)
            {
                ui->SystemWidget("   сухо","низкое");
            }
            else
            {
                ui->SystemWidget("   сухо","высокое");
            }
        }
        else
        {
            if (dataJson->data.pressure < 100258.)
            {
                ui->SystemWidget("   сухо","низкое");
            }
            else
            {
                ui->SystemWidget("   сухо","высокое");
            }
        }
    }

    else
    {
        if (settings->settings.pressure == "мм.рт.ст")
        {
            if (dataJson->data.pressure < 752.)
            {
                ui->SystemWidget("влажно","низкое");
            }
            else
            {
                ui->SystemWidget("влажно","высокое");
            }
        }
        else
        {
            if (dataJson->data.pressure < 100258.)
            {
                ui->SystemWidget("влажно","низкое");
            }
            else
            {
                ui->SystemWidget("влажно","высокое");
            }
        }
    }

    /// Fill system label with data
    double arr[3];
    dataJson->readJsonFile(arr);
    ui->labelsSystem[1]->setText(QString::number(arr[0]) + ", " + settings->settings.temperature);
}
void MainWindow::on_pushButtonData_clicked()
{
    /// Delete layout content and data widget setup
    ui->DeleteLayoutContent();
    ui->DataWidget();

    /// Block line edit with powerSystem = false
    for ( int i = 0 ; i < 3 ; i ++){
        ui->lineEditData[i]->setEnabled(powerSystem);
    }

    /// Fill data labeles with data
    ui->labelDigitData[0]->setText(", " + settings->settings.temperature);
    ui->labelDigitData[1]->setText(", " + settings->settings.pressure);

    /// Connect save button signal with onPushButtonDataClicked slot
    QObject::connect(ui->pushButtonSaveData,&QPushButton::clicked,this, &MainWindow::onPushButtonDataClicked);
}
void MainWindow::on_themeButton_clicked(){

    /// Change app theme
    if (!ui->theme)
    {
        this->setStyleSheet("background-color: rgb(7, 11, 6); color:rgb(177, 203, 169); ");
        ui->verticalWidget->setStyleSheet("QWidget {background-color: rgb(22, 35, 19);border-radius: 15px;};");
        ui->theme = !ui->theme;
        ui->themeButton->setText("светлая тема");
    }
    else{
        this->setStyleSheet("background-color: rgb(205, 225, 199); color:rgb(7, 11, 6); ");
        ui->verticalWidget->setStyleSheet("QWidget {background-color: rgb(147, 175, 139);border-radius: 15px;};");
        ui->theme = !ui->theme;
        ui->themeButton->setText("темная тема");
    }
}

void MainWindow::onPushButtonDataClicked()
{
    /// Writte to JSON
    dataJson->writeDataJson(ui->lineEditData[0]->text().toDouble(), ui->lineEditData[1]->text().toDouble(),ui->lineEditData[2]->text().toDouble());
}

void MainWindow::onPushButtonControlClicked()
{
    /// Save control data
    double arr[3];
    dataJson->readJsonFile(arr);
    dataJson->writeDataJson(ui->doubleSpinBoxControl->value(), arr[1], arr[2]);
}

void MainWindow::onPushButtonControlOnClicked()
{
    /// On and off buton setup
    ui->buttonOffOn[0]->setStyleSheet("QPushButton {\n"
                                      "background-color: rgb(147, 175, 139);\n"
                                      "border-style: solid;\n"
                                      "border-width: 2px;\n"
                                      "border-radius: 15px;\n"
                                      "border-color: rgb(71, 101, 63);\n"
                                      "}\n"
                                      "QPushButton:pressed{\n"
                                      "color: white;\n"
                                      "background-color: rgb(71, 101, 63);\n"
                                      "border-style: dashed;\n"
                                      "}");
    ui->buttonOffOn[1]->setStyleSheet("QPushButton {\n"
                                         "background-color: rgba(191, 64, 64, 0);\n"
                                         "border-style: solid;\n"
                                         "border-width: 2px;\n"
                                         "border-radius: 15px;\n"
                                         "border-color: rgb(71, 101, 63);\n"
                                         "}\n"
                                         "QPushButton:pressed{\n"
                                         "color: white;\n"
                                         "background-color: rgb(71, 101, 63);\n"
                                         "border-style: dashed;\n"
                                         "}");
    powerSystem = !powerSystem;
    ui->buttonOffOn[0]->setEnabled(false);
    ui->buttonOffOn[1]->setEnabled(true);
}

void MainWindow::onPushButtonControlOffClicked()
{
    /// On and off buton setup
    ui->buttonOffOn[1]->setStyleSheet("QPushButton {\n"
                                      "background-color: rgb(147, 175, 139);\n"
                                      "border-style: solid;\n"
                                      "border-width: 2px;\n"
                                      "border-radius: 15px;\n"
                                      "border-color: rgb(71, 101, 63);\n"
                                      "}\n"
                                      "QPushButton:pressed{\n"
                                      "color: white;\n"
                                      "background-color: rgb(71, 101, 63);\n"
                                      "border-style: dashed;\n"
                                      "}");
    ui->buttonOffOn[0]->setStyleSheet("QPushButton {\n"
                                         "background-color: rgba(191, 64, 64, 0);\n"
                                         "border-style: solid;\n"
                                         "border-width: 2px;\n"
                                         "border-radius: 15px;\n"
                                         "border-color: rgb(71, 101, 63);\n"
                                         "}\n"
                                         "QPushButton:pressed{\n"
                                         "color: white;\n"
                                         "background-color: rgb(71, 101, 63);\n"
                                         "border-style: dashed;\n"
                                         "}");
    powerSystem = !powerSystem;
    ui->buttonOffOn[0]->setEnabled(true);
    ui->buttonOffOn[1]->setEnabled(false);
    dataJson->deleteJsonFile();
}

void MainWindow::currentTextChangedInfo()
{
    /// Modify XML element
    QString text = ui->comboBoxInfo[0]->currentText();
    settings->modifyElement(elements[0],text );
    double value = ui->lineEditInfo[0]->text().toDouble();

    /// Recalculation value
    settings->recalculation(text, &value);
    settings->settings.temperature = text;
    ui->lineEditInfo[0]->setText(QString::number(value));

    /// Writte to JSON
    dataJson->writeDataJson(value, dataJson->data.pressure, dataJson->data.humidity);
}

void MainWindow::currentTextChangedInfo_2()
{
    /// Modify XML element
    QString text = ui->comboBoxInfo[1]->currentText();
    settings->modifyElement(elements[1],text );
    double value = ui->lineEditInfo[1]->text().toDouble();

    /// Recalculation value
    settings->recalculation(text, &value);
    settings->settings.pressure = text;
    ui->lineEditInfo[1]->setText(QString::number(value));

    /// Writte to JSON
    dataJson->writeDataJson(dataJson->data.temperature, value, dataJson->data.humidity);
}

