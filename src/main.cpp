#include <cstdlib>
 
#include <QApplication>
#include <QCoreApplication>
#include <QDialog>
#include <QSettings>
#include <QDebug>
#include <QCommandLineParser>

#include <KAboutData>
#include <KLocalizedString>

#include "welcome.h"
#include "mainwindow.h"
 
int main (int argc, char *argv[])
{
    QApplication app(argc, argv);
    KLocalizedString::setApplicationDomain("oblaci");
    QCoreApplication::setApplicationName("oblaci");
    QCoreApplication::setOrganizationName("vedra_nebesa");
    
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
                         i18n("(c) 2017 kepica"),
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
    QSettings mset;
    
    if (mset.value("pic_root_dir", "none") == "none")
    {
        // --- pic_root not set
        Welcome* welcome = new Welcome(0);
        welcome->exec();
    }
    else if (mset.value("flickr_user_id", "none") == "none")
    {
        // ---- started, but flickr_id not set
        Welcome* welcome = new Welcome(1);
        welcome->exec();
    }
    else if (mset.value("welcome_disabled", "none") != "disabled")
    {
        Welcome* welcome = new Welcome(2);
        welcome->exec();
    }
    
    // if (welcome.exec() == QDialog::Accepted)
    window->show();
    
    return app.exec();
}
