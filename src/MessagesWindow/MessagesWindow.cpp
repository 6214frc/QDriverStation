/*
 * Copyright (c) 2015 WinT 3794 <http://wint3794.org>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

//=============================================================================
// System includes
//=============================================================================

#include <QTabWidget>
#include <QVBoxLayout>

//=============================================================================
// Application includes
//=============================================================================

#include "ConsoleWidget.h"
#include "MessagesWindow.h"
#include "Utilities/Global.h"

//=============================================================================
// MessagesWindow::MessagesWindow
//=============================================================================

MessagesWindow::MessagesWindow()
{
    m_tabWidget     = new QTabWidget    (this);
    m_consoleWidget = new ConsoleWidget (this);
    m_layout        = new QVBoxLayout   (this);

    m_consoleWidget->layout()->setContentsMargins (MAIN_MARGINS());
    m_tabWidget->addTab          (m_consoleWidget, tr ("Messages"));
    m_layout->setContentsMargins (MAIN_MARGINS());
    m_layout->addWidget          (m_tabWidget);

    setMinimumSize (minimumSizeHint().width()  * 2.0,
                    minimumSizeHint().height() * 2.0);
}

//=============================================================================
// MessagesWindow::~MessagesWindow
//=============================================================================

MessagesWindow::~MessagesWindow()
{
    delete m_layout;
    delete m_tabWidget;
    delete m_consoleWidget;
}
