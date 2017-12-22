#ifndef TrianglePulseComponent_hpp
#define TrianglePulseComponent_hpp

#include <stdio.h>
#include "AlgoplexComponent.hpp"

class TrianglePulseComponent : public AlgoplexComponent {
public:
  TrianglePulseComponent(MeshMap* _meshMap) : AlgoplexComponent(_meshMap) {}
protected:
  virtual void drawCanvas();
};

#endif /* TrianglePulseComponent_hpp */
