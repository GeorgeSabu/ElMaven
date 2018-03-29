#ifndef POLLYINTEGRATION_H
#define POLLYINTEGRATION_H

// #include "QMap"
// #include "QString"
// #include <QDebug>
// #include "QStringList"
// #include "QByteArray"
// #include "QMap"
// #include "QString"
// #include <QDebug>
// #include "QStringList"
#include <QtCore>

class PollyIntegration
{

	public:
	    ~PollyIntegration();
	    PollyIntegration();
	    QString username;
	    QString password;
		QString jsPath;
        QByteArray run_qt_process(QString command, QStringList args = QStringList());
	    QByteArray run_system_process(QString command);
	    QString get_urls(QByteArray result);
	    QStringList get_system_urls(QString filename);
	    QStringList get_project_upload_url_commands(QByteArray result2,QStringList filenames);
		QStringList get_projectFiles_download_url_commands(QByteArray result2,QStringList filenames);
	    QString get_run_id(QByteArray result);
	    QString get_patch_id(QByteArray result);
	    int authenticate_login(QString username,QString password);
	    int check_already_logged_in();
	    QString login_required();
	    QStringList exportData(QString filedir,QString projectId);
		QString loadDataFromPolly(QString ProjectId,QStringList filenames);
		QVariantMap getUserProjects();
		QVariantMap getUserProjectFiles(QStringList ProjectIds);
		QVariantMap getUserProjectsMap(QByteArray result2);
		QStringList getUserProjectFilesMap(QByteArray result2);
		// LoginForm* _loginform;
	private:
		QString nodePath;
		// QString jsPath;
		QString credFile;
};

#endif // POLLYINTEGRATION_H
