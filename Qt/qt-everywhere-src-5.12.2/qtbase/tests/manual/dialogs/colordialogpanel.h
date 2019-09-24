/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
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

#ifndef COLORDIALOGPANEL_H
#define COLORDIALOGPANEL_H

#include <QPointer>
#include <QColorDialog>

QT_BEGIN_NAMESPACE
class QComboBox;
class QCheckBox;
class QPushButton;
QT_END_NAMESPACE

class ColorDialogPanel : public QWidget
{
    Q_OBJECT
public:
    explicit ColorDialogPanel(QWidget *parent = 0);

public slots:
    void execModal();
    void showModal();
    void showNonModal();
    void deleteNonModalDialog();
    void deleteModalDialog();
    void accepted();
    void rejected();
    void currentColorChanged(const QColor & color);
    void showAcceptedResult();
    void restoreDefaults();

private slots:
    void enableDeleteNonModalDialogButton();
    void enableDeleteModalDialogButton();

private:
    void applySettings(QColorDialog *d) const;

    QComboBox *m_colorComboBox;
    QCheckBox *m_showAlphaChannel;
    QCheckBox *m_noButtons;
    QCheckBox *m_dontUseNativeDialog;
    QPushButton *m_deleteNonModalDialogButton;
    QPushButton *m_deleteModalDialogButton;
    QString m_result;
    QPointer<QColorDialog> m_modalDialog;
    QPointer<QColorDialog> m_nonModalDialog;
};

#endif // COLORDIALOGPANEL_H
