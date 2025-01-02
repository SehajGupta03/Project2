project(MachineLib)
set(CMAKE_OSX_DEPLOYMENT_TARGET 10.14)

set(SOURCE_FILES
        pch.h
        IMachineSystem.h
        MachineSystemFactory.cpp MachineSystemFactory.h
        MachineDialog.cpp MachineDialog.h include/machine-api.h
        Const.cpp
        Const.h
        MachineSystemStandin.h
        MachineSystemStandin.cpp
        MachineStandin.cpp
        MachineStandin.h
        Polygon.cpp
        Polygon.h
        Cylinder.cpp
        Cylinder.h
        MachineSystem.cpp
        MachineSystem.h
        Machine.cpp
        Machine.h
        MachineCFactory.cpp
        MachineCFactory.h
        Component.cpp
        Component.h
        Box.cpp
        Box.h
        Sparty.cpp
        Sparty.h
        Crank.cpp
        Crank.h
        RotationSink.cpp
        RotationSink.h
        Shaft.cpp
        Shaft.h
        RotationSource.cpp
        RotationSource.h
        MachineSFactory.cpp
        MachineSFactory.h
        Pulley.cpp
        Pulley.h
        Cam.cpp
        Cam.h
        ITrigger.h
)

find_package(wxWidgets COMPONENTS core base xrc html xml REQUIRED)
include(${wxWidgets_USE_FILE})

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})
