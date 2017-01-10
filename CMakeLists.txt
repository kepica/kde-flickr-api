project (oblaci)

if(POLICY CMP0063)
    cmake_policy(SET CMP0063 OLD)
endif(POLICY CMP0063)

cmake_minimum_required(VERSION 2.8.12 FATAL_ERROR)
set(QT_MIN_VERSION "5.6.0")
set(KF5_MIN_VERSION "5.2.0")
set(QT_USE_QTNETWORK true)
set(CMAKE_AUTOMOC True)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_FLAGS "${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

add_definitions(-DQT_STRICT_ITERATORS)
add_definitions(-DQT_USE_QSTRINGBUILDER)
add_definitions(-DQT_USE_FAST_OPERATOR_PLUS)
add_definitions(-DQT_USE_FAST_CONCATENATION)

option(o2_WITH_QT5 "use qt5" ON)
option(o2_WITH_OAUTH1 "use o1" ON)


# find_package(Qt5 ${QT_MIN_VERSION}  COMPONENTS Network Core Widgets CONFIG REQUIRED ) 
find_package(Qt5Network REQUIRED ) 
find_package(Qt5Core REQUIRED ) 
find_package(Qt5Widgets REQUIRED ) 
find_package(Qt5Sql REQUIRED ) 
# QCommandLineParser, QStringLiteral
# QApplication, QAction
# QNetworkRequest, QNetworkAccessManager 


find_package(ECM 1.0.0 REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH} ${ECM_KDE_MODULE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

include(KDEInstallDirs)
include(KDECMakeSettings)
include(KDECompilerSettings)

include(FeatureSummary)
feature_summary(WHAT ALL INCLUDE_QUIET_PACKAGES FATAL_ON_MISSING_REQUIRED_PACKAGES)

find_package(KF5 ${KF5_MIN_VERSION} REQUIRED COMPONENTS
    CoreAddons      # KAboutData
    I18n            # KLocalizedString
    XmlGui          # KXmlGuiWindow, KActionCollection
    TextWidgets     # KTextEdit
    ConfigWidgets   # KStandardActions
    Notifications   # obavijesti
)

set(path_o1 ${CMAKE_CURRENT_SOURCE_DIR}/src/O1)
set(o1_SOURCES
    ${path_o1}/o0baseauth.cpp
    ${path_o1}/o0settingsstore.cpp
    ${path_o1}/o1.cpp
    ${path_o1}/o1requestor.cpp
    ${path_o1}/o1timedreply.cpp
    ${path_o1}/o2.cpp
    ${path_o1}/o2reply.cpp
    ${path_o1}/o2replyserver.cpp
    ${path_o1}/o2requestor.cpp
    ${path_o1}/o2simplecrypt.cpp
)

set(path_src ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(oblaci_SOURCES 
    ${path_src}/main.cpp 
    ${path_src}/mainwindow.cpp 
    ${path_src}/dblite.cpp 
    ${path_src}/favorites.cpp 
    ${path_src}/groups.cpp 
    ${path_src}/notice.cpp 
    ${path_src}/notica.cpp 
    ${path_src}/komentar.cpp 
    ${path_src}/linesearch.cpp
    ${path_src}/people.cpp 
    ${path_src}/photodown.cpp 
    ${path_src}/postavke.cpp 
    ${path_src}/tags.cpp 
    ${path_src}/waitsignal.cpp
    ${path_src}/welcome.cpp 
)

# include_directories(/home/vjeko/projects/oblaci)
include_directories(${path_src})
include_directories(${path_o1})
# The following is required so that the moc_*.cpp and ui_*.h are found
include_directories(${CMAKE_CURRENT_BINARY_DIR})

qt5_wrap_cpp(o1_header
    ${path_o1}/o0abstractstore.h
    ${path_o1}/o0globals.h
    ${path_o1}/o0requestparameter.h
    ${path_o1}/o0simplecrypt.h
)

add_executable(oblaci ${oblaci_SOURCES} ${o1_SOURCES} ${o1_header})
# set_property(TARGET oblaci APPEND PROPERTY COMPILE_DEFINITIONS QT_NO_CAST_FROM_ASCII QT_NO_CAST_TO_ASCII)

target_link_libraries(oblaci
    Qt5::Widgets
    Qt5::Network
    Qt5::Sql
    KF5::CoreAddons
    KF5::I18n
    KF5::XmlGui
    KF5::TextWidgets
    KF5::ConfigWidgets
    KF5::Notifications
)

qt5_use_modules(oblaci Network Core Widgets)

# set(XDG_DATA_DIRS $HOME/bin/share:$XDG_DATA_DIRS)

install(TARGETS oblaci  ${INSTALL_TARGETS_DEFAULT_ARGS})
install(FILES ./src/oblaciui.rc DESTINATION ${KXMLGUI_INSTALL_DIR}/oblaci)
install(FILES ./rsc/angel_s.jpg DESTINATION $<TARGET_FILE_DIR:oblaci>)
install(FILES ./rsc/angel_s.jpg DESTINATION bin )
install(FILES ./rsc/angel_icon.png DESTINATION $<TARGET_FILE_DIR:oblaci>)
install(FILES ./rsc/angel_icon.png DESTINATION bin )

# install( PROGRAMS oblaci.desktop DESTINATION ${XDG_APPS_INSTALL_DIR} )
# install(FILES oblaci.notifyrc DESTINATION ${KNOTIFYRC_INSTALL_DIR} )

