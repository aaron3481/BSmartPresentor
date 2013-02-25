/*
 * Record.cpp
 *
 *  Created on: Feb 23, 2013
 *      Author: aaron
 */
#include "Record.hpp"
#include <QString>
#include <iostream>

Record::Record(int sc,QString fn):slideCount(sc),fileName(fn){
	slides = new Slide*[slideCount];
	for(int i=0; i<slideCount;i++)
		slides[i]=0;
}
Record::~Record(){
	for(int i=0;i<slideCount;i++){
		if(slides[i]!=0)
			delete(slides[i]);
	}
	delete(slides);
}

void Record::addSlide(int sn,int ac, QString note){
	slides[sn] = new Slide(ac,note);
}

Slide* Record::getSlide(int sn){
	return slides[sn];
}

int Record::getSlideCount(){
	return slideCount;
}

void Record::printRecord(){
	std::cout<<"Record name: "<<fileName.toStdString()<<" Slide Count: "<<slideCount<<std::endl;
	std::cout<<"---------------------------------------"<<std::endl;
	for(int i=0;i<slideCount;i++){
		std::cout<<"Slide#: "<<i<<" Animation Count: "<<slides[i]->getAnimCount()<<std::endl;
		std::cout<<"Note: "<<slides[i]->getNote().toStdString()<<std::endl;
		std::cout<<"---------------------------------------"<<std::endl;
	}

}

QString Record::getName(){
	return fileName;
}

Slide::Slide(int ac, QString note): animCount(ac),note(note){

}

Slide::~Slide(){

}

int Slide::getAnimCount(){
	return animCount;
}

QString Slide::getNote(){
	return note;
}


