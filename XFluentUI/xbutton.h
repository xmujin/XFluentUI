#ifndef XBUTTON_H
#define XBUTTON_H

#include <QWidget>
#include <QPushButton>



class XButtonPrivate;
class QMenu;
class QStyleOptionButton;

class XButton : public QPushButton
{
    Q_OBJECT

    //Q_D_CREATE(XButton)
    // Q_PROPERTY(type name READ getter WRITE setter)
    Q_PROPERTY(bool autoDefault READ autoDefault WRITE setAutoDefault)
    Q_PROPERTY(bool default READ isDefault WRITE setDefault)
    Q_PROPERTY(bool flat READ isFlat WRITE setFlat)



public:

    explicit XButton(QWidget *parent = nullptr);
    //explicit XButton(const QString &text, QWidget *parent = nullptr);


    //XButton(const QIcon& icon, const QString &text, QWidget *parent = nullptr);
    //~XButton();


protected:
    //bool event(QEvent *e) override;
    void paintEvent(QPaintEvent *) override;
    //void keyPressEvent(QKeyEvent *) override;
    //void focusInEvent(QFocusEvent *) override;
    //void focusOutEvent(QFocusEvent *) override;
    //void mouseMoveEvent(QMouseEvent *) override;
    //void initStyleOption(QStyleOptionButton *option) const override;
    //bool hitButton(const QPoint &pos) const override;
    //XButton(QPushButtonPrivate &dd, QWidget* parent = nullptr);

private:
    Q_DISABLE_COPY(XButton) // 禁用拷贝构造和拷贝赋值
    Q_DECLARE_PRIVATE(XButton) // XButtonPrivate设置为友元，提供了指向XButtonPrivate的指针

};

#endif // XBUTTON_H
