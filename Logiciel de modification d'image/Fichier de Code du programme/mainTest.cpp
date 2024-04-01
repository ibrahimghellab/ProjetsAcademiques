/*#include "seance1.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;
int main() {
  vector<vector<int>> ro = {
      {0, 0, 0, 0}, {0, 0, 255, 255}, {0, 255, 255, 255}, {255, 255, 255, 255}};
  vector<vector<int>> ve = {{0, 0, 255, 255},
                            {0, 255, 255, 255},
                            {255, 255, 255, 0},
                            {255, 255, 0, 0}};
  vector<vector<int>> bl = {{255, 255, 0, 0}, {255, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};

  cout << endl << "----------------------Test du constructeur avec des vecteurs-----------------------------" << endl;
  Image img(bl, bl, bl);

  cout << endl << "----------------------Test de la methode affichevecteur----------------------------" << endl;
  img.affichevecteur();

  cout << endl << "----------------------Test de la methode couleurPixel--------------------------" << endl;
  img.couleurPixel(2, 2);

  cout << endl << "-----------------------Test de la methode composanteRouge-------------------------" << endl;
  Image img1 = img.composanteRouge();
  img1.affichevecteur();

  cout << endl << "---------------------Test de la methode detection---------------------------" << endl;
  if (img.detection(255, 0, 0)) {
    cout << "Le pixel (255, 0, 255) est présent dans l'image" << endl;
  } else {
    cout << "Le pixel (255, 0, 255) n'est pas présent dans l'image" << endl;
  }

  cout << endl << "------------------Test de la methode niveauxGris------------------------------" << endl;
  Image img2 = img.niveauxGris();
  img2.affichevecteur();

  cout << endl << "------------------Test de la methode noirEtBlanc------------------------------" << endl;
  Image img3 = img.noirEtBlanc(90);
  img3.affichevecteur();

  cout << endl << "-------------------Test de la methode histogrammeGris-----------------------------" << endl;
  vector<int> hist = img.histogrammeGris();
  for (int i = 0; i < hist.size(); i++) {
    cout << hist[i] << " ";
  }

  cout << endl << "------------------Test de la methode histogrammeCouleur------------------------------" << endl;
  vector<vector<vector<int>>> hist2 = img.histogrammeCouleur();
  for (int i = 0; i < hist2.size(); i++) {
    for (int j = 0; j < hist2[i].size(); j++) {
      for (int k = 0; k < hist2[i][j].size(); k++) {
        cout << hist2[i][j][k] << " ";
      }
    }
  }

  cout << endl << "----------------Test de la methode luminosityDown--------------------------------" << endl;
  Image img4 = img.luminosityDown(0.3);
  img4.affichevecteur();

  cout << endl << "-----------------Test de la methode luminosityUp-------------------------------" << endl;
  Image img5 = img4.luminosityUp(2);
  img5.affichevecteur();

  cout << endl << "------------------Test de la methode contrasteDown------------------------------" << endl;
  Image img6 = img.contrasteDown(0.5);
  img6.affichevecteur();

  cout << endl << "------------------Test de la methode contrasteUp------------------------------" << endl;
  Image img7 = img6.contrasteUp(2);

  cout << endl << "-----------------Test de la methode menu-------------------------------" << endl;
  menu();

  cout << endl << "--------------------Test du constructeur avec un nom de fichier----------------------------" << endl;
  string nomfichier = "exCouleur.ppm";
  Image img10(nomfichier);
  img10.affichevecteur();
  cout << endl << "--------------------Test de la methode rognerH----------------------------" << endl;
  Image img9 = img.rognerH();
  img9.affichevecteur();

  cout << endl << "--------------------Test de la methode rognerB----------------------------" << endl;
  Image img10 = img.rognerB();
  img10.affichevecteur();

  cout << endl << "----------------------Test de la methode retrecissement--------------------------" << endl;
  img.affichevecteur();
  Image img11 = img.retrecissement(2);
  img11.affichevecteur();

  cout << endl << "-----------------------Test de la methode agrandissement-------------------------" << endl;
  Image img12 = img.agrandissement(3);
  img12.affichevecteur();

  cout << endl << "-----------------------Test de la methode rotationD-------------------------" << endl;
  Image img13 = img.rotationD();
  img13.affichevecteur();

  cout << endl << "-----------------------Test de la methode retournementV-------------------------" << endl;
  Image img14 = img.retournementV();
  img14.affichevecteur();

  cout << endl << "--------------------Creation des filtres----------------------------" << endl;

  vector<vector<float>> filtre1 = {{1.0 / 16.0, 1.0 / 8.0, 1.0 / 16.0}, {1.0 / 8.0, 1.0 / 4.0, 1.0 / 8.0}, {1.0 / 16.0, 1.0 / 8.0, 1.0 / 16.0}};

  vector<vector<int>> filtre2 = {{1, 4, 6, 4, 1}, {4, 16, 24, 16, 4}, {6, 24, 36, 24, 6}, {4, 16, 24, 16, 4}, {1, 4, 6, 4}};

  vector<vector<float>> filtreX = {{-1.0, 0.0, 1.0}, {-2.0, 0.0, 2.0}, {-1.0, 0.0, 1.0}};
  vector<vector<float>> filtreY = {{-1.0, -2.0, -1.0}, {0.0, 0.0, 0.0}, {1.0, 2.0, 1.0}};
  vector<vector<float>> contraster = {{0.0, -1.0, 0.0}, {-1.0, 5.0, -1.0}, {0.0, -1.0, 0.0}};

  Filtre gradientX(filtreX,1);
  Filtre gradientY(filtreY,1);

  Filtre flouG5(produitMatrix(1.0/256.0, filtre2), 2);
  Filtre flouG3(filtre1,1);

  cout << endl << "------------------test de l'application du flouG3------------------------------" << endl;
  img.affichevecteur();
  flouG3.application(img).affichevecteur();

  cout << endl << "---------------------Test de l'application du flouG5---------------------------" << endl;
  flouG5.application(img).affichevecteur();

  return 0;
}*/
