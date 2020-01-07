import QtQuick 2.0
import MQTTProtocol 1.0

MQTTProtocol {
    property string topicList: ''
    readonly property var valueMap: new Map()

    function read(device, address) {
        return valueMap.get(`${device}_${address}`)
    }
    function write(device, address, value) {
        publish(device, JSON.stringify({[address]:value}))
    }

    onConnected: {
        var topics = topicList.split(";")
        for(var topic of  topics) {
            subscribe(topic, 1)
        }
        print("MQTT连接成功")
    }
    onMessageReceived: {
        var messageObj = JSON.parse(message)
        for(var key in messageObj) {
            valueMap.set(`${valueMap}_${key}`, messageObj[key])
        }
    }
}
