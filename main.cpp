#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "someclass.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    //SomeClass testClass;
    qmlRegisterType< SomeClass > ( "Monty", 1, 0, "SomeClass" );

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    //QQmlContext * rootContext = engine.rootContext();
    //rootContext->setContextProperty( "classA", &testClass );

    return app.exec();
}
