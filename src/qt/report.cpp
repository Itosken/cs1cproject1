#include "report.h"
#include "ui_report.h"
#include <QMessageBox>
/*!
 * \file report.cpp
 * \brief Source file for report class methods
 *
 * This file contains all of the definitions for the report class
 */
Report::Report(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Report)
{
    ui->setupUi(this);
    date.SetDate(1, 1, 1900);
}

Report::~Report()
{
    delete ui;
}

void Report::on_buttonBox_accepted()
{
    Date date1;
    QString monthTemp = ui->MonthEdit->text();
    QString dayTemp = ui->DayEdit->text();
    QString yearTemp = ui->YearEdit->text();
    if(monthTemp.isEmpty() || dayTemp.isEmpty() || yearTemp.isEmpty())
    {
        QMessageBox::information(this, tr("Invalid input"),
                   "Please verify input before submitting");
    }
    else
    {
        int month = monthTemp.toInt();
        int day = dayTemp.toInt();
        int year = yearTemp.toInt();
        date1.SetDate(month, day, year);
        date = date1;
    }

}

Date Report::getDate(){
    return this->date;
}

void Report::on_buttonBox_rejected()
{
    this->close();
}

void Report::on_checkBox_clicked()
{
    cheq = true;
}

bool Report::getCheq(){
    return this->cheq;
}
