#ifndef CPU_H
#define CPU_H

#include <QAbstractTableModel>
#include <QString>
#include <QSet>
#include <QVector>
#include <string>
#include "defines.h"



class CpuModel: public QAbstractTableModel
{
    Q_OBJECT
public:
    CpuModel(QObject* parent);
    ~CpuModel();

    void initMappings();
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    std::string getRegString(const REGISTER_NAME name) const;

    template<class T>
    void setRegValue(int reg, T value)
    {
        mRegData[reg].second = value;
    }

private:
    RegToStringType mRegisterMapping;
    int mNumRows;
    int mNumColumns;
    QVector<RegValueType> mRegData;

};

#endif // CPU_H
