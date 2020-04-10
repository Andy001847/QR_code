#include "TwoDimensionCode.h"
#include "ui_TwoDimensionCode.h"

TwoDimensionCode::TwoDimensionCode(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TwoDimensionCode)
{
    ui->setupUi(this);

    this->setWindowTitle("二维码生成器 V1.0.0");
    this->setMaximumSize(600, 600);
    this->setMinimumSize(600, 600);

    ui->QRcode_content_label->setMaximumSize(500, 500);
    ui->QRcode_content_label->setMinimumSize(500, 500);

    connect(ui->generate_QRcode_pushButton, &QAbstractButton::clicked, this, &TwoDimensionCode::generateQRcode);
    connect(ui->QRcode_content_lineEdit, &QLineEdit::returnPressed, this, &TwoDimensionCode::generateQRcode);
    connect(ui->save_pushButton, &QAbstractButton::clicked, this, &TwoDimensionCode::saveQRcode);
}

TwoDimensionCode::~TwoDimensionCode()
{
    delete ui;
}

void TwoDimensionCode::generateQRcode(void)
{
    QString text = ui->QRcode_content_lineEdit->text();

    if(!text.isEmpty())
    {
        qDebug() << "二维码内容:" << text;

        /* 调用二维码库API生成二维码 */
        QRcode* qrcode = QRcode_encodeString(text.toStdString().c_str(), 2, QR_ECLEVEL_H, QR_MODE_8, 1);
        if(qrcode)
        {
            /* 设置二维码的长度和宽度 */
            qint32 width = ui->QRcode_content_label->width();
            qint32 height = ui->QRcode_content_label->height();
            qint32 qrcode_width = qrcode->width > 0 ? qrcode->width : 1;

            /* 设置二维码的缩放比例 */
            qreal scale_x = 1.0 * width / qrcode_width;
            qreal scale_y = 1.0 * height / qrcode_width;

            QImage mainimg = QImage(width, height, QImage::Format_ARGB32);

            QPainter painter(&mainimg);
            QColor background(Qt::white);
            painter.setBrush(background);
            painter.setPen(Qt::NoPen);

            painter.drawRect(0, 0, width, height);

            QColor foreground(Qt::black);
            painter.setBrush(foreground);

            /* 生成二维码中的黑白像素点 */
            for(qint32 y = 0; y < qrcode_width; y++)
            {
                for(qint32 x = 0; x < qrcode_width; x++)
                {
                    quint8 b = qrcode->data[y * qrcode_width + x];
                    if(b & 0x01)
                    {
                        QRectF qrcode(x * scale_x, y * scale_y, scale_x, scale_y);
                        painter.drawRects(&qrcode, 1);
                    }
                }
            }

            /* 将生成的二维码放置在控件中 */
            QPixmap mainmap = QPixmap::fromImage(mainimg);
            ui->QRcode_content_label->setPixmap(mainmap);
        }
        else
        {
            QMessageBox::critical(this, "错误", "二维码生成失败!", "确定");
        }
    }
    else
    {
        QMessageBox::warning(this, "警告", "请输入二维码内容!", "确定");
    }
    text.clear();
}

void TwoDimensionCode::saveQRcode(void)
{
    const QPixmap* QRcode_image = ui->QRcode_content_label->pixmap();
    if(QRcode_image)
    {
        QString display_information;

        QFile file;
        file.setFileName("二维码.png");
        display_information.append(file.fileName());
        file.open(QIODevice::WriteOnly);

        QRcode_image->save(file.fileName(), "PNG");
        file.close();

        display_information.append("保存成功!");

        QMessageBox::information(this, "提示", display_information, "确定");
        display_information.clear();
    }
    else
    {
        QMessageBox::warning(this, "警告", "请先生成二维码图片!", "确定");
    }
}
