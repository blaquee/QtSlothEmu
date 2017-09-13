#include <QPair>
#include "cpumodel.h"
#include "contextview.h"


CpuModel::CpuModel(QObject *parent = 0):QAbstractTableModel(parent)
{
    //initialize the underlying data
    initMappings();
}

CpuModel::~CpuModel()
{

}

void CpuModel::initMappings()
{
    mRegisterMapping.clear();
    mRegMapListing.clear();
    mRegValueData.clear();

#ifdef _WIN64
    mRegisterMapping.insert(CAX, "RAX");
    mRegisterMapping.insert(CBX, "RBX");
    mRegisterMapping.insert(CCX, "RCX");
    mRegisterMapping.insert(CDX, "RDX");
    mRegisterMapping.insert(CBP, "RBP");
    mRegisterMapping.insert(CSP, "RSP");
    mRegisterMapping.insert(CSI, "RSI");
    mRegisterMapping.insert(CDI, "RDI");

    mRegisterMapping.insert(R8, "R8");
    mRegisterMapping.insert(R9, "R9");
    mRegisterMapping.insert(R10, "R10");
    mRegisterMapping.insert(R11, "R11");
    mRegisterMapping.insert(R12, "R12");
    mRegisterMapping.insert(R13, "R13");
    mRegisterMapping.insert(R14, "R14");
    mRegisterMapping.insert(R15, "R15");

    mRegisterMapping.insert(CIP, "RIP");

    mRegisterMapping.insert(EFLAGS, "RFLAGS");
#else //x32
    mRegisterMapping.insert(CAX, "EAX");
    mRegisterMapping.insert(CBX, "EBX");
    mRegisterMapping.insert(CCX, "ECX");
    mRegisterMapping.insert(CDX, "EDX");
    mRegisterMapping.insert(CBP, "EBP");
    mRegisterMapping.insert(CSP, "ESP");
    mRegisterMapping.insert(CSI, "ESI");
    mRegisterMapping.insert(CDI, "EDI");

    mRegisterMapping.insert(CIP, "EIP");

    mRegisterMapping.insert(EFLAGS, "EFLAGS");
#endif

    mRegisterMapping.insert(ZF, "ZF");
    mRegisterMapping.insert(PF, "PF");
    mRegisterMapping.insert(AF, "AF");

    mRegisterMapping.insert(OF, "OF");
    mRegisterMapping.insert(SF, "SF");
    mRegisterMapping.insert(DF, "DF");

    mRegisterMapping.insert(CF, "CF");
    mRegisterMapping.insert(TF, "TF");
    mRegisterMapping.insert(IF, "IF");

    mRegisterMapping.insert(LastError, "LastError");

    mRegisterMapping.insert(GS, "GS");
    mRegisterMapping.insert(FS, "FS");
    mRegisterMapping.insert(ES, "ES");
    mRegisterMapping.insert(DS, "DS");
    mRegisterMapping.insert(CS, "CS");
    mRegisterMapping.insert(SS, "SS");

    //Add them to the vector
    for(auto it = mRegisterMapping.begin(); it != mRegisterMapping.end(); ++it)
    {
        RegToStringType tmp;
        tmp.insert(0, it.key(), it.value());
        mRegMapListing.push_back(tmp);
    }

    //zero initialize by default
    for(auto it = mRegisterMapping.begin(); it != mRegisterMapping.end(); ++it)
    {
        //RegToStringType tmp;
        //tmp.insert(0, it.key(), it.value());

        RegValueType tmp(it.key(), 0);
        mRegValueData.push_back(tmp);
    }
}

int CpuModel::rowCount(const QModelIndex &parent = QModelIndex()) const
{
    return mRegValueData.count();
}

int CpuModel::columnCount(const QModelIndex &parent = QModelIndex()) const
{
    return 2;
}

QVariant CpuModel::data(const QModelIndex &index, int role) const
{
    // What does this actually check?
    if(!index.isValid())
        return QVariant();
    if(role == Qt::DisplayRole)
    {
        //ensure index is within range
        //if (index > mRegValueData.size())
         //   return QVariant();
        auto data = mRegValueData[index.row()];

        switch(index.column())
        {
        case 0:
        {
            //Name of Register
            auto it = mRegisterMapping.find(data.first);
            return it.value();
        }
        case 1:
        {
            // value
            return data.second;
        }
        }

    }
    return QVariant();
}

QVariant CpuModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role != Qt::DisplayRole || orientation != Qt::Horizontal)
        return QVariant();

    switch(section)
    {
    case 0:
        return "Name";
    case 1:
        return "Value";
    }
    return QVariant();
}

QString CpuModel::getRegString(const REGISTER_NAME name) const
{
    return "";
}
