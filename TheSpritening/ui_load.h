/********************************************************************************
** Form generated from reading UI file 'load.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOAD_H
#define UI_LOAD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_Load
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Load)
    {
        if (Load->objectName().isEmpty())
            Load->setObjectName(QStringLiteral("Load"));
        Load->resize(400, 300);
        buttonBox = new QDialogButtonBox(Load);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(Load);
        QObject::connect(buttonBox, SIGNAL(accepted()), Load, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Load, SLOT(reject()));

        QMetaObject::connectSlotsByName(Load);
    } // setupUi

    void retranslateUi(QDialog *Load)
    {
        Load->setWindowTitle(QApplication::translate("Load", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class Load: public Ui_Load {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOAD_H
