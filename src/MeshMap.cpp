#include "MeshMap.hpp"
#include "ofxAssimpModelLoader.h"

void MeshMap::loadFromModel(string filename) {
  ofxAssimpModelLoader model;
  model.loadModel(filename);
  
  ofPoint min = model.getSceneMin();
  ofPoint max = model.getSceneMax();
    
  unmappedMesh = model.getMesh(0);
  
  for (int i = 0; i < unmappedMesh.getNumVertices(); i++) {
    ofPoint v = unmappedMesh.getVertex(i);
    ofPoint newV = ofPoint(ofMap(v.x, min.y, max.y, -ofGetHeight() / 4, ofGetHeight() / 4) + ofGetWidth() / 2,
                          ofMap(v.y, min.y, max.y, -ofGetHeight() / 4, ofGetHeight() / 4) + ofGetHeight() / 2);
    unmappedMesh.setVertex(i, newV);
  }
  
  // TODO: this is common for any way you create a mesh. move to "finishMesh" function
  mappedMesh = unmappedMesh;
  
  for (int i = 0; i < mappedMesh.getNumVertices(); i++) {
    mappedMesh.addTexCoord(unmappedMesh.getVertex(i));
  }
}

void MeshMap::loadFromMeshMap(string filename) {
  // TODO
}

void MeshMap::createGridMesh(int rows, int cols, float cellSize) {
  unmappedMesh.setMode(OF_PRIMITIVE_TRIANGLES);
  mappedMesh.setMode(OF_PRIMITIVE_TRIANGLES);
  
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      unmappedMesh.addVertex(ofPoint(x * cellSize, y * cellSize));
    }
  }
  
  for (int y = 0; y < rows - 1; y++) {
    for (int x = 0; x < cols - 1; x++) {
      unmappedMesh.addIndex(y * cols + x);
      unmappedMesh.addIndex(y * cols + x + 1);
      unmappedMesh.addIndex((y + 1) * cols + x);
      
      unmappedMesh.addIndex((y + 1) * cols + x + 1);
      unmappedMesh.addIndex(y * cols + x + 1);
      unmappedMesh.addIndex((y + 1) * cols + x);
    }
  }

  mappedMesh = unmappedMesh;
  
  for (int i = 0; i < mappedMesh.getNumVertices(); i++) {
    mappedMesh.addTexCoord(unmappedMesh.getVertex(i));
  }
}

void MeshMap::createCone(float radius, int segments) {
  unmappedMesh.setMode(OF_PRIMITIVE_TRIANGLE_FAN);
  mappedMesh.setMode(OF_PRIMITIVE_TRIANGLE_FAN);
  
  unmappedMesh.addVertex(ofPoint(radius, radius));
  unmappedMesh.addIndex(0);
  
  for (int i = 0; i < segments; i++) {
    unmappedMesh.addVertex(ofPoint(
                                   radius + cos(i * (2 * PI / segments)) * radius,
                                   radius + sin(i * (2 * PI / segments)) * radius, 0));
    unmappedMesh.addIndex(i + 1);
  }
  
  unmappedMesh.addIndex(0);
  unmappedMesh.addIndex(1);
  unmappedMesh.addIndex(unmappedMesh.getNumVertices() - 1);

  mappedMesh = unmappedMesh;
  
  for (int i = 0; i < mappedMesh.getNumVertices(); i++) {
    mappedMesh.addTexCoord(unmappedMesh.getVertex(i));
  }
  
}

void MeshMap::mousePressed(int x, int y) {
  lastMouse.set(x, y);
  for (int i = 0; i < mappedMesh.getNumVertices(); i++) {
    if (lastMouse.distance(mappedMesh.getVertex(i)) < 10) {
      selectedIndex = i;
    }
  }
}

void MeshMap::mouseReleased(int x, int y) {
  selectedIndex = -1;
}

void MeshMap::mouseDragged(int x, int y) {
  if (selectedIndex >= 0) {
    mappedMesh.setVertex(selectedIndex, ofPoint(x, y));
  } else {
    ofPoint diff = ofPoint(x, y) - lastMouse;
    translate(diff);
  }
  lastMouse.set(x, y);
}

void MeshMap::drawUI() {
  ofSetColor(255, 255, 255);
  mappedMesh.draw(OF_MESH_WIREFRAME);
}

void MeshMap::render(ofFbo* canvas) {
  canvas->getTexture().bind();
  mappedMesh.draw();
  canvas->getTexture().unbind();
}

void MeshMap::translate(int x, int y) {
  translate(ofPoint(x, y));
}

void MeshMap::translate(ofPoint diff) {
  for (int i = 0; i < mappedMesh.getNumVertices(); i++) {
    ofPoint point = mappedMesh.getVertex(i);
    point += diff;
    mappedMesh.setVertex(i, point);
  }
}

void MeshMap::save(ofFile* file) {
  
}

ofMesh* MeshMap::getUnmappedMesh() {
  return &unmappedMesh;
}