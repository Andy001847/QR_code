#ifndef TWODIMENSIONCODE_H
#define TWODIMENSIONCODE_H

#include <QWidget>
#include <QPainter>
#include <QPixmap>
#include <QMessageBox>
#include <QFile>
#include <QString>
#include <QDebug>
#include "libqrencode-4.0.2/qrencode.h"

namespace Ui
{
    class TwoDimensionCode;
}

class TwoDimensionCode : public QWidget
{
    Q_OBJECT

public:
    explicit TwoDimensionCode(QWidget *parent = nullptr);
    ~TwoDimensionCode();

private slots:
    void generateQRcode(void);
    void saveQRcode(void);

private:
    Ui::TwoDimensionCode *ui;
};

#endif // TWODIMENSIONCODE_H
