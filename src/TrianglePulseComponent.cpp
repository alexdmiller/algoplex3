#include "TrianglePulseComponent.hpp"

void TrianglePulseComponent::drawCanvas() {
  vector<ofMeshFace> triangles;
  
  if (meshMap->getUnmappedMesh()->getMode() == OF_PRIMITIVE_TRIANGLES) {
    triangles = meshMap->getUnmappedMesh()->getUniqueFaces();
  } else if (meshMap->getUnmappedMesh()->getMode() == OF_PRIMITIVE_TRIANGLE_FAN) {
    cout << meshMap->getUnmappedMesh()->getNumIndices() << "\n";
    for (int i = 1; i < meshMap->getUnmappedMesh()->getNumIndices() - 1; i += 1) {
      cout << i << "\n";
      cout << meshMap->getUnmappedMesh()->getIndex(i) << "\n";
      cout << meshMap->getUnmappedMesh()->getIndex(i + 1) << "\n";
      cout << meshMap->getUnmappedMesh()->getIndex(i + 2) << "\n";
      
      ofMeshFace face;
      face.setVertex(0, meshMap->getUnmappedMesh()->getVertex(meshMap->getUnmappedMesh()->getIndex(0)));
      face.setVertex(1, meshMap->getUnmappedMesh()->getVertex(meshMap->getUnmappedMesh()->getIndex(i)));
      face.setVertex(2, meshMap->getUnmappedMesh()->getVertex(meshMap->getUnmappedMesh()->getIndex(i + 1)));
      triangles.push_back(face);
    }
  }
  
  ofSetLineWidth(0);
  
  for (int i = 0; i < triangles.size(); i++) {
    ofSetColor(ofFloatColor(ofMap(sin((float) i / 5 + ofGetElapsedTimef()), -1, 1, 0, 1)));
    ofMeshFace tri = triangles.at(i);
    ofDrawTriangle(tri.getVertex(0), tri.getVertex(1), tri.getVertex(2));
  }
}