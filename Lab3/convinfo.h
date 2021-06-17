#ifndef CONVINFO_H
#define CONVINFO_H

#include <QString>

class ConvInfo
{
public:
    ConvInfo();
    ConvInfo(QString date, int cityCode, QString cityName, QString timeOfConv, QString rate, QString cityNumber, QString abonentNumber);
    ~ConvInfo();
    QString convInfoData();
    QString convInfoDataRecord();
    QString getAbonentNumber();
    QString getCityName();
private:
    QString date;
    int cityCode;
    QString cityName;
    QString timeOfConv;
    QString cityNumber;
    QString abonentNumber;
    QString rate;
};

#endif // CONVINFO_H
