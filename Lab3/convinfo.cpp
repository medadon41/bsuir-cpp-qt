#include "convinfo.h"

ConvInfo::ConvInfo() {

}

ConvInfo::~ConvInfo() {
}

ConvInfo::ConvInfo(QString date, int cityCode, QString cityName, QString timeOfConv, QString rate, QString cityNumber, QString abonentNumber)
{
    this->date = date;
    this->cityCode = cityCode;
    this->cityName = cityName;
    this->timeOfConv = timeOfConv;
    this->rate = rate;
    this->cityNumber = cityNumber;
    this->abonentNumber = abonentNumber;
    qDebug("Объект класса успешно добавлен");
}

QString ConvInfo::convInfoData() {
    QString convInfoData = "Дата разговора: " + date + "\nКод города: " + QString::number(cityCode) +
                          "\nНазвание города: " + cityName + "\nВремя разговора " + timeOfConv +
                          "\nТариф " + rate + "\nНомер телефона в городе " + cityName + " :" + cityNumber
                          +"\nНомер абонента: " + abonentNumber;
    return convInfoData;
}

QString ConvInfo::convInfoDataRecord() {
    QString convInfoData = "Дата разговора: " + date + "\nКод города: " + QString::number(cityCode) +
                          "\nНазвание города: " + cityName + "\nВремя разговора " + timeOfConv +
                          "\nТариф " + rate + "\nНомер телефона в городе " + cityName + " :" + cityNumber +
                          "\nНомер абонента: " + abonentNumber + "\n=====================\n";
    return convInfoData;
}

QString ConvInfo::getAbonentNumber() {
    return abonentNumber;
}


QString ConvInfo::getCityName() {
    return cityName;
}
