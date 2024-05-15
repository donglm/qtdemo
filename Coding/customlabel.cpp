#include "customlabel.h"


DebugLabel::DebugLabel(QWidget* parent)
    : QLabel(parent)
{
}

DebugLabel::DebugLabel(const QString& text, QWidget* parent)
    : QLabel(text, parent)
    , m_text(text)
{
}

void DebugLabel::adjustText(const QString& text)
{
    m_text = text;
}



CustomIconLabel::CustomIconLabel(QWidget* parent)
    : QLabel(parent)
    , m_bToggled(false)
    , m_bHovered(false)
    , m_bClicked(false)
    , m_bToggleable(false)
{
    setStyleSheet("background: transparent");
}

void CustomIconLabel::setIcons(const QSize& sz, const QString& iconEnable, const QString& iconHover, const QString& iconNormalOn, const QString& iconHoverOn, const QString& iconDisable)
{
    m_iconSz = sz;
    m_icon.addFile(iconEnable, QSize(), QIcon::Normal, QIcon::Off);
    m_icon.addFile(iconHover, QSize(), QIcon::Active, QIcon::Off);
    m_icon.addFile(iconNormalOn, QSize(), QIcon::Normal, QIcon::On);
    m_icon.addFile(iconHoverOn, QSize(), QIcon::Active, QIcon::On);
    m_icon.addFile(iconDisable, QSize(), QIcon::Disabled, QIcon::Off);

    if (!iconNormalOn.isEmpty())
        m_bToggleable = true;

    setPixmap(m_icon.pixmap(m_iconSz, QIcon::Normal));
    setFixedSize(m_iconSz);
}

void CustomIconLabel::setIcons(const QString& iconIdle, const QString& iconLight)
{
    QIcon ic(iconIdle);
    QPixmap px(iconIdle);
    m_iconSz = px.size();
    m_icon.addFile(iconIdle, QSize(), QIcon::Normal, QIcon::Off);
    m_icon.addFile(iconLight, QSize(), QIcon::Active, QIcon::Off);
    m_bToggleable = false;
    setPixmap(m_icon.pixmap(m_iconSz, QIcon::Normal));
    setFixedSize(m_iconSz);
}

void CustomIconLabel::toggle(bool bToggle)
{
    if (m_bToggleable)
    {
        m_bToggled = bToggle;
        updateIcon();
    }
}

void CustomIconLabel::enterEvent(QEvent* event)
{
    m_bHovered = true;
    updateIcon();
}

void CustomIconLabel::leaveEvent(QEvent* event)
{
    m_bHovered = false;
    updateIcon();
}

void CustomIconLabel::paintEvent(QPaintEvent* e)
{
    QLabel::paintEvent(e);
}

void CustomIconLabel::mouseReleaseEvent(QMouseEvent* event)
{
    QLabel::mouseReleaseEvent(event);
    if (m_bToggleable)
    {
        m_bToggled = !m_bToggled;
    }
    updateIcon();
    if (m_bToggleable)
    {
        emit toggled(m_bToggled);
    }
    emit clicked();
}

void CustomIconLabel::onClicked()
{

}

void CustomIconLabel::updateIcon()
{
    if (isEnabled())
    {
        setPixmap(m_icon.pixmap(m_iconSz, m_bHovered ? QIcon::Active : QIcon::Normal, m_bToggled ? QIcon::On : QIcon::Off));
    }
    else
    {
        setPixmap(m_icon.pixmap(m_iconSz, QIcon::Disabled));
    }
    update();
}

void CustomIconLabel::onToggled()
{
}



CustomTextLabel::CustomTextLabel(QWidget* parent)
    : QLabel(parent)
    , m_bUnderlineHover(false)
    , m_bUnderline(false)
    , m_hoverCursor(Qt::PointingHandCursor)
{
    setMouseTracking(true);
}

CustomTextLabel::CustomTextLabel(const QString& text, QWidget* parent)
    : QLabel(text, parent)
    , m_bUnderlineHover(false)
    , m_bUnderline(false)
    , m_hoverCursor(Qt::PointingHandCursor)
{
    setMouseTracking(true);
}

void CustomTextLabel::setHoverCursor(Qt::CursorShape shape)
{
    m_hoverCursor = shape;
}

void CustomTextLabel::setUnderline(bool bUnderline)
{
    m_bUnderline = bUnderline;
}

void CustomTextLabel::setUnderlineOnHover(bool bUnderline)
{
    m_bUnderlineHover = bUnderline;
}

void CustomTextLabel::setEnterCursor(Qt::CursorShape shape)
{
    m_hoverCursor = shape;
}

void CustomTextLabel::setTextColor(const QColor& clr)
{
    m_normal = clr;
    QPalette pal = palette();
    pal.setColor(QPalette::WindowText, m_normal);
    setPalette(pal);
}

void CustomTextLabel::setBackgroundColor(const QColor& clr)
{
    QPalette pal = palette();
    pal.setColor(backgroundRole(), QColor(56, 57, 56));
    setAutoFillBackground(true);
    setPalette(pal);
}

void CustomTextLabel::enterEvent(QEvent* event)
{
    QPalette pal = palette();
    pal.setColor(QPalette::WindowText, QColor(255, 255, 255));
    setPalette(pal);

    if (m_bUnderlineHover || m_bUnderline)
    {
        QFont fnt = this->font();
        fnt.setUnderline(true);
        setFont(fnt);
    }

    setCursor(m_hoverCursor);
}

void CustomTextLabel::leaveEvent(QEvent* event)
{
    QPalette pal = palette();
    pal.setColor(QPalette::WindowText, m_normal);
    setPalette(pal);

    if (m_bUnderlineHover)
    {
        QFont fnt = this->font();
        fnt.setUnderline(false);
        setFont(fnt);
    }

    setCursor(Qt::ArrowCursor);
}

void CustomTextLabel::mouseReleaseEvent(QMouseEvent* event)
{
    QLabel::mouseReleaseEvent(event);
    if (event->button() == Qt::LeftButton)
        emit clicked();
    else if (event->button() == Qt::RightButton)
        emit rightClicked();
}

void CustomTextLabel::mousePressEvent(QMouseEvent* event)
{
    QPalette pal = palette();
    pal.setColor(QPalette::WindowText, QColor(85, 177, 85));
    setPalette(pal);
}
