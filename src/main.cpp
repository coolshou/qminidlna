/*
qminidlna
http://github.com/coolshou/qminidlna

Copyright (C) 2018 jimmy

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
version 2 as published by the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#include <QApplication>
#include <QCommandLineParser>
#include <QSettings>
#include <QDebug>
#include "view/qminidlna.h"
#include "server/restserver.h"
/*
void loadCommandLine(int argc, char** argv, KAboutData* aboutData) {
    KCmdLineArgs::init(argc, argv, aboutData);

    KCmdLineOptions options;
    options.add("norestserver", ki18n("Run http server with REST interface (default is off)"));
    options.add("nogui", ki18n("Run without GUI (default is on)"));
    options.add("start-dlna", ki18n("Start MiniDLNA server (default is off)"));

    KCmdLineArgs::addCmdLineOptions(options);
}
*/
int main(int argc, char** argv)
{

    Q_INIT_RESOURCE(resource);
    //QString versionName = VERSION;
    QApplication app(argc, argv);;
    QApplication::setOrganizationName("coolshou");
    QApplication::setOrganizationDomain("coolshou.idv.tw");
    QApplication::setApplicationName("qminidlna");

    app.setWindowIcon(QIcon(":/images/qminidlna.png"));
    QCommandLineParser parser;
    parser.setApplicationDescription("qminidlna helper");
    parser.addHelpOption();
    parser.addVersionOption();
    parser.addPositionalArgument("norestserver", QCoreApplication::translate("main", "Run http server with REST interface (default is off)."));
    parser.addPositionalArgument("nogui", QCoreApplication::translate("main", "Run without GUI (default is on)."));
    parser.addPositionalArgument("start-dlna", QCoreApplication::translate("main", "Start MiniDLNA server (default is off)."));
    // Process the actual command line arguments given by the user
    parser.process(app);
    const QStringList args = parser.positionalArguments();

    QminiDLNA *mainWindow = 0;
    if (args.indexOf("gui")) {//isSet without --no!
        qDebug() << "Main: GUI start";
        mainWindow = new QminiDLNA();
        mainWindow->show();
    }

    
    if (args.indexOf("restserver")) {
        RESTServer *server = RESTServer::getInstance();
        QSettings config;// = QSettings();
        config.beginGroup("server");
        if (config.value("run_server_on_start",false).toBool()) {
            server->startServer();
            qDebug() << "Main: HTTP Server start on port " << server->port();
        }
        config.endGroup();
    }
    if (args.indexOf("start-dlna")) {
        MiniDLNAProcess* process = MiniDLNAProcess::getInstance();
        process->minidlnaStart();
    }
    //args->clear();

    return app.exec();
}

