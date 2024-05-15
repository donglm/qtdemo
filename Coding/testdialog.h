#pragma once

namespace Ui
{
    class Dialog;
}

#include <QtWidgets>

class TestDialog : public QDialog
{
    Q_OBJECT
public:
    TestDialog(QWidget* parent = nullptr);

private:
    Ui::Dialog* m_ui;
};

class OLinkLabel: public QLabel
{
    Q_OBJECT
public:
    OLinkLabel(QWidget* parent = nullptr);

};

class AppStyle
{
public:
    static void initStyleSheets(QApplication* app);
    static QString readQss(const QString& qssPath);
    static qreal dpiScaled(qreal value);
    static QSize dpiScaledSize(const QSize& value);
    static QSizeF dpiScaledSize(const QSizeF& sz);

    static QMargins dpiScaledMargins(const QMargins& margins);
    static QString dpiScaleSheet(const QString& sheet);
    static qreal scaleWidth(qreal value);
};