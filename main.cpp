#include <cstdlib>
 
#include <QApplication>
#include <QCommandLineParser>

#include <KAboutData>
#include <KLocalizedString>

#include "mainwindow.h"
 
int main (int argc, char *argv[])
{
    QApplication app(argc, argv);
    KLocalizedString::setApplicationDomain("oblaci");
    
    KAboutData aboutData(
                         // The program name used internally. (componentName)
                         QStringLiteral("oblaci"),
                         // A displayable program name string. (displayName)
                         i18n("Oblaci"),
                         // The program version string. (version)
                         QStringLiteral("1.0"),
                         // Short description of what the app does. (shortDescription)
                         i18n("bring your flickr activity to KDE desktop"),
                         // The license this code is released under
                         KAboutLicense::GPL,
                         // Copyright Statement (copyrightStatement = QString())
                         i18n("(c) 2016 kepica"),
                         // Optional text shown in the About box.
                         // Can contain any information desired. (otherText)
                         i18n("KDE desktop app Flickr API client"),
                         // The program homepage string. (homePageAddress = QString())
                         QStringLiteral("https://github.com/kepica/kde-flickr-api"),
                         // The bug report email address
                         // (bugsEmailAddress = QLatin1String("submit@bugs.kde.org")
                         QStringLiteral("submit@bugs.kde.org"));
    aboutData.addAuthor(i18n("kepica"), i18n("Task"), QStringLiteral("none@email.com"),
                        QStringLiteral("https://github.com/kepica/kde-flickr-api"), QStringLiteral("Username"));
    KAboutData::setApplicationData(aboutData);
 
    QCommandLineParser parser;
    parser.addHelpOption();
    parser.addVersionOption();
    aboutData.setupCommandLine(&parser);
    parser.process(app);
    aboutData.processCommandLine(&parser);
    
    MainWindow* window = new MainWindow();
    window->show();
    
    return app.exec();
}
