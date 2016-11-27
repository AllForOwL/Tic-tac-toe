#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

const char CNT_SYMBOL_ZERO    = '0';
const char CNT_SYMBOL_DAGGER  = 'X';

const int CNT_ROWS = 3;
const int CNT_COLS = 3;

const int CNT_QUENTITY_COURSES = 9;

const int CNT_QUENTITY_MATHES = 3;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_welcomeForm = new WelcomeForm();
    m_welcomeForm->show();

    m_quentityCourses = 1;
    m_playerOne     = true;
    m_playerSecond  = false;

    m_Field.resize(CNT_ROWS);       // задається кількість рядків
    for (int i = 0; i < CNT_ROWS; i++)
    {
        m_Field[i].resize(CNT_COLS);    // задається кількість стовпців
    }

    connect(m_welcomeForm, SIGNAL(CompleteRegistration()), this, SLOT(GetUserDate()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::GetUserDate()
{
    m_userOne       = m_welcomeForm->m_oneUser;     // копіюємо дані першого користувача з першої форми
    m_userSecond    = m_welcomeForm->m_secondUser;  // копіюємо дані другого користувача з першої форми

    m_symbolPlayerOne       = m_userOne.m_symbol;
    m_symbolPlayerSecond    = m_userSecond.m_symbol;

    m_welcomeForm->close(); // закриття першої форми
    this->show();
}

char MainWindow::ExecuteMove(QPushButton &i_button)
{
    if (m_playerOne)    // якщо активний перший користувач
    {
        ui->NamePlayer->setText(m_userOne.m_name);      // виводить ім'я користувача
        i_button.setText(QString(m_userOne.m_symbol));  // кнопці присвоюється символ активного користувача
        i_button.setEnabled(false);                     // блокуємо натиснуту кнопку
        m_playerOne     = false;                        // змінюємо активного користувача
        m_playerSecond  = true;
        return m_symbolPlayerOne;                       // повертаємо символ активного користувача
    }
    else
    {
        ui->NamePlayer->setText(m_userSecond.m_name);
        i_button.setText(QString(m_userSecond.m_symbol));
        i_button.setEnabled(false);
        m_playerSecond  = false;
        m_playerOne     = true;
        return m_symbolPlayerSecond;
    }
}

bool MainWindow::VerifyWinner(int i_rows, int i_cols, char i_symbol)
{
    m_Field[i_rows][i_cols] = i_symbol;

    int _quentityMathes = 0;
    for (int i = 0; i < CNT_ROWS; i++)  // перевірка переможних стовпчиків
    {
        for (int j = 0; j < CNT_COLS; j++)
        {
            if (m_Field[i][j] == i_symbol)
            {
                ++_quentityMathes;      // містить кількість одинакових символів в рядку
            }
        }
        if (_quentityMathes == CNT_QUENTITY_MATHES)
        {
            return true;
        }
        _quentityMathes = 0;
    }

    _quentityMathes = 0;
    for (int i = 0; i < CNT_COLS; i++)  // перевірка переможних рядків
    {
        for (int j = 0; j < CNT_ROWS; j++)
        {
            if (m_Field[j][i] == i_symbol)
            {
                ++_quentityMathes;  // містить кількість одинакових символів в стовпчику
            }
        }
        if (_quentityMathes == CNT_QUENTITY_MATHES)
        {
            return true;
        }
        _quentityMathes = 0;
    }

    if (_quentityMathes == CNT_QUENTITY_MATHES)
    {
        return true;
    }

    _quentityMathes = 0;
    for (int i = 0; i < CNT_ROWS; i++)  // перевірка переможної діагоналі зліва направо
    {
        if (m_Field[i][i] == i_symbol)
        {
            ++_quentityMathes;
        }
    }
    if (_quentityMathes == CNT_QUENTITY_MATHES)
    {
        return true;
    }

    _quentityMathes = 0;
    for (int i = CNT_ROWS - 1; i >= 0; i--) // перевірка переможної діагоналі справа наліво
    {
        if (m_Field[i][i] == i_symbol)
        {
            ++_quentityMathes;
        }
    }
    if (_quentityMathes == CNT_QUENTITY_MATHES)
    {
        return true;
    }

    if (m_quentityCourses++ == CNT_QUENTITY_COURSES)
    {
        QMessageBox::information(this, "Інформація", "Нічия");
    }

    return false;
}

void MainWindow::on_btn_1_clicked()
{
    char _symbolPlayer = ExecuteMove(*ui->btn_1);
    if (VerifyWinner(0, 0, _symbolPlayer))          // якщо є переможець
    {
        if (_symbolPlayer == m_userOne.m_symbol)    // якщо переможець перший користувач
        {
            QMessageBox::information(this, "Перемога", "Переможець :" + m_userOne.m_name);  // вивести привітання
        }
        else                                        // якщо переможець другий користувач
        {
            QMessageBox::information(this, "Перемога", "Переможець :" + m_userSecond.m_name);
        }
    }
}

void MainWindow::on_btn_2_clicked()
{
    char _symbolPlayer = ExecuteMove(*ui->btn_2);
    if (VerifyWinner(0, 1, _symbolPlayer))
    {
        if (_symbolPlayer == m_userOne.m_symbol)
        {
            QMessageBox::information(this, "Winner", "Winner :" + m_userOne.m_name);
        }
        else
        {
            QMessageBox::information(this, "Winner", "Winner :" + m_userSecond.m_name);
        }
    }
}

void MainWindow::on_btn_3_clicked()
{
    char _symbolPlayer = ExecuteMove(*ui->btn_3);
    if (VerifyWinner(0, 2, _symbolPlayer))
    {
        if (_symbolPlayer == m_userOne.m_symbol)
        {
            QMessageBox::information(this, "Winner", "Winner :" + m_userOne.m_name);
        }
        else
        {
            QMessageBox::information(this, "Winner", "Winner :" + m_userSecond.m_name);
        }    }
}

void MainWindow::on_btn_4_clicked()
{
    char _symbolPlayer = ExecuteMove(*ui->btn_4);
    if (VerifyWinner(1, 0, _symbolPlayer))
    {
        if (_symbolPlayer == m_userOne.m_symbol)
        {
            QMessageBox::information(this, "Winner", "Winner :" + m_userOne.m_name);
        }
        else
        {
            QMessageBox::information(this, "Winner", "Winner :" + m_userSecond.m_name);
        }    }
}

void MainWindow::on_btn_5_clicked()
{
    char _symbolPlayer = ExecuteMove(*ui->btn_5);
    if (VerifyWinner(1, 1, _symbolPlayer))
    {
        if (_symbolPlayer == m_userOne.m_symbol)
        {
            QMessageBox::information(this, "Winner", "Winner :" + m_userOne.m_name);
        }
        else
        {
            QMessageBox::information(this, "Winner", "Winner :" + m_userSecond.m_name);
        }   }
}

void MainWindow::on_btn_6_clicked()
{
    char _symbolPlayer = ExecuteMove(*ui->btn_6);
    if (VerifyWinner(1, 2, _symbolPlayer))
    {
        if (_symbolPlayer == m_userOne.m_symbol)
        {
            QMessageBox::information(this, "Winner", "Winner :" + m_userOne.m_name);
        }
        else
        {
            QMessageBox::information(this, "Winner", "Winner :" + m_userSecond.m_name);
        }
    }
}

void MainWindow::on_btn_7_clicked()
{
    char _symbolPlayer = ExecuteMove(*ui->btn_7);
    if (VerifyWinner(2, 0, _symbolPlayer))
    {
        if (_symbolPlayer == m_userOne.m_symbol)
        {
            QMessageBox::information(this, "Winner", "Winner :" + m_userOne.m_name);
        }
        else
        {
            QMessageBox::information(this, "Winner", "Winner :" + m_userSecond.m_name);
        }
    }
}

void MainWindow::on_btn_8_clicked()
{
    char _symbolPlayer = ExecuteMove(*ui->btn_8);
    if (VerifyWinner(2, 1, _symbolPlayer))
    {
        if (_symbolPlayer == m_userOne.m_symbol)
        {
            QMessageBox::information(this, "Winner", "Winner :" + m_userOne.m_name);
        }
        else
        {
            QMessageBox::information(this, "Winner", "Winner :" + m_userSecond.m_name);
        }
    }
}

void MainWindow::on_btn_9_clicked()
{
    char _symbolPlayer = ExecuteMove(*ui->btn_9);
    if (VerifyWinner(2, 2, _symbolPlayer))
    {
        if (_symbolPlayer == m_userOne.m_symbol)
        {
            QMessageBox::information(this, "Winner", "Winner :" + m_userOne.m_name);
        }
        else
        {
            QMessageBox::information(this, "Winner", "Winner :" + m_userSecond.m_name);
        }
    }
}

void MainWindow::on_pushButton_clicked()
{
    ui->btn_1->setEnabled(true);
    ui->btn_1->setText("");
    ui->btn_2->setEnabled(true);
    ui->btn_2->setText("");
    ui->btn_3->setEnabled(true);
    ui->btn_3->setText("");
    ui->btn_4->setEnabled(true);
    ui->btn_4->setText("");
    ui->btn_5->setEnabled(true);
    ui->btn_5->setText("");
    ui->btn_6->setEnabled(true);
    ui->btn_6->setText("");
    ui->btn_7->setEnabled(true);
    ui->btn_7->setText("");
    ui->btn_8->setEnabled(true);
    ui->btn_8->setText("");
    ui->btn_9->setEnabled(true);
    ui->btn_9->setText("");

    m_quentityCourses = 1;
    m_playerOne     = true;
    m_playerSecond  = false;
}
