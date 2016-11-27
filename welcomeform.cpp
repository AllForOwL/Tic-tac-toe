#include "welcomeform.h"
#include "ui_welcomeform.h"

WelcomeForm::WelcomeForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WelcomeForm)
{
    ui->setupUi(this);

    m_quentityRegister = 0;
}

WelcomeForm::~WelcomeForm()
{
    delete ui;
}

void WelcomeForm::on_pushButton_clicked()
{
    if (m_quentityRegister == 0)    // якщо реєструвється перший користувач
    {
        ++m_quentityRegister;

        m_oneUser.m_name    = ui->lineEdit->text(); // зчитуємо ім'я користувача
        if (ui->radioButton->isChecked())   // якщо вибраний символ є Х
        {
            m_oneUser.m_symbol = 'X';              // задаємо для користувача символ Х
            ui->radioButton->setEnabled(false);    // блокуємо вибір Х
            ui->radioButton_2->setChecked(true);   // вибираємо 0 для другого
            ui->radioButton_2->setEnabled(false);  // блокуємо вибір 0
            ui->lineEdit->clear();                 // очищуємо поле для імені
        }
        else                                // аналогічно до вибору Х
        {
            m_oneUser.m_symbol = '0';
            ui->radioButton_2->setEnabled(false);
            ui->radioButton->setChecked(true);
            ui->radioButton->setEnabled(false);
            ui->lineEdit->clear();
        }
    }
    else                            // якщо реєструвється другий користувач
    {
        m_secondUser.m_name = ui->lineEdit->text(); // зчитуємо ім'я користувача
        if (ui->radioButton->isChecked())
        {
            m_secondUser.m_symbol = 'X';    // задаємо для користувача символ Х
        }
        else
        {
            m_secondUser.m_symbol = '0';    // задаємо для користувача символ 0
        }

        emit CompleteRegistration();    // сигнал для події відкрити другу форму
    }
}
