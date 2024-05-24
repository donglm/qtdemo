#include "multilinelabel.h"


MultilineLabel::MultilineLabel(const QString& text, qreal fixedWidth, QWidget* parent)
    : QLabel(text, parent)
    , m_fixedWidth(fixedWidth)
{
    const int margin = 10;
    this->setFixedWidth(fixedWidth + m_leftMargin + m_rightMargin);
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

    m_lines = m_segments.size();
    int h = fontMetrics.height();
    this->setFixedHeight(h * m_lines + m_topMargin + m_bottomMargin);
}

QSize MultilineLabel::sizeHint() const {
    QSize sz = QLabel::sizeHint();
    return sz;
}

QSize MultilineLabel::minimumSizeHint() const {
    QSize sz = QLabel::minimumSizeHint();
    return sz;
}

void MultilineLabel::paintEvent(QPaintEvent* e)
{
    QPainter painter(this);

    QFont fnt = QApplication::font();
    QFontMetrics fontMetrics(fnt);
    QString txt = this->text();
    int fontHeight = fontMetrics.height();
    int lineWidth = m_fixedWidth;

    int mw = fontMetrics.maxWidth();

    int y = 0;
    //for (QString seg : m_segments)
    //{
    //    painter.drawText(0, y, seg);
    //    y += fontHeight;
    //}

    //QString lineContent;
    int totalw = 0;
    for (QChar ch : txt)
    {
        int cw = fontMetrics.horizontalAdvance(ch);
        if (totalw + cw < lineWidth) {
            painter.drawText(totalw + m_leftMargin, y + m_topMargin, cw, fontHeight, 0, ch);
        }
        else {
            totalw = 0;
            y += fontHeight;
            painter.drawText(totalw + m_leftMargin, y + m_topMargin, cw, fontHeight, 0, ch);
        }
        totalw += cw;
    }
}