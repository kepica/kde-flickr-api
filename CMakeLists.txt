project (oblaci)

if(POLICY CMP0063)
    cmake_policy(SET CMP0063 OLD)
endif(POLICY CMP0063)

cmake_minimum_required(VERSION 2.8.12 FATAL_ERROR)
set(QT_MIN_VERSION "5.6.0")
set(KF5_MIN_VERSION "5.2.0")
set(QT_USE_QTNETWORK true)
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_FLAGS "${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

include_directories(/home/vjeko/projects/oblaci)

option(o2_WITH_QT5 "use qt5" ON)
option(o2_WITH_OAUTH1 "use o1" ON)

set(oblaci_SRCS main.cpp mainwindow.cpp notice.cpp notica.cpp mauth.cpp komentar.cpp favorites.cpp photodown.cpp dblite.cpp waitsignal.cpp
    mainwindow.h notice.h notica.h mauth.h komentar.h favorites.h photodown.h dblite.h waitsignal.h
    postavke.cpp welcome.cpp people.cpp tags.cpp groups.cpp linesearch.cpp
    postavke.h welcome.h people.h tags.h groups.h linesearch.h
    o0baseauth.cpp o0settingsstore.cpp o1.cpp o1requestor.cpp o1timedreply.cpp
    o0abstractstore.h o0baseauth.h o0globals.h o0requestparameter.h o0settingsstore.h o0simplecrypt.h
    o2.cpp o2reply.cpp o2replyserver.cpp o2requestor.cpp o2simplecrypt.cpp 
    o1.h o1requestor.h o1timedreply.h o2.h o2reply.h o2replyserver.h o2requestor.h 
    )

add_executable(oblaci ${oblaci_SRCS})

find_package(ECM 1.0.0 REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH} ${ECM_KDE_MODULE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

include(KDEInstallDirs)
include(KDECMakeSettings)
include(KDECompilerSettings)
include(FeatureSummary)

# find_package(Qt5 ${QT_MIN_VERSION}  COMPONENTS Network Core Widgets CONFIG REQUIRED ) 
find_package(Qt5Network REQUIRED ) 
find_package(Qt5Core REQUIRED ) 
find_package(Qt5Widgets REQUIRED ) 
find_package(Qt5Sql REQUIRED ) 
# QCommandLineParser, QStringLiteral
# QApplication, QAction
# QNetworkRequest, QNetworkAccessManager 
qt5_use_modules(oblaci Network Core Widgets)


find_package(KF5 ${KF5_MIN_VERSION} REQUIRED COMPONENTS
    CoreAddons      # KAboutData
    I18n            # KLocalizedString
    XmlGui          # KXmlGuiWindow, KActionCollection
    TextWidgets     # KTextEdit
    ConfigWidgets   # KStandardActions
    Notifications   # obavijesti
)

feature_summary(WHAT ALL INCLUDE_QUIET_PACKAGES FATAL_ON_MISSING_REQUIRED_PACKAGES)
    

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

# set(XDG_DATA_DIRS $HOME/bin/share:$XDG_DATA_DIRS)

install(TARGETS oblaci  ${INSTALL_TARGETS_DEFAULT_ARGS})
install(FILES oblaciui.rc DESTINATION ${KXMLGUI_INSTALL_DIR}/oblaci)
install(FILES ./rsc/angel_s.jpg DESTINATION $<TARGET_FILE_DIR:oblaci>)
install(FILES ./rsc/angel_s.jpg DESTINATION bin )
# install( PROGRAMS oblaci.desktop DESTINATION ${XDG_APPS_INSTALL_DIR} )
# install(FILES oblaci.notifyrc DESTINATION ${KNOTIFYRC_INSTALL_DIR} )

