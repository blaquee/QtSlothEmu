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
    mRegData.clear();

#ifdef _WIN64
    mRegisterMapping.insert(std::make_pair(CAX, "RAX"));
    mRegisterMapping.insert(std::make_pair(CBX, "RBX"));
    mRegisterMapping.insert(std::make_pair(CCX, "RCX"));
    mRegisterMapping.insert(std::make_pair(CDX, "RDX"));
    mRegisterMapping.insert(std::make_pair(CBP, "RBP"));
    mRegisterMapping.insert(std::make_pair(CSP, "RSP"));
    mRegisterMapping.insert(std::make_pair(CSI, "RSI"));
    mRegisterMapping.insert(std::make_pair(CDI, "RDI"));

    mRegisterMapping.insert(std::make_pair(R8, "R8"));
    mRegisterMapping.insert(std::make_pair(R9, "R9"));
    mRegisterMapping.insert(std::make_pair(R10, "R10"));
    mRegisterMapping.insert(std::make_pair(R11, "R11"));
    mRegisterMapping.insert(std::make_pair(R12, "R12"));
    mRegisterMapping.insert(std::make_pair(R13, "R13"));
    mRegisterMapping.insert(std::make_pair(R14, "R14"));
    mRegisterMapping.insert(std::make_pair(R15, "R15"));

    mRegisterMapping.insert(std::make_pair(CIP, "RIP"));

    mRegisterMapping.insert(std::make_pair(EFLAGS, "RFLAGS"));
#else //x32
    mRegisterMapping.insert(std::make_pair(CAX, "EAX"));
    mRegisterMapping.insert(std::make_pair(CBX, "EBX"));
    mRegisterMapping.insert(std::make_pair(CCX, "ECX"));
    mRegisterMapping.insert(std::make_pair(CDX, "EDX"));
    mRegisterMapping.insert(std::make_pair(CBP, "EBP"));
    mRegisterMapping.insert(std::make_pair(CSP, "ESP"));
    mRegisterMapping.insert(std::make_pair(CSI, "ESI"));
    mRegisterMapping.insert(std::make_pair(CDI, "EDI"));

    mRegisterMapping.insert(std::make_pair(CIP, "EIP"));

    mRegisterMapping.insert(std::make_pair(EFLAGS, "EFLAGS"));
#endif

    mRegisterMapping.insert(std::make_pair(ZF, "ZF"));
    mRegisterMapping.insert(std::make_pair(PF, "PF"));
    mRegisterMapping.insert(std::make_pair(AF, "AF"));

    mRegisterMapping.insert(std::make_pair(OF, "OF"));
    mRegisterMapping.insert(std::make_pair(SF, "SF"));
    mRegisterMapping.insert(std::make_pair(DF, "DF"));

    mRegisterMapping.insert(std::make_pair(CF, "CF"));
    mRegisterMapping.insert(std::make_pair(TF, "TF"));
    mRegisterMapping.insert(std::make_pair(IF, "IF"));

    mRegisterMapping.insert(std::make_pair(LastError, "LastError"));

    mRegisterMapping.insert(std::make_pair(GS, "GS"));
    mRegisterMapping.insert(std::make_pair(FS, "FS"));
    mRegisterMapping.insert(std::make_pair(ES, "ES"));
    mRegisterMapping.insert(std::make_pair(DS, "DS"));
    mRegisterMapping.insert(std::make_pair(CS, "CS"));
    mRegisterMapping.insert(std::make_pair(SS, "SS"));

    //zero initialize by default
    for(auto it = mRegisterMapping.begin(); it != mRegisterMapping.end(); ++it)
    {
        //RegToStringType tmp;
        //tmp.insert(0, it.key(), it.value());

        RegValueType tmp(it->first, 0);
        mRegData.push_back(tmp);
    }
}

int CpuModel::rowCount(const QModelIndex &parent = QModelIndex()) const
{
    Q_UNUSED(parent);
    return mRegData.count();
}

int CpuModel::columnCount(const QModelIndex &parent = QModelIndex()) const
{
    Q_UNUSED(parent);
    return 2;
}

QVariant CpuModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();
    // Display the data
    if(role == Qt::DisplayRole)
    {
        //ensure index is within range
        //if (index > mRegValueData.size())
         //   return QVariant();
        auto data = mRegData[index.row()];

        switch(index.column())
        {
        case 0:
        {
            //Name of Register
            auto it = mRegisterMapping.find(data.first);
            if(it != mRegisterMapping.end())
            {
                return QString::fromStdString(it->second);
            }
            return "None";
        }
        case 1:
        {
            // value in hex
            QString value = QString("%1").arg(data.second, 0, 16);
            return value;
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

Qt::ItemFlags CpuModel::flags(const QModelIndex &index) const
{
    //only edit the register values
    if(index.column() == 1)
    {
        return Qt::ItemIsEditable | Qt::ItemIsSelectable| QAbstractTableModel::flags(index);
    }
    return QAbstractTableModel::flags(index);
}

bool CpuModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(index.column() == 1)
    {
        if(role == Qt::EditRole)
        {
            QString s = value.toString();
#ifdef _WIN64
            setRegValue(index.row(), s.toULongLong(nullptr, 16));
#else
            setRegValue(index.row(), s.toULong(nullptr, 16));
#endif
            emit dataChanged(index, index);
            return true;
        }
    }
    return false;
}

std::string CpuModel::getRegString(const REGISTER_NAME name) const
{
    auto keyIter = mRegisterMapping.find(name);
    if(keyIter != mRegisterMapping.end())
        return keyIter->second;
    return "";
}
