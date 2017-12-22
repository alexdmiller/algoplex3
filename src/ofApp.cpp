#include "ofApp.h"
#include "TrianglePulseComponent.hpp"

//--------------------------------------------------------------
void ofApp::setup(){
//  MeshMap* meshMap = new MeshMap();
//  meshMap->createGridMesh(10, 10, 50);
//  meshMaps.push_back(meshMap);
//  AlgoplexComponent* component = new TrianglePulseComponent(meshMap);
//  components.push_back(component);
//  
//  meshMap = new MeshMap();
//  meshMap->loadFromModel("mesh.dae");
//  meshMaps.push_back(meshMap);
//  component = new TrianglePulseComponent(meshMap);
//  components.push_back(component);
  
  MeshMap* meshMap = new MeshMap();
  meshMap->createCone(400, 10);
  meshMaps.push_back(meshMap);
  AlgoplexComponent* component = new TrianglePulseComponent(meshMap);
  components.push_back(component);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
  ofBackground(0);
  
  for (auto it = components.begin(); it != components.end(); ++it) {
    (*it)->draw();
  }
  
  if (selectedMeshMapIndex >= 0) {
    meshMaps.at(selectedMeshMapIndex)->drawUI();
  }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
  if (key == 9) {
    selectedMeshMapIndex = (selectedMeshMapIndex + 1) % meshMaps.size();
  }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
  if (selectedMeshMapIndex >= 0) {
    meshMaps.at(selectedMeshMapIndex)->mouseDragged(x, y);
  }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
  if (selectedMeshMapIndex >= 0) {
    meshMaps.at(selectedMeshMapIndex)->mousePressed(x, y);
  }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
  if (selectedMeshMapIndex >= 0) {
    meshMaps.at(selectedMeshMapIndex)->mouseReleased(x, y);
  }
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
