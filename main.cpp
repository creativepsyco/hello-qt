/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor
**     the names of its contributors may be used to endorse or promote
**     products derived from this software without specific prior written
**     permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
** $QT_END_LICENSE$
**
****************************************************************************/

#include <qapplication.h>
#include <qlabel.h>
#include <qslider.h>
#include <qpushbutton.h>
#include <qlcdnumber.h>
#include <qmenubar.h>
#include <qmenu.h>
#include <qmessagebox.h>

int main(int argc, char* argv[])
{
    // XXX: Need to be fixed

    QApplication myapp(argc, argv);
    QWidget* mywidget = new QWidget;
    mywidget->setGeometry(400, 400,200,200);

    QLabel* myLabel = new QLabel("Hello World", mywidget);
    myLabel->setGeometry(10,10,80,30);

    QPushButton* quitButton = new QPushButton("Quit", mywidget);
    quitButton->setGeometry(10,50,100,30);

    QPushButton* quitButton2= new QPushButton("Click Me", mywidget);
    quitButton2->setGeometry(100,50,100,30);

    QObject::connect(quitButton, SIGNAL(clicked()), &myapp, SLOT(quit()));

    QSlider* myslider = new QSlider(Qt::Horizontal, mywidget);
    myslider->setTickInterval(1);
    myslider->setMinimum(0);
    myslider->setMaximum(9);
    myslider->setGeometry(10, 100, 100, 30);
    myslider->setTickPosition(QSlider::TicksBelow);

    // optional

    QLCDNumber* mylcdnumber = new QLCDNumber(1, mywidget);
    mylcdnumber->setGeometry(10, 150, 100, 30);
    mylcdnumber->display(1);

    QObject::connect(myslider, SIGNAL(sliderMoved(int)),
                     mylcdnumber, SLOT(display(int))); // Connecting signals into slots

    // Menu
    QMenuBar* qmenubar = new QMenuBar(mywidget);
    QMenu* filemenu = new QMenu("&FIle", qmenubar);
    QMenu* helpmenu = new QMenu("Help", filemenu);
    filemenu->addAction("N&ew...");
    filemenu->addMenu(helpmenu);
    qmenubar->addMenu(filemenu);

    mywidget->show();
    return myapp.exec();
}
