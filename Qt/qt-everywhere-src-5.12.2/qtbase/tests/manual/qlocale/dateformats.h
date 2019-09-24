/****************************************************************************
**
** Copyright (C) 2017 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the test suite of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:GPL-EXCEPT$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 as published by the Free Software
** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef DATEFORMATS_H
#define DATEFORMATS_H

#include <QWidget>
#include <QLocale>

class QLineEdit;
class QScrollArea;
class QGridLayout;
class QComboBox;

class DateFormatsWidget : public QWidget
{
    Q_OBJECT
public:
    DateFormatsWidget();

private:
    void addItem(const QString &label, QWidget *);
    QLineEdit *addItem(const QString &label);

    QScrollArea *scrollArea;
    QWidget *scrollAreaWidget;
    QGridLayout *layout;

    QLineEdit *shortDateFormat;
    QLineEdit *longDateFormat;
    QLineEdit *shortTimeFormat;
    QLineEdit *longTimeFormat;
    QLineEdit *shortDateTimeFormat;
    QLineEdit *longDateTimeFormat;
    QLineEdit *amText;
    QLineEdit *pmText;
    QLineEdit *firstDayOfWeek;
    QComboBox *monthNamesShort, *monthNamesLong;
    QComboBox *standaloneMonthNamesShort, *standaloneMonthNamesLong;
    QComboBox *dayNamesShort, *dayNamesLong;
    QComboBox *standaloneDayNamesShort, *standaloneDayNamesLong;

private slots:
    void localeChanged(QLocale locale);
};

#endif
