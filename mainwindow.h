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

#include "controlpanel.h"

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

    QPushButton *btnClear;
    QPushButton *btnPort;
    QPushButton *btnSendFile;

    QLabel *lblInput;
    QLabel *lblDelay;
    QLabel *lblLog;

    QComboBox *cmbInput;
    QComboBox *cmbPlain;
    QComboBox *cmbBaud;

    QCheckBox *chkHexOut;
    QCheckBox *chkLog;

    QSpinBox *spbDelay;

    QLineEdit *lntInput;

    QTextEdit *txtInput;
    QTextEdit *txtOutput;

    QHBoxLayout *hbxInput;
    QHBoxLayout *hbxOutput;
    QVBoxLayout *vbxInput;
    QVBoxLayout *vbxOutput;

    ControlPanel *controlPanel;
};

#endif
