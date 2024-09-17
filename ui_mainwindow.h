#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets>
#include <QDoubleValidator>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    /// Main window
    QWidget *centralwidget=nullptr; ///< Central widget
    QHBoxLayout *horizontalLayout=nullptr; ///< Horizontal layout for central widget
    QVBoxLayout *layoutContent=nullptr;
    QWidget *widget=nullptr; ///< Widget for content
    QWidget *verticalWidget=nullptr; ///< Vertical widget for menu widget
    QVBoxLayout *verticalLayout=nullptr; ///< Vertical layout for buttons
    QLabel *label=nullptr; ///< Label for menu text
    QPushButton *pushButton[4]; ///< Buttons for menu
    QPushButton *themeButton=nullptr; ///< Button for change theme
    bool theme = false;

    /// Info widget
    QLabel *labelWidgetNameInfo=nullptr; ///< Label for widget name
    QGridLayout *gridLayout=nullptr; ///< Grid layout for widgets
    QLabel *labelDiscr[3]; ///< Labels for discription on info widget
    QLineEdit *lineEditInfo[3]; ///< Line edit for outputting information on info widget
    QComboBox *comboBoxInfo[2]; ///< Combo boxes for selecting units of measurement on info widget
    QLabel *labelHumidityInfo=nullptr; ///< Label for output of units of measurement of humididty on info widget

    /// Control widget
    QLabel *labelGradControl=nullptr; ///< Label for widget name on control widget
    QLabel *labelDialControl=nullptr; ///< Label for output of direction angle on control widget
    QLabel *labelTemperatureControl= nullptr; ///< Label for output of units of measurement of temperature on control widget
    QDoubleSpinBox *doubleSpinBoxControl=nullptr; ///< Double spin box for changing temperature on control widget
    QPushButton *buttonOffOn[2]; ///< Push buttons for on and off on control widget
    QPushButton* pushButtonSaveControl = nullptr; ///< Push button for save data on control widget
    QDial *dialControl=nullptr; ///< Dial control for change the direction angle on control widget

    /// System widget
    QGraphicsView *graphicsViewSystem[2]; ///< Graphics views for display the system status on system widget
    QGraphicsScene *scene[2]; ///< Graphics scenes for display the system status on system widget
    QGraphicsTextItem *textHumidity, *textPressure; ///< Graphics text items for display the system status on system widget
    QLabel *labelsSystem[2]; ///< Labels for widget name display the temperature status on system widget

    /// Data widget
    QLabel *labelDigitData[3]; ///< Labels for output of units of measurement on system widget
    QLineEdit *lineEditData[3]; ///< Lines edit for output of units of measurement on system widget
    QPushButton* pushButtonSaveData = nullptr; ///< Push button for save data on system widget

    /**
     * @brief setupUi The function to create the main window of the application
     * @param MainWindow The main application window
     */
    void setupUi(QMainWindow *MainWindow)
    {
        /// Main window setup
        MainWindow->resize(800, 600);
        MainWindow->setMinimumSize(800,600);
        MainWindow->setMaximumSize(1024,768);
        MainWindow->setStyleSheet("background-color: rgb(205, 225, 199);"
                                  "color:rgb(7, 11, 6); ");

        /// Central widget setup
        centralwidget = new QWidget(MainWindow);
        MainWindow->setCentralWidget(centralwidget);
        horizontalLayout = new QHBoxLayout(centralwidget);

        /// Vertical widget menu setup
        verticalWidget = new QWidget(centralwidget);
        verticalWidget->setMinimumSize(QSize(200, 0));
        verticalWidget->setMaximumSize(QSize(250, 16777215));
        verticalWidget->setBaseSize(QSize(200, 0));
        verticalWidget->setObjectName("menuWidget");
        verticalWidget->setStyleSheet("QWidget {background-color: rgb(147, 175, 139);"
                                      "border-radius: 15px;};");

        /// Vertical layout for buttons setup
        verticalLayout = new QVBoxLayout(verticalWidget);
        verticalLayout->setContentsMargins(20, 20, 20, 20);

        /// Label setup
        label = new QLabel(verticalWidget);
        label->setMinimumSize(QSize(0, 30));
        label->setMaximumSize(QSize(16777215, 30));
        label->setAlignment(Qt::AlignCenter);
        label->setText("МЕНЮ");
        QFont font;
        font.setPointSize(15);
        label->setFont(font);
        verticalLayout->addWidget(label);

        /// Menu buttons setup
        for(int i = 0 ; i < 4 ; i++)
        {
            pushButton[i] = new QPushButton(verticalWidget);
            pushButton[i]->setMinimumHeight(30);
            pushButton[i]->setMaximumHeight(40);
            pushButton[i]->setCursor(QCursor(Qt::PointingHandCursor));
            pushButton[i]->setStyleSheet("QPushButton {\n"
                                         "background-color: rgba(191, 64, 64, 0);\n"
                                         "border-style: dashed;\n"
                                         "border-width: 5px;\n"
                                         "border-radius: 15px;\n"
                                         "border-color: rgb(71, 101, 63);\n"
                                         "}\n"
                                         "QPushButton:pressed{\n"
                                         "color: white;\n"
                                         "background-color: rgb(71, 101, 63);\n"
                                         "border-style: dashed;\n"
                                         "}");
            verticalLayout->addWidget(pushButton[i]);
        }
        pushButton[0]->setText("ИНФОРМАЦИЯ");
        pushButton[0]->setObjectName(QString::fromUtf8("pushButtonInfo"));
        pushButton[1]->setText("УПРАВЛЕНИЕ");
        pushButton[1]->setObjectName(QString::fromUtf8("pushButtonControl"));
        pushButton[2]->setText("СИСТЕМА");
        pushButton[2]->setObjectName(QString::fromUtf8("pushButtonSystem"));
        pushButton[3]->setText("ВВОД ДАННЫХ");
        pushButton[3]->setObjectName(QString::fromUtf8("pushButtonData"));

        /// Theme button setup
        themeButton = new QPushButton(verticalWidget);
        themeButton->setMinimumHeight(25);
        themeButton->setMaximumHeight(25);
        themeButton->setCursor(QCursor(Qt::PointingHandCursor));
        themeButton->setStyleSheet("QPushButton {\n"
                                   "background-color: rgba(191, 64, 64, 0);\n"
                                   "border-style: solid;\n"
                                   "border-width: 5px;\n"
                                   "border-radius: 10px;\n"
                                   "border-color: rgb(71, 101, 63);\n"
                                   "}\n"
                                   "QPushButton:pressed{\n"
                                   "color: white;\n"
                                   "background-color: rgb(71, 101, 63);\n"
                                   "border-style: solid;\n"
                                   "}");
        themeButton->setText("темная тема");
        themeButton->setObjectName(QString::fromUtf8("themeButton"));
        verticalLayout->addWidget(themeButton);

        /// Menu block setup
        horizontalLayout->addWidget(verticalWidget);

        /// Widget for content block setup
        widget = new QWidget(centralwidget);
        widget->setMinimumSize(QSize(600, 0));
        widget->setMaximumSize(QSize(766, 16777215));
        layoutContent = new QVBoxLayout(centralwidget);
        layoutContent->addWidget(widget);
        horizontalLayout->addLayout(layoutContent);
        gridLayout = new QGridLayout(widget);

        /// Set central widget
        MainWindow->setCentralWidget(centralwidget);

        /// Connect slots
        QMetaObject::connectSlotsByName(MainWindow);
    }

    /**
     * @brief DeleteLayoutContent The function to remove all widgets from a layout
     */
    void DeleteLayoutContent();

    /**
     * @brief InfoWidget The function to create info widget
     */
    void InfoWidget();

    /**
     * @brief ControlWidget The function to create control widget
     */
    void ControlWidget();

    /**
     * @brief SystemWidget The function to create system widget
     * @param humidity The string for outputting humidity status
     * @param pressure The string for outputting pressure status
     */
    void SystemWidget(QString humidity, QString pressure);

    /**
     * @brief DataWidget The function to create info widget
     */
    void DataWidget();

    /**
     * @brief WidgetSetUp The function for widget customization
     * @param labelWidgetText The label for displaying widget name
     */
    void WidgetSetUp(QString labelWidgetText);



};

void Ui_MainWindow::DeleteLayoutContent(){

    /// Item for deleting child elements of a layout
    QLayoutItem *item;

    /// Deleting elements
    while ((item = this->gridLayout->takeAt(0)) != nullptr) {
        if (item->widget()) {
            delete item->widget();
        }
        delete item;
    }
    if(widget) delete widget;
    if(labelWidgetNameInfo) delete labelWidgetNameInfo;
}

void Ui_MainWindow::WidgetSetUp(QString labelWidgetText){

    /// Widget setup
    widget = new QWidget(centralwidget);
    widget->setMinimumSize(QSize(580, 0));
    widget->setMaximumSize(QSize(746, 16777215));

    /// Label setup
    labelWidgetNameInfo = new QLabel(verticalWidget);
    labelWidgetNameInfo->setMaximumSize(QSize(16777215, 40));
    labelWidgetNameInfo->setMinimumSize(QSize(580,40));
    labelWidgetNameInfo->setAlignment(Qt::AlignCenter);
    labelWidgetNameInfo->setStyleSheet("border-style:dashed none dashed; border-width: 1px; border-color:rgb(71, 101, 63);");
    labelWidgetNameInfo->setText(labelWidgetText);

    /// Placing label on a layout
    layoutContent->addWidget(labelWidgetNameInfo);

    /// Grid layout setup
    gridLayout = new QGridLayout(widget);
    gridLayout->setContentsMargins(10, 10, 10, 300);
}


void Ui_MainWindow::InfoWidget(){

    /// Info widget setup
    WidgetSetUp("ИНФОРМАЦИЯ");

    /// Info labels for descriptions setup
    for(int i = 0; i < 3; i++)
    {
        labelDiscr[i] = new QLabel(widget);
        labelDiscr[i]->setAlignment(Qt::AlignCenter);
        gridLayout->addWidget(labelDiscr[i], i, 0, 1, 1);
    }
    labelDiscr[0]->setText("ТЕМПЕРАТУРА");
    labelDiscr[1]->setText("ДАВЛЕНИЕ");
    labelDiscr[2]->setText("ВЛАЖНОСТЬ");

    /// Info line edit for information output setup
    for( int i = 0; i < 3; i++)
    {
        lineEditInfo[i] = new QLineEdit(widget);
        lineEditInfo[i]->setMinimumSize(QSize(350, 30));
        lineEditInfo[i]->setMaximumSize(QSize(400, 16777215));
        lineEditInfo[i]->setReadOnly(true);
        lineEditInfo[i]->setText("0");
        lineEditInfo[i]->setStyleSheet("background-color: rgba(191, 64, 64, 0);\n"
                                   "border-style: solid;\n"
                                   "border-width: 2px;\n"
                                   "border-radius: 10px;\n"
                                   "border-color: rgb(71, 101, 63);\n");
        gridLayout->addWidget(lineEditInfo[i], i, 1, 1, 1);
    }

    /// Info combo box setup
    for( int i = 0; i < 2; i++)
    {
        comboBoxInfo[i] = new QComboBox(widget);
        comboBoxInfo[i]->setMinimumSize(QSize(90, 30));
        comboBoxInfo[i]->setStyleSheet("background-color: rgba(191, 64, 64, 0);\n"
                                   "border-style: solid;\n"
                                   "border-width: 2px;\n"
                                   "border-radius: 10px;\n"
                                   "border-color: rgb(71, 101, 63);\n");
        gridLayout->addWidget(comboBoxInfo[i], i, 2, 1, 1);
    }
    comboBoxInfo[0]->insertItems(0,{"°C","°F","K"});
    comboBoxInfo[1]->insertItems(0,{"мм.рт.ст","Па"});

    /// Info label for humidity setup
    labelHumidityInfo = new QLabel(widget);
    labelHumidityInfo->setMinimumSize(QSize(90, 30));
    gridLayout->addWidget(labelHumidityInfo, 2, 2, 1, 1);
    labelHumidityInfo->setText(", %");

    /// Placing widget on layout
    layoutContent->addWidget(widget);
}

void Ui_MainWindow::ControlWidget(){

    /// Control widget setup
    WidgetSetUp("УПРАВЛЕНИЕ");

    /// Control labels for discripton setup
    for(int i = 0; i < 3; i++)
    {
        labelDiscr[i] = new QLabel(widget);
        labelDiscr[i]->setAlignment(Qt::AlignCenter);
        labelDiscr[i]->setMinimumSize(180,30);
        //gridLayout->addWidget(labelDiscr[i], i, 0, 1, 1);
    }
    labelDiscr[0]->setText("Изменить температуру");
    gridLayout->addWidget(labelDiscr[0], 0, 0, 1, 1);
    labelDiscr[1]->setText("Изменить направление");
    gridLayout->addWidget(labelDiscr[1], 1, 0, 1, 1);
    labelDiscr[2]->setText("Питание");
    gridLayout->addWidget(labelDiscr[2], 3, 0, 1, 1);

    /// Control labeles for angle setup
    labelGradControl = new QLabel(widget);
    labelGradControl->setMaximumSize(QSize(80, 16777215));
    labelGradControl->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
    labelGradControl->setText("0");

    gridLayout->addWidget(labelGradControl, 1, 1, 1, 1);

    labelDialControl = new QLabel(widget);
    labelDialControl->setMaximumSize(QSize(80, 16777215));
    labelDialControl->setText("°");

    gridLayout->addWidget(labelDialControl, 1, 2, 1, 1);

    /// Control double spin box setup
    doubleSpinBoxControl = new QDoubleSpinBox(widget);
    doubleSpinBoxControl->setMinimumSize(QSize(200, 30));
    doubleSpinBoxControl->setRange(-100000.0, 100000.0);
    doubleSpinBoxControl->setStyleSheet("background-color: rgba(191, 64, 64, 0);\n"
                               "border-style: solid;\n"
                               "border-width: 2px;\n"
                               "border-radius: 10px;\n"
                               "border-color: rgb(71, 101, 63);\n");

    gridLayout->addWidget(doubleSpinBoxControl, 0, 1, 1, 2);

    /// Control label for temperature setup
    labelTemperatureControl = new QLabel(widget);
    labelTemperatureControl->setText(", °C");
    gridLayout->addWidget(labelTemperatureControl, 0, 3, 1, 1);

    /// Control buttons for on and off setup
    for( int i = 0; i < 2; i++){
        buttonOffOn[i] = new QPushButton(widget);
        buttonOffOn[i]->setMinimumSize(QSize(80, 30));
        buttonOffOn[i]->setMaximumSize(QSize(200, 16777215));
        buttonOffOn[i]->setCursor(QCursor(Qt::PointingHandCursor));
        buttonOffOn[i]->setStyleSheet("QPushButton {\n"
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

        gridLayout->addWidget(buttonOffOn[i], 3, i+1, 1, 1);
    }

    buttonOffOn[0]->setText("ВКЛ");
    buttonOffOn[0]->setEnabled(false);
    buttonOffOn[0]->setStyleSheet("QPushButton {\n"
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
\
    buttonOffOn[1]->setText("ВЫКЛ");

    /// Control button for save setup
    pushButtonSaveControl = new QPushButton(widget);
    pushButtonSaveControl->setCursor(QCursor(Qt::PointingHandCursor));
    pushButtonSaveControl->setMinimumSize(QSize(150, 30));
    pushButtonSaveControl->setMaximumSize(QSize(200, 16777215));
    pushButtonSaveControl->setStyleSheet("QPushButton {\n"
                                 "    background-color: rgba(191, 64, 64, 0);\n"
                                 "    border-style: solid;\n"
                                 "    border-width: 2px;\n"
                                 "    border-radius: 15px;\n"
                                 "    border-color: rgb(71, 101, 63);\n"
                                 "}\n"
                                 "QPushButton:pressed{\n"
                                 "    color: white;\n"
                                 "    background-color: rgb(71, 101, 63);\n"
                                 "    border-style: dashed;\n"
                                 "}");

    gridLayout->addWidget(pushButtonSaveControl, 2, 1, 1, 2);
    pushButtonSaveControl->setText("ИЗМЕНИТЬ");

    /// Control dial setup
    dialControl = new QDial(widget);
    dialControl->setMinimumSize(QSize(100, 150));
    dialControl->setMaximumSize(QSize(150, 150));
    dialControl->setObjectName(QString::fromUtf8("dialControl"));
    dialControl->setRange(0,360);

    gridLayout->addWidget(dialControl, 1, 3, 1, 1);

    /// Placing widget on layout
    layoutContent->addWidget(widget);

    /// Connect control slots
    QObject::connect(dialControl, SIGNAL(valueChanged(int)),labelGradControl,  SLOT(setNum(int)));

}

void Ui_MainWindow::SystemWidget(QString humidity, QString pressure){
    /// System widget setup
    WidgetSetUp("СИСТЕМА");

    /// System graphics elements setup
    for(int i = 0; i < 2; i++)
    {
        graphicsViewSystem[i] = new QGraphicsView(widget);
        graphicsViewSystem[i]->setMaximumSize(QSize(100, 100));
        graphicsViewSystem[i]->scale(0.6, 0.6);
        graphicsViewSystem[i]->setStyleSheet("border-radius:50px;"
                                             "background-color:qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.9, fx:0.505, fy:0.5, "
                                             "stop:0.31 rgb(205, 225, 199), stop:1 rgb(71, 101, 63));");
        gridLayout->addWidget(graphicsViewSystem[i], 0, i, 1, 1);
    }
    scene[0] = new QGraphicsScene(widget);
    scene[1] = new QGraphicsScene(widget);

    scene[0]->addPixmap(QPixmap(":/img/blob.png"));
    scene[1]->addPixmap(QPixmap(":/img/circle.png"));

    graphicsViewSystem[0]->setScene(scene[0]);
    graphicsViewSystem[1]->setScene(scene[1]);

    textHumidity = scene[0]->addText(humidity);
    textHumidity->setPos(20,70);
    textPressure = scene[1]->addText(pressure);
    textPressure->setPos(20,80);

    /// System labels setup
    QFont font("Arial",20, QFont::Bold);
    for (int i = 0; i < 2; i++){
        labelsSystem[i] = new QLabel(widget);
        labelsSystem[i]->setAlignment(Qt::AlignCenter);
        labelsSystem[i]->setFont(font);
        labelsSystem[i]->setStyleSheet("border-style:solid none none; border-width: 1px; border-color:rgb(71, 101, 63);");
        gridLayout->addWidget(labelsSystem[i], i+1, 0, 1, 2);
    }
    labelsSystem[0]->setText("ТЕМПЕРАТУРА");
    labelsSystem[1]->setText("0");

    /// Placing widget on layout
    layoutContent->addWidget(widget);
}

void Ui_MainWindow::DataWidget()
{
    /// System widget setup
    WidgetSetUp("ВВОД ДАННЫХ");

    /// System labels for discription setup
    for(int i = 0; i < 3; i++)
    {
        labelDiscr[i] = new QLabel(widget);
        labelDiscr[i]->setAlignment(Qt::AlignCenter);
        gridLayout->addWidget(labelDiscr[i], i, 0, 1, 1);
    }
    labelDiscr[0]->setText("ТЕМПЕРАТУРА");
    labelDiscr[1]->setText("ДАВЛЕНИЕ");
    labelDiscr[2]->setText("ВЛАЖНОСТЬ");

    /// System line edit setup
    for( int i = 0; i < 3; i++)
    {
        lineEditData[i] = new QLineEdit(widget);
        lineEditData[i]->setMinimumSize(QSize(350, 30));
        lineEditData[i]->setMaximumSize(QSize(400, 16777215));
        lineEditData[i]->setStyleSheet("background-color: rgba(191, 64, 64, 0);\n"
                                   "border-style: solid;\n"
                                   "border-width: 2px;\n"
                                   "border-radius: 10px;\n"
                                   "border-color: rgb(71, 101, 63);\n");
        lineEditData[i]->setValidator(new QDoubleValidator(lineEditData[i]));
        lineEditData[i]->setText("0");
        gridLayout->addWidget(lineEditData[i], i, 1, 1, 1);

    }

    /// System labels for units of measurement setup
    for(int i = 0; i < 3; i++)
    {
        labelDigitData[i] = new QLabel(widget);
        labelDigitData[i]->setAlignment(Qt::AlignCenter);
        labelDigitData[i]->setMinimumSize(QSize(90, 30));
        gridLayout->addWidget(labelDigitData[i], i, 2, 1, 1);
    }
    labelDigitData[0]->setText("°С");
    labelDigitData[1]->setText("мм.рт.ст");
    labelDigitData[2]->setText("%");

    /// System button for save setup
    pushButtonSaveData = new QPushButton(widget);
    pushButtonSaveData->setCursor(QCursor(Qt::PointingHandCursor));
    pushButtonSaveData->setMinimumSize(QSize(350, 30));
    pushButtonSaveData->setStyleSheet("QPushButton {\n"
                                 "    background-color: rgba(191, 64, 64, 0);\n"
                                 "    border-style: solid;\n"
                                 "    border-width: 2px;\n"
                                 "    border-radius: 15px;\n"
                                 "    border-color: rgb(71, 101, 63);\n"
                                 "}\n"
                                 "QPushButton:pressed{\n"
                                 "    color: white;\n"
                                 "    background-color: rgb(71, 101, 63);\n"
                                 "    border-style: dashed;\n"
                                 "}");

    gridLayout->addWidget(pushButtonSaveData, 3, 1, 1, 1);
    pushButtonSaveData->setText("СОХРАНИТЬ");

    /// Placing widget on layout
    layoutContent->addWidget(widget);
}

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
}

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
