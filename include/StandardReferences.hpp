#ifndef STANDARDREFERENCES_HPP
#define STANDARDREFERENCES_HPP

#include "Renderer.hpp"
#include "Writer.hpp"
#include "Resource.hpp"
#include "Property.hpp"
#include "Logger.hpp"
#include "SoundManager.hpp"

class StandardReferences {
public:  
  StandardReferences() :
      	  pRendererPtr( Renderer::getInstance() ),
      	  pWriterPtr( Writer::getInstance() ),
      	  pSoundManagerPtr( SoundManager::getInstance() ),
      	  logger("StandardReferences")
      {
	  	 pScreenHeight = pRendererPtr->getScreenHeight();
	  	 pScreenWidth = pRendererPtr->getScreenWidth();
      }
  
  virtual ~StandardReferences(){  };

protected:
  Renderer* pRendererPtr;
  Writer* pWriterPtr;  
  SoundManager* pSoundManagerPtr;

  short pScreenWidth;
  short pScreenHeight;
  Logger logger;

};
#endif
