#include "usersettings.h"

UserSettings::UserSettings()
{
    QFileInfo fileInfo("user_settings.xml");
    if (!fileInfo.exists())
    {
        QDomDocument doc;

        /// Create root element
        QDomElement root = doc.createElement("settings");
        doc.appendChild(root);

        /// Create base elements of structure
        QDomElement temperatureElem = doc.createElement("temperature");
        QDomText temperatureText = doc.createTextNode("°C");
        temperatureElem.appendChild(temperatureText);
        root.appendChild(temperatureElem);

        QDomElement pressureElem = doc.createElement("pressure");
        QDomText pressureText = doc.createTextNode("мм.рт.ст");
        pressureElem.appendChild(pressureText);
        root.appendChild(pressureElem);

        /// Open XML file
        QFile file("user_settings.xml");
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            qWarning() << "Could not open file for writing.";
            return;
        }

        /// Writte doc to XML
        QTextStream stream(&file);
        stream << doc.toString();
        file.close();

        qDebug() << "XML file created with default structure.";
    }
    else
    {
        qDebug() << "File already exists.";
    }
}

QString UserSettings::searchElements(QString &elementName)
{
    QFile file("user_settings.xml");

    /// Open XML file
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qWarning() << "Could not open file for reading.";
        return "2";
    }

    QDomDocument doc;

    /// Parse
    if (!doc.setContent(&file))
    {
        qWarning() << "Failed to parse the file.";
        file.close();
        return "3";
    }
    file.close();

    QString value;

    /// Search element by name
    QDomNodeList elements = doc.elementsByTagName(elementName);

    QDomNode node = elements.at(0);
    value = node.toElement().text();
    qDebug() << elementName << ":" << value;

    return value;
}

void UserSettings::recalculation(QString newValue, double *value)
{
    /// Recalculation
    if (newValue == "°C")
    {

        if (settings.temperature == "°F")
        {
            *value = ( *value * (9./5.) ) + 32.;
        }
        else if (settings.temperature == "K")
        {
            *value += 273.15;
        }

    }
    else if (newValue == "°F")
    {
        if (settings.temperature == "°C")
        {
            *value = ( *value - 32. ) * (5./9.);
        }
        else if (settings.temperature == "K")
        {
            *value = ( *value - 32. ) * (5./9.) + 273.15;
        }
    }
    else if (newValue == "K")
    {
        if (settings.temperature == "°C")
        {
            *value -= 273.15;
        }
        else if (settings.temperature == "°F")
        {
            *value = (*value - 273.15) * (9./5.) + 32.;
        }
    }
    if (newValue == "мм.рт.ст")
    {

        if (settings.pressure == "Па")
        {
            *value *= 133.3;
        }

    }
    else if (newValue == "Па")
    {
        if (settings.pressure == "мм.рт.ст")
        {
            *value /= 133.3;
        }
    }
}

void UserSettings::modifyElement(QString elementName, QString newElementValue) {

    QFile file("user_settings.xml");

    /// Open XML file for read
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qWarning() << "Could not open file for reading.";
        return;
    }

    QDomDocument doc;

    /// Parse
    if (!doc.setContent(&file))
    {
        qWarning() << "Failed to parse the file.";
        file.close();
        return;
    }
    file.close();

    /// Search element by name
    QDomNodeList elements = doc.elementsByTagName(elementName);
    if (elements.isEmpty())
    {
        qWarning() << "Element not found.";
        return;
    }

    /// Change value of element
    QDomElement element = elements.at(0).toElement();
    element.firstChild().setNodeValue(newElementValue);

    /// Save changes
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qWarning() << "Could not open file for writing.";
        return;
    }

    QTextStream stream(&file);
    doc.save(stream, 4);
    file.close();

    qDebug() << "Element value modified successfully.";
    return;
}
