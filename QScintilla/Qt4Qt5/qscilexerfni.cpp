// This module implements the QsciLexerProperties class.
//
// Copyright (c) 2012 Riverbank Computing Limited <info@riverbankcomputing.com>
// 
// This file is part of QScintilla.
// 
// This file may be used under the terms of the GNU General Public
// License versions 2.0 or 3.0 as published by the Free Software
// Foundation and appearing in the files LICENSE.GPL2 and LICENSE.GPL3
// included in the packaging of this file.  Alternatively you may (at
// your option) use any later version of the GNU General Public
// License if such license has been publicly approved by Riverbank
// Computing Limited (or its successors, if any) and the KDE Free Qt
// Foundation. In addition, as a special exception, Riverbank gives you
// certain additional rights. These rights are described in the Riverbank
// GPL Exception version 1.1, which can be found in the file
// GPL_EXCEPTION.txt in this package.
// 
// If you are unsure which license is appropriate for your use, please
// contact the sales department at sales@riverbankcomputing.com.
// 
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.


#include "QsciPS3/qscilexerfni.h"

#include <qcolor.h>
#include <qfont.h>
#include <qsettings.h>


// The ctor.
QsciLexerFni::QsciLexerFni(QObject *parent)
    : QsciLexer(parent)
{
}


// The dtor.
QsciLexerFni::~QsciLexerFni()
{
}


// Returns the language name.
const char *QsciLexerFni::language() const
{
    return "Fni";
}


// Returns the lexer name.
const char *QsciLexerFni::lexer() const
{
    return "fni";
}


// Return the string of characters that comprise a word.
const char *QsciLexerFni::wordCharacters() const
{
    return "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_";
}


// Returns the foreground colour of the text for a style.
QColor QsciLexerFni::defaultColor(int style) const
{
    switch (style)
    {
    case Default:
        return QColor(0x00,0x00,0x00);

    case Comment:
        return QColor(0x00,0x7f,0x00);

    case Group:
        return QColor(0x7f,0x00,0x7f);

    case Command:
        return QColor(0x00,0x00,0xff);

    case Operator:
        return QColor(0x00,0x00,0x00);
    }

    return QsciLexer::defaultColor(style);
}


// Returns the user name of a style.
QString QsciLexerFni::description(int style) const
{
    switch (style)
    {
    case Default:
        return tr("Default");

    case Comment:
        return tr("Comment");

    case Group:
        return tr("Command group");

    case Command:
        return tr("Console command");

    case Operator:
        return tr("Operator");
    }

    return QString();
}
