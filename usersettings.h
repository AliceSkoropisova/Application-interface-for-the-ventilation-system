#ifndef USERSETTINGS_H
#define USERSETTINGS_H
#include <QFile>
#include <QDomDocument>
#include <QTextStream>
#include <QDebug>
#include <QString>
#include <QFileInfo>

struct Settings{
    QString temperature;
    QString pressure;
};

class UserSettings
{
public:

    Settings settings; ///< Structure for storing users settings

    UserSettings();

    /**
     * @brief modifyElement The function for modify XML element
     * @param elementName XML element name
     * @param newElementValue New XML element value
     */
    void modifyElement(QString elementName,  QString newElementValue);

    /**
     * @brief searchElements The function searches XML element
     * @param elementName XML element name
     * @return XML element value
     */
    QString searchElements(QString &elementName);

    /**
     * @brief recalculation The function recalculations values of temperature or pressure
     * @param newValue New XML element name
     * @param value Temperature or pressure value
     */
    void recalculation(QString newValue, double *value);

};

#endif // USERSETTINGS_H
