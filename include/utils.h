#ifndef UTILS_H
#define UTILS_H

#include "qt_common.h"
#include <string.h>
#include <iostream>

qint64 MillsencondsToSeconds(qint64 millseconds);
QString Seconds2DurationFormat(qint64 seconds); 
void CheckMultimediaService(QWidget *parent);
void DemoQSoundEffect(const QString &music_path);
void DemoQMediaMusic(const QString &music_path);

#endif