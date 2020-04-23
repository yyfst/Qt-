#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H
#include <QDialog>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QMouseEvent>
#include <QPoint>

class LoginDialog : public QDialog
{
    Q_OBJECT    //使用信号和槽等特性必须添加的宏
public:
    explicit LoginDialog(QWidget *parent=0);
    ~LoginDialog();

     bool m_login;

private:
    //声明三个鼠标事件函数
    void mouseReleaseEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);



private:
    QLabel *usrLabel;   //用户名提示标签
    QLabel *pwdLabel;   //密码提示标签

    QLineEdit *usrLineEdit;//输入用户名文本框
    QLineEdit *pwdLineEdit;//输入密码文本框

    QPushButton *loginBtn;//登录确认按钮
    QPushButton *exitBtn;//退出按钮

    QGridLayout *gridlayout;
    QVBoxLayout *vboxLayout;

    bool m_bPressed;
    QPoint m_point;




private slots:
    //自定义私有槽函数
    void okBtnclicked();
    void okLogin();



};

#endif // LOGINDIALOG_H
