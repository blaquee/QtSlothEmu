#ifndef CPU_H
#define CPU_H

#include <QAbstractTableModel>
#include <QString>
#include <QSet>
#include <QVector>

enum REGISTER_NAME
{
    CAX, CCX, CDX, CBX, CDI, CBP, CSI, CSP,
    R8, R9, R10, R11, R12, R13, R14, R15,
    CIP,
    EFLAGS, CF, PF, AF, ZF, SF, TF, IF, DF, OF,
    GS, FS, ES, DS, CS, SS,
    LastError,
    DR0, DR1, DR2, DR3, DR6, DR7,
    UNKNOWN
    /*
    // x87 stuff
    x87r0, x87r1, x87r2, x87r3, x87r4, x87r5, x87r6, x87r7,
    x87TagWord, x87ControlWord, x87StatusWord,
    // x87 Tag Word fields
    x87TW_0, x87TW_1, x87TW_2, x87TW_3, x87TW_4, x87TW_5,
    x87TW_6, x87TW_7,
    // x87 Status Word fields
    x87SW_B, x87SW_C3, x87SW_TOP, x87SW_C2, x87SW_C1, x87SW_O,
    x87SW_ES, x87SW_SF, x87SW_P, x87SW_U, x87SW_Z,
    x87SW_D, x87SW_I, x87SW_C0,
    // x87 Control Word fields
    x87CW_IC, x87CW_RC, x87CW_PC, x87CW_PM,
    x87CW_UM, x87CW_OM, x87CW_ZM, x87CW_DM, x87CW_IM,
    //MxCsr
    MxCsr, MxCsr_FZ, MxCsr_PM, MxCsr_UM, MxCsr_OM, MxCsr_ZM,
    MxCsr_IM, MxCsr_DM, MxCsr_DAZ, MxCsr_PE, MxCsr_UE, MxCsr_OE,
    MxCsr_ZE, MxCsr_DE, MxCsr_IE, MxCsr_RC,
    // MMX and XMM
    MM0, MM1, MM2, MM3, MM4, MM5, MM6, MM7,
    XMM0, XMM1, XMM2, XMM3, XMM4, XMM5, XMM6, XMM7,
    XMM8, XMM9, XMM10, XMM11, XMM12, XMM13, XMM14, XMM15,
    // YMM
    YMM0, YMM1, YMM2, YMM3, YMM4, YMM5, YMM6, YMM7, YMM8,
    YMM9, YMM10, YMM11, YMM12, YMM13, YMM14, YMM15,

    UNKNOWN
    */
};

typedef QMap<REGISTER_NAME, QString> RegToStringType;
typedef QVector<RegToStringType> RegToStringTypeList;
typedef QPair<REGISTER_NAME, int> RegValueType;

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
    QString getRegString(const REGISTER_NAME name) const;

private:
    RegToStringType mRegisterMapping;
    RegToStringTypeList mRegMapListing;
    int mNumRows;
    int mNumColumns;
    QVector<RegValueType> mRegValueData;

};

#endif // CPU_H
