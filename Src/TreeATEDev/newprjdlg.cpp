///
/// @project       TreeATE
/// @brief         New project dialog
/// @author        David Yin  2018-12 willage.yin@163.com
///
/// @license       GNU LGPL
///
/// Distributed under the GNU LGPL License
/// (See accompanying file LICENSE or copy at
/// http://www.gnu.org/licenses/lgpl.html)
///

#include "newprjdlg.h"
#include "ui_newprjdlg.h"

#include <QFileDialog>

NewPrjDlg::NewPrjDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewPrjDlg)
{
    ui->setupUi(this);
    ui->lineEdit_workpath->setText(qApp->applicationDirPath());
}

NewPrjDlg::~NewPrjDlg()
{
    delete ui;
}

void NewPrjDlg::on_pushButton_clicked()
{
    QString workPath = QFileDialog::getExistingDirectory(this, tr("Select path"),
                                                         ui->lineEdit_workpath->text());
    if(workPath.isEmpty())
        return;
    ui->lineEdit_workpath->setText(workPath);
}

QStringList NewPrjDlg::GetNewProjectFiles()
{
    QString strName = ui->lineEdit_name->text();
    QString strPath = ui->lineEdit_workpath->text();
    QString strNewName = strName.trimmed();
    QStringList lstFile;
    if(!strNewName.isEmpty()) {
        strName = strPath.trimmed() + "/" + strNewName + "/" + strNewName;
        lstFile << strName + ".tp"
                << strName + ".tpx"
                << strName + ".tsx";
    }
    return lstFile;
}