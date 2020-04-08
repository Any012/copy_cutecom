#include "controlpanel.h"
#include <QFileDialog>

ControlPanel::ControlPanel(QWidget *parent) : QFrame(parent)
{
    createItems();
    initLayout();
    initSerial();
    initConnections();
}

ControlPanel::~ControlPanel()
{}

void ControlPanel::createItems()
{
    btnPort = new QPushButton(tr("打开"));
    btnLog = new QPushButton("...");
    btnLog->setMaximumWidth(30);

    lblBaud = new QLabel(tr("波特率"));
    lblDataBits = new QLabel(tr("数据位"));
    lblStopBits = new QLabel(tr("停止位"));
    lblParity = new QLabel(tr("校    验"));
    lblFlowControl = new QLabel(tr("流    控"));
    lblMode = new QLabel(tr("模    式"));
    lblPort = new QLabel(tr("串口:"));
    lblLogFile = new QLabel(tr("记录到..."));

    cmbPort = new QComboBox();
    cmbBaud = new QComboBox();
    cmbDataBits = new QComboBox();
    cmbStopBits = new QComboBox();
    cmbParity = new QComboBox();
    cmbFlowControl = new QComboBox();
    cmbMode = new QComboBox();

    chkCharacters = new QCheckBox(tr("显示控制字符"));
    chkTimestamp = new QCheckBox(tr("显示时间戳"));
    chkRTS = new QCheckBox("RTS");
    chkDTR = new QCheckBox("DTR");
    chkReconnect = new QCheckBox(tr("自动重连"));
    chkAppend = new QCheckBox("Append");

    lntLog = new QLineEdit("");
    lntLog->setMaximumWidth(100);

    wdtTab = new QWidget();
    wdtTab->setLayoutDirection(Qt::LeftToRight);

    tabPanel = new QTabWidget();
    tabPanel->setTabPosition(QTabWidget::South);
    tabPanel->setLayoutDirection(Qt::RightToLeft);
}

void ControlPanel::initLayout()
{
    vbxPanel = new QVBoxLayout();
    hbxPanel = new QHBoxLayout();
    grdPanel = new QGridLayout();
    hbxLog = new QHBoxLayout();

    hbxLog->addWidget(lblLogFile);
    hbxLog->addWidget(lntLog);
    hbxLog->addWidget(btnLog);
    hbxLog->addWidget(chkAppend);
    hbxLog->addStretch();

    grdPanel->addWidget(lblBaud, 1, 1);
    grdPanel->addWidget(cmbBaud, 1, 2);
    grdPanel->addWidget(lblDataBits, 1, 3);
    grdPanel->addWidget(cmbDataBits, 1, 4);
    grdPanel->addWidget(chkCharacters, 1, 5);
    grdPanel->addWidget(lblFlowControl, 2, 1);
    grdPanel->addWidget(cmbFlowControl, 2, 2);
    grdPanel->addWidget(lblParity, 2, 3);
    grdPanel->addWidget(cmbParity, 2, 4);
    grdPanel->addWidget(chkTimestamp, 2, 5);
    grdPanel->addWidget(lblMode, 3, 1);
    grdPanel->addWidget(cmbMode, 3, 2);
    grdPanel->addWidget(lblStopBits, 3, 3);
    grdPanel->addWidget(cmbStopBits, 3, 4);
    grdPanel->addLayout(hbxLog, 3, 5);

    wdtTab->setLayout(grdPanel);
    tabPanel->addTab(wdtTab, tr("设置"));

    hbxPanel->addWidget(btnPort);
    hbxPanel->addWidget(lblPort);
    hbxPanel->addWidget(cmbPort);
    hbxPanel->addWidget(chkRTS);
    hbxPanel->addWidget(chkDTR);
    hbxPanel->addWidget(chkReconnect);
    hbxPanel->addStretch();
//    hbxPanel->addWidget(tabPanel);

    vbxPanel->addWidget(tabPanel);
    vbxPanel->addLayout(hbxPanel);

    setLayout(vbxPanel);
}

void ControlPanel::initSerial()
{
    cmbPort->clear();
    int numberDevices = 0;
    for(auto info : QSerialPortInfo::availablePorts())
    {
        cmbPort->addItem(info.systemLocation());
        if(!info.isNull())
        {
            QString deviceInfo = QString("%1 %2\n%3:%4 # %5")
                .arg(info.manufacturer())
                .arg(info.description())
                .arg(info.vendorIdentifier())
                .arg(info.productIdentifier())
                .arg(info.serialNumber());
            cmbPort->setItemData(numberDevices, deviceInfo, Qt::ToolTipRole);
        }
        else
        {
            cmbPort->setItemData(numberDevices, tr("Not a valid device"), Qt::ToolTipRole);
        }
        numberDevices++;
    }

    cmbBaud->addItem(QStringLiteral("9600"), QSerialPort::Baud9600);
    cmbBaud->addItem(QStringLiteral("19200"), QSerialPort::Baud19200);
    cmbBaud->addItem(QStringLiteral("38400"), QSerialPort::Baud38400);
    cmbBaud->addItem(QStringLiteral("57600"), QSerialPort::Baud57600);
    cmbBaud->addItem(QStringLiteral("115200"), QSerialPort::Baud115200);
    cmbBaud->insertSeparator(9);
    cmbBaud->addItem(QStringLiteral("自定义"), -1);

    cmbFlowControl->addItem(QStringLiteral("None"), QSerialPort::NoFlowControl);
    cmbFlowControl->addItem(QStringLiteral("Hardware"), QSerialPort::HardwareControl);
    cmbFlowControl->addItem(QStringLiteral("Software"), QSerialPort::SoftwareControl);

    cmbParity->addItem(QStringLiteral("None"), QSerialPort::NoParity);
    cmbParity->addItem(QStringLiteral("Even"), QSerialPort::EvenParity);
    cmbParity->addItem(QStringLiteral("Odd"), QSerialPort::OddParity);
    cmbParity->addItem(QStringLiteral("Mark"), QSerialPort::MarkParity);

    cmbDataBits->addItem(QStringLiteral("5"), QSerialPort::Data5);
    cmbDataBits->addItem(QStringLiteral("6"), QSerialPort::Data6);
    cmbDataBits->addItem(QStringLiteral("7"), QSerialPort::Data7);
    cmbDataBits->addItem(QStringLiteral("8"), QSerialPort::Data8);

    cmbStopBits->addItem(QStringLiteral("1"), QSerialPort::OneStop);
    cmbStopBits->addItem(QStringLiteral("1.5"), QSerialPort::OneAndHalfStop);
    cmbStopBits->addItem(QStringLiteral("2"), QSerialPort::TwoStop);

    cmbMode->addItem(tr("只读"), QIODevice::ReadOnly);
    cmbMode->addItem(tr("只写"), QIODevice::WriteOnly);
    cmbMode->addItem(tr("读/写"), QIODevice::ReadWrite);

    connect(btnLog, &QPushButton::clicked, this, &ControlPanel::chooseLogFile);
}

void ControlPanel::chooseLogFile()
{
    QString logFile = QFileDialog::getSaveFileName(this, tr("保存记录到..."), lntLog->text());
    if(!logFile.isEmpty())
    {
        lntLog->setText(logFile);
    }
}

void ControlPanel::initConnections()
{
    connect(btnPort, &QPushButton::clicked, this, &ControlPanel::toggleDevice);
}

void ControlPanel::toggleDevice()
{}
