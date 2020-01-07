#ifndef MQTTPROTOCOL_H
#define MQTTPROTOCOL_H

#include "protocolinterface.h"
#include <QMqttClient>
#include <QTimer>

class MQTTProtocol : public QMqttClient
{
    Q_OBJECT

    Q_PROPERTY(bool autoConnect READ getAutoConnect WRITE setAutoConnect NOTIFY autoConnectChanged)

public:
    explicit MQTTProtocol(QObject *parent = nullptr);

    Q_INVOKABLE qint32 publish(const QString &topic, const QByteArray &message = QByteArray(), quint8 qos = 1, bool retain = false);
    Q_INVOKABLE void subscribe(const QString &topic, int qos = 0);

public slots:
    inline bool getAutoConnect() const { return this->autoConnect; }
    inline void setAutoConnect(bool autoConnect) { this->autoConnect = autoConnect; emit autoConnectChanged(autoConnect); }

signals:
    void messageReceived(const QString &message, const QString &topic);
    void autoConnectChanged(bool autoConnect);

private:
    bool autoConnect = true;
    QTimer *autoConnectTimer = new QTimer(this);
};

#endif // MQTTPROTOCOL_H
