#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

#include "welcomeform.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    char ExecuteMove(QPushButton& i_button);
    bool VerifyWinner(int i_rows, int i_cols, char i_symbol);

private slots:
    void GetUserDate();

    void on_btn_1_clicked();

    void on_btn_2_clicked();

    void on_btn_3_clicked();

    void on_btn_4_clicked();

    void on_btn_5_clicked();

    void on_btn_6_clicked();

    void on_btn_7_clicked();

    void on_btn_8_clicked();

    void on_btn_9_clicked();

private:
    Ui::MainWindow *ui;
    bool m_playerOne;
    bool m_playerSecond;
    char m_symbolPlayerOne;
    char m_symbolPlayerSecond;
    std::vector<std::vector<char>> m_Field;

    WelcomeForm::User m_userOne;
    WelcomeForm::User m_userSecond;

    WelcomeForm*    m_welcomeForm;

};

#endif // MAINWINDOW_H
