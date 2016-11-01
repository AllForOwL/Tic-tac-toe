#ifndef WELCOMEFORM_H
#define WELCOMEFORM_H

#include <QWidget>

namespace Ui {
class WelcomeForm;
}

class WelcomeForm : public QWidget
{
    Q_OBJECT

public:
    explicit WelcomeForm(QWidget *parent = 0);
    ~WelcomeForm();

    struct User
    {
        QString m_name;
        char    m_symbol;
    };


signals:
    void CompleteRegistration();

private slots:
    void on_pushButton_clicked();

public:
    Ui::WelcomeForm *ui;
    User m_oneUser;
    User m_secondUser;
    int  m_quentityRegister;
};

#endif // WELCOMEFORM_H
