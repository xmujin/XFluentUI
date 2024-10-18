#ifndef XNAVIGATIONVIEWITEM_H
#define XNAVIGATIONVIEWITEM_H

#include <QToolButton>
class XNavigationViewItemPrivate;



class XNavigationViewItem : public QAbstractButton
{
    Q_OBJECT

    Q_PROPERTY(bool hover READ isHover WRITE setHover)

public:
    explicit XNavigationViewItem(QWidget *parent = nullptr);
    explicit XNavigationViewItem(const QString &text, QWidget *parent = nullptr);
    // ~XNavigationViewItem();
    bool isHover() { return hover; };

private:
    bool hover;
    void setHover(bool hover) { this->hover = hover; };


protected:
    bool event(QEvent *e) override;
    //void mousePressEvent(QMouseEvent *) override;
    // void mouseReleaseEvent(QMouseEvent *) override;
    void paintEvent(QPaintEvent *) override;
    // void actionEvent(QActionEvent *) override;

    // void enterEvent(QEnterEvent *) override;
    // void leaveEvent(QEvent *) override;
    // void timerEvent(QTimerEvent *) override;
    // void changeEvent(QEvent *) override;

    // bool hitButton(const QPoint &pos) const override;
    // void checkStateSet() override;
    // void nextCheckState() override;
    //virtual void initStyleOption(QStyleOptionToolButton *option) const;

private:
    Q_DISABLE_COPY(XNavigationViewItem)
    Q_DECLARE_PRIVATE(XNavigationViewItem)


};

#endif // XNAVIGATIONVIEWITEM_H
