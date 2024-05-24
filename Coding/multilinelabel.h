#ifndef __MULTILINE_LABEL_H__
#define __MULTILINE_LABEL_H__

#include <QtWidgets>

class MultilineLabel : public QLabel
{
    Q_OBJECT
public:
    MultilineLabel(const QString& text, qreal fixedWidth, QWidget* parent = nullptr);
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;

protected:
    void paintEvent(QPaintEvent*) override;

private:
    qreal m_fixedWidth = 0.;
    int m_lines = 0;
    int m_leftMargin = 0, m_rightMargin = 0, m_topMargin = 0, m_bottomMargin = 0;
    QStringList m_segments;
};

#endif