#include "appvideoplayer.h"
#include <QJsonObject>
#include <QCoreApplication>
#include <QDebug>
#include "common.h"
#include <QTime>
#include <QTimer>

AppVideoPlayer::AppVideoPlayer(QJsonValue params, QLayout *lay,
                               QWidget *parent) : App(parent) , params(params)
{
	proc=nullptr;
	cmd = params.toObject()["cmd"].toString();
}

AppVideoPlayer::~AppVideoPlayer()
{

}

void AppVideoPlayer::buildUi()
{
	load();
}

void AppVideoPlayer::destroyUi()
{
	unload();
}

void AppVideoPlayer::unload()
{
	if (proc!=nullptr) {
		proc->write("q");
		proc->waitForFinished();
		delete proc;
		proc=nullptr;
		delete temp;
	}
}

void AppVideoPlayer::load()
{
	unload();
	proc = new QProcess(this);
	proc->setWorkingDirectory(sharedResPath);
	proc->start("/bin/sh",QStringList() << "-c" <<  cmd);
	temp= new QTimer(this);
	temp->setInterval(500);
	connect(temp,SIGNAL(timeout()),this,SLOT(intermediateResult()));
	temp->start();
	qDebug()<<proc->readAll();

}

void AppVideoPlayer::intermediateResult()
{
	qDebug()<<proc->readAll();
}

