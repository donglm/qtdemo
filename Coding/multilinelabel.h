#ifndef __MULTILINE_LABEL_H__
#define __MULTILINE_LABEL_H__

#include <QObject>
#include <QWidget>

class MultilineLabel : public QWidget
{
    Q_OBJECT
public:
    MultilineLabel(const QString& text, qreal fixedWidth, QWidget* parent = nullptr);

protected:
    void paintEvent(QPaintEvent*) override;

private:
    qreal m_fixedWidth = 0.;
    QStringList m_segments;
};

#endif