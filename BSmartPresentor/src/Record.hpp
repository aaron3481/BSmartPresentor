/*
 * Record.hpp
 *
 *  Created on: Feb 23, 2013
 *      Author: aaron
 */

#ifndef RECORD_HPP_
#define RECORD_HPP_
#include <QObject>
#include <QString>
#include <iostream>

class Slide{
public:
	Slide(int animCount,QString note);
	~Slide();
//public Q_SLOTS:
	int getAnimCount();
	QString getNote();

private:
	const int animCount;
	const QString note;

};

class Record{
	/*Q_OBJECT
	Q_PROPERTY(QString fileName READ getName CONSTANT)*/
public:
	Record(int slideCount, QString fileName);
	~Record();
	void addSlide(int slideNum,int animCount,QString note);
	int getSlideCount();

//public Q_SLOTS:
	QString getName();
	Slide* getSlide(int slideNum);
	void printRecord();

private:
	const int slideCount;
	const QString fileName;
	Slide** slides;

};



#endif /* RECORD_HPP_ */
