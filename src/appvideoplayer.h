#ifndef APPVIDEOPLAYER_H
#define APPVIDEOPLAYER_H
#include <QJsonValue>
#include <QProcess>
#include <QLayout>
#include "app.h"

class AppVideoPlayer : public App
{
	Q_OBJECT
	QJsonValue params;
	QProcess *proc;
	QString cmd;
	QTimer *temp;
public:
	explicit AppVideoPlayer(QJsonValue params, QLayout *lay, QWidget *parent = 0);
	~AppVideoPlayer();

signals:

public slots:
	virtual void buildUi();
	virtual void destroyUi();
	virtual void load();
	virtual void unload();
	virtual void intermediateResult();

private:

};

#endif // APPVIDEOPLAYER_H
