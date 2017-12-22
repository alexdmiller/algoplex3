#ifndef MeshMap_hpp
#define MeshMap_hpp

#include <stdio.h>
#include "ofMain.h"

class MeshMap {
public:
  void loadFromModel(string filename);
  void loadFromMeshMap(string filename);
  void createGridMesh(int rows, int cols, float cellSize);
  void createCone(float radius, int segments);
  
  void save(ofFile* file);
  void mousePressed(int x, int y);
  void mouseReleased(int x, int y);
  void mouseDragged(int x, int y);
  void drawUI();
  void render(ofFbo* canvas);
  void translate(int x, int y);
  void translate(ofPoint diff);
  ofMesh* getUnmappedMesh();

private:
  ofMesh unmappedMesh;
  ofMesh mappedMesh;
  ofPoint lastMouse;
  int selectedIndex = -1;
};


#endif /* MeshMapper_hpp */
