/********************************************************************************
** Form generated from reading UI file 'ChartForm.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARTFORM_H
#define UI_CHARTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChartForm
{
public:

    void setupUi(QWidget *ChartForm)
    {
        if (ChartForm->objectName().isEmpty())
            ChartForm->setObjectName(QStringLiteral("ChartForm"));
        ChartForm->resize(400, 300);

        retranslateUi(ChartForm);

        QMetaObject::connectSlotsByName(ChartForm);
    } // setupUi

    void retranslateUi(QWidget *ChartForm)
    {
        ChartForm->setWindowTitle(QApplication::translate("ChartForm", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChartForm: public Ui_ChartForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARTFORM_H
