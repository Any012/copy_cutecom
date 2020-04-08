#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QCheckBox>
#include <QComboBox>
#include <QSpinBox>
#include <QLineEdit>
#include <QTextEdit>
#include <QSplitter>
#include <QStatusBar>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include <QSerialPort>
#include <QSerialPortInfo>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    void createItems();
    void initUI();
    void initSerial();


    QMenuBar *menuBar;

    QStatusBar *stsBar;

    QSplitter *splMain;

    QWidget *wdtInput;
    QWidget *wdtOutput;

    QPushButton *btnSend;
    QPushButton *btnClear;
    QPushButton *btnPort;
    QPushButton *btnSendFile;

    QLabel *lblPort;
    QLabel *lblInput;
    QLabel *lblDelay;
    QLabel *lblLog;

    QComboBox *cmbPort;
    QComboBox *cmbInput;
    QComboBox *cmbPlain;
    QComboBox *cmbBaud;

    QCheckBox *chkRTS;
    QCheckBox *chkDTR;
    QCheckBox *chkReconnect;
    QCheckBox *chkHexOut;
    QCheckBox *chkLog;

    QSpinBox *spbDelay;

    QLineEdit *lntInput;

    QTextEdit *txtInput;
    QTextEdit *txtOutput;

    QHBoxLayout *hbxPort;
    QHBoxLayout *hbxInput;
    QHBoxLayout *hbxOutput;
    QVBoxLayout *vbxInput;
    QVBoxLayout *vbxOutput;
};

#endif
