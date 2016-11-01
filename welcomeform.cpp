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
    if (m_quentityRegister == 0)
    {
        ++m_quentityRegister;

        m_oneUser.m_name    = ui->lineEdit->text();
        if (ui->radioButton->isChecked())
        {
            m_oneUser.m_symbol = 'X';
            ui->radioButton->setEnabled(false);
            ui->radioButton_2->setChecked(true);
            ui->radioButton_2->setEnabled(false);
            ui->lineEdit->clear();
        }
        else
        {
            m_oneUser.m_symbol = '0';
            ui->radioButton_2->setEnabled(false);
            ui->radioButton->setChecked(true);
            ui->radioButton->setEnabled(false);
            ui->lineEdit->clear();
        }
    }
    else
    {
        m_secondUser.m_name = ui->lineEdit->text();
        if (ui->radioButton->isChecked())
        {
            m_secondUser.m_symbol = 'X';
        }
        else
        {
            m_secondUser.m_symbol = '0';
        }

        emit CompleteRegistration();
    }
}
