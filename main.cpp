#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QApplication>
#include <protocol/mqttprotocol.h>

int main(int argc, char *argv[])
{
    //qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    qmlRegisterType<MQTTProtocol>("MQTTProtocol", 1, 0, "MQTTProtocol");

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    qSetMessagePattern("[%{time h:mm:ss.zzz} %{if-debug}Debug%{endif}%{if-warning}Waring%{endif}%{if-critical}Critical%{endif}%{if-fatal}Fatal%{endif}] %{file}:%{line} : %{message}");

    return app.exec();
}
