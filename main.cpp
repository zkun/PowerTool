#include <QApplication>
#include <QPluginLoader>
#include <QCommandLineParser>

int main(int argc, char *argv[])
{
    QCoreApplication::setApplicationVersion("1.0");
    QCoreApplication::setOrganizationName("zkun");

    QStringList list;
    QCommandLineParser parser;
    for (int var = 0; var < argc; ++var)
        list.append(argv[var]);

    QCommandLineOption gui("gui", "display window");
    QCommandLineOption plugin("plugin", "plugin name", "plugins");

    parser.addHelpOption();
    parser.addVersionOption();
    parser.addOption(gui);
    parser.addOption(plugin);

    parser.parse(list);

    if (parser.isSet(gui))
        new QApplication(argc, argv);
    else
        new QCoreApplication(argc, argv);

    for (const QString &name: parser.values(plugin)) {
        QPluginLoader lib(name);
        lib.setLoadHints(QLibrary::DeepBindHint);

        if (lib.instance() == nullptr)
            return lib.unload();
    }

    return parser.isSet(plugin) ? qApp->exec() : 0;
}
