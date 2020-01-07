#ifndef PROTOCOLINTERFACE_H
#define PROTOCOLINTERFACE_H

#include <QObject>

class ProtocolInterface : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString deviceName READ getDeviceName WRITE setDeviceName NOTIFY deviceNameChanged)

public:
    explicit ProtocolInterface(QObject *parent = nullptr): QObject(parent) { }
    virtual ~ProtocolInterface() {}

    inline QString getDeviceName() const {  return this->deviceName;}
    inline void setDeviceName(const QString &deviceName) { this->deviceName = deviceName; emit deviceNameChanged(deviceName); }

signals:
    void deviceNameChanged(const QString &deviceName);

public slots:
    virtual QString read(const QString &device) const = 0;
    virtual void write(const QString &device, double value) = 0;
    virtual bool connect() const = 0;

private:
    QString deviceName;
};

#endif // PROTOCOLINTERFACE_H
