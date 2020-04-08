#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H

#include <QPushButton>
#include <QLabel>
#include <QComboBox>
#include <QCheckBox>
#include <QLineEdit>
#include <QTabWidget>
#include <QFrame>
#include <QSerialPort>
#include <QSerialPortInfo>

#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include "settings.h"

class ControlPanel : public QFrame
{
    Q_OBJECT

    friend class MainWindow;

signals:
    void openDeviceClicked();
    void closeDeviceClicked();
    void settingChanged(Settings::Options option, QVariant setting);

public:
    explicit ControlPanel(QWidget *parent = nullptr);
    ~ControlPanel();

    void createItems();
    void initLayout();
    void initSerial();
    void initConnections();

    void closeDevice()
    {
        toggleDevice(false);
        btnPort->setChecked(false);
    }

private:
    void chooseLogFile();
    void toggleDevice(bool open);
    
    QPushButton *btnPort;
    QPushButton *btnLog;

    QLabel *lblBaud;
    QLabel *lblDataBits;
    QLabel *lblFlowControl;
    QLabel *lblParity;
    QLabel *lblMode;
    QLabel *lblStopBits;
    QLabel *lblLogFile;
    QLabel *lblPort;

    QComboBox *cmbPort;
    QComboBox *cmbBaud;
    QComboBox *cmbDataBits;
    QComboBox *cmbFlowControl;
    QComboBox *cmbParity;
    QComboBox *cmbMode;
    QComboBox *cmbStopBits;

    QCheckBox *chkCharacters;
    QCheckBox *chkTimestamp;
    QCheckBox *chkAppend;
    QCheckBox *chkRTS;
    QCheckBox *chkDTR;
    QCheckBox *chkReconnect;

    QLineEdit *lntLog;

    QWidget *wdtTab;

    QTabWidget *tabPanel;

    QVBoxLayout *vbxPanel;
    QHBoxLayout *hbxPanel;
    QHBoxLayout *hbxLog;
    QGridLayout *grdPanel;
};

#endif
