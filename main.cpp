#include <KAboutData>
#include <KApplication>
#include <KCmdLineArgs>

#include "KminiDLNA.h"

int main(int argc, char** argv)
{    
  
    Q_INIT_RESOURCE(resource);
    KAboutData aboutData("KminiDLNA",
			  0,
			 ki18n("KminiDLNA"),
			 "0.1",
			 ki18n("Frotnend for minidlna"),
			 KAboutData::License_GPL_V2);
    
    aboutData.addAuthor(ki18n("Saljack"));
    KCmdLineArgs::init(argc, argv, &aboutData);
    KApplication app;
    KminiDLNA *mainWindow = new KminiDLNA();
    mainWindow->setWindowIcon(QIcon(":/images/ikona.png"));
    mainWindow->show();
    return app.exec();
}
