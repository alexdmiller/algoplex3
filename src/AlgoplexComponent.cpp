#include "AlgoplexComponent.hpp"

AlgoplexComponent::AlgoplexComponent(MeshMap* _meshMap) : meshMap(_meshMap) {
  canvas.allocate(ofGetWidth(), ofGetHeight());
  canvas.begin();
  ofClear(0, 0, 0);
  canvas.end();
}

ofFbo* AlgoplexComponent::getCanvas() {
  return &canvas;
}

void AlgoplexComponent::draw() {
  canvas.begin();
  ofClear(0, 0, 0);
  drawCanvas();
  canvas.end();
  meshMap->render(&canvas);
}
