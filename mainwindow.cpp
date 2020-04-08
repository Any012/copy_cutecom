#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    createItems();
    initUI();
    initSerial();
}

MainWindow::~MainWindow()
{}

void MainWindow::createItems()
{    
    btnSend = new QPushButton(tr("发送"));
    btnPort = new QPushButton(tr("打开"));
    btnSendFile = new QPushButton(tr("发送文件"));
    btnClear = new QPushButton(tr("清除"));

    lblPort = new QLabel(tr("串口"));
    lblInput = new QLabel(tr("输入"));
    lblDelay = new QLabel(tr("延时"));
    lblLog = new QLabel(tr("某位置"));
    
    cmbPort = new QComboBox();
    cmbBaud = new QComboBox();
    cmbInput = new QComboBox();
    cmbPlain = new QComboBox();

    chkRTS = new QCheckBox("RTS");
    chkDTR = new QCheckBox("DTR");
    chkReconnect = new QCheckBox(tr("自动重连"));
    chkHexOut = new QCheckBox(tr("Hex输出"));
    chkLog = new QCheckBox(tr("记录到:"));

    spbDelay = new QSpinBox();
    spbDelay->setSuffix(tr("ms"));

    lntInput = new QLineEdit();

    txtInput = new QTextEdit();
    txtOutput = new QTextEdit();


}

void MainWindow::initUI()
{
    splMain = new QSplitter(Qt::Vertical);

    wdtInput = new QWidget();
    wdtOutput = new QWidget();

    hbxPort = new QHBoxLayout();
    hbxInput = new QHBoxLayout();
    hbxOutput = new QHBoxLayout();

    vbxInput = new QVBoxLayout();
    vbxOutput = new QVBoxLayout();

    hbxPort->addWidget(btnPort);
    hbxPort->addWidget(lblPort);
    hbxPort->addWidget(cmbPort);
    hbxPort->addWidget(cmbBaud);
    hbxPort->addWidget(chkRTS);
    hbxPort->addWidget(chkDTR);
    hbxPort->addWidget(chkReconnect);

    hbxInput->addWidget(lblInput);
    hbxInput->addWidget(lntInput);
    hbxInput->addWidget(cmbInput);
    hbxInput->addWidget(lblDelay);
    hbxInput->addWidget(spbDelay);
    hbxInput->addWidget(btnSendFile);
    hbxInput->addWidget(cmbPlain);

    hbxOutput->addWidget(btnClear);
    hbxOutput->addWidget(chkHexOut);
    hbxOutput->addWidget(chkLog);
    hbxOutput->addWidget(lblLog);

    vbxInput->addLayout(hbxPort);
    vbxInput->addWidget(txtInput);
    vbxInput->addLayout(hbxInput);

    vbxOutput->addWidget(txtOutput);
    vbxOutput->addLayout(hbxOutput);

    wdtInput->setLayout(vbxInput);
    wdtOutput->setLayout(vbxOutput);

    splMain->addWidget(wdtInput);
    splMain->addWidget(wdtOutput);

    setCentralWidget(splMain);

    stsBar = statusBar();
}

void MainWindow::initSerial()
{
    cmbBaud->addItem(QStringLiteral("1200"), QSerialPort::Baud1200);
    cmbBaud->addItem(QStringLiteral("4800"), QSerialPort::Baud4800);
    cmbBaud->addItem(QStringLiteral("9600"), QSerialPort::Baud9600);
    cmbBaud->addItem(QStringLiteral("19200"), QSerialPort::Baud19200);
    cmbBaud->addItem(QStringLiteral("38400"), QSerialPort::Baud38400);
    cmbBaud->addItem(QStringLiteral("57600"), QSerialPort::Baud57600);
    cmbBaud->addItem(QStringLiteral("115200"), QSerialPort::Baud115200);
    cmbBaud->insertSeparator(90);
    cmbBaud->addItem(QStringLiteral("Custom"), -1);
}
