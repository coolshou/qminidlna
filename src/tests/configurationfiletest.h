#include "../core/configurationfile.h"
#include <QObject>

class ConfigurationFileTest: public QObject {
    Q_OBJECT
private:
    ConfigurationFile* m_confFile;
private slots:
    void initTestCase(); // will be called before the first testfunction is executed.
    void cleanupTestCase(); // will be called after the last testfunction was executed.
    void init(); // will be called before each testfunction is executed.
    void cleanup(); // will be called after every testfunction.
    void createFileTest();
};
