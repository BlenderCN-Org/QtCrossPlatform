import QtQml 2.1
import Qt3D.Core 2.0

Entity {
    NodeInstantiator {
        active: false
        Entity {
            property bool success: true
            property int idx: index
        }
    }
}
