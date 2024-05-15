#ifndef __CUSTOM_LABEL_H__
#define __CUSTOM_LABEL_H__

#include <QtWidgets>

class DebugLabel : public QLabel
{
    Q_OBJECT
public:
    DebugLabel(QWidget* parent = nullptr);
    DebugLabel(const QString& text, QWidget* parent = nullptr);
    void adjustText(const QString& text);

private:
    QString m_text;
};

class CustomIconLabel : public QLabel
{
    Q_OBJECT
public:
    CustomIconLabel(QWidget* pLabel = nullptr);
    void setIcons(const QSize& sz, const QString& iconEnable, const QString& iconHover, const QString& iconNormalOn = QString(), const QString& iconHoverOn = QString(), const QString& iconDisable = QString());
    void setIcons(const QString& iconIdle, const QString& iconLight);
    void toggle(bool bToggle = true);

protected:
    void paintEvent(QPaintEvent* e) override;
    void enterEvent(QEvent* event) override;
    void leaveEvent(QEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;

signals:
    void clicked();
    void toggled(bool);

private:
    void onClicked();
    void onToggled();
    void updateIcon();

    QIcon m_icon;
    QSize m_iconSz;
    bool m_bToggled;
    bool m_bHovered;
    bool m_bClicked;
    bool m_bToggleable;
};

class CustomTextLabel : public QLabel
{
    Q_OBJECT
public:
    CustomTextLabel(QWidget* parent = nullptr);
    CustomTextLabel(const QString& text, QWidget* parent = nullptr);
    void setHoverCursor(Qt::CursorShape shape);
    void setTextColor(const QColor& clr);
    void setBackgroundColor(const QColor& clr);
    void setUnderline(bool bUnderline);
    void setUnderlineOnHover(bool bUnderline);
    void setEnterCursor(Qt::CursorShape shape);

protected:
    void enterEvent(QEvent* event) override;
    void leaveEvent(QEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;

signals:
    void clicked();
    void rightClicked();

private:
    QColor m_normal;
    Qt::CursorShape m_hoverCursor;
    bool m_bUnderlineHover;
    bool m_bUnderline;
};

#endif