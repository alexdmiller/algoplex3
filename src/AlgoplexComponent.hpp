#ifndef AlgoplexComponent_hpp
#define AlgoplexComponent_hpp

#include <stdio.h>
#include "MeshMap.hpp"

class AlgoplexComponent {
  
public:
  AlgoplexComponent(MeshMap* _meshMap);
  ofFbo* getCanvas();
  void draw();
  virtual void setup() {}

protected:
  MeshMap* meshMap;
  virtual void drawCanvas() {}
  
private:
  ofFbo canvas;
};

#endif /* Component_hpp */
