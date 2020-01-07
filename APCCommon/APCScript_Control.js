.pragma library

function createSpriteObjects(filePath, propertys, parent)
{
    var component = Qt.createComponent(filePath);
    return component.createObject(parent, propertys);
}

function newPage(parent, propertys)
{
    return createSpriteObjects('qrc:/Control/APCPageContainer.qml', propertys, parent)
}
function newLabel(parent, propertys)
{
    return createSpriteObjects('qrc:/Control/ControlLabel.qml', propertys, parent)
}
function newButton(parent, propertys)
{
    return createSpriteObjects('qrc:/Control/ControlButton.qml', propertys, parent)
}
function newInput(parent, propertys)
{
    return createSpriteObjects('qrc:/Control/ControlInput.qml', propertys, parent)
}
function newImage(parent, propertys)
{
    return createSpriteObjects('qrc:/Control/ControlImage.qml', propertys, parent)
}

function newDevice(parent, propertys)
{
    return createSpriteObjects('qrc:/MQTTClient.qml', propertys, parent)
}




