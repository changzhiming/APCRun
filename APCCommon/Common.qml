pragma Singleton

import Qt.labs.settings 1.0
import QtQuick 2.0
import "./APCScript_Control.js" as GB

Item {
    property string projectFilePath: ''

    //读取所有页面
    function readPages() {
        return JSON.parse(projectSetting.value('windowList', "[]"))
    }
    //读取一个页面
    function readOnePage(pageName) {
        return JSON.parse(projectSetting.value(pageName, "{}"))
    }

    //读取所有设备
    function readDevices() {
        return JSON.parse(projectSetting.value('deviceList', "[]"))
    }
    //读取一个设备
    function readOneDevice(deviceName) {
        return JSON.parse(projectSetting.value(deviceName, "{}"))
    }

    Settings {
        id: projectSetting
        fileName: projectFilePath
    }

    Component.onCompleted: {
        GB.newDevice(this, {hostname: 'mqtt.huikezk.com',
                         clientId: 'mqtt_111',
                         username: 'admin',
                         password: '123456',
                         port:'1883',
                         topicList:'1231434;3323434'
                     }).connectToHost()
    }
}
