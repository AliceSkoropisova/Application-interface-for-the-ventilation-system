#ifndef DATA_H
#define DATA_H
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>
#include <QDebug>

struct dataJson{
    double temperature;
    double pressure;
    double humidity;
};

class Data
{
public:
    Data();
    ~Data();


    dataJson data; ///< Data about temperature, pressure and humidity

    /**
     * @brief writeDataJson The function writes data to a JSON
     * @param temperature Temperature value
     * @param pressure Pressure value
     * @param humidity Humidity value
     */
    void writeDataJson(double temperature, double pressure, double humidity);

    /**
     * @brief readJsonFile The function reads data from JSON
     * @param data Array for storing data
     */
    void readJsonFile(double *data);

    /**
     * @brief deleteJsonFile The function deletes JSON
     */
    void deleteJsonFile();


private:

    QJsonObject dataJsonObj; ///< JSON object

    /**
     * @brief writeJsonToFile The function writes JSON object to a JSON
     */
    void writeJsonToFile();

    /**
     * @brief toJsonObject The function converts data to JSON object
     */
    void toJsonObject();
};

#endif // DATA_H
