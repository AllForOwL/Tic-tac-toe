#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

const char CNT_SYMBOL_ZERO    = '0';
const char CNT_SYMBOL_DAGGER  = 'X';

const int CNT_ROWS = 3;
const int CNT_COLS = 3;

const int CNT_QUENTITY_MATHES = 3;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_symbolPlayerOne       = CNT_SYMBOL_DAGGER;
    m_symbolPlayerSecond    = CNT_SYMBOL_ZERO;

    m_playerOne     = true;
    m_playerSecond  = false;

    m_Field.resize(CNT_ROWS);

    for (int i = 0; i < CNT_ROWS; i++)
    {
        m_Field[i].resize(CNT_COLS);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

char MainWindow::ExecuteMove(QPushButton &i_button)
{
    if (m_playerOne)
    {
        i_button.setText(QString(m_symbolPlayerOne));
        m_playerOne     = false;
        m_playerSecond  = true;
        return m_symbolPlayerOne;
    }
    else
    {
        i_button.setText(QString(m_symbolPlayerSecond));
        m_playerSecond  = false;
        m_playerOne     = true;
        return m_symbolPlayerSecond;
    }
}

bool MainWindow::VerifyWinner(int i_rows, int i_cols, char i_symbol)
{
    m_Field[i_rows][i_cols] = i_symbol;

    int _quentityMathes = 0;
    for (int i = 0; i < CNT_ROWS; i++)
    {
        for (int j = 0; j < CNT_COLS; j++)
        {
            if (m_Field[i][j] == i_symbol)
            {
                ++_quentityMathes;
            }
        }
    }
    if (_quentityMathes == CNT_QUENTITY_MATHES)
    {
        return true;
    }

    _quentityMathes = 0;
    for (int i = 0; i < CNT_COLS; i++)
    {
        for (int j = 0; j < CNT_ROWS; j++)
        {
            if (m_Field[i][j] == i_symbol)
            {
                ++_quentityMathes;
            }
        }
    }
    if (_quentityMathes == CNT_QUENTITY_MATHES)
    {
        return true;
    }

    _quentityMathes = 0;
    for (int i = 0; i < CNT_ROWS; i++)
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
    for (int i = CNT_ROWS - 1; i > 0; i--)
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

    return false;
}

void MainWindow::on_btn_1_clicked()
{
    char _symbolPlayer = ExecuteMove(*ui->btn_1);
    if (VerifyWinner(0, 0, _symbolPlayer))
    {
        QMessageBox::information(this, "Winner", "Winner : owl");
    }
}

void MainWindow::on_btn_2_clicked()
{
    if (VerifyWinner(0, 1, ExecuteMove(*ui->btn_2)))
    {
        QMessageBox::information(this, "Winner", "Winner : owl");
    }
}

void MainWindow::on_btn_3_clicked()
{
    if (VerifyWinner(0, 2, ExecuteMove(*ui->btn_3)))
    {
        QMessageBox::information(this, "Winner", "Winner : owl");
    }
}

void MainWindow::on_btn_4_clicked()
{
    if (VerifyWinner(1, 0, ExecuteMove(*ui->btn_4)))
    {
        QMessageBox::information(this, "Winner", "Winner : owl");
    }
}

void MainWindow::on_btn_5_clicked()
{
    if (VerifyWinner(1, 1, ExecuteMove(*ui->btn_5)))
    {
        QMessageBox::information(this, "Winner", "Winner : owl");
    }
}

void MainWindow::on_btn_6_clicked()
{
    if (VerifyWinner(1, 2, ExecuteMove(*ui->btn_6)))
    {
        QMessageBox::information(this, "Winner", "Winner : owl");
    }
}

void MainWindow::on_btn_7_clicked()
{
    if (VerifyWinner(2, 0, ExecuteMove(*ui->btn_7)))
    {
        QMessageBox::information(this, "Winner", "Winner : owl");
    }
}

void MainWindow::on_btn_8_clicked()
{
    if (VerifyWinner(2, 1, ExecuteMove(*ui->btn_8)))
    {
        QMessageBox::information(this, "Winner", "Winner : owl");
    }
}

void MainWindow::on_btn_9_clicked()
{
    if (VerifyWinner(2, 2, ExecuteMove(*ui->btn_9)))
    {
        QMessageBox::information(this, "Winner", "Winner : owl");
    }
}
