#include "mqttprotocol.h"
#include <QMqttTopicName>
#include <QDebug>

MQTTProtocol::MQTTProtocol(QObject *parent): QMqttClient (parent)
{
    connect(this, &QMqttClient::messageReceived, this, [this](const QByteArray &message, const QMqttTopicName &topic){
        emit MQTTProtocol::messageReceived(message, topic.name());
    });
    //自动重连
    connect(autoConnectTimer, &QTimer::timeout, this, [this]{
        if(this->state() == QMqttClient::Disconnected) {
            this->connectToHost();
        }
    });
    autoConnectTimer->start(5000);

    connect(this, &MQTTProtocol::autoConnectChanged, this, [this](bool autoConnect){
       if(autoConnect) {  autoConnectTimer->start(5000); }
       else { autoConnectTimer->stop(); }
    });
}

qint32 MQTTProtocol::publish(const QString &topic, const QByteArray &message, quint8 qos, bool retain)
{
    return QMqttClient::publish(topic, message, qos, retain);
}
void MQTTProtocol:: subscribe(const QString &topic, int qos)
{
    QMqttClient::subscribe(topic, static_cast<quint8>(qos));
}
