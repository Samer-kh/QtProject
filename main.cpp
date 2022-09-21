#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include"grille.h"
#include "numbergrid.h"
#include <QQmlContext>
#include <cstdlib>
#include <ctime>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    NumberGrid grid=NumberGrid(4,4);
    //grid.affich();
    srand(time(NULL));
    int v= (rand()%4)+1;
    //cout<<v<<endl;
    //grid.initGrid();


    QGuiApplication app(argc, argv);
    //Grille g=Grille(4,4);
    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    //engine.rootContext()->setContextProperty("grille", &g);
    engine.rootContext()->setContextProperty("ng",&grid);
    engine.load(url);

    return app.exec();
}
