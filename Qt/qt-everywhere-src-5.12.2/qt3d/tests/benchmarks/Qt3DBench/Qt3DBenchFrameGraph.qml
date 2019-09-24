/****************************************************************************
**
** Copyright (C) 2014 Klaralvdalens Datakonsult AB (KDAB).
** Contact: https://www.qt.io/licensing/
**
** This file is part of the Qt3D module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:GPL-EXCEPT$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 as published by the Free Software
** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

import Qt3D.Core 2.0
import Qt3D.Render 2.0
import QtQuick 2.2 as QQ2

FrameGraph {
    id: root

    property alias viewCamera: viewCameraSelector.camera
    property alias lightCamera: lightCameraSelector.camera
    readonly property Texture2D shadowTexture: depthTexture

    activeFrameGraph: Viewport {
        rect: Qt.rect(0.0, 0.0, 1.0, 1.0)
        clearColor: Qt.rgba(0.0, 0.0, 0.0, 1.0)

        RenderPassFilter {
            includes: [ FilterKey { name: "pass"; value: "shadowmap" } ]

            RenderTargetSelector {
                target: RenderTarget {
                    attachments: [
                        RenderAttachment {
                            name: "depth"
                            type: RenderAttachment.DepthAttachment
                            texture: Texture2D {
                                id: depthTexture
                                width: 1024
                                height: 1024
                                format: Texture.DepthFormat
                                generateMipMaps: false
                                magnificationFilter: Texture.Linear
                                minificationFilter: Texture.Linear
                                wrapMode {
                                    x: WrapMode.ClampToEdge
                                    y: WrapMode.ClampToEdge
                                }
                                comparisonFunction: Texture.CompareLessEqual
                                comparisonMode: Texture.CompareRefToTexture
                            }
                        }
                    ]
                }

                ClearBuffers {
                    buffers: ClearBuffers.DepthBuffer

                    CameraSelector {
                        id: lightCameraSelector
                    }
                }
            }
        }

        RenderPassFilter {
            includes: [ FilterKey { name: "pass"; value: "forward" } ]

            ClearBuffers {
                buffers : ClearBuffers.ColorDepthBuffer

                CameraSelector {
                    id: viewCameraSelector
                }
            }
        }
    }
}
