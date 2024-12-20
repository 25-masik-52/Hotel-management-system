#include "hmsconfigurator.h"
#include "hmsserver.h"
#include "hmsdatabase.h"
#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    HmsConfigurator configurator;
    
    HmsDatabase database{ configurator.getDatabaseName(), configurator.getDatabaseSQLQueries() };
    
    HmsServer server{ configurator.getServerPort(), database };
    
    return a.exec();
}
