#include "testdialog.h"
#include "ui_testdialog.h"

qreal editor_factor = 1.0;
//-----------------------------
void AppStyle::initStyleSheets(QApplication* app)
{
    QString qss;
    qss += readQss(":/stylesheet/qlabel.qss");
    app->setStyleSheet(qss);
}

 QString AppStyle::readQss(const QString& qssPath)
{
    bool ret = false;
    QFile file;
    file.setFileName(qssPath);
    ret = file.open(QIODevice::ReadOnly | QIODevice::Text);
    return dpiScaleSheet(file.readAll());
}

 qreal AppStyle::dpiScaled(qreal value)
 {
     static qreal scale = -1;
     if (scale < 0)
     {
         QScreen* screen = qobject_cast<QApplication*>(QApplication::instance())->primaryScreen();
         qreal dpi = screen->logicalDotsPerInch();
         scale = dpi / 96.0;
     }
     return value * scale;
 }

 QSize AppStyle::dpiScaledSize(const QSize& value)
 {
     return QSize(AppStyle::dpiScaled(value.width()), AppStyle::dpiScaled(value.height()));
 }

 QSizeF AppStyle::dpiScaledSize(const QSizeF& sz)
 {
     return QSizeF(AppStyle::dpiScaled(sz.width()), AppStyle::dpiScaled(sz.height()));
 }

 QMargins AppStyle::dpiScaledMargins(const QMargins& margins)
 {
     return QMargins(AppStyle::dpiScaled(margins.left()), AppStyle::dpiScaled(margins.top()),
         AppStyle::dpiScaled(margins.right()), AppStyle::dpiScaled(margins.bottom()));
 }

 QString AppStyle::dpiScaleSheet(const QString& sheet) {
     if (sheet.isEmpty()) {
         return sheet;
     }

     QString tempStyle = sheet;
     tempStyle.replace("FontFamily", QApplication::font().family());

     qreal scale = AppStyle::dpiScaled(1);
     if (scale == 1.0) {
         return tempStyle;
     }

     QRegExp rx("\\d+px", Qt::CaseInsensitive);
     rx.setMinimal(true);
     int index = -1;
     while ((index = rx.indexIn(tempStyle, index + 1)) >= 0) {
         int capLen = rx.cap(0).length() - 2;
         QString strNum = tempStyle.mid(index, capLen);
         strNum = QString::number(qRound(strNum.toInt() * scale));
         tempStyle.replace(index, capLen, strNum);
         index += strNum.length();
         if (index > tempStyle.size() - 2) {
             break;
         }
     }
     return tempStyle;
 }

 qreal AppStyle::scaleWidth(qreal value)
 {
     qreal dividend = 1;
     if (editor_factor < 0.3f)
         dividend = editor_factor / 0.5;
     else if (editor_factor < 1.0f)
         dividend = editor_factor / 0.8;
     return AppStyle::dpiScaled(value / dividend);
 }


const char* qssRadiobutton = "\n"
"QRadioButton::indicator {\n"
"    width: 13px;\n"
"    height: 13px;\n"
"}\n"
"\n"
"QRadioButton::indicator::unchecked {\n"
"    image: url(:/icons/radiobutton_unchecked.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked:hover {\n"
"    image: url(:/icons/radiobutton_unchecked_hover.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked:pressed {\n"
"    image: url(:/icons/radiobutton_unchecked_pressed.png);\n"
"}\n"
""
"QRadioButton::indicator::checked {"
"    image: url(:/icons/radiobutton_checked.png);"
"}\n"
""
"QRadioButton::indicator:checked:hover {"
"    image: url(:/icons/radiobutton_checked_hover.png);"
"}\n"
""
"QRadioButton::indicator:checked:pressed {"
"    image: url(:/icons/radiobutton_checked_pressed.png);"
"}\n"
"";


TestDialog::TestDialog(QWidget* parent)
    : QDialog(parent)
{
    m_ui = new Ui::Dialog;
    m_ui->setupUi(this);

    //CustomTextLabel* label = new CustomTextLabel(this);
    m_ui->custom_label->setText("ABC");
    m_ui->custom_label->setHoverCursor(Qt::PointingHandCursor);
    //m_ui->custom_label->setTextColor(const QColor & clr);
    //m_ui->custom_label->setBackgroundColor(const QColor & clr);

    //CustomIconLabel* iconLabel = new CustomIconLabel(this);
    //iconLabel->setIcons(QSize(24,24), ":/icons/sphere.png", ":/icons/sphere.png");
}

OLinkLabel::OLinkLabel(QWidget* parent)
    :QLabel(parent)
{
    setFixedSize(70, 22);
    setOpenExternalLinks(false);
    setText("<a href=\"www.baidu.com\">Clicked</a>");
}