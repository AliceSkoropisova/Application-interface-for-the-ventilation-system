#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>

#include <data.h>
#include <usersettings.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Data *dataJson; ///< Data class object for converting data to JSON
    UserSettings *settings; ///< UserSettings class object for converting users settings to XML

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    /**
     * @brief on_pushButtonInfo_clicked Slot for info button signal
     */
    void on_pushButtonInfo_clicked();

    /**
     * @brief on_pushButtonControl_clicked Slot for control button signal
     */
    void on_pushButtonControl_clicked();

    /**
     * @brief on_pushButtonSystem_clicked Slot for system button signal
     */
    void on_pushButtonSystem_clicked();

    /**
     * @brief on_pushButtonData_clicked Slot for data button signal
     */
    void on_pushButtonData_clicked();

    /**
     * @brief on_themeButton_clicked Slot for change theme button signal
     */
    void on_themeButton_clicked();

    /**
     * @brief onPushButtonDataClicked Slot for save data button signal
     */
    void onPushButtonDataClicked();

    /**
     * @brief onPushButtonControlClicked Slot for save control data button signal
     */
    void onPushButtonControlClicked();

    /**
     * @brief onPushButtonControlOnClicked Slot for system on button signal
     */
    void onPushButtonControlOnClicked();

    /**
     * @brief onPushButtonControlOffClicked Slot for system off button signal
     */
    void onPushButtonControlOffClicked();

    /**
     * @brief currentTextChangedInfo Slot for change text combo box temperature signal
     */
    void currentTextChangedInfo();

    /**
     * @brief currentTextChangedInfo_2 Slot for change text combo box pressure signal
     */
    void currentTextChangedInfo_2();

private:
    Ui::MainWindow *ui; ///< UI

    QString elements[2] = {"temperature","pressure"}; ///< Elements name

    bool powerSystem = true; ///< Information about system activation
};
#endif // MAINWINDOW_H
