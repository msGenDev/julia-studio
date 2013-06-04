/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of Qt Creator.
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
****************************************************************************/

#ifndef DIFFEDITOREDITABLE_H
#define DIFFEDITOREDITABLE_H

#include "diffeditor_global.h"
#include "diffeditorwidget.h"

#include <coreplugin/editormanager/ieditor.h>
#include <coreplugin/idocument.h>

QT_BEGIN_NAMESPACE
class QToolBar;
class QComboBox;
QT_END_NAMESPACE

namespace DiffEditor {

namespace Internal {
class DiffEditorFile;
}

class DIFFEDITOR_EXPORT DiffEditor : public Core::IEditor
{
    Q_OBJECT
public:
    explicit DiffEditor(DiffEditorWidget *editorWidget);
    virtual ~DiffEditor();

public:
    void setDiff(const QList<DiffEditorWidget::DiffFilesContents> &diffFileList,
                 const QString &workingDirectory = QString());
    void clear(const QString &message);

    // Core::IEditor
    bool createNew(const QString &contents);
    bool open(QString *errorString, const QString &fileName, const QString &realFileName);
    Core::IDocument *document();
    QString displayName() const;
    void setDisplayName(const QString &title);
    Core::Id id() const;
    bool isTemporary() const { return true; }
    DiffEditorWidget *editorWidget() const { return m_editorWidget; }

    QWidget *toolBar();

public slots:
    void activateEntry(int index);

private slots:
    void entryActivated(int index);

private:
    void updateEntryToolTip();

    Internal::DiffEditorFile *m_file;
    DiffEditorWidget *m_editorWidget;
    QToolBar *m_toolWidget;
    QComboBox *m_entriesComboBox;
    mutable QString m_displayName;
};

} // namespace DiffEditor

#endif // DIFFEDITOREDITABLE_H