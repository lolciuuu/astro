#ifndef STANDARDREFERENCES_HPP
#define STANDARDREFERENCES_HPP

#include "Renderer.hpp"
#include "Writer.hpp"
#include "Resource.hpp"
#include "Property.hpp"
#include "Logger.hpp"

class StandardReferences {
public:  
  StandardReferences() :
      	  pRendererPtr( Renderer::getInstance() ),
      	  pWriterPtr( Writer::getInstance() ),
      	  logger("StandardReferences")
      {
	  	 pScreenHeight = pRendererPtr->getScreenHeight();
	  	 pScreenWidth = pRendererPtr->getScreenWidth();
      }
  
protected:
  Renderer* pRendererPtr;
  Writer* pWriterPtr;  

  short pScreenWidth;
  short pScreenHeight;
  Logger logger;

};
#endif
