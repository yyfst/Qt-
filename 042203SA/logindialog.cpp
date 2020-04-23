#include "logindialog.h"
#include <QWidget>
#include <QStringList>
#include <QPalette>
#include <QPoint>

LoginDialog::LoginDialog(QWidget *parent)
{
    m_bPressed= false;
    m_login=false;

    //设置页面最大 最小
    this->setMinimumSize(1200,800);
    //this->setMaximumSize(1200,800);

    usrLabel=new QLabel(this);
    //usrLabel->move(70,80);
    usrLabel->setText("用户名：");

    usrLineEdit=new QLineEdit(this);
    //usrLineEdit->move(140,80);
    //地址占位符
    usrLineEdit->setPlaceholderText("请输入用户名");

    pwdLabel=new QLabel(this);
    //pwdLabel->move(70,130);
    pwdLabel->setText("密码：");
    pwdLineEdit=new QLineEdit(this);
    //pwdLineEdit->move(140,130);
    pwdLineEdit->setPlaceholderText("请输入密码");
    //密码隐藏
    pwdLineEdit->setEchoMode(QLineEdit::Password);
    //限制输入长度
    usrLineEdit->setMaxLength(16);
    pwdLineEdit->setMaxLength(16);

    usrLineEdit->setFixedWidth(400);//设置固定长度
    pwdLineEdit->setFixedWidth(400);




    loginBtn=new QPushButton(this);
    loginBtn->setText("登录");

    exitBtn=new QPushButton(this);
    exitBtn->setText("退出");


    //实例网格布局空间
    gridlayout=new QGridLayout;
    //添加布局 0，0, 1， 1：行 列 行间距 列间距，水平居中
    gridlayout->addWidget(usrLabel,0,0,1,1,Qt::AlignRight);
    gridlayout->addWidget(usrLineEdit,0,1,1,1,Qt::AlignLeft);


    //间隔
    //gridlayout->setSpacing(1000);//这一行 不起作用
    gridlayout->addWidget(pwdLabel,1,0,1,1,Qt::AlignRight);
    gridlayout->addWidget(pwdLineEdit,1,1,1,1,Qt::AlignLeft);

    loginBtn->setFixedWidth(200);
    exitBtn->setFixedWidth(200);

    //gridlayout->addWidget(loginBtn,2,0,1,1,Qt::AlignLeft);
    //gridlayout->addWidget(exitBtn,2,1,1,1,Qt::AlignRight);


    gridlayout->setHorizontalSpacing(30);
    gridlayout->setVerticalSpacing(50);
    gridlayout->setContentsMargins(300, 100, 300, 0);//gridlayout的左、上、右、下与边框之间的距离

    //设置行高
    //gridlayout->setRowMinimumHeight(1,600);//第一行最小高度
    //gridlayout->setRowMinimumHeight(2,600);//第二行最小高度



    QHBoxLayout *hboxLayout=new QHBoxLayout;
    //hboxLayout->setSpacing(80);

    //横向布局填充控件

    //hboxLayout->addStretch(1);
    hboxLayout->addWidget(loginBtn,Qt::AlignRight);
    //hboxLayout->addStretch(1);
    hboxLayout->addWidget(exitBtn,Qt::AlignLeft);
    //hboxLayout->addStretch(1);
    //hboxLayout->setContentsMargins(300,0,300,100);

    vboxLayout=new QVBoxLayout;
    vboxLayout->addLayout(gridlayout);
    vboxLayout->addLayout(hboxLayout);



    QStringList list;
    list.append("color:white");                         // 前景色
    list.append("background-color:rgb(85,170,255)");    // 背景色
    list.append("border-style:outset");                 // 边框风格
    //list.append("border-width:5px");                    // 边框宽度
    //list.append("border-color:rgb(10,45,110)");         // 边框颜色
    list.append("border-radius:20px");                  // 边框倒角
    list.append("border:none");
    list.append("font:bold 34px");                      // 字体
    list.append("padding:8px");                         // 内边距
    loginBtn->setStyleSheet(list.join(';'));
    exitBtn->setStyleSheet(list.join(';'));

    // 按钮按下时修改样式
    list.replace(1, "background-color:rgb(255,0,0)");
    connect(loginBtn, &QPushButton::pressed, [=](){
        loginBtn->setStyleSheet(list.join(';'));
    });

    // 按钮弹起时恢复样式
    list.replace(1, "background-color:rgb(85,170,255)");
    connect(loginBtn, &QPushButton::released, [=](){
        loginBtn->setStyleSheet(list.join(';'));
    });

    // 按钮按下时修改样式
    list.replace(1, "background-color:rgb(255,0,0)");
    connect(exitBtn, &QPushButton::pressed, [=](){
        exitBtn->setStyleSheet(list.join(';'));
    });

    // 按钮弹起时恢复样式
    list.replace(1, "background-color:rgb(85,170,255)");
    connect(exitBtn, &QPushButton::released, [=](){
        exitBtn->setStyleSheet(list.join(';'));
    });

    connect(exitBtn, &QPushButton::released, this,&LoginDialog::close);

//    QPalette palette(this->palette());
//    palette.setColor(QPalette::Background,Qt::blue);
//    this->setPalette(palette);

    //this->setStyleSheet("background-color:rgb(85,170,255)");


    this->setLayout(vboxLayout);
    //this->setWindowTitle(" ");
    //this->setWindowFlags(Qt::FramelessWindowHint | windowFlags());      //设置为无边框窗口


    QString userName;
    QString password;
    userName =usrLineEdit->text();
    password=pwdLineEdit->text();

    QString a="admin";
    QString b="123456";


    //if(userName==a && password==b)//有问题
    {
        connect(loginBtn,&QPushButton::clicked,this,&LoginDialog::okLogin);
        connect(loginBtn,&QPushButton::clicked,this,&LoginDialog::close);
    }



}

LoginDialog::~LoginDialog()
{

}

void LoginDialog::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    m_bPressed=false;
}

void LoginDialog::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        m_bPressed=true;
        m_point=event->pos();
    }
}

void LoginDialog::mouseMoveEvent(QMouseEvent *event)
{
    if(m_bPressed)
        move(event->pos()-m_point+pos());
}

void LoginDialog::okBtnclicked()
{

}

void LoginDialog::okLogin()
{
    m_login=true;
}
