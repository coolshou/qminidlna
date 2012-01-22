/*
    <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) 2012  TomÃ¡Å¡ PolednÃ½ <email>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#ifndef RESTMINIDLNA_H
#define RESTMINIDLNA_H

#include "restresource.h"
#include "../../core/minidlna_process.h"
#include <QProcess>

class RESTMiniDLNA : public RESTresource
{
Q_OBJECT
public:
    RESTMiniDLNA(QObject* process = 0, QString address = "/minidlna-state.xml");
    virtual ~RESTMiniDLNA();
    virtual QDomDocument* resource();
    virtual bool setResource(QDomDocument* resource);
    virtual bool isValidResource(QDomDocument* resource);
    
private:
  QDomText m_stateText;
private slots:
  void onMiniDLNAState(QProcess::ProcessState state);
    
};

#endif // RESTMINIDLNA_H