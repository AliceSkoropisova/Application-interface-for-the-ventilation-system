#include "data.h"

Data::Data()
{
    /// Writte initial data to JSON
    writeDataJson(0,0,0);
}

Data::~Data()
{
    /// Deleting JSON
    deleteJsonFile();
}

void Data::writeJsonToFile()
{
    /// Convert data to JsonObject
    toJsonObject();

    /// Convert data to JsonDocument
    QJsonDocument jsonDoc(dataJsonObj);

    /// Writte to JSON
    QFile file("data.json");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        qWarning("Couldn't open file for writing.");
        return;
    }

    file.write(jsonDoc.toJson());
    file.close();
}

void Data::deleteJsonFile()
{
    /// Delete JSON
    if (QFile::exists("data.json"))
    {
        if (QFile::remove("data.json")){
            qDebug() << "File deleted successfully.";
            return;
        }
        else
        {
            qWarning() << "Failed to delete file.";
            return;
        }
    }
    else
    {
        qWarning() << "File does not exist.";
        return;
    }
}

void Data::writeDataJson(double temperature, double pressure, double humidity)
{
    /// Writte data
    data.temperature = temperature;
    data.pressure = pressure;
    data.humidity = humidity;

    /// Convert data to JsonObject
    toJsonObject();

    /// Writte to JSON
    writeJsonToFile();
}

void Data::readJsonFile(double *array)
{
    QFile file("data.json");

    /// Open JSON
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qWarning("Couldn't open the file.");
    }

    /// Read JSON contents
    QByteArray fileData = file.readAll();
    file.close();

    /// Convert data to JsonDocument
    QJsonDocument doc = QJsonDocument::fromJson(fileData);

    /// Check the validity of a JSON document
    if (doc.isNull() || !doc.isObject())
    {
        qWarning("Invalid JSON document.");
    }

    /// Extract the root object
    QJsonObject json = doc.object();

    /// Extract data from a JSON object
    array[0] = json["temperature"].toDouble();
    array[1] = json["pressure"].toDouble();
    array[2] = json["humidity"].toDouble();


}

void Data::toJsonObject()
{

    /// Read JSON contents and convert to data structure
    dataJsonObj["temperature"] = data.temperature;
    dataJsonObj["pressure"] = data.pressure;
    dataJsonObj["humidity"] = data.humidity;
}
