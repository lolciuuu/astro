/*
 * GameItem.hpp
 *
 *  Created on: 17-03-2013
 *      Author: lolcio
 */

#ifndef GAMEITEM_HPP_
#define GAMEITEM_HPP_

/** Interfejs wymuszjacy zaimplementowanie draw i update */
class GameItem {
public:
	virtual ~GameItem(){}

public:
	virtual void draw()=0;
	virtual void update(const float&)=0;

};

#endif /* GAMEITEM_HPP_ */
