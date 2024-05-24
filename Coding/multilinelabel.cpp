#include "multilinelabel.h"
#include <QApplication>
#include <QPainter>


MultilineLabel::MultilineLabel(const QString& text, qreal fixedWidth, QWidget* parent)
    : QWidget(parent)
    , m_fixedWidth(fixedWidth)
{
    QFontMetrics fontMetrics(QApplication::font());

    QString currentLine;
    int totalw = 0, y = 0;
    for (QChar ch : text)
    {
        int cw = fontMetrics.horizontalAdvance(ch);
        totalw += cw;
        if (totalw < m_fixedWidth) {
            currentLine.append(ch);
        }
        else {
            totalw = cw;
            m_segments.append(currentLine);
            currentLine.clear();
            currentLine.append(ch);
        }
    }
    if (!currentLine.isEmpty()) {
        m_segments.append(currentLine);
    }

    //上述分行并没有考虑字符串原有的换行符，以及wordwrap，请自行调整逻辑。
    int lines = m_segments.size();
    int fontHeight = fontMetrics.height();
    setFixedSize(fixedWidth, fontHeight * lines);
}

void MultilineLabel::paintEvent(QPaintEvent* e)
{
    QPainter painter(this);

    QFont fnt = QApplication::font();
    QFontMetrics fontMetrics(fnt);
    int fontHeight = fontMetrics.height();
    int y = 0;
    for (QString seg : m_segments)
    {
        /*
        The flags argument is a bitwise OR of the following flags:
            Qt::AlignLeft
            Qt::AlignRight
            Qt::AlignHCenter
            Qt::AlignJustify
            Qt::AlignTop
            Qt::AlignBottom
            Qt::AlignVCenter
            Qt::AlignCenter
            Qt::TextSingleLine
            Qt::TextExpandTabs
            Qt::TextShowMnemonic
            Qt::TextWordWrap
        */
        int flags = Qt::TextSingleLine;
        painter.drawText(0, y, m_fixedWidth, fontHeight, flags, seg);
        y += fontHeight;
    }
}